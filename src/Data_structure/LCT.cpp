// warning: it may not correct
struct LCT { // use tree size as example
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1])
#define NORMAL 0
#define fa(x) (tree[x].fa)
#define get(x) (tree[tree[x].fa].ch[1] == x)
#define is_root(x) (tree[tree[x].fa].ch[0] != x and tree[tree[x].fa].ch[1] != x)
  struct Node {
    int ch[2] = {};
    int fa = 0, rev = 0;
    int size = 0, v_size = 0;
  } tree[MAXN + 1];
  void reverse(int x) {
    if (x) {
      swap(lson(x), rson(x));
      tree[x].rev ^= 1;
    }
  }
  void push_up(int x) {
    tree[x].size = 1 + tree[lson(x)].size + tree[rson(x)].size + tree[x].v_size;
    // and other attribute you want
  }
  void push_down(int x) {
    if (tree[x].rev != NORMAL) {
      reverse(lson(x));
      reverse(rson(x));
      tree[x].rev = NORMAL;
    }
    // and other tag you want
  }
  void update(int x) {
    if (!is_root(x)) update(fa(x));
    push_down(x);
  }
  void rotate(int x) {
    int father = fa(x), gfather = fa(father), is_right = get(x);
    if (!is_root(father)) tree[gfather].ch[get(father)] = x;
    tree[father].ch[is_right] = tree[x].ch[!is_right], tree[tree[x].ch[!is_right]].fa = father;
    tree[x].ch[!is_right] = father, fa(x) = gfather, fa(father) = x;
    push_up(father), push_up(x);
  }
  void splay(int x) {
    update(x);
    while (!is_root(x)) {
      int father = fa(x);
      if (!is_root(father))
        rotate(get(father) == get(x) ? father : x);
        rotate(x);
      }
    push_up(x);
  }
  int access(int x) {
    int new_ch = 0;
    while (x) {
      splay(x);
      tree[x].v_size -= tree[new_ch].size - tree[rson(x)].size;
      rson(x) = new_ch, push_up(x);
      new_ch = x, x = fa(x);
    }
    return new_ch;
  }
  void make_root(int x) {
    int new_splay_root = access(x);
    reverse(new_splay_root);
  }
  void link(int x, int p) {
    make_root(x);
    splay(x);
    fa(x) = p;
    tree[p].v_size += tree[x].size;
    push_up(p);
  }
  void split(int x, int y) {
    make_root(x);
    access(y);
    splay(y);
  }
  void cut(int x, int y) {
    split(x, y);
    fa(x) = lson(y) = 0;
    push_up(y);
  }
  int find(int x) {
    access(x);
    splay(x);
    push_down(x);
    while (lson(x)) {
      x = lson(x);
      push_down(x);
    }
    return x;
  }
  int query(int x, int y) {
    split(x, y);
    return tree[y].size;
  }
} lctree;