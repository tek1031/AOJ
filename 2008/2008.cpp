#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

int n,dx,dy,hx,hy;
bool done[20];
int cx[20],cy[20];

double calc(int x1,int y1,int x2,int y2){
	return sqrt((double)(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool dfs(int x,int y,double time,int k){
	if(time>=calc(x,y,dx,dy)) return false;
	if(k==n) return true;

	for(int i=0;i<n;i++){
		if(done[i]) continue;
		if(time+calc(x,y,cx[i],cy[i])>=calc(cx[i],cy[i],dx,dy)) return false;
	}

	for(int i=0;i<n;i++){
		if(done[i]) continue;
		if(dfs(cx[i],cy[i],time+calc(cx[i],cy[i],x,y),k+1)) return true;
	}
	return false;
}

int main()
{
	while(cin>>n>>hx>>hy>>dx>>dy && n!=0){
		for(int i=0;i<n;i++)
			cin>>cx[i]>>cy[i];
		memset(done,false,sizeof(done));
		if(dfs(hx,hy,0.0,0)) cout<<"YES\n";
		else cout<<"NO\n";

	}
	return 0;
}