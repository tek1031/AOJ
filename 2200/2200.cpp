#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int INF=100000000;


class Node{
public:
	int now_mission,ship,sum;
	Node(int now_mission,int ship,int sum):now_mission(now_mission),ship(ship),sum(sum){};
};

bool operator < (Node a,Node b){
	return a.sum>b.sum;
}


int main()
{
	int N,M;
	while(cin>>N>>M && N!=0){
		vector<vector<int> > dist_ground(N,vector<int>(N,INF));
		vector<vector<int> > dist_sea(N,vector<int>(N,INF));

		for(int i=0;i<M;i++){
			int x,y,t; char c;
			cin>>x>>y>>t>>c;
			x--;y--;
			if(c=='L'){
				dist_ground[x][y]=min(dist_ground[x][y],t);
				dist_ground[y][x]=min(dist_ground[y][x],t);
			}
			else{
				dist_sea[x][y]=min(dist_sea[x][y],t);
				dist_sea[y][x]=min(dist_sea[y][x],t);
			}
		}
		for(int i=0;i<N;i++){
			dist_sea[i][i]=dist_ground[i][i]=0;
		}
		int R;cin>>R;
		vector<int> mission(R);
		for(int i=0;i<R;i++){cin>>mission[i];mission[i]--;}


		for(int k=0;k<N;k++){
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					dist_sea[i][j]=min(dist_sea[i][j],dist_sea[i][k]+dist_sea[k][j]);
					dist_ground[i][j]=min(dist_ground[i][j],dist_ground[i][k]+dist_ground[k][j]);
				}
			}
		}
		
		vector<vector<int> > memo(R,vector<int>(N,INF));
		memo[0][mission[0]]=0;
		for(int i=1;i<R;i++){
			int area=mission[i-1];
			for(int j=0;j<N;j++){
				memo[i][j]=min(memo[i][j],memo[i-1][j]+dist_ground[area][mission[i]]);

				for(int k=0;k<N;k++){
					memo[i][j]=min(memo[i][j],
						memo[i-1][k]+dist_ground[area][k]+dist_sea[k][j]+dist_ground[j][mission[i]]
					);
				}
			}
		}

		int ans=INF;
		for(int i=0;i<N;i++){
			ans=min(ans,memo[R-1][i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}

