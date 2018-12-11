#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
 int i,j,r=0,g=0,b=0,k,l,m=2,n=2,p=0,q=0;
 Mat img=imread("lena.jpg",1);
 Mat img1(img.rows/2,img.cols/2,CV_8UC3,Scalar(0,0,0));
 for(i=0;i<img.rows/2;i++)
  {
  for(j=0;j<img.cols/2;j++)
   {
    for(k=p;k<m;k++)
     {
      for(l=q;l<n;l++)
       {
        r=r+img.at<Vec3b>(k,l)[2];
        g=g+img.at<Vec3b>(k,l)[1];
        b=b+img.at<Vec3b>(k,l)[0];
       }
      }
     img1.at<Vec3b>(i,j)={r/4,g/4,b/4};
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
 namedWindow("win",WINDOW_NORMAL);
 imshow("win",img1);
 waitKey(0);
 return 0;
}
