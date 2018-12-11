#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv/opencv.hpp>
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

void callback(int k, void*c)
{
  Mat img = imread("./rubik.jpg", 1);
  Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));


  for(int i1=1;i1<img1.rows-1;i1++)
  {
    for(int j1=1;j1<img1.cols-1;j1++)
    {    
      img1.at<uchar>(i1,j1)=0.07*img.at<Vec3b>(i1,j1)[0]+0.72*img.at<Vec3b>(i1,j1)[1]+0.21*img.at<Vec3b>(i1,j1)[2];
    }             

  }


  Mat img2(img1.rows,img1.cols,CV_8UC1,Scalar(0));
  int a[9],n=9,x,y,t;
  /*for(int i=1;i<img1.rows-1;i++)
  {
  	for(int j=1;j<img1.cols-1;j++)
  	{
  		a[0]=img1.at<uchar>(i-1,j);
  		a[1]=img1.at<uchar>(i-1,j-1);
  		a[2]=img1.at<uchar>(i-1,j+1);
  		a[3]=img1.at<uchar>(i,j);
  		a[4]=img1.at<uchar>(i,j-1);
  		a[5]=img1.at<uchar>(i,j+1);
  		a[6]=img1.at<uchar>(i+1,j);
  		a[7]=img1.at<uchar>(i+1,j-1);
  		a[8]=img1.at<uchar>(i+1,j+1);

  		
  		x=(a[0]*0+a[1]*(-1)+a[2]*1+a[3]*0+a[4]*(-2)+a[5]*2+a[6]*0+a[7]*(-1)+a[8]*1)/8;
      y=(a[0]*(-2)+a[1]*(-1)+a[2]*(-1)+a[3]*0+a[4]*0+a[5]*0+a[6]*2+a[7]*1+a[8]*1)/8;
      t=sqrt(x*x+y*y);
           

      if(t<k)
        img2.at<uchar>(i,j)=0;
      else
        img2.at<uchar>(i,j)=255; */
     

  	
  
  Canny(img,img2,k,3*k,3);
  imshow("edge",img2);
}

  int main()
  {
  	int var=0;
  	namedWindow("edge",WINDOW_NORMAL);
  createTrackbar("a","edge",&var,255,callback,0);
  
  
  waitKey(0);
  return(0);
}
