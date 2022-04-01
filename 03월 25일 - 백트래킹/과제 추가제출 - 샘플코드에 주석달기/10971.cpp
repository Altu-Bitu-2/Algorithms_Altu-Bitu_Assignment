#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e8;

vector<bool> visited; //방문 검사 배열
vector<vector<int>> matrix; //비용 행렬
int n, ans = INF; //최소 비용 저장 위해 미리 최댓값으로 초기화

void backtracking(int cnt, int cur_city, int cost) { // cnt : 방문하는 도시 횟수, cur_city : 현재 도시의 인덱스, cost : 누적 비용 
    if (cost >= ans) { 
        return;
    }
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) { // 다시 돌아올 수 있다면 
            ans = min(ans, cost + matrix[cur_city][0]); // 최소비용 업데이트 
        }
        return;
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            visited[i] = true; // 방문되었다고 업데이트 
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]); 
            visited[i] = false; // 원래대로 돌려놓기 
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 *
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {
    //입력
    cin >> n; // 도시의 수  
    visited.assign(n, false); // false로 초기화 
    matrix.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j]; // 비용행렬 채우기 
        }
    }

    //연산
    visited[0] = true; // 일단 출발점은 방문 
    backtracking(1, 0, 0);

    //출력
    cout << ans;
    return 0;
}
