#include<iostream>
#include<string.h>
#include<set>
#include<queue>
using namespace std;

int dx[]={1,1,0,-1,-1,0};
int dy[]={1,0,-1,-1,0,1};

set<pair<int,int> > OB;
set<pair<int,int> > D;

int main()
{
	int t,n;
	while(cin>>t>>n && t!=0){
		OB.clear();
		D.clear();
		for(int i=0;i<n;i++){
			int x,y;cin>>x>>y;
			OB.insert(make_pair(x,y));
		}
		queue<pair<pair<int,int> ,int> > Q;
		int x,y; cin>>x>>y;
		Q.push(make_pair(make_pair(x,y),0));
		while(!Q.empty()){
			pair<int,int> now=Q.front().first;
			int cost=Q.front().second;
			Q.pop();
			if(OB.count(now)) continue;
			if(D.count(now)) continue;
			D.insert(now);
			if(cost==t) continue;
			for(int r=0;r<6;r++)
				Q.push(make_pair(make_pair(now.first+dx[r],now.second+dy[r]),cost+1));
		}
		cout<<D.size()<<endl;
	}
	return 0;
}