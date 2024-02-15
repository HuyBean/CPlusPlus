#include <bits/stdc++.h>
#define MAXN 505
#define INF 9999999
using namespace std;
typedef long long int lli;

int m[MAXN+1][MAXN+1];

int N, U, Q;

void init(){
    int i, j;
    for( int i = 0; i < MAXN; ++i ){
        for( int j = 0; j < MAXN; ++j ){
            if( i != j ){
                m[i][j] = INF;
            } else {
                m[i][j] = 0;
            }
        }
    }
}

void setupMap(int maxN)
{
    for( int k = 0; k <= maxN; ++k ){
        for( int i = 0; i <= maxN; ++i ){
            for( int j = 0; j <= maxN; ++j ){
                m[i][j] = min( m[i][j] , m[i][k] + m[k][j] );
            }
        }
    }
}

int main() {
    int x, y, w; int maxN = 1; int V;
    int ans;
    cin >> N;
    init();
    for(int i = 0; i < N; ++i ){
        cin >> x >> y >> w;
        maxN = max( maxN, max( x, y ) );
        m[x][y] = min( m[x][y], w );
        m[y][x] = min( m[y][x], w );
    }
    setupMap(maxN);
    cin >> U;
    cin >> Q;
    for(int i = 0; i < Q; ++i ){
        cin >> V;
        ans = min( m[U][V], m[V][U] );
        if( ans == INF ){
            cout << "NO PATH\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}
