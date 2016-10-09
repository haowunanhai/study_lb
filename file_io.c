#include "file_io.h"

int main(int argc, char **argv)
{
	char *fileName = NULL;
	int fd = 0;
	int ret = 0;
	char data = 0;
	char bufWrite[BUF_LEN] = {0};
	char bufRead[BUF_LEN] = {0};
	int offset = 0;
	int i = 0;

	if (2 != argc)
	{
		printf("One input param need\r\n");
		return -1;
	}
	system("clear");
	
	fileName = argv[1];
	fd = open(fileName, O_RDWR|O_CREAT, S_IRWXU|S_IRWXG|S_IRWXO|S_IWOTH);	
	printf("####fd:%d\r\n", fd);
	if (-1 == fd)
	{
		perror(NULL);
		return -1;
	}
	
	ret = read(fd, bufRead, BUF_LEN);
	if (-1 == ret)
	{
		perror(NULL);
		return ;
	}
	
	for (i = 0; i < ret; i++)
	{
		printf("%c", bufRead[i]);
	}

	while(1)
	{
		data = getchar();
		switch(data)
		{
			//case '\n':
				//printf("LF\n");
				//continue;
			case 'q':
				close(fd);
				break;
			case 's':
				ret = write(fd, bufWrite, BUF_LEN);
				printf("Wroten %d characters\n", ret);
				break;
			default:
				//printf("->%c:%d\r\n", data,data);
				bufWrite[offset++] = data;
				continue;
		}
		break;
	}
	
	return 0;
}
