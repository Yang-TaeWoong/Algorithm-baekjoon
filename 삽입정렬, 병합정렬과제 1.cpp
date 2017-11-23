#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void insertionSort(int start, int end, int *arr)
{
	for (int i = start; i<end ; i++) {
		for (int j = i; j >= start; j--) {
			if (arr[j]>arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}//Insertion Sort
void merge(int start, int end, int* arr)
{
	insertionSort(start,end,arr);
}
void mergeSort(int start, int end, int*arr)
{
	int mid;
	if (start < end)
	{
		mid = (start + end) / 2;
		mergeSort(start, mid, arr);
		mergeSort(mid + 1, end, arr);
		merge(start, end, arr);
	}
}
//mergeSort with insertionSort
int main()
{
	int num;
	cin >> num;
	int *arr = new int[num+1];
	for (int i = 1; i<=num; i++) {
		cin >> arr[i];
	}
	if (num <= 32)	insertionSort(1, num , arr);
	else mergeSort(1, num, arr);
	for (int i = 1; i <= num; i++) {
		cout << arr[i] << " ";
	}
}
