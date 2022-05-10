#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e7; //최대 n-1개의 연결관계 있으므로 -> n * (가중치 최대값)

//다익스트라
ci dijkstra(int start, int v, vector<vector<ci>> &graph) {
    priority_queue<ci, vector<ci>, greater<>> pq;
    vector<int> dist(v + 1, INF);

    dist[start] = 0;
    pq.push({0, start});
    int cnt = 0, t = 0;
    while (!pq.empty()) {
    	// 가중치, 정점 미리 저장 
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop(); // 다음을 위해 pop 

        if (weight > dist[node]) { // 최솟값이 아니라면 
            continue; // 갱신 x 
        }
        cnt++; // 감염될 컴퓨터 수 업데이트 
        t = weight; // 총 걸리는 시간 업데이트 
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second; // 가중치 업데이트 
            if (next_weight < dist[next_node]) { // 더 값이 작다면 
                dist[next_node] = next_weight; // 갱신 
                pq.push({next_weight, next_node}); // pq에도 push 해주기 
            }
        }
    }
    return {cnt, t};
}

/**
 * [해킹]
 *
 * - 기본적인 다익스트라 문제
 * - 다익스트라 내에서 이미 더 짧은 경로가 존재하는 정점은 탐색에서 배제하면서, 탐색하는 정점의 수와 마지막 시간을 저장
 *
 * !주의! 그래프 생성 시, a가 b를 의존한다는 건 b 감염 후 a가 감염된다는 뜻이므로 b -> a 방향임
 */

int main() {
    int t, n, d, c, a, b, s;

    //입력
    cin >> t; // 테스트케이스 
    while (t--) {
        cin >> n >> d >> c; // 컴퓨터 개수, 의존성 개수, 해킹당한 컴퓨터 번호 
        vector<vector<ci>> graph(n + 1, vector<ci>(0)); //방향 그래프
        while (d--) {  
            cin >> a >> b >> s; // a가 b 의존, 감염되는데 걸리는 시간 
            graph[b].push_back({a, s}); // b에 의존하는 컴퓨터, 걸리는 시간 저장 
        }

        //연산
        ci ans = dijkstra(c, n, graph);

        //출력
        cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;
}
