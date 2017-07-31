#include "acv.hpp"

#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>

using namespace std;
using namespace cv;


int main(){
	Mat image;
	double i = 0;

	VideoCapture cap(0);
	
	if (!cap.isOpened()){
		cout << "failur open the camera." << endl;
		return -1;
	}
	
	while (1){
		cap >> image;
		ACV(image, Point(255, 255), 150, 42589,
			sin(i) + 0.1 * rand() / double(RAND_MAX),
			cos(i) + 0.1 * rand() / double(RAND_MAX),
			tan(i) + 0.1 * rand() / double(RAND_MAX),
			-cos(i) + 0.1 * rand() / double(RAND_MAX),
			-sin(i) + 0.1 * rand() / double(RAND_MAX));

		imshow("HUD", image);
		waitKey(10);
		
		i += 0.01;
		cout << i << endl;
	}
}
