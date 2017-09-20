#ifndef EDGE_H
#define EDGE_H
#include "Vertex.h";
#include "Equation.h";
#include <iostream>

/************************************************************
 *  Class to define edges from two vertices. It is composed *
 *   with an Equation object for the scanline algorithm.    *
 ************************************************************/
class Edge
{
    public:
        Edge(Vertex&, Vertex&); //Defines an edge with two vertices
        Vertex& getv1();
        Vertex& getv2();
        void print(); //For debugging purposes
        Equation& getEquation();
    protected:
    private:
        Vertex v1;
        Vertex v2;
        Equation equation;
};

#endif // EDGE_H
