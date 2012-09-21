#include<iostream>
#include<vector>
#include<string>
using namespace std;

int W,H;
int dx[4]={1,0,-1,0};//������
int dy[4]={0,1,0,-1};

struct Cor{//���W��\��
	int x,y;
	Cor(int para_x,int para_y){
		x=para_x;
		y=para_y;
	}
};

bool in(int x,int y){//�͈͓��Ȃ�true
	if(x<0 || y<0 || x>=W || y>=H)
		return false;
	 return true;
}

void upper(int x,int y,char c,vector<string> &M,vector<vector<bool> > &visit,vector<Cor> &C){
	//��Ƀu���b�N������ƌĂяo�����
	//���ڂ��Ă���u���b�N�̐�����c�ŕ\�����

	if(!in(x,y)) return; //�O�ł���
	if(visit[y][x]) return;  //����������
	if(M[y][x]!=c) return;  //�Ⴄ�u���b�N����
	visit[y][x]=true;
	

	C.push_back(Cor(x,y));//���܂Œʂ����u���b�N�ɒǉ����邺

	for(int r=0;r<4;r++){//�אڂ���������ނ̃u���b�N����������A�������Ăяo��
		int nx=x+dx[r],ny=y+dy[r];
		if(in(nx,ny) && M[ny][nx]==c)
			upper(nx,ny,M[ny][nx],M,visit,C);
	}

	if(in(x,y-1) && isdigit(M[y-1][x]) && M[y-1][x]!=c){//��Ƀu���b�N����������A���̃u���b�N�ɒ��ڂ��ČĂяo��
		upper(x,y-1,M[y-1][x],M,visit,C);
	}
}

void start(int x,int y,char c,vector<string> &M,vector<vector<bool> > &visit,vector<Cor> &C,int &left,int &right,vector<vector<bool> > &checked){
	//�ŏ��ɒ��ڂ����u���b�N�ɂ���
	if(!in(x,y)) return; //�O�ł���
	if(visit[y][x]) return;  //����������
	if(M[y][x]!=c) return;  //�Ⴄ�u���b�N����
	if(checked[y][x]) return;
	visit[y][x]=true;  //���܂�����I
	checked[y][x]=true;


	C.push_back(Cor(x,y));//���܂Œʂ����u���b�N�ɒǉ����邺
	if(!in(x,y+1)){ //�n�ʂ��I
		left=min(left,x); //���̒l���X�V
		right=max(right,x);  //�E�̒l���ˁI
	}
	else{
		if(isdigit(M[y+1][x]) && M[y+1][x]!=c){//�Ⴄ�u���b�N�ł����I
			left=min(left,x);// �X�V�I
			right=max(right,x);
		}
	}

	for(int r=0;r<4;r++){//����4�}�X�ɓ����u���b�N���Ȃ������Ă݂�
		int nx=x+dx[r],ny=y+dy[r];
		if(!in(nx,ny)) continue;
		if(M[ny][nx]==M[y][x])
			start(nx,ny,M[ny][nx],M,visit,C,left,right,checked);//����������A�Ăяo��
	}

	if(in(x,y-1) && !visit[y-1][x] && isdigit(M[y-1][x]) && M[y-1][x]!=c){//��ɈႤ�u���b�N������܂���?
		upper(x,y-1,M[y-1][x],M,visit,C);
	}

}

void solve(){
	vector<string> M;
	for(int i=0;i<H;i++){
		string s;
		cin>>s;
		M.push_back(s);
	}

	vector<vector<bool> > checked(H,vector<bool>(W,false));
	for(int y=0;y<H;y++){
		for(int x=0;x<W;x++){
			if(checked[y][x]) continue;
			if(M[y][x]!='.'){
				vector<Cor> C;  //�d�S�����߂����u���b�N�̉�����Ă���
				int left=10000,right=0;
				vector<vector<bool> > visit(H,vector<bool>(W,false));
				start(x,y,M[y][x],M,visit,C,left,right,checked);

				double sum_x=0;
				for(int n=0;n<C.size();n++){//�d�S���v�Z����
					sum_x+=C[n].x+0.5;
				}


				double g=double(sum_x)/C.size();


				if(!(left < g && g < right+1)){ //���߂ł���
					cout<<"UNSTABLE\n";
					return;
				}
			}
		}
	}
	cout<<"STABLE\n";
}

int main()
{
	while(cin>>W>>H){
		if(W==0) break;
		solve();
	}
	return 0;
}
