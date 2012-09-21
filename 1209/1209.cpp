#include<iostream>
#include<string.h>
using namespace std;


int main()
{
	int a[301][301];

	memset(a,0,sizeof(a));
	for(int i=0;i<301;i++)
		a[1][i]=1;

	for(int i=2;i<=17;i++){
		for(int j=0;j<301;j++){
			a[i][j]=a[i-1][j];
			if(j-i*i>=0) a[i][j]+=a[i][j-i*i];
		}
	}
	int n;
	while(cin>>n && n!=0)
		cout<<a[17][n]<<endl;
}
