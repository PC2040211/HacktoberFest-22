#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define vp vector<pair<int, int>>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

#define endl "\n"

#define forin(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define fordec(a, b, c) for (int(a) = (b); (a) >= (c); --(a))

#define tc_ll \
    lli t;    \
    cin >> t; \
    while (t--)

#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int mod(int x)
{
    return x >= 0 ? x : -x;
}

// recursive algorithm for finding GCD in O(log(max(a,b))) time

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, (a % b));
}

int main()
{
    fast

        tc_ll
    {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}
