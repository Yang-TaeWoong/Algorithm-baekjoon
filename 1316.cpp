#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int count1 = 0;
bool check(string a)
{
	int arr[26] = { 0 };
	int b = a.length();
	arr[a.at(0) - 97] = 1;
	for (int i = 1; i<b; i++) {
		if (arr[a.at(i) - 97] == 101) {
			return false;
		}
		if (a.at(i) != a.at(i - 1)) arr[a.at(i-1) - 97] = 101;
		else arr[a.at(i) - 97] += 1;
	}//�Ѱ��� �о���鼭 �ٸ� ���ڰ� ������ �� ���� ���ڿ� �ش��ϴ� �ε����� 101�� �����. 
	 //�׸��� ��� �о� �����ٰ� 101�� �ε����� ���ڸ� ������ �ٷ� false�� ��ȯ�Ѵ�. 
	return true;
}
int main()
{
	int num;
	string a;
	cin >> num;
	for (int i = 0; i<num; i++) {
		cin >> a;
		if (check(a))count1++; 
	}
	cout << count1;
}
