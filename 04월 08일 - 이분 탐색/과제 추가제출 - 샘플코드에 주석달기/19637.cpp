#include <iostream>
#include <map>

using namespace std;

/**
 * [IF문 좀 대신 써줘]
 *
 * 모든 캐릭터와 칭호를 매칭하는 브루트 포스를 사용하기엔 최대 연산 횟수 10^5 * 10^5 -> 100억!
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음
 * -> 이분 탐색
 *
 * 맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있음
 */

int main() {
	//입출력 속도 향상 코드 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, string> title; //칭호와 그 칭호의 전투력 상한값

    int n, m, power;
    string name;

    //입력
    cin >> n >> m; // 칭호의 개수, 캐릭터 개수 
    while (n--) {
        cin >> name >> power; // n개의 칭호 이름, 해당 칭호의 전투력 상한값 
        if (title[power].empty()) { // 해당 power key의 값이 비어있다면  
            title[power] = name; // 해당 칭호 이름 넣어주기 
        }
    }

    //출력
    while (m--) { 
        cin >> power; // 캐릭터의 전투력 
        cout << title.lower_bound(power)->second << '\n'; // 전투력이 파워 미만인 값들 모두 출력 
    }
}
