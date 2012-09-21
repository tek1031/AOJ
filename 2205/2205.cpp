#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n,m;

struct kuzi{
	string s;
	int n;
	kuzi(string a,int b){s=a;n=b;}
};

void solve(){
	vector<kuzi> K;
	for(int i=0;i<n;i++){
		string s;
		int d;
		cin>>s>>d;
		K.push_back(kuzi(s,d));
	}
	vector<string> M;
	for(int i=0;i<m;i++){
		string s;
		cin>>s;
		M.push_back(s);
	}
	int res=0;

	for(int i=0;i<m;i++){
		for(int j=0;j<K.size();j++){
			string s1=M[i],s2=K[j].s;

			bool ok=true;
			for(int z=0;z<s1.size();z++){
				if(s2[z]=='*') continue;
				if(s1[z]!=s2[z]){ok=false;break;}
			}
			if(ok){res+=K[j].n; break;}
		}
	}
	cout<<res<<endl;
}




int main(){
	while(cin>>n>>m){
		if(n==0 && m==0) break;
		solve();
	}
	return 0;
}

