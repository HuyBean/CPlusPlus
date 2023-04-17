#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_SIZE 1000

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n, m;
        std::cin >> n >> m;

        bool edges[MAX_SIZE][MAX_SIZE];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                edges[i][j] = 0;
            }
        }

        for (int i = 0; i < m; i++)
        {
            int a, b;
            std::cin >> a >> b;
            edges[a - 1][b - 1] = 1;
            edges[b - 1][a - 1] = 1;
        }

        std::queue<int> qu;

        int str, temp;
        std::cin >> str;
        temp = str - 1;
        bool vstd[MAX_SIZE];
        for (int i = 0; i < n; i++)
        {
            vstd[i] = 0;
        }

        qu.push(str - 1);
        int dis[MAX_SIZE];
        for (int i = 0; i < n; i++)
        {
            dis[i] = -1;
        }

        dis[str - 1] = 0;
        while (!qu.empty())
        {
            str = qu.front();
            qu.pop();

            for (int i = 0; i < n; i++)
                if (edges[str][i] && vstd[i] == 0)
                {
                    vstd[str] = 1;
                    qu.push(i);
                    if (dis[i] == -1 || dis[i] > (dis[str] + 6))
                        dis[i] = dis[str] + 6;
                }
        }
        for (int i = 0; i < n; i++)
        {
            if (i != temp)
            {
                std::cout << dis[i] << " ";
            }
        }
        std::cout << "\n";
    }
    system("pause");
    return 0;
}