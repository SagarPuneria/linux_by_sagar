#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
int main()
{
	int fd=-1;
	struct stat d;
	stat("file.txt",&d);
	printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n",d.st_dev,d.st_ino,d.st_mode,d.st_nlink,d.st_uid,d.st_gid,d.st_rdev,d.st_size,d.st_blksize,d.st_blocks,d.st_atime,d.st_mtime,d.st_ctime);
}
