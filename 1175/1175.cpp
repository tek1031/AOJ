#include<iostream>
#include<string.h>
using namespace std;

class Disc{//�~�Ղ̏���\���N���X
public:
	int x,y,r,c;
	Disc(int x,int y,int r,int c): x(x),y(y),r(r),c(c){}
	Disc(){};
};

int n;//�~�Ղ̖���
char memo[1<<24];//����Dp
bool exist[24];//�~�Ղ��c���Ă邩�ǂ���
Disc D[24];//�~�Ղ�����z��
int ans;//����������

bool touch(Disc a,Disc b){//2���̉~�Ղ��d�Ȃ��Ă��邩�@���ɂ���Ό덷���C�ɂ��Ȃ��Ă��悢
	return (a.r+b.r)*(a.r+b.r)>(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool top(int k){//k�Ԗڂ̉~�Ղ̏�ɑ��̉~�Ղ�����Ă��Ȃ���
	for(int i=k-1;i>=0;i--){
		if(exist[i]){
			if(touch(D[k],D[i])){return false;}
		}
	}
	return true;
}

int dfs(int bit,int num){//���������Đ[���D��
	if(memo[bit]>=0) return memo[bit];
	int res=num;

	for(int i=0;i<n;i++){
		if(exist[i] && top(i)){
			for(int j=i+1;j<n;j++){//j=0 �ɂ�����TLE����
				//j�Ԗڂ̉~�Ղ����݂��āC��ɑ��̉~�Ղ�����ĂȂ��āCi�Ԗڂ̉~�ՂƐF���ꏏ
				if(exist[j] && top(j) && i!=j && D[i].c==D[j].c){
					exist[i]=false;//��菜��
					exist[j]=false;
					res=dfs((bit&(~(1<<i)))&(~(1<<j)),num+2);
					exist[i]=true;//�߂�
					exist[j]=true;
				}
			}
		}
	}
	memo[bit]=res;//������
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