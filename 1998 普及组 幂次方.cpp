#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
void d(int x){
	for(int i=14; i>=0; i--){
		int num=pow(2,i);
		if(num<=x){
			if(i==0){
				cout<<"2(0)";
			}
			else if(i==1){
				cout<<"2";
			}
			else{
				cout<<"2(";
				d(i);
				cout<<")";
			}
			x-=num;
			if(x) cout<<"+";
		}
	}
}
int main(){
	cin>>n;
	d(n);
	return 0;
}

