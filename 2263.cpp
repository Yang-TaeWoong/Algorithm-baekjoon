//인오더와 포스트오더가 주어졌을때 프리오더를 구하는 문제.
//인오더 : left print right
//프리  오더 : print left right
//포스트 오더 : left right print

//트리를 직접 만들어서 프리오더를 구하자. n이 10만 

#include <iostream>
#include <vector>

using namespace std;

int postOrder[100001];
int inOrder[100001];

int rv;//루트 값 

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
	}//ri를 구한다.
	int ls=ri-is;//길이 
	
	
	solve(is,ri-1,ps,ps+ls-1);
	solve(ri+1,ie,ps+ls,pe-1);
} 

int main()
{
	int num;
	cin>>num;
	//포스트 오더를 통해 루트 노드를 구한다.	
	//루트 노드를 기준으로 왼쪽은 전부다 루트노드 왼쪽. 
	//1 2 4 5 7 3 6 프리오더
	
	//4 7 5 2 6 3 1 포스트오더 
	// 4 2 7 5 1 3 6 인오더 
	//계속해서 나누어가자
	for(int i=0;i<num;i++){
		cin>>inOrder[i];
	} 
	for(int i=0;i<num;i++){
		cin>>postOrder[i];
	}
	solve(0,num-1,0,num-1);
} 
