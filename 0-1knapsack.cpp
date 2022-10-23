#include <bits/stdc++.h>

using namespace std;

const int N = 2001;

int s[N], v[N];
int memo[N][N];

// O(n*size)
int knapsack(int index, int size)
{
    if (index == 0)
        return 0;

    int &ans = memo[index][size];

    if (ans != -1)
        return ans;
    ans = 0;

    // include
    if (s[index] <= size)
    {
        ans = v[index] + knapsack(index - 1, size - s[index]);
    }
    // exclude
    ans = max(ans, knapsack(index - 1, size));

    return ans;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int size, n;
    cin >> size >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> v[i];
    }

    // memset(memo, -1, sizeof(memo));

    // cout << knapsack(n, size);

    // tabulation with O(n*size) memory

    // int dp[n + 1][size + 1];
    // for (int i = 0; i <= size; i++)
    // {
    //     dp[0][i] = 0;
    // }
    // for (int i = 0; i <= n; i++)
    // {
    //     dp[i][0] = 0;
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= size; j++)
    //     {
    //         dp[i][j] = dp[i - 1][j];
    //         if (j >= s[i])
    //             dp[i][j] = max(v[i] + dp[i - 1][j - s[i]], dp[i - 1][j]);
    //     }
    // }
    // cout << dp[n][size] << endl;

    // tabulation with only O(size) memory
    vector<int> dp(size + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = size; j >= 1; j--)
        {
            if (j >= s[i])
            {
                dp[j] = max(v[i] + dp[j - s[i]], dp[j]);
            }
        }
    }
    cout << dp[size] << endl;

    return 0;
}
