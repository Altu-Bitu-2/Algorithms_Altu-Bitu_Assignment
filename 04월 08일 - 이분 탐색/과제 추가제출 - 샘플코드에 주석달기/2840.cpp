#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, char> ci;

//특정 화살표에서 시작한 행운의 바퀴 리턴
string arrowStartWheel(int arrow_point, int n, vector<char> &wheel) {
    string ans = "";
    int start = arrow_point;
    do {
        ans += wheel[arrow_point]; // ans 업데이트 
        arrow_point = (arrow_point + 1) % n; // 다음 칸 
    } while (arrow_point != start); // 처음으로 돌아오기 전까지 
    return ans;
}

//행운의 바퀴 구하는 함수
string makeWheel(int n, vector<ci> &record) {
    vector<char> wheel(n, '?'); //바퀴의 상태
    vector<bool> is_available(26, false); //알파벳 중복 체크

    int idx = 0; //화살표가 가리키는 인덱스
    for (int i = 0; i < record.size(); i++) {
        int rot = record[i].first;  
        char alpha = record[i].second;
        idx = (idx - rot % n + n) % n; // 해당 칸으로 화살표 이동시키기 
        if (wheel[idx] == alpha) { // 중복이면
            continue; // 넘어가기 
        }
        if (wheel[idx] != '?' || is_available[alpha - 'A']) { // 해당하는 바퀴가 없다면 
            return "!"; // ! 리턴 
        }
        wheel[idx] = alpha; // 해당 칸에 맞는 알파벳 넣어주기 
        is_available[alpha - 'A'] = true; // 알파벳 사용 업데이트 
    }
    return arrowStartWheel(idx, n, wheel);
}

/**
 * [행운의 바퀴]
 *
 * 바퀴가 돌아갈 필요 X
 * 화살표가 가르키는 인덱스를 회전 정보에 따라 바꿔줌
 *
 * 1. 화살표가 가르키는 칸이 결정되지 않았으면 알파벳을 바퀴에 적는다.
 * 2. 이미 알파벳이 써 있는 경우, 같은 알파벳이 아닌 경우 조건에 해당하는 바퀴 만들 수 없다.
 * 3. 바퀴에 쓰여있는 알파벳은 중복되지 않으므로 동일한 알파벳이 여러 자리에 있을 수 없다.
 */

int main() {
    int n, k; 

    //입력
    cin >> n >> k; // 바퀴의 칸 수와 돌리는 횟수 
    vector<ci> record(k, {0, 0}); //바퀴 회전 기록
    for (int i = 0; i < k; i++) { 
        cin >> record[i].first >> record[i].second; // pair의 first에는 화살표가 가리키는 글자가 변하는 횟수, second에는 어떤 글자에서 멈추었는지 저장  
    }

    //연산 & 출력
    cout << makeWheel(n, record);
    return 0;
}
