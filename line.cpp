#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <math.h>
using namespace cv;
using namespace std;

int main()
{
 Mat img=imread("pentagon.png",0);
 float i,j,r,t;
 int a=img.rows;
 int b=img.cols;
 int x=2*((a^2+b^2)^1/2);
 Mat img1(x,180,CV_8UC1,Scalar(0));
 for(i=0;i<img.rows;i++)
 {
  for(j=0;j<img.cols;j++)
  {
   if(img.at<uchar>(i,j)>175)
   {
    for(t=0;t<181;t++)
    {
     r=j*cos(t*3.14/180)+i*sin(t*3.14/180);
     img1.at<uchar>(x/2-r,t)=img1.at<uchar>(x/2-r,t)+25;
    }
   }
  }
 }
namedWindow("win",WINDOW_NORMAL);
 imshow("win",img1);
 waitKey(0);
 return 0;
}
