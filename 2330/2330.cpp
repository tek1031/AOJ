#include<iostream>
using namespace std;

int main()
{
	long long  n;
	while(cin>>n && n!=0){
		int ans=1;
		long long  count=3;
		while(count<n){
			ans++;
			count*=3;
		}
		cout<<ans<<endl;
	}
	return 0;
}