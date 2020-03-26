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
	//������ �ִ� ���̸� ���ϴ� ���α׷��� �ۼ�
	//k : ������ �ִ� ���� ����
	//n : �ʿ��� ���� ����
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
		}//�ʹ� ���� �߶���. -> mid�� �ʹ� �۴� 
		else{
			right=mid-1;
		}//�ʹ� ���� �߶��� -> mid�� �ʹ� ũ��  
	}
	printf("%lld",ans);
}
