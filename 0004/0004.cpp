#include<iostream>
using namespace std;

int main()
{
	double a,b,c,d,e,f;
	while(cin>>a>>b>>c>>d>>e>>f){
		printf("%.3f ",(c-b*(f-d*c/a)/(e-d*b/a))/a);
		printf("%.3f\n",(f-d*c/a)/(e-d*b/a));
	}
	return 0;
}