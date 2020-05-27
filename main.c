#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <linux/videodev2.h>
#include <linux/uvcvideo.h>
#include <linux/usb/video.h>

#include <sys/ioctl.h>

const char* usage = "Usage: %s [-d DEVICE] <on|off>\n";

int main(int argc, char *argv[]) {
    const char * device = "/dev/video2";    
    int opt;
    while ((opt = getopt(argc, argv, "d:")) != -1) {
        switch(opt) {
            case 'd':
                device = optarg;
            break;
            case '?':
                fprintf(stderr, usage, argv[0]);
                exit(-1);        
            return -1;
        }
    }

    if (optind + 1 > argc) {
        /* need at least one argument */
        fprintf(stderr, usage, argv[0]);
        exit(-1);        
	} 

    __u8 setbuffer[256] = {};
    if (strcmp(argv[optind], "on") == 0) {
        setbuffer[0] = 0x02;
        setbuffer[1] = 0x19;
    }

    struct uvc_xu_control_query set_query = {
        .unit = 0x0e,
        .selector = 0x0e,
        .query = UVC_SET_CUR,
        .size = 2,
        .data = (__u8*)&setbuffer,
    };

    int result = 0;
    int fd = open(device, O_WRONLY);

    result = ioctl(fd, UVCIOC_CTRL_QUERY, &set_query);
    if (result < 0) {
        printf("Error code: %d, errno: %d, error: %s\n", result, errno, strerror(errno));
        switch(errno) {
           case ENOMEM:
                printf("Not enough memory to perform the operation.\n");
                break;
           case EPERM:
                printf("Insufficient privileges (super user privileges are required).\n");
                break;
           case EINVAL:
                printf("No such UVC control.\n");
                break;
           case EOVERFLOW:
                printf("The requested offset and size would overflow the UVC control.\n");
                break;
           case EEXIST:
                printf("Mapping already exists.\n");
                break;
        }
        return -1;
    }

    close(fd);
    return 0;
}