#include<iostream>
#include<string.h>
using namespace std;




int n;


void solve()
{
	bool ok=false;
	long long  total[4000];
	bool check[4000];
	memset(check,false,sizeof(check));
	memset(total,0,sizeof(total));
	for(int i=0;i<n;i++){
		long long  num,a,b;
		cin>>num>>a>>b;
		total[num]+=a*b;
		if(total[num]>=1000000 && !check[num]){
			cout<<num<<endl;
			check[num]=true;
			ok=true;
		}
	}
	if(!ok) cout<<"NA"<<endl;
}

int main()
{
	while(cin>>n){
		if(n==0) break;
		solve();
	}
	return 0;
}
