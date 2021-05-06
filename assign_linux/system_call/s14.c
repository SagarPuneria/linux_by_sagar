#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
int main()
{
	int fd=-1;
	struct stat d;
	//stat("file.txt",&d);
	fd=open("file.txt",O_RDONLY,0644);
	if(fd<0)
	{
		perror("open failed\n");
		return -1;
	}
	fstat(fd,&d);
	printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n",d.st_dev,d.st_ino,d.st_mode,d.st_nlink,d.st_uid,d.st_gid,d.st_rdev,d.st_size,d.st_blksize,d.st_blocks,d.st_atime,ctime(&d.st_mtime),ctime(&d.st_ctime));
	 printf("File type:                ");

           switch (d.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }

}
