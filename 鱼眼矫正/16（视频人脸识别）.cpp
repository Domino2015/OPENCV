//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/objdetect/objdetect.hpp"
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/core/core.hpp>
//#include <stdio.h>
//#include <iostream>
////-----------------------------------【命名空间声明部分】------------------------------------ 
////          描述：包含程序所使用的命名空间  
////-----------------------------------------------------------------------------------------------
//using namespace cv;
//using namespace std;
//
//Rect select;
//bool select_flag = false;
//Point origin;
//Mat frame;
//
////-----------------------------------【全局函数声明部分】------------------------------------ 
////          描述：全局函数的声明  
////----------------------------------------------------------------------------------------------- 
//
////---------------人脸识别---------
///** Function Headers */
//void detectAndDisplay(Mat& frame);
//
////-----------------------------------【全局变量声明部分】------------------------------------ 
////          描述：全局变量的声明  
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
//	//打开摄像头
//	VideoCapture cam(1);
//	//
//	if (!cam.isOpened())
//		return -1;
//
//	while (1)
//	{
//		//读取一帧图像
//		cam >> frame;
//		if (frame.empty())
//			return -1;
//		//人脸识别文件打开判断
//		if (!face_cascade.load(face_cascade_name)){ printf("open faces faile"); return -1; }
//		if (!eyes_cascade.load(eyes_cascade_name)){ printf("open eyes faile"); return -1; }
//		storage = cvCreateMemStorage(0);
//		detectAndDisplay(frame);
//		//键盘响应
//		c = (char)waitKey(20);
//		if (27 == c)//ESC键
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
//		int ox, oy;//图像中心
//		faceROI = frame(Rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height));
//		//设置图片中心为原点
//		oy = faceROI.cols / 2;
//		ox = faceROI.rows / 2;
//		double theta;
//		double range;
//		double rangeMax;
//		double newRange;//归一化后r
//		//创建和原始图一样的效果图，x重映射图，y重映射图
//		faceROI.create(faceROI.size(), faceROI.type());
//		map_x.create(faceROI.size(), CV_32FC1);
//		map_y.create(faceROI.size(), CV_32FC1);
//		//双层循环，遍历每一个像素点，改变map_x & map_y的值
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
//					//改变map_x & map_y的值. 
//					map_x.at<float>(j, i) = static_cast<float>(newRange*cos(theta) + ox);
//					map_y.at<float>(j, i) = static_cast<float>(newRange*sin(theta) + oy);
//				}
//			}
//			//进行重映射操作
//		remap(faceROI, out, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//		imshow("ROI处理后", out);
//	}
//	imshow("人脸识别", frame);
//
//}