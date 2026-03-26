#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
const int mod=1e8-3;
using namespace std;
int n,a[100009],b[100009],pos1[100009],pos2[100009],tree[100009],c[100009]; 
bool cmd1(int x,int y){
	return a[x]<a[y];
}
bool cmd2(int x,int y){
	return b[x]<b[y];
}
int lowbit(int x){
	return x&-x;
}
void add(int x){
	for( ; x<=n; x+=lowbit(x)){
		tree[x]++,tree[x]%=mod;
	}
}
long long query(int x){
	long long sum=0;
	for( ; x>0; x-=lowbit(x)){
		sum=(sum+tree[x])%mod;
	}
	return sum;
}
int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		pos1[i]=i;
	}
	for(int i=1; i<=n; i++){
		cin>>b[i];
		pos2[i]=i;
	}
	sort(pos1+1,pos1+1+n,cmd1);
	sort(pos2+1,pos2+1+n,cmd2);
	for(int i=1; i<=n; i++){
		c[pos1[i]]=pos2[i];
	}
	long long sum=0;
	for(int i=n; i>=1; i--){
		add(c[i]);
		sum=(sum+query(c[i]-1))%mod;
	}
	cout<<sum;
	return 0;
}

