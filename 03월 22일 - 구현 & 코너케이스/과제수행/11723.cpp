#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> s;

bool check(int x) {
	// s가 비어있다면 그냥 0 return  
	if (s.empty()) return 0;
	// 존재하면 1 return 
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == x) {
			return 1;
		}
	}
	// 존재하지 않으면 0 return 
	return 0;
}

void add(int x) {
	// s에 아무것도 없다면 x 그냥 추가 
	if (s.empty()) {
		s.push_back(x);
		return;
	}
	// x가 이미 존재하면 연산 무시
	if (check(x)) return;
	// x 추가 
	s.push_back(x);
}

void remove(int x) {
	// s 사이즈 0이면 아무 작업 X
	if (s.size() == 0) {
		return;
	}
	// x 없애기 
	if (check(x)) {
		s.erase(std::remove(s.begin(), s.end(), x));
		return;
	}
	// x가 존재하지 않으면 연산 무시 
	return;
}

void toggle(int x) {
	// x 존재하면 x 제거 
	if (check(x)) remove(x);
	// x 존재하지 않으면 x 추가 
	else add(x);
}

void empty() {
	s.clear(); // 공집합으로 바꾸기 
}

void all() {
	empty(); // s를 공집합으로 바꾼 후 
	for (int i = 1; i <= 20; i++) { // 1부터 20까지 넣어주기 
		s.push_back(i);
	}
}

int main() {
	// 입출력 속도 향상
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m;
	cin >> m;

	string cmd;
	int x;
	for (int i = 0; i < m; i++) {
		cin >> cmd;
		if (cmd == "add") {
			cin >> x;
			add(x);
			continue;
		}
		if (cmd == "remove") {
			cin >> x;
			remove(x);
			continue;
		}
		if (cmd == "check") {
			cin >> x;
			cout << check(x) << "\n";
			continue;
		}
		if (cmd == "toggle") {
			cin >> x;
			toggle(x);
			continue;
		}
		if (cmd == "all") {
			all();
			continue;
		}
		if (cmd == "empty") {
			empty();
			continue;
		}
	}
	return 0;
}