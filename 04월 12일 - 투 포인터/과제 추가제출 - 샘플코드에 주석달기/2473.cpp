#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 3 * 1e9 + 1;

ll min_diff = INF;

//다른 위치에서 시작하여 서로를 향해 가까워지는 투 포인터
pair<ll, ll> liquid(vector<ll> &arr, ll fixed, int left, int right) {
    pair<ll, ll> ans;
    ans = make_pair(INF, INF); // 초기값 

    while (left < right) { // left가 right를 넘어서면 멈춘다 
        ll mix = fixed + arr[left] + arr[right]; 
        if (mix == 0) { // 0이면 더이상 할 필요 X  
            return make_pair(arr[left], arr[right]); // return  
        }
        if (abs(mix) < min_diff) { // 음수도 있으므로 절댓값과 최솟값을 비교  
            min_diff = abs(mix); // 최솟값 업데이트  
            ans = make_pair(arr[left], arr[right]);
        }
        if (mix > 0) { // 0보다 크다면  
            right--; // 오른쪽 포인터를 왼쪽으로 옮기기 
        } else { // 0보다 작으면 
            left++; // 왼쪽 포인터를 오른쪽으로 옮기기 
        }
    }
    return ans;
}

/**
 * 2470번 : 두 용액 섞기
 * 2473번 : 세 용액 섞기
 *
 * [세 용액]
 *
 * 1. 하나의 용액을 반드시 사용한다고 가정
 * 2. 용액 하나 고정
 * 3. 해당 용액 이후의 범위에 대해 투 포인터 알고리즘 적용
 *
 * pair : 2개의 값 저장
 * tuple : 3개의 값 저장
 *
 * !주의! 세 용액의 최댓값은 1e9(=10억)이기 때문에 3개를 섞은 최댓값은 30억이고, int를 넘어감!
 */
int main() {
    int n;

    //입력
    cin >> n; // 용액 수  
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // 용액의 특성값 
    }

    //연산
    sort(arr.begin(), arr.end()); // 오름차순 정렬 
    for (int i = 0; i < n - 2; i++) {
        pair<ll, ll> p = liquid(arr, arr[i], i + 1, n - 1); //arr[i] 용액은 고정
        if ((p.first != INF) && (p.second != INF)) { //최솟값이 갱신된 경우
            ans = make_tuple(arr[i], p.first, p.second); // 값 업데이트 
        }
    }

    //출력
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans);
    return 0;
}
