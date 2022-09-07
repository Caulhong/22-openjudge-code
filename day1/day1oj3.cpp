#include <iostream>
using namespace std;
int n, m, p;
int fa[3000];
int re[3000];
void init()
{
    for(int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        re[i] = 0;
    }
}
int getfather(int x)
{
    if(x == fa[x])return x;
    int t = fa[x];
    fa[x] = getfather(fa[x]);
    re[x] = (re[x] + re[t])%2;
    return fa[x];
}
int main()
{
    cin >> p;
    for(int i = 1; i <= p; ++i)
    {
        cout << "Scenario #" << i << ":" << endl; 
        cin >> n >> m;
        init();
        bool ans = true;
        for(int j = 0; j < m; ++j)
        {
            int x, y;
            cin >> x >> y;
            if(!ans) continue;
            int fx = getfather(x);
            int fy = getfather(y);
            if(fx == fy)
            {
                if(re[x] == re[y])
                {
                    ans = false;
                }
            }
            else
            {
                fa[fx] = fy;
                re[fx] = (re[y] - re[x] + 1)%2; 
            }
        }
        if(ans)
        {
            cout << "No suspicious bugs found!" << endl;
        }
        else
        {
            cout << "Suspicious bugs found!" << endl;
        }
        cout << endl;
    }
    return 0;
}