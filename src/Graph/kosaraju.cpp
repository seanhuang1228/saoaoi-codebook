// 0-base
vector<int> graph[MAXN];
vector<int> rev_graph[MAXN];
vector<int> path;
int visit[MAXN];
int group[MAXN];
int gindex = 0;
void dfs1(int root) {
    if (visit[root]) return;
    visit[root] = 1;
    for (auto it : graph[root])
        dfs1(it);
    path.push_back(root);
}
void dfs2(int root, int gid) {
    if (visit[root]) return;
    visit[root] = 1;
    group[root] = gid;
    for (auto it : rev_graph[root])
        dfs2(it, gid);
}
void kosoraju (int node_cnt) {
    for (int i = 0; i < node_cnt; ++i)
        for (auto child : graph[i])
            rev_graph[child].push_back(i);

    for (int i = 0; i < node_cnt; ++i)
        if (!visit[i]) dfs1(i);

    for (int i = 0; i < node_cnt; ++i)
        visit[i] = 0;

    for (int i = path.size() - 1; i >= 0; i--)
        if (!visit[path[i]])
            dfs2(path[i], gindex++);
}