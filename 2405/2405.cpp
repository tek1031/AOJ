#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

const int MOD=1000003;
int N,M;
vector<vector<int> > L;
int ans=0;
map<pair<int,int> ,int> memo;


long long calc(int start,int end){
//	cout<<"do "<<start<<" "<<end<<endl;
	if((end-start)%2==0) return 0;
	if(start>end) return 1;//I‚í‚è‚Ü‚Å‚«‚½‚ç‚»‚Ì‚Ü‚ÜˆêT•ª
	if(memo.count(make_pair(start,end))) return memo[make_pair(start,end)];
	long long res=0;

	int now=start;
	if(L[now].size()==0){
		while(now<=end && L[now].size()==0) now+=2;
		return calc(now,end);
	}
	else{
		for(int k=0;k<L[now].size();k++){
			res+=(calc(now+1,L[now][k]-1)*calc(L[now][k]+1,end))%MOD;
			res%=MOD;
		}
	}
	res+=calc(now+2,end);
	res%=MOD;
	memo[make_pair(start,end)]=res;
//	cout<<"res "<<start<<" "<<end<<" :"<<res<<endl;
	return res%MOD;
}

int main()
{
	while(cin>>N>>M && N!=0){
		memo.clear();
		L.clear();
		L.resize(N,vector<int>());

		for(int i=0;i<M;i++){
			int in,out;cin>>in>>out;
			in--;out--;
			if(in<out)
				L[in].push_back(out);
			else
				L[out].push_back(in);
		}
		for(int i=0;i<N;i++){
			sort(L[i].begin(),L[i].end());
			L[i].erase(unique(L[i].begin(),L[i].end()),L[i].end());
		}
		cout<<(calc(0,N-1)+calc(1,N-2))%MOD<<endl;
	}
}


