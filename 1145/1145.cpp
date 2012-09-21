#include<iostream>
#include<string>
using namespace std;
string s;
int t;
int p=0;
const int INF=1000001;

int read_digit(){
	int res=0;
	while(isdigit(s[p])){
		res*=10;
		res+=s[p++]-'0';
	}
	return res;
}

string calc(){
	string res;
	while(p<s.size()){
		if(isdigit(s[p])){
			int mul=read_digit();
			string get;
			if(s[p]=='('){
				p++;
				get=calc();
			}
			else{
				get=s[p++];
			}
			for(int i=0;i<mul;i++){
				for(int j=0;j<get.size();j++){
					if(res.size()>t) break;
					res+=get[j];
				}
				if(res.size()>t) break;
			}
		}
		else if(isupper(s[p])){
			if(res.size()<=t)
				res+=s[p];
			p++;
		}
		else{
			p++;
			return res;
		}
	}
	return res;
}

int main()
{
	while(cin>>s>>t && s!="0"){
		p=0;
		string get=calc();
		if(get.size()<t+1) cout<<0<<endl;
		else cout<<get[t]<<endl;
	}
}