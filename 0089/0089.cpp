#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	string s;
	cin>>s;
	istringstream is(s);
	while(true){
		int t;
		is>>t;
		cout<<t<<endl;;
		cout<<is.str()<<endl;
		char k;
		if(is>>k) break;
	}
	return 0;
}