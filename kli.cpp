#include<bits/stdc++.h>
using namespace std;

long long X;
vector <int> czworkowo;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> X;

    while (X > 0)
    {
        czworkowo.push_back(X % 4);
        X /= 4;
    }
    czworkowo.push_back(0);
    //reverse(czworkowo.begin(), czworkowo.end());

    for (int i = 0; i < czworkowo.size(); i++)
    {
        if (czworkowo[i] == 3 || czworkowo[i] == 4)
        {
            czworkowo[i] -= 4;
            czworkowo[i + 1]++;
        }
        if (czworkowo[i] == 2)
        {
            cout << "Panie idz pan stad\n";
            return 0;
        }
    }
    cout << "tak\n";
    return 0;
}
