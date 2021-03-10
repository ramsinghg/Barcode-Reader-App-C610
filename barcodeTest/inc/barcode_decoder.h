#ifndef DecoderHeader
#define DecoderHeader
#include "fastcv.h"

//Function to get digit for each binary representation of group of 4 bars.
int call_array(char array[10][7], char Binary_array[6][7], int pos);
//Function to return barcode number
int *get(int number, char L[10][7], char G[10][7], char R[10][7], char First_binary[6][7], char Second_binary[6][7], int *decode_result1);
//Function gives barcode decode values
void barcode_decoding(uint8_t *dst_gray, int *index1,int *check_bit, int decode_result[10][13]);
//Function gives ROI of barcode image
uint8_t* barcode_detection(unsigned char* img, int w2, int h2);
int barcode(uint8_t *img, int w, int h, int *check, int decode_result[10][13]);

#endif

