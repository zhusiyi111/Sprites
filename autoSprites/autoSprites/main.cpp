// HelloWorld.cpp  
#include <iostream>  
#include <string>  
#include <opencv2\opencv.hpp>  
#include <processFiles.h>
using namespace std;
using namespace cv;

int main()
{

	vector<string> aa = getFilesName("./image");
	vector<Mat> imgs;
	int row = 0, maxCol = 0;

	for (int i = 0; i < aa.size(); i++){
		imgs.push_back(imread(aa[i],1));
		row += imgs[i].rows;
		maxCol > imgs[i].cols ? maxCol : maxCol = imgs[i].cols;
		cout << "cols:"<<imgs[i].cols <<"rows:"<< imgs[i].rows <<endl;
		cout << row << "," << maxCol << endl;
	}

	Mat result;
	result.create(row, maxCol, CV_8UC3);
	
	int nowCol = 0;
	for (int i = 0; i < imgs.size(); i++){

		imgs[i].copyTo(result(Rect(0, nowCol, imgs[i].cols, imgs[i].rows)));

		nowCol += imgs[i].rows;
	
	}
	
	imshow("dassasa", result);
	waitKey(0); 

}