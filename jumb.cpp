#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include​ ​ "opencv2/opencv.hpp"
using​ ​ namespace​ ​ cv;
Mat​ ​ img​ = imread("a.png",​1);
int​ ​ rand_int(int​ a,​int​ b)
{
if​ ​ (a​>b)
return((rand()​%(a​-b+1))+b);
else​ ​ if​ ​ (b​>a)
return((rand()%(b-a+1))+a);
else
return​ a;
}
int​ ​ main()
{
int​ o=0,h=0;
int​ store[]={10,10,10,10,10,10,10,10,10};
int​ i,​j,​a,​cont​=0;
int​ x[]={0,img.cols​/3,2*img.cols/3,0,img.cols/3,2*img.cols/3,0,img.cols​/3,2*img.cols/3};
int​ y[]={0,0,0,img.rows/3,img.rows/3,img.rows/3,2*img.rows/3,2*img.rows/3,2*img.rows/3};
Mat​ jumble​(img.rows,​img.cols,​CV_8UC3,​Scalar(0,​0,​0));
int n=0;
while(cont==9)
{
int​ f=0;
a​=rand_int(0,8);
for​(i=0;​i<9;i++)
{
if​(a==store[i]){f++;}
}
if​(f​==​0)
{
cont++;
int​ ​ par1​ ​ = ​ ​ 0,​ ​ par2​ ​ = ​ ​ 0;
store[n]​ ​ = ​ ​ a;
n++;Mat​ ​ part(img.rows​/3,​ ​ img.cols​ ​ / ​ ​ 3,​ ​ CV_8UC3,​ ​ Scalar(0,​ ​ 0,​ ​ 0));
for​ ​ (int​ ​ p ​ ​ = ​ ​ x[a];​ ​ p ​ ​ < ​ ​ x[a]​ ​ + ​ ​ img.rows​ ​ / ​ ​ 3;​ ​ p++)
{
for​ ​ (j​ ​ = ​ ​ y[a];​ ​ j ​ ​ < ​ ​ y[a]​ ​ + ​ ​ img.cols​ ​ / ​ ​ 3;​ ​ j++)
{
part.at<Vec3b>(par1,​ ​ par2)[0]​ ​ = ​ ​ img.at<Vec3b>(p,​ ​ j)[0];
part.at<Vec3b>(par1,​ ​ par2)[1]​ ​ = ​ ​ img.at<Vec3b>(p,​ ​ j)[1];
part.at<Vec3b>(par1,​ ​ par2)[2]​ ​ = ​ ​ img.at<Vec3b>(p,​ ​ j)[2];
if​ ​ (par2​ ​ ==​ ​ img.cols​ ​ / ​ ​ 3)
{
par2​ ​ = ​ ​ 0;
par1​ ​ = ​ ​ par1​ ​ + ​ ​ img.rows;
}
else
{
par2++;
}
}
}
part.copyTo(jumble(cv::Rect(h,​ ​ o,​ ​ h ​ ​ + ​ ​ img.rows​ ​ / ​ ​ 3,​ ​ o ​ ​ + ​ ​ img.cols​ ​ / ​ ​ 3)));
if​ ​ (o​ ​ ==​ ​ img.cols)
{
o​ ​ = ​ ​ 0;
h​ ​ = ​ ​ h ​ ​ + ​ ​ img.rows​ ​ / ​ ​ 3;
}
else
{
o​ ​ = ​ ​ o ​ ​ + ​ ​ img.cols​ ​ / ​ ​ 3;
}
}
}
}
