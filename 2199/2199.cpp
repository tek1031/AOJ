#include<iostream>
#include<string.h>
using namespace std;

int cut(int n){
	if(n<0) return 0;
	if(n>255) return 255;
	return n;
}

		int dp[20001][256];
int main()
{
	int N,M;
	while(cin>>N>>M && N!=0){
		int book[16],signal[20000];
		memset(book,-1,sizeof(bool));
		memset(signal,-1,sizeof(signal));

		for(int i=0;i<M;i++)
			cin>>book[i];
		for(int i=0;i<N;i++)
			cin>>signal[i];


		memset(dp,-1,sizeof(dp));
		dp[0][128]=0;

		for(int i=0;i<N;i++){
			for(int j=0;j<=255;j++){
				if(dp[i][j]<0) continue;
				for(int k=0;k<M;k++){
					if(dp[i+1][cut(j+book[k])]<0)
						dp[i+1][cut(j+book[k])]=dp[i][j]+(signal[i]-cut(j+book[k]))*(signal[i]-cut(j+book[k]));
					else dp[i+1][cut(j+book[k])]=min(dp[i+1][cut(j+book[k])],dp[i][j]+(signal[i]-cut(j+book[k]))*(signal[i]-cut(j+book[k])));
					
				}
			}
		}
		int ans=100000000;

		for(int i=0;i<=255;i++){
			if(dp[N][i]>=0)
				ans=min(ans,dp[N][i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}