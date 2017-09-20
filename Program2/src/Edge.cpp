#include "Edge.h"

Edge::Edge(Vertex &v1, Vertex &v2) {
    this->v1 = v1;
    this->v2 = v2;

    equation = Equation(this->v1, this->v2);
}

Vertex& Edge::getv1(){
    return v1;
}

Vertex& Edge::getv2(){
    return v2;
}

Equation& Edge::getEquation() {
	return equation;
}

void Edge::print() {
	std::cout<<"v1: ";
	v1.print();
	std::cout<<"v2: ";
	v2.print();
	std::cout<<"\n";
}

