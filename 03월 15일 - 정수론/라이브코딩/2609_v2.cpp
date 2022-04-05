//
// Created by ZERO-black 
// 튜터분이 작성하신 라이브 코드를 일부 수정했습니다. 
//

// version 2. 유클리드 호제법 원리를 이용하여 최대공약수 구하기
// 추천! 시간복잡도가 O(log(n))으로 시간복잡도가 O(n)인 version 1보다 더 효율적이다. 

#include <iostream>

using namespace std;

// 유클리드 호제법
int gcdRecursion(int a, int b) {
    // a > b 일 때, a와 b의 최대공약수를 리턴
    if (b == 0) { //이 때 최대공약수 
        return a;
    }
    return gcdRecursion(b, a % b); //아직 b==0이 아니면, swap해서 재귀함수 수행 
}

int main() {
    // 입력
    int a, b;
    cin >> a >> b;

    // 최대공약수
    int g = gcdRecursion(max(a, b), min(a, b)); // a>b 라고 가정해야하므로 max, min 함수 이용 
    // 최소공배수 
    int l = a * b / g; // [두수의 곱 = 최대공약수 * 최소공배수] 식을 이용 

    // 출력
    cout << g << '\n' << l << '\n';
    return 0;
}
