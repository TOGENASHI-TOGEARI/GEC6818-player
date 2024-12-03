# 基于GEC6818的多媒体智能终端设计

## 本项目采用GPLv3协议
如果你不清楚这个协议是什么，那么恭喜你，相信你应该不会违反协议内容。
    fork之后也在github开源就行

## 题目要求
使用嵌入式 6818 开发板完成；相册功能：能够通过触摸屏，进行相册的浏览控制（浏览的图片至少3张）；自动播放照片音乐播放功能：播放，暂停，下一首，上一首，返回到主界面（至少3首）视频播放功能：播放，暂停，下一首，上一首，返回到主界面（至少3个视频）团队介绍功能：进入该选项，可查看制作团队信息各小组可在此基础上增加一些特色功能。 

## 环境
粤嵌GEC6818开发板、Ubuntu-24.04.1、VScode、arm-linux-gnueabi-5.4.0

## 保姆教程
***waring!!!*** 本项目全部采用相对路径，请把整个文件夹保存在U盘里使用，不要破坏文件结构 (你会自己修改请无视)
* 在文件夹里打开终端使用： `arm-linux-gcc ./src/*c -I./include -o 6818 -lpthread` 进行编译

#### 一些真真真小白可能会用到的指令
* 创建挂载点: `mkdir /mnt/usb`
* 挂载U盘： `mount /dev/sda1 /mnt/usb`
* 给文件权限： `chmod 777 6818`
* 打开程序： `./6818`

PS：虽然能顺着github找到这份开源就不太可能是小白，但。。。万一呢?(笑)
## 功能操作
**开机**

开机显示4秒进度条动画，约6秒后进入密码界面。密码验证失败显示蓝屏图片并退出，验证成功进入主界面。选择界面四个按钮进入相应功能。

**音乐功能**

* 点击 **播放** 进行播放音乐，如果在暂停状态点击则恢复播放
* 点击 **暂停** 暂停播放
* 点击 **下一曲** 切换到下一首歌
* 点击 **返回** 停止所有歌曲播放，并回到主界面
     
**视频功能**

* 点击 **音量加(音量减)** 将进行放大（缩小）音量
* 点击 **快进(快退)** 将会快进（快退）5秒
* 点击 **播放/暂停** 将会播放/暂停
* 点击 **下一集(上一集)** 将会播放下一集(上一集)
* 点击 **退出** 将退出所有视频播放，并回到主界面

**设置功能**

* 本界面将显示制作人信息(我)，并感谢 ***GBC 有刺无刺乐队*** 对本人精神上的支持
* 点击 **点此退出** 将显示蓝屏界面，并退出程序

***

## 文件树
    |   .gitattributes
    |   project
    |   README.md
    |
    +---include
    |       Project.h
    |
    +---music
    |       cage.mp3
    |       die_for_you.mp3
    |       enemy.mp3
    |       prisoner_of_love.mp3
    |
    +---picture
    |       exit.bmp
    |       lock0.bmp
    |       lock1.bmp
    |       lock2.bmp
    |       lock3.bmp
    |       lock4.bmp
    |       lock5.bmp
    |       lock6.bmp
    |       main.bmp
    |       music.bmp
    |       photo1.bmp
    |       photo2.bmp
    |       photo3.bmp
    |       photo4.bmp
    |       setting.bmp
    |       video.bmp
    |       wait.bmp
    |
    +---src
    |       lock.c
    |       main.c
    |       music.c
    |       picture.c
    |       project_ctrl.c
    |       video.c
    |
    \---video
            1.avi
            gbc0.avi
            gbc11.avi
            gbc7.avi