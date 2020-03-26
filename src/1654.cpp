#include <iostream>
using namespace std;

long long int k,n;
long long int arr[10001];

bool go(long long int limit)
{
	long long int count=0;
	for(int i=0;i<k;i++){
		count+=arr[i]/limit;	
	}
	if(count>=n){
		return true;		
	}
	else return false;
}

int main()
{
	//랜선의 최대 길이를 구하는 프로그램을 작성
	//k : 가지고 있는 랜선 갯수
	//n : 필요한 랜선 갯수
	scanf("%lld%lld",&k,&n);
	long long int ans=0;
	long long int left=1, right=3147483648;
	for(int i=0;i<k;i++){
		scanf("%lld",&arr[i]);
	}
	while(left<=right){
		long long int mid=(left+right)/2;
		if(go(mid)){
			if(ans<mid){
				ans=mid;
			}
			left=mid+1;
		}//너무 많이 잘랏다. -> mid가 너무 작다 
		else{
			right=mid-1;
		}//너무 조금 잘랏다 -> mid가 너무 크다  
	}
	printf("%lld",ans);
}
