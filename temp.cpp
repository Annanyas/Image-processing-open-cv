#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

Mat img1=imread("./coins.jpeg",1);
Mat img2=imread("./temp.jpeg",1);
Mat img3(img1.rows,img1.cols,CV_8UC1,Scalar(0));
Mat img4(img1.rows,img1.cols,CV_8UC1,Scalar(0));


int main()
{

int m;
	cout<<"Enter the method number: ";
	cin>>m;
	if(m>=6 || m<0)
	{
		cout<<"Invalid Input"<<endl;
		exit(0);
	}
   namedWindow("temp",WINDOW_NORMAL);
   matchTemplate(img1,img2,img3,m);
   normalize(img3,img3,0,1,NORM_MINMAX,-1,Mat());

   double minVal,maxVal;
   Point minLoc,maxLoc,matchLoc;

   minMaxLoc(img3,&minVal,&maxVal,&minLoc,&maxLoc,Mat());
   if(m==0 || m==1)
   matchLoc=minLoc;
else 
	matchLoc=maxLoc;
   rectangle(img3,Point(matchLoc.x-img2.cols/4,matchLoc.y+img2.rows/4),Point(matchLoc.x+img2.cols/4,matchLoc.y-img2.rows/4),Scalar::all(0),2,8,0);

   /*for(int i=(-1)*matchLoc.y+img2.rows/4;i<=(-1)*matchLoc.y-img2.rows/4;i++)
   {
   	for(int j=(-1)*matchLoc.x-img2.cols/4;j<=(-1)*matchLoc.x+img2.cols/4;j++)
   	{
         img4.at<uchar>(i,j)=255;
   	}

   }*/
   
   imshow("temp",img3);
   
   waitKey(0);
   return(0);

}


