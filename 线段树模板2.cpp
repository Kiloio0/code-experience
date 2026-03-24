#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
ll n,m,p,a[100009];
struct node{
	ll l,r,sum,add,mul;
}tree[100009<<2];
ll ls(ll x){
	return x<<1;
}
ll rs(ll x){
	return x<<1|1; 
}
void push_up(ll x){
	tree[x].sum=(tree[ls(x)].sum+tree[rs(x)].sum)%p;
	return ;
}
void push_down(ll x){
	tree[ls(x)].sum=(tree[ls(x)].sum*tree[x].mul+(tree[ls(x)].r-tree[ls(x)].l+1)*tree[x].add)%p;
	tree[rs(x)].sum=(tree[rs(x)].sum*tree[x].mul+(tree[rs(x)].r-tree[rs(x)].l+1)*tree[x].add)%p;
	tree[ls(x)].mul=(tree[ls(x)].mul*tree[x].mul)%p;
	tree[rs(x)].mul=(tree[rs(x)].mul*tree[x].mul)%p;
	tree[ls(x)].add=(tree[ls(x)].add*tree[x].mul+tree[x].add)%p;
	tree[rs(x)].add=(tree[rs(x)].add*tree[x].mul+tree[x].add)%p;
	tree[x].add=0,tree[x].mul=1;
	return ;
}
void build(ll root,ll l,ll r){
	tree[root].l=l,tree[root].r=r,tree[root].mul=1;
	if(l==r){
		tree[root].sum+=a[l]%p;
		return ;
	}
	ll mid=(l+r)>>1;
	build(ls(root),l,mid),build(rs(root),mid+1,r);
	push_up(root);
	return ;
}
void mul(ll root,ll l,ll r,ll k){
	if(l<=tree[root].l && tree[root].r<=r){
		tree[root].add=(tree[root].add*k)%p,tree[root].mul=(tree[root].mul*k)%p,tree[root].sum=(tree[root].sum*k)%p;
		return ;
	}
	push_down(root);
	ll mid=(tree[root].l+tree[root].r)>>1;
	if(l<=mid){
		mul(ls(root),l,r,k);
	}
	if(mid+1<=r){
		mul(rs(root),l,r,k);
	}
	push_up(root);
	return ;
}
void add(ll root,ll l,ll r,ll k){
	if(l<=tree[root].l && tree[root].r<=r){
		tree[root].add=(tree[root].add+k)%p,tree[root].sum=(tree[root].sum+k*(tree[root].r-tree[root].l+1))%p;
		return ;
	}
	push_down(root);
	ll mid=(tree[root].l+tree[root].r)>>1;
	if(l<=mid){
		add(ls(root),l,r,k);
	}
	if(mid+1<=r){
		add(rs(root),l,r,k);
	}
	push_up(root);
	return ;
}
ll query(ll root,ll l,ll r){
	if(l<=tree[root].l && tree[root].r<=r){
		return tree[root].sum;
	}
	push_down(root);
	ll ans=0;
	ll mid=(tree[root].l+tree[root].r)>>1;
	if(l<=mid){
		ans=(ans+query(ls(root),l,r))%p;
	}
	if(mid+1<=r){
		ans=(ans+query(rs(root),l,r))%p;
	}
	return ans;
}
int main(){
	cin>>n>>m>>p;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	build(1,1,n);
	ll op,l,r,k;
	for(int i=1; i<=m; i++){
		cin>>op>>l>>r;
		if(op==1){
			cin>>k;
			mul(1,l,r,k);
		}
		else if(op==2){
			cin>>k;
			add(1,l,r,k);
		}
		else{
			cout<<query(1,l,r)<<'\n';
		}
	}
	return 0;
}

