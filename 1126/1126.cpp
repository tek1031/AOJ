#include<iostream>
#include<string>
#include<vector>
using namespace std;

string comp(string s1,string s2){
	if(s1.size()>s2.size())
		return s1;
	else if(s1.size()<s2.size())
		return s2;

	return max(s1,s2);
}

int main()
{
	int W,H;
	while(cin>>W>>H && W!=0){
		vector<string> M;
		for(int i=0;i<H;i++){
			string s;
			cin>>s;
			M.push_back(s);
		}
		vector<vector<string> > dp(H,vector<string>(W,""));

		string ans="";

		for(int y=0;y<H;y++){
			for(int x=0;x<W;x++){
				if(!isdigit(M[y][x])) continue;
				dp[y][x]=M[y][x];

				string s1="",s2="";
				if(x>=1){
					s1=dp[y][x-1]+M[y][x];
				}
				if(y>=1){
					s2=dp[y-1][x]+M[y][x];
				}

				dp[y][x]=comp(dp[y][x],comp(s1,s2));
				if(dp[y][x]=="0") dp[y][x]="";

				ans=comp(dp[y][x],ans);
			}
		}
		cout<<ans<<endl;
	}
}