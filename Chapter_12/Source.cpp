#include <stdio.h>
#include <time.h>
#include <windows.h>

int main()
{
	time_t tt;
	for (int i = 0; i < 10; i++)
	{
		time(&tt);
		printf("timestamp: %u\n", tt);
		Sleep(1000);
	}
	
	return 0;
}

