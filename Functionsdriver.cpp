#include "Functions.cpp"
#include "Convolution.cpp"
#include <iostream>

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
void deleteMatrix(int** matrix, int rows){
    for (int i = 0; i < rows; ++i)
        {delete [] matrix[i];}
    delete [] matrix;
}

int main()
{   
    int** matrix1 = createMatrix(10,10,0);
    int** matrix2 = createMatrix(10,10,124);
    int** matrix3 = createMatrix(10,10,255);
    int** matrix4 = createMatrix(10,10,255);

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

    //power
    std::cout<<"Fungsi power"<<std::endl;
    power(matrix2,15,0.3,matrix3,10,10);
    printmatrix(matrix3,10,10);
    std::cout<<std::endl;

    //Convolution

    //garbage
    deleteMatrix(matrix1,10);
    deleteMatrix(matrix2,10);
    deleteMatrix(matrix3,10);
    deleteMatrix(matrix4,10);
}