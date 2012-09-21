#include<iostream>
#include<complex>
#include<vector>
using namespace std;

typedef complex<double> P;
#define EPS (1e-10)

int main()
{
	int n;
	while(cin>>n && n!=0){
		int ans=1;
		vector<P> points;
		for(int i=0;i<n;i++){
			double x,y; cin>>x>>y;
			points.push_back(P(x,y));
		}
		for(int a=0;a<n;a++){
			for(int b=a+1;b<n;b++){
				if(abs(points[b]-points[a])+EPS>2.0) continue;
				P sa=P(points[b]-points[a])/2.0;
				P rev[2];
				rev[0]=sa*P(0,1.0)/abs(sa);
				rev[1]=sa*P(0,-1.0)/abs(sa);
				double l=sqrt(1-abs(sa)*abs(sa));

				for(int k=0;k<2;k++){
					P center=points[a]+sa+rev[k]*l;
					int t_ans=2;
					for(int id=0;id<n;id++){
						if(id==a || id==b) continue;
						if(abs(center-points[id])+EPS<1.0){
							t_ans++;
//							cout<<abs(center-points[id])<<endl;
						}
					}
					
//					cout<<t_ans<<endl;
					ans=max(ans,t_ans);
				}
			}
		}

		cout<<ans<<endl;
	}
	return 0;
}
