#include <bits/stdc++.h>
using namespace std;
#define SIZE 100
int input[SIZE][SIZE];
int sum[SIZE];
int solve(int N) {
int max_ending_here, max_so_far, maximum = INT_MIN;
for (int startx = 0; startx < N; startx++) {
memset(sum, 0, N * sizeof(int));
for (int x = startx; x < N; x++) {
max_ending_here = 0;
max_so_far = INT_MIN;
for (int y = 0; y < N; y++) {
sum[y] += input[x][y];
max_ending_here = max(0, max_ending_here + sum[y]);
max_so_far = max(max_so_far, max_ending_here);
}
maximum = max(maximum, max_so_far);
}
}
return maximum;
}
int main() {

//freopen("a.txt","w",stdout);
int N, num;
 while(cin >> N){
    for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
    scanf("%d", &num);
    input[i][j] = num;
    }
    }
    printf("%d\n", solve(N));
}
return 0;
}
