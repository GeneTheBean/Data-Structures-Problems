#ifndef SCANLINERASTERIZER_H
#define SCANLINERASTERIZER_H
#include <string>
#include <vector>

using namespace std;

/************************************************************
 *  Class to define frame buffer and fill it by using the   *
 *  scanline algorithm                                      *
 ************************************************************/
class ScanlineRasterizer {
    public:
        ScanlineRasterizer(int, int); //Initializes the frame buffer
        virtual ~ScanlineRasterizer(); //Deconstructor
        void rasterize(const string&); //Rasterizes vertices defined by file into the frame buffer
        void print(); //print the contents of the frame buffer
   
    private:
        char** frame_buffer;
        int nx, ny;
};

#endif // SCANLINERASTERIZER_H
