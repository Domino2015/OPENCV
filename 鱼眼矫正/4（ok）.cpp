//#include <iostream>
//#include <opencv2/opencv.hpp>
//using namespace cv;
//
//
//Mat fish;//ԭͼƬ
//Mat fishROI;//ѡȡ����Ȥ����
//Mat nor;//����Ч��ͼ
//Mat mx, my;
//int ox, oy;//ͼ������
//
//double dr, DR; //��߽��Բ�뾶���ڲ�СԲ�뾶
//double thetaMax;//���Ƕ�
//double f;//����
//
////����ͼƬ����Ϊԭ��
//void setO(Mat& m)
//{
//	ox = m.cols / 2;
//	oy = m.rows / 2;
//}
////�õ����ص����ԭ��ľ���
//double getRange(double x, double y)
//{
//	double i = sqrt((x - ox)*(x - ox) + (y - oy)*(y - oy));
//	return i;
//}
//
//void on_trackbar(int th)
//{
//	f = th;
//	for (int j = 0; j < nor.rows; j++)
//	{
//		for (int i = 0; i < nor.cols; i++)
//		{
//			double range = getRange(i, j);
//			mx.at<float>(j, i) = static_cast<float>((ox + ((i - ox) / ((range / f) / atan(range / f)))) - 300);//fish.cols-(ox+((ox-i-100)/((range/f)/atan(range/f))))
//			my.at<float>(j, i) = static_cast<float>((oy + ((j - oy) / ((range / f) / atan(range / f)))) - 300);//fish.rows-(oy+((oy-j-100)/((range/f)/atan(range/f))))
//		}
//	}
//	remap(fishROI, nor, mx, my, CV_INTER_LINEAR);
//	imshow("2", nor);
//}
//
//int main()
//{
//	//��ʼֵ�Ĵ���,����û��ֵ���룬������ʱ��ֵΪ1
//	dr = 1;
//	DR = 1;
//	thetaMax = 1;
//
//	//ͼƬ�ĳ�ʼ�����
//	fish = imread("4.jpg", 1);
//
//	imshow("1", fish);
//	//������ԭʼͼһ����Ч��ͼ��x��ӳ��ͼ��y��ӳ��ͼ  
//	nor.create(fish.rows * 2, fish.cols * 2, fish.type());
//	mx.create(fish.rows * 2, fish.cols * 2, CV_32FC1);
//	my.create(fish.rows * 2, fish.cols * 2, CV_32FC1);
//
//
//	f = DR / thetaMax;
//	//����������ʹ��ԭ��������ϵ
//
//	//����ͼƬ����Ϊԭ��
//	setO(fish);
//
//	//���ø���Ȥ����
//	//fish(Rect(400,100,1200,400)).copyTo(fishROI);
//	fish(Rect(1, 1, 300, 300)).copyTo(fishROI);
//	imshow("3", fishROI);
//
//	ox = ox + 300;
//	oy = oy + 300;
//
//	//���theta+�任ģ��
//	imshow("2", nor);
//	int num = 1;//�����ʼֵ
//	cvCreateTrackbar("f", "2", &num, 1000, on_trackbar);
//
//	cvWaitKey();
//}