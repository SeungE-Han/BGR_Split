#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main() {
	Mat image;
	image = imread("hwfig01.jpg", IMREAD_COLOR); //영상을 읽어들임
	if (image.empty()) { cout << "영상을 읽을 수 없음" << endl; }

	imshow("출력 영상", image); //영상 보여줌

	cout << "해상도= " << image.size() << endl;
	cout << "depth= " << image.depth() << endl;
	cout << "채널 수= " << image.channels() << endl;
	cout << "영상파일 크기= " << image.total()*(int)image.elemSize() << endl;
	//영상 파일 크기= (행렬 원소의 전체 개수)*(한 원소에 대한 바이트 크기)

	Mat bgr[3];
	split(image, bgr); //bgr로 분리
	imwrite("hwfig01_blue.jpg", bgr[0]); //분리된 영상 저장
	imwrite("hwfig01_green.jpg", bgr[1]); //분리된 영상 저장
	imwrite("hwfig01_red.jpg", bgr[2]); //분리된 영상 저장

	Mat img[3];
	img[0] = imread("hwfig01_blue.jpg", IMREAD_UNCHANGED); //파일 읽어들임
	img[1] = imread("hwfig01_green.jpg", IMREAD_UNCHANGED); //파일 읽어들임
	img[2] = imread("hwfig01_red.jpg", IMREAD_UNCHANGED); //파일 읽어들임

	imshow("b", img[0]); //영상 보여줌
	imshow("g", img[1]); //영상 보여줌
	imshow("r", img[2]); //영상 보여줌
	waitKey(0);
	
}