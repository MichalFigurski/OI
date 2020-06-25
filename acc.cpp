#include<bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e6 + 7;

int n;

int rep[MAXN];
long long val[MAXN];
long long val_rep[MAXN]; // val_rep[a] == 3  a jest większe od rep[a] o 3
bool defined[MAXN];

int Find(int a)
{
    if (a == rep[a])
        return a;

    int r = Find(rep[a]);
    val_rep[a] += val_rep[rep[a]]; // A -> B -> C -> D
    rep[a] = r;
    return r;
}

void Union(int a, int b, long long v)
{
    // A i B są już reprezentantami
    // A jest większe od B o V
    val_rep[a] = v;
    rep[a] = b;

    if (!defined[b] && defined[a]){
        defined[b] = true;
        val[b] = val[a] - val_rep[a];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < MAXN - 2; i++)
        rep[i] = i;

    for (int i = 1; i <= n; i++)
    {
        char c;
        int s1, s2;
        long long v;
        cin >> c;

        if (c == 'd')
        {
            cin >> s1 >> s2 >> v;

            if (s1 == s2 && v != 0){
                cout << i << "\n";
                continue;
            }

            int rs1 = Find(s1), rs2 = Find(s2);
            if (rs1 == rs2){
                if (val_rep[s1] - val_rep[s2] != v){
                    cout << i << "\n";
                    continue;
                }
            }
            else
            {
                if (defined[rs1] && defined[rs2] && (v + val_rep[s1] + val_rep[s2] != val[rs1] - val[rs2])){
                    cout << i << "\n";
                    continue;
                }
                else{
                    Union(rs1, rs2, v + val_rep[s1] + val_rep[s2]);
                }
            }
        }
        else
        {
            cin >> s1 >> v;
            int rs1 = Find(s1);

            if (defined[rs1])
            {
                if (v != val[rs1] + val_rep[s1]){
                    cout << i << "\n";
                    continue;
                }
            }
            else
            {
                defined[rs1] = true;
                val[rs1] = v - val_rep[s1];
            }
        }
    }
    return 0;
}
