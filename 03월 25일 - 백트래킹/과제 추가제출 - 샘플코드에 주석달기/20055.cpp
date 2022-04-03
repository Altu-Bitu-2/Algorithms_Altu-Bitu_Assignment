#include <iostream>
#include <vector>

using namespace std;

struct info { //내구도와 로봇 존재 여부
    int power;
    bool is_on;
};

vector<info> belt;  //컨테이너 벨트 정보(내구도, 로봇 여부)
int zero_power;     //내구도가 0인 벨트 칸의 개수

int minusPosition(int n, int pos) { //인덱스 감소
    if (--pos >= 0) { // 위치 인덱스 줄이기 
        return pos; 
    }
    return n * 2 - 1;
}

void second(int n, int start, int end) {
    int cur = end;
    while (cur != start) { //end - 1 부터 start 까지 검사
        cur = minusPosition(n, cur); // 위치 인덱스 업데이트 
        int next = (cur + 1) % (n * 2); //다음 위치
        if (belt[cur].is_on && !belt[next].is_on && belt[next].power) { //현재 위치에 로봇이 있고, 다음 위치에 로봇이 없으며 내구성 1이상인 경우 -> 로봇 옮김
            belt[cur].is_on = false; // 내렸으므로 false로 업데이트  
            belt[next].power--; // 옮긴 위치의 내구성 -1 업데이트 
            if (next != end) { //내리는 위치 아닐 경우만
                belt[next].is_on = true; //로봇 옮기기
            }
            if (belt[next].power == 0) { // 내구성 0이면 
                zero_power++; // 내구성 0 개수 업데이트 
            }
        }
    }
}

void third(int start) {
    if (belt[start].power) { //올리는 위치의 내구도가 0이 아니라면 로봇 올림
        belt[start].is_on = true; // 올렸으므로 true로 업데이트 
        belt[start].power--; // 내구성 줄여주기 
        if (belt[start].power == 0) { // 내구성 0이면 
            zero_power++; // 내구성 0 개수 업데이트 
        }
    }
}

/**
 * [컨베이어 벨트 위의 로봇 문제]
 * 1. 벨트가 각 칸 위의 로봇과 함께 한 칸 회전
 * 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동 (이동가능: 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1 이상이어야 함)
 * 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
 * 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료. 그렇지 않다면 1로 돌아감
 * -> 1 ~ 3까지가 1단계
 *
 * [문제 풀이]
 * 벨트의 로봇을 옮기는 게 아니라, 올리는 위치와 내리는 위치의 인덱스 값을 바꿔서 접근
 * 필요한 컨테이너: 내구도와 로봇의 존재여부를 체크할 배열
 *
 * 1번: 벨트의 방향이 오른쪽이므로, 벨트 한 칸 회전 시 올리는 위치와 내리는 위치의 인덱스 값은 하나 감소
 * 2번: 가장 먼저 올라간 로봇부터 고려해야 하므로 (내리는 위치 - 1)부터 (올리는 위치)까지 검사 -> 로봇 옮기는 거 가능하면 존재여부 체크하고 내구도 감소
 * 3번: 올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
 *
 * 해당 문제는 deque 자료구조를 사용해서도 구현 가능 (1번에서 회전하는 부분만 다르고 2번, 3번은 동일한 로직)
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    //입력
    cin >> n >> k; // 컨베이어 벨트 길이, 가능한 내구도 0 개수 
    belt.assign(n * 2, {0, false}); // 내구도 0, 로봇 X로 초기화 
    for (int i = 0; i < n * 2; i++) {
        cin >> belt[i].power; // 내구도 입력받기 
    }

    //연산
    int start = 0;    //올리는 위치
    int end = n - 1;  //내리는 위치
    int step = 0;     //단계 수
    while (true) {
    	// 1. 벨트 회전 
        start = minusPosition(n, start);
        end = minusPosition(n, end);
        
        if (belt[end].is_on) { //벨트 회전 후, 로봇이 내리는 위치에 있다면 내리기
            belt[end].is_on = false; // 내렸음을 표시 
        }
        // 2
        second(n, start, end); 
        // 3
        third(start);
        step++; // 단계 +1 업데이트 
        if (zero_power >= k) { // 내구도 0인 것이 k개가 되면 
            break; // 과정 종료 
        }
    }

    //출력
    cout << step;
    return 0;
}
