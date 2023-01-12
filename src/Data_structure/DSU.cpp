struct dsu {
  vector<size_t> pa, size;
  dsu(size_t size_) : pa(size_), size(size_, 1) {
    iota(pa.begin(), pa.end(), 0);
  }
  void unite(size_t x, size_t y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (size[x] < size[y]) swap(x, y);
    pa[y] = x;
    size[x] += size[y];
  }
  size_t find(size_t x) {
    return pa[x] == x ? x : find(pa[x]);
  }
  void com_unite(size_t x, size_t y) {
    pa[find(x)] = find(y);
  }
};