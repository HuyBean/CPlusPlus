#include <bits/stdc++.h>
using namespace std;

int64_t n, m, x, y, res = 0;

void Lat_Gach(int64_t a, int64_t b, int64_t counter, int64_t x, int64_t y)
{
    if(counter > (x + y))
    {
        return;
    }
    if(a == n && b == m)
    {
        if(counter == (x + y))
        {
            res++;
        }
        return;
    }
    if(a < n && b >= 2)
    {
        Lat_Gach(a + 1, b - 2, counter + 1, x, y);
    }
    if(a >= 2 && b < n)
    {
        Lat_Gach(a - 2, b + 1, counter + 1, x, y);
    }
    Lat_Gach(a, b, counter + 1, x, y);
}

int main()
{
    cin >> n >> m >> x >> y;
    Lat_Gach(0, 0, 0, x, y);
    cout << res;
    return 0;
}
