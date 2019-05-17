#include "source.h"
#include<time.h>
#include <Windows.h>


void source::settime()
{
	time_t timer;
	timer = time(NULL);
	t = localtime(&timer);
	printf("유닉스 타임 (Unix Time): %d 초\n\n", timer);
	printf("현재 년: %d\n", t->tm_year + 1900);
	fprintf(pw3, "%d년 \n\n", t->tm_year + 1900);
	printf("현재 월: %d\n", t->tm_mon + 1);
	fprintf(pw3, "%d월 \n\n", t->tm_mon + 1);
	printf("현재 일: %d\n\n", t->tm_mday);
	fprintf(pw3, "%d일 \n\n", t->tm_mday);
	printf("현재 시: %d\n", t->tm_hour);
	fprintf(pw3, "%d시 \n\n", t->tm_hour);
	printf("현재 분: %d\n", t->tm_min);
	fprintf(pw3, "%d분 \n\n", t->tm_min);
	printf("현재 초: %d\n\n", t->tm_sec);
	fprintf(pw3, "%d초 \n\n", t->tm_sec);
}

void source::write()
{

}

void source::show()
{
	
}