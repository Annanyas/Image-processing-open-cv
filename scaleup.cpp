#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
 int i,j,k,l,m=2,n=2,p=0,q=0,r=0,g=0,b=0;
 Mat img=imread("lena.bmp",1);
 Mat img1((img.rows*2),(img.cols*2),CV_8UC3,Scalar(0,0,0));
 for(i=0;i<img.rows;i++)
  {
  for(j=0;j<img.cols;j++)
   {
   r=img.at<Vec3b>(i,j)[2];
   g=img.at<Vec3b>(i,j)[1];
   b=img.at<Vec3b>(i,j)[0];
    for(k=p;k<m;k++)
    {
    for(l=q;l<n;l++)
     {
      img1.at<Vec3b>(k,l)={r,g,b};
     }
    }
    q+=2;
    n+=2;
   }
   p+=2;
   m+=2;
  }
 namedWindow("win",WINDOW_NORMAL);
 imshow("win",img1);
 waitKey(0);
 return 0;
}
