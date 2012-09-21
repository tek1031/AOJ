#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

class zone{
public:
	int s,t,id;
	zone(int s,int t,int id):s(s),t(t),id(id){}
};


int main()
{
	int n;
	while(cin>>n && n!=0){
		list<zone> L;
		for(int i=0;i<n;i++){

			char c;
			cin>>c;
			if(c=='W'){
				int id,length;
				cin>>id>>length;
				int now=0;
				for(list<zone>::iterator it=L.begin();it!=L.end();){
					zone look=*it;
					if(now<look.s){
						it=L.insert(it,zone(now,now+min(length,look.s-now)-1,id));
						length=length-min(length,look.s-now);
						if(length==0) break;
						now=look.t+1;
						continue;
					}
					now=look.t+1;
					it++;
				}
				if(length!=0)
					L.push_back(zone(now,now+length-1,id));
			}
			else if(c=='D'){
				int id; cin>>id;
				for(list<zone>::iterator it=L.begin();it!=L.end();){
					zone look=*it;
					if(look.id==id){
						it=L.erase(it);
						continue;
					}
					it++;
				}
			}
			else{
				int id;cin>>id;
				bool ok=false;
				for(list<zone>::iterator it=L.begin();it!=L.end();){
					zone look=*it;
					if(look.s>id){break;}
					if(look.s<=id && id<=look.t){ok=true;cout<<look.id<<endl;break;}
					it++;
				}
				if(!ok) cout<<-1<<endl;
			}
		}
		cout<<endl;
	}
	return 0;	
}