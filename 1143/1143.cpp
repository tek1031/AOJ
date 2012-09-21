#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<stdlib.h>
using namespace std;

int n,k;
int X,Y;

class Cor{
public:
	int x,y;
	Cor(int x,int y):x(x),y(y){}
	bool operator == (const Cor &a){
		if(a.x==x && a.y==y) return true;
		return false;
	}
};

bool operator < (Cor a,Cor b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}

set<Cor> Rock;
set<vector<Cor> > Done;
int dx[]={0,1,1,0,-1,-1};
int dy[]={-1,-1,0,1,1,0};

bool is_next(Cor a,Cor b){
	for(int r=0;r<6;r++){
		if(a.x+dx[r]==b.x && a.y+dy[r]==b.y) return true;
	}
	return false;
}

bool check(vector<Cor> snake,int pos){ //pos‚Ü‚ÅŠm’è
	if(Rock.count(snake[pos]))return false;
	for(int i=0;i<pos-1;i++){
		if(is_next(snake[i],snake[pos])) return false;
		if(snake[i]==snake[pos]) return false;
	}
	
	if(pos-1>=0 && !is_next(snake[pos-1],snake[pos])) return false;
//	if(pos+1<snake.size() && !is_next(snake[pos],snake[pos+1])) return false;
	return true;
}

bool connect(const vector<Cor> &snake,int pos){
	if(pos!=0){
		if(!is_next(snake[pos],snake[pos-1])) return false;
	}
	if(pos!=snake.size()-1){
		if(!is_next(snake[pos],snake[pos+1])) return false;
	}
	return true;
}

class state{
public:
	int cost;
	vector<Cor> snake;
	state(vector<Cor> snake,int cost):cost(cost),snake(snake){}
};

queue<state> Q;
void make_snake(vector<Cor> &snake,int pos,int cost){
	if(pos>=snake.size()){
		if(!Done.count(snake)){
			Done.insert(snake);
			if(check(snake,snake.size()-1))
				Q.push(state(snake,cost));
		}
		return;
	}

	for(int r=0;r<6;r++){
		snake[pos].x+=dx[r]; snake[pos].y+=dy[r];
		if(!Rock.count(snake[pos])){
			if(pos+1>=snake.size() || is_next(snake[pos],snake[pos+1]) )
				if(check(snake,pos) )
					make_snake(snake,pos+2,cost);
		}
		snake[pos].x-=dx[r];snake[pos].y-=dy[r];
	}
	if(check(snake,pos))
		make_snake(snake,pos+1,cost);
}

int bfs(vector<Cor> first){
	Done.clear();
	Q=queue<state>();
	Q.push(state(first,0));
	Done.clear();

	while(!Q.empty()){
//		cout<<"size "<<Q.size()<<endl;

		state now=Q.front();Q.pop();
		if(now.snake[0].x==X && now.snake[0].y==Y) return now.cost;
		if(abs(now.snake[0].x-X)>20-now.cost || abs(now.snake[0].y-Y)>20-now.cost) continue;
		make_snake(now.snake,0,now.cost+1);
	}
	return -1;
}


int main()
{
	while(cin>>n && n!=0){
		Rock.clear();
		Done.clear();
		vector<Cor>S;
		for(int i=0;i<n;i++){
			int x,y; cin>>x>>y; S.push_back(Cor(x,y));
		}
		cin>>k;
		for(int i=0;i<k;i++){
			int x,y;cin>>x>>y;Rock.insert(Cor(x,y));
		}
		cin>>X>>Y;
		cout<<bfs(S)<<endl;;
	}
	return 0;
}
