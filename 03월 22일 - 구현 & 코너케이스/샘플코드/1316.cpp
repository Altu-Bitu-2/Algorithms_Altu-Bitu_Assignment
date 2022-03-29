#include <iostream>
#include <vector>

using namespace std;

bool isGroup(string str) {
    char cur = NULL; //현재의 문자
    vector<bool> alphabet(26, false); //각 알파벳의 등장 여부를 체크. 처음에는 false로 초기화 

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == cur) { //연속해서 나타난 문자
            continue; // 아직 그룹 단어임 
        }
        //이전의 문자와 다른 문자가 나타났을 때
        if (alphabet[str[i] - 'a']) { //이전에 등장했던 문자면 떨어져서 나타난 것
            return false; // 그룹 단어 아님 
        }
        cur = str[i]; // 현재 문자 업데이트 
        alphabet[str[i] - 'a'] = true; // 연속으로 나타난 문자가 아닌데 처음 등장하는 문자면 아직 그룹 단어 맞음. 대신 해당 문자를 true로 바꿔서 등장했음을 표시  
    }
    return true; // 단어의 모든 글자를 검사하고 나서도 그룹 단어이면 true 리턴 
}

/**
 * [그룹 단어 체커] - 단순 구현 문제
 * - 이미 등장한 알파벳을 배열의 인덱스(알파벳)를 활용해서 정보 true/false로 저장
 * - set으로 체크할 수도 있겠지만 검색, 삽입 시마다 O(logN)의 시간복잡도가 걸리므로 인덱스 접근이 가능한 배열이 효율적
 * - 처음 등장하는 알파벳은 배열 정보 업데이트 하고, 무리에서 떨어졌는데 이미 등장한 알파벳이면 그룹 단어가 아니다.
 */

int main() {
    int n, result = 0; 

    //입력
    cin >> n; // 단어의 개수 입력 
    while (n--) {
        string word;
        cin >> word; // 단어 입력 

        //연산
        if (isGroup(word)) { //그룹 단어인지 확인
            result++; // 그룹 단어라면 결과 +1 업데이트 
        }
    }

    //출력
    cout << result;
    return 0;
}
