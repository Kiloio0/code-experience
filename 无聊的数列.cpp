#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
long long n,m,a[100009],op,sum[100009<<2],lazy[100009<<2];
void summarize(long long rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(long long l,long long r,long long rt){
	if(l==r){
		sum[rt]=a[l];
		return ;
	}
	long long mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	summarize(rt);
}
void pd(long long rt,long long llen,long long rlen){
	if(!lazy[rt]) return ;
	sum[rt<<1]+=lazy[rt]*llen;
	sum[rt<<1|1]+=lazy[rt]*rlen;
	lazy[rt<<1]+=lazy[rt],lazy[rt<<1|1]+=lazy[rt];
	lazy[rt]=0;
}
void update(long long l,long long r,long long rt,long long x,long long y,long long k){
	if(x<=l && r<=y){
		sum[rt]+=k*(r-l+1),lazy[rt]+=k;
		return ;
	}
	long long mid=(l+r)>>1;
	pd(rt,mid-l+1,r-mid);
	if(x<=mid) update(l,mid,rt<<1,x,y,k);
	if(mid+1<=y) update(mid+1,r,rt<<1|1,x,y,k);
	summarize(rt);
}
long long query(long long l,long long r,long long rt,long long x,long long y){
	if(x<=l && r<=y) return sum[rt];
	long long mid=(l+r)>>1;
	pd(rt,mid-l+1,r-mid);
	long long ans=0;
	if(x<=mid) ans+=query(l,mid,rt<<1,x,y);
	if(mid+1<=y) ans+=query(mid+1,r,rt<<1|1,x,y);
	return ans; 	
}
int main(){
	cin>>n>>m;
	for(long long i=1; i<=n; i++){
		scanf("%lld",&a[i]);
	}
	for(int i=n-1; i>0; i--){
		a[i+1]-=a[i];	
	}
	build(1,n,1);
	int k,d,x,y;
	while(m--){
		cin>>op;
		if(op==1){
			cin>>x>>y>>k>>d;
			update(1,n,1,x,x,k);
			if(x+1<=y) update(1,n,1,x+1,y,d);
			if(y+1<=n) update(1,n,1,y+1,y+1,-(k+d*(y-x)));
		}
		else{
			cin>>k;
			printf("%lld\n",query(1,n,1,1,k));
		}
	}
	return 0;
}
