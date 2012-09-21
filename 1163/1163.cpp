#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
#define INF 10000000

int gcd(int a, int b){ return a%b ? gcd(b, a%b) : b; }//ç≈ëÂåˆñÒêî

struct edge{
	int to,cap,rev;
	edge(int t,int c,int r){
		to=t;cap=c,rev=r;
	}
};

vector<vector<edge> > G;
int level[100000];
int iter[100000];

void add_edge(int from,int to,int cap){
	G[from].push_back(edge(to,cap,G[to].size()));
	G[to].push_back(edge(from,0,G[from].size()-1));
}

void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();que.pop();
		for(int i=0;i<G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>0 && level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}

int dfs(int v,int t,int f){
	if(v==t)return f;
	for(int &i=iter[v];i<G[v].size();i++){
		edge &e=G[v][i];
		if(e.cap>0 && level[v]<level[e.to]){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s,int t){
	int flow=0;
	while(true){
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,INF))>0){
			flow+=f;
		}
	}
}


int main()
{
	int n,m;
	while(cin>>n>>m && n>0){
		G.clear();
		G.resize(n+m+2);
		vector<int> red,blue;
		for(int i=0;i<n;i++){
			int t;
			cin>>t;
			red.push_back(t);
			add_edge(0,1+i,1);
		}
		for(int i=0;i<m;i++){
			int t;
			cin>>t;
			blue.push_back(t);
			add_edge(n+i+1,n+m+1,1);
		}
		for(int r=0;r<n;r++){
			for(int b=0;b<m;b++){
				if(gcd(red[r],blue[b])>1){
					add_edge(r+1,n+b+1,1);
				}
			}
		}
		cout<<max_flow(0,n+m+1)<<endl;
	}
	return 0;
}