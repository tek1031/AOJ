#include<iostream>
#include<vector>
using namespace std;

int n;

void solve(){
	vector<vector<int> > V(n,vector<int>(n));
	for(int y=0;y<n;y++){
		for(int x=0;x<n;x++){
			int n;
			cin>>n;
			V[y][x]=n;
		}
	}

	for(int y=0;y<n;y++){
		int a=0;
		for(int x=0;x<n;x++){
			cout<<V[y][x]<<" ";
			a+=V[y][x];
		}
		cout<<a;
	}

	for(int 


}
int main()
{
	while(cin>>n){
		if(n==0) break;
		solve();
	}
	return 0;
}
