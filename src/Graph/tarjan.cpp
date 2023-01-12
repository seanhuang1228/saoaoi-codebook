vector<pii> graph[MAXN];
int dfn[MAXN], low[MAXN], visited_cnt = 0;
int mapping[MAXN], bcc_cnt = 0;
vector<pii> tree[MAXN];
int tree_mater[MAXN];
bool ans[MAXN];

stack<int> tarjan_stack;
void tarjan(int curr, int parent) {
    tarjan_stack.push(curr);
    dfn[curr] = low[curr] = ++visited_cnt;

    for (pii nxt : graph[curr]) {
        if (!dfn[nxt.first]) {
            tarjan(nxt.first, curr);
        }
        if (nxt.first != parent) {
            low[curr] = min(low[curr], low[nxt.first]);
        }
    }

    if (low[curr] == dfn[curr]) {
        while (tarjan_stack.top() != curr) {
            mapping[tarjan_stack.top()] = bcc_cnt;
            tarjan_stack.pop();
        }
        mapping[tarjan_stack.top()] = bcc_cnt;
        tarjan_stack.pop();
        bcc_cnt++;
    }
}