#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat img=imread("a.png",1);
int lr=0,lg=0,lb=0;
int hr=255,hg=255,hb=255;
void update(int t,void *a)
{
 Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
 int i,j,r,g,b;
 for(i=0;i<img.rows;i++)
 {
  for(j=0;j<img.cols;j++)
  {
   r=img.at<Vec3b>(i,j)[2];
   g=img.at<Vec3b>(i,j)[1];
   b=img.at<Vec3b>(i,j)[0];
   if((r<=hr&&r>lr)&&(g<=hg&&g>lg)&&(b<=hb&&b>lb))
    img1.at<uchar>(i,j)=255;
   else{}
  }
 }
 imshow("win",img1);
}

int main()
{
 
namedWindow("win",WINDOW_NORMAL);
	
 createTrackbar("change_it", "win", &lr, 255, update);
 createTrackbar("change_it1", "win", &hr, 255, update);
 createTrackbar("change_it2", "win", &lg, 255, update);
 createTrackbar("change_it3", "win", &hg, 255, update);
 createTrackbar("change_it4", "win", &lb, 255, update);
 createTrackbar("change_it5", "win", &hb, 255, update);
 waitKey(0);
 return 0;
}
