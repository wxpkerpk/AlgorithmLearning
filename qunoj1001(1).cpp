#include<iostream>
using namespace std;
union u
{
	long long i;
	char c1[8];
};
unsigned int table[256] = {0};
void init()
{
	int sum = 0;
	for (int i = 1; i < (256); i++){
		sum = 0;
		while (i){
			sum +=(i & 1);
			i >> 1;
		}
		table[i] = sum;
	}
}
long long GetAns(long long min, long long max)
{
	int key = max;
	unsigned int temp = 0;
	min = (max / 2) < min ?   min:(max/2);
	u myu;
	int mymax = -1;
	long long cmax = -1;
	while (key >= min){
		temp = 0;
		myu.i = key;
		for (int j = 0; j < 8; j++){
			temp += table[myu.c1[j]];
		}
		if (temp>=mymax){
			mymax = temp;
			cmax = key;
		}
	}
	return cmax;
}
