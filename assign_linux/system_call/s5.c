#include<dirent.h>//linux pg:-125
#include<stdio.h>
int main()
{
	DIR *d;
	struct dirent *r;
	//const char *name="./linux_ques";//"/home/linux/linux_ques";
	d=opendir(".");
	while((r=readdir(d))!=NULL)
	{
//	printf("%s\n",r->d_name);
//	printf("%ld\n%d\n%d\n%s\n",r->d_ino,r->d_reclen,r->d_type,r->d_name);
	printf("%ld %ld %d %d %s\n",r->d_ino,r->d_off,r->d_reclen,r->d_type,r->d_name);
	}
	closedir(d);
	return 0;
}
