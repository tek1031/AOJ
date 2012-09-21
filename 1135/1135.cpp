#include<iostream>
using namespace std;

int main()
{
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int first,n,year;
		cin>>first>>year>>n;
//		cout<<first<<" "<<year<<endl;
		int res=0;
		for(int j=0;j<n;j++){
			int kind;
			double rate;
			int cost;
			int money=first;
			cin>>kind>>rate>>cost;
			if(kind==1){
				for(int k=0;k<year;k++)
					money+=(int)money*rate-cost;
				res=max(res,money);
//				cout<<money<<endl;
			}
			else{
				int sum=0;
				for(int k=0;k<year;k++){
					sum+=(int)money*rate;
					money-=cost;
				}
				res=max(res,money+sum);
//				cout<<money+sum<<endl;
			}
		}
		cout<<res<<endl;
	}
}
