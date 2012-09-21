#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

struct edge{//辺を表す
	int to,cost,limit;
	edge(int t,int c,int l){
		to=t;cost=c;limit=l;
	}
};

#define INF 1000000

struct Node{//キューに入れる状態を表す
	int now,speed,before;
	double time;
	Node(int n,int s,double t,int bef){
		now=n;speed=s;time=t;before=bef;
	}
};

bool operator < (Node a,Node b){
	return a.time>b.time;
}

int n,m,s,g;

void solve(){
	bool visit[31][31][31];
	//町の番号，直前に訪れた町の番号，速度でダイクストラ
	memset(visit,false,sizeof(visit));
	vector<vector<edge> > E(n+1);
	cin>>s>>g;
	for(int i=0;i<m;i++){//連結リストの作成
		int in,out,c,l;
		cin>>in>>out>>c>>l;
		E[in].push_back(edge(out,c,l));
		E[out].push_back(edge(in,c,l));
	}

	priority_queue<Node> Q;
	Q.push(Node(s,0,0.0,s));
	while(!Q.empty()){//ダイクストラ
		Node t=Q.top(); Q.pop();
		if(visit[t.now][t.before][t.speed]) continue;//既に来たよ
		visit[t.now][t.before][t.speed]=true;//来ました
		if(t.now==g && t.speed==1){printf("%.12lf\n", t.time );  return;}//答えを出力

		for(int i=0;i<E[t.now].size();i++){//辺がつながってる
			int to=E[t.now][i].to;
			if(to==t.before) continue;//Uターン禁止

			//速度を減らす，維持，増やす
			//速度が1以上　来たことがない　制限速度をオーバーしないならキューに突っ込む
			for(int s=-1;s<=1;s++){
				if(t.speed+s>=1 && !visit[to][t.now][t.speed+s] && E[t.now][i].limit>=t.speed+s)
					Q.push(Node(to,t.speed+s,t.time+E[t.now][i].cost/((double)t.speed+s),t.now));
			}
		}
	}
	cout<<"unreachable"<<endl;
}

int main()
{
	while(cin>>n>>m && n!=0)
		solve();
	return 0;
}
