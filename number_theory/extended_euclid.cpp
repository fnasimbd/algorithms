#include <cstdio>
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

int main()
{
    int a, b;
    int x, y;

    scanf("%d %d", &a, &b);

    int g = extended_euclid(a, b, x, y);

    printf("%d %d %d\n", g, x, y);

    return 0;
}
