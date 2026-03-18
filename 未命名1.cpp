#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m,tree[300009],cnt;
inline int lowbit(int x){
	return x&-x;
}
struct node1{
	int x,pos;
}a[300009];
struct node2{
	int l,r;
}pai[3000009];
struct node3{
	int l,r,pos;
}que[300009];
bool cmd1(node1 x,node1 y){
	return x.x<y.x;
}
bool cmd2(node2 x,node2 y){
	if(x.r!=y.r) return x.r<y.r;
	else return x.l<y.l;
}
bool cmd3(node3 x,node3 y){
	if(x.r!=y.r) return x.r<y.r;
	else return x.l<y.l;
}
void add(node1 x,node1 y){
	pai[++cnt].l=min(x.pos,y.pos);
	pai[cnt].r=max(x.pos,y.pos);
	return ;
}
void build(int x){
	for(; x<=n; x+=lowbit(x)){
		tree[x]++;
	}
}
long long query(int x){
	long long sum=0;
	for(; x>0; x-=lowbit(x)){
		sum+=tree[x];
	}
	return sum;
}
int main(){
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i].x);
		a[i].pos=i;
	}
	sort(a+1,a+1+n,cmd1);
	if(n!=1){
		add(a[1],a[2]);
		add(a[n-1],a[n]);
	}
	for(int i=2; i<n; i++){
		if(a[i].x-a[i-1].x<a[i+1].x-a[i].x){
			add(a[i],a[i-1]);
		}
		else if(a[i].x-a[i-1].x==a[i+1].x-a[i].x){
			add(a[i],a[i-1]),add(a[i+1],a[i]);
		}
		else{
			add(a[i+1],a[i]);
		}
	}
	sort(pai+1,pai+1+cnt,cmd2);
	for(int i=1; i<=m; i++){
		scanf("%d%d",&que[i].l,&que[i].r);
		que[i].pos=i;
	}
	sort(que+1,que+1+m,cmd3);
	long long ans=0;
	for(int i=1,j=1; i<=m; i++){
		while(pai[j].r<=que[i].r && j<=cnt){
			build(pai[j].l),j++;
		}
		ans+=1ll*que[i].pos*(j-query(que[i].l-1)-1);
	}
	cout<<ans;
	return 0;
}
