#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int main()
{
	int n,m;
	while(cin>>n>>m){
		if(n==0) return 0;
		vector<int> p1,p2;
		int t1=0,t2=0;
		for(int i=0;i<n;i++){
			int t;cin>>t;p1.push_back(t);
			t1+=t;
		}
		for(int i=0;i<m;i++){
			int t;cin>>t;p2.push_back(t);
			t2+=t;
		}

		bool ok=false;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				if(!ok && t1-p1[i]+p2[j]==t2-p2[j]+p1[i]){
					cout<<p1[i]<<" "<<p2[j]<<endl;
					ok=true;
				}
			}
		if(!ok) cout<<-1<<endl;
	}
}