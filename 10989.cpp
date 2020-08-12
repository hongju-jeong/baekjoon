#include<iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;

	cin >> T;

	int a[10001] = { 0};

	int num = 0;

	for (int i = 0; i < T; i++)
	{
		cin >> num;

		a[num-1]++;
	}

	for (int i = 0; i < 10001; i++) {
		if (a[i] != 0) {
			for (int j = 0; j < a[i]; j++) {
				cout << i+1 << '\n';
			}
		}
	}
	return 0;
}