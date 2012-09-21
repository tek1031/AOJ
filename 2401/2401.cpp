#include<iostream>
#include<string>
using namespace std;

int mynot(int a){
	if(a==1) return 0;
	return 1;
}

int myand(int a,int b){
	if(a==1 && b==1) return 1;
	return 0;
}

int myor(int a,int b){
	if(a==0 && b==0) return 0;
	return 1;
}

int naraba(int a,int b){
	if(a==0 || (a==1 && b==1)) return 1;
	return 0;
}

string s;
int bit=0;
int p=0;

int to_int(char a){
	if(a=='T') return 1;
	if(a=='F') return 0;
	int k=a-'a';
	if(bit & (1<<k)) return 1;
	return 0;
}


int calc(){
	if(isalpha(s[p])) return to_int(s[p++]);

	if(s[p]=='-'){
		p++;
		return mynot(calc());
	}

	if(s[p]=='('){
		p++;
		int res1=calc();
		if(s[p]=='*'){
			p++;
			int res2=calc();
			p++;
			return myand(res1,res2);
		}
		else if(s[p]=='+'){
			p++;
			int res2=calc();
			p++;
			return myor(res1,res2);
		}
		else if(s[p]=='-'){
			p+=2; //>‚ğ“Ç‚İ”ò‚Î‚·
			int res2=calc();
			p++;
			return naraba(res1,res2);
		}
	}
	cerr<<"Error"<<endl;
	return -1;
}


int main()
{
	while(cin>>s && s[0]!='#'){
		bool ok=true;
		for(bit=0;bit<(1<<11);bit++){
//			cout<<bit<<endl;
			p=0;
			int ans1=calc();
			p++; //=“Ç‚İ”ò‚Î‚µ
			int ans2=calc();
			if(ans1!=ans2){ok=false;break;}
		}
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
