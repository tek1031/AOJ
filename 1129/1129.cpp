#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n,r;
	while(cin>>n>>r){
		if(n==0) return 0;
		vector<int> V;
		for(int i=0;i<n;i++)
			V.push_back(n-i);

		for(int i=0;i<r;i++){
			int s,t;
			cin>>s>>t;
			s--;

			vector<int> w;
			for(int j=0;j<t;j++){
				w.push_back(V[s+j]);
			}

			vector<int> next;

			for(int k=0;k<w.size();k++){
				next.push_back(w[k]);
			}

			for(int k=0;k<s;k++){
				next.push_back(V[k]);
			}

			for(int k=s+t;k<n;k++)
				next.push_back(V[k]);

			V=next;
		}
		cout<<V[0]<<endl;


	}
}