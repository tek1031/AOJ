#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int W,H;

vector<string> V;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int res;
typedef pair<int,int> Cor;

bool in(int y,int x){
	return !(y<0 || x<0 || y>=H || x>=W);
}
vector<vector<Cor> >Al(26);

void print(){
	cout<<endl;
	for(int y=0;y<H;y++){
		for(int x=0;x<W;x++)
			cout<<V[y][x];
		cout<<endl;
	}
}


bool kesu(int k){
	vector<vector<bool> > Check(H,vector<bool>(W,false));
	int y1=Al[k][0].first,x1=Al[k][0].second;
	int y2=Al[k][1].first,x2=Al[k][1].second;

	for(int r=0;r<4;r++){
		int y=y1+dy[r],x=x1+dx[r];
		while(in(y,x) && V[y][x]=='.'){Check[y][x]=true; y+=dy[r];x+=dx[r];}
	}

	for(int r=0;r<4;r++){
		int y=y2+dy[r],x=x2+dx[r];
		while(in(y,x) && V[y][x]=='.'){
			if(Check[y][x]){res++;V[y1][x1]=V[y2][x2]='.';return true;}
			Check[y][x]=true; y+=dy[r];x+=dx[r];
		}
	}
	return false;
}

void solve(){
	res=0;
	V.clear();
	Al.clear();
	Al.resize(26);
	for(int i=0;i<H;i++){
		string s;
		cin>>s;
		V.push_back(s);
	}

	vector<bool> ex(26,false);
	
	for(int y=0;y<H;y++){
		for(int x=0;x<W;x++){
			if(V[y][x]!='.'){
				int c=V[y][x]-'A';
				ex[c]=true;
				Al[c].push_back(make_pair(y,x));
			}
		}
	}

	bool update=true;
	while(update){
		update=false;
		for(int k=0;k<26;k++){
			if(!ex[k]) continue;
			bool kekka=kesu(k);
			ex[k]=!kekka;
			update=(update || kekka);
		}
	}
	cout<<res*2<<endl;
}

int main()
{
	while(cin>>H>>W){
		if(H==0) break;
		solve();
	}
	return 0;
}
