#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while ( t-- )
    {
        string k;
        cin >> k;

        int highestChangedDigit = (int)k.size();
        double needAdjustMiddleDigits = false;
        
        // Handle the digits where k[i] > k[j].
        {
            int i = k.size() % 2 == 1? (int)k.size() / 2 : (int)k.size() / 2 - 1;
            int j = k.size() % 2 == 1? i : i + 1;
            for ( ; i >= 0; --i, ++j)
            {
                if (k[i] > k[j])
                {
                    k[j] = k[i];
                    highestChangedDigit = j;
                }
                else if (k[i] < k[j] 
                         && j < highestChangedDigit)
                {
                    needAdjustMiddleDigits = true;
                }
            }
        }
        if (highestChangedDigit == (int)k.size() || needAdjustMiddleDigits)
        {
            int i = k.size() % 2 == 1? (int)k.size() / 2 : (int)k.size() / 2 - 1;
            int j = k.size() % 2 == 1? i : i + 1;
            
            for ( ; i >= 0 && k[i] == '9'; --i, ++j)
                k[i] = k[j] = '0';
            if (i >= 0)
            {
                ++k[i];
                k[j] = k[i];
            }
            else
            {
                k = "1" + k;
                k[k.size() - 1] = '1';
            }
        }
        
        // Handle the digits where k[i] < k[i].
        int i = (int)k.size() / 2 - 1;
        int j = k.size() % 2 == 1? i + 2: i + 1;
        for ( ; i >= 0; --i, ++j)
        {
            if (k[i] < k[j])
                k[j] = k[i];
        }
        
        cout << k << endl;
    }
    return 0;
}