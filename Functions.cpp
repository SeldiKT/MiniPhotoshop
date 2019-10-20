#include <stdio.h>
#include <iostream>
#include <math.h>

void selectionSort(int a[], int n) {
   int i, j, min, temp;
   for (i = 0; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j < n; j++)
         if (a[j] < a[min])
            min = j;
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
   }
}

int** createMatrix(int rows, int cols, int initValue){
    //alloc matrix
    int** matrix = new int*[rows];
    
    for (int i = 0; i < rows; ++i){
        matrix[i] = new int[cols];
    }

    //Init matrix
    for(int i =0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            matrix[i][j] = initValue;
        }
    }

    return matrix;
}
bool** createMatrix(int rows, int cols, bool initValue){
    //alloc matrix
    bool** matrix = new bool*[rows];
    
    for (int i = 0; i < rows; ++i){
        matrix[i] = new bool[cols];
    }

    //Init matrix
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            matrix[i][j] = initValue;
        }
    }

    return matrix;
}
double** createMatrix(int rows, int cols, double initValue){
    //alloc matrix
    double** matrix = new double*[rows];
    
    for (int i = 0; i < rows; ++i){
        matrix[i] = new double[cols];
    }

    //Init matrix
    for(int i =0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            matrix[i][j] = initValue;
        }
    }

    return matrix;
}
void deleteMatrix(int** matrix, int rows){
    for (int i = 0; i < rows; ++i)
        {delete [] matrix[i];}
    delete [] matrix;
}
void printmatrix(int** matrix, int rows, int cols){
    for(int i =0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void printmatrix(bool** matrix, int rows, int cols){
    for(int i =0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void printmatrix(double** matrix, int rows, int cols){
    for(int i =0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void printpaddedmatrix(int** matrix, int rows, int cols){
    for(int i =1; i<=rows; i++){
        for(int j = 1; j<=cols; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void biner(int**  A, bool**  B, int T, int N, int M)
/* Membuat citra biner dari citra A berdasarkan nilai ambang
(threshold) T yang dispesifikasikan. Ukuran citra adalah N  M.
citra_biner adalah tipe data untuk citra biner).
*/
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
		{
			if (A[i][j] < T)
				B[i][j] = 0;
			else
				B[i][j] = 1;
		}
}

void negatif(int** A, int** B, int N, int M)
/* Membuat citra negatif dari citra A. Hasilnya disimpan di
dalam citra B. Ukuran citra adalah N  M.
*/
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
		{
			B[i][j] = 255 - A[i][j];
		}
}

void image_brightening(int** A, int b, int** B, int N, int M)
/* Pencerahan citra dengan menjumlahkan setiap pixel di dalam citra A dengan
sebuah skalar b. Hasil disimpan di dalam citra B. Citra berukuran N  M. */
{
	int i, j, temp;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
		{
			std::cout<< A[i][j] <<" "<< B[i][j] <<std::endl;
			temp = A[i][j] + b;
			std::cout<< temp <<std::endl;
			/* clipping */
			if (temp < 0)
				B[i][j] = 0;
			else
				if (temp > 255)
					B[i][j] = 255;
				else
					B[i][j] = temp;
		}
}

void grayscale(int** R, int** G, int** B, int** Gray, int N, int M) {
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
		{
			Gray[i][j] = 0.299 * R[i][j] + 0.587 * G[i][j] + 0.144 * B[i][j];
		}
}

void addvalues(int** A, int** B, int** C, int N, int M) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			int temp = A[i][j] + B[i][j];
			if (temp > 255) {
				C[i][j] = 255;
			}
			else {
				C[i][j] = temp;
			}
			temp = 0;
		}
	}
}
void substractvalues(int** A, int** B, int** C, int N, int M) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			int temp = A[i][j] - B[i][j];
			if (temp <= 0) {
				C[i][j] = 0;
			}
			else {
				C[i][j] = temp;
			}
			temp=0;
		}
	}
}

void addvalues(int** A, int B, int** C, int N, int M) {
	int i, j, temp;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			int temp = B + A[i][j];
			if (temp > 255) {
				C[i][j] = 255;
			}
			else {
				C[i][j] = temp;
			}
			temp = 0;
		}
	}
}
void substractvalues(int** A, int B, int** C, int N, int M) {
	int i, j, temp;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			int temp = A[i][j] - B;
			if (temp <= 0) {
				C[i][j] = 255;
			}
			else {
				C[i][j] = temp;
			}
			temp=0;
		}
	}
}

void multiplication(int** A, float** B, int** C, int N)
/* Mengalikan buah citra A dengan matriks koreksi B menjadi citra C.
Citra A, matriks B, dan hasil perkalian C berukuran N  N.
*/
{
	int i, j, k, temp;
	for (i = 0; i <= N - 1; i++)
		for (j = 0; j <= N - 1; j++)
		{
			temp = 0;
			for (k = 0; k <= N - 1; k++)
			{
				temp = temp + A[i][k] * B[k][j];
				/* clipping */
				if (temp < 0)
					C[i][j] = 0;
				else
					if (temp > 255)
						C[i][j] = 255;
					else
						C[i][j] = temp;
			}
		}
}
void multiplication(int** A, float B, int** C, int N)
/* Mengalikan buah citra A dengan matriks koreksi B menjadi citra C.
Citra A, matriks B, dan hasil perkalian C berukuran N  N.
*/
{
	int i, j, temp;
	for (i = 0; i <= N - 1; i++)
		for (j = 0; j <= N - 1; j++)
		{
			temp = A[i][j] * B;
			if (temp < 0) {
				C[i][j] = 0;
			}
			else {
				if (temp > 255) {
					C[i][j] = 255;
				}
				else {
					C[i][j] = (int)temp;
				}
			}
		}
}

void not_operation(bool** A, bool** B, int N, int M)
/* Membuat citra komplemen dari citra biner A.
Komplemennya disimpan di dalam B. Ukuran citra A
adalah N  M.
*/
{
	int i, j;
	for (i = 0; i <= N - 1; i++)
		for (j = 0; j <= M - 1; j++)
		{
			B[i][j] = !A[i][j];
		}
}

void translation(int** A, int** B, int N, int M, int m, int n)
/* Mentranslasi citra A sejauh m, n menjadi citra B. Ukuran citra N  M. */
// CUMA BISA POSITIF VALUE
{
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < M; j++)
		{
			B[i][j] = 0;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < N; j++)
		{
			B[j][i] = 0;
		}
	}
	for (i = m; i <= N - 1; i++) {
		for (j = n; j <= M - 1; j++)
		{
			B[i][j] = A[i][j];//NOTDONE
		}
	}
}

void rotation90CCW(int** A, int** B, int N, int M)
/* Rotasi citra A sejauh 90 berlawanan arah jarum jam (CCW = Clock Counterwise). Ukuran citra adalah N  M. Hasil rotasi disimpan di dalam citra B.
*/
{ 
	int i, j, k;
	for (i=0; i<=N-1; i++)
	{
		k=M-1;
		for (j=0; j<=M-1; j++)
		{
			B[k][i]=A[i][j];
			k--;
		}
	}
}
void rotation90CW(int** A, int** B, int N, int M)
/* Rotasi citra A sejauh 90 searah jarum jam (CW = Clock-wise).
Ukuran citra adalah N  M. Hasil rotasi disimpan di dalam cira B.
*/
{ 
	int i, j, k;
	k=M-1;
	for (i=0; i<=N-1; i++)
	{
		for (j=0; j<=M-1; j++)
		{
			B[j][k]=A[i][j];
		}
		k--;
	}
}
void horizontal_flip(int** A, int** B, int N, int M)
/* Flipping vertikal (pencerminan terhadap sumbu-X) terhadap citar A. 
Ukuran citra adalah N  M. Hasil flipping disimpan di dalam citra B.
*/
{ 
	int i, j, k;
	for (i=0; i<=N-1; i++)
	{
		k= M-1;
		for (j=0; j<=M-1; j++)
		{
			B[i][k]=A[i][j];
			k--;
		}
	}
}
void vertical_flip(int** A, int** B, int N, int M)
/* Flipping vertikal (pencerminan terhadap sumbu-X) terhadap citar A. 
Ukuran citra adalah N  M. Hasil flipping disimpan di dalam citra B.
*/
{ 
	int i, j, k;
	k=N-1;
	for (i=0; i<=N-1; i++)
	{
		for (j=0; j<=M-1; j++)
		{
			B[k][j]=A[i][j];
		}
		k--;
	}
}

void zoom_in(int** A, int** B, int N, int M)
/* perbesaran citra A dengan faktor skala 2
Ukuran citra adalah N  M. Hasil perbesaran disimpan dalam citra B.
*/
// B ukurannya dua kali dari A
{
	int i, j, k, m, n;
	m=0; n=0;
	for (i=0; i<=N-1; i++)
	{
		for (j=0; j<=M-1; j++)
		{
			B[m][n]= A[i][j];
			B[m][n+1]= A[i][j];
			B[m+1][n]= A[i][j];
			B[m+1][n+1]= A[i][j];
			n=n+2;
		}
		m=m+2;
		n=0;
	}
}
void zoom_out(int** A, int** B, int N, int M)
/* perbesaran citra A dengan faktor skala 1/2
Ukuran citra adalah N  M. Hasil perbesaran disimpa d dalam citra B.
*/
// N dan M Ukuran A, B sebisa mungkin ukurannya setengah dari A
{
	int i, j, k, m, n;
	m=0;
	for (i=0; i<=N-1; i+=2)
	{
		n=0;
		int temp = 0;
		for (j=0; j<=M-1; j+=2)
		{
			temp = 0;
			temp += A[i][j];
			temp += A[i][j+1];
			temp += A[i+1][j];
			temp += A[i+1][j+1];
			B[m][n] = temp/4 ;
			n+=1;
		}
		
		m+=1;
	}
}

void log_operation(int** A, int c, int** B, int N, int M)
{
	int i, j, temp;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
		{
			temp = c*log(A[i][j]+1) ;
			/* clipping */
			if (temp < 0)
				B[i][j] = 0;
			else
				if (temp > 255)
					B[i][j] = 255;
				else
					B[i][j] = temp;
		}
}
void invlog_operation(int** A, int c, int** B, int N, int M)
{
	int i, j, temp;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
		{
			temp = c*exp(A[i][j]+1) ;
			/* clipping */
			if (temp < 0)
				B[i][j] = 0;
			else
				if (temp > 255)
					B[i][j] = 255;
				else
					B[i][j] = temp;
		}
}
void power(int** A, int c, float y, int** B, int N, int M)
{
	int i, j, temp;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
		{
			temp = c*(pow(A[i][j],y)) ;
			/* clipping */
			if (temp < 0)
				B[i][j] = 0;
			else
				if (temp > 255)
					B[i][j] = 255;
				else
					B[i][j] = temp;
		}
}

void median_filter(int **input, int **output, int rows, int cols){
		 // This holds the convolution results for an index.
        int x, y; // Used for input matrix index

        // Fill output matrix: rows and columns are i and j respectively
        for (int i = 1; i < rows-1; i++)
        {
            for (int j = 1; j < cols-1; j++)
            {
                x = i-1;
                y = j-1;
				int convolute[9] = {0};

                // Kernel rows and columns are k and l respectively
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        // Convolute here.
                        convolute[k*3+l] = input[x][y];
						// std::cout<<input[x][y]<<std::endl;
                        y++; // Move right.
                    }
                    x++; // Move down.
                    y = j-1; // Restart column position
                }
				// std::cout<<convolute<<std::endl;
				selectionSort(convolute,9);
				// for (int z = 0; z < 9; z++){
				// 	std::cout<< convolute[z] <<" ";
				// }
				// std::cout<<std::endl;
				output[i][j] = (convolute[3]+convolute[4])/2;
				 // Add result to output matrix.
            }
        }
}

void convolute(int **input, int **output, double **kernel, int rows, int cols){
        int convolute = 0; // This holds the convolution results for an index.
        int x, y; // Used for input matrix index

        // Fill output matrix: rows and columns are i and j respectively
        for (int i = 1; i < rows-1; i++)
        {
            for (int j = 1; j < cols-1; j++)
            {
                x = i-1;
                y = j-1;

                // Kernel rows and columns are k and l respectively
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        // Convolute here.
                        convolute += kernel[k][l] * input[x][y];
						// std::cout<<input[x][y]<<std::endl;
                        y++; // Move right.
                    }
                    x++; // Move down.
                    y = j-1; // Restart column position
                }
				// std::cout<<convolute<<std::endl;
                if (convolute < 0)
					output[i][j] = 0;
				else
					if (convolute > 255)
						output[i][j] = 255;
					else
						output[i][j] = convolute;
				 // Add result to output matrix.

                convolute = 0; // Needed before we move on to the next index.
            }
        }
}

void highpass1(int **input, int **output, int rows, int cols){
	//detects edge
	double** kernel = createMatrix(3,3,1.0);
	kernel[0][0]=-1;
	kernel[0][1]=-1;
	kernel[0][2]=-1;
	kernel[1][0]=-1;
	kernel[1][1]=8;
	kernel[1][2]=-1;
	kernel[2][0]=-1;
	kernel[2][1]=-1;
	kernel[2][2]=-1;
	// printmatrix(kernel,3,3);
	convolute(input,output,kernel,rows,cols);
}
void highpass2(int **input, int **output, int rows, int cols){
	double** kernel = createMatrix(3,3,1.0);
	kernel[0][0]=-1;
	kernel[0][1]=-1;
	kernel[0][2]=-1;
	kernel[1][0]=-1;
	kernel[1][1]=9;
	kernel[1][2]=-1;
	kernel[2][0]=-1;
	kernel[2][1]=-1;
	kernel[2][2]=-1;
	// printmatrix(kernel,3,3);
	convolute(input,output,kernel,rows,cols);
}
void highpass3(int **input, int **output, int rows, int cols){
	double** kernel = createMatrix(3,3,1.0);
	kernel[0][0]=0;
	kernel[0][1]=-1;
	kernel[0][2]=0;
	kernel[1][0]=-1;
	kernel[1][1]=5;
	kernel[1][2]=-1;
	kernel[2][0]=0;
	kernel[2][1]=-1;
	kernel[2][2]=0;
	// printmatrix(kernel,3,3);
	convolute(input,output,kernel,rows,cols);
}

void unsharp_masking(int **input, int **output, int rows, int cols){
	int** temp = createMatrix(rows,cols,0);
	gaussian_blur(input, temp, rows, cols);
	int** highpass = createMatrix(rows,cols,0);
	substractvalues(input, temp, highpass, rows, cols);
	addvalues(input,highpass,output,rows,cols);
}

void highboost_filter(int **input, int **output, int rows, int cols, float alpha){
	int** temp = createMatrix(rows,cols,0);
	gaussian_blur(input, temp, rows, cols);
	int** highpass = createMatrix(rows,cols,0);
	substractvalues(input, temp, highpass, rows, cols);
	multiplication(input,alpha-1,temp,rows);
	addvalues(temp,highpass,output,rows,cols);
}

void edge_gradient(int **input, int **output, float Threshold, int rows, int cols){
		int convolute_x = 0; // This holds the convolution results for an index.
        int convolute_y= 0;
		int convoluted = 0;
		int x, y; // Used for input matrix index
		int** kernel_x = createMatrix(2,2,1);
		kernel_x[0][0]=-1;kernel_x[1][0]=-1;kernel_x[0][1]=1;kernel_x[1][1]=1;
		int** kernel_y = createMatrix(2,2,1);
		kernel_y[0][0]=1;kernel_y[1][0]=-1;kernel_y[0][1]=1;kernel_y[1][1]=-1;

        // Fill output matrix: rows and columns are i and j respectively
        for (int i = 1; i < rows-1; i++)
        {
            for (int j = 1; j < cols-1; j++)
            {
                
				x = i-1;
                y = j-1;
                // Kernel rows and columns are k and l respectively
                for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        // Convolute here.
                        convolute_x += kernel_x[k][l] * input[x][y];
                        y++; // Move right.
                    }
                    x++; // Move down.
                    y = j-1; // Restart column position
                }

				x = i-1;
                y = j-1;
				for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        // Convolute here.
                        convolute_y += kernel_y[k][l] * input[x][y];
                        y++; // Move right.
                    }
                    x++; // Move down.
                    y = j-1; // Restart column position
                }
				convoluted = abs(convolute_x) + abs(convolute_y);
				if(convoluted>=Threshold){
					output[i][j] = 255; 
				}
				else{
					output[i][j]= 0;
				}
				
				convolute_x = 0;
				convolute_y = 0;
                convoluted = 0; // Needed before we move on to the next index.
            }
        }
}

void gaussian_blur(int **input, int **output, int rows, int cols){
	double** kernel = createMatrix(3,3,1.0);
	kernel[0][0]=1.0/16;
	kernel[0][1]=1.0/8;
	kernel[0][2]=1.0/16;
	kernel[1][0]=1.0/8;
	kernel[1][1]=1.0/4;
	kernel[1][2]=1.0/8;
	kernel[2][0]=1.0/16;
	kernel[2][1]=1.0/8;
	kernel[2][2]=1.0/16;
	// printmatrix(kernel,3,3);
	convolute(input,output,kernel,rows,cols);
}

void edge_laplace(int **input, int **output, int rows, int cols){
	double** kernel = createMatrix(3,3,1.0);
	kernel[0][0]=0;
	kernel[0][1]=1;
	kernel[0][2]=0;
	kernel[1][0]=1;
	kernel[1][1]=-4;
	kernel[1][2]=1;
	kernel[2][0]=0;
	kernel[2][1]=1;
	kernel[2][2]=0;
	// printmatrix(kernel,3,3);
	convolute(input,output,kernel,rows,cols);
}

void LoG(int **input, int **output, int rows, int cols){
	int** temp = createMatrix(rows,cols,0);
	gaussian_blur(input, temp, rows, cols);
	edge_laplace(temp ,output,rows,cols);
}

void edge_sobel(int **input, int **output, float Threshold, int rows, int cols){
		int convolute_x = 0; // This holds the convolution results for an index.
        int convolute_y= 0;
		int convoluted = 0;
		int x, y; // Used for input matrix index
		double** kernel_x = createMatrix(3,3,1.0);
		kernel_x[0][0]=-1;
		kernel_x[0][1]=0;
		kernel_x[0][2]=1;
		kernel_x[1][0]=-2;
		kernel_x[1][1]=0;
		kernel_x[1][2]=2;
		kernel_x[2][0]=-1;
		kernel_x[2][1]=0;
		kernel_x[2][2]=1;
		double** kernel_y = createMatrix(3,3,1.0);
		kernel_y[0][0]=1;
		kernel_y[0][1]=2;
		kernel_y[0][2]=1;
		kernel_y[1][0]=0;
		kernel_y[1][1]=0;
		kernel_y[1][2]=0;
		kernel_y[2][0]=-1;
		kernel_y[2][1]=-2;
		kernel_y[2][2]=-1;

        // Fill output matrix: rows and columns are i and j respectively
        for (int i = 1; i < rows-1; i++)
        {
            for (int j = 1; j < cols-1; j++)
            {
				x = i-1;
                y = j-1;
                // Kernel rows and columns are k and l respectively
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        // Convolute here.
                        convolute_x += kernel_x[k][l] * input[x][y];
                        y++; // Move right.
                    }
                    x++; // Move down.
                    y = j-1; // Restart column position
                }

				x = i-1;
                y = j-1;
				for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        // Convolute here.
                        convolute_y += kernel_y[k][l] * input[x][y];
                        y++; // Move right.
                    }
                    x++; // Move down.
                    y = j-1; // Restart column position
                }
				convoluted = abs(convolute_x) + abs(convolute_y);
				if(convoluted>=Threshold){
					output[i][j] = 255; 
				}
				else{
					output[i][j]= 0;
				}
				
				convolute_x = 0;
				convolute_y = 0;
                convoluted = 0; // Needed before we move on to the next index.
            }
        }
}

void edge_prewitt(int **input, int **output, float Threshold, int rows, int cols){
		int convolute_x = 0; // This holds the convolution results for an index.
        int convolute_y= 0;
		int convoluted = 0;
		int x, y; // Used for input matrix index
		double** kernel_x = createMatrix(3,3,1.0);
		kernel_x[0][0]=-1;
		kernel_x[0][1]=0;
		kernel_x[0][2]=1;
		kernel_x[1][0]=-1;
		kernel_x[1][1]=0;
		kernel_x[1][2]=1;
		kernel_x[2][0]=-1;
		kernel_x[2][1]=0;
		kernel_x[2][2]=1;
		double** kernel_y = createMatrix(3,3,1.0);
		kernel_y[0][0]=1;
		kernel_y[0][1]=1;
		kernel_y[0][2]=1;
		kernel_y[1][0]=0;
		kernel_y[1][1]=0;
		kernel_y[1][2]=0;
		kernel_y[2][0]=-1;
		kernel_y[2][1]=-1;
		kernel_y[2][2]=-1;

        // Fill output matrix: rows and columns are i and j respectively
        for (int i = 1; i < rows-1; i++)
        {
            for (int j = 1; j < cols-1; j++)
            {
				x = i-1;
                y = j-1;
                // Kernel rows and columns are k and l respectively
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        // Convolute here.
                        convolute_x += kernel_x[k][l] * input[x][y];
                        y++; // Move right.
                    }
                    x++; // Move down.
                    y = j-1; // Restart column position
                }

				x = i-1;
                y = j-1;
				for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        // Convolute here.
                        convolute_y += kernel_y[k][l] * input[x][y];
                        y++; // Move right.
                    }
                    x++; // Move down.
                    y = j-1; // Restart column position
                }
				convoluted = abs(convolute_x) + abs(convolute_y);
				if(convoluted>=Threshold){
					output[i][j] = 255; 
				}
				else{
					output[i][j]= 0;
				}
				
				convolute_x = 0;
				convolute_y = 0;
                convoluted = 0; // Needed before we move on to the next index.
            }
        }
}

void edge_roberts(int **input, int **output, float Threshold, int rows, int cols){
	int convolute_x = 0; // This holds the convolution results for an index.
        int convolute_y= 0;
		int convoluted = 0;
		int x, y; // Used for input matrix index
		int** kernel_x = createMatrix(2,2,1);
		kernel_x[0][0]=1;kernel_x[1][0]=0;kernel_x[0][1]=0;kernel_x[1][1]=-1;
		int** kernel_y = createMatrix(2,2,1);
		kernel_y[0][0]=0;kernel_y[1][0]=-1;kernel_y[0][1]=1;kernel_y[1][1]=0;

        // Fill output matrix: rows and columns are i and j respectively
        for (int i = 1; i < rows-1; i++)
        {
            for (int j = 1; j < cols-1; j++)
            {
                
				x = i-1;
                y = j-1;
                // Kernel rows and columns are k and l respectively
                for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        // Convolute here.
                        convolute_x += kernel_x[k][l] * input[x][y];
                        y++; // Move right.
                    }
                    x++; // Move down.
                    y = j-1; // Restart column position
                }

				x = i-1;
                y = j-1;
				for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        // Convolute here.
                        convolute_y += kernel_y[k][l] * input[x][y];
                        y++; // Move right.
                    }
                    x++; // Move down.
                    y = j-1; // Restart column position
                }
				convoluted = abs(convolute_x) + abs(convolute_y);
				if(convoluted>=Threshold){
					output[i][j] = 255; 
				}
				else{
					output[i][j]= 0;
				}
				
				convolute_x = 0;
				convolute_y = 0;
                convoluted = 0; // Needed before we move on to the next index.
            }
        }
}

void edge_canny(int **input, int **output, float Gradient_T, float Canny_T, int rows, int cols){
	int** temp1 = createMatrix(rows,cols,0);
	int** temp2 = createMatrix(rows,cols,0);
	gaussian_blur(input, temp1, rows, cols);
	edge_roberts(temp1 ,temp2 , Gradient_T, rows, cols);
	for(int i =1; i<rows-1; i++){
		for(int j =1; j<cols-1; j++){
			if(temp2[i][j] >= Canny_T){
				output[i][j] = 255; 
			}
			else{
				output[i][j]= 0;
			}
		}
	}
	
}


