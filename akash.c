//Libraries which will be used
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    //Declarations
  char *hostname;   
  struct hostent *hostinfo;

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  FILE *fptr;

  //Hostinfo to check the internet connectivity,we are using google here because their up time is 99.998%
  hostname = "google.com";
  hostinfo = gethostbyname (hostname);

  //Checking the internet connection and then writing log accourdingly
  if (hostinfo == NULL)
  {
  fptr = fopen("file.log", "a");
   if(fptr == NULL)
   {
    printf("Couldn't fetch log file.");
   }
   else
   {
   fprintf(fptr,"Internet UNAVAILABLE at: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
   fclose(fptr);
   }
  }
  else
  {
   fptr = fopen("file.log", "a");
   if(fptr == NULL)
   {
    printf("Couldn't fetch log file.");
   }
   else
   {
   fprintf(fptr,"Internet AVAILABLE at: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
   fclose(fptr);
   }
  }

  return 0; 
  //The Program Ends
}
