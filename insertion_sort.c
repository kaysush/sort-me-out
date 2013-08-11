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

/*
* This is the naive implemetation of Insertion Sort as given in the 
* pseudo code given on Wikipedia http://en.wikipedia.org/wiki/Insertion_sort
*/
void insertion_sort(int * array, int length){
	int i,j;
	comparison_count = swap_count = 0;
	for( i = 2 ; i < length ; i++){
		int temp = array[i];
		j = i-1;
		
		/*
		* Loop untill you dont't find the right position i.e.  
		* a number smaller than the current one.
		*/
		
		while( j >=0 && array[j] > temp ){ 
			swap_count++;
			comparison_count++;
			array[j+1] = array[j];
			j--;
		}

		comparison_count++; // because last comparison failed.

		array[j+1] = temp; // Insert the current number in its right position.
		
	}
}

int main() {
	printf("Hello Insertion Sort\n");
	print(a,5);
	insertion_sort(a,5);
	print(a,5);
	printf("No. of Comparison : %d \n",comparison_count);
	printf("No. of swaps : %d \n",swap_count);
}