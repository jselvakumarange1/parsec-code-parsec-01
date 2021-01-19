#ifndef MYLIB_H
#define MYLIB_H


#include <math.h>
#include "opencv2/opencv.hpp"

using namespace cv;
////declaration de fonctions
Mat contours(Mat frame); 
Mat seuillageRtoV(Mat frame);
Mat seuillageBtoM (Mat frame);
Mat NBfilter(Mat frame);
Mat gausien (Mat frame);
Mat mirroir(Mat frame);


#endif 


