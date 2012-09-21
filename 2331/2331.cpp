#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
	int N;
	cin>>N;

	int left[100002],right[100002];
	memset(left,0,sizeof(left));
	memset(right,0,sizeof(right));

	for(int i=0;i<N;i++){
		int a,b;
		cin>>a>>b;
		left[a]++;right[b]++;
	}

	int before=left[2];
	int ans=0;
	if(left[2]>=1) ans=1;

	for(int num=3;num<=N+1;num++){
		int now=before+left[num]-right[num-1];
		if(now>=num-1) ans=max(ans,num-1);
		before=now;
	}
	cout<<ans<<endl;
}