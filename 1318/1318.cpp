#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std;

int N,M,Cap;

struct Edge{
public:
	int to,cost;
	Edge(int a,int b){to=a;cost=b;}
	Edge(){to=0;cost=0;}
};

typedef vector<vector<Edge> > Graph;

const int INF=1000000007;

class Info{
public: 
	int now,total,rem;
	Info(int a,int b,int c){now=a;total=b;rem=c;}
	bool operator < (const Info &a) const {return total>a.total;}
};

vector<int> get_cost(Graph g,int s){
	vector<int> res(N*2,INF);
	vector<bool> visit(N*2,false);
	priority_queue<Info> Q;
	Q.push(Info(s,0,0));
	while(!Q.empty()){
		Info top=Q.top();
		Q.pop();
		int pos=top.now;
		if(visit[pos]) continue;
		visit[pos]=true;
		res[pos]=top.total;
		for(int i=0;i<g[pos].size();i++)
			Q.push(Info(g[pos][i].to,top.total+g[pos][i].cost,0));
	}
	return res;
}

int calc(Graph g,int s,int t){
	vector<bool> visit(N*2,false);
	priority_queue<Info> Q;
	Q.push(Info(s,0,0));
	while(!Q.empty()){
		Info top=Q.top();
		Q.pop();
		if(top.now==t) return top.total;
		int pos=top.now;
		if(visit[pos]) continue;
		visit[pos]=true;
		for(int i=0;i<g[pos].size();i++)
			Q.push(Info(g[pos][i].to,top.total+g[pos][i].cost,0));
	}
	return -1;
}

void solve()
{
	Cap*=10;
	map<string,int> Idx;
	Graph V(N*2,vector<Edge>(0));
	int size=0;
	string start,goal;
	cin>>start>>goal;
	Idx[start]=size++; Idx[goal]=size++;
	for(int i=0;i<N;i++){
		string s1,s2; int d;
		cin>>s1>>s2>>d;
		if(!Idx.count(s1)) Idx[s1]=size++;
		if(!Idx.count(s2)) Idx[s2]=size++;
		V[Idx[s1]].push_back(Edge(Idx[s2],d));
		V[Idx[s2]].push_back(Edge(Idx[s1],d));
	}

	vector<int> Sta(M+2);
	for(int i=0;i<M;i++){
		string s;
		cin>>s;
		Sta[i]=Idx[s];
	}
	Sta[M]=Idx[start];Sta[M+1]=Idx[goal];

	Graph g(N*2);
	for(int i=0;i<M+2;i++){
		vector<int> temp=get_cost(V,Sta[i]);
		for(int j=0;j<M+2;j++){
			if(temp[Sta[j]]<=Cap)
				g[Sta[i]].push_back(Edge(Sta[j],temp[Sta[j]]));
		}
	}

	cout<<calc(g,Idx[start],Idx[goal])<<endl;

}


int main()
{
	while(cin>>N>>M>>Cap){
		if(N==0) break;
		solve();
	}
	return 0;
}
