#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string,int> idx;//���q�ʂ���������
int p;//���ݓǂݍ��ވʒu

int calc(string s){//�\����͂��n�߂�
	int res=0;
	while(p<s.size()){//�I���ɂ���܂ő��s
		if(s[p]==')'){p++; break;}//����')'��ǂݍ��񂾂�@�|�C���^��i�߂�break
		int weight=0;//�ǂݍ��񂾌��q��
		string f;//�ǂݍ��ތ��q������
		if(isupper(s[p])){//�啶���������炻�̂܂ܓǂݍ���
			f+=s[p];p++;
			if(p<s.size() && islower(s[p])){//���ɏ�������������f�ɒǉ�
				f+=s[p]; p++;
			}
			if(!idx.count(f)) return -1;//�m��Ȃ����q�������畉�̒l��Ԃ�
			weight=idx[f];//�����łȂ����weight�ɓ����
		}
		else if(s[p]=='('){//'('��ǂݍ��񂾂�ċA�Ŋ��ʓ��̌��q�̏d����ǂ�
			p++;//'('�̎��̕����Ɉڂ�
			weight=calc(s);
			if(weight<0) return -1;//���̒l���A���Ă����畉�̒l��Ԃ�
		}
		int mul=0;
		while(p<s.size() && isdigit(s[p])){//������ǂ�
			mul*=10;
			mul+=s[p]-'0';
			p++;
		}
		if(mul==0) mul=1;//�������Ȃ������Ƃ�
		res+=weight*mul;
	}
	return res;
}

int main()
{
	string s;
	while(cin>>s){
		if(s.size()>=3) break;
		int w; cin>>w;
		idx[s]=w;
	}
	while(cin>>s){
		if(s=="0") break;
		p=0;
		int ans=calc(s);
		if(ans<0) cout<<"UNKNOWN"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
