#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int main()
{
	int n;
	while(cin>>n && n!=0){
		bool can[50][31];
		memset(can,false,sizeof(can));
		for(int i=0;i<n;i++){
			int t;cin>>t;
			for(int j=0;j<t;j++){
				int k; cin>>k;can[i][k]=true;
			}
		}

		bool have[50][50];
		memset(have,false,sizeof(have));
		for(int i=0;i<n;i++)
			have[i][i]=true;

		bool print=false;
		for(int day=1;day<=30;day++){

			


			vector<int> meet;
			for(int k=0;k<n;k++)
				if(can[k][day]) meet.push_back(k);

			vector<int> share;
			for(int m=0;m<meet.size();m++){
				for(int k=0;k<n;k++){
					if(have[meet[m]][k]) share.push_back(k);
				}
			}

			for(int m=0;m<meet.size();m++){
				for(int s=0;s<share.size();s++){
					have[meet[m]][share[s]]=true;
				}
			}




			for(int i=0;i<n;i++){
				bool ok=true;
				for(int k=0;k<n;k++){
					if(!have[i][k]){ok=false;break;}
				}
				if(ok){cout<<day<<endl; print=true; break;}
			}
			if(print) break;
		}
		if(!print) cout<<-1<<endl;
	}
	return 0;
}