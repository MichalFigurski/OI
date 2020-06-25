#include<bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e6 + 7;

int q;

bool sito[MAXN];
int sum[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> q;


    for (int i = 2; i <= 1e6; i++)
    {
        sum[i] = sum[i - 1];

        if (!sito[i])
        {
            sum[i]++;

            if (i <= 1e3)
                for (int j = i*i; j <= 1e6; j += i)
                    sito[j] = true;
        }
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << sum[b] - sum[a - 1] << "\n";
    }
    return 0;
}
