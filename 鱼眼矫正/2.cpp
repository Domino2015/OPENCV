//#include "opencv2/highgui/highgui.hpp"  
//#include "opencv2/imgproc/imgproc.hpp"  
//#include <iostream>  
//
////-----------------------------------�������ռ��������֡�--------------------------------------  
//using namespace cv;
//using namespace std;
////-----------------------------------��ȫ�ֺ����������֡�--------------------------------------  
////     ������ȫ�ֺ�������  
////-----------------------------------------------------------------------------------------------
//static void ContrastAndBright(int, void *);
//
//int dr;//���ĺ�Բ�뾶
//double PI = 3.141592;
//int rou; //�ǰ뾶
//double phi;//th�ǽǶȣ����ȣ�
//double theta;//����Ƕ�
//double newRou; //�ǰ뾶
//double f;
//int g_nDRValue; //���뾶ֵ  
//int g_nThetamaxValue;  //���Ƕ�ֵ 
////��������  
//Mat srcImage, dstImage, dstImage2;
//Mat map_x, map_y;
//int main()
//{
//	
//	//��ʼ������
//	dr = 174;
//	//�趨���뾶ֵ  �����Ƕ�ֵ�ĳ�ֵ  
//	g_nDRValue = 800; //��߽��Բ�뾶
//	g_nThetamaxValue = 80;  //���Ƕ�ֵ
//
//
//	//����ԭʼͼ  
//	srcImage = imread("1.jpg", 1);
//	if (!srcImage.data) { cout<<"��ȡͼƬ����!\n"; return -1; }
//	imshow("ԭʼͼ", srcImage);
//	//ѡȡROI
//	dstImage = srcImage(Rect(250, 55, 300, 300)); // Cloud region
//	imshow("hehe", dstImage);
//	////�������
//	//double thetamax = g_nThetamaxValue * PI / 180;
//	//double f = g_nDRValue / thetamax;
//	////������ԭʼͼһ����Ч��ͼ��x��ӳ��ͼ��y��ӳ��ͼ  
//	//dstImage.create(dstImage.size(), dstImage.type());
//	//map_x.create(srcImage.size(), CV_32FC1);
//	//map_y.create(srcImage.size(), CV_32FC1);
//
//	////��3��˫��ѭ��������ÿһ�����ص㣬�ı�map_x & map_y��ֵ  
//	//for (int j = 0;j < srcImage.rows; j++)
//	//{
//	//	for (int i = 0; i < srcImage.cols; i++)
//	//	{
//	//		
//	//		//�ѿ�������ת��Ϊ������
//	//		phi = atan2(i, j);
//	//		rou = hypot(i, j);
//	//		theta = rou / f;
//	//		newRou = f*tan(theta);
//	//		//�ı�map_x & map_y��ֵ. 
//	//		map_x.at<float>(j, i) = static_cast<float>(i - newRou*cos(theta));
//	//		map_y.at<float>(j, i) = static_cast<float>(j - newRou*sin(theta));
//	//	}
//	//}
//
//	////������ӳ�����  
//	//remap(dstImage, dstImage2, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//	//��������  
//	namedWindow("�����򴰿ڡ�", 1);
//
//	//�����켣��  
//	createTrackbar("���ࣺ", "�����򴰿ڡ�", &g_nDRValue, 2000, ContrastAndBright);
//	createTrackbar("thetamax��", "�����򴰿ڡ�", &g_nThetamaxValue, 360, ContrastAndBright);
//	//���ûص�����  
//	ContrastAndBright(g_nDRValue, 0);
//	ContrastAndBright(g_nThetamaxValue, 0);
//	//��ʾЧ��ͼ  
//	imshow("�����򴰿ڡ�", dstImage2);
//	waitKey();
//
//	return 0;
//}
//static void ContrastAndBright(int, void *)
//{
//
//	//�������
//	double thetamax = g_nThetamaxValue * PI / 180;
//	double f = g_nDRValue / thetamax;
//	//������ԭʼͼһ����Ч��ͼ��x��ӳ��ͼ��y��ӳ��ͼ  
//	dstImage.create(dstImage.size(), dstImage.type());
//	map_x.create(srcImage.size(), CV_32FC1);
//	map_y.create(srcImage.size(), CV_32FC1);
//
//	//˫��ѭ��������ÿһ�����ص㣬�ı�map_x & map_y��ֵ  
//	for (int j = 0; j < srcImage.rows; j++)
//	{
//		for (int i = 0; i < srcImage.cols; i++)
//		{
//
//			//�ѿ�������ת��Ϊ������
//			phi = atan2(i, j);
//			rou = hypot(i, j);
//			theta = rou / f;
//			newRou = f*tan(theta);
//			//�ı�map_x & map_y��ֵ. 
//			map_x.at<float>(j, i) = static_cast<float>(i - newRou*cos(theta));
//			map_y.at<float>(j, i) = static_cast<float>(j - newRou*sin(theta));
//		}
//	}
//
//	//������ӳ�����  
//	remap(dstImage, dstImage2, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//
//	//��ʾЧ��ͼ  
//	imshow("�����򴰿ڡ�", dstImage2);
//}
