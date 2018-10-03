#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include<map>
using namespace std;
int main()
{
  //  freopen("a.txt","w",stdout);
    int i , j , a,b , x, y ,src , counter = 1 ;
   map <int, vector <int> > v;
    queue <int> q;
    int temp;
    while(cin>>temp)
        {
            for(j=0;j<temp;j++)
                {
                    cin >> b;
                    v[b].push_back(1);
                    v[1].push_back(b);
                }
           for(i=2 ; i<=19 ; i++)
            {
                cin >> a;
                for(j=0;j<a;j++)
                {
                    cin >> b;
                    v[b].push_back(i);
                    v[i].push_back(b);
                }
            }

                cin >> a;
          //      if(counter != 1) cout << "\n";
               cout << "Test Set #" << counter << endl;
               counter++;
                for(j = 0 ; j <a ; j++)
                {
                    int vis[50] = {0};
                    int level[50] = {0};
                    cin >> x >> y;
                    vis[x] = 1;
                    q.push(x);
                    while(!q.empty())
                    {
                        int u = q.front();

                        for(i = 0 ; i<v[u].size();i++)
                        {
                          int g = v[u][i];
                          if(vis[g] == 0)
                          {
                              q.push(g);
                              vis[g] = 1;
                              level[g] = level[u]+1;
                          }
                        }
                      q.pop();
                    }
                   printf("%2d to %2d:%2d\n", x , y ,level[y]);


                }
            cout << "\n";
            v.clear();
        }

}

