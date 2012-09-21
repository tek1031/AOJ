#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

class C{
public:
	int x,y;
	C(int x,int y):x(x),y(y){}
};
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

int w,h;

bool in(int x,int y){
	if(x<0 || y<0 || x>=w || y>=h) return false;
	return true;
}

long long int dist_goal[500][500],dist_spring[500][500];

const long long INF=10000000000LL;

int main()
{
/*	double m=1000000000000.0;
	for(int i=0;i<1000;i++){
		cout<<m<<endl;
		m/=2.0;
	}*/

	cin>>w>>h;
	int gx,gy,sx,sy;
	vector<string> M(h);
	vector<C> spring;
	long long num_normal=0;
	for(int i=0;i<h;i++){
		cin>>M[i];
		for(int j=0;j<M[i].size();j++){
			if(M[i][j]=='s'){sx=j;sy=i;num_normal++;}
			if(M[i][j]=='g'){gx=j;gy=i;}
			if(M[i][j]=='*'){spring.push_back(C(j,i));}
			if(M[i][j]=='.'){num_normal++;}
		}
	}

	for(int i=0;i<500;i++)
		for(int j=0;j<500;j++){
			dist_goal[i][j]=INF;
			dist_spring[i][j]=INF;
		}

	bool visit[500][500];
	memset(visit,false,sizeof(visit));

	queue<pair<C,int> > que;
	que.push(make_pair(C(gx,gy),0));

	while(!que.empty()){
		C now=que.front().first;
		int cost=que.front().second;
		que.pop();
		if(!in(now.x,now.y)) continue;
		if(M[now.y][now.x]=='#' || M[now.y][now.x]=='*') continue;
		if(visit[now.y][now.x]) continue;
		visit[now.y][now.x]=true;
		dist_goal[now.y][now.x]=cost;
		for(long long r=0;r<4;r++){
			que.push(make_pair(C(now.x+dx[r],now.y+dy[r]),cost+1));
		}
	}
	
	for(long long i=0;i<spring.size();i++)
		que.push(make_pair(C(spring[i].x,spring[i].y),0));
	memset(visit,false,sizeof(visit));
	while(!que.empty()){
		C now=que.front().first;
		long long cost=que.front().second;
		que.pop();
		if(!in(now.x,now.y)) continue;
		if(M[now.y][now.x]=='#') continue;
		if(visit[now.y][now.x]) continue;
		visit[now.y][now.x]=true;
		dist_spring[now.y][now.x]=cost;
		for(int r=0;r<4;r++){
			que.push(make_pair(C(now.x+dx[r],now.y+dy[r]),cost+1));
		}
	}

	const int NUM=1000;
	long double upper=1e20,lower=0.0;
	for(int t=0;t<NUM;t++){
		long double sum=0.0;
		long double E=(upper+lower)/2.0;
		vector<long double> work;
		for(int y=0;y<h;y++){
			for(int x=0;x<w;x++){
				if(M[y][x]!='.' && M[y][x]!='s') continue;
				if(dist_goal[y][x]<INF) work.push_back(min((double)dist_goal[y][x],(double)dist_spring[y][x]+(double)E));
				else work.push_back(dist_spring[y][x]+E);
			}
		}
//		sort(work.begin(),work.end());
		for(int i=0;i<work.size();i++)
			sum+=work[i];
//		cout<<sum/num_normal<<endl;
		if(sum/num_normal<E) upper=E-1e-10;
		else lower=E+1e-10;
	}
//	cout<<min((double)dist_goal[sy][sx],(upper+lower)/2.0+dist_spring[sy][sx])<<endl;
	printf("%.13lf\n",min((double)dist_goal[sy][sx],(double)(upper+lower)/2.0+dist_spring[sy][sx]));
	return 0;
}
