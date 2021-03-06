

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"
using namespace cv;
using namespace std;
int main( )
{
    Mat image;
    image = imread("pentagon.png", 1);  
    namedWindow( "Display window", WINDOW_NORMAL );  
    imshow( "Display window", image );
    Mat gray;
    cvtColor(image, gray, CV_BGR2GRAY);
    Canny(gray, gray, 100, 200, 3);
    /// Find contours   
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    RNG rng(12345);
    findContours( gray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
    /// Draw contours
    Mat drawing = Mat::zeros( gray.size(), CV_8UC3 );
    for( int i = 0; i< contours.size(); i++ )
    {
        Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
        drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
    }   
    Mat result;
    Mat result1(result.rows,result.cols,CV_8UC1,Scalar(0));
      cvtColor(drawing,result, CV_BGR2GRAY);
      for(int i=0;i<=result.rows;i++)
      {
        for(int j=0;j<=result.cols;j++)
        {
            if(result.at<uchar>(i,j)>100)
                {result1.at<uchar>(i,j)=255;}
        }
    }

    namedWindow("con",WINDOW_NORMAL);
    imshow( "con", result1 );
    waitKey(0);        

    return 0;
}


