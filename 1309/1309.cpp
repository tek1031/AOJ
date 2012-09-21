#include<iostream>
using namespace std;

typedef pair<int,int> cor;

int n;

void solve(){
	double dp[200][200];
	memset(dp,0,sizeof(dp));

	cout<<dp[0][0]<<endl;
	if(dp[0][0]==0) cout<<"ok\n";
	return;
}


int main()
{
	while(cin>>n){
		if(n==0) break;
		solve();
	}
	return 0;
}

