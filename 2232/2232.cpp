#include<iostream>
#include<vector>
#include<string>
using namespace std;

int h,w,n;

bool in(int x,int y){
	if(x<0 || x>=w || y<0 || y>=h) return false;
	return true;
}

void print(vector<string> M){
	for(int i=0;i<M.size();i++)
		cout<<M[i]<<endl;
	cout<<endl;
}

bool do_clear(vector<string> &M){
//	print(M);
	bool update=false;

	vector<vector<bool> > ok(h,vector<bool>(w,false));

	for(int y=0;y<h;y++){
		for(int x=0;x<w;x++){
			if(M[y][x]=='.') continue;
			char now=M[y][x];
			int ty=y,tx=x,num=0;
			while(in(tx,ty) && M[ty][tx]==now){
				num++;
				tx++;
			}
			tx--;
			if(num>=n){
				for(int i=0;i<num;i++){
					ok[y][tx-i]=true;
				}
			}

			ty=y;tx=x;num=0;
			while(in(tx,ty) && M[ty][tx]==now){
				num++;
				ty++;
			}
			ty--;
			if(num>=n){
				for(int i=0;i<num;i++){
					ok[ty-i][tx]=true;
				}
			}
		}
	}

	for(int y=0;y<h;y++){
		for(int x=0;x<w;x++){
			if(ok[y][x]){
				M[y][x]='.';
				update=true;
			}
		}
	}
	return update;
}

bool calc(vector<string> M,int x,int y){

	swap(M[y][x],M[y][x+1]);
	
	bool update=true;
	while(update){
		update=false;
		for(int y=h-1;y>=0;y--){
			for(int x=0;x<w;x++){
				int ty=y+1;
				if(M[y][x]=='.') continue;
				while(in(x,ty) && M[ty][x]=='.') ty++;
				ty--;
				if(y==ty) continue;
				update=true;
//				print(M);
//				cout<<y<<" "<<ty<<endl;
				M[ty][x]=M[y][x];
				M[y][x]='.';
			}
		}
		
		update=do_clear(M);
	}

	for(int y=0;y<h;y++){
		for(int x=0;x<w;x++){
			if(M[y][x]!='.') return false;
		}
	}
	return true;
}


int main()
{
	while(cin>>h>>w>>n && h!=0){
		vector<string> M;
		for(int i=0;i<h;i++){
			string s;
			cin>>s;
			M.push_back(s);
		}
		bool ok=false;
		for(int y=0;y<h;y++){
			if(ok) break;
			for(int x=0;x<w-1;x++){
				if(M[y][x]!=M[y][x+1])
					if(calc(M,x,y)){ok=true;break;}
			}
		}
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}