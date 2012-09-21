#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,w,d;

class Cake{//ケーキを表す
public:
	int x,y,id;
	Cake(int x,int y,int id):x(x),y(y),id(id){}
	Cake(){}
	int calc(){return x*y;}//面積を返す
};

int main()
{
	while(cin>>n>>w>>d && w!=0){
		vector<Cake> Now;//現在あるケーキ
		vector<Cake> Next;//カット後のケーキの集合
		Next.push_back(Cake(w,d,1));
		for(int turn=1;turn<=n;turn++){
			Now=Next;//取り換える
			Next.clear();
			int p,s;
			cin>>p>>s;
			for(int i=0;i<Now.size();i++){
				if(Now[i].id==p){//カット対象のケーキの場合
					Cake c1,c2;//カットした後のケーキ
					s%=Now[i].x+Now[i].y;//MODとって余分な分をとる
					if(s<Now[i].x){//縦に切る場合
						c1.y=c2.y=Now[i].y;
						c1.x=s;
						c2.x=Now[i].x-s;
					}
					else{//横に切る場合
						c1.x=c2.x=Now[i].x;
						c1.y=s-Now[i].x;
						c2.y=Now[i].y-(s-Now[i].x);
					}
					if(c1.calc()<c2.calc()){ c1.id=turn;c2.id=turn+1;}//面積に応じて番号を付ける
					else{c1.id=turn+1;c2.id=turn;}
					Next.push_back(c1);//次の集合に突っ込む
					Next.push_back(c2);
				}
				else{//それ以外のケーキ
					if(Now[i].id>p) Now[i].id--;//pよりもIDが大きいケーキはIDが１つ下がる
					Next.push_back(Now[i]);//突っ込む
				}
			}
		}
		vector<int> ans;//ベクタにぶち込んでソート出力
		for(int i=0;i<Next.size();i++)
			ans.push_back(Next[i].calc());
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++){
			cout<<ans[i];
			if(i!=ans.size()-1) cout<<" ";
		}
		cout<<endl;
		
	}
	return 0;
}