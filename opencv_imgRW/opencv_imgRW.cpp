// opencv_imgRW.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    /*if( argc != 2)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }*/

    Mat image;
    image = imread("myImage.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    namedWindow( "First image", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "First image", image );                   // Show our image inside it.

    waitKey(0);                                          // Wait for a keystroke in the window

	Mat greyImage;
	cvtColor(image, greyImage,CV_RGB2GRAY);
	imwrite("mygreyImage.jpg",greyImage);
	namedWindow("Other window",WINDOW_AUTOSIZE);
	imshow("Other window",greyImage);
	waitKey(0);

    return 0;
}
