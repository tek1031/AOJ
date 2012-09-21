#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int N,M,L,K,A,H;
bool re[100];
int cost[100][100];

struct Node{
	int total,rem,pos,total_b;
};

bool operator < (Node a,Node b){
	return a.total>b.total;
}


void solve()
{
	memset(re,false,sizeof(re));
	memset(cost,-1,sizeof(cost));
	re[A]=re[H]=true;
	for(int i=0;i<L;i++){int t;cin>>t;re[t]=true;}

	for(int i=0;i<K;i++){
		int in,out,c;cin>>in>>out>>c;
		cost[in][out]=cost[out][in]=c;
	}

	vector<vector<Node> >V(N);
	Node first;
	first.rem=M; first.total=0; first.pos=A;first.total_b=0;
	priority_queue<Node> Q;
	Q.push(first);
//	cout<<endl<<endl;

	while(!Q.empty()){
		Node now=Q.top();
		Q.pop();
//		cout<<now.pos<<" "<<now.rem<<" "<<now.total<<endl;
		if(now.rem<0) continue;
		if(now.pos==H){cout<<now.total-min(now.total_b,now.rem)<<endl; return;}
		bool ok=true;
		for(int i=0;i<V[now.pos].size();i++){
			if(V[now.pos][i].rem>=now.rem && V[now.pos][i].total<=now.total){
				ok=false;
				break;
			}
		}
		if(!ok) continue;
		V[now.pos].push_back(now);

		for(int i=0;i<N;i++){
			if(cost[now.pos][i]==-1) continue;
			Node next;
			if(re[i]){
				if(now.rem<cost[now.pos][i]) continue;
				next.rem=M;
				next.total=now.total+cost[now.pos][i]+M-now.rem+cost[now.pos][i];
				next.pos=i;
				next.total_b=now.total_b+M-now.rem+cost[now.pos][i];
			}
			else{
				next.rem=now.rem-cost[now.pos][i];
				next.total=now.total+cost[now.pos][i];
				next.pos=i;
				next.total_b=now.total_b;
			}
			Q.push(next);
		}

	}

	cout<<"Help!"<<endl;
}



int main(){
	while(cin>>N>>M>>L>>K>>A>>H){
		if(N==0) break;
		solve();
	}
	return 0;
}
