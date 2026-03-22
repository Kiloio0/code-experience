#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0,x;
		for(int i=1;i<=n;i++){
			int j=i+n;
			cout<<"? "<<i<<" "<<j<<endl;
			fflush(stdout);
			cin>>x;
			if(x==-1) return 0;
			if(x==1){
				ans=j;
				break;
			}
		}
		if(ans==0){
			cout<<"? "<<n<<" "<<2*n-1<<endl;
			fflush(stdout);
			cin>>x;
			if(x==-1) return 0;
			ans=(x==1)?2*n-1:2*n; 
		}
		cout<<"! "<<ans<<endl;
		fflush(stdout);
	}
	return 0;
}
