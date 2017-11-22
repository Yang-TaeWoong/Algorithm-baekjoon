#include <iostream>
#include <queue>
using namespace std;
int arr[101][101];
bool isVisit[101];
int count=0,num,type;
void bfs()
{
	queue<int> q;
	q.push(1);
	isVisit[1]=true;
	while(!q.empty()){
		int f=q.front();
		q.pop();
		count++;
		for(int i=1;i<=num;i++){
		if(arr[f][i]==1 && !isVisit[i] && f!=i && arr[i][f]==1) {
				q.push(i);
				isVisit[i]=true;
			}
		}	
	}		
}

int main()
{
	cin>>num>>type;
	for(int i=1;i<=num;i++){
		isVisit[i]=false;
		for(int j=1;j<=num;j++){
			arr[i][j]=0;
		}
	}
	for(int i=1;i<=type;i++){
		int x,y;
		cin>>x>>y;
		arr[x][y]=1;
		arr[y][x]=1;
	}	
	arr[1][1]=1;
	bfs();
	cout<<count-1;		
}
