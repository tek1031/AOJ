#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

struct edge{//�ӂ�\��
	int to,cost,limit;
	edge(int t,int c,int l){
		to=t;cost=c;limit=l;
	}
};

#define INF 1000000

struct Node{//�L���[�ɓ�����Ԃ�\��
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
	//���̔ԍ��C���O�ɖK�ꂽ���̔ԍ��C���x�Ń_�C�N�X�g��
	memset(visit,false,sizeof(visit));
	vector<vector<edge> > E(n+1);
	cin>>s>>g;
	for(int i=0;i<m;i++){//�A�����X�g�̍쐬
		int in,out,c,l;
		cin>>in>>out>>c>>l;
		E[in].push_back(edge(out,c,l));
		E[out].push_back(edge(in,c,l));
	}

	priority_queue<Node> Q;
	Q.push(Node(s,0,0.0,s));
	while(!Q.empty()){//�_�C�N�X�g��
		Node t=Q.top(); Q.pop();
		if(visit[t.now][t.before][t.speed]) continue;//���ɗ�����
		visit[t.now][t.before][t.speed]=true;//���܂���
		if(t.now==g && t.speed==1){printf("%.12lf\n", t.time );  return;}//�������o��

		for(int i=0;i<E[t.now].size();i++){//�ӂ��Ȃ����Ă�
			int to=E[t.now][i].to;
			if(to==t.before) continue;//U�^�[���֎~

			//���x�����炷�C�ێ��C���₷
			//���x��1�ȏ�@�������Ƃ��Ȃ��@�������x���I�[�o�[���Ȃ��Ȃ�L���[�ɓ˂�����
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
