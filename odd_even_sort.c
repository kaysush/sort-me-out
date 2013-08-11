/*
 ___   _  _______  __   __  _______  __   __  _______  __   __ 
|   | | ||   _   ||  | |  ||       ||  | |  ||       ||  | |  |
|   |_| ||  |_|  ||  |_|  ||  _____||  | |  ||  _____||  |_|  |
|      _||       ||       || |_____ |  |_|  || |_____ |       |
|     |_ |       ||_     _||_____  ||       ||_____  ||       |
|    _  ||   _   |  |   |   _____| ||       | _____| ||   _   |
|___| |_||__| |__|  |___|  |_______||_______||_______||__| |__|

Copyright (c) by Sushil Kumar <im@sushilkumar.uni.me>

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
*/


#include<stdio.h>

int a[] = {4,5,2,3,1};
// No. of swaps that occured.
int swap_count=0;
// No. of comparisons that occured.
int comparison_count=0;

/*
* Takes the array and its length and print it pretty.
*/
void print(int * array,int length) {
	int i;
	printf("Array is : ");
	for ( i = 0 ; i < length ; i++) {
		printf("%d ",array[i]);
	}
	printf("\n");
}

void odd_even_sort(int * array, int length) {
	int i,j,temp,sorted = 0;
	comparison_count = swap_count = 0;
	while(!sorted) {
		sorted = 1;
		for( i= 1 ; i < length-1 ; i += 2) {
			comparison_count++;
			if(array[i] > array[i+1]){
				swap_count++;
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				sorted = 0;
			}

		}

		for( j = 0 ; j < length-1 ; j += 2) {
			comparison_count++;
			if(array[j] > array[j+1]){
				swap_count++;
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				sorted = 0;
			}

		}
	}
}
int main(){
	printf("Hello Odd-Even Sort\n");
	print(a,5);
	odd_even_sort(a,5);
	print(a,5);
	printf("No. of comparisons : %d \n",comparison_count);
	printf("No. of swaps : %d \n",swap_count);
	return 0;
}


