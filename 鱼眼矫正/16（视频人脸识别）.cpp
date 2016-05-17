//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/objdetect/objdetect.hpp"
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/core/core.hpp>
//#include <stdio.h>
//#include <iostream>
////-----------------------------------�������ռ��������֡�------------------------------------ 
////          ����������������ʹ�õ������ռ�  
////-----------------------------------------------------------------------------------------------
//using namespace cv;
//using namespace std;
//
//Rect select;
//bool select_flag = false;
//Point origin;
//Mat frame;
//
////-----------------------------------��ȫ�ֺ����������֡�------------------------------------ 
////          ������ȫ�ֺ���������  
////----------------------------------------------------------------------------------------------- 
//
////---------------����ʶ��---------
///** Function Headers */
//void detectAndDisplay(Mat& frame);
//
////-----------------------------------��ȫ�ֱ����������֡�------------------------------------ 
////          ������ȫ�ֱ���������  
////----------------------------------------------------------------------------------------------- 
///** Global variables */
//String face_cascade_name = "haarcascade_frontalface_alt.xml";
//String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
//CascadeClassifier face_cascade;
//CascadeClassifier eyes_cascade;
//static CvMemStorage* storage = 0;
//static CvHaarClassifierCascade* cascade = 0;
//
//
//
//
//int main(int argc, unsigned char* argv[])
//{
//	char c;
//
//	//������ͷ
//	VideoCapture cam(1);
//	//
//	if (!cam.isOpened())
//		return -1;
//
//	while (1)
//	{
//		//��ȡһ֡ͼ��
//		cam >> frame;
//		if (frame.empty())
//			return -1;
//		//����ʶ���ļ����ж�
//		if (!face_cascade.load(face_cascade_name)){ printf("open faces faile"); return -1; }
//		if (!eyes_cascade.load(eyes_cascade_name)){ printf("open eyes faile"); return -1; }
//		storage = cvCreateMemStorage(0);
//		detectAndDisplay(frame);
//		//������Ӧ
//		c = (char)waitKey(20);
//		if (27 == c)//ESC��
//			return -1;
//	}
//	return 0;
//}
//
///**
//* @function detectAndDisplay
//*/
//void detectAndDisplay(Mat& frame)
//{
//
//	std::vector<Rect> faces;
//	Mat frame_gray;
//
//	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
//	equalizeHist(frame_gray, frame_gray);
//
//	//-- Detect faces
//
//	face_cascade.detectMultiScale(frame_gray, faces,
//		1.1,
//		2,
//		0,
//		Size(20, 20));
//
//	for (size_t i = 0; i < faces.size(); i++)
//	{
//		Mat faceROI = frame_gray(faces[i]);
//		std::vector<Rect> eyes;
//		//-- Draw the face
//		Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
//		ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 0), 2, 8, 0);
//		cout << "("<<faces[i].x << " , "<<faces[i].y<<")"<<"    "<< "("<<faces[i].width <<" , "<< faces[i].height <<")"<< endl;
//		//=========================
//		Mat out;
//		Mat map_x, map_y;
//		int ox, oy;//ͼ������
//		faceROI = frame(Rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height));
//		//����ͼƬ����Ϊԭ��
//		oy = faceROI.cols / 2;
//		ox = faceROI.rows / 2;
//		double theta;
//		double range;
//		double rangeMax;
//		double newRange;//��һ����r
//		//������ԭʼͼһ����Ч��ͼ��x��ӳ��ͼ��y��ӳ��ͼ
//		faceROI.create(faceROI.size(), faceROI.type());
//		map_x.create(faceROI.size(), CV_32FC1);
//		map_y.create(faceROI.size(), CV_32FC1);
//		//˫��ѭ��������ÿһ�����ص㣬�ı�map_x & map_y��ֵ
//		for (int j = 0; j < faceROI.rows; j++)
//		{
//			for (int i = 0; i <faceROI.cols; i++)
//				{
//					double newX = i - ox;
//					double newY = j - oy;
//					theta = atan2(newY, newX);
//					range = hypot(newX, newY);
//					rangeMax = 100;
//					newRange = range / rangeMax;
//					newRange = pow(newRange, 0.7);
//				    newRange = newRange*rangeMax;
//					//�ı�map_x & map_y��ֵ. 
//					map_x.at<float>(j, i) = static_cast<float>(newRange*cos(theta) + ox);
//					map_y.at<float>(j, i) = static_cast<float>(newRange*sin(theta) + oy);
//				}
//			}
//			//������ӳ�����
//		remap(faceROI, out, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//		imshow("ROI�����", out);
//	}
//	imshow("����ʶ��", frame);
//
//}