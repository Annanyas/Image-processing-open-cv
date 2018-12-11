#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat img=imread("index.jpg",1);
Mat img1(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
int isValid(int a,int b)
{
 if(a>=0&&a<img.rows&&b>=0&&b<img.cols)
  return 1;
 else
  return 0;
}

int main()
{
 int n=0,i,j,k,l,r=0,g=0,b=0;
 for(i=0;i<img.rows;i++)
 {
  for(j=0;j<img.cols;j++)
  {
   for(k=i-1;k<=i+1;k++)
   {
    for(l=j-1;l<=j+1;l++)
     {
      if(isValid(k,l)==1)
       {
        n++;
        r=r+img.at<Vec3b>(k,l)[2];
        g=g+img.at<Vec3b>(k,l)[1];
        b=b+img.at<Vec3b>(k,l)[0];
       }
     }
   }
   img1.at<Vec3b>(i,j)={r/n,g/n,b/n};
   r=0;
   g=0;
   b=0;
   n=0;
  }
 }
 namedWindow("win",WINDOW_NORMAL);
 imshow("win",img1);
 waitKey(0);
 return 0;
}
