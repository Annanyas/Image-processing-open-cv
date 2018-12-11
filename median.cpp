#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat img=imread("veg.jpg",1);
Mat img1(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
int isValid(int a,int b)
{
 if(a>=0&&a<img.rows&&b>=0&&b<img.cols)
  return 1;
 else
  return 0;
}

int sort(int a[], int p)
{
 int temp=0;
 for(int i=0;i<p;i++)
  {
   if(a[i]>a[i+1])
    {
     temp=a[i];
     a[i]=a[i+1];
     a[i+1]=temp;
    }
  }
 return a[(p+1)/2];
}

Mat blur(Mat x)
{
 int n=0,i,j,k,l,e,c,d;
 int r[9],g[9],b[9];
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
        r[n]=img.at<Vec3b>(k,l)[2];
        g[n]=img.at<Vec3b>(k,l)[1];
        b[n]=img.at<Vec3b>(k,l)[0];
        n++;
       }
     }
    e=sort(r,n);
    c=sort(g,n);
    d=sort(b,n);
   }
   img1.at<Vec3b>(i,j)={e,c,d};
   n=0;
  }
 }
 return img1;
}

int main()
{
 Mat img2=blur(img);
 Mat img3=blur(img2);
 Mat img4=blur(img3);
 namedWindow("win",WINDOW_NORMAL);
 imshow("win",img4);
 waitKey(0);
 return 0;
}
