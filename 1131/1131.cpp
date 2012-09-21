#include<iostream>
#include<vector>
#include<set>
using namespace std;

int p,q,a,n;
int ans=0;

class Fraction{//分数を表す
public:
	int bo,shi;//分母と分子
	Fraction(int shi,int bo):bo(bo),shi(shi){};
};

Fraction my_plus(Fraction a,Fraction b){//分数の足し算　約分するとTLEした
	int new_bo=a.bo*b.bo;
	int new_shi=a.shi*(new_bo/a.bo)+b.shi*(new_bo/b.bo);
	return Fraction(new_shi,new_bo);
}

void dfs(int num,int now_bo,int mul,Fraction now){
	if(p*now.bo<q*now.shi) return;//枝刈り　すでに目的の値よりも大きいので，これ以上何を足しても無駄
	if(num>n) return;//制限を超えた
	if(p*now.bo==q*now.shi){//値が一致
		ans++;
		return;
	}
	for(int i=now_bo;i<12000;i++){//次の値を足す
		if(mul*i>a) break;
		dfs(num+1,i,mul*i,my_plus(now,Fraction(1,i)));
	}
}


int main()
{
	while(cin>>p>>q>>a>>n && p!=0 && q!=0 && a!=0 && n!=0){
		ans=0;
		dfs(0,1,1,Fraction(0,2));
		cout<<ans<<endl;
	}
	return 0;
}