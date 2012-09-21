#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,E,T;
vector<bool> check;
vector<int> cost;
vector<vector<vector<int> > > rule;
const int NOT=-2;

int calc(int idx){
	if(cost[idx]>=0) return cost[idx];
	if(cost[idx]==NOT) return NOT;
	if(check[idx]){cost[idx]=NOT;return NOT;}
	check[idx]=true;
	if(rule[idx].size()==0){cost[idx]=NOT; return NOT;}
	int res=1000000000;
	for(int i=0;i<rule[idx].size();i++){
		vector<int> C;
		bool ok=true;
		for(int j=0;j<rule[idx][i].size();j++){
			int p=calc(rule[idx][i][j]);
			if(p==NOT){cost[idx]=NOT;ok=false;break;}
			C.push_back(p);
		}
		if(ok){
			if(idx==T){
				cout<<"WARNING\n";
				for(int k=0;k<C.size();k++)
					cout<<C[k]<<" ";
				cout<<endl;
			}
			sort(C.begin(),C.end());
			int num=0,fill=0;
			for(int k=C.size()-1;k>=0;k--){
				num=max(num,fill+C[k]);
				fill++;
			}
			res=min(res,num);
		}
	}
	check[idx]=false;
	if(res==1000000000) return cost[idx]=NOT;
	return cost[idx]=res;
}


int main()
{
	cin>>N>>E>>T;
	T--;
	check.resize(N,false);
	cost.resize(N,-1);
	for(int i=0;i<N;i++){
		int t;cin>>t;
		if(t==1){cost[i]=1;}
	}
	rule.resize(N);

	for(int i=0;i<E;i++){
		int idx,num; cin>>idx>>num;
		idx--;
		vector<int> now;
		for(int j=0;j<num;j++){
			int t;cin>>t;t--;
			now.push_back(t);
		}
		rule[idx].push_back(now);
	}
	for(int i=0;i<N;i++)
		calc(i);
	int res=calc(T);
	for(int i=0;i<cost.size();i++)
		cout<<i<<": "<<cost[i]<<endl;
	cout<<endl;

	if(res==NOT) cout<<-1<<endl;
	else cout<<res<<endl;
	return 0;
}