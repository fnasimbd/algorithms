#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 10000

int t[4*MAXN];

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2 + 1, tm + 1, tr);
        t[v] = t[v*2] + t[v*2 + 1];
    }
}

int sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
    {
        return 0;
    }

    if (l == tl && r == tr)
    {
        return t[v];
    }

    int tm = (tl + tr) / 2;

    return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        int tm = (tl + tr) / 2;

        if (pos <= tm)
        {
            update(v*2, tl, tm, pos, new_val);
        }
        else
        {
            update(v*2 + 1, tm + 1, tr, pos, new_val);
            t[v] = t[v*2] + t[v*2 + 1];
        }
    }
}

int main()
{
    int n, a[100], i;
    int q, r, s;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    build(a, 1, 0, n-1);

    while(scanf("%d %d %d", &q, &r, &s) == 3 && (q != 0))
    {
        if (q==1)
        {
            printf("%d\n", sum(1, 0, n-1, r, s));
        }
        else
        {
            update(1, 0, n-1, r, s);
        }
    }

    return 0;
}