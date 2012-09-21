#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while(cin>>n){
		if(n==0) return 0;

		vector<int> V;
		for(int i=0;i<n;i++){
			int t;
			cin>>t;
			V.push_back(t);
		}
		sort(V.begin(),V.end());

		int ans=0;
		for(int i=1;i<V.size()-1;i++)
			ans+=V[i];
		cout<<ans/(n-2)<<endl;

	}
}