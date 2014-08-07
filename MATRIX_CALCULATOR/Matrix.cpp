/* 
 * Matrix.cpp
 * This program takes as input one or two matrices and manipulates them according 
 * to a user's selection of options.
 * 
 */


#include "Matrix.h"

//default constructor
Matrix::Matrix()
{
    numRC = 0;
    sizeMatrix = 0;
}





//2nd constructor
Matrix::Matrix(int n)
{
    numRC = n;
    sizeMatrix = n*n;
}





/********************************************************************/
/*This function takes user input integers to populate a matrix.
/*At the end of the function run there is a Vector to rep the matrix
/********************************************************************/

void Matrix::createMatrix()
{  
    for(int i = 0; i < this->sizeMatrix; i++) 
    {
        cin >> intake;
        this->MatrixVector.push_back(intake);
    }
}







/********************************************************************************/
/*This function prints the options that a user can pick to operate on the matrix.
/********************************************************************************/

int Matrix::printOptions()
{
    cout << "  1 :  Take the matrix you just created and add it to a new matrix of the same size. \n";
    cout << "  2 :  Take the matrix you just created and multiply it with a new matrix of the same size. \n";
    cout << "  3 :  Multiply the matrix by a scalar. \n";
    cout << "  4 :  Transpose the matrix. \n";
    cout << "       Enter a number for your option or -1 to exit:  "; 
    int option; 
    cin >> option; 
    return option;
}









/********************************************************************
 *This function is sent two instantiated Matrix objects. It takes "this"
 *Matrix object, adds it to one of the passed Matrices, and then inserts 
 *the addition into a third matrix.
/********************************************************************/

void Matrix::add(Matrix Two, Matrix Three)
{
    for(int i = 0; i < this->sizeMatrix; i++)
    {
        int x = this->MatrixVector[i];
        int y = Two.MatrixVector[i];
        Three.MatrixVector.push_back(x + y);
    }
    cout << "\nAnd after addition... "; Three.printMatrix();
}










/********************************************************************
 *This function prints a matrix that is represented by a vector.
/********************************************************************/

void Matrix::printMatrix()
{
    cout << "\nThe matrix is: ";    
    for(int i = 0; i < this->sizeMatrix; i++) 
    {
        if(i%this->numRC == 0){cout << endl;}
        cout << setw(4) << this->MatrixVector[i];
    }
}










/*******************************************************************************
 *This function is sent two instantiated Matrix objects. It takes "this"
 *Matrix object, multiplies it with one of the passed Matrices, and then inserts 
 *the multiplication into the third matrix. For ease of use, the matrices were
 *converted to 2-dimensional arrays. The result is printed from the function.
/******************************************************************************/

void Matrix::multiply(Matrix Two, Matrix Three)
{
    int k = 0;
    int MatrixArrayOne[this->numRC][this->numRC];
    do
    {   for(int j = 0; j < this->numRC; j++)
        {   for(int i = 0; i < this->numRC; i++)
            {   int x = this->MatrixVector[k];
                MatrixArrayOne[j][i] = x; 
                k++;
            }
        }
    } while(k < this->sizeMatrix);
        
    int r = 0;
    int MatrixArrayTwo[this->numRC][this->numRC];
    do
    {   for(int f = 0; f < this->numRC; f++)
        {   for(int t = 0; t < this->numRC; t++)
            {   int x = Two.MatrixVector[r];
                MatrixArrayTwo[f][t] = x; 
                r++;
            }
        }
    } while(r < this->sizeMatrix);    
    
    int MatrixArrayThree[this->numRC][this->numRC];
    do{   
        for(int i = 0; i < this->numRC;i++)
        {
            for(int j = 0; j < this->numRC;j++)
            {
                MatrixArrayThree[i][j]=0;
                for(int k=0;k < this->numRC;k++)
                {
                    MatrixArrayThree[i][j]= MatrixArrayThree[i][j]+(MatrixArrayOne[i][k] * MatrixArrayTwo[k][j]);
                }
            }
        }
    } while(r < this->sizeMatrix);   

    
    cout << "\nAnd after multiplication... \n"; 
    for(int l = 0; l < this->numRC; l++)
    {
        for(int m = 0; m < this->numRC; m++)
        {
            cout << setw(4) << MatrixArrayThree[l][m]; 
        }
        cout << endl;
    }
}











/******************************************************************************/
/* This functin takes "this" matrix object, namely the vector that represents
/* the vector, and transposes it. The matrix is printed out from the function.
/******************************************************************************/

void Matrix::transpose()
{
    int k = 0;
    int MatrixArrayOne[this->numRC][this->numRC];
    do
    {   for(int j = 0; j < this->numRC; j++)
        {   for(int i = 0; i < this->numRC; i++)
            {   int x = this->MatrixVector[k];
                MatrixArrayOne[j][i] = x; 
                k++;
            }
        }
    } while(k < this->sizeMatrix);
    
    for(int j=0;j< this->numRC;j++)
    {
        for(int i=0;i<this->numRC;i++)
        {
            cout << setw(4) << MatrixArrayOne[i][j];
        }
    cout << endl;
    }
    
    
}


/******************************************************************************
 * This function takes as input a second matrix and a scalar, input by the user.
 * The matrix is multiplied by the scalar and the results are used to populate a
 * new second matrix object's vector. Results are printed from the function.
/******************************************************************************/

void Matrix::multiplyByScalar(Matrix Two, int scalar)
{
    for(int i = 0; i < this->sizeMatrix; i++)
    {
        int x = this->MatrixVector[i] * scalar;
        Two.MatrixVector.push_back(x);
    }
    Two.printMatrix();
}







