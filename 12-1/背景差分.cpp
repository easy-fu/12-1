#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap(0);

	if (!cap.isOpened())
	{
		printf("\nCan not open camera \n");
		return -1;
	}
	Mat bgMat;
	Mat subMat;
	Mat frame;
	Mat bny_subMat;
	int cnt = 0;
	while (1)
	{
		cap >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);
		if ( cnt == 0)
		{
			frame.copyTo(bgMat);
			cnt = 1;
		}
		
		else
		{
			absdiff(frame, bgMat, subMat);
			threshold(subMat, bny_subMat, 50, 255, CV_THRESH_BINARY);
			imshow("b-subMat", bny_subMat);
			imshow("subMat", subMat);
			waitKey(30);
		}
		
	}

	
	return 0;
}