#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

Mat img1=imread("./obstacle.jpg",0);
Mat img2(img1.rows,img1.cols,CV_8UC1,Scalar(0));

int isvalid(int f,int g)
{
	int m=img1.rows;
	int n=img1.cols;
	if(f>=0 && f<m && g>=0 && g<n)
		return 1;
	else return 0;
}

void dfs(int p,int q)
 {
 	int t=1;
 	

 	if(p==img1.rows-1 && q==img1.cols-1)
 	{

 		cout<<"Destination was reached";
 		t=0;
 	    return;
 	}
 	

 	img1.at<uchar>(p,q)=0;
 	namedWindow("path",WINDOW_NORMAL);
 	imshow("path",img1);
 	waitKey(1);


     if(isvalid(p,q+1) && t==1 && img1.at<uchar>(p,q+1)>=127 )
    {
      
      dfs(p,q+1);
      
    }
     if(isvalid(p+1,q) && t==1 && img1.at<uchar>(p+1,q)>=127 )
    {
      
      dfs(p+1,q);
      
    }
  	 if(isvalid(p-1,q) && t==1 && img1.at<uchar>(p-1,q)>=127 )
  	{
  		 
  	        dfs(p-1,q);
  	       
  	}
  	 if(isvalid(p,q-1) && t==1 && img1.at<uchar>(p,q-1)>=127 )
  	{
  		
  		dfs(p,q-1);
  		
  	}

  	 

  	
return;


  	



 }
int main()
{

  for(int p=0;p<img1.rows;p++)
  {
    for(int q=0;q<img1.cols;q++)
    {

    	if(img1.at<uchar>(p,q)>=127)
       {
         dfs(p,q);
       }

    }

  }	
  	   

  namedWindow("path",WINDOW_NORMAL);
  
  waitKey(0);
  return(0);  
       
}

