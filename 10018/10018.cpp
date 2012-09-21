#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int main()
{
	int num[26];
	memset(num,0,sizeof(num));
	string s="";
	while(getline(cin,s)){
		for(int i=0;i<s.size();i++){
			if(isupper(s[i])) s[i]=tolower(s[i]);
			if(isalpha(s[i]))
				num[s[i]-'a']++;
		}
	}
	for(int i=0;i<26;i++){
		cout<<(char)('a'+i)<<" : "<<num[i]<<endl;
	}
	return 0;

}