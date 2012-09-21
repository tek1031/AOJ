#include<vector>
#include<iostream>
#include<queue>
using namespace std;
#define INF 1000000

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
		if(level[t]<0){cout<<"calc "<<flow<<endl;return flow;}
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,INF))>0){
			flow+=f;
		}
	}
}

int N,E,Q;

int main()
{
	cin>>N>>E>>Q;
	G.clear();
	G.resize(N+1);
	for(int i=0;i<E;i++){
		int in,out; cin>>in>>out;
		add_edge(in,out,1);
		add_edge(out,in,1);
	}
	int flow=max_flow(1,N);
	max_flow(1,N);
	for(int i=0;i<Q;i++){
		int M,in,out;
		cin>>M>>in>>out;
		if(M==1){
			add_edge(in,out,1);
			add_edge(out,in,1);
			flow+=max_flow(1,N);
			cout<<flow<<endl;
		}
	}
	return 0;
}