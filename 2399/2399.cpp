//hogehgoe

//#include<gchost.h>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include<queue>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;

int main()
{
	int N;
	while(cin>>N && N!=0){
		vector<vector<int> > V(N);
		for(int i=0;i<N;i++){
			int M;
			cin>>M;
			for(int j=0;j<M;j++){
				int t; cin>>t;
				V[i].push_back(t);
			}
		}

		vector<int> target;
		int K; cin>>K;
		for(int i=0;i<K;i++){
			int t;cin>>t;
			target.push_back(t);
		}

		int ans=-1,num=0;

		for(int i=0;i<N;i++){
			bool ok=false;
			for(int k=0;k<K;k++){
				ok=false;
				for(int idx=0;idx<V[i].size();idx++){
					if(V[i][idx]==target[k]){ok=true;break;}
				}
				if(!ok) break;
			}
			if(ok){ans=i;num++;}
		}
		if(num!=1) cout<<-1<<endl;
		else cout<<ans+1<<endl;
	}
	return 0;
}
