#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class info{
public:
	int id,penalty,num;
	info(int id,int penalty,int num):id(id),penalty(penalty),num(num){}
};

bool operator < (info a,info b){
	if(a.num!=b.num) return a.num>b.num;
	if(a.penalty!=b.penalty) return a.penalty<b.penalty;
	return a.id<b.id;
}


int main()
{
	int T,P,R;
	while(cin>>T>>P>>R && T!=0){
		vector<vector<bool> > done(T,vector<bool>(P,false));
		vector<vector<int> >  num_wrong(T,vector<int>(P,0));
		vector<int> num_correct(T,0);
		vector<int> penalty(T,0);

		for(int i=0;i<R;i++){
			int team,problem,time;
			string s;
			cin>>team>>problem>>time>>s;
			problem--;team--;
			if(s=="WRONG"){
				num_wrong[team][problem]++;
			}
			else{
				num_correct[team]++;
				penalty[team]+=num_wrong[team][problem]*1200+time;
			}
		}
		vector<info> work;
		for(int i=0;i<T;i++){
			work.push_back(info(i,penalty[i],num_correct[i]));
		}
		sort(work.begin(),work.end());
		for(int i=0;i<T;i++)
			cout<<work[i].id+1<<" "<<work[i].num<<" "<<work[i].penalty<<endl;
	}
}