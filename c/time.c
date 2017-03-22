    #include <stdio.h>  
    #include <time.h>  
    int main()  
    {  
        time_t timep;  
        struct tm *p;  
	char buf[64]={0};
        time(&timep);  
        p =localtime(&timep); //此函数获得的tm结构体的时间，是已经进行过时区转化为本地时间  
        //p = gmtime(&timep); //把日期和时间转换为格林威治(GMT)时间的函数  
      	sprintf(buf,"%04d-%02d-%02d_%02d:%02d:%02d",p->tm_year+1900,p->tm_mon+1,
		p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
	printf("time=%s\n",buf);
        printf("Year:  %d\n", 1900+p->tm_year);  
        printf("Month:  %d\n", 1+p->tm_mon);  
        printf("Day:  %d\n", p->tm_mday);  
        printf("Hour:  %d\n", p->tm_hour);  
        printf("Minute:  %d\n", p->tm_min);  
        printf("Second:  %d\n",  p->tm_sec);  
        printf("Weekday:  %d\n", p->tm_wday);  
        printf("Days:  %d\n", p->tm_yday);  
        printf("Isdst:  %d\n", p->tm_isdst);  
    }  
