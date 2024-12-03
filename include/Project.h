#ifndef _PROJECT_H_
#define _PROJECT_H_

#include <stdio.h>
#include <error.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <linux/input.h>
#include <pthread.h>
#include <unistd.h>

#define _GEC_LCD_PATH_ "/dev/fb0"
#define _GEC_TS_PATH_ "/dev/input/event0"
#define _MMAP_LCD_SIZE_ 800 * 480 * 4

struct Pro_Info
{
    int lcd_fd;
    int ts_fd;
    int *mmap_addr;
    int Ts_x, Ts_y;
    pthread_t pid1, pid2;

} PI;
struct input_event Xy;

int ProjectInit();

int ProjectFree();

int Get_Xy();

int OpenPicture(int s_x, int s_y, const char *picName);

int System();

int QQMusicApp();

int BilibiliApp();

int VideoInit();

int VideoFree();

int SendCmd(char *cmd);

int PictureAPP();

int lock();

int musicnext(int musicnum);

int nextvideo();

#endif