#include <bits/stdc++.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

const int SIZE = 8192;

int main() {
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(1234);
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(serv_sock, 20);
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

    freopen("input1.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int* a = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    write(clnt_sock, &n, sizeof(int));
    int blk = SIZE / sizeof(int);
    for (int i = 0; i < n; i += blk)
        //write(clnt_sock, a + i, std::min(blk, n - i) * sizeof(int));
        send(clnt_sock, a + i, std::min(blk, n - i) * sizeof(int), 0);
    
    delete a;
    close(clnt_sock);
    close(serv_sock);
    return 0;
}