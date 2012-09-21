#include<iostream>
#include<string.h>
using namespace std;

bool ok[1000001];
bool done[1000001];
int n,a,b;

bool check(int k){
	if(k==0) return true;
	if(k<0) return false;
	if(done[k]) return ok[k];

	done[k]=true;
	ok[k]=(check(k-a) || check(k-b));
}

int main()
{
	while(cin>>n>>a>>b && n!=0){
		memset(ok,false,sizeof(ok));
		memset(done,false,sizeof(done));
		int ans=0;
		ok[0]=true;
		for(int i=0;i<=n;i++){
			if(ok[i]){
				if(i+a<=n)
					ok[i+a]=true;
				if(i+b<=n)
					ok[i+b]=true;
			}
			else ans++;
		}
		cout<<ans<<endl;
	}
	return 0; 
}