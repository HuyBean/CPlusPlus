#include <iostream>

using namespace std;

int64_t gcd(int64_t a, int64_t b)
{
    if( b == 0) return a;
    return gcd(b, a%b);
}

int64_t counter(int64_t a, int64_t b, int64_t x)
{
    int64_t _add = 0, _minus = 0;
    if(a == b && x == 0)
    {
        return 0;
    }
    if( a== 0 && a == b && x !=0)
    {
        return - 1;
    }
    else if(a == b && x != 0)
    {
        return -1;
    }
    if(b>a)
        swap(a, b);
    if(a > b)
    {
        _add = gcd(b, a + x);
        if(_add == b)
        {
            _minus = 1;
            _add = (x + a)/_add;
        }
        else
        {
            _minus = (b*_add + x)/a;
        }
    }
    return _add + _minus;
}
int main()
{
    int n;
    cin >> n;
    for(int i =0; i< n;++i)
    {
        int64_t a, b, x;
        cin >> a >> b>> x;
        cout << counter(a, b, x);
    }
    system("pause");
    return 0;
}