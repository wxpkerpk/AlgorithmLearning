#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string.h>
#include<iterator>
using namespace std;
const int Num = 30001;
int n, dp[Num], a[Num];
int bisearch(int val, int last){
	int l, r, mid;
	l = 1;
	r = last;
	while (l < r){
		mid = (1 + r) >> 1;
		if (val >= dp[mid]){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return l;
}
int LDS(){
	int i, ans, pos;
	dp[1] = a[1];
	ans = 1;
	for (i = 2; i <= n; i++){
		if (a[i] >= dp[ans])
			dp[++ans] = a[i];
		else{
			pos = bisearch(a[i], ans);
			dp[pos] = a[i];
		}
	}
	return ans;
}
int main(){
	int i;
	while(cin>>n){
		for (i = 1; i <= n; i++){
			cin>>a[i];
		}

		cout<<LDS()<<endl;
	}
	return 0;
}
