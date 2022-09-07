#include <iostream>
using namespace std;
int n, m;
int fa[50005];
void init()
{
	for(int i = 1; i <= n; ++i)fa[i] = i;
}
int getfather(int x)
{
	if(fa[x] == x)return x;
	else return fa[x] = getfather(fa[x]);
}
int main()
{
	while(cin >> n >> m){
		init();
		for(int i = 1; i <= m; ++i){
			int x, y;
			cin >> x >> y;
			int fx = getfather(x);
			int fy = getfather(y);
			if(fx == fy) cout << "Yes" << endl;
			else{
				fa[fy] = fx;
				cout << "No" <<endl;
			}
		}
		int num = 0;
		for(int i = 1; i <= n; ++i)
		{
			if(fa[i] == i) num ++;
		}
		cout << num << endl;
		for(int i = 1; i <= n; ++i)
		{
			if(fa[i] == i) cout << i <<" ";
		}
		cout << endl;
	}
	return 0;
}
