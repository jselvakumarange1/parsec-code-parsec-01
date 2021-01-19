#ifndef MYLIB_H
#define MYLIB_H

//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
#include <math.h>
#include "opencv2/opencv.hpp"
//#include <iostream>
using namespace cv;

Mat contours(Mat frame); 
Mat seuillageRtoV(Mat frame);
Mat seuillageBtoM (Mat frame);
Mat NBfilter(Mat frame);
Mat gausien (Mat frame);
Mat mirroir(Mat frame);

#endif 

