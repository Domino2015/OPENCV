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
///****                            如果采用这个onMouse()函数的话，则可以画出鼠标拖动矩形框的4种情形                        ****/
///************************************************************************************************************************/
//void onMouse(int event, int x, int y, int, void*)
//{
//	//Point origin;//不能在这个地方进行定义，因为这是基于消息响应的函数，执行完后origin就释放了，所以达不到效果。
//	if (select_flag)
//	{
//		select.x = MIN(origin.x, x);//不一定要等鼠标弹起才计算矩形框，而应该在鼠标按下开始到弹起这段时间实时计算所选矩形框
//		select.y = MIN(origin.y, y);
//		select.width = abs(x - origin.x);//算矩形宽度和高度
//		select.height = abs(y - origin.y);
//		select &= Rect(0, 0, frame.cols, frame.rows);//保证所选矩形框在视频显示区域之内
//	}
//	if (event == CV_EVENT_LBUTTONDOWN)
//	{
//		select_flag = true;//鼠标按下的标志赋真值
//		origin = Point(x, y);//保存下来单击是捕捉到的点
//		select = Rect(x, y, 0, 0);//这里一定要初始化，宽和高为(0,0)是因为在opencv中Rect矩形框类内的点是包含左上角那个点的，但是不含右下角那个点
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
//	//打开摄像头
//	VideoCapture cam(0);
//	if (!cam.isOpened())
//		return -1;
//
//	//建立窗口
//	namedWindow("camera", 1);//显示视频原图像的窗口
//
//	//捕捉鼠标
//	setMouseCallback("camera", onMouse, 0);
//
//	while (1)
//	{
//		//读取一帧图像
//		cam >> frame;
//		if (frame.empty())
//			return -1;
//
//		//画出矩形框
//		rectangle(frame, select, Scalar(255, 0, 0), 3, 8, 0);//能够实时显示在画矩形窗口时的痕迹
//		//得到鼠标左上角的位置，矩形宽度，高度
//		cout << "X坐标  : " << select.x << "   Y坐标  :  " << select.y << endl;
//		cout << "ROI宽度  : " << select.width << "  ROI高度  : " << select.height << endl;
//		if (select.width != 0)
//		{
//			Mat imageROI;
//			Mat out;
//			Mat map_x, map_y;
//			int ox, oy;//图像中心
//			imageROI = frame(Rect(select.x, select.y, select.width, select.height));
//			//设置图片中心为原点
//			oy = imageROI.cols / 2;
//			ox = imageROI.rows / 2;
//			double theta;
//			double range;
//			double rangeMax;
//			double newRange;//归一化后r
//			//创建和原始图一样的效果图，x重映射图，y重映射图
//			imageROI.create(imageROI.size(), imageROI.type());
//			map_x.create(imageROI.size(), CV_32FC1);
//			map_y.create(imageROI.size(), CV_32FC1);
//			//双层循环，遍历每一个像素点，改变map_x & map_y的值
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
//					//改变map_x & map_y的值. 
//					map_x.at<float>(j, i) = static_cast<float>(newRange*cos(theta) + ox);
//					map_y.at<float>(j, i) = static_cast<float>(newRange*sin(theta) + oy);
//				}
//			}
//			//进行重映射操作
//			remap(imageROI, out, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//			
//			imshow("ROI", imageROI);
//			imshow("ROI处理后", out);
//
//			cout << "------------我有面积-------------" << endl;
//		}
//		//显示视频图片到窗口
//		imshow("camera", frame);
//
//		//键盘响应
//		c = (char)waitKey(20);
//		if (27 == c)//ESC键
//			return -1;
//	}
//
//	return 0;
//}
