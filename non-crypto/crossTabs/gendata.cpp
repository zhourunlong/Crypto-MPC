#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(NULL));
    int n = 1e4;
    int cat = sqrt(n), data = log(n);
    freopen("input1.txt", "w", stdout);
    printf("%d\n", n);
    for (int i = 0; i < n; ++i)
        printf("%d %d\n", i, rand() % cat + 1);

    freopen("input2.txt", "w", stdout);
    printf("%d\n", n);
    for (int i = 0; i < n; ++i)
        printf("%d %d\n", i, rand() % data + 1);

    return 0;
}