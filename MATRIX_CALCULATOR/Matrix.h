/* 
 * Matrix.h
 *
 * This program takes as input one or two matrices and manipulates them according 
 * to a user's selection of options.
 */

#ifndef MATRIX_H
#define	MATRIX_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Matrix {
    
    private:
        int intake, numRC, sizeMatrix;
        vector<int> MatrixVector;

    public:
        Matrix();
        Matrix(int);
        void createMatrix();
        int printOptions();
        void add(Matrix, Matrix);
        void printMatrix();
        void multiply(Matrix, Matrix);
        void multiplyByScalar(Matrix, int);
        void transpose();
};





#endif	/* MATRIX_H */

