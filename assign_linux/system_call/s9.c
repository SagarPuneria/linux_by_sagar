#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
int main()
{
	DIR *d1;
	struct dirent *r;
	int fd=-1;
	struct stat d;
	d1=opendir(".");//const char *name="./linux_ques";//"/home/linux/linux_ques";
	while((r=readdir(d1))!=NULL)
	{
		printf("%s-->",r->d_name);
		stat(r->d_name,&d);
		printf("File type is:");

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
	closedir(d1);
	
}
