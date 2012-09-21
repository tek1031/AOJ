#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<string.h>
using namespace std;

int N,T,R;

class info{
public:
	int id,cvx,cvy,t;
	info(int id,int t,int cvx,int cvy):id(id),t(t),cvx(cvx),cvy(cvy){}
	info(){}
};

const double EPS=0.0000001;


bool operator < (info a,info b){
	return a.t<b.t;
}

bool connect(double x1,double y1,double x2,double y2,int vx1,int vy1,int vx2,int vy2,int st,int gt){
	cout<<"cor"<<endl;
	cout<<x1<<" "<<y1<<endl;
	cout<<x2<<" "<<y2<<endl;
	double a=(vx1-vx2)*(vx1-vx2)+(vy1-vy2)*(vy1-vy2);
	double b=2*((vx1-vx2)*(x1-x2)+(vy1-vy2)*(y1-y2));
	double c=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)-R*R;

	cout<<(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<<" "<<R*R+EPS<<endl;;
	if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<R*R+EPS) return true;


	if(abs(a)<=EPS){
		cout<<"small!!!\n";
		double ans=-c/b;
		if(b==0) return false;
		cout<<b<<" "<<c<<endl;
		cout<<ans<<"::"<<st<<" "<<gt<<endl;
		if(st<ans+EPS && ans<gt+EPS) return true;
		else return false;
	}
	if(b*b-4*a*c<0){
		cout<<"cannot\n";
		return false;
	}

	double ans1=(-b+sqrt(b*b-4*a*c))/(2*a);
	double ans2=(-b-sqrt(b*b-4*a*c))/(2*a);

	cout<<a<<" "<<b<<" "<<c<<endl;
	cout<<ans1<<" "<<ans2<<"::"<<st<<" "<<gt<<endl;
	if(st<ans1+EPS && ans1<gt+EPS) return true;
	if(st<ans2+EPS && ans2<gt+EPS) return true;
	return false;
}



int main(){
	while(cin>>N>>T>>R && N!=0){
		double x[100],y[100];
		int vx[100],vy[100];
		bool ok[100];
		memset(ok,false,sizeof(ok));
		vector<info> V;
		map<string,int> Idx;
		map<int,string> rev_Idx;
		for(int i=0;i<N;i++){
			string s;
			cin>>s;
			Idx[s]=i;
			rev_Idx[i]=s;
			int gomi;
			cin>>gomi>>x[i]>>y[i];
			int time=0,beftime=0;
			while(cin>>time){
				int ivx,ivy; 
				cin>>ivx>>ivy;
				if(beftime==0){
					vx[i]=ivx;vy[i]=ivy;
				}
				else V.push_back(info(i,beftime,ivx,ivy));
				if(time==T) break;
				beftime=time;
			}
		}
		sort(V.begin(),V.end());

		ok[0]=true;
		bool update=true;
//		while(update){
			update=false;
			for(int i=0;i<N;i++){//Å‰‚©‚ç’ÊM‚µ‚Ä‚¢‚é‚Æ‚±‚ë‚ð—ñ‹“
				if(!ok[i]) continue;
				for(int j=0;j<N;j++){
					if(i==j) continue;
					if(ok[j]) continue;
					if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<EPS+R*R){
						ok[j]=true;
						update=true;
					}
				}
			}
//		}

		int now,bef=0;
		for(int i=0;i<V.size();i++){
			if(i!=0)
				bef=V[i-1].t;
			now=V[i].t;

			update=true;
			while(update){
				update=false;
				for(int a=0;a<N;a++){
					if(!ok[a]) continue;
					for(int b=0;b<N;b++){
						if(ok[b]) continue;
						cout<<"check "<<rev_Idx[a]<<" "<<rev_Idx[b]<<endl;
						if(now-bef>0 && connect(x[a],y[a],x[b],y[b],vx[a],vy[a],vx[b],vy[b],bef,now)){
							ok[b]=true;
							update=true;
							cout<<"ok\n";
						}
					}
				}
			}

			for(int k=0;k<N;k++){
				x[k]+=vx[k]*(now-bef);
				y[k]+=vy[k]*(now-bef);
			}

			vx[V[i].id]=V[i].cvx;
			vy[V[i].id]=V[i].cvy;
			bef=now;
		}
//		cout<<"after////\n";

		update=true;
//		while(update){
			update=false;
			for(int a=0;a<N;a++){
				if(!ok[a]) continue;
				for(int b=0;b<N;b++){
					if(ok[b]) continue;
					cout<<"check a"<<rev_Idx[a]<<" "<<rev_Idx[b]<<endl;
					if(T-bef>0 && connect(x[a],y[a],x[b],y[b],vx[a],vy[a],vx[b],vy[b],bef,T)){
						cout<<"ok!\n";
						ok[b]=true;
						update=true;
					}
				}
			}
//		}

		vector<string> ans;
		for(int i=0;i<N;i++)
			if(ok[i]) ans.push_back(rev_Idx[i]);

		sort(ans.begin(),ans.end());
//		cout<<"///////////////\n";
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<endl;
//		cout<<"//////////////\n";
	}

	return 0;
}
