#ifndef _MAIN_BUS_H_
#define _MAIN_BUS_H_

#include <Chip.h>
#include <vector>
#include <map>
#include <Cartridge.h>
#include <Mapper.h>

/*
 * IO寄存器的具体含义参考 http://fms.komkon.org/EMUL8/NES.html#LABF
*/

enum IORegisters
{
    PPUCTRL = 0x2000,  // 控制寄存器
    PPUMASK,           
    PPUSTATUS,         // 状态寄存器
    OAMADDR,           // Sprite 内存地址寄存器
    OAMDATA,           // Sprite Memory Data
    PPUSCROL,          //  Screen Scroll Offsets 屏幕滚动偏移
    PPUADDR,           // PPU Memory Address
    PPUDATA,           // PPU Memory Data
    // 中间空余的为 Sound 寄存器
    OAMDMA = 0x4014,   // DMA Access to the Sprite Memory
    JOY1 = 0x4016,     // Joystick1 + Strobe
    JOY2 = 0x4017,     // Joystick2 + Strobe
};

/* 总线下不仅仅挂载了内存，如何设计这个类名还值得细细考虑一下 */
class MainBus
{
public:
    // 请补全，包括MainBus初始化，Read/Write函数等


    // 请补全，还得加上Mapper的设置函数


    // IO 寄存器读写Callback设置
    // 为什么不直接采用普通内存读写的实现？
    // 提供一个抽象接口，交由对应的硬件模块提供函数获得相应的寄存器值
    // 请补全


private:
    /* 使用vector，创建自己的内存RAM与扩展RAM */    
    // 请补全

    // 别忘了Mapper


    // 使用Map定义成员Read/WriteCallback


};

#endif