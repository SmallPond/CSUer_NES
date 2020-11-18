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

/*
 * CPU Memory Map
--------------------------------------- $10000
 Upper Bank of Cartridge ROM
--------------------------------------- $C000
 Lower Bank of Cartridge ROM
--------------------------------------- $8000
 Cartridge RAM (may be battery-backed)
--------------------------------------- $6000
 Expansion Modules
--------------------------------------- $5000
 Input/Output
--------------------------------------- $2000
 2kB Internal RAM, mirrored 4 times
--------------------------------------- $0000
*/

/* 根据地址从内存m_RAM[]中读出数据*/
// 可参考下面DMA 的访存操作GetPagePtr
Byte MainBus::Read(Address addr)
{
    /* 0x2000 =  8KB RAM  */

    if (addr < 0x2000)
    {
        /* 实际只有2KB RAM(如上定义的0x800)，所以采用addr & 0x7ff的操作 */
        // 请补全


    }
    else if(addr < 0x4020)
    {
        // PPU 寄存器 映射到了主总线上
        // 位于 $2000-$2007，另一个寄存器用于直接内存访问，地址为$4014
        // 位置$2000-$2007在$2008-$3FFF区域中每8个字节镜像一次
        if (addr < 0x4000)
        {
            // IO 寄存器的读写使用Map来实现，妙啊
            // 请补全


        }
        else if (addr < 0x4018 && addr >= 0x4014)
        {
            // 请补全


        }
        else 
        {
            LOG(InfoVerbose) << "Read access attempt at: " << std::hex << +addr << std::endl;
        }
    }
    else if (addr < 0x6000)
    {
        LOG(InfoVerbose) << "Expansion ROM read attempted. This is currently unsupported" << std::endl;
    }
    else if ( addr < 0x8000)
    {
        // 扩展RAM
        // 请补全


    }
    else 
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

bool MainBus::SetWriteCallback(IORegisters reg, std::function<void(Byte)> callback)
{
    // 请补全


}

bool MainBus::SetReadCallback(IORegisters reg, std::function<Byte(void)> callback)
{
    // 请补全

    
}


/*
 * DMA 的访存操作以页为单位
 * 每个页大小为256B
*/
const Byte* MainBus::GetPagePtr(Byte page)
{
    Address addr = page << 8;
    if (addr < 0x2000)
        return &m_RAM[addr & 0x7ff];
    else if (addr < 0x4020)
    {
        LOG(Error) << "Register address memory pointer access attempt" << std::endl;
    }
    else if (addr < 0x6000)
    {
        LOG(Error) << "Expansion ROM access attempted, which is unsupported" << std::endl;
    }
    else if (addr < 0x8000)
    {
        if (m_mapper->HasExtendedRAM())
        {
            return &m_extRAM[addr - 0x6000];
        }
    }
    else 
    {

    }
    return nullptr;
}