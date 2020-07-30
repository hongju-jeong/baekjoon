#include<iostream>

using namespace std;

int main() {

	int N;
	int temp = 0;
	cin >> N;

	int* a = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << a[i] << endl;
	}

	delete[] a;
	return 0;
}