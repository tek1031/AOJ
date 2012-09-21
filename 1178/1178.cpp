#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF=10000000;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

class Node{
public:
	int x,y,cost;
	Node(int x,int y,int cost):x(x),y(y),cost(cost){}
};

bool operator < (Node a,Node b){
	return a.cost>b.cost;
}


int H,W;

void bfs(vector<vector<int> > &cost,vector<vector<bool> > right,vector<vector<bool> >upper,int sx,int sy){
	cost.clear();
	cost.resize(H,vector<int>(W,INF));
	queue<Node> que;
	que.push(Node(sx,sy,0));
	while(!que.empty()){
		Node now=que.front(); que.pop();
		if(cost[now.y][now.x]<=now.cost) continue;
		cost[now.y][now.x]=now.cost;
		if(right[now.y][now.x]) que.push(Node(now.x+1,now.y,now.cost+1));
		if(now.x-1>=0 && right[now.y][now.x-1]) que.push(Node(now.x-1,now.y,now.cost+1));
		if(upper[now.y][now.x]) que.push(Node(now.x,now.y-1,now.cost+1));
		if(now.y+1<H && upper[now.y+1][now.x]) que.push(Node(now.x,now.y+1,now.cost+1));
	}
}

int main()
{
	while(cin>>H>>W && H!=0){
		vector<vector<bool> >right(H,vector<bool>(W,false));
		vector<vector<bool> >upper(H,vector<bool>(W,false));
		for(int x=0;x<W-1;x++){
			int t;cin>>t;
			if(t==0) right[0][x]=true;
		}
		for(int y=1;y<H;y++){
			for(int x=0;x<W;x++){
				int t;cin>>t;
				if(t==0) upper[y][x]=true;
			}
			for(int x=0;x<W-1;x++){
				int t;cin>>t;
				if(t==0) right[y][x]=true;
			}
		}

		vector<vector<int> > second_cost(H,vector<int>(W,0));
		for(int y=0;y<H;y++){
			for(int x=0;x<W;x++){
				if(upper[y][x]){
					upper[y][x]=false;
					vector<vector<int> > temp;
					bfs(temp,right,upper,W-1,H-1);
					for(int i=0;i<H;i++) for(int j=0;j<W;j++) second_cost[i][j]=max(second_cost[i][j],temp[i][j]);
					upper[y][x]=true;
				}
				if(right[y][x]){
					right[y][x]=false;
					vector<vector<int> > temp;
					bfs(temp,right,upper,W-1,H-1);
					for(int i=0;i<H;i++) for(int j=0;j<W;j++) second_cost[i][j]=max(second_cost[i][j],temp[i][j]);
					right[y][x]=true;
				}
			}
		}

		vector<vector<int> > ans(H,vector<int>(W,0));
		priority_queue<Node> que;
		que.push(Node(0,0,0));
		while(!que.empty()){
			Node now=que.top();
			que.pop();
			if(now.cost+second_cost[now.y][now.x]<ans[now.y][now.x]) continue;
			ans[now.y][now.x]=now.cost+second_cost[now.y][now.x];
			if(right[now.y][now.x]) que.push(Node(now.x+1,now.y,now.cost+1));
			if(now.x-1>=0 && right[now.y][now.x-1]) que.push(Node(now.x-1,now.y,now.cost+1));
			if(upper[now.y][now.x]) que.push(Node(now.x,now.y-1,now.cost+1));
			if(now.y+1<H && upper[now.y+1][now.x]) que.push(Node(now.x,now.y+1,now.cost+1));
		}
		for(int y=0;y<H;y++){
			for(int x=0;x<W;x++){
				cout<<ans[y][x]<<" ";
			}
			cout<<endl;
		}

		cout<<ans[H-1][W-1]<<endl;
	}


	return 0;
}