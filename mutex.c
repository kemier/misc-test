#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void * process(void * arg)
{
    fprintf(stderr, "Starting process %s\n", (char *) arg);

    while (1) {
        /* 加锁等待某些资源 */
        pthread_mutex_lock(&lock);
        fprintf(stderr, "Process %s lock mutex\n", (char *) arg);
        /* 加锁成功表示资源就绪 */
        usleep(1000);
        /* do something */
    }

    return NULL;
}

int main(void)
{000
    pthread_t th_a, th_b;
    int ret = 0;

    ret = pthread_create(&th_a, NULL, process, "a");
    if (ret != 0) fprintf(stderr, "create a failed %d\n", ret);

    ret = pthread_create(&th_b, NULL, process, "b");
    if (ret != 0) fprintf(stderr, "create b failed %d\n", ret);

    while (1) {
        /* 等待并检测某些资源就绪 */
        /* something */
        /* 解锁告知线程资源就绪 */
        pthread_mutex_unlock(&lock);
        fprintf(stderr, "Main Process unlock mutex\n");
    }

    return 0;
}

