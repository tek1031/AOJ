#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int main()
{
	int n,a,s,g;
	while(cin>>n>>a>>s>>g && n!=0){
		int LIMIT=0;
		vector<string> ans(n);
		vector<vector<vector<string> > > edge(n,vector<vector<string> >(n));//edge[i][j][k]  i->j :k番目のラベル
		for(int i=0;i<a;i++){
			int x,y; string r;
			cin>>x>>y>>r;
			edge[x][y].push_back(r);
			LIMIT+=r.size()*10;
		}

		queue<int> que;
		que.push(g);
		int count=0;

		while(!que.empty()){//無限ループするよ！
			count++;
			int to=que.front(); que.pop();
			for(int from=0;from<n;from++){
				for(int k=0;k<edge[from][to].size();k++){
					if(from==g) continue;
					string rabel=edge[from][to][k];
					if(ans[from]=="" || ans[from]>rabel+ans[to]){
						ans[from]=rabel+ans[to];que.push(from);
					}
				}
			}
			bool b=false;
			for(int i=0;i<n;i++){
				if(ans[i].size()>=LIMIT){b=true;break;}
			}
			if(b)  break;
		}
		if(ans[s].size()>=LIMIT/4 || ans[s]=="") cout<<"NO"<<endl;
		else cout<<ans[s]<<endl;
	}
	return 0;
}