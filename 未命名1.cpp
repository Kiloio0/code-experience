#include <bits/stdc++.h>
using namespace std;
int n,k,a[33],ans;
bool check(int x) {
	if(x==1) return 0;
	for(int i=2; i*i<=x; i++){
		if(x%i==0) return 0;
	}
	return 1;
}
void dfs(int now,int sum,int sid){
	if(now==k){
		if(check(sum)){
			ans++;
		}
		return ;
	}
	for(int i=sid; i<=n-k+now+1; i++){
		dfs(now+1,sum+a[i],i+1);
	}
	return ;
}
int main() {
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	dfs(0,0,1);
	cout<<ans;
	return 0;
}

