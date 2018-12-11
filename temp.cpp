#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
using namespace cv;
Mat img,temp1,result;
char* image_window="Source Image";
char* result_window="Result window";

int match_method;
int max_Trackbar=5;

//function headers
void MtchingMethod(int,void*)

int main(int argc,char** argv)
{
	img=imread("coins.jpg",1);
	temp1=("coin.jpg",1);

	namedWindow("img_win",WINDOW_AUTOSIZE);
	namedWindow("res_win",WINDOW_AUTOSIZE);
	
	void match(int b,void *a)
	{
		Mat img=imread("coins.jpg"
	}
}
