#include <bits/stdc++.h>
using namespace std;
int n,k,head[50004],to[100004],nex[100004],tot,num[50004],ans,dis[50004],fa[50004][22];
inline void add(int u,int v){
	to[++tot]=v,nex[tot]=head[u],head[u]=tot;
}
inline void init(int u,int f){
	dis[u]=dis[f]+1,fa[u][0]=f;
	for(int i=0; i<=19; i++){
		fa[u][i+1]=fa[fa[u][i]][i];
	}
	for(int i=head[u]; i; i=nex[i]){
		if(to[i]!=f) init(to[i],u);
	}
}
inline int lca(int u,int v){
	if(dis[u]<dis[v]) u^=v,v^=u,u^=v;
	for(int i=20; i>=0; i--){
		if(dis[fa[u][i]]>=dis[v]) u=fa[u][i];
	}
	if(u==v) return u;
	for(int i=20; i>=0; i--){
		if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	}
	return fa[u][0];
}
inline void sum(int u,int f){
	for(int i=head[u]; i; i=nex[i]){
		if(to[i]==f) continue;
		sum(to[i],u);
		num[u]+=num[to[i]];
	}
	ans=max(ans,num[u]);
}
int main(){
	cin>>n>>k;
	int a,b;
	for(int i=1; i<n; i++){	
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	init(1,0);
	for(int i=1; i<=k; i++){
		scanf("%d%d",&a,&b);
		int LCA=lca(a,b);
		//cout<<LCA<<endl;
		num[a]++,num[b]++,num[LCA]--,num[fa[LCA][0]]--;
	}
	sum(1,0);
	cout<<ans;
	return 0;
}

