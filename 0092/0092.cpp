#include<iostream>
#include<vector>
#include<string>
using namespace std;

int N;

void solve()
{
	vector<string> M;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		M.push_back(s);
	}
	vector<vector<int> > Dp(N,vector<int>(N,0));
	int ans=0;

	for(int i=0;i<N;i++){
		if(M[0][i]=='.') Dp[0][i]=1;
		if(M[i][0]=='.') Dp[i][0]=1;
	}

	for(int y=1;y<N;y++){
		for(int x=1;x<N;x++){
			if(M[y][x]=='.'){
				if(M[y-1][x]=='.' && M[y][x-1]=='.'){
					Dp[y][x]=min(Dp[y-1][x-1],min(Dp[y-1][x],Dp[y][x-1]))+1;
				}
				else Dp[y][x]=1;
			}
			ans=max(Dp[y][x],ans);
		}
	}
	cout<<ans<<endl;
}


int main()
{
	while(cin>>N){
		if(N==0) return 0;
		solve();
	}

}