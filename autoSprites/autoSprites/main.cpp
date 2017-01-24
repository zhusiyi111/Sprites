// HelloWorld.cpp  
#include <iostream>  
#include <string>  
#include <opencv2\opencv.hpp>  
using namespace std;
using namespace cv;

int main()
{

	Mat a = imread("hehe.jpg", 1);
	imshow("dasd", a);

	waitKey(0);


}