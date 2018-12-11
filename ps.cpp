#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "noise.cpp"
#include "bfs.cpp"

using namespace cv;
using namespace std;

Mat src; 
Mat src_gray;
Mat src_HSV;
int thresh = 140;
int max_thresh = 255;
RNG rng(12345);
int score=0;

void thresh_callback(int, void* );

int main( int argc, char** argv )
{
  int i,j;
  VideoCapture vid("PS 2.mp4");

  int k=180;

  while(1)
  {

  vid.read(src);
  //Mat canny_output(src.rows,src.cols,src.type());
  Mat car(src.rows,src.cols,CV_8UC1,Scalar(0));


  //cvtColor( src, src_gray, CV_BGR2GRAY );
  cvtColor( src, src_HSV, CV_BGR2HSV );
  int sumx, sumy, count;
  sumx=sumy=count=0;
  //Mat light(src.rows,src.cols,CV_8UC1,Scalar(255));
  //Mat light2;

  //namedWindow( "light", WINDOW_NORMAL );
  namedWindow( "car", WINDOW_NORMAL );
  namedWindow( "car_centroid", WINDOW_NORMAL );
  namedWindow( "source", WINDOW_NORMAL );
  //namedWindow( "light2", WINDOW_NORMAL );
  
  //createTrackbar("Brightness","car", &k, 255);

  //blur( src_gray, src_gray, Size(3,3) );

  for(i=0;i<src_HSV.rows;i++)
  {
    for(j=0;j<src_HSV.cols;j++)
    {
     /*if(src_HSV.at<Vec3b>(i,j)[2]>=100)
        light.at<uchar>(i,j)=0;*/
      if((src.at<Vec3b>(i,j)[2]>=180 && src.at<Vec3b>(i,j)[2]<=210 && src.at<Vec3b>(i,j)[0]>=140 && src.at<Vec3b>(i,j)[0]<=180) || (src.at<Vec3b>(i,j)[2]>=150 && src.at<Vec3b>(i,j)[2]<=180 && src.at<Vec3b>(i,j)[0]>=110 && src.at<Vec3b>(i,j)[0]<=150))
        {
          car.at<uchar>(i,j)=255;
          sumx+=sumx;
          sumy+=sumy;
          count++;
        }
    }
  }
  Mat car_centroid(src.rows,src.cols,CV_8UC1,Scalar(0));
  int x,y;

  x=(int)(sumx/count);
  y=(int)(sumy/count);

  car_centroid.at<uchar>(x,y)=255;



  for(i=0;i<src_HSV.rows;i++)
  {
    for(j=0;j<src_HSV.cols;j++)
    {
     /*if(src_HSV.at<Vec3b>(i,j)[2]>=100)
        light.at<uchar>(i,j)=0;*/
      if(car_centroid.at<uchar>(i,j)==255)
        {
          if((i<=850 && i>=800 && j<=550 && j>=500) || (i<=800 && i>=750 && j<=70 && j>=15))
            score+=10;

          if((i<=770 && i>=700 && j<=200 && j>=150) || (i<=470 && i>=400 && j<=240 && j>=180) || (i<=620 && i>=560 && j<=480 && j>=410))
            score+=20;
        }
    }
  }

  //blur( car, car, Size(3,3) );
  //noise(car);

  //light2=bfs(light);
  

  //imshow("light2", light2 );
  imshow("car", car );
  imshow("car_centroid", car_centroid );
  imshow("source", src );
  //imshow("light", light );

  //noise(src); 

  //namedWindow( "Canny", WINDOW_NORMAL );
 
  //Canny( src_gray, canny_output, thresh, thresh*2, 3 );
  //blur( canny_output, canny_output, Size(3,3) );
  //imshow("Canny", canny_output );

  waitKey(10);
  } 

  printf("\nSquare-->+20 and Triangle-->+10 ==> Score-->%d\n",score);
  return(0);
}

