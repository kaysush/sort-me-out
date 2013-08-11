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
* This is the naive implementation of Bubble Sort
* It doesn't takes into account that after N(th) iteration
* last N-1 elements are sorted.
* It uses the optimizatin that if array is already sorted
* then it breaks out of the loop
*/

void bubble_sort(int * array,int length) {
	int i,j,temp,swapped = 0;
	comparison_count = swap_count = 0;
	for ( i = 0 ; i < length ; i++) {
		swapped = 0;
		for ( j = 0 ; j < length - 1; j++) {
		comparison_count++;
			if ( array[j] > array[j+1]) {
				swapped = 1;
				swap_count++;
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
		if(!swapped) break;
	}
}


/*
* This is an optimized version of Bubble Sort
* which optimizes the inner loop taking into account
* that last N-1 elements are sorted after N(th) iteration.
* It uses the optimizatin that if array is already sorted
* then it breaks out of the loop
*/

void bubble_sort_optimization1(int * array, int length) {
	int i,j,temp,swapped = 0;
	comparison_count = swap_count = 0;
	for ( i = 0 ; i < length ; i++) {
		for ( j =0 ; j < length -i -1 ; j++) {
			swapped = 0;
			comparison_count++;
			if ( array[j] > array[j+1]) {
				swapped = 1;
				swap_count++;
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			    }

		}
		if(!swapped) break;
	}
}

/*
* Another optimization considering that after the last index swapped
* the array after it is sorted.
* It uses the optimizatin that if array is already sorted
* then it breaks out of the loop
* ( Currently Not working )
*/

void bubble_sort_optimization2(int * array,int length) {
	int i,j,temp,swapped = 0,newn=0,n;
	comparison_count = swap_count = 0;
	n = length;
	for ( i = 0 ; i < length ; i++) {
		newn = 0;
		for ( j =0 ; j < n ; j++) {
			swapped = 0;
			comparison_count++;
			if ( array[j] > array[j+1]) {
				swapped = 1;
				swap_count++;
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				newn = j;
			}

		}
		n = newn;
		if(!swapped) break;
	}
}



int main() {
	printf("Hello Bubble Sort\n");
	print(a,5);
	//bubble_sort(a,5);
	bubble_sort_optimization1(a,5);
	print(a,5);
	printf("No. of Comparison : %d \n",comparison_count);
	printf("No. of swaps : %d \n",swap_count);
}