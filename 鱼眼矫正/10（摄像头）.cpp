//#include<opencv2\opencv.hpp>
//#include<iostream>
//#include<math.h>
//
//using namespace std;
//using namespace cv;
//
//Mat srcImg;//ԭͼƬ
//Mat srcImagROI;//ѡȡ����Ȥ����
//Mat outImg;//����Ч��ͼ
//Mat map_x, map_y;
//int ox, oy;//ͼ������
//double theta;
//double range;
//double rangeMax;
//double newRange;//��һ����r
//double PI = 3.14;
//string name = "��������ͷ";
//
//
//
////�õ����ص����ԭ��ľ���
//double getRange(double x, double y)
//{
//	double i = sqrt(x*x + y*y);
//	return i;
//}
//
//int main()
//{
//	VideoCapture capture; //������Ƶ������  
//	capture.open(0); //������ͷ������Ƶ 0��ʾ������ͷ����  
//
//	if (!capture.isOpened()) //���ж��Ƿ������ͷ  
//	{
//		cout << "can not open";
//		cin.get();
//		return -1;
//	}
//
//	namedWindow(name);
//
//	while (1) {
//		Mat srcImg; //����һ��Mat���������ڴ洢ÿһ֡��ͼ��  
//		capture >> srcImg; //��ȡ��ǰ֡  
//		if (!srcImg.data) { cout << "��ȡͼƬ������ȷ��Ŀ¼���Ƿ���imread����ָ����ͼƬ����~�� \n"; return -1; }
//		imshow("ԭʼͼ", srcImg);
//		//����ͼƬ����Ϊԭ��
//		oy = srcImg.cols / 2;
//		ox = srcImg.rows / 2;
//		//������ԭʼͼһ����Ч��ͼ��x��ӳ��ͼ��y��ӳ��ͼ
//		srcImg.create(srcImg.size(), srcImg.type());
//		map_x.create(srcImg.size(), CV_32FC1);
//		map_y.create(srcImg.size(), CV_32FC1);
//
//		//˫��ѭ��������ÿһ�����ص㣬�ı�map_x & map_y��ֵ
//		for (int j = 0; j < srcImg.rows; j++)
//		{
//			for (int i = 0; i < srcImg.cols; i++)
//			{
//				double newX = i - ox;
//				double newY = j - oy;
//				theta = atan2(newY, newX);
//				range = hypot(newX, newY);
//				rangeMax = 100;
//				newRange = range / rangeMax;
//				newRange = pow(newRange, 0.7);
//				newRange = newRange*rangeMax;
//				//�ı�map_x & map_y��ֵ. 
//				map_x.at<float>(j, i) = static_cast<float>(newRange*cos(theta) + ox);
//				map_y.at<float>(j, i) = static_cast<float>(newRange*sin(theta) + oy);
//			}
//		}
//		//������ӳ�����
//		remap(srcImg, outImg, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//
//		//��ʾЧ��ͼ
//		if (!srcImg.empty()) //�жϵ�ǰ֡�Ƿ�׽�ɹ� **�ⲽ����Ҫ  
//			imshow(name, outImg); //����ǰ֡��׽�ɹ�����ʾ  
//		else
//			cout << "can not ";
//		waitKey(30); //��ʱ30����  
//	}
//
//	waitKey();
//}



