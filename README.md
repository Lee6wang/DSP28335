# DSP28335学习笔记

author:Lee_07
11-02-2024
version:1.0.0
这里是一个初学者学习DSP28335的学习笔记，如有不妥之处请指出，谢谢！

## 一、写在前面

在使用DSP28335的时候，程序烧录过程中，请不要按下复位按键，否则芯片会锁死，想要完成开锁，可以参考网络上的一些资料，例如[https://bbs.elecfans.com/jishu_946759_1_1.html](https://bbs.elecfans.com/jishu_946759_1_1.html)这一部分，但本人未曾验证，请谨慎参考。网址上附带的压缩包文件，也已经存储在本工程中，如需自取。
同时，本人也只是一名在读学生，开发过程中如出现代码不规范等情况，敬请谅解。欢迎有志之士一起交流。

## 二、为什么要学习DSP28335

相信你如果能看到这个教程，一定是带着需求来学习的。至于DSP的外部资源，在这里便不做赘述，可以直接百度or淘宝。
在学习DSP28335之前，希望你能够拥有一定的单片机开发经验，较强的C语言基础，较好的电路基础，敢于多动手实践，这样学起来可以事半功倍。

## 三、DSP28335最小系统

### 3.1 最小系统组成

**1、电源电路**
在普中的开发板中，使用的是SY- 8088芯片来完成1.9V（给内核）和3.3V（芯片外设）电源的输出，接入时可以设计电源指示灯，用于反馈。同时可加稳压，单独供给外围外设。
**2、复位电路**
在普中的开发板中，可以参考的是他的RC电路设计，在开机时可自动复位。
再次提醒，一定不要在烧录时按下复位按键或者拔掉电源，否则芯片将会锁死！！！
**3、晶振电路**
在普中的开发板中，选择的晶振是30MHz，DSP28335工作最大频率是150MHz。XclkIN接地。
**4、下载电路（非必须）**
在普中的开发板中，下载使用的是JTAG，具体设计可以完全参考。

### 3.2 启动模式

通过GPIO84~GPIO87四个IO口来控制，对应的功能表如下所示：
![alt text](images/3.2.png)
对到左边为1，即为上拉。

## 四、软件安装、驱动安装、工程导入

这一步过程只需要参考教程上，便可一步步完成，需要关闭电脑病毒实时扫描，和内存安全性，并重启电脑生效。
