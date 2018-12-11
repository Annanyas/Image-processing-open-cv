#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>


using namespace std;
using namespace cv;

  Mat img = imread("./lenna.jpg", 1);



void callback(int t,void *)
{

    Mat img1(4*img.rows,4*img.cols,CV_8UC3,Scalar(0,0,0));
  		
 for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		    {    

                          	
			
						int a=i*cos(t*M_PI/180.0)*1.0-j*sin(t*M_PI/180.0)*1.0;
						int b=i*sin(t*M_PI/180.0)*1.0+j*cos(t*M_PI/180.0)*1.0;
						img1.at<Vec3b>(2*img.rows+a,2*img.cols+b)=img.at<Vec3b>(i,j);
				
		    }
	}

  imshow("lenna", img1);
}


int main() {

    namedWindow("lenna", WINDOW_NORMAL);

  
    int b;
    
        


   

    

    createTrackbar("rotate","lenna",&b,360,callback);	

    waitKey(0);
    return 0;
}

