#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class hist{//‹æŠÔ‚ð•\‚·
public:
	int s,e;
	hist(int s,int e):s(s),e(e){};
};

bool operator < (hist a,hist b){
	if(a.s!=b.s) return a.s<b.s;
	return a.e<b.e;
}

int main()
{
	int N,M;
	while(cin>>N>>M && N!=0){
		vector<int> PC(N+1,-1);
		vector<vector<hist> > Stu(M+1);
		int r;
		cin>>r;
		for(int i=0;i<r;i++){
			int t,n,m,s;
			cin>>t>>n>>m>>s;
			if(s==0)
				Stu[m].push_back(hist(PC[n],t));
			else{
				PC[n]=t;
			}
		}
		int q;
		cin>>q;
		for(int i=0;i<q;i++){
			int s,e,m;
			cin>>s>>e>>m;
			sort(Stu[m].begin(),Stu[m].end());
			int ans=0;
			int time=s;
			for(int k=0;k<Stu[m].size();k++){
				if(min(Stu[m][k].e,e)-max(time,Stu[m][k].s)<0) continue;
				ans+=min(Stu[m][k].e,e)-max(time,Stu[m][k].s);
				time=min(Stu[m][k].e,e);
			}
			cout<<ans<<endl;
		}
	}
}
