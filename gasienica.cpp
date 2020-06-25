#include<bits/stdc++.h>
using namespace std;

int n, k, res = 1000000000;

int tab[1000007];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> tab[i];

    int glowa = 0, ogon = 0;
    int akt_roze = 0;

    while (glowa < n)
    {
        glowa++;
        akt_roze += tab[glowa];

        if (akt_roze < k)
            continue;

        while (ogon < glowa && akt_roze - tab[ogon] >= k){
            akt_roze -= tab[ogon];
            ogon++;
        }

        res = min(res, glowa - ogon + 1 - k);
    }

    if (res == 1000000000)
        cout << "NIE\n";
    else
        cout << res << "\n";

    return 0;
}
