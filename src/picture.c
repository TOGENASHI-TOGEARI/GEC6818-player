#include "Project.h"

int PictureAPP()
{
    int next = 0;
    OpenPicture(0, 0, "./picture/photo4.bmp");
    while (1)
    {
        Get_Xy();
        if (PI.Ts_x > 0 && PI.Ts_x < 300 && PI.Ts_y > 0 && PI.Ts_y < 120)
        {
            next++;
            next = next % 4;
            printf("下一张！\n");
            if (next == 2)
            {
                OpenPicture(0, 0, "./picture/photo2.bmp");
            }

            else if (next == 3)
            {
                OpenPicture(0, 0, "./picture/photo3.bmp");
            }

            else if (next == 1)
            {
                OpenPicture(0, 0, "./picture/photo1.bmp");
            }

            else if (next == 0)
            {
                OpenPicture(0, 0, "./picture/photo4.bmp");
            }
        }

        if (PI.Ts_x > 0 && PI.Ts_x < 200 && PI.Ts_y > 380 && PI.Ts_y < 480)
        {
            for (int photosize = 0; photosize < 4; photosize++)
            {
                next++;
                next = next % 4;
                printf("下一张！\n");
                if (next == 2)
                {
                    OpenPicture(0, 0, "./picture/photo2.bmp");
                }

                else if (next == 3)
                {
                    OpenPicture(0, 0, "./picture/photo3.bmp");
                }

                else if (next == 1)
                {
                    OpenPicture(0, 0, "./picture/photo1.bmp");
                }
                sleep(2);
            }
            OpenPicture(0, 0, "./picture/photo4.bmp");
        }

        if (PI.Ts_x > 690 && PI.Ts_x < 800 && PI.Ts_y > 220 && PI.Ts_y < 480)
        {
            printf("退出！\n");
            OpenPicture(0, 0, "./picture/main.bmp");
            PI.Ts_x = -1;
            PI.Ts_y = -1;
            break;
        }
    }
}