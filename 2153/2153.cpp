#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


class state{
public:
	int rx,ry,lx,ly;
	state(int lx,int ly,int rx,int ry):lx(lx),ly(ly),rx(rx),ry(ry){}
};

int w,h;

bool in(int x,int y)
{
	if(x<0 || x>=w || y<0 || y>=h) return false;
	return true;
}

bool done[50][50][50][50];
		


int main(){
	while(cin>>w>>h && w!=0){
		vector<string> L(h),R(h);
		int flx,fly,frx,fry;
		for(int i=0;i<h;i++){
			cin>>L[i]>>R[i];
			for(int k=0;k<L[i].size();k++){
				if(L[i][k]=='L'){flx=k;fly=i;}
				if(R[i][k]=='R'){frx=k;fry=i;}
			}
		}
		memset(done,false,sizeof(done));
		queue<state> Q;
		Q.push(state(flx,fly,frx,fry));
		bool ok=false;
		while(!Q.empty()){
			state t=Q.front(); Q.pop();
			if(L[t.ly][t.lx]=='%' && R[t.ry][t.rx]=='%'){cout<<"Yes"<<endl;ok=true;break;}
			if(L[t.ly][t.lx]=='%' || R[t.ry][t.rx]=='%') continue;
			if(done[t.lx][t.ly][t.rx][t.ry]) continue;
			done[t.lx][t.ly][t.rx][t.ry]=true;

			for(int r=0;r<4;r++){
				int nlx=t.lx+dx[r],nly=t.ly-dy[r];
				if(!in(nlx,nly) || L[nly][nlx]=='#'){nlx=t.lx;nly=t.ly;}

				int nrx=t.rx+dx[(r+2)%4],nry=t.ry+dy[(r+2)%4];
				if(!in(nrx,nry) || R[nry][nrx]=='#'){nrx=t.rx;nry=t.ry;}
				Q.push(state(nlx,nly,nrx,nry));
			}
		}
		if(!ok)
			cout<<"No"<<endl;
	}
	return 0;
}
