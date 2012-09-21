#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class line{
public:
	int h,p,q;
	line(int h,int p,int q):h(h),p(p),q(q){}
};

bool operator < (line a,line b){
	return a.h>b.h;
}

int main()
{
	int n,m,a;
	while(cin>>n>>m>>a && n!=0){
		vector<line> L;
		for(int i=0;i<m;i++){
			int h,p,q; cin>>h>>p>>q;
			L.push_back(line(h,p,q));
		}
		sort(L.begin(),L.end());

		int now=a;
		for(int i=0;i<L.size();i++){
			if(L[i].p==now) now=L[i].q;
			else if(L[i].q==now) now=L[i].p;
		}
		cout<<now<<endl;
	}
	return 0;
}