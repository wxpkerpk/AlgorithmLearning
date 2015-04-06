#include<stdio.h>
# include <stdio.h>
void sort3p(int* x, int len)
{
	int p = 0;
	int left = 0;
	int right = len-1;

	while(p<=right){
		if(x[p]<0){
			int t = x[left];
			x[left] = x[p];
			x[p] = t;
			left++;
			p++;
		}
		else if(x[p]>0){
			int t = x[right];
			x[right] = x[p];
			x[p] = t;
			right--;
		}
		else{
			x[p++]=0;  //ÃÓø’Œª÷√
		}
	}

}

int main(void)
{
	char * haystack = "abcd1234";
	char * needle = "abc";
	printf("%s\n", prefix(haystack, needle));
}
