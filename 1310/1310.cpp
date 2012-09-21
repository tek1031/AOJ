#include<iostream>
#include<vector>
#include<map>

using namespace std;

int N,S,W,Q;

int a[100000];

void solve(){

	unsigned int res=0;
	map<int,int> M;
	M.clear();

    int g = S;
    for(int i=0; i<N; i++) {
        a[i] = (g/7) % 10;
        if( g%2 == 0 ) { g = (g/2); }
        else           { g = (g/2) ^ W; }
    }

	if(Q==2 || Q==5){
		int count=0;
		for(int i=N-1;i>=0;i--){
			if(a[i]%Q==0)
				count++;
			if(a[i]!=0)
				res+=count;
		}
		cout<<res<<endl; return;
	}


	res=0;
	int mul=1;
	int bef=0;

	for(int i=N-1;i>=0;i--){
		bef=(a[i]*mul+bef)%Q;
		if(a[i]!=0){
			if(bef==0) res++;
			res+=M[bef];
		}
		if(!M.count(bef)) M[bef]=1;
		else
			M[bef]++;
	
		mul=(10*mul)%Q;
	}
	cout<<res<<endl;
}

int main(){

	while(cin>>N>>S>>W>>Q){
		if(N==0 && S==0 && W==0 && Q==0) break;
		solve();
	}
	return 0;
}