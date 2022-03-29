#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int SIZE = 21; // 입력 x의 값은 1~20의 숫자. 0번 인덱스를 비우기 위해 SIZE는 20이 아니라 21 

/**
 * [집합] - 단순 구현 문제
 *
 * ver1. 배열 사용 풀이
 * set()을 사용해서 매번 연산을 하면 시간이 굉장히 오래 걸려요.
 * 입력되는 x의 값이 1~20으로 범위가 매우 작기 때문에, 각 숫자가 집합에 들어있는 여부를 저장하는 배열을 이용합니다.
 *
 * 1. 집합에는 1~20의 숫자만 입력 or 제거됨 (=true or false)
 * 2. 크기 21의 bool 배열을 선언
 * 3. 입력은 true 처리, 제거는 false 처리
 */

int main() {
	// 시간 단축  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
`	
    int m, num;
    string cmd;
    vector<bool> s(SIZE, false); // 1~20 중 x에 존재하는 수를 나타내는 vector. 아직 아무것도 없으므로 모두 false로 초기화  

    cin >> m; // 수행할 연산의 수 입력 
    while (m--) {
        cin >> cmd; // 수행연산 입력 
        if (cmd == "all") { 
            s.assign(SIZE, true); // 1~20까지 모든 수를 넣으므로 모두 true로 바꿔주기 
            continue;
        }
        if (cmd == "empty") { // 1~20까지 모든 수를 없애므로 모두 false로 바꿔주기 
            s.assign(SIZE, false);
            continue;
        }

        cin >> num; // 연산에 해당하는 x 입력받기 
        if (cmd == "add") {
            s[num] = true; // 해당 수를 넣어야하므로 해당 수만 true로 바꿔주기 
            continue;
        }
        if (cmd == "remove") {
            s[num] = false; // 해당 수를 없애야하므로 해당 수만 false로 바꿔주기 
            continue;
        }
        if (cmd == "check") {
            cout << s[num] << '\n'; //bool 형을 출력하면 true: 1, false: 0으로 출력
            continue;
        }
        if (cmd == "toggle") {
            s[num] = !s[num]; // 해당 수가 있으면(true) false를 넣어주고, 없으면(false) true를 넣어줌 
            continue;
        }
    }
    return 0;
}
