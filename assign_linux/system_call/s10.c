#include<stdio.h>
main()
{
	printf("contents of file.txt\n");
	system("cat file.txt");
	printf("\n");
	printf("creating hard link\n");
	system("ln file.txt hd.txt");
	printf("contents of hd.txt\n");
	system("cat hd.txt");
	printf("\n");
	printf("creating soft link\n");
	system("ln -s file.txt sf.txt");
	printf("contents of sf.txt\n");
	system("cat sf.txt");
	printf("\n");
	printf("removing original file.txt\n");
	system("rm file.txt");
	printf("contents of file.txt is removed\n");
	system("cat file.txt"); 
	printf("\n");
	printf("contents of hd.txt is not removed\n");
	system("cat hd.txt");
	printf("\n");
	printf("contents of sf.txt is removed\n");
	system("cat sf.txt"); 
}
