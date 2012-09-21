#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	cin.get();
	for(int i=0;i<n;i++){
		string s;
		getline(cin,s);
		for(int j=0;j<s.size();j++){
			if(s.substr(j,7)=="Hoshino")
				s[j+6]='a';
		}
		cout<<s<<endl;
	}
	return 0;

}