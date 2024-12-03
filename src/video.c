#include "Project.h"

static int fd_fifo;

int VideoInit()
{
    if (access("/fifo", F_OK))
    {
        mkfifo("/fifo", 777);
    }

    fd_fifo = open("/fifo", O_RDWR);
    if (fd_fifo == -1)
    {
        printf("失败！\n");
        return -1;
    }

    return 0;
}

int VideoFree()
{
    system("killall -9 mplayer");
    OpenPicture(0, 0, "./picture/main.bmp");
    PI.Ts_x = -1;
    PI.Ts_y = -1;

    return 0;
}

int SendCmd(char *cmd)
{
    write(fd_fifo, cmd, strlen(cmd));
    return 0;
}

int nextvideo(int nextnum)
{
    if (nextnum < 0)
    {
        nextnum = 2;
    }

    nextnum = nextnum % 3;
    system("killall -9 mplayer");
    if (nextnum == 0)
    {
        system("mplayer -slave -quiet -input file=/fifo -geometry 0:0 -zoom -x 800 -y 450 ./video/gbc0.avi &");
    }

    else if (nextnum == 1)
    {
        system("mplayer -slave -quiet -input file=/fifo -geometry 0:0 -zoom -x 800 -y 450 ./video/gbc7.avi &");
    }

    else if (nextnum == 2)
    {
        system("mplayer -slave -quiet -input file=/fifo -geometry 0:0 -zoom -x 800 -y 450 ./video/gbc11.avi &");
    }
    return nextnum;
}

int BilibiliApp()
{
    int nextnum = 0;
    OpenPicture(0, 0, "./picture/video.bmp");
    VideoInit();

    system("mplayer -slave -quiet -input file=/fifo -geometry 0:0 -zoom -x 800 -y 450 ./video/gbc0.avi &");
    while (1)
    {
        Get_Xy();
        if (PI.Ts_x > 0 && PI.Ts_x < 95 && PI.Ts_y > 430 && PI.Ts_y < 480)
        {
            printf("音量加大！\n");
            SendCmd("volume +10\n");
        }

        if (PI.Ts_x > 95 && PI.Ts_x < 209 && PI.Ts_y > 430 && PI.Ts_y < 480)
        {
            printf("音量减小！\n");
            SendCmd("volume -10\n");
        }

        if (PI.Ts_x > 294 && PI.Ts_x < 379 && PI.Ts_y > 430 && PI.Ts_y < 480)
        {
            printf("后退5秒!\n");
            SendCmd("seek -5\n");
        }

        if (PI.Ts_x > 379 && PI.Ts_x < 515 && PI.Ts_y > 430 && PI.Ts_y < 480)
        {
            printf("暂停！\n");
            SendCmd("pause\n");
        }

        if (PI.Ts_x > 209 && PI.Ts_x < 294 && PI.Ts_y > 430 && PI.Ts_y < 480)
        {
            printf("快进5秒!\n");
            SendCmd("seek +5\n");
        }

        if (PI.Ts_x > 515 && PI.Ts_x < 618 && PI.Ts_y > 430 && PI.Ts_y < 480)
        {
            printf("下一集！\n");
            nextnum++;
            nextnum = nextvideo(nextnum);
        }

        if (PI.Ts_x > 618 && PI.Ts_x < 719 && PI.Ts_y > 430 && PI.Ts_y < 480)
        {
            printf("上一集！\n");
            nextnum--;
            nextnum = nextvideo(nextnum);
        }

        if (PI.Ts_x > 719 && PI.Ts_x < 800 && PI.Ts_y > 430 && PI.Ts_y < 480)
        {
            printf("已退出！\n");
            break;
        }
    }

    VideoFree();
    return 0;
}
