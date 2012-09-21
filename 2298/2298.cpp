#include<iostream>
#include<vector>
using namespace std;

int N,K,T,U,V,L;

void solve()
{
	bool cal[10001];
	memset(cal,false,sizeof(cal));

	for(int i=0;i<N;i++){
		int n;
		cin>>n;
		cal[n]=true;
	}

	double res=0.0;
	int k=0;
	double rem=0;
	bool mode=false;


int main()
{
	while(cin>>N>>K>>T>>U>>V>>L)
		solve();
	return 0;
}
