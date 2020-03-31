#include <iostream>
using namespace std;

int map[65][65];
int size;

bool same(int x,int y,int n)
{
	int a=map[y][x];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[y+i][x+j]!=a){
				return false;
			}
		}
	}
	return true;
}
void cut(int x,int y,int n)
{
	if(same(x,y,n)){
		cout<<map[y][x];
	}
	else{
		cout<<"(";
		int m=n/2;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				cut(x+m*j,y+m*i,m);
			}
		}
		cout<<")";
	}
}
int main()
{
	int size;
	cin>>size;
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			scanf("%1d",&map[i][j]);
		}
	}
	cut(1,1,size);
}
