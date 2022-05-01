#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//좋은 수인지 검사하는 함수(투 포인터)
bool isGood(vector<int> &num, int left, int right, int idx) {
    while (left < right) { // left가 right를 넘어가면 더이상 의미 X 
        if (left == idx) { // idx 수가 되버리면 
            left++; // left 포인터 오른쪽으로 이동 
            continue;
        }
        if (right == idx) { // idx 수가 되버리면 
            right--; // right 포인터 왼쪽으로 이동 
            continue;
        }

        if (num[left] + num[right] == num[idx]) { // 두 수의 합으로 나타나면 
            return true; // true
        }
        if (num[left] + num[right] > num[idx]) { // 수 넘어가면 
            right--; // right 포인터 왼쪽으로 이동 
        } else { // 수 작으면 
            left++; // left 포인터 오른쪽으로 이동 
        }
    }
    return false;
}

/**
 * [좋다]
 *
 * 1. 각 수마다 양 쪽 끝에서 포인터를 시작해서 좁혀오면서 어떤 '다른 두 수'가 현재 수를 만들 수 있는지 검사
 * 2. 포인터를 차례로 옮기며 검사하기 위해 미리 수를 오름차순 정렬함
 * 3. 현재 만드려는 수의 위치와 left, right 포인터 위치가 겹칠 경우 처리 주의
 */

int main() {
    int n, ans = 0;

    //입력
    cin >> n; // 수의 개수 
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> num[i]; // 수 입력받기 
    }

    //연산
    sort(num.begin(), num.end()); // 정렬  
    for (int i = 0; i < n; i++) {
        if (isGood(num, 0, n - 1, i)) {
            ans++; // 개수 업데이트 
        }
    }

    //출력
    cout << ans;
    return 0;
}
