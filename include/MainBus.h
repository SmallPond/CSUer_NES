#ifndef _MAIN_BUS_H_
#define _MAIN_BUS_H_

#include <Chip.h>
#include <vector>

#include <Cartridge.h>

/* 总线下不仅仅挂载了内存，如何设计这个类名还值得细细考虑一下 */
class MainBus
{
public:
    // 请补全，包括MainBus初始化，Read/Write方法等


    /* 
    在day3时这样写并不准确，因为还没考虑mapper，
    仅仅为了测试CPU能否正常执行指令
    */
    MainBus(Cartridge& cartridge);

private:
    /* 使用vector，创建自己的内存RAM与扩展RAM*/
    // 请补全

    
    /* 在day3时这么定义并不准确，因为还没考虑mapper的存在 */
    Cartridge cartridge;
};

#endif