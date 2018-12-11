#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat img=imread("rubik.jpg",0);
Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
int isValid(int a,int b)
{
 if(a>=0&&a<img.rows&&b>=0&&b<img.cols)
  return 1;
 else
  return 0;
}

int diff(int a[],int p)
{
 int temp=0;
 for(int j=0;j<p;j++)
  {
for(int i=0;i<p;i++)

   if(a[i]>a[i+1])
    {
     temp=a[i];
     a[i]=a[i+1];
     a[i+1]=temp;
    }
  }
 int x=a[p-1]-a[0];
 return x;
}

int main()
{
 
 int n=0,i,j,k,l,u[9],m,t,o,p,q;
 for(i=0;i<img.rows;i++)
 {
  for(j=0;j<img.cols;j++)
  {
   n=0;
   for(k=i-1;k<=i+1;k++)
   {
    for(l=j-1;l<=j+1;l++)
     {
      if(isValid(k,l)==1)
       {
        u[n]=img.at<uchar>(k,l);
        n++;
       }
     }
     if(diff(u,n)>2)
       img1.at<uchar>(i,j)=255;
     else{img1.at<uchar>(i,j)=0;
         }
     }
   }
  }
 namedWindow("win",WINDOW_NORMAL);
 imshow("win",img1);
 waitKey(0);
 return 0;
}
 
