#include <bits/stdc++.h>
using namespace std;
map <int, int> c, d, e;
int main() {
    freopen("input1.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int id, cat;
        scanf("%d%d", &id, &cat);
        c[id] = cat;
        d[cat] = e[cat] = 0;
    }

    freopen("input2.txt", "r", stdin);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int id, data;
        scanf("%d%d", &id, &data);
        d[c[id]] += data;
        e[c[id]] += 1;
    }

    freopen("answer.txt", "w", stdout);
    printf("Cat\tSum\tCount\n");
    for (map <int, int> :: iterator it = d.begin(); it != d.end(); ++it) {
        int cat = it->first, sum = it->second;
        int cnt = e[cat];
        printf("%d\t%d\t%d\n", cat, sum, cnt);
    }

    return 0;
}