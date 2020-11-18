#include <MainBus.h>
#include <iostream>
#include <Log.h>
/*  0x800 = 2KB */
MainBus::MainBus() : m_RAM(0x800, 0)
{
}


bool MainBus::SetMapper(Mapper *mapper)
{
    // 请补全


}

/* 根据地址从内存m_RAM[]中读出数据*/
Byte MainBus::Read(Address addr)
{
    /* 0x2000 =  8KB RAM  */

    if (addr < 0x2000)
    {
        /* 实际只有2KB RAM(如上定义的0x800)，所以采用addr & 0x7ff的操作 */
        // 请补全


    }

    if (addr >= 0x8000)
    {   
        // Byte val = cartridge.GetROM()[addr - 0x8000];
        // std::cout << "MainBus Read a Byte: " << std::hex << static_cast<int>(val) << std::endl;
        // return val;
        // 请补全


    }
    return 0;
}

/* 向地址为addr的内存单元写入数据value，请仿照Read()写*/
void MainBus::Write(Address addr, Byte val)
{
    // 请补全

    
}