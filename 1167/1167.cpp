#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int polloc[200];
	for(int i=0;i<200;i++){//ポロック数を求める
		polloc[i]=i*(i+1)*(i+2)/6;
	}
	int n;
	vector<int> ans1(1000001,-1);
	vector<int> ans2(1000001,-1);
	
	for(int i=0;i<200;i++){//初期値を入れておく
		if(polloc[i]>1000000) break;
		ans1[polloc[i]]=1;
		if(polloc[i]%2==1)
			ans2[polloc[i]]=1;
	}

	for(int i=1;i<=1000000;i++){//Dpするよ
		if(ans1[i]<0){//ポロック数じゃない
			ans1[i]=100000000;
			for(int k=0;k<200;k++){
				if(i-polloc[k]<0) break;
				ans1[i]=min(ans1[i],ans1[i-polloc[k]]+1);//今の数-ポロック数のときの解+1で作れる
			}
		}

		if(ans2[i]<0){//ポロック数じゃない
			ans2[i]=1000000000;
			for(int k=0;k<200;k++){
				if(polloc[k]%2==0) continue;
				if(i-polloc[k]<0) break;
				ans2[i]=min(ans2[i],ans2[i-polloc[k]]+1);
			}
		}
	}

	while(cin>>n){
		if(n==0) return 0;
		cout<<ans1[n]<<" "<<ans2[n]<<endl;
	}
}
