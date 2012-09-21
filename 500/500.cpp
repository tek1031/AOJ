#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	while(cin>>n){
		if(n==0) break;
		int p1=0,p2=0;
		for(int i=0;i<n;i++){
			int t1,t2;
			cin>>t1>>t2;
			if(t1==t2){
				p1+=t1;
				p2+=t2;
			}
			else if(t1>t2)
				p1+=t1+t2;
			else p2+=t1+t2;
		}
		cout<<p1<<" "<<p2<<endl;
	}
	return 0;
}