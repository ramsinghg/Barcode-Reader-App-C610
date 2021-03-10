#include <stdio.h> 
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "barcode_decoder.h"


//variables to store dimension of resized image in fastcv
int width2 = 400;
int height2 = 400;
unsigned int *pPointBuffer;
int w1 , h1;                        //Size for ROI of barcode

//Function used to get each number from each binary representation of width
int call_array(char array[10][7], char Binary_array[6][7], int pos)
{

	int i, j, count, index = 0, count_check[10], check_bit = 0;
	for(i = 0; i<10;i++)
	{
		count = 0;
		for(j=0;j<7;j++)
		{      
			if(array[i][j] == Binary_array[pos][j])
			{
				count++;
			}
		}
		count_check[i] = count;
		if(count == 7)
		{
			index = i;
		}   
	}
	for(i=0;i<10;i++)
	{
		if(count_check[i] == 7)
		{
			check_bit = 1;
		}
	}
	if(check_bit == 1)
	{
		index = index;
	}
	else
	{
		index = -1;
	}
	return index;  
}



//Function which gives decoding result for every first digit
int *get(int number, char L[10][7], char G[10][7], char R[10][7], char First_binary[6][7], char Second_binary[6][7], int *decode_result1)
{
	switch(number)
	{
		case 0:  
			decode_result1[0] = call_array(L, First_binary,0);
			decode_result1[1] = call_array(L, First_binary,1);
			decode_result1[2] = call_array(L, First_binary,2);
			decode_result1[3] = call_array(L, First_binary,3);
			decode_result1[4] = call_array(L, First_binary,4);
			decode_result1[5] = call_array(L, First_binary,5);
			decode_result1[6] = call_array(R, Second_binary,0);
			decode_result1[7] = call_array(R, Second_binary,1);
			decode_result1[8] = call_array(R, Second_binary,2);
			decode_result1[9] = call_array(R, Second_binary,3);
			decode_result1[10] = call_array(R, Second_binary,4);
			decode_result1[11] = call_array(R, Second_binary,5);         
			break;
		case 1: decode_result1[0] = call_array(L, First_binary,0);
			decode_result1[1] = call_array(L, First_binary,1);
			decode_result1[2] = call_array(G, First_binary,2);
			decode_result1[3] = call_array(L, First_binary,3);
			decode_result1[4] = call_array(G, First_binary,4);
			decode_result1[5] = call_array(G, First_binary,5);
			decode_result1[6] = call_array(R, Second_binary,0);
			decode_result1[7] = call_array(R, Second_binary,1);
			decode_result1[8] = call_array(R, Second_binary,2);
			decode_result1[9] = call_array(R, Second_binary,3);
			decode_result1[10] = call_array(R, Second_binary,4);
			decode_result1[11] = call_array(R, Second_binary,5);
			break;
		case 2: decode_result1[0] = call_array(L, First_binary,0);
			decode_result1[1] = call_array(L, First_binary,1);
			decode_result1[2] = call_array(G, First_binary,2);
			decode_result1[3] = call_array(G, First_binary,3);
			decode_result1[4] = call_array(L, First_binary,4);
			decode_result1[5] = call_array(G, First_binary,5);
			decode_result1[6] = call_array(R, Second_binary,0);
			decode_result1[7] = call_array(R, Second_binary,1);
			decode_result1[8] = call_array(R, Second_binary,2);
			decode_result1[9] = call_array(R, Second_binary,3);
			decode_result1[10] = call_array(R, Second_binary,4);
			decode_result1[11] = call_array(R, Second_binary,5);
			break; 
		case 3: decode_result1[0] = call_array(L, First_binary,0);
			decode_result1[1] = call_array(L, First_binary,1);
			decode_result1[2] = call_array(G, First_binary,2);
			decode_result1[3] = call_array(G, First_binary,3);
			decode_result1[4] = call_array(G, First_binary,4);
			decode_result1[5] = call_array(L, First_binary,5);
			decode_result1[6] = call_array(R, Second_binary,0);
			decode_result1[7] = call_array(R, Second_binary,1);
			decode_result1[8] = call_array(R, Second_binary,2);
			decode_result1[9] = call_array(R, Second_binary,3);
			decode_result1[10] = call_array(R, Second_binary,4);
			decode_result1[11] = call_array(R, Second_binary,5);
			break; 
		case 4: decode_result1[0] = call_array(L, First_binary,0);
			decode_result1[1] = call_array(G, First_binary,1);
			decode_result1[2] = call_array(L, First_binary,2);
			decode_result1[3] = call_array(L, First_binary,3);
			decode_result1[4] = call_array(G, First_binary,4);
			decode_result1[5] = call_array(G, First_binary,5);
			decode_result1[6] = call_array(R, Second_binary,0);
			decode_result1[7] = call_array(R, Second_binary,1);
			decode_result1[8] = call_array(R, Second_binary,2);
			decode_result1[9] = call_array(R, Second_binary,3);
			decode_result1[10] = call_array(R, Second_binary,4);
			decode_result1[11] = call_array(R, Second_binary,5);
			break; 
		case 5: decode_result1[0] = call_array(L, First_binary,0);
			decode_result1[1] = call_array(G, First_binary,1);
			decode_result1[2] = call_array(G, First_binary,2);
			decode_result1[3] = call_array(L, First_binary,3);
			decode_result1[4] = call_array(L, First_binary,4);
			decode_result1[5] = call_array(G, First_binary,5);
			decode_result1[6] = call_array(R, Second_binary,0);
			decode_result1[7] = call_array(R, Second_binary,1);
			decode_result1[8] = call_array(R, Second_binary,2);
			decode_result1[9] = call_array(R, Second_binary,3);
			decode_result1[10] = call_array(R, Second_binary,4);
			decode_result1[11] = call_array(R, Second_binary,5);
			break; 
		case 6: decode_result1[0] = call_array(L, First_binary,0);
			decode_result1[1] = call_array(G, First_binary,1);
			decode_result1[2] = call_array(G, First_binary,2);
			decode_result1[3] = call_array(G, First_binary,3);
			decode_result1[4] = call_array(L, First_binary,4);
			decode_result1[5] = call_array(L, First_binary,5);
			decode_result1[6] = call_array(R, Second_binary,0);
			decode_result1[7] = call_array(R, Second_binary,1);
			decode_result1[8] = call_array(R, Second_binary,2);
			decode_result1[9] = call_array(R, Second_binary,3);
			decode_result1[10] = call_array(R, Second_binary,4);
			decode_result1[11] = call_array(R, Second_binary,5);
			break;
		case 7: decode_result1[0] = call_array(L, First_binary,0);
			decode_result1[1] = call_array(G, First_binary,1);
			decode_result1[2] = call_array(L, First_binary,2);
			decode_result1[3] = call_array(G, First_binary,3);
			decode_result1[4] = call_array(L, First_binary,4);
			decode_result1[5] = call_array(G, First_binary,5);
			decode_result1[6] = call_array(R, Second_binary,0);
			decode_result1[7] = call_array(R, Second_binary,1);
			decode_result1[8] = call_array(R, Second_binary,2);
			decode_result1[9] = call_array(R, Second_binary,3);
			decode_result1[10] = call_array(R, Second_binary,4);
			decode_result1[11] = call_array(R, Second_binary,5);
			break;       
		case 8:  
			decode_result1[0] = call_array(L, First_binary,0);
			decode_result1[1] = call_array(G, First_binary,1);
			decode_result1[2] = call_array(L, First_binary,2);
			decode_result1[3] = call_array(G, First_binary,3);
			decode_result1[4] = call_array(G, First_binary,4);
			decode_result1[5] = call_array(L, First_binary,5);
			decode_result1[6] = call_array(R, Second_binary,0);
			decode_result1[7] = call_array(R, Second_binary,1);
			decode_result1[8] = call_array(R, Second_binary,2);
			decode_result1[9] = call_array(R, Second_binary,3);
			decode_result1[10] = call_array(R, Second_binary,4);
			decode_result1[11] = call_array(R, Second_binary,5);
			break;
		case 9: decode_result1[0] = call_array(L, First_binary,0);
			decode_result1[1] = call_array(G, First_binary,1);
			decode_result1[2] = call_array(G, First_binary,2);
			decode_result1[3] = call_array(L, First_binary,3);
			decode_result1[4] = call_array(G, First_binary,4);
			decode_result1[5] = call_array(L, First_binary,5);
			decode_result1[6] = call_array(R, Second_binary,0);
			decode_result1[7] = call_array(R, Second_binary,1);
			decode_result1[8] = call_array(R, Second_binary,2);
			decode_result1[9] = call_array(R, Second_binary,3);
			decode_result1[10] = call_array(R, Second_binary,4);
			decode_result1[11] = call_array(R, Second_binary,5);
			break;  
	}
	return decode_result1;
}



//Function containing decode value of given barcode image
void barcode_decoding(uint8_t *dst_gray, int *index1,int *check_bit, int decode_result[10][13])
{ 
	int count = 0;
	int counter = 0; 
    int i,j,k;
    int mid_row[345];                                       	// to store middle row entries
    int occur_list[345];                                   		// to store occurrence of entries
    int occurlist_newsize;                                      // size of occur_list
    int decode_list[48];                                        // to store proper occur_list leaving few entries
    float number = 0.0;                   						// to store result before rounding
    int max;                              						// to store max value in the decode_list
    int round_list[48];                   						// to store rescaled values
	int first_group[24], second_group[24];                      // to store first_group and second_group values
	int first_four[6][4], second_four[6][4];                    // to store values in the form of group of 4 
	char first_binary[6][7], second_binary[6][7];               // to store binary representation of each group of 4
	int decode_result1[12], *decode_result_temp;                // to store decoding results 
    int sum_even , sum_odd , check_sum;                         // To store checksum values
	
    //Applying thresholding on input image having threshold value = 150
	for(j=0;j<w1; j++)
	{
		for(k=0;k<1;k++)
		{
			if(dst_gray[((h1/2)*w1*1)+(j*1)+k] >= 150)
			{
				dst_gray[((h1/2)*w1*1)+(j*1)+k] = 255;
				mid_row[counter] = dst_gray[((h1/2)*w1*1)+(j*1)+k];
				counter++;
			}
			else
			{
				dst_gray[((h1/2)*w1*1)+(j*1)+k] = 0;
				mid_row[counter] = dst_gray[((h1/2)*w1*1)+(j*1)+k];
				counter++;
			}
			count++;
		}
	}
	counter = 0;
	*index1 = 0;
	//This loop calculates number of continuous 0's and 255's in the extracted image row.
	for(i = 0; i<w1; i++)
	{
		counter = 1;
		if(*index1 >= w1)
		{
			break;
		}
		for(j=1;j<w1; j++)
		{
			if((j+(*index1)) >= w1)
			{
				break;
			}
			if(mid_row[*index1] == mid_row[j+*index1])
			{
				counter++;
			}
			if(mid_row[*index1] != mid_row[j+*index1])
			{
				break;
			}
		}
		occur_list[i] = counter;
		count = counter;
		*index1 = *index1 + count; 
	}
	occurlist_newsize = 59;
	j=0;
	//Below removes beginning and middle width of barcode since they wont contribute for decoding.
	for(i=3; i<occurlist_newsize-3; i++)
	{

		if((i != 24+3) && (i != 25+3) && (i != 26+3) && (i != 27+3) && (i !=28+3))
		{
			decode_list[j] = occur_list[i]; 
			j++;
		}
	}


	//Getting max bar value 
	max = decode_list[0];
	for(i=1;i<48;i++)
	{
		if(decode_list[i] > max)
		{
			max = decode_list[i];
		}
	}
	//Rescaling barcode width in the range 1 to 4
	for(i =0; i< 48; i++)
	{
		if(decode_list[0] == max)
		{
			number = (decode_list[i] * 3.0/max);
			round_list[i] = round(number);
		}
		else
		{
			number = (decode_list[i] * 4.0/max);
			round_list[i] = round(number);
		}
	}
	j = 0;
	//Making two groups from the width of 48, 24 widths eachpNumContourPoints
	for(i=0;i<48;i++)
	{
		if(i<24)
		{

			first_group[i] = round_list[i];
		}
		else
		{
			second_group[j] = round_list[i];
			j++;
		}
	}
	//In each group, making group of 4 widths
	for(i=0;i<24;i=i+4)
	{
		for(j=0;j<4;j++)
		{
			first_four[i/4][j] = first_group[i+j];
			second_four[i/4][j] = second_group[i+j]; 
		}
	}
	//Representing widths in binary form, for First group of 4 it encodes 0's to 1st and 3rd width and 1's to 2nd and 4th group. 
	for(i=0;i<6;i++)
	{
		*index1 =0;
		for(j=0;j<4;j++)
		{
			if(j==0 || j==2)
			{
				for(k=0;k<first_four[i][j]; k++)
				{
					first_binary[i][*index1] = '0';
					(*index1)++;
				}
			}
			if(j==1 || j==3)
			{
				for(k=0;k<first_four[i][j]; k++)
				{
					first_binary[i][*index1] = '1';
					(*index1)++;
				}
			}
		}
	}

	//Representing widths in binary form, for second group of 4 it encodes 1's to 1st and 3rd width and 0's to 2nd and 4th group.
	for(i=0;i<6;i++)
	{
		*index1 =0;
		for(j=0;j<4;j++)
		{
			if(j==0 || j==2)
			{
				for(k=0;k<second_four[i][j]; k++)
				{
					second_binary[i][*index1] = '1';
					(*index1)++;
				}
			}
			if(j==1 || j==3)
			{
				for(k=0;k<second_four[i][j]; k++)
				{
					second_binary[i][*index1] = '0';
					(*index1)++;
				}
			}
		}
	}

	char L[10][7]  =    {'0','0','0','1','1','0','1',
		'0','0','1','1','0','0','1',
		'0','0','1','0','0','1','1',
		'0','1','1','1','1','0','1',
		'0','1','0','0','0','1','1',
		'0','1','1','0','0','0','1',
		'0','1','0','1','1','1','1',
		'0','1','1','1','0','1','1',
		'0','1','1','0','1','1','1',
		'0','0','0','1','0','1','1'};

	char G[10][7]  =    {'0','1','0','0','1','1','1',
		'0','1','1','0','0','1','1',
		'0','0','1','1','0','1','1',
		'0','1','0','0','0','0','1',
		'0','0','1','1','1','0','1',
		'0','1','1','1','0','0','1',
		'0','0','0','0','1','0','1',
		'0','0','1','0','0','0','1',
		'0','0','0','1','0','0','1',
		'0','0','1','0','1','1','1'};

	char R[10][7]  =    {'1','1','1','0','0','1','0',
		'1','1','0','0','1','1','0',
		'1','1','0','1','1','0','0',
		'1','0','0','0','0','1','0',
		'1','0','1','1','1','0','0',
		'1','0','0','1','1','1','0',
		'1','0','1','0','0','0','0',
		'1','0','0','0','1','0','0',
		'1','0','0','1','0','0','0',
		'1','1','1','0','1','0','0'};

	*index1 = 0;
	for(i=0;i<10;i++)
	{
		count = 0;
		decode_result_temp = get(i,L,G,R,first_binary,second_binary,decode_result1);

		for(j=0;j<12;j++)
		{
			if(decode_result_temp[j] != -1)
			{
				count++;
			}
			decode_result[i][j+1] = decode_result_temp[j];       
		}
		sum_even = (decode_result[i][1] + decode_result[i][3] + decode_result[i][5] + decode_result[i][7] + decode_result[i][9] + decode_result[i][11]) * 3;
		sum_odd = i + decode_result[i][2] + decode_result[i][4] + decode_result[i][6] + decode_result[i][8] + decode_result[i][10];
		check_sum = ceil((sum_even + sum_odd)/10.0) * 10 - (sum_even + sum_odd);
		if(count == 12 && decode_result[i][12] == check_sum)
		{

			*index1 = i;
			*check_bit = 1;

		}
	}
}

int min(int *arr,int len)
{
   int index = 0;
   for (int i =1 ;i< len;i++){
      if(arr[i]<arr[index])
         index = i;  
   }
   return index;  
}


int max(int *arr, int len)
{
   int index = 0;
   for (int i =1 ;i< len;i++){
      if(arr[i]>arr[index])
         index = i;  
   }
   return index;  
}

//Function which returns ROI of barcode
uint8_t* barcode_detection(unsigned char* img, int w, int h)
{
    unsigned int maxNumContours = 1000;
	unsigned int pNumContours = 0;                                            // Actual Found Contour
	unsigned int pNumContourPoints[1000] = {0};                               // Total Number of Points in Each Contour
	unsigned int *pContourStartPointsfind[1000];                              // Pointer to Start of All Contour
	int32_t hierarchy[1000][4];
	unsigned int maxContour = pNumContourPoints[0];                           // To store max counter value
	int maxIndex = 0;                                                         // to store index of max contour
	int mid_value;                                                            // To get the contour boundary

	fcvMemInit();
	uint8_t *dst = (uint8_t *)fcvMemAlloc((w*h), 16);
	uint8_t *dst2 = (uint8_t *)fcvMemAlloc((width2*height2), 16);
	uint8_t *dst3 = (uint8_t *)fcvMemAlloc((width2*height2), 16);
	uint8_t *dst4 = (uint8_t *)fcvMemAlloc((width2*height2), 16);

	fcvColorRGB888ToGrayu8((const uint8_t*)img, w, h, 0, dst, 0);	
	fcvScaleDownNNu8((const uint8_t *)dst, w, h, 0, dst2, width2, height2, 0);


	fcvFilterErodeNxNu8((const uint8_t*)dst2, width2, height2, 0, 7,(uint8_t*)dst4, 0);
	fcvFilterDilateNxNu8((const uint8_t*)dst4, width2, height2, 0, 7,(uint8_t*)dst3, 0);


	unsigned int sizeOfPointBuffer = (400 * 2 * 400 * sizeof(unsigned int));
	pPointBuffer=(unsigned int *)malloc(sizeOfPointBuffer);

	memset(pPointBuffer,0,sizeOfPointBuffer);
	
	
fcvFindContoursExternalu8((uint8_t*)dst4,width2,height2,width2,maxNumContours,&pNumContours,pNumContourPoints,pContourStartPointsfind,pPointBuffer,sizeOfPointBuffer,hierarchy,fcvFindContoursAllocate(width2));

    
	//unsigned int maxContour = pNumContourPoints[0];
	//int maxIndex = 0;
	for(int j = 1; j < pNumContours; j++){
		if(pNumContourPoints[j] > maxContour){
			maxContour = pNumContourPoints[j];
			maxIndex = j;
		}
	}

	mid_value = pNumContourPoints[maxIndex]/2;
 


    int x[4], y[4];           //points to select ROI points from the contour 

	x[0] = pPointBuffer[0];
	y[0] = pPointBuffer[1];
	x[1] = pPointBuffer[mid_value - 1];
	y[1] = pPointBuffer[mid_value];
	x[2] = pPointBuffer[mid_value];
	y[2] = pPointBuffer[mid_value + 1];
	x[3] = pPointBuffer[pNumContourPoints[maxIndex]];
	y[3] = pPointBuffer[pNumContourPoints[maxIndex] - 1];


	int x_max = x[3];
	int y_max = y[3];
	int x_min = x[0] - 1;
	int y_min = y[0] - 1;
	int region_width = x_max - x_min;
	int region_height = y_max - y_min;
	x_min = floor(x_min + region_height*0.09);
	x_max = ceil(x_max - region_height*0.05);

	y_min = y_min + region_width * 0.0;
  	y_max = ceil(y_max - region_width*0.1);

	w1 = x_max - x_min;
 	h1 = y_max - y_min ;

   uint8_t *dst_gray = (uint8_t *)fcvMemAlloc((w1*h1), 16);
   int index1 = 0;
	for(int i=0;i<y_max;i++)
    {
     for(int j=x_min;j<x_max; j++)
      {
         for(int k=0;k<1;k++)
           {
               dst_gray[index1] = dst2[(i*width2*1)+(j*1)+k];
        	index1++;
           }
      }
    	 
    }

	fcvMemFree(dst);
	fcvMemFree(dst2);
	fcvMemFree(dst3);
	fcvMemFree(dst4);
	return dst_gray;
}    



int barcode(uint8_t *img, int w, int h,int *check, int decode_result[10][13])
{
	uint8_t *dst_gray = (uint8_t *)fcvMemAlloc((w1*h1), 16);
	dst_gray = barcode_detection(img, w, h);                        //dst_gray stores recognized barcode region	
	int check_bit = 0, index1;
	barcode_decoding(dst_gray, &index1, &check_bit, decode_result);                //Getting barcode decode values
    *check = check_bit;
    fcvMemFree(dst_gray);
	free(pPointBuffer);
    return index1;
}

