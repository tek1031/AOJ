#include<iostream>
#include<complex>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<string.h>
using namespace std;
typedef complex<double> P;

const double EPS=0.000000001;
const double INF=1000000;
double r,theta;

	double memo[10001][20][20];

bool is_ok(P a,P b,P c){
	P in=b-a,out=c-b;
	double dot=in.real()*out.real()+in.imag()*out.imag();
//	cout<<in<<out<<endl;
//	cout<<2.0*theta*asin(1.0)/180.0<<endl;
//	cout<<cos(90.0*theta*2.0*asin(1.0)/180.0)<<endl;
//	cout<<cos(theta*2.0*asin(1.0)/180.0)<<" "<<dot/(abs(in)*abs(out))<<endl;
	if(cos(theta)<dot/(abs(in)*abs(out))) return true;
	return false;
}

class Idx{
public:
	int num,bef,now;
	Idx(int bef,int now,int num):bef(bef),now(now),num(num){}
};

class Info{
public:
	Idx idx;
	double sum_r;
	Info(Idx idx,double sum_r):idx(idx),sum_r(sum_r){}
};

int main()
{
	int n;
	cin>>n>>r>>theta;
	vector<P> V;
	for(int i=0;i<n;i++){
		double a,b;
		cin>>a>>b;
		V.push_back(P(a,b));
	}

	for(int i=0;i<10001;i++)
		for(int j=0;j<20;j++)
			for(int k=0;k<20;k++)
				memo[i][j][k]=INF;

	memo[0][0][0]=0.0;
	int ans=0;

	bool ok[20][20][20];
	memset(ok,false,sizeof(ok));
	for(int in=0;in<n;in++){
		for(int out=0;out<n;out++){
			if(in==out) continue;
			for(int next=0;next<n;next++){
				if(in==next || out==next) continue;
//				cout<<"check "<<in<<" "<<out<<" "<<next<<endl;
				if(is_ok(V[in],V[out],V[next])){ok[in][out][next]=true;
				cout<<"ok"<<in<<" "<<out<<" "<<next<<" "<<abs(V[next]-V[out])<<endl;;
				}
			}
		}
	}

	for(int num=1;num<=10000;num++){
		for(int in=0;in<n;in++){
			for(int out=0;out<n;out++){
				if(memo[num-1][in][out]>r+EPS) continue;
				for(int next=0;next<n;next++){
					if((num==1 && next!=0) || ok[in][out][next]){
						if(memo[num-1][in][out]+abs(V[out]-V[next])<r+EPS){
							ans=num;
							memo[num][out][next]=memo[num-1][in][out]+abs(V[out]-V[next]);
							cout<<in<<" "<<out<<" "<<next<<" "<<memo[num][out][next]<<" "<<num<<endl;
						}
					}
				}
			}
		}
		if(ans!=num) break;
	}

	cout<<ans<<endl;
	return 0;
}