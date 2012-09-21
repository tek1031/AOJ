#include<iostream>
#include<queue>
#include<string.h>
#include<queue>
#include<vector>
#include<set>
using namespace std;

class info{
public:
	int id,cost;
	vector<int> bef;
	vector<bool> L;
	info(int id,int cost,vector<int> bef,vector<bool> L):L(L),bef(bef),id(id),cost(cost){}
};

bool operator <(info a,info b){
	if(a.id!=b.id) return a.id<b.id;
	if(a.cost!=b.cost) return a.cost>b.cost;
	if(a.bef.size()!=b.bef.size()) return a.bef.size()>b.bef.size();

	for(int i=0;i<a.bef.size();i++){
		if(a.bef[i]!=b.bef[i]) return a.bef[i]>b.bef[i];
	}
	return false;
}

int main()
{
	int ans[1001];
	for(int i=0;i<1001;i++)
		ans[i]=100000;

	int n;
	while(cin>>n && n!=0){
		bool done[1001];

		memset(done,false,sizeof(done));
		queue<info> que;
		que.push(info(1,0,vector<int>(1,1),vector<bool>(1001,false)));
		while(!que.empty()){
			info now=que.front();que.pop();
			if(now.id<0 || now.id>1000) continue;
			if(ans[now.id]<now.cost) continue;

			ans[now.id]=now.cost;
			if(now.id==n){cout<<now.cost<<endl; break;}
			for(int i=0;i<now.bef.size();i++){
				if(now.id+now.bef[i]>=0 && now.id+now.bef[i]<=1000 && !now.L[now.id+now.bef[i]]) {
					now.bef.push_back(now.id+now.bef[i]);
					now.L[now.id+now.bef[i]]=true;
					que.push(info(now.id+now.bef[i],now.cost+1,now.bef,now.L));
					now.bef.pop_back();
					now.L[now.id+now.bef[i]]=false;
				}
				if(now.id-now.bef[i]>=0 && now.id-now.bef[i]<=1000 && !now.L[now.id-now.bef[i]]){
					now.bef.push_back(now.id-now.bef[i]);
					now.L[now.id-now.bef[i]]=true;
					que.push(info(now.id-now.bef[i],now.cost+1,now.bef,now.L));
					now.bef.pop_back();
					now.L[now.id-now.bef[i]]=false;
				}
			}
		}
	}
	return 0;
}