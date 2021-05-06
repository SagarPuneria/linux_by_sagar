#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
int main()
{
	int fd=-1;
	struct stat d;
	//stat("file.txt",&d);
	fd=open("file.txt",O_CREAT|O_RDONLY,0644);
	if(fd<0)
	{
		perror("open failed\n");
		return -1;
	}
	fstat(fd,&d);
	printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n",d.st_dev,d.st_ino,d.st_mode,d.st_nlink,d.st_uid,d.st_gid,d.st_rdev,d.st_size,d.st_blksize,d.st_blocks,d.st_atime,d.st_mtime,d.st_ctime);
}
