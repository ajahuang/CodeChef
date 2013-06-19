#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
 
typedef long long ll;
 
const int IS_PRIME_SIZE = 31650;
bitset<IS_PRIME_SIZE> isPrime;
int primes[5000];
bitset<100001> interval;
 
int main()
{
    // Prepare isPrime and primes.
    isPrime.set();
    isPrime.reset(1);
    
    int primesIndex = 0;
    for (int n = 2; n < IS_PRIME_SIZE; ++n)
    {
        if (isPrime.test(n))
        {
            primes[primesIndex++] = n;
            for (int m = n * n; m < IS_PRIME_SIZE; m += n)
                isPrime.reset(m);
        }
    }
    
    interval.set();
 
    int T;
    scanf("%d", &T);
    while ( T-- )
    {
        ll m, n;
        scanf("%lld %lld", &m, &n);
        if (m == 1)
            ++m;
        
        for (int i = 0; i < 5000 && primes[i] * primes[i] <= n; ++i)
        {
            ll start = m % primes[i] == 0? m : m + (primes[i] - m % primes[i]);
            if (start == primes[i])
                start += primes[i];
            for (ll idx = start - m; idx <= n - m; idx += primes[i])
                interval.reset(idx);
        }
        
        for (ll x = m; x <= n; ++x)
        {
            if (interval[x - m] == 1)
                printf("%lld\n", x);
            else
                interval.set(x - m);
        }
        
        // Separate the answers for each test case by an empty line.
        if (T)
            printf("\n");
    }
    return 0;
} 