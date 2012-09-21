#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

typedef pair<int,int> COR;

int H,W,C;
vector<string> M;
int INF= 100000;

int cost[10][10];
bool come[1000][1000];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};


void solve(){

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			cost[i][j]=INF;

	M.clear();
	vector<pair<int,int> > V;
	
	for(int i=0;i<H;i++){
		string h;
		cin>>h;
		for(int j=0;j<h.size();j++)
			if(isdigit(h[j]) || h[j]=='S')
				V.push_back(make_pair(i,j));
			
		M.push_back(h);
	}

	int now;
	for(int i=0;i<V.size();i++){
		if(isdigit(M[V[i].first][V[i].second]))
			now=M[V[i].first][V[i].second]-'0';

		if(M[V[i].first][V[i].second]=='S')
			now=0;

		memset(come,false,sizeof(come));
		queue<pair<COR,int> > Q;
		Q.push(make_pair(V[i],0));
		int count=0;
		while(!Q.empty() && count<C+1){
			pair<COR,int> p=Q.front();
			Q.pop();
			int y=p.first.first,x=p.first.second,c=p.second;
			if(y<0 || x<0 || y>=H || x>=W ||come[y][x] || M[y][x]=='X')
				continue;
			come[y][x]=true;
			if(M[y][x]=='0'+now+1){
				cost[now][now+1]=c;
				break;
			}

			for(int r=0;r<4;r++)
				Q.push(make_pair(make_pair(y+dy[r],x+dx[r]),c+1));
		}
	}

	int res=0;

	for(int i=0;i<V.size()-1;i++)
		res+=cost[i][i+1];
	cout<<res<<endl;
}

int main()
{
	while(cin>>H>>W>>C){
		solve();
	}
	return 0;
}

