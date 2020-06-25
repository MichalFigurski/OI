#include<bits/stdc++.h>
using namespace std;

constexpr int MAXN = 500007;

int n;

vector <int> graf[MAXN];

long long docelowo;

long long ile_na_poczatku[MAXN];
long long nadmiar[MAXN];
long long res[MAXN];
bool odw[MAXN];

void dfs(int w)
{
    for (int i = 0; i < graf[w].size(); i++)
    {
        int curr = graf[w][i];

        if (odw[curr])
            continue;
        odw[curr] = true;
        dfs(curr);

        res[w] += res[curr] + abs(nadmiar[curr]);
        nadmiar[w] += nadmiar[curr];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> ile_na_poczatku[i];
        docelowo += ile_na_poczatku[i];
    }

    docelowo /= n;

    for (int i = 1; i <= n; i++){
        nadmiar[i] = ile_na_poczatku[i] - docelowo;
    }


    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;

        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    odw[1] = true;
    dfs(1);

    cout << res[1] << "\n";
}
