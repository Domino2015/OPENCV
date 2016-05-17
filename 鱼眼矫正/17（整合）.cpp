////-----------------------------------������˵����----------------------------------------------  
////      ��������:������ʶ��ͼ�����  
////      ��������IDE�汾��Visual Studio 2013  
////      ��������OpenCV�汾��   3.1.0  
////      2016��5��11�� Created by ����
////----------------------------------------------------------------------------------------------
//
////-----------------------------------��ͷ�ļ��������֡�------------------------------------- 
////      ����������������������ͷ�ļ�  
////----------------------------------------------------------------------------------------------
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/objdetect/objdetect.hpp"
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/core/core.hpp>
//#include <stdio.h>
//#include <iostream>
//
////-----------------------------------�������ռ��������֡�------------------------------------ 
////          ����������������ʹ�õ������ռ�  
////-----------------------------------------------------------------------------------------------
//using namespace cv;
//using namespace std;
//
////-----------------------------------��ȫ�ֺ����������֡�------------------------------------ 
////          ������ȫ�ֺ���������  
////----------------------------------------------------------------------------------------------- 
//
///** ����ʶ���� */
//void detectAndDisplay(Mat& frame);
//
////-----------------------------------��ȫ�ֱ����������֡�------------------------------------ 
////          ������ȫ�ֱ���������  
////----------------------------------------------------------------------------------------------- 
//String face_cascade_name = "haarcascade_frontalface_alt.xml";//����ʶ�����������
//String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";//�۾�ʶ����������ƣ�δ��ɣ�
//CascadeClassifier face_cascade;//��������������  
//CascadeClassifier eyes_cascade;//�����۾�������  
//static CvMemStorage* storage = 0;
//static CvHaarClassifierCascade* cascade = 0;
//
////-----------------------------------��main( )������--------------------------------------------  
////   ����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼִ��  
////-----------------------------------------------------------------------------------------------  
//int main(int argc, unsigned char* argv[])
//{
//
//	//������ͷ��0����Ĭ������ͷ��1���������ͷ
//	VideoCapture cam(1);
//	//�ж�����ͷ�Ƿ�������
//	if (!cam.isOpened()){return -1;}
//
//	while (1)
//	{
//		Mat frame;//����һ��Mat���ڴ�����Ƶ��ȡһ֡ͼ��
//		//��ȡһ֡ͼ��
//		cam >> frame;
//		if (frame.empty()){return -1;}//�ж϶�ȡһ֡ͼ���Ƿ����
//			
//		//����ʶ���ļ����ж�
//		if (!face_cascade.load(face_cascade_name)){ printf("open faces faile"); return -1; }//�ж�����ʶ��������Ƿ�������
//		if (!eyes_cascade.load(eyes_cascade_name)){ printf("open eyes faile"); return -1; }//�ж��۾�ʶ��������Ƿ�������
//		storage = cvCreateMemStorage(0); 
//		detectAndDisplay(frame);//���ú���ʵ������ʶ��
//
//		char c;
//		//������Ӧ
//		c = (char)waitKey(20);
//		if (27 == c)//ESC��
//			return -1;
//	}
//	return 0;
//}
//
////-----------------------------------��detectAndDisplay( )������----------------------------------    
////      ����������ʵ������ʶ������һ��Mat����ʾ��Բ�α�ǵ� ��������
////----------------------------------------------------------------------------------------------    
//void detectAndDisplay(Mat& frame)
//{
//
//	std::vector<Rect> faces;//����һ������ʶ����������
//	Mat frame_gray;
//	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);//���ڸ�ά��ͼ��ռ䣬��������Ӧ�ý��н�ά�������������
//	equalizeHist(frame_gray, frame_gray);
//	//����detectMultiScale()�������
//	face_cascade.detectMultiScale(frame_gray, faces,
//		1.1,
//		2,
//		0,
//		Size(20, 20));
//	/**detectMultiScale()��������˵��
//	    1.image��ʾ����Ҫ��������ͼ��
//		2.objects��ʾ��⵽������Ŀ������
//		3.scaleFactor��ʾÿ��ͼ��ߴ��С�ı���
//		4. minNeighbors��ʾÿһ��Ŀ������Ҫ����⵽3�β��������Ŀ��(��Ϊ��Χ�����غͲ�ͬ�Ĵ��ڴ�С�����Լ�⵽����),
//		5.minSizeΪĿ�����С�ߴ�
//		6.minSizeΪĿ������ߴ�
//		*/
//	for (size_t i = 0; i < faces.size(); i++)
//	{
//		Mat faceROI = frame_gray(faces[i]);//ѡȡ��������ΪROI����
//		std::vector<Rect> eyes;//����һ���۾�ʶ����������
//
//		//Ȧ�������������״��ellipseԲ�Σ�rectangle����
//		//Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);//ȷ����������Բ��
//		//ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 0), 2, 8, 0);
//		rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
//		//����Ϊ�����ص�ͼ�񡢶��㡢�Խǵ㡢��ɫ����������ɫ������ϸ����С 
//
//		//��������������Ͻ����꣬�����ȣ�����
//		cout << "(" << faces[i].x << " , " << faces[i].y << ")" << "    ";
//		cout<< "(" << faces[i].width << " , " << faces[i].height << ")" << endl;
//		//=======���β���=============
//		Mat out;//����һ��������κ��mat
//		Mat map_x, map_y;
//		int ox, oy;//ͼ������
//		//ѡȡ��������ΪROI����
//		faceROI = frame(Rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height));
//		//����ͼƬ����Ϊԭ�㣨oy,ox��
//		oy = faceROI.cols / 2;
//		ox = faceROI.rows / 2;
//		double theta;//������ת���õ��Ƕ�theta
//		double range;//������ת���õ��뾶range
//		double rangeMax;//�涨���뾶
//		double newRange;//��һ����뾶r
//		//������ԭʼͼһ����Ч��ͼ��x��ӳ��ͼ��y��ӳ��ͼ
//		faceROI.create(faceROI.size(), faceROI.type());
//		map_x.create(faceROI.size(), CV_32FC1);
//		map_y.create(faceROI.size(), CV_32FC1);
//		//˫��ѭ��������ÿһ�����ص㣬�ı�map_x & map_y��ֵ
//		for (int j = 0; j < faceROI.rows; j++)
//		{
//			for (int i = 0; i <faceROI.cols; i++)
//			{
//				double newX = i - ox;//����ԭ��仯��X����
//				double newY = j - oy;//����ԭ��仯��Y����
//				theta = atan2(newY, newX);//������ת���õ��Ƕ�theta
//				range = hypot(newX, newY);//������ת���õ��뾶range
//				rangeMax = 100;//�������뾶
//				newRange = range / rangeMax;//��һ��
//				newRange = pow(newRange, 0.7);//����ͼ������㷨--͹��
//				//newRange = pow(newRange, 2);//����ͼ������㷨--����
//				//newRange = sin(newRange*CV_PI / 2);//����ͼ������㷨--����
//				//newRange = tan(newRange*CV_PI / 4);
//				newRange = newRange*rangeMax;
//				//�ı�map_x & map_y��ֵ. 
//				map_x.at<float>(j, i) = static_cast<float>(newRange*cos(theta) + ox);//ת��Ϊֱ�����꣬�����������Ļ�ԭ
//				map_y.at<float>(j, i) = static_cast<float>(newRange*sin(theta) + oy);
//			}
//		}
//		//������ӳ�����
//		remap(faceROI, out, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//		imshow("ROI�����", out);
//	}
//	imshow("����ʶ��", frame);
//}