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
#define pii pair < int, int >=

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

#define N 101
#define M 1000000007

lli mod(lli x)
{
    return x >= 0 ? x : -x;
}

// also solving MPOW from SPOJ in the optimized approach
lli ar[N][N], I[N][N];

// naive approach for power funtion which takes O((dimensions^3) * (power)) i.e O((m^3) * n)

// O(m^3)

void mul(lli A[][N], lli B[][N], lli m)
{
    lli res[m + 1][m + 1];
    for (lli i = 0; i <= m; i++)
    {
        for (lli j = 0; j <= m; j++)
        {
            res[i][j] = 0;
        }
    }
    for (lli i = 0; i < m; i++)
    {
        for (lli j = 0; j < m; j++)
        {
            for (lli k = 0; k < m; k++)
            {
                res[i][j] = (res[i][j] + ((A[i][k] % M) * (B[k][j] % M)) % M) % M;
            }
        }
    }

    for (lli i = 0; i < m; i++)
    {
        for (lli j = 0; j < m; j++)
        {
            A[i][j] = res[i][j];
        }
    }
}

void mpower(lli ar[][N], lli m, lli n)
{
    for (lli i = 0; i < m; i++)
    {
        for (lli j = 0; j < m; j++)
        {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }

    // prllimat(I, m);

    for (lli i = 0; i < n; i++)
    {
        // res *= base;
        mul(I, ar, m);
    }

    for (lli i = 0; i < m; i++)
    {
        for (lli j = 0; j < m; j++)
        {
            ar[i][j] = I[i][j];
        }
    }
}

void prllimat(lli ar[][N], lli m)
{
    for (lli i = 0; i < m; i++)
    {
        for (lli j = 0; j < m; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}

// optimized approach: inspired from binary exponentiation in O((m^3) * log(n))

void oppower(lli ar[][N], lli m, lli n)
{
    for (lli i = 0; i < m; i++)
    {
        for (lli j = 0; j < m; j++)
        {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }

    // prllimat(I, m);
    // I is identity matrix in here

    while (n)
    {
        if (n % 2)
        {
            // res = (res*base)%modulo
            mul(I, ar, m);
            n--;
        }
        else
        {
            // res = (A*A)%modulo
            mul(ar, ar, m);
            n /= 2;
        }
    }

    for (lli i = 0; i < m; i++)
    {
        for (lli j = 0; j < m; j++)
        {
            ar[i][j] = I[i][j];
        }
    }
}

int main()
{
    fast

        tc_ll
    {
        lli dim, n;
        cin >> dim >> n;
        for (lli i = 0; i < dim; i++)
        {
            for (lli j = 0; j < dim; j++)
            {
                cin >> ar[i][j];
            }
        }

        oppower(ar, dim, n);
        prllimat(ar, dim);
    }
    return 0;
}
