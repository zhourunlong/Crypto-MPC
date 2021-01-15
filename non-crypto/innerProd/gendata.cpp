#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(NULL));
    int n = 1e6;
    int* b = (int*) malloc(n * sizeof(int));
    freopen("input1.txt", "w", stdout);
    int res = 0;
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        int a = rand();
        b[i] = rand();
        printf("%d\n", a);
        res += a * b[i];
    }

    freopen("input2.txt", "w", stdout);
    printf("%d\n", n);
    for (int i = 0; i < n; ++i)
        printf("%d\n", b[i]);
    
    freopen("answer.txt", "w", stdout);
    printf("%d\n", res);

    delete b;
    return 0;
}