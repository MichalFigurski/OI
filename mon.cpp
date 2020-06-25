#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 7;
const int mod = 1e9 + 7;

int n;
int tab[MAXN];

long long res = 1;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> tab[i];

    sort(tab + 1, tab + 1 + n);

    for (int i = 1; i <= n; i++){
        res = (res * (tab[i] - i + 1)) % mod;
        if (res <= 0){
            cout << "0\n";
            return 0;
        }
    }
    cout << res << "\n";
    return 0;
}
