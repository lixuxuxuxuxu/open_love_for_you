#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <iostream>
#include<math.h>
using namespace cv;
using namespace std;


Mat dst;
void myline();
int main(int argc, char** argv) {

	Mat src = imread("D:/Users/Xuxuxuxuxu/Desktop/my/love.jpg");

	if (!src.data) {
		printf("could not load image...\n");
	    return -1;
	}
	char input_win[] = "input image";
	namedWindow(input_win, CV_WINDOW_AUTOSIZE);
	imshow(input_win, src);

	int height = src.rows;
	int width = src.cols;
	float alpha = 1.2;
	float beta = 10;
	dst = Mat::zeros(src.size(), src.type());
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (src.channels() == 3) {
				float b = src.at<Vec3b>(row, col)[0];
				float g = src.at<Vec3b>(row, col)[1];
				float r = src.at<Vec3b>(row, col)[2];

				dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b * alpha + beta);
				dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g * alpha + beta);
				dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r * alpha + beta);
		   }
			else if (src.channels() == 1) {
				float v = src.at<uchar>(row, col);
				dst.at<uchar>(row, col)= saturate_cast<uchar>(v * alpha + beta);
			}
		}
	}
	myline();
	char output_win[] = "output image";
	namedWindow(output_win, CV_WINDOW_AUTOSIZE);
	imshow("output image ", dst);


	waitKey(0);
	return 0;
}

void myline() {
	Point p1 = Point(29, 29);
	Point p2 = Point(290, 290);
	Scalar color = Scalar(255, 0, 0);
	line(dst, p1, p2, color, 1, LINE_8);


}