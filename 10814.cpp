#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class Id {
private:
	int age;
	string name;
	int number;
public:
	Id(int _age, string _name, int _number) : age(_age), name(_name), number(_number) {}
	int get_num();
	int get_age();
	string get_name();
};
int Id::get_num() { return number; }
int Id::get_age() { return age; }
string Id::get_name() { return name; }

bool comp(Id& v1,Id& v2)
{
	if (v1.get_age() == v2.get_age()) {
		return v1.get_num() < v2.get_num(); //v1이 v2보다 먼저 가입했다면 true == 위치변환 x
	}
	return v1.get_age() < v2.get_age();
}

int main()
{
	int N;
	cin >> N;

	vector<Id> v;
	int age;
	string name;

	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		v.emplace_back(age, name, i);
	}

	//vector<Id>::iterator iter;

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < N; i++) {
		cout << v[i].get_age() << ' ' << v[i].get_name() << endl;
	}
	return 0;
}