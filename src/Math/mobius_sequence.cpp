vector<int> primes;
bool not_prime[MAXN + 1];
char mobius[MAXN + 1];
void gen_factorize (int n) {
    for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) {
            primes.push_back(i);
            mobius[i] = -1;
        }
        for (int prime : primes) {
            if (i * prime > n)
                break;
            not_prime[i * prime] = 1;
            if (i % prime == 0) {
                mobius[i * prime] = 0;
                break;
            }
            mobius[i * prime] = mobius[i] * -1;
        }
    }
}