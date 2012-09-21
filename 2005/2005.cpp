#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
#include<fstream>
using namespace std;

class state{
public:
	int now,cost;
	state(int now,int cost):now(now),cost(cost){}
};

bool operator <(state a,state b){
	return a.cost>b.cost;
}

int n,m,s,g1,g2;

int cost_s[101],cost_g1[101],cost_g2[101];

int edge[101][101];
int edge_rev[101][101];

int main()
{	std::ofstream ofs( "ans.txt" );
	while(cin>>n>>m>>s>>g1>>g2 && n!=0){
		int ans=1000000;
		for(int i=0;i<101;i++){
			cost_s[i]=cost_g1[i]=cost_g2[i]=10000000;
			for(int j=0;j<101;j++){
				edge[i][j]=10000000;
				edge_rev[i][j]=100000000;
			}
		}

		
		for(int i=0;i<m;i++){
			int in,out,c; cin>>in>>out>>c;
			edge[in][out]=c;
			edge_rev[out][in]=c;
		}


		priority_queue<state> Q;
		Q.push(state(s,0));
		while(!Q.empty()){
			state info=Q.top();
			Q.pop();
			if(info.cost>=cost_s[info.now]) continue;
			cost_s[info.now]=info.cost;
			for(int i=0;i<101;i++){
				Q.push(state(i,info.cost+edge[info.now][i]));
			}
		}
		
		Q.push(state(g1,0));
		while(!Q.empty()){
			state info=Q.top();
			Q.pop();
			if(info.cost>=cost_g1[info.now]) continue;
			cost_g1[info.now]=info.cost;
			for(int i=0;i<101;i++){
				Q.push(state(i,info.cost+edge_rev[info.now][i]));
			}
		}

		Q.push(state(g2,0));
		while(!Q.empty()){
			state info=Q.top();
			Q.pop();
			if(info.cost>=cost_g2[info.now]) continue;
			cost_g2[info.now]=info.cost;
			for(int i=0;i<101;i++){
				Q.push(state(i,info.cost+edge_rev[info.now][i]));
			}
		}

		for(int i=0;i<101;i++){
			ans=min(ans,cost_s[i]+cost_g1[i]+cost_g2[i]);
		}
		cout<<ans<<endl;
		ofs<<ans<<endl;
	}
	return 0;
}