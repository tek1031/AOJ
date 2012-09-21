#include<iostream>
using namespace std;

		int dp[(1<<16)+1];
int main()
{
	int N;
	while(cin>>N && N!=0){
		for(int k=0;k<=(1<<16);k++)
			dp[k]=100000000;

		dp[0]=0;

		int cost[16][16];
		int no[16];
		for(int i=0;i<N;i++){
			cin>>no[i];
			for(int j=0;j<N;j++)
				cin>>cost[i][j];
		}
			

		for(int bit=0;bit<(1<<N);bit++){
			for(int i=0;i<N;i++){
				if(bit & (1<<i)) continue;
				int next=(bit | (1<<i));
				dp[next]=min(dp[next],dp[bit]+no[i]);
				for(int j=0;j<N;j++){
					if(bit & (1<<j))
						dp[next]=min(dp[next],dp[bit]+cost[i][j]);
				}
			}


		}
		cout<<dp[(1<<N)-1]<<endl;


	}
	return 0;
}