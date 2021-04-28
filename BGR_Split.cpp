#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main() {
	Mat image;
	image = imread("hwfig01.jpg", IMREAD_COLOR); //������ �о����
	if (image.empty()) { cout << "������ ���� �� ����" << endl; }

	imshow("��� ����", image); //���� ������

	cout << "�ػ�= " << image.size() << endl;
	cout << "depth= " << image.depth() << endl;
	cout << "ä�� ��= " << image.channels() << endl;
	cout << "�������� ũ��= " << image.total()*(int)image.elemSize() << endl;
	//���� ���� ũ��= (��� ������ ��ü ����)*(�� ���ҿ� ���� ����Ʈ ũ��)

	Mat bgr[3];
	split(image, bgr); //bgr�� �и�
	imwrite("hwfig01_blue.jpg", bgr[0]); //�и��� ���� ����
	imwrite("hwfig01_green.jpg", bgr[1]); //�и��� ���� ����
	imwrite("hwfig01_red.jpg", bgr[2]); //�и��� ���� ����

	Mat img[3];
	img[0] = imread("hwfig01_blue.jpg", IMREAD_UNCHANGED); //���� �о����
	img[1] = imread("hwfig01_green.jpg", IMREAD_UNCHANGED); //���� �о����
	img[2] = imread("hwfig01_red.jpg", IMREAD_UNCHANGED); //���� �о����

	imshow("b", img[0]); //���� ������
	imshow("g", img[1]); //���� ������
	imshow("r", img[2]); //���� ������
	waitKey(0);
	
}