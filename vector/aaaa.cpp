#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	queue<int> Q;
	Q.push(1);
	Q.push(2);
	while(!Q.empty()){
		int a=Q.front();
		Q.pop();
		cout<<a<<endl;
	}
	return 0;
}