#include<iostream>
#include<cmath>

using namespace std;
int N;


double arithmetic_mean(int a[]) {
	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += (double)a[i];
	}
	return round(sum / N);
}

int median(int a[]) {
	int temp=0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	return a[(N / 2)];
}

int mode(int a[]) {
	int dummy[8001] = { 0 };  //0~4000까지 -4000~ 0까지
	int max = 0;
	int temp = 0;
	int mo = 0;
	bool isSecond = false;
	for (int i = 0; i < N; i++)
	{
		if (a[i] >0) { dummy[a[i]+4000]++; temp = a[i]+4000; }
		else { dummy[a[i]+4000]++; temp = a[i] + 4000; }
		
		if (dummy[temp] > max) max = dummy[temp];
	}
	for (int i = -4000; i < 4001; i++) {
		temp = i + 4000;
		if (dummy[temp] == max) {
			mo = i;
			if (isSecond) {
				break;
			}
			isSecond = true;
		}
	}
	return mo;
}

int main() {
	cin >> N;

	int* a = new int[N];
	int max = -5000;
	int min = 5000;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (a[i] > max) max = a[i];
		if (a[i] < min) min = a[i];
	}

	cout << arithmetic_mean(a) << endl;
	cout << median(a) << endl;
	cout << mode(a) << endl;
	cout << max - min << endl;
	delete[] a;
	return 0;
}