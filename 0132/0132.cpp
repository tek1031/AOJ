#include<iostream>
#include<string>
#include<vector>
using namespace std;

int H,W;

typedef vector<string> P;

P V;
vector<P> K;
vector<int> Ans;
int n;

bool same[20][20];

P fill(P All,int ny,int nx,int k,int r){

	int h=K[k].size(),w=K[k][0].size();
	P temp;
	if(r==0) temp=K[k];
	if(r==1){
		for(int x=w-1;x>=0;x--){
			string s="";
			for(int y=0;y<h;y++)
				s+=K[k][y][x];
			temp.push_back(s);
		}
	}
	if(r==2){
		for(int y=h-1;y>=0;y--){
			string s="";
			for(int x=w-1;x>=0;x--)
				s+=K[k][y][x];
			temp.push_back(s);
		}
	}
	if(r==3){
		for(int x=0;x<w;x++){
			string s="";
			for(int y=h-1;y>=0;y--)
				s+=K[k][y][x];
			temp.push_back(s);
		}
	}
	int sy=0,sx=0,count=0;
	while(temp[sy][sx]!='#'){count++;sx++;}
	nx-=count;

	for(int y=0;y<temp.size();y++)
		for(int x=0;x<temp[y].size();x++){
			if(ny+y<0 || nx+x<0 || ny+y>=H || nx+x>=W){return P(1,"");}
			if(temp[y][x]!='#') continue;
			if(All[ny+y][nx+x]=='#')  return P(1,"");
			All[ny+y][nx+x]='#';
		}

		return All;
}

void check(P All,int y,int x,int bit){
	if(All[y][x]=='#'){
		if(y==H-1 && x==W-1){Ans.push_back(bit); return;}
		if(x==W-1)check(All,y+1,0,bit);
		else check(All,y,x+1,bit);
	}
	else{
		for(int i=0;i<n;i++){
			int nb=1<<i;
			if(bit&nb) continue;

			bool ok=true;
			for(int j=0;j<i;j++)
				if(same[j][i] && !(bit&1<<j)){
					ok=false;
					break;
				}
			if(!ok) break;

			for(int r=0;r<4;r++){
				P next=fill(All,y,x,i,r);
				if(next[0].size()==0) continue;
				check(next,y,x,nb|bit);
			}
		}
	}
}


void solve()
{
	V.clear();
	V.resize(H);
	Ans.clear();
	memset(same,false,sizeof(same));
	for(int i=0;i<H;i++){
		string s; cin>>s; V[i]=s;
	}
	cin>>n; K.clear(); K.resize(n);
	for(int i=0;i<n;i++){
		int h,w; cin>>h>>w;
		string s;
		K[i].resize(h);
		for(int y=0;y<h;y++){cin>>s;K[i][y]=s;}
	}

	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			if(K[i]==K[j]){
				same[i][j]=true;
				same[j][i]=true;
			}
		}

	check(V,0,0,0);

	int T;cin>>T;
	for(int i=0;i<T;i++){
		int num;cin>>num;
		vector<int> test;
		int bit=0;
		for(int j=0;j<num;j++){int temp;cin>>temp;bit=bit|1<<(temp-1);}
		bool ok=false;
		for(int j=0;j<Ans.size();j++){
			if(Ans[j]==bit) ok=true;
		}
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
	}

}


int main()
{
	while(cin>>H>>W){
		if(H==0) break;
		solve();
	}
	return 0;
}
