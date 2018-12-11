#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;


int c=0;
Mat img;

int isValid(int a,int b)
{
	if(a>=0&&a<img.rows&&b>=0&&b<img.cols)
  	 return 1;
 	else
  	 return 0;
}

void dfs(int i,int j,int t)
{
 	int k,l;
        img.at<uchar>(i,j)=t;
 	for(k=i-1;k<=i+1;k++)
 	{
 	 	for(l=j-1;l<=j+1;l++)
 	 	{
 	  		if(isValid(k,l)==1)
 	  		{
 	   			if(img.at<uchar>(k,l)>200)
 	    			{
 	    				dfs(k,l,t); 

 	    			}  
 	  		}
 	 	}
 	}    
}

void onMouse(int event,int y,int x,int flag,void *a)
{
	if(event==1)
		dfs(x,y,0);
	if(event==2)
		dfs(x,y,150);
}	

int main()
{
	img=imread("shapes.jpg",0);
	namedWindow("win",WINDOW_NORMAL);
 	setMouseCallback("win",onMouse,0);
        imshow("win",img);
	waitKey(0);
 	return 0;
}
