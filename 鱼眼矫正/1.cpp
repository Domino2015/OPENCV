#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/imgproc/imgproc.hpp"  
#include <iostream>  

//-----------------------------------�������ռ��������֡�--------------------------------------  
//          ����������������ʹ�õ������ռ�  
//-----------------------------------------------------------------------------------------------  
using namespace cv;
using namespace std;

//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------  
//     ������ȫ�ֺ�������  
//-----------------------------------------------------------------------------------------------
//int cx;//ͼ������x����
//int cy;//ͼ������y����
//int dr;//���ĺ�Բ�뾶
//int DR;//��߽��Բ�뾶
//double PI = 3.141592;
//int rou; //�ǰ뾶
//double phi;//th�ǽǶȣ����ȣ�
//double theta;//����Ƕ�
//double newRou; //�ǰ뾶
//-----------------------------------��main( )������--------------------------------------------  
//          ����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼִ��  
//-----------------------------------------------------------------------------------------------  
//int main()
//{
	//��������  
	//Mat srcImage, srcImage1, dstImage;
	//Mat map_x, map_y;

	//����ԭʼͼ  
	//srcImage = imread("1.jpg", 1);
	//srcImage1 = imread("2.jpg", 1);
	//if (!srcImage.data) { cout<<"��ȡͼƬ������ȷ��Ŀ¼���Ƿ���imread����ָ����ͼƬ����~�� \n"; return -1; }
	//imshow("ԭʼͼ", srcImage);

	//��ʼ������
	//cx = srcImage1.rows/2;
	//cy = srcImage1.cols/2;
	//dr = 60;
	//DR = 375;
	//double thetamax = 4 * PI / 9;
	//double f = DR / thetamax;
	// ѡȡһ��ROIͼ������ ��������
	//Rect rect(100, 220, 150, 150);
	//srcImage(rect).copyTo(srcImage);
	//imshow("roi", srcImage);
	////������ԭʼͼһ����Ч��ͼ��x��ӳ��ͼ��y��ӳ��ͼ  
	//dstImage.create(srcImage1.size(), srcImage1.type());
	//map_x.create(srcImage1.size(), CV_32FC1);
	//map_y.create(srcImage1.size(), CV_32FC1);
	////˫��ѭ��������ÿһ�����ص㣬�ı�map_x & map_y��ֵ  
	//for (int j = 0; <j <srcImage1.rows; j++)
	//{
	//	for (int i = 0; <i < srcImage.cols; i++)
	//	{
	//		i = i - cx;
	//		j = j - cy;
	//		double ii, jj;
	//		//�ı�map_x & map_y��ֵ.   
	//		//map_x.at<float>(j, i) = static_cast<float>(i);
	//		//map_y.at<float>(j, i) = static_cast<float>(j);
	//		//�ѿ�������ת��Ϊ������
	//		phi = atan2(i, j);
	//		rou = hypot(i, j);
	//		theta = rou / f;
	//		newRou = f*tan(theta);
	//		//cout <<newRou <<" "<<theta<< endl;
	//		ii = (int)newRou*cos(theta);
	//		jj = (int)newRou*sin(theta);
	//		//cout << ii << "  " << jj << endl;
	//		map_x.at<float>(j, i) = static_cast<float>(i-ii);
	//		map_y.at<float>(j, i) = static_cast<float>(j-jj);
	//	}
	//}


	////������ӳ�����  
	//remap(srcImage, dstImage, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));

	////��ʾЧ��ͼ  
	//imshow("��Ч��ͼ��", dstImage);

	//waitKey();

	//return 0;
//}

//����cvLogPolar����,�ѿ������굽������任
//Mat translateToPolar(Mat image, int centerx, int centery, int m)
//{
//	if (image.empty())
//		return image;
//	cv::Mat pImage = cv::Mat::zeros(image.size(), CV_8UC1);
//	IplImage ipl_a = image, ipl_pa = pImage;
//	cvLogPolar(&ipl_a, &ipl_pa, cvPoint2D32f(centerx, centery), m);
//	return pImage;
//}
