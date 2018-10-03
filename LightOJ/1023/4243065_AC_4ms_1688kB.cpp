#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n , k , i , j , m , counter = 0;
    char save[50];
    char arr[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int test;
    cin >> test;
    for(m = 1 ; m<= test ; m++)
    {
        printf("Case %d:\n",m);
        cin >> n >> k;
        counter = 0;
        for(i = 0 ; i<n ; i++)
        {
         save[i] = arr[i];
        }
        save[i] = '\0';

        do{
            counter++;
            for(i = 0 ; i<n ; i++)
               printf("%c", save[i]);
            printf("\n");
            if(counter == k) break;
        }while(next_permutation(save,save+n));
    }
}
