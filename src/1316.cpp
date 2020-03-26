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
	}//한개씩 읽어나가면서 다른 문자가 나오면 그 이전 문자에 해당하는 인덱스를 101로 만든다. 
	 //그리고 계속 읽어 나가다가 101이 인덱스인 문자를 만나면 바로 false를 반환한다. 
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
