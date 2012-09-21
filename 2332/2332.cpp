#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

vector<int> T;
vector<int> M;
vector<bool> check;
int N;
const int NOT=-2;

int calc(int idx){
	if(T[idx]==NOT) return NOT;
	if(T[idx]>=0) return T[idx];
	if(check[idx]){T[idx]=NOT; return NOT;}
	check[idx]=true;
	if(M[idx]==0){
		T[idx]=idx;
		return idx;
	}
	return T[idx]=calc(idx+M[idx]);
}

class Node{
public:
	int idx,cost;
	Node(int idx,int cost):idx(idx),cost(cost){}
	Node();
};

bool operator  < (Node a,Node b){
	return a.cost>b.cost;
}


int main()
{
	cin>>N;
	T.resize(N,-1);
	check.resize(N,false);
	M.resize(N);
	for(int i=0;i<N;i++)
		cin>>M[i];

	T[0]=0;
	T[N-1]=N-1;
	for(int i=N-1;i>=1;i--){
		if(!check[i])
			calc(i);
	}
	vector<int> ans(N,N+1);
	priority_queue<Node> que;
	que.push(Node(0,0));


//	cout<<endl;
	int res=N+1;
	while(!que.empty()){
		Node now=que.top();
		que.pop();
//		cout<<now.idx<<endl;
		if(T[now.idx]==NOT) continue;
		if(ans[now.idx]<=now.cost) continue;
		ans[now.idx]=now.cost;
		for(int i=1;i<=6;i++){
			if(now.idx+i<=N-1){
				if(T[now.idx+i]>=0)
					que.push(Node(T[now.idx+i],now.cost+1));
			}
		}
	}
	cout<<ans[N-1]<<endl;
	return 0;
}
