#include<iostream>
using namespace std;

int main()
{
	int M;
	bool ok=false;
	while(cin>>M && M!=0){
		if(ok) cout<<endl;
		ok=true;
		int m[4];
		int ans[4];
		for(int i=0;i<4;i++){
			cin>>m[i];
			ans[i]=m[i];
		}

		int have=m[0]*10+m[1]*50+m[2]*100+m[3]*500;

		M=have-M;

//		cout<<M<<endl;
		ans[3]-=M/500;
		M%=500;
//		cout<<M<<endl;
		ans[2]-=M/100;
		M%=100;
//		cout<<M<<endl;
		ans[1]-=M/50;
		M%=50;
//		cout<<M<<endl;
		ans[0]-=M/10;
//		cout<<M<<endl;
		
		if(ans[0]>0) cout<<10<<" "<<ans[0]<<endl;
		if(ans[1]>0) cout<<50<<" "<<ans[1]<<endl;
		if(ans[2]>0) cout<<100<<" "<<ans[2]<<endl;
		if(ans[3]>0) cout<<500<<" "<<ans[3]<<endl;
	}
	return 0;
}