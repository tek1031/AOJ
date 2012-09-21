#include<iostream>
#include<vector>
#include<string>
using namespace std;

int W,H;
int dx[4]={1,0,-1,0};//いつもの
int dy[4]={0,1,0,-1};

struct Cor{//座標を表す
	int x,y;
	Cor(int para_x,int para_y){
		x=para_x;
		y=para_y;
	}
};

bool in(int x,int y){//範囲内ならtrue
	if(x<0 || y<0 || x>=W || y>=H)
		return false;
	 return true;
}

void upper(int x,int y,char c,vector<string> &M,vector<vector<bool> > &visit,vector<Cor> &C){
	//上にブロックがあると呼び出される
	//着目しているブロックの数字がcで表される

	if(!in(x,y)) return; //外でした
	if(visit[y][x]) return;  //もうきたぜ
	if(M[y][x]!=c) return;  //違うブロックだよ
	visit[y][x]=true;
	

	C.push_back(Cor(x,y));//今まで通ったブロックに追加するぜ

	for(int r=0;r<4;r++){//隣接した同じ種類のブロックがあったら、もう一回呼び出す
		int nx=x+dx[r],ny=y+dy[r];
		if(in(nx,ny) && M[ny][nx]==c)
			upper(nx,ny,M[ny][nx],M,visit,C);
	}

	if(in(x,y-1) && isdigit(M[y-1][x]) && M[y-1][x]!=c){//上にブロックがあったら、そのブロックに着目して呼び出す
		upper(x,y-1,M[y-1][x],M,visit,C);
	}
}

void start(int x,int y,char c,vector<string> &M,vector<vector<bool> > &visit,vector<Cor> &C,int &left,int &right,vector<vector<bool> > &checked){
	//最初に着目したブロックについて
	if(!in(x,y)) return; //外でした
	if(visit[y][x]) return;  //もうきたぜ
	if(M[y][x]!=c) return;  //違うブロックだよ
	if(checked[y][x]) return;
	visit[y][x]=true;  //きましたよ！
	checked[y][x]=true;


	C.push_back(Cor(x,y));//今まで通ったブロックに追加するぜ
	if(!in(x,y+1)){ //地面だ！
		left=min(left,x); //左の値を更新
		right=max(right,x);  //右の値もね！
	}
	else{
		if(isdigit(M[y+1][x]) && M[y+1][x]!=c){//違うブロックでした！
			left=min(left,x);// 更新！
			right=max(right,x);
		}
	}

	for(int r=0;r<4;r++){//周囲4マスに同じブロックがないか見てみる
		int nx=x+dx[r],ny=y+dy[r];
		if(!in(nx,ny)) continue;
		if(M[ny][nx]==M[y][x])
			start(nx,ny,M[ny][nx],M,visit,C,left,right,checked);//見つかったら、呼び出す
	}

	if(in(x,y-1) && !visit[y-1][x] && isdigit(M[y-1][x]) && M[y-1][x]!=c){//上に違うブロックがありますか?
		upper(x,y-1,M[y-1][x],M,visit,C);
	}

}

void solve(){
	vector<string> M;
	for(int i=0;i<H;i++){
		string s;
		cin>>s;
		M.push_back(s);
	}

	vector<vector<bool> > checked(H,vector<bool>(W,false));
	for(int y=0;y<H;y++){
		for(int x=0;x<W;x++){
			if(checked[y][x]) continue;
			if(M[y][x]!='.'){
				vector<Cor> C;  //重心を求めたいブロックの塊を入れておく
				int left=10000,right=0;
				vector<vector<bool> > visit(H,vector<bool>(W,false));
				start(x,y,M[y][x],M,visit,C,left,right,checked);

				double sum_x=0;
				for(int n=0;n<C.size();n++){//重心を計算して
					sum_x+=C[n].x+0.5;
				}


				double g=double(sum_x)/C.size();


				if(!(left < g && g < right+1)){ //だめでした
					cout<<"UNSTABLE\n";
					return;
				}
			}
		}
	}
	cout<<"STABLE\n";
}

int main()
{
	while(cin>>W>>H){
		if(W==0) break;
		solve();
	}
	return 0;
}
