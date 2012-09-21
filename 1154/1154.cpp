#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> prime;
	for(int i=2;i<=300000;i++){
		if(i%7==1 || i%7==6){
			bool ok=true;
			for(int k=0;k<prime.size();k++){
				if(i%prime[k]==0){ok=false;break;}
			}
			if(ok) prime.push_back(i);
		}
	}

	int n;
	while(cin>>n){
		if(n==1) return 0;
		cout<<n<<":";

		for(int i=0;i<prime.size();i++){
			if(prime[i]>n) break;
			if(n%prime[i]==0) cout<<" "<<prime[i];
		}
		cout<<endl;
	}

}