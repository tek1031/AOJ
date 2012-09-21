#include<iostream>
#include<string>
using namespace std;

bool is_left(char c){
	if(c=='q' || c=='a' || c=='z' || c=='w' || c=='s' || c=='x' || c=='e' || c=='d' || c=='c' || c=='r' ||
		c=='f' || c=='v' || c=='t' || c=='g' || c=='b') return true;
	else return false;
}

int main()
{
	string s;
	while(cin>>s){
		if(s=="#") return 0;
		bool left=is_left(s[0]);
		int ans=0;
		for(int i=1;i<s.size();i++){
			if(left && !is_left(s[i])) ans++;
			if(!left && is_left(s[i])) ans++;
			left=is_left(s[i]);
		}
		cout<<ans<<endl;
	}
}