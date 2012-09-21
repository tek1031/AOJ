#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

int N;
vector<vector<int> > L;
vector<int> power;
vector<bool> ok;
int ans;
vector<int> total;

void calc(int now,int sum){

	ans=max(ans,sum);
	int t=0;

	for(int i=now;i<N;i++)
		t+=power[i];
	if(t+sum<=ans) return;

	if(now>=N) return;

	if(!ok[now]){calc(now+1,sum);return;}
	bool can_cut=true;

	for(int i=0;i<L[now].size();i++){//Ž}Žë‚ê‚é‚©ƒ`ƒFƒbƒN!
		if(ok[L[now][i]]){can_cut=false;break;}
	}

	vector<int> memo;
	for(int i=0;i<L[now].size();i++){
		if(ok[L[now][i]]){memo.push_back(L[now][i]);ok[L[now][i]]=false;}
	}


	calc(now+1,sum+power[now]);

	for(int i=0;i<memo.size();i++)
		ok[memo[i]]=true;

	if(!can_cut) calc(now+1,sum);//Ž}Š ‚è
}

int main()
{
	while(cin>>N && N!=0){
		ans=0;
		int c=0;
		map<string,int> Idx;
		L.clear();L.resize(N,vector<int>());
		ok.clear();ok.resize(N,true);
		power.clear(); power.resize(N,0);
		for(int i=0;i<N;i++){
			string nation;
			cin>>nation;
			if(!Idx.count(nation))Idx[nation]=c++;
			cin>>power[Idx[nation]];
			int m=0;cin>>m;
			for(int j=0;j<m;j++){
				string s; cin>>s;
				if(!Idx.count(s))Idx[s]=c++;
				L[Idx[nation]].push_back(Idx[s]);
			}
		}

		total.clear();total.resize(N+1,0);
		for(int i=N-1;i>=0;i--){
			total[i]=total[i+1]+power[i];
		}


		ok[0]=false;
		ans+=power[0];
		for(int i=0;i<L[0].size();i++)
			ok[L[0][i]]=false;

		calc(1,ans);
		cout<<ans<<endl;
	}
}