#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while ( T-- )
    {
        int N;
        cin >> N;
        vector<int> ids(N), sums(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> ids[i];
            cin >> sums[i];
        }
        cout << accumulate(ids.begin(), ids.end(), 0) -
                accumulate(sums.begin(), sums.end(), 0)
             << endl;
    }
    return 0;
}

