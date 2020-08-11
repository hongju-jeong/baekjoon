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
	// i�� middle���� ���� j�� ������ ���� �Ű� j�� n���� ���� i�� ����
	// �� ���� �Ŵϱ� ���� �����͵鵵 sorted�� �������ش�.
	
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

	int* array = new int[N];   //�����Ҵ�

	for (int t = 0; t < N; t++) {
		cin >> array[t];
	}

	mergesort(array, 0, N - 1);

	for (int t=0; t < N; t++) {
		cout << array[t]<<endl;
	}
	
	delete[] array;   //���� ��
	return 0;
}