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
	for (int i = 0; i < aa.size(); i++){
		imgs.push_back(imread(aa[i],1));
	}

	Mat result;
	int col = 0, row = 0;

	for (int i = 0; i < imgs.size(); i++){

		if (result.empty()){
			result = imgs[i];
			col = result.cols;
			row = result.rows;
		}
		else{
			Mat temp, now = imgs[i];
			int nowRow = now.rows,
				nowCol = now.cols;
			temp.create(row + nowRow, nowCol > col ? nowCol : col, CV_8UC3);
			result.copyTo(temp(Rect(0, 0, row, col)));
			
			now.copyTo(temp(Rect(0, col, nowRow, nowCol)));
			result = temp;
			col = result.cols;
			row = result.rows;
			imshow(to_string(i + 666), result);
			waitKey(0);
		}

	
	}
	
	
	waitKey(0); 

}