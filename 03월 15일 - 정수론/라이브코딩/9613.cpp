//
// Created by ZERO-black 
// 튜터분이 작성하신 라이브 코드를 일부 수정했습니다. 
//

#include <iostream>
#include <vector>

using namespace std;

 // 일반 gcd 함수 구현
int gcd(int a, int b) { //gcd 자체는 최대 1,000,000이므로 int 범위 내에 있기 때문에 return 값 int형 가능 
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

//가능한 모든 쌍의 GCD의 합을 구하기 
long long gcdSum(int n, vector<int> &v) {
	// 숫자 입력범위 1,000,000 -> gcd의 최댓값은 1,000,000
    // 숫자 집합 원소(숫자) 개수는 최대 100개 -> 가능한 GCD 쌍은 C(100, 2) = 4,950
    // sum <= 4,950,000,000 -> int 범위를 넘음. long long 사용
    long long sum = 0;

    // 가능한 모든 쌍의 최대공약수를 구해서, sum에 더하기
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // 자기자신과 짝이 되지 않도록 j = i+1 부터 
            sum += gcd(max(v[i], v[j]), min(v[i], v[j])); // gcd(a,b)에서 a>b 라고 가정하기 때문에 max, min 함수 사용 
        }
    }
    return sum;
}

int main() {
    // 입력
    int t; //테스트케이스 
    cin >> t;

    while (t--) { 
        int n;
        cin >> n; //확인하려는 숫자 집합의 원소(숫자) 개수  
        vector<int> v(n, 0); 
        for (int i = 0; i < n; i++) { 
            cin >> v[i]; //숫자 집합의 원소(숫자)들 입력받기
        }
        // 연산 + 출력
        cout << gcdSum(n, v) << '\n';
    }
}
