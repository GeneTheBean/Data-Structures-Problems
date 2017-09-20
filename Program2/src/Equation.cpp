#include "Equation.h"

Equation::Equation() {}

Equation::Equation(Vertex &v1, Vertex &v2) {
	A = v1.getY()-v2.getY();
	B = v2.getX()-v1.getX();
	C = v1.getX()*v2.getY()-v2.getX()*v1.getY();
}

double Equation::findX(int y) {
    if (A == 0) A++; //Kept throwing 0 so in order to get around it, just increment A

	else if (B == 0 ) B++; //Kept throwing 0 so in order to get around it, just increment B

	return (-1*(B*y+C)) / A;
}
