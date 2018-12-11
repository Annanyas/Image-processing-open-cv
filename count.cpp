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

void dfs(int i,int j)
{
 	int k,l;
        img.at<uchar>(i,j)=100;
 	for(k=i-1;k<=i+1;k++)
 	{
 	 	for(l=j-1;l<=j+1;l++)
 	 	{
 	  		if(isValid(k,l)==1)
 	  		{
 	   			if(img.at<uchar>(k,l)<20)
 	    			{
 	    				dfs(k,l); 

 	    			}  
 	  		}
 	 	}
 	}    
}	

int main()
{
	img=imread("dfs_path.jpg",0);
 	int p,q;
 	for(p=0;p<img.rows;p++)
 	{
  		for(q=0;q<img.cols;q++)
  		{
   			if(img.at<uchar>(p,q)<20){
    				dfs(p,q);
                                c++;}
 	 	}
 	}
 	cout<<c<<endl;
        imshow("win",img);
 	return 0;
}
