#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

vector<string> M;
int H,W;
int c_to_int[26];
char int_to_c[7];
int num;

vector<vector<vector<char> > > E;

bool pre_check(){
	E.clear();
	E.resize(H,vector<vector<char> > (W,vector<char>()));

	for(int k=0;k<num;k++){
		char now=int_to_c[k];
		int minx=100,maxx=0,miny=100,maxy=0;
		for(int y=0;y<H;y++){
			for(int x=0;x<W;x++){
				if(M[y][x]==now){
					maxx=max(maxx,x);minx=min(minx,x);
					maxy=max(maxy,y);miny=min(miny,y);
				}
			}
		}
		for(int y=miny;y<=maxy;y++){
			for(int x=minx;x<=maxx;x++){
				if(M[y][x]=='.') return false;
				E[y][x].push_back(now);
			}
		}
	}

	return true;
}

bool check(vector<int> perm){
	for(int y=0;y<H;y++){
		for(int x=0;x<W;x++){
			if(M[y][x]=='.') continue;
			int top=c_to_int[M[y][x]];
			for(int i=0;i<E[y][x].size();i++){
				if(E[y][x].size()<2) continue;
				int now=c_to_int[E[y][x][i]];
				if(perm[top]>perm[now]) return false;
			}
		}
	}


	return true;
}

bool solve(){
	cin>>H>>W;
	M.clear();
	set<char> S;
	num=0;

	for(int i=0;i<H;i++){
		string s; cin>>s; M.push_back(s);
		for(int k=0;k<s.size();k++){
			if(!S.count(s[k]) && s[k]!='.'){
				S.insert(s[k]);
				c_to_int[s[k]]=num;
				int_to_c[num]=s[k];
				num++;
			}
		}
	}


	if(!pre_check()) return false;
	if(num<2) return true;
	vector<int> perm;
	for(int i=0;i<num;i++) perm.push_back(i);
	sort(perm.begin(),perm.end());

	while(next_permutation(perm.begin(),perm.end())){
		if(check(perm)) return true;
	}
	return false;
}


int main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++){
		if(solve()) cout<<"SAFE\n";
		else cout<<"SUSPICIOUS\n";
	}
	return 0;
}

