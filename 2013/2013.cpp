#include<iostream>
#include<vector>
#include<string>
using namespace std;

int convert(string s){
	int h=(s[0]-'0')*10+(s[1]-'0');
	int m=(s[3]-'0')*10+(s[4]-'0');
	int t=(s[6]-'0')*10+(s[7]-'0');
	return h*3600+m*60+t;
}

class range{
public:
	int left,right;
	range(int left,int right):left(left),right(right){}
	range(){};
};

bool is_connect(range a,range b){
	if(a.right<=b.left || b.right<=a.left) return false;
	return true;
}


int main()
{
	int n;
	while(cin>> n && n!=0){
		vector<range> V(n);
		for(int i=0;i<n;i++){
			string s,t;cin>>s>>t;
			V[i].left=convert(s);
			V[i].right=convert(t);
		}

		int ans[24*3600+60*60+60+1];
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;i++){
			for(int k=V[i].left;k<V[i].right;k++){
				ans[k]++;
			}
		}

		int res=0;
		for(int i=0;i<=24*3600+60*60+60;i++){
			res=max(res,ans[i]);
		}
		cout<<res<<endl;



	}
	return 0;
}