#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

ull combinations(ull n, ull k)
{
    if (k > n)
        return 0;
    
    // C(n, k) = C(n, n - k)
    if (n - k < k)
        k = n - k;
    
    ull ret = 1;
    for (ull d = 1; d <= k; ++d)
    {
        ret *= n--;
        ret /= d;
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while ( T-- )
    {
        ull n, k;
        cin >> k >> n;
        
        // Select at least one marble of each color. 
        k -= n;
        
        /**
            This is a typical problem of k-combination with repetitions, where
            we want to choose k items out of n with replacement (the order is
            not important). The formula is C(n + k - 1, k).
        */
        cout << combinations(n + k - 1, k) << endl;
    }
    return 0;
}

