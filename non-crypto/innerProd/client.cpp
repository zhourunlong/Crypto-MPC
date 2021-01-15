#include <bits/stdc++.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

const int SIZE = 8192;

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(1234);
    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
   
    int n;
    read(sock, &n, sizeof(int));
    int* a = (int*) malloc(n * sizeof(int));

    int blk = SIZE / sizeof(int);
    for (int i = 0; i < n; i += blk)
        //read(sock, a + i, std::min(blk, n - i) * sizeof(int));
        recv(sock, a + i, std::min(blk, n - i) * sizeof(int), 0);

    freopen("input2.txt", "r", stdin);
    int m;
    scanf("%d", &m);
    int* b = (int*) malloc(m * sizeof(int));
    for (int i = 0; i < m; ++i)
        scanf("%d", &b[i]);
    
    if (n != m)
        printf("error! n = %d m = %d\n", n, m);

    int res = 0; // intended!!
    for (int i = 0; i < n; ++i)
        res += a[i] * b[i];
    printf("%d\n", res);

    delete a;
    delete b;
    close(sock);
    return 0;
}