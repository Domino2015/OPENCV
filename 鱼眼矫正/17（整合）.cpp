////-----------------------------------【程序说明】----------------------------------------------  
////      程序名称:：人脸识别图像变形  
////      开发所用IDE版本：Visual Studio 2013  
////      开发所用OpenCV版本：   3.1.0  
////      2016年5月11日 Created by 王威
////----------------------------------------------------------------------------------------------
//
////-----------------------------------【头文件包含部分】------------------------------------- 
////      描述：包含程序所依赖的头文件  
////----------------------------------------------------------------------------------------------
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/objdetect/objdetect.hpp"
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/core/core.hpp>
//#include <stdio.h>
//#include <iostream>
//
////-----------------------------------【命名空间声明部分】------------------------------------ 
////          描述：包含程序所使用的命名空间  
////-----------------------------------------------------------------------------------------------
//using namespace cv;
//using namespace std;
//
////-----------------------------------【全局函数声明部分】------------------------------------ 
////          描述：全局函数的声明  
////----------------------------------------------------------------------------------------------- 
//
///** 人脸识别函数 */
//void detectAndDisplay(Mat& frame);
//
////-----------------------------------【全局变量声明部分】------------------------------------ 
////          描述：全局变量的声明  
////----------------------------------------------------------------------------------------------- 
//String face_cascade_name = "haarcascade_frontalface_alt.xml";//人脸识别分类器名称
//String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";//眼睛识别分类器名称（未完成）
//CascadeClassifier face_cascade;//定义人脸分类器  
//CascadeClassifier eyes_cascade;//定义眼睛分类器  
//static CvMemStorage* storage = 0;
//static CvHaarClassifierCascade* cascade = 0;
//
////-----------------------------------【main( )函数】--------------------------------------------  
////   描述：控制台应用程序的入口函数，我们的程序从这里开始执行  
////-----------------------------------------------------------------------------------------------  
//int main(int argc, unsigned char* argv[])
//{
//
//	//打开摄像头，0代表默认摄像头，1代表次摄像头
//	VideoCapture cam(1);
//	//判断摄像头是否正常打开
//	if (!cam.isOpened()){return -1;}
//
//	while (1)
//	{
//		Mat frame;//创建一个Mat用于储存视频读取一帧图像
//		//读取一帧图像
//		cam >> frame;
//		if (frame.empty()){return -1;}//判断读取一帧图像是否错误
//			
//		//人脸识别文件打开判断
//		if (!face_cascade.load(face_cascade_name)){ printf("open faces faile"); return -1; }//判断人脸识别分类器是否正常打开
//		if (!eyes_cascade.load(eyes_cascade_name)){ printf("open eyes faile"); return -1; }//判断眼睛识别分类器是否正常打开
//		storage = cvCreateMemStorage(0); 
//		detectAndDisplay(frame);//调用函数实现人脸识别
//
//		char c;
//		//键盘响应
//		c = (char)waitKey(20);
//		if (27 == c)//ESC键
//			return -1;
//	}
//	return 0;
//}
//
////-----------------------------------【detectAndDisplay( )函数】----------------------------------    
////      描述：函数实现人脸识别，输入一个Mat并显示用圆形标记的 人脸区域
////----------------------------------------------------------------------------------------------    
//void detectAndDisplay(Mat& frame)
//{
//
//	std::vector<Rect> faces;//创建一个人脸识别区的容器
//	Mat frame_gray;
//	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);//对于高维的图像空间，我们首先应该进行降维操作（不清楚）
//	equalizeHist(frame_gray, frame_gray);
//	//调用detectMultiScale()函数检测
//	face_cascade.detectMultiScale(frame_gray, faces,
//		1.1,
//		2,
//		0,
//		Size(20, 20));
//	/**detectMultiScale()函数参数说明
//	    1.image表示的是要检测的输入图像
//		2.objects表示检测到的人脸目标序列
//		3.scaleFactor表示每次图像尺寸减小的比例
//		4. minNeighbors表示每一个目标至少要被检测到3次才算是真的目标(因为周围的像素和不同的窗口大小都可以检测到人脸),
//		5.minSize为目标的最小尺寸
//		6.minSize为目标的最大尺寸
//		*/
//	for (size_t i = 0; i < faces.size(); i++)
//	{
//		Mat faceROI = frame_gray(faces[i]);//选取人脸区域为ROI区域
//		std::vector<Rect> eyes;//创建一个眼睛识别区的容器
//
//		//圈出人脸区域的形状，ellipse圆形，rectangle矩形
//		//Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);//确定人脸检测的圆心
//		//ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 0), 2, 8, 0);
//		rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
//		//参数为：承载的图像、顶点、对角点、颜色（这里是蓝色）、粗细、大小 
//
//		//输出人脸区域左上角坐标，区域宽度，长度
//		cout << "(" << faces[i].x << " , " << faces[i].y << ")" << "    ";
//		cout<< "(" << faces[i].width << " , " << faces[i].height << ")" << endl;
//		//=======变形操作=============
//		Mat out;//定义一个处理变形后的mat
//		Mat map_x, map_y;
//		int ox, oy;//图像中心
//		//选取人脸区域为ROI区域
//		faceROI = frame(Rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height));
//		//设置图片中心为原点（oy,ox）
//		oy = faceROI.cols / 2;
//		ox = faceROI.rows / 2;
//		double theta;//极坐标转换得到角度theta
//		double range;//极坐标转换得到半径range
//		double rangeMax;//规定最大半径
//		double newRange;//归一化后半径r
//		//创建和原始图一样的效果图，x重映射图，y重映射图
//		faceROI.create(faceROI.size(), faceROI.type());
//		map_x.create(faceROI.size(), CV_32FC1);
//		map_y.create(faceROI.size(), CV_32FC1);
//		//双层循环，遍历每一个像素点，改变map_x & map_y的值
//		for (int j = 0; j < faceROI.rows; j++)
//		{
//			for (int i = 0; i <faceROI.cols; i++)
//			{
//				double newX = i - ox;//经过原点变化的X坐标
//				double newY = j - oy;//经过原点变化的Y坐标
//				theta = atan2(newY, newX);//极坐标转换得到角度theta
//				range = hypot(newX, newY);//极坐标转换得到半径range
//				rangeMax = 100;//定义最大半径
//				newRange = range / rangeMax;//归一化
//				newRange = pow(newRange, 0.7);//进行图像变形算法--凸起
//				//newRange = pow(newRange, 2);//进行图像变形算法--凹陷
//				//newRange = sin(newRange*CV_PI / 2);//进行图像变形算法--拉扯
//				//newRange = tan(newRange*CV_PI / 4);
//				newRange = newRange*rangeMax;
//				//改变map_x & map_y的值. 
//				map_x.at<float>(j, i) = static_cast<float>(newRange*cos(theta) + ox);//转换为直角坐标，并把坐标中心还原
//				map_y.at<float>(j, i) = static_cast<float>(newRange*sin(theta) + oy);
//			}
//		}
//		//进行重映射操作
//		remap(faceROI, out, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//		imshow("ROI处理后", out);
//	}
//	imshow("人脸识别", frame);
//}