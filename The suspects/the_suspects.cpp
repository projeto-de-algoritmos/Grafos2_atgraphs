#include <bits/stdc++.h>

using namespace std;

class UFDS
{
    std::vector<int> size, ps;

public:
    UFDS(int N) : size(N + 1, 1), ps(N + 1)
    {
        std::iota(ps.begin(), ps.end(), 0);
    }

    int find_set(int x)
    {
        return x == ps[x] ? x : (ps[x] = find_set(ps[x]));
    }

    bool same_set(int x, int y) { return find_set(x) == find_set(y); }

    void union_set(int x, int y)
    {
        if (same_set(x, y))
            return;

        int p = find_set(x);
        int q = find_set(y);

        if (size[p] < size[q])
            std::swap(p, q);

        ps[q] = p;
        size[p] += size[q];
    }

    int get_size(int x) { return size[find_set(x)]; }
};

int main()
{

    int m, n;
    while (1)
    {

        cin >> n >> m;
        if (n == 0 and m == 0)
        {
            return 0;
        }
        UFDS ufds(n);
        for (int i = 0; i < m; i++)
        {
            int qnt;
            cin >> qnt;
            int x;
            cin >> x;
            for (int j = 0; j < qnt - 1; j++)
            {
                int y;
                cin >> y;
                ufds.union_set(x, y);
            }
        }
        cout << ufds.get_size(0) << endl;
    }

    return 0;
}