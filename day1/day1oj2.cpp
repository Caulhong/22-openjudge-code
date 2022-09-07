#include <iostream>
using namespace std;
int n, k;
int fa[50010];
int re[50010];
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
    int origin = fa[x];
    fa[x] = getfather(fa[x]);
    re[x] = (re[x] + re[origin])%3;
    return fa[x];
}
int main()
{
    int cnt = 0;
    cin >> n >> k;
    init();
    for(int i = 0; i < k; ++i)
    {
        int d, x, y;
        cin >> d >> x >> y;
        if(x == y && d == 2)
        {
            cnt++;
            continue;
        }
        if(x > n || y > n)
        {
            cnt ++;
            continue;
        }
        int fx = getfather(x);
        int fy = getfather(y);
        if(d == 1)
        {
            if(fx != fy) 
            {
                fa[fx] = fy;
                re[fx] = (re[y]+3-re[x])%3;
            }
            else if(fx == fy)
            {
                if((re[x]+3-re[y])%3 != 0) cnt++;
                //cout << cnt << "first" << endl;
            }     
        } 
        else 
        {
            if(fx != fy) 
            {
                fa[fx] = fy;
                re[fx]=(re[y]+2-re[x])%3;
            }
            else if(fx == fy)
            {
                if((re[x]+3-re[y])%3 != 2) cnt++;
                //cout << cnt << "second" << endl;
            }     
        } 
    }
    cout << cnt << endl;
    //cout << re[3] << re[2] << re[1] << endl;
    return 0;
}