#include "opencv2/opencv.hpp"

using namespace cv;

int main()
{
	Mat img(8,8,CV_8UC1,Scalar(0));
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			if((i+j)%2==0)
			img.at<uchar>(i,j)=0;
			else
			img.at<uchar>(i,j)=255;
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img);
	waitKey(0);
}
