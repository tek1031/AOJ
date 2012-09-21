#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,w,d;

class Cake{//�P�[�L��\��
public:
	int x,y,id;
	Cake(int x,int y,int id):x(x),y(y),id(id){}
	Cake(){}
	int calc(){return x*y;}//�ʐς�Ԃ�
};

int main()
{
	while(cin>>n>>w>>d && w!=0){
		vector<Cake> Now;//���݂���P�[�L
		vector<Cake> Next;//�J�b�g��̃P�[�L�̏W��
		Next.push_back(Cake(w,d,1));
		for(int turn=1;turn<=n;turn++){
			Now=Next;//��芷����
			Next.clear();
			int p,s;
			cin>>p>>s;
			for(int i=0;i<Now.size();i++){
				if(Now[i].id==p){//�J�b�g�Ώۂ̃P�[�L�̏ꍇ
					Cake c1,c2;//�J�b�g������̃P�[�L
					s%=Now[i].x+Now[i].y;//MOD�Ƃ��ė]���ȕ����Ƃ�
					if(s<Now[i].x){//�c�ɐ؂�ꍇ
						c1.y=c2.y=Now[i].y;
						c1.x=s;
						c2.x=Now[i].x-s;
					}
					else{//���ɐ؂�ꍇ
						c1.x=c2.x=Now[i].x;
						c1.y=s-Now[i].x;
						c2.y=Now[i].y-(s-Now[i].x);
					}
					if(c1.calc()<c2.calc()){ c1.id=turn;c2.id=turn+1;}//�ʐςɉ����Ĕԍ���t����
					else{c1.id=turn+1;c2.id=turn;}
					Next.push_back(c1);//���̏W���ɓ˂�����
					Next.push_back(c2);
				}
				else{//����ȊO�̃P�[�L
					if(Now[i].id>p) Now[i].id--;//p����ID���傫���P�[�L��ID���P������
					Next.push_back(Now[i]);//�˂�����
				}
			}
		}
		vector<int> ans;//�x�N�^�ɂԂ�����Ń\�[�g�o��
		for(int i=0;i<Next.size();i++)
			ans.push_back(Next[i].calc());
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++){
			cout<<ans[i];
			if(i!=ans.size()-1) cout<<" ";
		}
		cout<<endl;
		
	}
	return 0;
}