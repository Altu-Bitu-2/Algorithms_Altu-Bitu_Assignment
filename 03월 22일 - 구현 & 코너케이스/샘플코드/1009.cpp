#include <iostream>
#include <vector>

using namespace std;

vector<int> findPattern(int num) {
    vector<int> pattern = {num}; 

    int temp = num;
    while (num != (temp * num) % 10) { // 맨 처음 일의 자리 수로 다시 돌아올 때까지 반복 
        temp *= num; // 일의 자리끼리 곱하고 
        temp %= 10; // 곱한 결과의 일의 자리만 남기기 
        pattern.push_back(temp); // pattern vector에 일의 자리 패턴 넣어주기 
    }
    return pattern; // 패턴 다 찾으면 return 
}

/**
 * [분산처리]
 *
 * - a^b의 일의 자리를 구하는 문제
 * - 일의 자리는 0 ~ 9 중 하나 이므로, 어떤 수를 계속 곱해 나가면 일의 자리는 패턴을 가지게 되어 있음
 *     ex) 2 -> 4 -> 8 -> 6 -> 2 ...
 * - 0 ~ 9까지 일의 자리 패턴을 미리 구한 후, a의 일의 자리에 대한 (b - 1 % 패턴의 길이)번째 수를 출력하면 된다.
 * - 0이 나올 경우 10번 컴퓨터가 처리하므로, 0이 출력되지 않도록 예외처리
 */

int main() {
    int t, a, b;

    //0 ~ 9까지 일의 자리 패턴 미리 구하기
    vector<vector<int>> last_digit(10, vector<int>(0)); // 일의 자리는 0~9가 될 수 있으므로 크기는 10, 우선 일의 자리별 패턴은 크기 0 
    vector<int> pattern_size(10, 1); // 각 일의 자리별 패턴 수 저장할 vector. 기본적으로 자기자신이 패턴 1이므로 모두 1로 초기화 
    for (int i = 0; i < 10; i++) {
        last_digit[i] = findPattern(i); // 일의 자리 0~9인 수의 패턴 찾기 
        pattern_size[i] = last_digit[i].size(); // 해당 일의 자리수의 패턴 횟수 넣어주기 
    }

    //입력
    cin >> t; // 테스트케이스 입력 
    while (t--) { 
        cin >> a >> b; // 데이터 개수인 a, b 입력받기 
        a %= 10; // a의 일의 자리만 확인하면 되므로 a % 10 하여 a에 저장 
	
		// 일의 자리가 0일 때는 10번 컴퓨터가 처리하므로 0이 나오지 않도록 예외처리 
        if (a == 0) {
            cout << "10\n";
            continue;
        }
        //인덱스가 0부터 시작하므로 (b - 1)로 계산해야 함을 주의
        cout << last_digit[a][(b - 1) % pattern_size[a]] << '\n'; // a의 일의 자리에 해당되는 패턴에 접근. 이 때 b - 1을 패턴 사이즈로 나누어서 패턴 중 어느 것인지 구하기 
    }
    return 0;
}
