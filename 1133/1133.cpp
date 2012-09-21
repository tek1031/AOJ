#include<iostream>
#include<vector>
#include<list>
using namespace std;

const int EPS=0.00000001;

class area{
public:
	int lx,rx,lh,rh;
	double water;
	int cap;
	area(int lx,int lh,int rx,int rh,double water):lx(lx),lh(lh),rx(rx),rh(rh),water(water){
		cap=min(lh,rh)*(rx-lx)*30;
	}
	double get_rem(){return cap-water;}
	double get_h(){return water/(30.0*(rx-lx));}
	bool is_full_left(){
		if(water/(30.0*(rx-lx))+EPS<lh) return false;
		return true;
	}

	bool is_full_right(){
		if(water/(30.0*(rx-lx))+EPS<rh) return false;
		return true;
	}
};

int get_id(vector<area> &Tank,int x){
	for(int idx=0;idx<Tank.size();idx++){
		if(Tank[idx].lx<x && x<Tank[idx].rx){
			return x;
		}
	}
	cout<<"Error\n";
	return -1;
}

int main()
{
	int D;
	cin>>D;
	for(int t=0;t<D;t++){
		int N;
		cin>>N;
		int before_lx=0,before_lh=50;
		vector<area> Tank;
		for(int i=0;i<N;i++){
			int B,H;
			cin>>B>>H;
			Tank.push_back(area(before_lx,before_lh,B,H,0.0));
		}
		int M;
		cin>>M;
		int wx[10],wcap[10];
		for(int i=0;i<M;i++){
			cin>>wx[i]>>wcap[i];
		}

		int query_time[10],query_x[10];
		int L;
		cin>>L;
		for(int i=0;i<L;i++){
			cin>>query_x[i]>>query_time[i];
		}

		//�����܂œ���

		double now=0.0;
		int num_query=0;//�ǂ��܂ł̃N�G��������������

		while(true){//�Ƃ肠����

			int w_id[10];//�ǂ���area�ɐ������Ă��邩
			int sum_water[10];//�e�G���A�ō��v�ǂꂾ���̐������邩
			memset(sum_water,0,sizeof(sum_water));

			for(int i=0;i<M;i++){//�����ǂ���area�ɓ��邩�𒲂ׂ�
				int id=get_id(Tank,wx[i]);
				w_id[i]=id;
				sum_water[id]+=wcap[i];
			}

			double next_time=100000000;

			for(int idx=0;idx<Tank.size();idx++){//���ɂǂ��������ς��ɂȂ邩�C���̍ŒZ���Ԃ����߂�
				double rem=Tank[idx].get_rem();
				next_time=min(next_time,now+rem/sum_water[idx]);
			}

			while(num_query<L && query_time[num_query]>next_time){//now �Ɓ@nexttime�̊Ԃɗv�����������璀���o��

				int id=get_id(Tank,query_x[num_query]);
				cout<<Tank[id].water+(next_time-now)*sum_water[id]<<endl;
				num_query++;//�N�G���������������̂ŁC����
				//Caution ���������ς��ɂȂ����Ƃ��̏����������ɏ�����
			}
			if(num_query==L) break;//�S�ẴN�G������������

			for(int i=0;i<Tank.size();i++){//���𒍓�
				Tank[i].water+=(next_time-now)*sum_water[i];
			}

			bool update=true;//�T�����悤�Ƃ���ƁC�ʓ|�Ȃ̂ŁC�ω����Ȃ��Ȃ�܂ōX�V��
			while(update){
				update=false;
				for(int i=0;i<M;i++){
					int id=get_id(Tank,wx[i]);
					if(!(Tank[id].is_full_left() || Tank[id].is_full_right())) continue; //�ǂ����ɂ����ӂ�ĂȂ�
					update=true;
					//�܂��ׂ͗Ɉ��o���P�[�X
					if(Tank[id].is_full_left()){

					}
				}
			}



		}


	}
}
