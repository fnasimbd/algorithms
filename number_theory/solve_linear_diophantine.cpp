#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int extended_euclid(int a, int b, int& x2, int& y2)
{
    int q; 
    int r = a % b;
    int x1, y1;

    x1 = 1, y1 = 0;
    x2 = 0, y2 = 1;

    while((r = a % b) > 0)
    {
	q = a / b;
	a = b;
	b = r;

	int t1 = x2, t2 = y2;
	x2 = x1 - q * x2;
	y2 = y1 - q * y2;

	x1 = t1;
	y1 = t2;
    }

    return b;
}

void solve_linear_diophantine(int a, int b, int c, int& x, int& y)
{
    int g = extended_euclid(a, b, x, y);

    if(c % g != 0)
        return;

    int m = c / g;

    x *= m;
    y *= m;
}

int main()
{
    int a, b, c, x, y;

    scanf("%d %d %d", &a, &b, &c);

    solve_linear_diophantine(a, b, c, x, y);

    printf("%d %d\n", x, y);

    return 0;
}
