#include "cv.h"
#include "highgui.h"
#include "stdio.h"
//分离出不同通道的图像
//红色通道
IplImage* get_red(IplImage *img)
{
IplImage* rimg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
IplImage* bimg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
IplImage* gimg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
if(img==NULL)
      return 0;
 else
    {
        cvSplit(img,rimg,gimg,bimg,NULL);
         }
  return rimg;
}
//绿色通道
IplImage* get_green(IplImage *img)
{
IplImage* rimg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
IplImage* bimg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
IplImage* gimg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
if(img==NULL)
      return 0;
 else
    {
        cvSplit(img,rimg,gimg,bimg,NULL);
         }
  return gimg;
}
//蓝色通道
IplImage* get_blue(IplImage *img)
{
 IplImage* rimg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
  IplImage* bimg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
   IplImage* gimg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
    if(img==NULL)
        return 0;
     else
         cvSplit(img,rimg,gimg,bimg,NULL);
      return bimg;
}
//验证是否为雪碧，是返回ture,否则返回false
int Is_sprit(IplImage* img)
{
  int w = 0;
  int h = 0;
  int num = 0;
  for(;w<img->width;w++)
  {
    for(;h<img->height;h++)
    {
        if(((uchar*)(img->imageData+img->widthStep*h))[w*img->nChannels+0]<50&&((uchar*)(img->imageData+img->widthStep*h))[w*img->nChannels+1]>40&&((uchar*)(img->imageData+img->widthStep*h))[w*img->nChannels+2]<50)
          num++;
    }
    }
  printf("%d\n",num);
  if(num > 10)
    return 1;
  else
    return 0;
  }


//
int Is_jdb(IplImage* img)
{
  int w = 0;
  int h = 0;
  int num = 0;
  for(;w<img->width;w++)
  {
    for(;h<img->height;h++)
    {
        if(((uchar*)(img->imageData+img->widthStep*h))[w*img->nChannels+0]<20&&((uchar*)(img->imageData+img->widthStep*h))[w*img->nChannels+1]<20&&((uchar*)(img->imageData+img->widthStep*h))[w*img->nChannels+2]<70)
          num++;
    }
    }
  printf("%d\n",num);
  if(num > 10)
    return 1;
  else
    return 0;
  }

//
int Is_coke(IplImage* img)
{
  int w = 0;
  int h = 0;
  int num = 0;
  for(;w<img->width;w++)
  {
    for(;h<img->height;h++)
    {
        if(((uchar*)(img->imageData+img->widthStep*h))[w*img->nChannels+0]>80&&((uchar*)(img->imageData+img->widthStep*h))[w*img->nChannels+1]>80&&((uchar*)(img->imageData+img->widthStep*h))[w*img->nChannels+2]>100)
          num++;
    }
    }
  printf("%d\n",num);
  if(num > 10)
    return 1;
  else
    return 0;
  }

//nclude "fuc.h"
int main(int argc,char* argv[])
{

//测试代码
  IplImage* img = cvLoadImage(argv[1]);

  if(Is_sprit(img) ==1)
  printf("是雪碧\n",Is_sprit(img));
  if(Is_jdb(img) == 1)
  printf("%d 是家多宝\n",Is_jdb(img));
  if(Is_coke(img) == 1)
  printf("%d  是可乐\n",Is_coke(img));
  cvWaitKey();
}

