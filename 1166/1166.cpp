#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int W,H;
bool in(int x,int y){
	if(x<0 || y<0 || x>=W || y>=H) return false;
	return true;
}

struct Info{
	int x,y,cost;
	Info(int para_x,int para_y,int para_c){
		x=para_x;y=para_y;cost=para_c;
	}
};

void solve()
{
	
	int cost[30][30];
	bool r[30][30];//右に行ける？
	bool u[30][30];//上に行ける？
	memset(r,false,sizeof(r));
	memset(u,false,sizeof(u));

	for(int x=0;x<W-1;x++){//最初の一行
		int k; 
		cin>>k;
		if(k==0) r[0][x]=true;
	}

	for(int y=1;y<H;y++){
		for(int x=0;x<W;x++){
			int k;
			cin>>k;
			if(k==0) u[y][x]=true;
		}
		for(int x=0;x<W-1;x++){
			int k;
			cin>>k;
			if(k==0) r[y][x]=true;
		}
	}

	memset(cost,-1,sizeof(cost));
	queue<Info> Q;
	Q.push(Info(0,0,0));

	while(!Q.empty()){//幅優先！
		Info t=Q.front();
		Q.pop();
		if(!in(t.x,t.y)) continue;
		if(cost[t.y][t.x]>=0) continue;
		if(t.y==H-1 && t.x==W-1){cout<<t.cost+1<<endl;return;}
		cost[t.y][t.x]=t.cost;
		if(u[t.y][t.x]) Q.push(Info(t.x,t.y-1,t.cost+1));//右に行きたいなぁ
		if(r[t.y][t.x]) Q.push(Info(t.x+1,t.y,t.cost+1));//上に行きたいなぁ
		if(t.x!=0 && r[t.y][t.x-1]) Q.push(Info(t.x-1,t.y,t.cost+1));//左に行きたいなぁ
		if(t.y!=H-1 && u[t.y+1][t.x]) Q.push(Info(t.x,t.y+1,t.cost+1));//下に行きたいなぁ
	}
	cout<<0<<endl;
}


int main()
{
	while(cin>>W>>H){
		if(W==0) return 0;
		solve();
	}
}