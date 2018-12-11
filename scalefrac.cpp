#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat img1=imread("lena.jpg",1);
int i,j,r=0,g=0,b=0,k,l,p=0,q=0,t=0;
int s=t*t;
int m=t;
int n=t;

Mat scaled(Mat img, int t)
{
 Mat img2(img.rows/t,img.cols/t,CV_8UC3,Scalar(0,0,0));
 for(i=0;i<img1.rows/t;i++)
  {
  for(j=0;j<img1.cols/t;j++)
   {
    for(k=p;k<m;k++)
     {
      for(l=q;l<n;l++)
       {
        r=r+img1.at<Vec3b>(k,l)[2];
        g=g+img1.at<Vec3b>(k,l)[1];
        b=b+img1.at<Vec3b>(k,l)[0];
       }
      }
     img2.at<Vec3b>(i,j)={r/s,g/s,b/s};
     q+=2;
     n+=2;
     r=0;
    g=0;
    b=0;
     }
    p+=2;
    m+=2;
    q=0;
    n=2;
   }
 return img2;
}

Mat scaled(Mat img,t)
{
 Mat img2((img.rows*t),(img.cols*t),CV_8UC3,Scalar(0,0,0));
 for(i=0;i<img1.rows;i++)
  {
  for(j=0;j<img1.cols;j++)
   {
   r=img1.at<Vec3b>(i,j)[2];
   g=img1.at<Vec3b>(i,j)[1];
   b=img1.at<Vec3b>(i,j)[0];
    for(k=p;k<m;k++)
    {
    for(l=q;l<n;l++)
     {
      img2.at<Vec3b>(k,l)={r,g,b};
     }
    }
    q+=t;
    n+=t;
   }
   p+=t;
   m+=t;
  }
 return img2;
}

int main()
{
 Mat img3=scaled(img1,5);
 Mat img4=scaleup(img2,3);
 namedWindow("win",WINDOW_NORMAL);
 imshow("win",img4);
 waitKey(0);
 return 0;
}
