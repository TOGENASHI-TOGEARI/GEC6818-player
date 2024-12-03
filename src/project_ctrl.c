#include "Project.h"

int ProjectInit()
{
    PI.lcd_fd = open(_GEC_LCD_PATH_, O_RDWR);
    PI.ts_fd = open(_GEC_TS_PATH_, O_RDONLY);
    if (PI.lcd_fd == PI.ts_fd == -1)
    {
        perror("open lcd or ts failed!");
        return -1;
    }
    PI.mmap_addr = mmap(NULL, _MMAP_LCD_SIZE_,
                        PROT_READ | PROT_WRITE,
                        MAP_SHARED, PI.lcd_fd, 0);
    if (PI.mmap_addr == MAP_FAILED)
    {
        perror("mmap");
        return -1;
    }
    PI.Ts_x = 0;
    PI.Ts_y = 0;
    PI.pid1 = 0;
    PI.pid2 = 0;
    return 0;
}

int ProjectFree()
{
    int close_ret1 = close(PI.lcd_fd);
    int close_ret2 = close(PI.ts_fd);
    int munmap_ret = munmap(PI.mmap_addr, _MMAP_LCD_SIZE_);
    if (close_ret1 == close_ret2 == munmap_ret == -1)
    {
        perror("ProjectFree failed");
        return -1;
    }

    return 0;
}

int Get_Xy()
{

    int flag = 0;
    memset(&Xy, 0, sizeof(Xy));
    while (1)
    {
        read(PI.ts_fd, &Xy, sizeof(struct input_event));

        if (EV_ABS == Xy.type && Xy.code == ABS_X && flag == 0)
        {
            PI.Ts_x = Xy.value * 800 / 1024;

            flag = 1;
        }

        if (Xy.type == EV_ABS && Xy.code == ABS_Y && flag == 1)
        {

            PI.Ts_y = Xy.value * 480 / 600;
            flag = 2;
        }

        if (flag == 2)
        {
            printf("坐标(%d,%d)\n", PI.Ts_x, PI.Ts_y);
            break;
        }
    }
    return 0;
}

int OpenPicture(int s_x, int s_y, const char *picName)
{
    int bmp_fd = open(picName, O_RDONLY);
    if (bmp_fd == -1)
    {
        perror("open bmp failed!");
        return -1;
    }

    char head[54];

    memset(head, 0, sizeof(head));
    read(bmp_fd, head, 54);

    int wide = 0;
    int height = 0;
    wide = head[21] << 24 | head[20] << 16 | head[19] << 8 | head[18];
    height = head[25] << 24 | head[24] << 16 | head[23] << 8 | head[22];
    unsigned char buf[wide * height * 3];
    memset(buf, 0, sizeof(buf));
    read(bmp_fd, buf, sizeof(buf));
    unsigned char A, R, G, B;
    int x = 0, y = 0, n = 0;
    unsigned int bmp_buf[wide * height];
    unsigned int tmp;

    for (n = 0; n < wide * height; n++)
    {
        A = 0x00;
        B = buf[3 * n];
        G = buf[3 * n + 1];
        R = buf[3 * n + 2];
        bmp_buf[n] = A << 24 | R << 16 | G << 8 | B;
    }
    for (y = 0; y < height / 2; y++)
    {
        for (x = 0; x < wide; x++)
        {
            tmp = bmp_buf[wide * y + x];
            bmp_buf[wide * y + x] = bmp_buf[wide * (height - y) + x];
            bmp_buf[wide * (height - y) + x] = tmp;
        }
    }
    for (y = s_y; y < height + s_y && y < 480; y++)
    {
        for (x = s_x; x < wide + s_x && x < 800; x++)
        {
            PI.mmap_addr[800 * y + x] = bmp_buf[wide * (y - s_y) + (x - s_x)];
        }
    }
    close(bmp_fd);
    return 0;
}