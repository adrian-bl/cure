#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <stdarg.h>
#include <dlfcn.h>

#define GRAB 40

void dx(char *scratch) {
	int i=0;
        for(i=0;i<GRAB;i++) {
                if(scratch[i] >= 32 && scratch[i] <=122)
                        printf(" %c ",scratch[i]);
                else
                        printf("<%x>", (char)scratch[i]);
        }
	printf("\n");
}

int ioctl(int fd, unsigned long int request, ...)
{
  int result = -1;
  char *argp = NULL;
  char *scratch;
  void * (*ix)();
  int i;

  ix = dlsym(-1, "ioctl");

  scratch = malloc(GRAB);


  va_list ap;
  va_start(ap, request);
  argp = (char *)va_arg(ap, char *);
  va_end(ap);


    if (argp) {
        printf("------------------------------------------------------\n");
	printf("ADVANC IOCTL ON %d -> %X \n", fd, request);
	memcpy(scratch,argp,GRAB);
	dx(scratch);

      result =  ix(fd, request, argp);

        memcpy(scratch,argp,GRAB);
	dx(scratch);
        printf("------------------------------------------------------\n");

 
    }else{
      result =  ix(fd, request);
	printf("SIMPLE IOCTL ON %d -> %X\n", fd, request);
    }


  free(scratch);

  return result;

}

