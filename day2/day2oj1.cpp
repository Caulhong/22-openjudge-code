#include <iostream>
using namespace std;
const int N = 2e6 + 10;
int n, cnt = 0, num = 0;
int a[N] = {0}, t[N] = {0}, head[N] = {0};
struct Node
{
    int Min, Max;
}node[N];
struct edge
{
    int to, next;
}e[N];
void add(int x, int y)
{
    cnt++;
    e[cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
}
int lowbit(int x)
{
    return x & -x;
}
void dfs(int x)
{
    node[x].Min = ++num;
    for(int i = head[x]; i; i = e[i].next) 
        dfs(e[i].to);
    node[x].Max = num;
}
void add(int x)
{
    for(int i = x; i <= n; i += lowbit(i))
    {
        if(a[i] == 1) 
        {
            t[i] ++;
        }
        else
        {
            t[i] --;
        }
    }
}
void build_tree()
{
    for(int i = 1; i <= n; ++i)
    {
        a[i] = 1;
    }
    for(int i = 1; i <= n; ++i)
    {
        add(i);
    }
}
int sum(int x)
{
    int ans = 0;
    for(int i = x; i; i -= lowbit(i))
    {
        ans += t[i];
    }
    return ans;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n-1; ++i)
    {
        int u, v;
        cin >> u >> v;
        add (u, v);
    }
    dfs(1);
    build_tree();
    int m;
    cin >> m;
    while(m--)
    {
        char x;
        int y;
        cin >> x >> y;
        if(x == 'C')
        {
            a[node[y].Min] = (a[node[y].Min] + 1)%2;
            add(node[y].Min);
        }
        else
        {
            cout << sum(node[y].Max) - sum(node[y].Min - 1) << endl;
        }
    }
    return 0;
}
