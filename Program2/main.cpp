//Eugene Chen
#include <iostream>
#include <stdlib.h>     /* atoi */

#include "ScanlineRasterizer.h"

int main(int argc, char* argv[]) {

	ScanlineRasterizer r(atoi(argv[1]), atoi(argv[2]));
	r.rasterize(argv[3]);
	r.print();

}
