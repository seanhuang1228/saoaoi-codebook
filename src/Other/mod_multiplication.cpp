ll mul (ull x, ull y, ll p) {
    return (x * y - (ull)((ld)x / p * y) * p + p) % p;
}