#include <bits/stdc++.h>
using namespace std;
map <int, vector<int> > v;
int a[1500000],sum,falg;
int call(int num)
{
    int s = v[num].size(), maxi = 0,node;
    if(s==0){
        falg = num;
        return sum;
    }
    for(int i = 0 ; i< s ; i++)
    {
        int save = v[num][i];
        if(a[save] > maxi)
        {
            maxi = a[save];
            node = save;

        }
    }
    sum += maxi;
    call(node);
}
int main()
{
    int i, j , k, test,caseno = 0,n,m,x,y;
    cin >> test;
    while(test--)
    {
        caseno++;
        cin >> n >> m;
        for(i = 0 ;i<n ; i++) cin >> a[i];
        for(i = 0 ; i<m ; i++)
        {
            cin >> x >> y;
            v[x].push_back(y);
        }
        sum = 0;
        call(0);
        printf("Case %d: %d %d\n", caseno , sum , falg);
        v.clear();
    }
}
