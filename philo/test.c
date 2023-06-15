#include <sys/time.h>
#include <libc.h>

int	main(void)
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	printf("%ld, %d\n", time.tv_sec * (unsigned long)1000, time.tv_usec / 1000);
	//tv_sec に1000をかけるのは、末尾にミリ秒を追加したいから
	//tn_usecを1000で割るのは、マイクロ秒をミリ秒に変換したいから。変換後３桁になるので、tv_secには1000をかけている
	return (0);
}