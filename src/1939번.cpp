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
	
//	�ٸ��� ���� : m ���� ���� : n
//  �������� ������ ��ġ�� ���� �ٸ� ����. from, to ���� 
//c�� 10����� ���� ���� 
	int left=1,right=1000000000,ans=0;	
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		arr[a].push_back(make_pair(b,c));
		arr[b].push_back(make_pair(a,c));
	}
	cin>>start>>ed;
	//�迭 �ε����� ����, b�� ������, c�� ����ġ 
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
	//dfs��.
	cout<<ans;  
}
