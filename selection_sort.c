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

void selection_sort(int *array, int length) {
	int i,j,min,minindex,temp;
	comparison_count = swap_count = 0;
	for ( i = 0 ; i < length ; i++){
		min = array[i];
		minindex = i;
		for (j = i+1 ; j < length ; j++) {
			comparison_count++;
			if(array[j] < min){
				min = array[j];
				minindex = j;
			}
		}
		if(minindex != i) { // a sanitation check (won't break the program if not used)
			swap_count++;
			temp = array[i];
			array[i] = array[minindex];
			array[minindex]=temp;
		}
	}
}

int main(){
	printf("Hello Selectin Sort\n");
	print(a,5);
	selection_sort(a,5);
	print(a,5);
	printf("No. of comparisons : %d \n",comparison_count);
	printf("No. of swaps : %d \n",swap_count);
	return 0;
}