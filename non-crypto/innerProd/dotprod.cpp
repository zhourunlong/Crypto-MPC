#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("input1.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int* a = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    freopen("input2.txt", "r", stdin);
    int m;
    scanf("%d", &m);
    int* b = (int*) malloc(m * sizeof(int));
    for (int i = 0; i < m; ++i)
        scanf("%d", &b[i]);

    assert(n == m);

    int res = 0;
    for (int i = 0; i < n; ++i)
        res += a[i] * b[i];
    printf("%d\n", res);
    
    return 0;
}