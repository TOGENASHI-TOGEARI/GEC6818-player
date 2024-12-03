#include "Project.h"

int QQMusicApp()
{
    int musicnum = 0, music_flag = 0;
    int musicnext();
    OpenPicture(0, 0, "./picture/music.bmp");

    while (1)
    {
        Get_Xy();
        if (PI.Ts_x > 0 && PI.Ts_x < 400 && PI.Ts_y > 0 && PI.Ts_y < 240 && music_flag == 0)
        {
            printf("开始播放！\n");
            system("madplay ./music/cage.mp3 &");
            music_flag = 1;
        }

        if (PI.Ts_x > 0 && PI.Ts_x < 400 && PI.Ts_y > 240 && PI.Ts_y < 480)
        {
            printf("下一首！\n");

            musicnum = musicnext(musicnum);
        }

        if (PI.Ts_x > 400 && PI.Ts_x < 800 && PI.Ts_y > 0 && PI.Ts_y < 240)
        {
            printf("暂停！\n");
            system("killall -19 madplay");
        }

        if (PI.Ts_x > 400 && PI.Ts_x < 800 && PI.Ts_y > 240 && PI.Ts_y < 480)
        {
            printf("已退出！\n");
            system("killall -9 madplay");
            music_flag = 0;
            OpenPicture(0, 0, "./picture/main.bmp");
            PI.Ts_x = -1;
            PI.Ts_y = -1;
            break;
        }
        if (PI.Ts_x > 0 && PI.Ts_x < 400 && PI.Ts_y > 0 && PI.Ts_y < 240 && music_flag != 0)
        {
            printf("继续播放！\n");
            system("killall -18 madplay");
        }
    }
}

int musicnext(int musicnum)
{
    musicnum++;
    musicnum = musicnum % 4;
    system("killall -9 madplay");
    if (musicnum == 0)
    {
        system("madplay ./music/cage.mp3 &");
    }

    if (musicnum == 1)
    {
        system("madplay ./music/die_for_you.mp3 &");
    }

    if (musicnum == 2)
    {
        system("madplay ./music/enemy.mp3 &");
    }

    if (musicnum == 3)
    {
        system("madplay ./music/prisoner_of_love.mp3 &");
    }
    return musicnum;
}