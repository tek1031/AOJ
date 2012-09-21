#include<iostream>
using namespace std;

int main()
{
	int n;
	while(cin>>n){
		if(n==0) break;
		int mx=0,mi=500;
		for(int i=0;i<n;i++){
			int temp=0;
			for(int j=0;j<5;j++){
				int t;
				cin>>t;
				temp+=t;
			}
			mx=max(mx,temp);
			mi=min(mi,temp);
		}
		cout<<mx<<" "<<mi<<endl;
	}
	return 0;
}