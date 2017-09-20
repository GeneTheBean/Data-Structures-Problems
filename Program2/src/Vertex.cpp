#include "Vertex.h"
#include <iostream>

Vertex::Vertex() { //default constructor
	x = y = 0;
}

double Vertex::getX() {
	return x;
}

double Vertex::getY() {
	return y;
}

void Vertex::print() {
	std::cout<<x<<" "<<y<<"\n";
}

