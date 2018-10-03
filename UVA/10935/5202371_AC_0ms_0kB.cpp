#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    queue <int> q;
    while(scanf("%d", &num)==1)
    {
        if(!num) break;
        for(int i = 1 ; i<= num ; i++)
            q.push(i);
        printf("Discarded cards:");
        int counter = 0;
        while(q.size() != 1){
            int temp = q.front();
            if(counter)
            printf(", %d", temp);
            else printf(" %d", temp);
            counter++;
            q.pop();
            temp = q.front();
            q.pop();
            q.push(temp);
        }
        int temp = q.front();
        printf("\nRemaining card: %d\n", temp);
        q.pop();

    }
return 0;
}
