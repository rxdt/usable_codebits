/* 
 * Polynomial.cpp
 * Created on March 2, 2014, 1:21 PM
 ********** POLYNOMIAL CALCULATOR ***********
 * This program takes in two user-input polynomials and conducts a set of 
 * operations on them.
 */

#include "polynomial.h"


// default constructor
Poly::Poly()
{
    coefficent = 0;
    degree = 0;
} 
    



    
//2nd constructor
Poly::Poly(int p, int n)
{ 
    degree = p;
    numTerms = n;  
}
    





/****************************************************************************
 * This function takes "this" polynomial object and prints and formats
 * it according to whether there is a scalar constant, a coefficient of 1,
 * or an exponent of 1.
/****************************************************************************/

void Poly::print() const
{
    for(int i=0; i < PolyVector.size(); i++)
    {
        if(PolyVector[i].coef == 1 && PolyVector[i].exp == 1)
        {
            cout << "x"; 
        }
        else if(PolyVector[i].coef == 1 && PolyVector[i].exp != 1)
        {
            cout << "x^" << PolyVector[i].exp;
        }
        else if(PolyVector[i].coef != 1 && PolyVector[i].exp == 1)
        {
            cout << PolyVector[i].coef << "x";
        }
        else if(PolyVector[i].coef != 1 && PolyVector[i].exp != 1 && PolyVector[i].exp != 0)
        {
            cout << PolyVector[i].coef << "x^" << PolyVector[i].exp;
        }
        else if(PolyVector[i].exp == 0)
        {
            cout << PolyVector[i].coef;
        }
        if(i+1 != PolyVector.size())
        {cout << " + ";}
    }
}







/* ************************************************************************
 * (n = number of terms, d = degree)
 * In this function the polynomial is loaded in its entirety. For each part of 
 * the polynomial, the coefficient and exponent are obtained and used to create
 * a struct. Each struct is pushed into a vector. The vector represents the 
 * entire polynomial.
 *************************************************************************/

void Poly::set_poly(int n, int d)
{        
    for(int i=0; i < n; i++)
    {
        if(n == 1 && (con == 'n' || con == 'N'))
        {
            cout << "What's the power of your variable?";
            cin >> exponent;
            cout << "What's the coefficient of that power? ";
            cin >> coefficent;
        }
        else if(n > 1 && (con == 'y' || con == 'Y'))
        {
            if(i == 0)
            {
                exponent = d;
                cout << "What's the coefficient of the highest power term? ";
                cin >> coefficent;
            }
            else if(i == n-1)
            {
                cout << "Enter the scalar constant:  ";
                cin >> coefficent;
                exponent = 0;
            }
            else
            {
                cout << "What's the power of the next highest term? ";
                cin >> exponent;
                cout << "What's the coefficient of that term? ";
                cin >> coefficent;
            }
        }
        else if(n > 1 && (con == 'n' || con == 'N') && i==0)
        {
            exponent = d;
            cout << "What's the coefficient of that power? ";
            cin >> coefficent;
        }
        else if(n > 1 && (con == 'n' || con == 'N'))
        {
            cout << "What's the next highest power? ";
            cin >> exponent;
            cout << "What's the coefficient of that power? ";
            cin >> coefficent;
        }
        term s;
        s.coef = coefficent;
        s.exp = exponent;
        PolyVector.push_back(s);
    } // close outer for loop
    
    if(n == 1 && (con == 'y' || con == 'Y'))
    {
        cout << "Enter the constant:  ";
        cin >> coefficent;
        term s;
        s.coef = coefficent;
        s.exp = 0;
        PolyVector.push_back(s);
    }

    
}    
    






/****************************************************************************
 * This function prompts a user for information about the polynomial about to 
 * be loaded. It also determines whether a constant is in the polynomial. 
 ****************************************************************************/

void Poly::prompt()
{
    cout << "How many terms will your polynomial have?  ";
    cin >> numTerms;
    cout << "Will the polynomial contain a constant? Enter y for yes, n for no:  ";
    cin >> con;
    if(con == 'n' || (con == 'y' || con == 'Y') && numTerms > 1)
    {
        cout << "What's the highest power of the polynomial?  ";
        cin >> degree;
    }
}
    







/****************************************************************************
 * This function takes the two polynomial objects and uses the values of 
 * the coefficients and exponents in the struct of the vector of each
 * polynomial to perform addition of the two polynomial objects. 
 ****************************************************************************/

void Poly::add(Poly first, Poly second)
{
    Poly temp;
    int i=0, j=0; 

    while((i < first.PolyVector.size()) || (j < second.PolyVector.size()))
    {

        if(first.PolyVector[i].exp == second.PolyVector[j].exp) // first exp == second exp --> add coef
        {
            term s;
            s.coef = first.PolyVector[i].coef + second.PolyVector[j].coef;
            s.exp = first.PolyVector[i].exp; 
            temp.PolyVector.push_back(s);
            i++; j++;
        }

        else if(first.PolyVector[i].exp > second.PolyVector[j].exp) 
        {
            term s;
            s.coef = first.PolyVector[i].coef;
            s.exp = first.PolyVector[i].exp; 
            temp.PolyVector.push_back(s);
            i++;
        }

        else if(first.PolyVector[i].exp < second.PolyVector[j].exp)
        {   term s;
            s.coef = second.PolyVector[j].coef;
            s.exp = second.PolyVector[j].exp; 
            temp.PolyVector.push_back(s);
            j++;
        }    

        else if(first.PolyVector.size() > second.PolyVector.size())
        {   term s;
            s.coef = first.PolyVector[i].coef;
            s.exp = first.PolyVector[i].exp; 
            temp.PolyVector.push_back(s);
            i++;
        }    

        else if(first.PolyVector.size() < second.PolyVector.size())
        {   term s;
            s.coef = second.PolyVector[j].coef;
            s.exp = second.PolyVector[j].exp; 
            temp.PolyVector.push_back(s);
            j++;
        }   

    }//close while
    temp.print();
}






/****************************************************************************
 * This function simply returns the highest degree of "this" polynomial. 
 ****************************************************************************/

int Poly::getDegree() const
{
    return (this->degree);
}







/****************************************************************************
 * (int c == the specified exponent to search for and report the coefficient of)
 * This function reports the accompanying coefficient of a variable of the x to the 
 * c-power term. It searches the structs in the vector of the polynomial object.
 ****************************************************************************/

int Poly::getCoefficient(int c) const
{        
    bool contained = false; // assume that the x-power term doesn't exist
    for(int i=0; i < this->PolyVector.size(); i++)
    {
        if(this->PolyVector[i].exp == c)
        {
            contained = true;   
            c = this->PolyVector[i].coef;
            return c;
        }
    }
    if(contained == false){return (-1);}
}







/****************************************************************************
 * This function merely prints a set of options a user can choose from to 
 * operate on a polynomial object.
 ****************************************************************************/

void Poly::printOptions()
{
    cout << "\nEnter a number from the following options: \n";
    cout << "Add the two polynomials.\t\t\t 1\n";
    cout << "Get the highest degree of the polynomials.\t 2\n";
    cout << "Get the coefficient for the x-power term.\t 3\n";
    cout << "Change the coefficient of a term.\t\t 4\n";
    cout << "Multiply a polynomial by a scalar.\t\t 5\n";
}





/****************************************************************************
 * (f = x-power term to change, t = coef it changes to)
 * This function changes the coefficient of an x-power term, the power is
 * specified by f. It searches the structs in the vector of the polynomial object
 * in order to do say and changes the value in the struct.
 ****************************************************************************/

void Poly::changeCoefficient(int f, int t)
{
    bool exists = false;
    for(int i = 0; i < this->PolyVector.size(); i++)
    {
        if(this->PolyVector[i].exp == f)
        {
            this->PolyVector[i].coef = t;
            exists = true;
        }
    }
    if(exists == false)
    {
        cout << "There isn't a term of that power.\n";
    }
    else
    {
        cout << "The polynomial is now:   "; this->print();
    }
    
}






/****************************************************************************
 * scalar == the user-specified number by which to multiply the polynomial
 * This function multiplies the polynomial by a scalar. It changes the 
 * coefficients stored in the structs of the vector in the object.
 ****************************************************************************/

void Poly::multiply(int scalar)
{
    for(int i = 0; i < this->PolyVector.size(); i++)
    {
        this->PolyVector[i].coef = this->PolyVector[i].coef * scalar;
    }
}


