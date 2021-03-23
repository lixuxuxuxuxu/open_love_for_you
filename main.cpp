#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <iostream>
#include<math.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv) {

	Mat src = imread("D:/Users/Xuxuxuxuxu/Desktop/my/love.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
	    return -1;
	}
	double t = getTickCount();
	Mat gray_src;
	imshow("test opencv", src);
	cvtColor(src, gray_src, CV_BGR2GRAY);
	imshow("gray1", gray_src);
	//namedWindow("output", CV_WINDOW_AUTOSIZE);

	//单通道像素操作
	/*int height = gray_src.rows;
	int width = gray_src.cols;
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			int gray = gray_src.at<uchar>(row, col);
			gray_src.at<uchar>(row, col)=255-gray;
	   }
	
	}
	imshow("gray_covert", gray_src);
	*/

	Mat dst;
	dst.create(src.size(), src.type());
	int height = dst.rows;
	int width = dst.cols;
	int nc = dst.channels();
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (nc == 1) {
			    int gray = dst.at<uchar>(row, col);
			    dst.at<uchar>(row, col) = 255 - gray;
			}
			if (nc == 3) {
				int b = src.at<Vec3b>(row, col)[0];
				int g = src.at<Vec3b>(row, col)[1];
				int r = src.at<Vec3b>(row, col)[2];
				dst.at<Vec3b>(row, col)[0] =  0 ;
				dst.at<Vec3b>(row, col)[1] =  g ;
				dst.at<Vec3b>(row, col)[2] =  r ;
				gray_src.at<uchar>(row, col) = max(r, max(g, b));
			}
		}
    
	}  
	//bitwise_not(src, dst);
	imshow("cov iamge", dst);
	imshow("gray2", gray_src);
	double timeconsume = (getTickCount() - t) / getTickFrequency();
	printf ("time consume %.2f\n", timeconsume);
	waitKey(0);
	/*
	//namedWindow("output window", CV_WINDOW_AUTOSIZE);
	//Mat output_image;
	//cvtColor(src, output_image, CV_BGR2HLS);
	//imshow("OUT ", output_image);
	int cols = (src.cols) * src.channels();
	int offsetx = src.channels();
	int rows = src.rows;
	Mat dst = Mat::zeros(src.size(), src.type());
	for (int row = 1; row < (rows - 1); row++) {
		const uchar* previous = src.ptr<uchar>(row-1);
		const uchar* current = src.ptr<uchar>(row);
		const uchar* next = src.ptr<uchar>(row+1);
		uchar* output = dst.ptr<uchar>(row);
		for (int col = offsetx; col < cols; col++) {
			output[col] =saturate_cast<uchar>( 5 * current[col] - (current[col - offsetx] + current[col + offsetx] + previous[col] + next[col]));
		
		}
	}
	namedWindow("constract image demo", CV_WINDOW_AUTOSIZE);
	imshow("current iamge demo ", dst);
	waitKey(0);
	return 0;
	*/

	    
}