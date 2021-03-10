#include <stdio.h> 
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include "barcode_decoder.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#include "opencv2/opencv.hpp"
using namespace cv;

int main(int argc, char *argv[])
{
    int w, h, c, index_value, check;    
    int decode_result[10][13];
    unsigned char *img;
    Mat frame;
    if(!(memcmp(argv[1], "camera",6)))
 {
    cv::VideoCapture cap("qtiqmmfsrc ldc=TRUE !video/x-raw, format=NV12, width=1280, height=720, framerate=30/1 ! videoconvert ! appsink");

       if(!cap.isOpened() )
       {
            printf("VideoCapture is not opened");
	        exit(-1);
       }else{
          printf("working");
       }

       int i =10;   // In order to get proper camera frame we are skipping 9 frames. 

	   while(i--)
		{
			 w = 720;
             h = 640;
             c = 3;

			cap >> frame;

			if(i ==1){
				img = frame.data;
			 }
		}

        cap.release();
    }
    else{   
	    img= stbi_load(argv[1], &w, &h, &c, 0);
	    printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", w, h, c);
    }

    index_value = barcode(img, w, h, &check, decode_result);
	
    decode_result[index_value][0] = index_value;
	printf("Barcode value = ");
	if(check == 1)
	{
		for(int j=0;j<13;j++)
		{
			printf("%d", decode_result[index_value][j]);
		}
	}
	printf("\n");

	return 0;
}

    



    

