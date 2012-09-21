#include<queue>
#include<iostream>
using namespace std;

int dy[]={-1,0,1,0},dx[]={0,-1,0,1};

struct Dice{
	int t,b,n,s,e,w;
	int y,x;
	
	int c;
	Dice(int top,int bottom,int north,int south,int east,int west,int sx,int sy,int cost){
		t=top,b=bottom,n=north,s=south,e=east,w=west;
		x=sx,y=sy,c=cost;
	}
	bool operator<(const Dice &r)const
	{
		return c>r.c;
	}
	void roll(int d)
	{
		int tmp;
		y+=dy[d],x+=dx[d];
		
		if(d==0)
		{
			tmp=t; t=s; s=b; b=n; n=tmp;
		}else if(d==1)
		{
			tmp=t; t=e; e=b; b=w; w=tmp;
		}else if(d==2)
		{
			tmp=t; t=n; n=b; b=s; s=tmp;
		}else
		{
			tmp=t; t=w; w=b; b=e; e=tmp;
		}
	}
};

int w,h;
bool in(int x,int y){
	if(x<0 || y<0 || x>=w || y>=h) return false;
	return true;
}

int main(){
	int p[10][10],memo[10][10][100];
	while(cin>>h>>w && h!=0){
		priority_queue<Dice> que;
		for(int y=0;y<h;y++)
			for(int x=0;x<w;x++){
				cin>>p[y][x];
			}
		memset(memo,-1,sizeof(memo));

		int gx,gy,sx,sy;
		cin>>sy>>sx>>gy>>gx;
		que.push(Dice(1,6,5,2,3,4,sx,sy,0));
		while(!que.empty()){
			Dice now=que.top();
			que.pop();
//			cout<<now.x<<" "<<now.y<<" "<<now.b<<" "<<now.c<<endl;
			if(now.x==gx && now.y==gy) {cout<<now.c<<endl; break;}
			if(memo[now.y][now.x][now.e*7+now.b]>=0 && memo[now.y][now.x][now.e*7+now.b]<=now.c) continue;
			memo[now.y][now.x][now.e*7+now.b]=now.c;


			for(int r=0;r<4;r++){
				Dice copy=now;
				copy.roll(r);
				if(in(copy.x,copy.y)){
					copy.c+=copy.b*p[copy.y][copy.x];
					que.push(copy);
				}
			}
		}
	}
	return 0;
}