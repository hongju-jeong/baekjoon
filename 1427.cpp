#include<iostream>
#include<cmath>
using namespace std;

int main() {

	int N,temp=0;

	cin >> N;
	int a[10] = {-1,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 };
	//10으로 나누다 보면 자리수나옴
	int count = 0;
	while (N>0) {
		a[count] = N % 10;
		N = N / 10;
		count++;
	}
	
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (a[j] < a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	int printN=0;
	int k = 0;
	while (count > 0) {
		printN += a[k]*pow(10,count-1);
		k++;
		count--;
	}

	cout << printN << endl;



	return 0;
}