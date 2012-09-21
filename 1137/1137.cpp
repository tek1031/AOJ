#include<iostream>
#include<string>
using namespace std;

int to_int(string s){
	int p=0;
	int res=0;
	while(p<s.size()){
		int count=1;
		if(isdigit(s[p])){
			count=s[p]-'0';
			p++;
		}
		if(s[p]=='m') res+=count*1000;
		else if(s[p]=='c') res+=count*100;
		else if(s[p]=='x') res+=count*10;
		else if(s[p]=='i') res+=count;
		p++;
	}
	return res;
}

string to_string(int n){
	string res="";
	if(n/1000>0){
		if(n/1000>1) res+='0'+n/1000;
		res+='m';
		n%=1000;
	}
	if(n/100>0){
		if(n/100>1) res+='0'+n/100;
		res+='c';
		n%=100;
	}
	
	if(n/10>0){
		if(n/10>1) res+='0'+n/10;
		res+='x';
		n%=10;
	}
	if(n>0){
		if(n>1) res+='0'+n;
		res+='i';
	}
	return res;

}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		cout<<to_string(to_int(s1)+to_int(s2))<<endl;
	}
	return 0;
}