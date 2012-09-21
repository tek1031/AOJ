#include<iostream>
#include<string>
#include<vector>
using namespace std;
int h,w;
vector<vector<char> > V;

int res;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};


void go(int y,int x,char a){

	if(x<0 || y<0 || x>=w || y>=h ||V[y][x]!=a) return;
	V[y][x]='.';
	for(int r=0;r<4;r++)
		go(y+dy[r],x+dx[r],a);
}

void solve()
{
	V.clear();
	V.resize(h,vector<char>(w));
	res=0;
	for(int i=0;i<h;i++){
		string h;
		cin>>h;
		for(int j=0;j<w;j++)
			V[i][j]=h[j];
	}
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			if(V[i][j]!='.'){
				res++;
				go(i,j,V[i][j]);
			}
	cout<<res<<endl;
}

int main()
{
	while(cin>>h>>w){
		solve();
	}
	return 0;
}
