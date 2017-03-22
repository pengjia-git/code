#include <syslog.h>   
      
int main(int argc, char *argv[])   
{   
  openlog("testsyslog", LOG_CONS | LOG_PID, 0);   
  syslog(LOG_USER | LOG_INFO, "syslog test message generated in program %s \n", argv[0]);   
  closelog();   
  return 0;   
}  
