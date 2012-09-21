#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class zone{
public:
	int d,p;
	zone(int d,int p):d(d),p(p){}
};

bool operator < (zone a,zone b){
	return a.p>b.p;
}


int main()
{
	int n;
	long long m;
	while(cin>>n>>m && n!=0){
		vector<zone> V;
		for(int i=0;i<n;i++){
			int d,p; cin>>d>>p;
			V.push_back(zone(d,p));
		}
		sort(V.begin(),V.end());
		int ans=0;
		for(int i=0;i<V.size();i++){
			if(m-V[i].d>=0) m-=V[i].d;
			else{
				ans+=V[i].p*(V[i].d-m);
				m=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}