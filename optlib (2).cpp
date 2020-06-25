#include "opt.cpp"
#include <iostream>
#include <cstddef>
#include <vector>

using namespace std;

void init(vector<int>);
long long query(int, int);

int main()
{
    size_t n;
    cin >> n;

    vector<int> x(n);
    for(size_t i = 0; i < n; i++)
        cin >> x[i];

    init(x);

    size_t q;
    cin >> q;
    for(size_t i = 0; i < q; i++)
    {
        size_t a, b;
        cin >> a >> b;
        cout << query(a, b) << '\n';
    }
}
