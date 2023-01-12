int modInverse(int num, int p) {
  int p0 = p;
  int y = 0, x = 1;
  if (p == 1) return 0;
  while (num > 1) {
    int q = num / p;
    int t = p;
    p = num % p, num = t;
    t = y, y = x - q * y;
    x = t;
  }
  if (x < 0) x += p0;
  return x;
}