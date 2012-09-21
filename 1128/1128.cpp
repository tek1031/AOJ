#include<iostream>
#include<vector>
using namespace std;

class square{
public:
	int x,y,size;
	square(int x,int y,int size):x(x),y(y),size(size){}
	square(){}
};

bool is_hold(square a,square b){//b‚ªa‚ÉŠÜ‚Ü‚ê‚Ä‚¢‚é‚©‚ð”»’è
	if(b.x<a.x) return false;
	if(a.x+a.size<b.x+b.size) return false;

	if(b.y<a.y) return false;
	if(a.y+a.size<b.y+b.size) return false;
	return true;
}

int W,H;
bool in(int x,int y){
	if(x<0 || y<0 || x>=W || y>=H) return false;
	return true;

}

int main()
{
	while(cin>>W>>H && W!=0){
		vector<vector<bool> > dirty(W,vector<bool>(H,false));
		for(int y=0;y<H;y++){
			for(int x=0;x<W;x++){
				int t;cin>>t;
				if(t==1)dirty[y][x]=true;
			}
		}
		vector<square> V;

		for(int x=0;x<W;x++){
			for(int y=0;y<H;y++){
				bool ok=true;
				for(int size=0;size<min(H,W);size++){



				}
			}
		}


	}
	return 0;
}