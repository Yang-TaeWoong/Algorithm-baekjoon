//�ο����� ����Ʈ������ �־������� ���������� ���ϴ� ����.
//�ο��� : left print right
//����  ���� : print left right
//����Ʈ ���� : left right print

//Ʈ���� ���� ���� ���������� ������. n�� 10�� 

#include <iostream>
#include <vector>

using namespace std;

int postOrder[100001];
int inOrder[100001];

int rv;//��Ʈ �� 

void solve(int is,int ie,int ps,int pe)
{
	if(is>ie || ps>pe) return;
	int ri;
	rv=postOrder[pe];
	cout<<rv<<" ";
	for(int i=is;i<=ie;i++){
		if(inOrder[i]==rv){
			ri=i;
			break;	
		}
	}//ri�� ���Ѵ�.
	int ls=ri-is;//���� 
	
	
	solve(is,ri-1,ps,ps+ls-1);
	solve(ri+1,ie,ps+ls,pe-1);
} 

int main()
{
	int num;
	cin>>num;
	//����Ʈ ������ ���� ��Ʈ ��带 ���Ѵ�.	
	//��Ʈ ��带 �������� ������ ���δ� ��Ʈ��� ����. 
	//1 2 4 5 7 3 6 ��������
	
	//4 7 5 2 6 3 1 ����Ʈ���� 
	// 4 2 7 5 1 3 6 �ο��� 
	//����ؼ� �������
	for(int i=0;i<num;i++){
		cin>>inOrder[i];
	} 
	for(int i=0;i<num;i++){
		cin>>postOrder[i];
	}
	solve(0,num-1,0,num-1);
} 
