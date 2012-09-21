#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> sieve_of_eratosthenes(int n) {
	vector<int> primes(n);
	for (int i = 2; i < n; ++i)
		primes[i] = i;
	for (int i = 2; i*i < n; ++i)
		if (primes[i])
			for (int j = i*i; j < n; j+=i)
				primes[j] = 0;

//	primes.erase(remove( primes.begin(), primes.end(),0 ), primes.end() );
	return primes;
}

int main()
{
	vector<int> prime=sieve_of_eratosthenes(200000);
	int N,P;
	while(cin>>N>>P && N>=0){
		vector<int> use;
		for(int i=N+1;i<prime.size();i++){
			if(prime[i]!=0) use.push_back(i);
			if(use.size()>100) break;
		}

		vector<int> L;
		for(int i=0;i<=P;i++){
			for(int j=i;j<=P;j++){
				L.push_back(use[i]+use[j]);
			}
		}
		
		sort(L.begin(),L.end());
		cout<<L[P-1]<<endl;
	}
	return 0;
}

