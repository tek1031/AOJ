#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int h,w,s;
int cost[32][32];//コストを入れておく
int sum[33][33];//累積和
int num[32][32][32][32];//エリアの個数の合計　メモ
int cap[32][32][32][32];//予備力　メモ
int M;//最低でもこれだけ停電させないと　だめ

int calc_sum(int x1,int y1,int x2,int y2){//[x1,x2] [y1,y2]の合計を累積和で計算
	x1++;y1++;x2++;y2++;
	return sum[y2][x2]-sum[y2][x1-1]-sum[y1-1][x2]+sum[y1-1][x1-1];
}

typedef pair<int,int> A;//ペアで解を表す　first エリアの個数　second　予備力のmin

A dfs(int x1,int y1,int x2,int y2){
	if(num[y1][x1][y2][x2]>=0) return make_pair(num[y1][x1][y2][x2],cap[y1][x1][y2][x2]);//メモってた
	if(calc_sum(x1,y1,x2,y2)<M) return make_pair(0,10000000);//このエリアの合計がMを満たないので個数0
	A res=make_pair(1,calc_sum(x1,y1,x2,y2)-M);//何も分割しない場合

	for(int x=x1;x+1<=x2;x++){//縦に分割
		if(calc_sum(x1,y1,x,y2)<M || calc_sum(x+1,y1,x2,y2)<M) continue;
		A ans1=dfs(x1,y1,x,y2);
		A ans2=dfs(x+1,y1,x2,y2);
		A temp=make_pair(ans1.first+ans2.first,min(ans1.second,ans2.second));
		if(temp.first>res.first) res=temp;
		else if(temp.first==res.first && temp.second>res.second) res=temp;
	}

	for(int y=y1;y+1<=y2;y++){//横に分割
		if(calc_sum(x1,y1,x2,y)<M || calc_sum(x1,y+1,x2,y2)<M) continue;
		A ans1=dfs(x1,y1,x2,y);
		A ans2=dfs(x1,y+1,x2,y2);
		A temp=make_pair(ans1.first+ans2.first,min(ans1.second,ans2.second));
		if(temp.first>res.first) res=temp;
		else if(temp.first==res.first && temp.second>res.second) res=temp;
	}
	num[y1][x1][y2][x2]=res.first;//メモ化
	cap[y1][x1][y2][x2]=res.second;
	
	return res;
}

void solve()
{
	memset(num,-1,sizeof(num));
	memset(sum,0,sizeof(sum));
	for(int y=1;y<=h;y++){//入力，累積和計算
		for(int x=1;x<=w;x++){
			int t;cin>>t; 
			cost[y-1][x-1]=t;
			sum[y][x]=sum[y][x-1];
			sum[y][x]+=cost[y-1][x-1];
		}
	}

	for(int x=1;x<=w;x++){//累積和計算
		for(int y=1;y<=h;y++){
			sum[y][x]+=sum[y-1][x];
		}
	}

	M=calc_sum(0,0,w-1,h-1)-s;//最低でもMだけ停電させないとやばい
	A Ans=dfs(0,0,w-1,h-1);
	cout<<Ans.first<<" "<<Ans.second<<endl;
}

int main()
{
	while(cin>>h>>w>>s && !(h==0 && w==0 && s==0)){
		solve();
	}
	return 0;
}