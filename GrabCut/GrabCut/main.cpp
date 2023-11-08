#include "time.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include "D:\Users\dell\Desktop\南开考核\UI.h"

static void help()
{
	std::cout << "\nThis program demonstrates GrabCut segmentation -- select an object in a region\n"
		"and then grabcut will attempt to segment it out.\n"
		"Call:\n"
		"./grabcut <image_name>\n"
		"\nSelect a rectangular area around the object you want to segment\n" <<
		"\nHot keys: \n"
		"\tESC - quit the program\n"
		"\tr - restore the original image\n"
		"\tn - next iteration\n"
		"\n"
		"\tleft mouse button - set rectangle\n"
		"\n"
		"\tCTRL+left mouse button - set GC_BGD pixels\n"
		"\tSHIFT+left mouse button - set CG_FGD pixels\n"
		"\n"
		"\tCTRL+right mouse button - set GC_PR_BGD pixels\n"
		"\tSHIFT+right mouse button - set CG_PR_FGD pixels\n" << endl;
}


UI gcapp;

static void on_mouse(int event, int x, int y, int flags, void* param)
{
	gcapp.mouseClick(event, x, y, flags, param);
}


int main()
{
	
	
	string filename = "D:\\Users\\dell\\Desktop\\23.jpg";
	Mat image = imread(filename, 1);
	
	
	//resize(image, image, s);
	if (image.empty())
	{
		cout << "\n , couldn't read image filename " << filename << endl;
		return 1;
	}

	help();

	const string winName = "image";
	cv::namedWindow(winName.c_str(), cv::WINDOW_AUTOSIZE);
	cv::setMouseCallback(winName.c_str(), on_mouse, 0);

	gcapp.setImageAndWinName(image, winName);
	//int xPos = (cv::getWindowImageRect(winName.c_str()).width - image.cols) / 2;
	//int yPos = (cv::getWindowImageRect(winName.c_str()).height - image.rows) / 2;
	//cv::moveWindow(winName.c_str(), xPos, yPos);
	gcapp.showImage();

	
	for (;;)
	{
		int c = cv::waitKey(0);
		switch ((char)c)
		{
		case '\x1b':
			cout << "Exiting ..." << endl;
			goto exit_main;
		case 'r':
			cout << endl;
			gcapp.reset();
			gcapp.showImage();
			break;
		case 'n':
			int iterCount = gcapp.getIterCount();
			cout << "<" << iterCount << "... ";
			int newIterCount = gcapp.nextIter();
			if (newIterCount > iterCount)
			{
				gcapp.showImage();
				cout << iterCount << ">" << endl;
			}
			else
				cout << "rect must be determined>" << endl;
			break;
		}
	}

exit_main:
	cv::destroyWindow(winName.c_str());
	return 0;

	return 0;
}