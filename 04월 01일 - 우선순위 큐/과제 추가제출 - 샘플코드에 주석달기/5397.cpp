#include <iostream>
#include <deque>

using namespace std;

string dqToString(deque<char> &dq) {
    string ans = "";
    while (!dq.empty()) { // 모든 값 접근 
        ans += dq.front(); // ans에 하나하나 넣어주기 
        dq.pop_front(); // 다음 값을 위해 pop 
    }
    return ans;
}

string findPass(string s) {
    deque<char> dq_left;  //커서 이전 내용을 저장
    deque<char> dq_right; //커서 이후 내용을 저장

    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) { // 문자 하나하나 접근 
            case '-': //현재 커서 앞에 있는 글자를 지운다.
                if (!dq_left.empty()) { // 커서 이전 내용이 있다면 
                    dq_left.pop_back(); // 지우기 
                }
                break;
            case '<': //커서를 왼쪽으로 이동 -> dq_left 의 마지막 원소를 dq_right 앞에 삽입
                if (!dq_left.empty()) { // 커서 이전 내용이 있다면 
                    dq_right.push_front(dq_left.back()); // 커서 오른쪽은 하나 더 늘어난 효과 
                    dq_left.pop_back(); // 커서 왼쪽은 맨 뒤에 있던 문자가 사라진 효과 
                }
                break;
            case '>': //커서를 오른쪽으로 이동 -> dq_right 의 처음 원소를 dq_left 의 마지막에 삽입
                if (!dq_right.empty()) { // // 커서 이전 내용이 있다면 
                    dq_left.push_back(dq_right.front()); // 커서 왼쪽은 하나 더 늘어난 효과 
                    dq_right.pop_front(); // 커서 오른쪽은 맨 앞에 있던 문자가 사라진 효과 
                }
                break;
            default: //문자인 경우, 입력을 하면 커서보다 왼쪽에 위치하므로 dq_left에 삽입
                dq_left.push_back(s[i]); // 왼쪽에 해당 문자 넣어주기 
                break;
        }
    }
    
	// string으로 바꿔주는 함수
    string pass = dqToString(dq_left); // 왼쪽 먼저 
    pass += dqToString(dq_right); // 오른쪽 후 왼+오 합치기 
    return pass;
}

/**
 * [키로거]
 *
 * 해당 풀이는, 글자 삽입 삭제 시 이동시키는 과정에서 생기는 코너케이스를 해결하기 위해 커서를 기준으로 왼쪽, 오른쪽으로 나눠서 값을 저장함
 *
 * 1. 커서 앞의 글자를 지울 때, 글자가 없는 경우 주의
 * 2. 커서를 왼쪽으로 이동할 때, 이미 가장 왼쪽에 커서가 있는 경우 주의
 * 3. 커서를 오른쪽으로 이동할 때, 이미 가장 오른쪽에 커서가 있는 경우 주의
 */

int main() {
    int t;
    string s; 

    //입력
    cin >> t; // 테스트케이스 
    while (t--) {
        cin >> s; // 입력한 문자열 

        //연산 & 출력
        cout << findPass(s) << '\n';
    }
    return 0;
}
