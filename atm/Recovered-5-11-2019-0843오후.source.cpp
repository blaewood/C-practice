#include "source.h"
#include<time.h>
#include <Windows.h>


void source::settime()
{
	time_t timer;
	timer = time(NULL);
	t = localtime(&timer);
	printf("���н� Ÿ�� (Unix Time): %d ��\n\n", timer);
	printf("���� ��: %d\n", t->tm_year + 1900);
	fprintf(pw3, "%d�� \n\n", t->tm_year + 1900);
	printf("���� ��: %d\n", t->tm_mon + 1);
	fprintf(pw3, "%d�� \n\n", t->tm_mon + 1);
	printf("���� ��: %d\n\n", t->tm_mday);
	fprintf(pw3, "%d�� \n\n", t->tm_mday);
	printf("���� ��: %d\n", t->tm_hour);
	fprintf(pw3, "%d�� \n\n", t->tm_hour);
	printf("���� ��: %d\n", t->tm_min);
	fprintf(pw3, "%d�� \n\n", t->tm_min);
	printf("���� ��: %d\n\n", t->tm_sec);
	fprintf(pw3, "%d�� \n\n", t->tm_sec);
}

void source::write()
{

}

void source::show()
{
	
}