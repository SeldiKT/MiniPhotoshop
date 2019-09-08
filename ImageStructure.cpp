#pragma comment(lib, "coredll.lib")
#pragma comment(lib, "Gdi32.lib")

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

class Image    
 {    
    public:  

    Image(){
        Width = 0;
        Height = 0;
    }
    ~Image(){
        dealokasiCitra(citra, Height);
    }
    // unsigned char** alokasiCitra(int height, int width){
    //     int i;
    //     citra =(unsigned char**)malloc(height * sizeof(unsigned char*));
    //     if (citra==NULL) return(NULL); /* memori habis */
    //     for (i=0; i<height; i++)
    //     {
    //     citra[i]=(unsigned char*)malloc(width*sizeof(unsigned char));
    //     if (citra[i]==NULL)
    //         { /* memori habis, dealokasi semua elemen baris matriks */
    //         dealokasiCitra(citra, height);
    //         return(NULL);
    //         }
    //     }
    //     return citra;
    // }

    void **alokasi(int N, int M, int UkuranElemen)/* Mengalokasikan memori untuk matriks N x M. Setiap elemen matriks berukuran UkuranElemen byte */
    {
        int i;
        void **larik = (void**)xalloc(N * sizeof(void *)); /* buat array N elemen */
        for (i=0; i<N; i++)
            larik[i] = (void*)xalloc(M * UkuranElemen);
        return larik;
    }

    void *xalloc(unsigned ukuran)/* Mengalokasikan memori dan memeriksa apakah alokasi memori berhasil */
    {
        void *p = malloc(ukuran);
        if (p==NULL){
            printf("Memori tidak cukup untuk alokasi matriks");
            exit(0);
        }
        return p;
    }

    void dealokasiCitra(void** citra, int height){
        int  i;
        for(i=0; i<height; i++){
            free(citra[i]); //bebaskan memori tiap elemen citra
        }
        free(citra);
    }

    // void tampilkan_citra(unsigned char** r, unsigned char** g, unsigned char** b, int height, int width){
    //     int i,j;
    //     for(i=0;i<height;i++){
    //         for(j=0;j<width;j++){
    //             setpixel(r[i][j],g[i][j],b[i][j],j,i);
    //         }
    //     }
    // }

    //Menampilkan Citra di Windows
    void WIN_tampilkan_citra(unsigned char** Image, int height, int width, bool RGB){
        HDC         MemDC;
        HBITMAP     mbitmap;
        HWND        hwnd;
        COLORREF    TabelWarna[256];
        int i,j,palet;

        hwnd = GetActiveWindow();
        MemDC = CreateCompatibleDC(GetDC(hwnd));
        mbitmap = CreateCompatibleBitmap(GetDC(hwnd),width,height);
        SelectObject(MemDC,mbitmap);
        
        //Definisikan Palet
        for(i=0; i<256; i++)
            TabelWarna[i] = GetNearestColor(MemDC, RGB(i,i,i));

        //isi pixel ke memory device
        // if(RGB){
        // input fungsi ada 3 citra (r,g,b)
        //     for(i=0;i<height;i++){
        //         for(j=0;j<width;j++){
        //             palet = GetNearestColor(MemDC, RGB(r[i][j], g[i][j], b[i][j]);
        //             SetPixelV(MemDC,j,i,palet);
        //         }
        //     }
        // }

        for(i=0;i<height;i++){
            for(j=0;j<width;j++){
                palet = Image[i][j];
                SetPixelV(MemDC,j,i,TabelWarna[palet]);
            }
        }
        //tembak citra ke layar
        BitBlt(GetDC(hwnd),0,0,width,height,MemDC,0,0,SRCCOPY);
    }

    void baca_citra_dari_arsip(char nama_arsip[], void** f)
    /* Membaca citra dari file citra mentah. Citra hasil pembacaan disimpan di alam matriks f. */
    {
        FILE *fp;
        int i, j;
        unsigned short int N, M;
        if((fp=fopen(nama_arsip, "rb"))==NULL)
        {
            printf("Arsip tidak ada");
            exit(0);
        }
        fread(&N, sizeof(unsigned short int), 1, fp); /* baca tinggi citra */
        fread(&M, sizeof(unsigned short int), 1, fp); /* baca lebar citra */
        f = alokasi(N, M, sizeof(unsigned char)); /* alokasi memori matriks untuk citra f */
        if(f==NULL){ 
            printf("Memori tidak cukup");
            exit(0);
        }
        /* baca data citra baris demi baris */
        for(i=0; i<N; i++)
        {
            /* baca data citra baris ke-i */
            fread(f[i], sizeof(unsigned char), M, fp);
        }
        fclose(fp);
    }

    void tulis_citra_ke_arsip(char nama_arsip[], void** f)
    /* Menulis citra f ke dalam arsip nama_arsip. */
    {
        FILE *fp;
        int i, j;
        unsigned short int N, M;
        if((fp=fopen(nama_arsip, "wb"))==NULL)
        {
            printf("Arsip tidak dapat dibuat");
            exit(0);
        }
        fwrite(&N, sizeof(unsigned short int), 1, fp); /* tulis tinggi citra */
        fwrite(&M, sizeof(unsigned short int), 1, fp); /* tulis lebar citra */
        /* baca data citra baris demi baris */
        for(i=0; i<N; i++)
        {
            /* tulis data citra baris ke-i */
            fwrite(f[i], sizeof(unsigned char), M, fp);
        }
        fclose(fp);
    }

    int Width,Height;
    void** citra;  

 }; 

 int main(int argc, char* argv[]){
    Image test;
    std::cout<<test.Width<<"\n"<<test.Height<<"\n";
    test.baca_citra_dari_arsip(argv[1],test.citra);
    test.WIN_tampilkan_citra((unsigned char**)test.citra,test.Height,test.Width,false);
 }