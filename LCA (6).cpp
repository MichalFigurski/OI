#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e6;
const int maxh = 20; // co najmniej log2(n) 
int n;
vector <int> graph[maxn];
vector <int> tree[maxn];
int LCAnext[maxn][maxh];
int depth[maxn];

void read_input() {
    cin >> n;
    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void make_tree(int node, int parent) {
    tree[node].push_back(parent);
    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];
        if (child != parent) {
            tree[node].push_back(child);
            make_tree(child, node);
        }
    }
}

void build_depth(int node) {
    depth[node] = depth[tree[node][0]] + 1;
    for (int i = 1; i < tree[node].size(); i++)
        build_depth(tree[node][i]);
}

void build_LCAnext() {
    for (int node = 1; node <= n; node++)
        LCAnext[node][0] = tree[node][0];

    for (int i = 1; i < 20; i++)
        for (int node = 1; node <= n; node++)
            LCAnext[node][i] = LCAnext[LCAnext[node][i - 1]][i - 1];
}

int find_LCA(int node1, int node2) {
    if (depth[node1] < depth[node2])
        swap(node1, node2);
    // teraz node1 jest na conajmniej tym poziomie co node2
    for (int i = maxh - 1; i >= 0; i--)
        if (depth[LCAnext[node1][i]] >= depth[node2])
            node1 = LCAnext[node1][i];
    // teraz node1 i node2 są na tym samym poziomie
    for (int i = maxh - 1; i >= 0; i--) {
        if (LCAnext[node1][i] != LCAnext[node2][i]) {
            node1 = LCAnext[node1][i];
            node2 = LCAnext[node2][i];
        }
    }
    // teraz node1 równa się node2 lub node1 i node2 są dziećmi tego samego wierzchołka
    if (node1 == node2) 
        return node1;
    else
        return LCAnext[node1][0];
}

int main() {
    read_input();
    make_tree(1, 1);
    depth[1] = -1;
    build_depth(1);
    build_LCAnext();
    int node1 = 6;
    int node2 = 11;
    int lca = find_LCA(node1, node2);
    cout << lca << endl;
}