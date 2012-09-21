#include<iostream>
#include<vector>
using namespace std;

int W,H;
int count=0;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


vector<vector<char> > M;

void go(int x,int y){
	if(x<0 || y<0 || x>=W || y>=H) return;
	if(M[y][x]=='.' || M[y][x]=='@'){
		count++;
		M[y][x]='#';
		for(int r=0;r<4;r++){
			go(x+dx[r],y+dy[r]);
		}
	}
}

void solve(){
	count=0;

	M.clear();
	M.resize(H,vector<char>(W));

	int sx,sy;
	for(int y=0;y<H;y++){
		for(int x=0;x<W;x++){
			char t;
			cin>>t;
			M[y][x]=t;
			if(t=='@'){
				sx=x;sy=y;
			}
		}
	}

	go(sx,sy);
	cout<<count<<endl;

}


int main(){
	while(cin>>W>>H){
		if(W==0) return 0;
		solve();
	}
}