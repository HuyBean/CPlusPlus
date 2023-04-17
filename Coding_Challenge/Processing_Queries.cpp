#include <iostream>
#include <queue>

#define MAX_SIZE 1000000

long long t[MAX_SIZE], d[MAX_SIZE], f[MAX_SIZE];

long long n, m;

int main()
{
    std::cin >> n >> m;
    long long T, D;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> t[i] >> d[i];
        f[i] = 0;
    }

    std::queue<long long> q;

    T = t[0] + d[0];
    f[0] = T;
    q.push(T);

    for (int i = 1; i < n; ++i)
    {
        while (q.size() > 0 && t[i] >= q.front())
        {
            q.pop();
        }

        if (T <= t[i])
        {
            T = t[i] + d[i];
            f[i] = T;
            q.push(T);
        }

        else
        {
            if (q.size() > m)
            {
                f[i] = -1;
            }

            else
            {
                T += d[i];
                f[i] = T;
                q.push(T);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << f[i] << " ";
    }

    system("pause");
    std::cout << "\n";
    return 0;
}