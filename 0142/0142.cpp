#include<iostream>
#include<map>
#include<vector>
using namespace std;

int n;

typedef long long ll;

void solve()
{
	map<ll,int> M;
	vector<int> V;
	vector<int> res((n-1)/2,0);
	for(ll i=1;i<n;i++){
		int t=i*i%n;
		if(!M.count(t)){
			V.push_back(t);
			M[t]=0;
		}
	}

	for(int i=0;i<V.size();i++){
		for(int j=i+1;j<V.size();j++){
			int t=V[i]-V[j];
			if(t<0) t+=n;
			if(t>(n-1)/2) t=n-t;
			res[t-1]++;
		}
	}
	for(int i=0;i<res.size();i++)
		cout<<res[i]*2<<endl;

}

int main()
{
	while(cin>>n){
		if(n==0) break;
		solve();
	}
	return 0;
}
