#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/netlink.h>

#define BUFFER_SIZE 4096

int main() {
    // 创建 Netlink 套接字
    int sock_fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_KOBJECT_UEVENT);
    if (sock_fd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // 绑定地址
    struct sockaddr_nl addr = {
        .nl_family = AF_NETLINK,
        .nl_pid = getpid(),    // 当前进程 ID 作为唯一标识
        .nl_groups = 1,        // 监听多播组 1 (内核事件)
    };

    if (bind(sock_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(sock_fd);
        return EXIT_FAILURE;
    }

    printf("Listening for uevents...\n(Ctrl+C to exit)\n\n");

    // 循环接收事件
    char buffer[BUFFER_SIZE];
    while (1) {
        ssize_t len = recv(sock_fd, buffer, sizeof(buffer), 0);
        if (len < 0) {
            perror("recv");
            break;
        }

        // 解析事件内容（格式为 key=value 的字符串序列）
        printf("=== New Event (size: %ld bytes) ===\n", len);
        for (char *ptr = buffer; ptr < buffer + len; ) {
            // 每行以 '\0' 分隔
            printf("%s\n", ptr);
            ptr += strlen(ptr) + 1;
        }
        printf("\n");
    }

    close(sock_fd);
    return EXIT_SUCCESS;
}
