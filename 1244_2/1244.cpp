#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string,int> idx;//原子量を検索する
int p;//現在読み込む位置

int calc(string s){//構文解析を始める
	int res=0;
	while(p<s.size()){//終わりにくるまで続行
		if(s[p]==')'){p++; break;}//もし')'を読み込んだら　ポインタを進めてbreak
		int weight=0;//読み込んだ原子量
		string f;//読み込む原子を入れる
		if(isupper(s[p])){//大文字だったらそのまま読み込む
			f+=s[p];p++;
			if(p<s.size() && islower(s[p])){//次に小文字がきたらfに追加
				f+=s[p]; p++;
			}
			if(!idx.count(f)) return -1;//知らない原子がきたら負の値を返す
			weight=idx[f];//そうでなければweightに入れる
		}
		else if(s[p]=='('){//'('を読み込んだら再帰で括弧内の原子の重さを読む
			p++;//'('の次の文字に移る
			weight=calc(s);
			if(weight<0) return -1;//負の値が帰ってきたら負の値を返す
		}
		int mul=0;
		while(p<s.size() && isdigit(s[p])){//数字を読む
			mul*=10;
			mul+=s[p]-'0';
			p++;
		}
		if(mul==0) mul=1;//数字がなかったとき
		res+=weight*mul;
	}
	return res;
}

int main()
{
	string s;
	while(cin>>s){
		if(s.size()>=3) break;
		int w; cin>>w;
		idx[s]=w;
	}
	while(cin>>s){
		if(s=="0") break;
		p=0;
		int ans=calc(s);
		if(ans<0) cout<<"UNKNOWN"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
