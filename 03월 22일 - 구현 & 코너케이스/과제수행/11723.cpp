#include <iostream>
#include <vector>

using namespace std;

vector<int> s;

void add(int x) {
	// s 사이즈 0이면 그냥 추가 
	if (s.size() == 0) {
		s.push_back(x);
		return;
	}
	// x가 이미 존재하면 연산 무시
	for (int i=0;i<s.size();i++) {
		if (s[i] == x) return;
	}
	// x 추가 
	s.push_back(x);
}

void remove() {
	// s 사이즈 0이면 아무 작업 X
	if (s.size() == 0) {
		return;
	}
	// x 없애기 
	for (int i=0;i<s.size();i++) {
		if (s[i] == x) {
			s.erase(s.begin() + i);
		} 
	}
	
	// x가 존재하지 않으면 연산 무시 
	return;
}

bool check() {

}

void toggle() {
	
}

void all() {
	
}

void empty() {
	
}

int main() {
	int m;
	cin >> m;
	
	string cmd;
	int x; 
	for (int i=0;i<m;i++) {
		cin >> cmd >> x;
		if (cmd == "add") add(x);
		if (cmd == "remove") remove();
		if (cmd == "check") check();
		if (cmd == "toggle") toggle();
		if (cmd == "all") all();
		if (cmd == "empty") empty();
	}
	for (int i=0;i<s.size();i++) {
			cout << s[i];
	}
	
	return 0;
} 
