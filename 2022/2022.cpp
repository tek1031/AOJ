#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<fstream>
#include<algorithm>
#include<set>
using namespace std;

int n;

int main()
{
	
	std::ofstream ofs( "ans.txt" );


	while(cin>>n && n!=0){
		set<string> S;
		vector<string> in;
		for(int i=0;i<n;i++){
			string t;cin>>t;
			if(S.count(t)) continue;
			S.insert(t);
			in.push_back(t);
		}
		n=in.size();

		vector<string> s;
		for(int i=0;i<n;i++){
			bool lap=false;
			for(int j=0;j<n;j++){
				if(i==j) continue;
				if(in[i].size()>in[j].size()) continue;
				for(int k=0;k<=in[j].size()-in[i].size();k++){
					if(in[j].substr(k,in[i].size())==in[i])
						lap=true;
				}
			}
			if(!lap) s.push_back(in[i]);
		}
		n=s.size();
		string p[10][10];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				p[i][j]=s[j];
				for(int k=0;k<min(s[i].size(),s[j].size());k++){
					if(s[i].substr(s[i].size()-1-k)==s[j].substr(0,k+1)){
						p[i][j]=s[j].substr(k+1);
					}
				}
			}
		}
		int cost[10][1<<10];
		string ans[10][1<<10];
		for(int i=0;i<n;i++){
			for(int b=0;b<(1<<n);b++){
				cost[i][b]=10000000;
				ans[i][b]="";
			}
			cost[i][1<<i]=s[i].size();
			ans[i][1<<i]=s[i];
		}

		for(int bit=1;bit<(1<<n);bit++){
			for(int i=0;i<n;i++){
				if(!(bit & (1<<i))) continue;
				for(int j=0;j<n;j++){
					if(bit & (1<<j)) continue;
					int next_bit=(bit | (1<<j));
					int next_c=cost[i][bit]+p[i][j].size();
					string next_s=ans[i][bit]+p[i][j];
					if(cost[j][next_bit]>next_c){
						cost[j][next_bit]=next_c;
						ans[j][next_bit]=next_s;
					}
					else if(cost[j][next_bit]==next_c){
						ans[j][next_bit]=min(ans[j][next_bit],next_s);
					}
				}
			}
		}
		int mini_cost=1000000;
		string f_ans="";
		for(int i=0;i<n;i++){
			if(mini_cost>ans[i][(1<<n)-1].size()){
				mini_cost=ans[i][(1<<n)-1].size();
				f_ans=ans[i][(1<<n)-1];
			}
			else if(mini_cost==ans[i][(1<<n)-1].size()){
				f_ans=min(f_ans,ans[i][(1<<n)-1]);
			}
		}
		cout<<f_ans<<endl;
		ofs<<f_ans<<endl;
	}
	return 0;
}