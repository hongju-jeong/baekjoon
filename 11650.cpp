#include<iostream>

using namespace std;

int main() {

	int N;
	int tempx = 0, tempy = 0;
	cin >> N;

	int* x = new int[N];
	int* y = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (x[j] >= x[j + 1]) {                          //y °í·Á ÇØ¾ß µÊ
				if (x[j] == x[j + 1]) {
					if (y[j] > y[j + 1]) {
						tempy = y[j];
						y[j] = y[j + 1];
						y[j + 1] = tempy;
					}
				}
				else {
					tempx = x[j];
					x[j] = x[j + 1];
					x[j + 1] = tempx;
					tempy = y[j];
					y[j] = y[j + 1];
					y[j + 1] = tempy;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << x[i] << ' ' << y[i] << endl;
	}

	delete[] x;
	delete[] y;

	return 0;
}