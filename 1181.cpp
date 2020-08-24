#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {

	int N;
	cin >> N;

	vector<string> word(N);

	string temp;
	for (int i = 0; i < N; i++) {
		cin >> word[i];
	}

	for (int i = 0; i < N - 1; i++){
		for (int j = 0; j < N - i - 1; j++) {
			if (word[j].length() > word[j + 1].length()) {
				temp = word[j];
				word[j] = word[j + 1];
				word[j + 1] = temp;
			}
			if (word[j].length() == word[j + 1].length() && word[j] > word[j+1]) {
				temp = word[j];
				word[j] = word[j + 1];
				word[j + 1] = temp;
			}
			if (word[j] == word[j + 1])
			{ 
				word.erase(word.begin() + j);
			}
		}
	}
	


	for (int i = 0; i < word.size(); i++) {
		cout << word[i] << endl;
	}
	

	return 0;
}