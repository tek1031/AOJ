#include<iostream>
#include<vector>
#include<string>
using namespace std;

int h,w;

int dx[2]={-1,0};
int dy[2]={0,-1};

void solve()
{
	vector<string> V;
	for(int i=0;i<h;i++){
		string s;
		cin>>s;
		V.push_back(s);
	}

	vector<vector<int> > Dp(h,vector<int>(w,10000000));

	Dp[0][0]=0;

	for(int y=0;y<h;y++){
		for(int x=0;x<w;x++){
			for(int r=0;r<2;r++){
				int nx=x+dx[r],ny=y+dy[r];
				if(nx<0 || ny<0 ||nx>=w || ny>=h) continue;
				Dp[y][x]=min(Dp[ny][nx]+V[y][x]-'0',Dp[y][x]);
			}
		}
	}
	cout<<Dp[h-1][w-1]<<endl;
}

int main()
{
	while(cin>>h>>w){
		if(h==0) break;
		solve();
	}
	return 0;
}
