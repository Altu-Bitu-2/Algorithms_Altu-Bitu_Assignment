#include <iostream>
#include <vector>

using namespace std;

vector<int> check(26, 0); // 해당 알파벳이 문자열에서 등장했는지 확인해주는 vector

int isCheck(char c) {
	if (check[c - 'a']) return 1; // check 되어있으면 1 return
	else return 0; // check 안되어있으면 0 return 
}

int isGroup(string word) {
	check[word[0] - 'a'] = 1; // 첫번째 글자 업데이트  
	for (int i = 0; i < word.size() - 1; i++) {
		if (word[i] == word[i + 1]) continue; // 연속된 알파벳이 나오면 그룹 유지 
		else { // 다른 알파벳이 나오면 
			// 처음 등장하는 알파벳인지 체크
			if (!isCheck(word[i + 1])) check[word[i + 1] - 'a'] = 1; // 처음 등장이면 check 업데이트
			else return 0; // 이미 등장했으면 그룹 단어 아님	
		}
	}
	return 1; // 끝까지 다 돌았으면 return 1 

}

int main() {
	int n;
	cin >> n; // 단어 개수 입력 

	int groupNum = 0; // 그룹 단어 개수를 업데이트 해줄 변수
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word; // 단어 입력
		groupNum += isGroup(word);  // 각 단어별로 그룹단어인지 확인 후 총 그룹단어 개수 업데이트
		fill(check.begin(), check.end(), 0); // 전역변수 check 초기화 
	}

	// 출력
	cout << groupNum;

	return 0;
}