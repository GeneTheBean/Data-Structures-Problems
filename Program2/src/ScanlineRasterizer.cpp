#include "ScanlineRasterizer.h"
#include "Edge.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "Vertex.h"
#include <algorithm> //sort()

//Initialize the frame buffer so that each entry is lled with the background color ('-').
ScanlineRasterizer::ScanlineRasterizer(int nx, int ny) {
    this->nx = nx;
    this->ny = ny;
    frame_buffer = new char*[ny];

    for(int i = 0;i < ny;i++)
        frame_buffer[i] = new char(nx);

    for(int i = 0;i < ny;i++) {
        for(int j = 0;j <nx;j++)
        frame_buffer[i][j] = '-';
    }
}

ScanlineRasterizer::~ScanlineRasterizer() {
    for(int i = 0; i < ny; ++i) {
        delete [] frame_buffer[i];
    }
    delete [] frame_buffer;
}

//given a filename, read in its vertices and rasterize into frame buffer member variable
void ScanlineRasterizer::rasterize(const string& filename) {
    ifstream infile;
    infile.open(filename.c_str());
	vector<Vertex> vertices;
	vector<Edge> edges;

    double x, y;

    //Reads in each coordinate and transforms with the viewport transformation matrix.
	while (!infile.eof()) {
		infile >> x;
		infile >> y;

        if(infile.eof()){
            break;
        }

		x = x*(nx/2)+(( nx - 1 )/2);
		y = y*(ny/2)+(( ny - 1)/2);

		vertices.push_back(Vertex( x, y ));
	}

	infile.close();

    //Assemble vertices into edges.  (First transform the coordinates into screen coordinates using the view-
    //port transformation.)  Remember that the last edge should connect the last vertex with the first.
	for (int i = 0;i < vertices.size() - 1;i++)
        edges.push_back(Edge(vertices.at(i), vertices.at((i+1) % vertices.size())));

    vector< vector<double> > intersections; //vector to store the intersections

    //For each y from 0 to ny-1, calculate and store all intersections with each edge.
    for (int y = 0;y < ny;y++) {
        vector< double > scanline;

        for (int j = 0; j < edges.size();j++){
            //For each edge, plug y into the edge's equation
            double x = edges.at(j).getEquation().findX(y);

            //Check that the resulting x is between the edge's start and end points
            if (x <= edges.at(j).getv2().getX() && x >= edges.at(j).getv1().getX()) {
                scanline.push_back(x);
            }
        }
        //Sort each scanline's x-intersections from left to right.
        sort(scanline.begin(), scanline.end());

        intersections.push_back(scanline);

        //Fill each all pixels between each pair of x-intersections with the foreground color ('*').
        //(This follows the odd-even parity rule.
    }

    //Fill intersections
    for (int y = 0;y < intersections.size();y++) {
        if (intersections.at(y).size()>0) {
            for (int i = 0;i<intersections.at(y).size()-1; i+=2) {
            //Fills the frame_buffer while checking for existing intersections
            if (!(intersections.at(y).at(i) == intersections.at(y).at(i + 1)))
                for (int x= intersections.at(y).at(i);x<intersections.at(y).at(i+1);x++)
                    frame_buffer[y][x] = '*';
            }
        }
    }
}

void ScanlineRasterizer::print() { //print the contents of the frame buffer
    for(int i = 0;i < ny;i++) {
        for(int j = 0;j <nx;j++)
        cout<<frame_buffer[i][j];
        cout<<endl;
    }
}
