#ifndef VERTEX_H
#define VERTEX_H

/********************************************************
 *  Class to define a vertex from x and y coordinates.  *
 ********************************************************/
class Vertex
{
    public:
        Vertex();
        Vertex(double x, double y){ //Sets the coordinates for the vertex
            this->x = x;
            this->y = y;
        }

        double getX();
        double getY();
        void print(); //For debugging purposes

    private:
        double x;
        double y;
};

#endif // VERTEX_H
