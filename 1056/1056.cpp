#include<iostream>
#include<vector>
using namespace std;
const int MAX=12;

int main()
{
	double e[100001];
	for(int i=0;i<=100000;i++)
		e[i]=0.0;

	e[0]=0.0;
	e[1]=1.0;
	e[2]=1.5;
	double pro[MAX+1],imp[MAX+1];
	pro[0]=1.0;
	for(int i=1;i<=MAX;i++){
		double p=1.0/(1<<(i-1));
		pro[i]=pro[i-1]*p;
		imp[i]=pro[i-1]*(1.0-p);
//		cout<<imp[i]<<endl;
	}

	for(int day=3;day<=100000;day++){
		for(int k=2;k<=min(day,MAX);k++){
			e[day]+=imp[k]*(e[day-k]+k-1);
//			cout<<imp[k]<<" "<<(e[day-k]+k-1)<<endl;
		}
		if(day<MAX)
			e[day]+=pro[day]*day;
//		cout<<e[day]<<endl;
	}
	int n;
	while(cin>>n && n!=0)
		printf("%.3lf\n",e[n]);

	return 0;
}