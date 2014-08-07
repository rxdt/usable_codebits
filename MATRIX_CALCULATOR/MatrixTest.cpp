/* 
 * MatrixTest.cpp
 *
 * This program takes as input one or two matrices and manipulates them according 
 * to a user's selection of options.
 
 */

#include "Matrix.h"




int main() {
    
    cout << "Enter an integer for the # of rows/columns:  ";
    int n; cin >> n;
    cout << "Enter integers separated by spaces: ";
    Matrix One(n); 
    One.createMatrix();
    One.printMatrix();
    Matrix Two(n); Matrix Three(n);
    
    cout << "\nWhich of the following options would you like to do? \n";
    cout << "______________________________________________________\n";
    int option = One.printOptions();
    
    switch(option)
    {
        case 1:
            cout << "\nFor the second matrix, enter integers separated by spaces: ";  
            Two.createMatrix(); Two.printMatrix(); One.add(Two, Three);
            break;
            ;
        case 2:
            cout << "\nFor the second matrix, enter integers separated by spaces: ";
            Two.createMatrix(); Two.printMatrix(); One.multiply(Two, Three);
            break;
            ;
        case 3:
            cout << "Enter the scalar would you like to multiply by:  ";
            int scalar; cin >> scalar;
            One.multiplyByScalar(Two, scalar);
            break;
        case 4:
            cout << "The matrix transposed is: \n";
            One.transpose();
            break;
        default:
            break;
    }
    
   
    
    return 0;
}