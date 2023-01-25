struct Treap {
  Treap *l, *r;
  int pri, key, val;
  Treap(int _val, int _key)
    : val(_val), key(_key), l(nullptr), r(nullptr), pri(rand()) {}
};
Treap *merge(Treap *a, Treap *b) {
  if (!a || !b) return a ? a : b;
  if (a->pri > b->pri) {
    a->r = merge(a->r, b);
    return a;
  }
  else {
    b->l = merge(a, b->l);
    return b;
  }
}
void split(Treap *t, int k, Treap *&a, Treap *&b) {
  if (!t) a = b = nullptr;
  else if (t->key <= k) {
    a = t;
    split(t->r, k, a->r, b);
  }
  else {
    b = t;
    split(t->l, k, a, b->l);
  }
}
