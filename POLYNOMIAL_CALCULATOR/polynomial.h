/* 
 * polynomial.h
 *  
 * Created on March 2, 2014, 1:21 PM
 * 
 * ********* POLYNOMIAL CALCULATOR ********
 * This program takes as input one or two matrices and manipulates them according 
 * to a user's selection of options.
 
 */

#ifndef POLYNOMIAL_H
#define	POLYNOMIAL_H

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Poly{

    private:
        int coefficent;
        int exponent;
        
        struct term {
            int coef;
            int exp;
        };
        
        vector<term> PolyVector;
        
    public:
        int OldCoef, NewCoeff, degree, numTerms, constInt;  
        char con;
                
        Poly(); // default constructor
        Poly(int, int); // Constructor #2
        void prompt(); // prompts user for polynomial information
        void set_poly(int, int); // load polynomial in its entirety
        void print() const; // print a polynom.
        void printOptions();
        void add(Poly, Poly); // adds two polynomials by creating a third polynomial
        int getDegree() const;
        int getCoefficient(int) const; // Returns the coefficient of the x p o w e r term.
        void changeCoefficient(int, int); // Replaces coeff. of term with new coeff.
        
        void multiply(int); // multiply a polynom. by a scalar
        
        
};
        
        
    
#endif	/* POLYNOMIAL_H */

