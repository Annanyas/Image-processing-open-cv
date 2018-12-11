#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<stdio.h>
#include<math.h>
using namespace cv;
using namespace std;
Mat frame;
int b;
VideoCapture vid(0);
void check_callback(int t,void *a)
{
Mat img(480,640,CV_8UC1,Scalar(0));
int i,j,flag ;
//VideoCapture vid(0);
vid>>frame;
imshow("win",frame);
Mat hsv(frame.rows,frame.cols,CV_8UC3);
cvtColor(frame,hsv,CV_BGR2HSV);
imshow("win1",hsv);
while (1)//(b)
 {
 int ci=0,cj=0,x,y,count=0; 
 vid>>frame;
 Mat hsv(frame.rows,frame.cols,CV_8UC3);
 cvtColor(frame,hsv,CV_BGR2HSV);
 imshow("win",frame);
// imshow("win1",hsv);
 for(i=0;i<img.rows;i++)
 {
    //flag=0;
  for(j=0;j<img.cols;j++)
  {
       if(frame.at<Vec3b>(i,j)[2]>150)//&& frame.at<Vec3b>(i,j)[0]<10 && frame.at<Vec3b>(i,j)[2]<10)
    {
     ci=ci+i;
     cj=cj+j;
     count++;
        //img.at<uchar>(i,j)=255 ;
      //flag=1;
    }
  }   
 }
 if (count == 0) continue;
 x=ci/count;
 y=cj/count;
 for(i=-1;i<2;i++)
     {
     for (j=-1;j<2;j++)
         {
         img.at<uchar>(x+i,y+j)=255;
         }
     }   
 //img.at<uchar>(x,y)=255;         
 //if(flag==0) break ;
 imshow("track1",img);
 waitKey(1);
 imwrite("ps3.bmp",img);
 //imshow("win1",img1);
 }
 imshow("track1",img);
 waitKey(1);

 //printf("%d",frame.rows);
 //printf("%d",frame.cols);
}


int main()
{
//VideoCapture vid(0);
int t=100;
b=0;
namedWindow("track",WINDOW_NORMAL);
//while(1)
    //{
    check_callback(t,NULL);
    //createTrackbar("if done set to 1","track",&b,1,check_callback);
    createTrackbar( "change it", "track", &t, 255, check_callback);
    waitKey(0);
    //}
return 0;
}    
