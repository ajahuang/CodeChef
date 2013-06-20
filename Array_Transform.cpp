#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    int t;
    cin >> t;
    while ( t-- )
    {
        int n, K;
        cin >> n >> K;
        
        map<int, int> numbers;
        for (int i = 1; i <= n; ++i)
        {
            int number;
            cin >> number;
            /**
                We can decrement a number by K + 1 for arbitrary times. 
                For example:
                
                n = 4, K = 10.
                numbers = 1 11 2 3
             
                Lets try to decrement 11 by 10.
                         1   11   2   3
                Step 1. -9    1  -9  -7   // Decrement all numbers by 1 for K times.
                Step 2.  1    0   2   3   // Decrease the number 1 but increment other numbers by K.
            */
            ++numbers[number % (K + 1)];
        }
        /** If at most two differnt numbers exist and at least n - 1 numbers are the same, 
            then it's possible to perform operations such that exactly n - 1 numbers become 0. */
        if (numbers.size() <= 2)
        {
            if (max_element(numbers.begin(), numbers.end(), comp)->second >= n - 1)
            {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}

