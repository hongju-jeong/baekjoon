#include<iostream>

using namespace std;

int sorted[1000001];

void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	// i가 middle까지 가면 j가 남은게 있을 거고 j가 n까지 가면 i가 남은
	// 게 있을 거니까 남은 데이터들도 sorted에 삽입해준다.
	
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}

void mergesort(int a[], int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergesort(a, m, middle);
		mergesort(a, middle+1, n);
		merge(a, m, middle, n);
	}
}



int main() {
	int N;
	cin >> N;

	int* array = new int[N];   //동적할당

	for (int t = 0; t < N; t++) {
		cin >> array[t];
	}

	mergesort(array, 0, N - 1);

	for (int t=0; t < N; t++) {
		cout << array[t]<<endl;
	}
	
	delete[] array;   //삭제 꼭
	return 0;
}