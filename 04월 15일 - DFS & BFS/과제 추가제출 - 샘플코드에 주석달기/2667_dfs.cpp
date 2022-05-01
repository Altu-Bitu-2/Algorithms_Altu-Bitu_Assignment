#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

int n;
vector<vector<bool>> board;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};


//단지 내 집 개수 탐색하는 dfs
int dfs_recursion(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n) { //인덱스 에러 방지
        return 0; // return 0
    }
    if (!board[r][c]) { //집이 있는지 (이미 방문 했는지) 확인
        return 0; // return 0
    }
    int cnt = 1;
    board[r][c] = false; 

    for (int i = 0; i < 4; i++) {
        cnt += dfs_recursion(r + dr[i], c + dc[i]); // 좌표 이동해가며 1 탐색하여 cnt 개수 업데이트 
    }
    return cnt;
}

//단지 수와 단지 내 집 개수 구하는 함수
vector<int> cntComplex(int n, vector<vector<bool>> &board) {
    vector<int> complex;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) { // 1이라면 
                int cnt = dfs_recursion(i, j); // dfs 재귀함수 
                complex.push_back(cnt); // 단지의 집 개수 넣어주기 
            }
        }
    }
    return complex;
}

/**
 * [단지 번호 붙이기] - dfs
 *
 * 단순 탐색
 * (주의) 단지 내 집의 수를 "오름차순"으로 출력
 *
 * 이 풀이에서는 방문체크 배열을 따로 사용하지 않고, 처음 지도에 표기를 1 -> 0으로 바꾸어 중복으로 탐색하지 않도록 함
 */

int main() {
    string s;

    //입력
    cin >> n; // 지도의 크기 
    board.assign(n, vector<bool>(n, false)); 
    for (int i = 0; i < n; i++) {
        cin >> s; // string으로 채우기 
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j] - '0'; // 정수로 변환 
        }
    }

    //연산
    vector<int> ans = cntComplex(n, board);
    sort(ans.begin(), ans.end()); // 오름차순 정렬 

    //출력
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
