#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;


vector<int> sieve_of_eratosthenes(int n) {
  vector<int> primes(n);
  for (int i = 2; i < n; ++i)
    primes[i] = i;
  for (int i = 2; i*i < n; ++i)
    if (primes[i])
      for (int j = i*i; j < n; j+=i)
        primes[j] = 0;
  return primes;
}

		int dp[15][200][1121];

int main()
{
	vector<int> a=sieve_of_eratosthenes(1121);
	vector<int> prime;
	for(int i=0;i<a.size();i++)
		if(a[i]!=0) prime.push_back(a[i]);

	int n,k;
	while(cin>>n>>k && n!=0){
		memset(dp,0,sizeof(dp));

		dp[0][0][0]=1;

		for(int i=0;i<k;i++){
			for(int j=0;j<prime.size();j++){
				for(int num=0;num<=n;num++){
					if(dp[i][j][num]==0) continue;
					for(int next=j;next<prime.size();next++){
						if(num+prime[next]>n) break;
						dp[i+1][next+1][num+prime[next]]+=dp[i][j][num];
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=prime.size();i++){
			ans+=dp[k][i][n];
		}
		cout<<ans<<endl;
	}

	return 0;
}