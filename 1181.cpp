#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool comp(const string& s1, const string& s2) {
	if (s1.size() == s2.size()) {
		return s1 < s2;    //s1이 s2보다 사전순으로 앞이면 true == 위치변환 x
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

	sort(v.begin(), v.end(), comp);   //comp는 판단기준 boolean false면 자리 바꿈

	end_iter = unique(v.begin(), v.end()); //겹치는거 걸러내고 마지막으로 주루룩 보내버림 쓰레기처리
	                                       //ㄴ 그 보낸거에서 첫 번째 부분
	for (iter = v.begin(); iter != end_iter; iter++) {
		cout << *iter << endl;
	}
	return 0;
}