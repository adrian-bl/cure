#include <stdio.h>
#include <fcntl.h>

#define OUR_VERSION "260.19.21"

typedef struct n_version {
	char unk0;
	char unk1;
	char unk2;
	char unk3;
	char reply;
	char unk5;
	char unk6;
	char unk7;
	char vstring[14];
};


int main() {

	int fd;
	int r;
	
	struct n_version funk;
	
	
	strcpy(funk.vstring, OUR_VERSION);
	
	fd = open("/dev/nvidiactl", O_RDWR);
	r = ioctl(fd, 0xC04846D2, &funk);
	close(fd);
	
	
	if(r)
		printf("ioctl() failed. maybe your driver didn't like our version: *%s*\n", OUR_VERSION);
		
	if(funk.reply)
		printf("Reply from nvidia driver: version=%s\n", funk.vstring);
	
	exit(0);

}
