#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>

/*int main()
{
int a,x,y,w,h;
 Mat img=imread("image_2.png",1);
int lr=0,lg=0,lb=0;
int hr=255,hg=170,hb=170;

Mat img2;
 Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
 int i,j,r,g,b;
 for(i=0;i<img.rows;i++)
 {
  for(j=0;j<img.cols;j++)
  {
   r=img.at<Vec3b>(i,j)[2];
   g=img.at<Vec3b>(i,j)[1];
   b=img.at<Vec3b>(i,j)[0];
   if((r<=hr&&r>lr)&&(g<=hg&&g>lg)&&(b<=hb&&b>lb))
    img1.at<uchar>(i,j)=255;
   else{}
  }
 }
 imshow("win",img1);

	Mat dst;
	threshold(img1,dst,250,255,THRESH_BINARY);
	Mat contour_img(img1.rows,img1.cols,CV_8UC1,Scalar(0));
	vector<vector<Point> >contours;
	vector<Vec4i>hierarchy;
	findContours(dst,contours,hierarchy,RETR_TREE,CHAIN_APPROX_NONE,Point(0,0));
	for(size_t a=0;a<contours.size();a++)
	{
		drawContours(contour_img,contours,a,255);
	
	}
	imshow("My_Window",contour_img);
return 0;
}*/
int main()
{
Mat src=Mat::zeros(400,400,CV_8UC3);
Rect r(100,100,50,50);

Point point0=Point(r.x,r.y);
Point point1=Point(r.x+r.width,r.y);
Point point2=Point(r.x+r.width,r.y+r.height);
Point point3=Point(r.x,r.y+r.height);
rectangle(src,r,Scalar:all(255));
circle(src,point0,10,Scalar(0,0,255);
circle(src,point1,10,Scalar(0,0,255);
circle(src,point2,10,Scalar(0,0,255);
circle(src,point3,10,Scalar(0,0,255);

imshow("coordinatesvof all the cornerof rectangle);
waitKey(0);
}
