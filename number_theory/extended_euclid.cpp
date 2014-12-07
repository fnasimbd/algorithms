#include <cstdio>
#include <algorithm>

using namespace std;

int x1, y1;
int x2, y2;

int extended_euclid(int a, int b)
{
    int q; 
    int r = a % b;

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

    scanf("%d %d", &a, &b);

    int g = extended_euclid(a, b);

    printf("%d %d %d\n", g, x2, y2);

    return 0;
}
