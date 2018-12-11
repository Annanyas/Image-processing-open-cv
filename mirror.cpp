#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
 int i,j;
 Mat img1(1,1,CV_8UC3,Scalar(0,0,0));
 Mat img=imread("lena.bmp",1);
 Mat img2(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
  for(i=0;i<img.cols;i++)
  {
   for(j=0;j<img.rows;j++)
   {
    img1.at<Vec3b>(0,0)=img.at<Vec3b>(j,i);
    
    img2.at<Vec3b>(j,img.cols-i-1)=img1.at<Vec3b>(0,0);
   }
  }
  imshow("win",img2);
  waitKey(0);
  return 0;
}
