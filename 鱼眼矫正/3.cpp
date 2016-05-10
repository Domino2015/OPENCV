//#include "opencv2/highgui/highgui.hpp"  
//#include "opencv2/imgproc/imgproc.hpp"  
//#include <iostream>  
//
////-----------------------------------�������ռ��������֡�--------------------------------------  
////          ����������������ʹ�õ������ռ�  
////-----------------------------------------------------------------------------------------------  
//using namespace cv;
//using namespace std;
//
////-----------------------------------��ȫ�ֺ����������֡�--------------------------------------  
////     ������ȫ�ֺ�������  
////-----------------------------------------------------------------------------------------------
//
////-----------------------------------��ȫ�ֱ����������֡�--------------------------------------  
////     ������ȫ�ֱ�������  
////-----------------------------------------------------------------------------------------------
//int cx;//ͼ������X����
//int cy;//ͼ������y����
//int dr;//���ĺ�Բ�뾶
//int DR;//��߽��Բ�뾶
//double PI = 3.141592;
//int rou; //�ǰ뾶
//double phi;//th�ǽǶȣ����ȣ�
//double theta;//����Ƕ�
//double newRou; //�ǰ뾶
//double thetamax=80;
//double f;
////-----------------------------------��main( )������--------------------------------------------  
////          ����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼִ��  
////-----------------------------------------------------------------------------------------------  
//int main()
//{
//	//��0����������  
//	Mat srcImage, srcImage1, dstImage;
//	Mat map_x, map_y;
//
//	//��1������ԭʼͼ  
//	srcImage = imread("1.jpg", 1);
//	srcImage1 = imread("3.jpg", 1);
//	cx = 450;
//	cy = 450;
//	rou = 100;
//	dr = 20;
//	DR = 100;
//	thetamax = thetamax*PI / 180;
//	f = DR / thetamax;
//	if (!srcImage.data) { cout << "��ȡͼƬ������ȷ��Ŀ¼���Ƿ���imread����ָ����ͼƬ����~�� \n"; return -1; }
//	imshow("ԭʼͼ", srcImage);
//
//	//��2��������ԭʼͼһ����Ч��ͼ��x��ӳ��ͼ��y��ӳ��ͼ  
//	dstImage.create(srcImage1.size(), srcImage.type());
//	map_x.create(srcImage1.size(), CV_32FC1);
//	map_y.create(srcImage1.size(), CV_32FC1);
//	//��3��˫��ѭ��������ÿһ�����ص㣬�ı�map_x & map_y��ֵ  
//	for (int j = 0; j < srcImage1.rows; j++)
//	{
//		for (int i = 0; i < srcImage1.cols; i++)
//		{
//			//�ѿ�������ת��Ϊ������
//			phi = atan2(i, j);
//			rou = hypot(i, j);
//			theta = rou / f;
//			newRou = f*tan(theta);
//			//�ı�map_x & map_y��ֵ.   
//			map_x.at<float>(j, i) = static_cast<float>(i - cx);
//			map_y.at<float>(j, i) = static_cast<float>(j - cy);
//		}
//	}
//
//	//��4��������ӳ�����  
//	remap(srcImage, dstImage, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//
//	//��5����ʾЧ��ͼ  
//	imshow("�����򴰿ڡ�", dstImage);
//	waitKey();
//
//	return 0;
//}
//
////double getPoint(int i,int j)
////{
////	double ii, jj;
////	//�ѿ�������ת��Ϊ������
////	phi = atan2(i, j);
////	rou = hypot(i, j);
////	theta = rou / f;
////	newRou = f*tan(theta);
////	//cout <<newRou <<" "<<theta<< endl;
////	ii = newRou*cos(theta) - cx;
////	jj = newRou*sin(theta) - cy;
////	//�ı�map_x & map_y��ֵ.   
////	//map_x.at<float>(j, i) = static_cast<float>(ii);
////	//map_y.at<float>(j, i) = static_cast<float>(jj);
////}
