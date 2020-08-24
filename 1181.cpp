#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool comp(const string& s1, const string& s2) {
	if (s1.size() == s2.size()) {
		return s1 < s2;    //s1�� s2���� ���������� ���̸� true == ��ġ��ȯ x
	}
	return s1.size() < s2.size();
}

int main() {

	vector<string> v;

	int N;
	cin >> N;

	string str;

	for (int i = 0; i < N; i++) {

		cin >> str;
		v.push_back(str);
	}

	vector<string>::iterator iter;
	vector<string>::iterator end_iter;

	sort(v.begin(), v.end(), comp);   //comp�� �Ǵܱ��� boolean false�� �ڸ� �ٲ�

	end_iter = unique(v.begin(), v.end()); //��ġ�°� �ɷ����� ���������� �ַ�� �������� ������ó��
	                                       //�� �� �����ſ��� ù ��° �κ�
	for (iter = v.begin(); iter != end_iter; iter++) {
		cout << *iter << endl;
	}
	return 0;
}