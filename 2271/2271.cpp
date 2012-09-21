#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while(cin>>s){
		int num[4];
		num[0]=num[1]=num[2]=num[3]=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='K') num[0]++;
			if(s[i]=='U') num[1]++;
			if(s[i]=='P') num[2]++;
			if(s[i]=='C') num[3]++;
		}
		int res=100000;
		res=min(num[0],res);
		res=min(num[1],res);
		res=min(num[2],res);
		res=min(num[3],res);
		cout<<res<<endl;
	}
	return 0;
}