#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int num[101][101];
int dist[101][101];
#define INF 100000000

class state{
public:
	int now,money,cost;
	state(int now,int money,int cost):now(now),cost(cost),money(money){}
	bool operator < (const state &a){
		return cost>a.cost;
	}
};

bool operator < (state a,state b){
	return a.cost>b.cost;
}

int main()
{
	int n,m,l;
	while(cin>>n>>m>>l && n!=0){

		int C[101][101];
		for(int i=0;i<101;i++)
			for(int j=0;j<101;j++)
				num[i][j]=dist[i][j]=C[i][j]=INF;

		for(int i=0;i<m;i++){
			int in,out,d,e;cin>>in>>out>>d>>e;
			num[in][out]=num[out][in]=e;
			dist[in][out]=dist[out][in]=d;
		}

		priority_queue<state> Q;
		Q.push(state(1,l,0));
		while(!Q.empty()){
			state t=Q.top(); Q.pop();
			if(C[t.now][t.money]<=t.cost) continue;
			C[t.now][t.money]=t.cost;
			if(t.now==n){cout<<t.cost<<endl; break;}
			for(int i=1;i<=n;i++){
				if(dist[t.now][i]<INF){
					if(t.money-dist[t.now][i]>=0)
						Q.push(state(i,t.money-dist[t.now][i],t.cost));
					Q.push(state(i,t.money,t.cost+num[t.now][i]));
				}
			}
		}
	}
	return 0;
}