//#include <iostream>
//#include <stdio.h>
//#include "opencv2/objdetect/objdetect.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <cv.h>
//#include <highgui.h>
//
//using namespace std;
//using namespace cv;
//
///** Function Headers */
//void detectAndDisplay(Mat& frame);
////void detect_and_draw(IplImage* img);
//
///** Global variables */
//String face_cascade_name = "haarcascade_frontalface_alt.xml";
//String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
//CascadeClassifier face_cascade;
//CascadeClassifier eyes_cascade;
//static CvMemStorage* storage = 0;
//static CvHaarClassifierCascade* cascade = 0;
//String window_name = "Capture - Face detection";
///**
//* @function main
//*/
//int main(void)
//{
//
//	if (!face_cascade.load(face_cascade_name)){printf("open faces faile");return -1;}
//	if (!eyes_cascade.load(eyes_cascade_name)){printf("open eyes faile");return -1;}
//	Mat A = imread("10.jpg", IMREAD_COLOR);
//	if (A.empty()){
//
//		cout << "image faile";
//
//	}
//
//	imshow("image", A);
//	waitKey(10);
//	storage = cvCreateMemStorage(0);
//	namedWindow(window_name.c_str(), 1);
//
//	detectAndDisplay(A);
//	return 0;
//
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
//
//	for (size_t i = 0; i < faces.size(); i++)
//	{
//
//		Mat faceROI = frame_gray(faces[i]);
//		std::vector<Rect> eyes;
//		//-- Draw the face
//		Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
//		ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 0), 2, 8, 0);
//
//	}
//	imshow(window_name, frame);
//	waitKey();
//
//}