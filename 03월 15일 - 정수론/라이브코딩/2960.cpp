//
// Created by ZERO-black 
// 튜터분이 작성하신 라이브 코드를 일부 수정했습니다. 
// 

#include <iostream>
#include <vector>

using namespace std;

// 에라토스테네스의 체를 활용해 소수를 찾는 함수
int findPrime(int n, int k) {
    vector<bool> is_prime(n + 1, true); //인덱스 n까지, 초기화는 true로 
    is_prime[0] = is_prime[1] = false; // 0과 1은 소수가 아니므로 false
   
    int cnt = 0;    // 지워진 수의 개수를 count
	
	// i가 소수인지 판단
    for (int i = 2; i <= n; i++) { // k번째에 지워지는 소수를 찾는 것이기 때문에, sqrt(n)까지가 아니라 i <=n 까지!
        // 1. i가 소수가 아니라면, 즉 i가 이미 false로 지워졌다면 넘어가기 
        if (!is_prime[i]) { 
            continue;
        }
        // 2. i가 소수라면, i의 배수를 순서대로 방문하기
        for (int j=i; j<= n; j +=i) { // 이 문제에서는 순서대로 i부터 지워야 하므로 j = i*i 가 아니라 j = i
            if (!is_prime[j]) { // 소수가 아니라면, 즉 이미 false로 지워졌다면 넘어가기
                continue;
            }
            
            // 찾은 소수 false로 지우고 지운 횟수인 cnt 값 +1 해주기 
            is_prime[j] = false; //소수를 찾았다면 false로 바꿔서 지워주기 
            if (++cnt == k) { //방금 지워진 수가 k번째로 지워진 것이라면 j를 리턴 
                return j;
            }
        }
    }
    return -1; // for문에 들어가지 않을 경우를 대비하여 findPrime의 return값 만들어주기 
}

int main() {
    // 입력
    int n, k; 
    cin >> n >> k;
    // 연산 + 출력
    cout << findPrime(n, k); 
    return 0;
}
