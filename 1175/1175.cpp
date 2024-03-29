#include<iostream>
#include<string.h>
using namespace std;

class Disc{//円盤の情報を表すクラス
public:
	int x,y,r,c;
	Disc(int x,int y,int r,int c): x(x),y(y),r(r),c(c){}
	Disc(){};
};

int n;//円盤の枚数
char memo[1<<24];//メモDp
bool exist[24];//円盤が残ってるかどうか
Disc D[24];//円盤を入れる配列
int ans;//答えを入れる

bool touch(Disc a,Disc b){//2枚の円盤が重なっているか　二乗にすれば誤差を気にしなくてもよい
	return (a.r+b.r)*(a.r+b.r)>(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool top(int k){//k番目の円盤の上に他の円盤が乗っていないか
	for(int i=k-1;i>=0;i--){
		if(exist[i]){
			if(touch(D[k],D[i])){return false;}
		}
	}
	return true;
}

int dfs(int bit,int num){//メモ化して深さ優先
	if(memo[bit]>=0) return memo[bit];
	int res=num;

	for(int i=0;i<n;i++){
		if(exist[i] && top(i)){
			for(int j=i+1;j<n;j++){//j=0 にしたらTLEした
				//j番目の円盤が存在して，上に他の円盤が乗ってなくて，i番目の円盤と色が一緒
				if(exist[j] && top(j) && i!=j && D[i].c==D[j].c){
					exist[i]=false;//取り除く
					exist[j]=false;
					res=dfs((bit&(~(1<<i)))&(~(1<<j)),num+2);
					exist[i]=true;//戻す
					exist[j]=true;
				}
			}
		}
	}
	memo[bit]=res;//メモる
	ans=max(ans,res);
	return res;
}

int main()
{
	while(cin>>n && n!=0){
		memset(memo,-1,sizeof(memo));
		memset(exist,true,sizeof(exist));
		for(int i=0;i<n;i++){
			int x,y,r,c;
			cin>>x>>y>>r>>c;
		D[i]=Disc(x,y,r,c);
		}
		ans=0;
		dfs((1<<24)-1,0);
		cout<<ans<<endl;
	}
	return 0;
}