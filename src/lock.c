#include <Project.h>
int keynum1 = 0;
int key1[7] = {0};
int truekey[7] = {0, 2, 2, 2, 0, 1, 2};
int panduan = 0;

int lock()
{
    int keyshow()
    {
        switch (keynum1)
        {
        case 0:
            ShowBmp(0, 0, "./picture/lock0.bmp");
            break;

        case 1:
            ShowBmp(0, 0, "./picture/lock1.bmp");
            break;

        case 2:
            ShowBmp(0, 0, "./picture/lock2.bmp");
            break;

        case 3:
            ShowBmp(0, 0, "./picture/lock3.bmp");
            break;

        case 4:
            ShowBmp(0, 0, "./picture/lock4.bmp");
            break;

        case 5:
            ShowBmp(0, 0, "./picture/lock5.bmp");
            break;

        case 6:
            ShowBmp(0, 0, "./picture/lock6.bmp");
            break;

        default:
            break;
        }
    }

    while (1)
    {
        Get_Xy();
        if (PI.Ts_x > 0 && PI.Ts_x < 265 && PI.Ts_y > 0 && PI.Ts_y < 120)
        {
            printf("0\n");
            keynum1++;
            keyshow();
            key1[keynum1] = 0;
        }

        if (PI.Ts_x > 0 && PI.Ts_x < 265 && PI.Ts_y > 120 && PI.Ts_y < 240)
        {
            printf("1\n");
            keynum1++;
            keyshow();
            key1[keynum1] = 1;
        }

        if (PI.Ts_x > 266 && PI.Ts_x < 535 && PI.Ts_y > 120 && PI.Ts_y < 240)
        {
            printf("2\n");
            keynum1++;
            keyshow();
            key1[keynum1] = 2;
        }

        if (PI.Ts_x > 536 && PI.Ts_x < 800 && PI.Ts_y > 120 && PI.Ts_y < 240)
        {
            printf("3\n");
            keynum1++;
            keyshow();
            key1[keynum1] = 3;
        }

        if (PI.Ts_x > 0 && PI.Ts_x < 265 && PI.Ts_y > 240 && PI.Ts_y < 360)
        {
            printf("4\n");
            keynum1++;
            keyshow();
            key1[keynum1] = 4;
        }

        if (PI.Ts_x > 266 && PI.Ts_x < 535 && PI.Ts_y > 240 && PI.Ts_y < 360)
        {
            printf("5\n");
            keynum1++;
            keyshow();
            key1[keynum1] = 5;
        }

        if (PI.Ts_x > 536 && PI.Ts_x < 800 && PI.Ts_y > 240 && PI.Ts_y < 360)
        {
            printf("6\n");
            keynum1++;
            keyshow();
            key1[keynum1] = 6;
        }

        if (PI.Ts_x > 0 && PI.Ts_x < 265 && PI.Ts_y > 360 && PI.Ts_y < 480)
        {
            printf("7\n");
            keynum1++;
            keyshow();
            key1[keynum1] = 7;
        }

        if (PI.Ts_x > 266 && PI.Ts_x < 535 && PI.Ts_y > 360 && PI.Ts_y < 480)
        {
            printf("8\n");
            keynum1++;
            keyshow();
            key1[keynum1] = 8;
        }

        if (PI.Ts_x > 536 && PI.Ts_x < 800 && PI.Ts_y > 360 && PI.Ts_y < 480)
        {
            printf("9\n");
            keynum1++;
            keyshow();
            key1[keynum1] = 9;
        }

        if (keynum1 == 6)
        {
            break;
        }
    }

    for (; panduan < 7; panduan++)
    {
        if (key1[panduan] != truekey[panduan])
        {
            break;
        }
    }

    if (panduan == 7)
    {
        return 1;
    }
    else
        return 0;
}