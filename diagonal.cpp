#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;

int main()
{
 int i,j;
 Mat img(50,50,CV_8UC3,Scalar(255,0,0));
 for(i=0;i<50;i++)
  {
   for(j=0;j<=i;j++)
    {
     img.at<Vec3b>(i,j)={0,0,255};
    }
  }
 namedWindow("win",WINDOW_NORMAL);
 imshow("win",img);
 waitKey(0);
 return 0;
}
