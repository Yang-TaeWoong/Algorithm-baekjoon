#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

int n,m,start,ed;
vector<pair<int,int> > arr[100001];
	
bool visited[100001]={false,};

bool check(int num,int limit)
{
	if(visited[num]){
		return false;
	}				
	visited[num]=true;
	if(num==ed){
		return true;
	}
	for(auto &p:arr[num]){
		int next=p.first;
		int cost=p.second;
		if(cost>=limit){
			if(check(next,limit)){
				return true;
			}
		}
	}
	return false;
} 
int main()
{
	
//	다리의 갯수 : m 섬의 갯수 : n
//  마지막에 공장이 위치한 서로 다른 정수. from, to 존재 
//c가 10억까지 임을 유의 
	int left=1,right=1000000000,ans=0;	
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		arr[a].push_back(make_pair(b,c));
		arr[b].push_back(make_pair(a,c));
	}
	cin>>start>>ed;
	//배열 인덱스가 시작, b가 도착지, c가 가중치 
	while(left<=right)
	{
		int mid=left+(right-left)/2;
		memset(visited,false,sizeof(visited));
		if(check(start,mid)){
			ans=mid;
			left=mid+1;
		}	
		else{
			right=mid-1;
		}			
	} 
	//dfs로.
	cout<<ans;  
}
