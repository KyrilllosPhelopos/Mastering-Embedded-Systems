/*
 ============================================================================
 Name        : Ex2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
//c function to take an integer number and calculate it's square root?



float sqrt(int number)
{
	int start = 0, end = number;
	int mid;
	float ans;
	while (start <= end) {
		mid = (start + end) / 2;
		if (mid * mid == number) {
			ans = mid;
			break;
		}
		if (mid * mid < number) {
			ans=start;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	float increment = 0.1;
	for (int i = 0; i < 5; i++) {
		while (ans * ans <= number) {
			ans += increment;
		}
		ans = ans - increment;
		increment = increment / 10;
	}
	return ans;
}

// Driver Code
int main()
{

	// Given number
	//int N = 12;

	// Function call
	printf("%0.3f ", sqrt(12));
	return 0;
}
