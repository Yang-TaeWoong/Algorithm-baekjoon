#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;
	int max = 0;
	int *countB = new int[b.length() + 1];
	for (int i = 0;i <= b.length();i++) {
		countB[i] = 0;
	}
	//ÃÊ±âÈ­ 	
	for (int i = 0;i <= b.length() - a.length();i++) {
		int count = 0;
		for (int j = 0;j<a.length();j++) {
			if (b.at(i + j) == a.at(j)) {
				count++;
			}
		}
		countB[i + a.length()] = count;
	}
	for (int i = 0;i <= b.length();i++) {
		if (countB[i]>max) max = countB[i];
	}
	cout << a.length() - max;
}
