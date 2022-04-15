#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll cntTree(int height, vector<int> &tree) {
    ll sum = 0;
    for (int i = 0; i < tree.size(); i++) {
        if (height >= tree[i]) { // 해당 tree 높이보다 높으면 
            return sum; // 더이상 더할 필요X 
        }
        sum += (tree[i] - height); // tree가 높다면 sum 업데이트 
    }
    return sum;
}

int upperSearch(int left, int right, int target, vector<int> &tree) {
    while (left <= right) { // left가 최고 높이를 넘지 않을 때까지 
        int mid = (left + right) / 2; // 중간 값 
        ll tree_cnt = cntTree(mid, tree); 

        if (tree_cnt >= target) { // 필요한 나무의 길이보다 더 길다면 
            left = mid + 1; // left 값 업데이트 
        } else {
            right = mid - 1; // right 값 업데이트 
        }
    }
    return left - 1;
}

/**
 * [나무 자르기]
 *
 * 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값은?
 * -> 절단기의 높이가 k(임의의 값)일 때, M미터의 나무를 집에 가져갈 수 있는가?
 *
 * left: 절단기의 최소 높이 -> 0
 * right: 절단기의 최대 높이 -> 주어진 나무 중 가장 높은 나무 높이
 *
 * !주의! int 자료형 범위를 넘어가므로 long long써야 함
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m; // 나무의 수, 필요한 나무의 길이 
    vector<int> tree(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> tree[i]; // 나무의 높이 
    }

    sort(tree.begin(), tree.end(), greater<>()); // 나무 높이 내림차순 정렬 

    //연산 & 출력
    cout << upperSearch(0, tree[0], m, tree);
    return 0;
}
