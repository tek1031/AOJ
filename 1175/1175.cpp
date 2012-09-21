#include<iostream>
#include<string.h>
using namespace std;

class Disc{//‰~”Õ‚Ìî•ñ‚ğ•\‚·ƒNƒ‰ƒX
public:
	int x,y,r,c;
	Disc(int x,int y,int r,int c): x(x),y(y),r(r),c(c){}
	Disc(){};
};

int n;//‰~”Õ‚Ì–‡”
char memo[1<<24];//ƒƒ‚Dp
bool exist[24];//‰~”Õ‚ªc‚Á‚Ä‚é‚©‚Ç‚¤‚©
Disc D[24];//‰~”Õ‚ğ“ü‚ê‚é”z—ñ
int ans;//“š‚¦‚ğ“ü‚ê‚é

bool touch(Disc a,Disc b){//2–‡‚Ì‰~”Õ‚ªd‚È‚Á‚Ä‚¢‚é‚©@“ñæ‚É‚·‚ê‚ÎŒë·‚ğ‹C‚É‚µ‚È‚­‚Ä‚à‚æ‚¢
	return (a.r+b.r)*(a.r+b.r)>(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool top(int k){//k”Ô–Ú‚Ì‰~”Õ‚Ìã‚É‘¼‚Ì‰~”Õ‚ªæ‚Á‚Ä‚¢‚È‚¢‚©
	for(int i=k-1;i>=0;i--){
		if(exist[i]){
			if(touch(D[k],D[i])){return false;}
		}
	}
	return true;
}

int dfs(int bit,int num){//ƒƒ‚‰»‚µ‚Ä[‚³—Dæ
	if(memo[bit]>=0) return memo[bit];
	int res=num;

	for(int i=0;i<n;i++){
		if(exist[i] && top(i)){
			for(int j=i+1;j<n;j++){//j=0 ‚É‚µ‚½‚çTLE‚µ‚½
				//j”Ô–Ú‚Ì‰~”Õ‚ª‘¶İ‚µ‚ÄCã‚É‘¼‚Ì‰~”Õ‚ªæ‚Á‚Ä‚È‚­‚ÄCi”Ô–Ú‚Ì‰~”Õ‚ÆF‚ªˆê
				if(exist[j] && top(j) && i!=j && D[i].c==D[j].c){
					exist[i]=false;//æ‚èœ‚­
					exist[j]=false;
					res=dfs((bit&(~(1<<i)))&(~(1<<j)),num+2);
					exist[i]=true;//–ß‚·
					exist[j]=true;
				}
			}
		}
	}
	memo[bit]=res;//ƒƒ‚‚é
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