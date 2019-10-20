#include "Functions.cpp"
#include "Convolution.cpp"
#include <iostream>


int main()
{   
    int** matrix1 = createMatrix(10,10,0);
    int** matrix2 = createMatrix(10,10,124);
    int** matrix3 = createMatrix(10,10,255);
    int** matrix4 = createMatrix(10,10,0);

    bool** matrixbool = createMatrix(10,10,false);
    bool** matrixbool2 = createMatrix(10,10,false);

    int** matrixbig = createMatrix(20,20,1);

    //Print Inisial matrix
    printmatrix(matrix2,10,10);
    std::cout<<std::endl;

    // //Biner
    // std::cout<<"Fungsi Biner"<<std::endl;
    // biner(matrix2,matrixbool,120,10,10);
    // printmatrix(matrixbool,10,10);
    // biner(matrix2,matrixbool,125,10,10);
    // printmatrix(matrixbool,10,10);
    // std::cout<<std::endl;

    // //negatif
    // std::cout<<"Fungsi Negatif"<<std::endl;
    // negatif(matrix2,matrix3,10,10);
    // printmatrix(matrix3,10,10);
    // std::cout<<std::endl;

    // //image brightening
    // std::cout<<"Fungsi brighten"<<std::endl;
    // image_brightening(matrix2,10,matrix3,10,10);
    // printmatrix(matrix3,10,10);
    // std::cout<<std::endl;

    // //grayscale
    // std::cout<<"Fungsi grayscale"<<std::endl;
    // grayscale(matrix1,matrix2,matrix4,matrix3,10,10);
    // printmatrix(matrix3,10,10);
    // std::cout<<std::endl;

    // //addvalue
    // std::cout<<"Fungsi add"<<std::endl;
    // addvalues(matrix1,matrix2,matrix3,10,10);
    // printmatrix(matrix3,10,10);
    // addvalues(matrix1,69,matrix3,10,10);
    // printmatrix(matrix3,10,10);
    // std::cout<<std::endl;

    // //substract
    // std::cout<<"Fungsi substract"<<std::endl;
    // substractvalues(matrix1,matrix2,matrix3,10,10);
    // printmatrix(matrix3,10,10);
    // substractvalues(matrix4,255,matrix3,10,10);
    // printmatrix(matrix3,10,10);
    // std::cout<<std::endl;

    // //multiplication
    // std::cout<<"Fungsi kali"<<std::endl;
    // multiplication(matrix2,(float)1.5,matrix3,10);
    // printmatrix(matrix3,10,10);
    // std::cout<<std::endl;

    // //not
    // std::cout<<"Fungsi not"<<std::endl;
    // not_operation(matrixbool,matrixbool2,10,10);
    // printmatrix(matrixbool2,10,10);
    // std::cout<<std::endl;

    // //translation blum
    // std::cout<<"Fungsi translasi"<<std::endl;
    // translation(matrix2,matrix3,10,10,1,1);
    // printmatrix(matrix3,10,10);
    // std::cout<<std::endl;

    // //rotation
    // std::cout<<"Fungsi rotasi"<<std::endl;
    // matrix2[1][1]=0;
    // printmatrix(matrix2,10,10);
    // std::cout<<std::endl;
    // rotation90CCW(matrix2,matrix3,10,10);
    // printmatrix(matrix3,10,10);
    // std::cout<<std::endl;
    // rotation90CW(matrix2,matrix3,10,10);
    // printmatrix(matrix3,10,10);
    // std::cout<<std::endl;

    // //flip
    // std::cout<<"Fungsi flip"<<std::endl;
    // matrix2[1][1]=0;
    // printmatrix(matrix2,10,10);
    // std::cout<<std::endl;
    // vertical_flip(matrix2,matrix3,10,10);
    // printmatrix(matrix3,10,10);
    // std::cout<<std::endl;
    // horizontal_flip(matrix2,matrix3,10,10);
    // printmatrix(matrix3,10,10);
    // std::cout<<std::endl;

    // //zoom
    // std::cout<<"Fungsi zoom in"<<std::endl;
    // zoom_in(matrix2,matrixbig,10,10);
    // printmatrix(matrixbig,20,20);
    // std::cout<<"Fungsi zoom out"<<std::endl;
    // zoom_out(matrix2,matrix3,10,10);
    // printmatrix(matrix3,10,10);
    // std::cout<<std::endl;
    
    // //log
    // std::cout<<"Fungsi log"<<std::endl;
    // matrix2[1][1]=0;
    // printmatrix(matrix2,10,10);
    // std::cout<<std::endl;
    // log_operation(matrix2,10,matrix3,10,10);
    // printmatrix(matrix3,10,10);
    // std::cout<<std::endl;
    // invlog_operation(matrix2,10,matrix3,10,10);
    // printmatrix(matrix3,10,10);
    // std::cout<<std::endl;

    // //power
    // std::cout<<"Fungsi power"<<std::endl;
    // power(matrix2,15,0.3,matrix3,10,10);
    // printmatrix(matrix3,10,10);
    // std::cout<<std::endl;

    int** matrix12 = createMatrix(12,12,124);
    int** matrix13 = createMatrix(12,12,0);
    int** matrix14 = createMatrix(12,12,0);
    //Convolution
    std::cout<<"Fungsi Convolution"<<std::endl;
    double** kernel = createMatrix(3,3,0.1);
    convolute(matrix12,matrix13,kernel,12,12);
    printmatrix(matrix13,12,12);
    translation(matrix13,matrix13,12,12,3,3);
    std::cout<<"Translated"<<std::endl;
    printmatrix(matrix13,12,12);

    //Conv stuff
    std::cout<<"Highpasses filter"<<std::endl;
    highpass1(matrix13,matrix14,12,12);
    printpaddedmatrix(matrix14,10,10);
    highpass2(matrix13,matrix14,12,12);
    printpaddedmatrix(matrix14,10,10);
    highpass3(matrix13,matrix14,12,12);
    printpaddedmatrix(matrix14,10,10);

    std::cout<<"median filter"<<std::endl;
    median_filter(matrix13,matrix14,12,12);
    printpaddedmatrix(matrix14,10,10);

    //EDGE
    // std::cout<<"Gaussian Blur"<<std::endl;
    // gaussian_blur(matrix13,matrix14,12,12);
    // printpaddedmatrix(matrix14,10,10);
    // std::cout<<"Edge gradient"<<std::endl;
    // edge_gradient(matrix13,matrix14,100,12,12);
    // printpaddedmatrix(matrix14,10,10);
    // std::cout<<"Laplace"<<std::endl;
    // edge_laplace(matrix13,matrix14,12,12);
    // printpaddedmatrix(matrix14,10,10);
    // std::cout<<"LoG"<<std::endl;
    // LoG(matrix13,matrix14,12,12);
    // printpaddedmatrix(matrix14,10,10);
    // std::cout<<"Edge Sobel"<<std::endl;
    // edge_sobel(matrix13,matrix14,400,12,12);
    // printpaddedmatrix(matrix14,10,10);
    // std::cout<<"Edge Prewitt"<<std::endl;
    // edge_prewitt(matrix13,matrix14,300,12,12);
    // printpaddedmatrix(matrix14,10,10);
    // std::cout<<"Edge Roberts"<<std::endl;
    // edge_roberts(matrix13,matrix14,100,12,12);
    // printpaddedmatrix(matrix14,10,10);
    // std::cout<<"Edge Canny"<<std::endl;
    // edge_canny(matrix13,matrix14,100,100,12,12);
    // printpaddedmatrix(matrix14,10,10);

    std::cout<<std::endl;

    //garbage
    deleteMatrix(matrix1,10);
    deleteMatrix(matrix2,10);
    deleteMatrix(matrix3,10);
    deleteMatrix(matrix4,10);
}