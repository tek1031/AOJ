#include<iostream>
#include<string>
#include<vector>
#include<string.h>
using namespace std;

int h,w;

bool is_next[2][50][50];
vector<string> M;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void dfs(int x,int y,int is_black){
	if(x<0 || y<0 || x>=w || y>=h) return;
	if(M[y][x]!='.') return;
	if(is_next[is_black][y][x]) return;
	is_next[is_black][y][x]=true;

	for(int r=0;r<4;r++)
		dfs(x+dx[r],y+dy[r],is_black);
}

int main()
{
	while(cin>>w>>h && w!=0){
		M.clear();
		memset(is_next,false,sizeof(is_next));
		for(int i=0;i<h;i++){
			string s; cin>>s; M.push_back(s);
		}

		for(int y=0;y<h;y++){
			for(int x=0;x<w;x++){
				if(M[y][x]=='W'){
					for(int r=0;r<4;r++){
						dfs(x+dx[r],y+dy[r],1);
					}
				}
				else if(M[y][x]=='B'){
					for(int r=0;r<4;r++){
						dfs(x+dx[r],y+dy[r],0);
					}
				}
			}
		}

		int ans_b=0,ans_w=0;
		for(int y=0;y<h;y++){
			for(int x=0;x<w;x++){
				if(is_next[0][y][x] && !is_next[1][y][x]) ans_b++;
				if(is_next[1][y][x] && !is_next[0][y][x]) ans_w++;
			}
		}
		cout<<ans_b<<" "<<ans_w<<endl;
	}
	return 0;
}