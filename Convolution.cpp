class Convolution{
    private:
    
    //  ATTRIBUTES    
    int method;
    int convKernel[3][3];

    // CONTRUCTORS
    Convolution(){
        method = 0;

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                convKernel[i][j] = 0;
            }                    
        }
    }
    
    public:

    void convolute(int **input, int **output, int **kernel){
        int convolute = 0; // This holds the convolution results for an index.
        int x, y; // Used for input matrix index

        // Fill output matrix: rows and columns are i and j respectively
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                x = i;
                y = j;

                // Kernel rows and columns are k and l respectively
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        // Convolute here.
                        convolute += kernel[k][l] * input[x][y];
                        y++; // Move right.
                    }
                    x++; // Move down.
                    y = j; // Restart column position
                }
                output[i][j] = convolute; // Add result to output matrix.
                convolute = 0; // Needed before we move on to the next index.
            }
        }
    }

    void setKernel(int **kernel, int kernelsize){
        for (int i = 0; i < kernelsize; i++){
            for (int j = 0; j < kernelsize; j++){
                convKernel[i][j] = kernel[i][j];
            }                    
        }
    }

    
    
};