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

    //Print Inisial matrix
    printmatrix(matrix2,10,10);
    std::cout<<std::endl;
    //Biner
    std::cout<<"Fungsi Biner"<<std::endl;;
    biner(matrix2,matrix3,120,10,10);
    printmatrix(matrix3,10,10);
    biner(matrix2,matrix3,125,10,10);
    printmatrix(matrix3,10,10);
    std::cout<<std::endl;
    //negatif
    std::cout<<"Fungsi Negatif"<<std::endl;;
    negatif(matrix2,matrix3,10,10);
    printmatrix(matrix3,10,10);
    std::cout<<std::endl;
    //image brightening
    std::cout<<"Fungsi brighten"<<std::endl;;
    image_brightening(matrix2,10,matrix3,10,10);
    printmatrix(matrix3,10,10);
    std::cout<<std::endl;
    //grayscale
    std::cout<<"Fungsi grayscale"<<std::endl;;
    grayscale(matrix1,matrix2,matrix4,matrix3,10,10);
    printmatrix(matrix3,10,10);
    std::cout<<std::endl;
    //addvalue
    std::cout<<"Fungsi add"<<std::endl;;
    addvalues(matrix1,matrix2,matrix3,10,10);
    printmatrix(matrix1,10,10);
    addvalues(matrix1,69,matrix3,10,10);
    printmatrix(matrix3,10,10);
    std::cout<<std::endl;
    //substract
    //multiplication
    //not
    //translation
    //rotation
    //flip
    //zoom
    //log
    //power

    //garbage
    deleteMatrix(matrix1,10);
    deleteMatrix(matrix2,10);
    deleteMatrix(matrix3,10);
    deleteMatrix(matrix4,10);
}