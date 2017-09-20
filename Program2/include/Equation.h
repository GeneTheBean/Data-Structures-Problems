#ifndef EQUATION_H
#define EQUATION_H
#include "Vertex.h"

/****************************************
 *  Class to define Equation of a line. *
 ****************************************/
class Equation
{
    public:
        Equation();
        Equation(Vertex&, Vertex&); //Solves for A B C given two vertices
        double findX(int); //Solves for x given a y in equation

    private:
        double A, B, C; //Coefficients for Ax + By + C = 0(implicit equation);
};

#endif // EQUATION_H
