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

## 五、存储器和寄存器

### 5.1寄存器映射

1、基本
存储器本身不具有地址信息，它的地址是由芯片厂商或用户分配，给寄存器分配地址的过程称为存储器映射，再分配地址称为重映射。
可以理解为C语言中的指针，p->0x0000H
片上资源有256Kx16位Flash、34Kx16的SRAM、8Kx16位的BOOT ROM，2Kx16的OPT ROM，采用统一寻址（程序、数据和IO统一寻址）。
采用多级流水线增强哈佛（还有一种弗洛依曼）结构，并行访问程序和数据存储空间。
下图为地址范围图，可供参考：
![alt text](images/5.1.png)

2、代码安全模块
通过一个128位的密码（相当于8个16位的字）来对安全区进行加密或解密。保存在Flash中的的最后8个字（0x33FFF8~0x33FFFF）即密码区，通过密码匹配，解锁器件。

## 六、工程模板

工程模板直接使用提供好的即可，在根目录下
DSP2833x_Libraries
|--DSP2833x_common
|   |--cmd，分配启动文件
|   |--gel，存放通用拓展
|   |--inlude，存放通用外设头文件
|   |--lib，存放运算库文件
|   |--source，通用外设源文件
|   |
|--DSP2833x_headers
|   |--cmd，存放操作系统所需文件
|   |--gel，相关外设
|   |--include，与common中对应的头文件
|   |--source，全局定义的文件
**创建工程模板的步骤**
①首先需要仿真调试或者flash烧写所需的.cmd文件和DSP的BIOS或nonBIOS .cmd文件。
②其次需要使用芯片的.ccxml目标配置文件。
③芯片内核及外设.c源文件，比如DSP2833x_Gpio.c、DSP2833x_PieCtrl.c等。
④芯片内核及外设.h头文件，比如DSP2833x_Gpio.h、DSP2833x_PieCtrl.h等。
⑤DSP .lib库文件，常用的如IQmath.lib等。

## 七、时钟及其控制系统

### 7.1 外部时钟接入方式

![alt text](images/7.1.1.png)
外部时钟源信号接入方法有2种，分别针对的是电压为3.3V的外部时钟和1.9V的外部时钟。
（1）外部时钟信号接入方式1，即采用3.3V的外部时钟。
![alt text](images/7.1.2.png)
（2）外部时钟信号接入方式2，即采用1.9V的外部时钟。
![alt text](images/7.1.3.png)

### 7.2 时钟结构

![alt text](images/7.2.1.png)
下图为常用寄存器
![alt text](images/7.2.2.png)
![alt text](images/7.2.3.png)

```C
//#define DSP28_DIVSEL   0   // Enable /4 for SYSCLKOUT
#define DSP28_DIVSEL   1 // Disable /4 for SYSCKOUT
//#define DSP28_DIVSEL     2 // Enable /2 for SYSCLKOUT
//#define DSP28_DIVSEL     3 // Enable /1 for SYSCLKOUT

//#define DSP28_PLLCR   10
//#define DSP28_PLLCR    9
//#define DSP28_PLLCR    8
//#define DSP28_PLLCR    7
//#define DSP28_PLLCR    6
//#define DSP28_PLLCR    5
//#define DSP28_PLLCR    4
#define DSP28_PLLCR    3
//#define DSP28_PLLCR    2
//#define DSP28_PLLCR    1
//#define DSP28_PLLCR    0  // PLL is bypassed in this mode
```

上面所展示的代码为官方提供的文件中，对其进行模块化处理的代码

## 八、点亮第一个LED灯

### 8.1 管脚分类

![alt text](images/8.1.1.png)
此芯片共有 176 引脚，类型如下：
（1）电源引脚
（2）晶振引脚
（3）复位引脚
（4）下载引脚
（5）BOOT引脚
（6）GPIO 引脚

### 8.2 GPIO结构框图

![alt text](images/8.2.1.png)
滤波+采样来实现去除毛刺信号
![alt text](images/8.2.2.png)
![alt text](images/8.2.3.png)

### 8.3 LED实验程序

对于部分没有使用过条件编译的读者来说，这里特别说明一下，条件编译的代码格式如下

```c
#ifndef __YOURCODE_H_  //if判断语句，用来判断有没有定义，如果没有定义，直接跳转到endif
#define __YOURCODE_H_   //如果未定义，则定义，防止重复定义，造成资源浪费

···
···
#endif
```

下面是普中提供的一个GPIO的案例

```C
/*******************************************************************************
* 函 数 名         : LED_Init
* 函数功能         : LED初始化函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void LED_Init(void)
{
    EALLOW;//关闭写保护,修改GPIO引脚功能的时候必须执行

    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;    // 开启GPIO时钟

    //LED1端口配置
    GpioCtrlRegs.GPCMUX1.bit.GPIO68=0;//设置为通用GPIO功能
    GpioCtrlRegs.GPCDIR.bit.GPIO68=1;//设置GPIO方向为输出
    GpioCtrlRegs.GPCPUD.bit.GPIO68=0;//使能GPIO上拉电阻

    GpioDataRegs.GPCSET.bit.GPIO68=1;//设置GPIO输出高电平

    EDIS;//开启写保护
}
```

## 九、蜂鸣器

### 9.1 硬件部分

对于普中的开发板，上面采用的是无源蜂鸣器，在对其进行驱动的时候，需要提供1.5~5KHz的频率，这一步目前可以通过使用delay函数来粗略完成，等之后学习过pwm波即可完成更加精细的操作
同时，因为板载驱动能力有限，在这里，采用ULN2003D芯片来驱动。需要注意的是，其引脚间连接有非门，故输出会发生转换
对于有源蜂鸣器的设计电路，这一部分可以参考CSDN上的一些文章，叙述已经十分完全，在此就不做赘述。下面提供一个普中的有源蜂鸣器电路，采用PNP三极管外加上拉电阻的结构实现。
![alt text](images/9.1.1.png)

### 9.2 软件部分
