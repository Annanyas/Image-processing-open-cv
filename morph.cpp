#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat img=imread("lena.bmp",1);
Mat img1=imread("coins.jpg",1);
Mat img2(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));

void update(int t,void *a)
{
	int i,j;
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			img2.at<Vec3b>(i,j)[2]=(t*img1.at<Vec3b>(i,j)[2]+(100-t)*img.at<Vec3b>(i,j)[2])/100;
			img2.at<Vec3b>(i,j)[1]=(t*img1.at<Vec3b>(i,j)[1]+(100-t)*img.at<Vec3b>(i,j)[1])/100;
			img2.at<Vec3b>(i,j)[0]=(t*img1.at<Vec3b>(i,j)[0]+(100-t)*img.at<Vec3b>(i,j)[0])/100;
		}
	}
	imshow("win",img2);
	waitKey(5000);
}

int main()
{
	int th=0;
	namedWindow("win",WINDOW_NORMAL);
	createTrackbar("changeit","win",&th,100,update);
	
	waitKey(0);
	return 0; 
}

