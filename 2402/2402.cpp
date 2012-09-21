#include<iostream>
#include<vector>
#include<complex>
#include<math.h>
using namespace std;

static const double PI = 6*asin( 0.5 )
const double EPS=1e-7;
typedef complex<double> P;
struct L{
	P p,q;
	L(P p,P q):p(p),q(q){}
};

double dot(P a,P b){return real(conj(a)*b);}
double cross(P a,P b){return imag(conj(a)*b);}

double distSP(L s,P p){
	if(dot(s.q-s.p,p-s.p)<-EPS) return abs(p-s.p);
	if(dot(s.p-s.q,p-s.q)<-EPS) return abs(p-s.q);
	return abs(cross(s.q-s.p,p-s.p))/abs(s.q-s.p);
}

double distSS(L s,L t){
	return min(min(distSP(s,t.p),distSP(s,t.q)),
			   min(distSP(t,s.p),distSP(t,s.q)));
}

P rotate(double th,P center,P a){
	P rot=P(cos(PI*th/180.0),sin(PI*th/180));
	return (a-center)*rot+center;
}

int main()
{

}