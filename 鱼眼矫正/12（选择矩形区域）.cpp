//#include "opencv2/imgproc/imgproc.hpp"
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/core/core.hpp>
//#include <stdio.h>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//Rect select;
//bool select_flag = false;
//Point origin;
//Mat frame;
///************************************************************************************************************************/
///****                            ����������onMouse()�����Ļ�������Ի�������϶����ο��4������                        ****/
///************************************************************************************************************************/
//void onMouse(int event, int x, int y, int, void*)
//{
//	//Point origin;//����������ط����ж��壬��Ϊ���ǻ�����Ϣ��Ӧ�ĺ�����ִ�����origin���ͷ��ˣ����Դﲻ��Ч����
//	if (select_flag)
//	{
//		select.x = MIN(origin.x, x);//��һ��Ҫ����굯��ż�����ο򣬶�Ӧ������갴�¿�ʼ���������ʱ��ʵʱ������ѡ���ο�
//		select.y = MIN(origin.y, y);
//		select.width = abs(x - origin.x);//����ο�Ⱥ͸߶�
//		select.height = abs(y - origin.y);
//		select &= Rect(0, 0, frame.cols, frame.rows);//��֤��ѡ���ο�����Ƶ��ʾ����֮��
//	}
//	if (event == CV_EVENT_LBUTTONDOWN)
//	{
//		select_flag = true;//��갴�µı�־����ֵ
//		origin = Point(x, y);//�������������ǲ�׽���ĵ�
//		select = Rect(x, y, 0, 0);//����һ��Ҫ��ʼ������͸�Ϊ(0,0)����Ϊ��opencv��Rect���ο����ڵĵ��ǰ������Ͻ��Ǹ���ģ����ǲ������½��Ǹ���
//	}
//	else if (event == CV_EVENT_LBUTTONUP)
//	{
//		select_flag = false;
//	}
//}
//
//int main(int argc, unsigned char* argv[])
//{
//	char c;
//
//	//������ͷ
//	VideoCapture cam(0);
//	if (!cam.isOpened())
//		return -1;
//
//	//��������
//	namedWindow("camera", 1);//��ʾ��Ƶԭͼ��Ĵ���
//
//	//��׽���
//	setMouseCallback("camera", onMouse, 0);
//
//	while (1)
//	{
//		//��ȡһ֡ͼ��
//		cam >> frame;
//		if (frame.empty())
//			return -1;
//
//		//�������ο�
//		rectangle(frame, select, Scalar(255, 0, 0), 3, 8, 0);//�ܹ�ʵʱ��ʾ�ڻ����δ���ʱ�ĺۼ�
//		//�õ�������Ͻǵ�λ�ã����ο�ȣ��߶�
//		cout << "X����  : " << select.x << "   Y����  :  " << select.y << endl;
//		cout << "ROI���  : " << select.width << "  ROI�߶�  : " << select.height << endl;
//		if (select.width != 0)
//		{
//			Mat imageROI;
//			Mat out;
//			Mat map_x, map_y;
//			int ox, oy;//ͼ������
//			imageROI = frame(Rect(select.x, select.y, select.width, select.height));
//			//����ͼƬ����Ϊԭ��
//			oy = imageROI.cols / 2;
//			ox = imageROI.rows / 2;
//			double theta;
//			double range;
//			double rangeMax;
//			double newRange;//��һ����r
//			//������ԭʼͼһ����Ч��ͼ��x��ӳ��ͼ��y��ӳ��ͼ
//			imageROI.create(imageROI.size(), imageROI.type());
//			map_x.create(imageROI.size(), CV_32FC1);
//			map_y.create(imageROI.size(), CV_32FC1);
//			//˫��ѭ��������ÿһ�����ص㣬�ı�map_x & map_y��ֵ
//			for (int j = 0; j < imageROI.rows; j++)
//			{
//				for (int i = 0; i < imageROI.cols; i++)
//				{
//					double newX = i - ox;
//					double newY = j - oy;
//					theta = atan2(newY, newX);
//					range = hypot(newX, newY);
//					rangeMax = 100;
//					newRange = range / rangeMax;
//					newRange = pow(newRange, 0.7);
//					newRange = newRange*rangeMax;
//					//�ı�map_x & map_y��ֵ. 
//					map_x.at<float>(j, i) = static_cast<float>(newRange*cos(theta) + ox);
//					map_y.at<float>(j, i) = static_cast<float>(newRange*sin(theta) + oy);
//				}
//			}
//			//������ӳ�����
//			remap(imageROI, out, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//			
//			imshow("ROI", imageROI);
//			imshow("ROI�����", out);
//
//			cout << "------------�������-------------" << endl;
//		}
//		//��ʾ��ƵͼƬ������
//		imshow("camera", frame);
//
//		//������Ӧ
//		c = (char)waitKey(20);
//		if (27 == c)//ESC��
//			return -1;
//	}
//
//	return 0;
//}
