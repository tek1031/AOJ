#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
int w,h;

int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={-1,-1,0,1,1,1,0,-1};

void solve(){
	set<string> S;
	vector<string> V;
	for(int i=0;i<h;i++){
		string s;
		cin>>s;
		V.push_back(s);
	}
	string res="";

	for(int y=0;y<h;y++){
		for(int x=0;x<w;x++){
			for(int r=0;r<8;r++){
				int nx=x,ny=y;
				string read="";
				while(!(nx==x && ny==y) || read.size()==0){
					read+=V[ny][nx];
					if(S.count(read)){
						if(res.size()<read.size()) res=read;
						if(res.size()==read.size() && res>read) res=read;
					}
					S.insert(read);
					ny+=dy[r];
					nx+=dx[r];
					if(ny<0) ny=h-1;
					if(ny>=h) ny=0;
					if(nx<0) nx=w-1;
					if(nx>=w) nx=0;
				}
			}
		}
	}
	if(res.size()>1)
		cout<<res<<endl;
	else cout<<0<<endl;
}



int main()
{
	while(cin>>h>>w){
		if(h==0) break;
		solve();
	}
	return 0;
}
