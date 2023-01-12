vector<pii> graph[MAXN];
int dist[MAXN] = {};
void dijkstra(int s) { // 0-base
    int is_visited[MAXN] = {};
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int curr_node = pq.top().second;
        pq.pop();
        if (is_visited[curr_node])
            continue;
        is_visited[curr_node] = 1;
        for (auto edge : graph[curr_node]) {
            if (!is_visited[edge.first] and dist[edge.first] > dist[curr_node] + edge.second) {
                dist[edge.first] = dist[curr_node] + edge.second;
                pq.push({dist[curr_node] + edge.second, edge.first});
            }
        }
    }
} // graph[from].pb({to, cost})