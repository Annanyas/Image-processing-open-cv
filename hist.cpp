#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
 int count,i,j,p,max=0,k,l;
 Mat img=imread("lena.bmp",0);
 for(p=0;p<=255;p++)
  {
   count=0;
   for(i=0;i<img.rows;i++)
    {
     for(j=0;j<img.cols;j++)
      {
        if(img.at<uchar>(i,j)==p)
         count++;
      }
    }
	
    if(count>max)
     max=count;
  }
   Mat img1(max,256,CV_8UC1,Scalar(255));
  
 for(p=0;p<=255;p++)
  {
   int n=0;
   for(i=0;i<img.rows;i++)
    {
     for(j=0;j<img.cols;j++)
      {
        if(img.at<uchar>(i,j)==p)
         n++;
      }
    }   
//cout<<count<<endl;
  
     for(l=0;l<n;l++)
      {
//cout<<l<<endl;
       img1.at<uchar>(max-l-1,p)=0;
      }
    }
 namedWindow("win",WINDOW_AUTOSIZE);
 imshow("win",img1);
 waitKey(0);
 return 0;
}

