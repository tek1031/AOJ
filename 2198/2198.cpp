#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class flower{
public:
	string name;
	int bo,si;
	flower(string name,int si,int bo):name(name),bo(bo),si(si){}
};

bool operator < (flower a,flower b){
	if(a.si*b.bo!=b.si*a.bo) return a.si*b.bo>b.si*a.bo;
	else return a.name<b.name;
}

int main()
{
	int n;
	while(cin>>n && n!=0){
		vector<string> F(n);
		vector<flower> ans;
		int p[50],a[50],b[50],c[50],d[50],e[50],f[50],s[50],m[50];
		for(int i=0;i<n;i++){
			cin>>F[i]>>p[i]>>a[i]>>b[i]>>c[i]>>d[i]>>e[i]>>f[i]>>s[i]>>m[i];
			ans.push_back(flower(F[i],(s[i]*f[i]*m[i]-p[i]),(a[i]+b[i]+c[i]+(d[i]+e[i])*m[i])));
//			cout<<ans[i].k<<endl;
//			cout<<ans[i].name<<endl;
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<n;i++)
			cout<<ans[i].name<<endl;
		cout<<"#"<<endl;
	}
}