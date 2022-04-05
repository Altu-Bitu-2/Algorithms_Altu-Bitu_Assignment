//
// Created by ZERO-black 
// 튜터분이 작성하신 라이브 코드를 일부 수정했습니다. 
// 

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 5e6; // k의 범위 

vector<int> isPrime() {
    // n 이하의 수를 소인수분해하는 경로를 리턴
    vector<int> prime(MAX + 1, 0); //0번 인덱스 비워놓고 1부터 시작할 것이기 때문에 MAX + 1 
    for (int i = 2; i * i <= MAX; i++) {
        // 소수가 아니면 continue
        if (prime[i] != 0) {
            continue;
        }
        // i가 소수라면
        // i부터 i*(i-1)은 이미 앞선 소수들에 의해 지워졌음.
        for (int j = i * i; j <= MAX; j += i) { // j의 배수를 지우는 것이므로 j += i  
            if (prime[j] == 0) { // j가 0이라는 것은 아직 안 지워졌다는 의미 
                prime[j] = i; // j를 지우는 소수인 i를 넣어주기 
            }
        }
    }
    return prime; // prime 배열 return 하기 
}


int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n;
    cin >> n;

    // 소수 경로 구하기
    auto prime = isPrime(); // 결론적으로, is_prime[i]에는 i의 가장 작은 소인수가 들어가게 됨
							// cf) vector<int> 라고 써도 되지만 auto 라고 쓰면 자동으로 자료형을 인식해준다. 이 코드가 훨씬 간결하다. 
    while (n--) {
        int k;
        cin >> k;

        // prime[k] != 0이면 소수가 아님 -> k가 소수가 될 때까지 소인수분해 해주기 
        while (prime[k] != 0) { // 0이면 소수가 되어 종료됨 
            cout << prime[k] << ' '; // 해당 수에 저장되어있는 소수 출력 
            k /= prime[k]; // k를 해당 소수로 나눈 값을 다시 k에 넣어주기 
        }
        // 마지막 남은 소수 k 출력
        cout << k << '\n';
    }

    return 0;
}
