#include <func.h>

int main(int argc, char* argv[]) {

    if (fork()) {
        exit(0);
    } 
    
    // 创建一个新的会话, 子进程即为新会话首进程
    // 新的会话可以脱离该 bash 独立运行
    setsid();

    // 修改和启动环境相关的属性
    chdir("/");
    umask(0);

    // 断开文件描述符
    for (int i=0; i < 3; ++i) {
        close(i);
    }

    // 使用日志收集系统 收集 程序运行信息
    // 可用于 解决多进程并发问题
    for (int i = 0; i < 100; ++i) {
        syslog(LOG_INFO, "i = %d\n", i);
        sleep(5);
    }

    return 0;
}
