#include "Project.h"

int System()
{
    OpenPicture(0, 0, "./picture/wait.bmp");
    system("mplayer -slave -quiet -input file=/fifo -geometry 300:200 -zoom -x 178 -y 178 ./video/1.avi &");
    sleep(5);
    OpenPicture(0, 0, "./picture/lock0.bmp");

    int keysign = lock();
    int exit_flag = 0;
    if (keysign == 1)
    {
        OpenPicture(0, 0, "./picture/main.bmp");
        while (1)
        {
            Get_Xy();
            if (PI.Ts_x > 0 && PI.Ts_x < 100 && PI.Ts_y > 280 && PI.Ts_y < 380)
            {
                printf("bilibili启动!\n");
                BilibiliApp();
            }

            if (PI.Ts_x > 100 && PI.Ts_x < 200 && PI.Ts_y > 180 && PI.Ts_y < 280)
            {
                printf("qq音乐启动！\n");
                QQMusicApp();
            }

            if (PI.Ts_x > 0 && PI.Ts_x < 100 && PI.Ts_y > 180 && PI.Ts_y < 280)
            {
                printf("相册启动!\n");
                PictureAPP();
            }

            if (PI.Ts_x > 100 && PI.Ts_x < 200 && PI.Ts_y > 280 && PI.Ts_y < 380)
            {
                printf("设置\n");
                OpenPicture(0, 0, "./picture/setting.bmp");
                exit_flag = 1;
            }
            if (PI.Ts_x > 700 && PI.Ts_x < 800 && PI.Ts_y > 390 && PI.Ts_y < 480 && exit_flag == 1)
            {
                OpenPicture(0, 0, "./picture/exit.bmp");
                exit(0);
            }
        }
    }
    else
    {
        printf("密码错误\n");
        OpenPicture(0, 0, "./picture/exit.bmp");
        exit(1);
    }
}

int main()
{
    int ProjectInit_ret = ProjectInit();
    if (ProjectInit_ret == -1)
    {
        printf("初始化失败！\n");
        return -1;
    }
    else
    {
        printf("初始化成功！\n");
    }
    VideoInit();
    System();
    int ProjectFree_ret = ProjectFree();
    if (ProjectFree_ret == -1)
    {
        printf("资源回收失败！\n");
        return -1;
    }
    else
    {
        printf("资源回收成功！\n");
    }
    return 0;
}