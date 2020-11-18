#include <CPU.h>
#include <CPUOpcodes.h>
#include <MainBus.h>
/* CPU 6502 */

CPU::CPU(MainBus &mem) : m_bus(mem) 
{
    
}

void CPU::Reset()
{
    Reset(ReadAddress(ResetVector));
}

void CPU::Step()
{
    Byte opcode = m_bus.Read(r_PC++);
    // 待实现解码执行
}

/* 内存addr处保存着一个数据，可能是值也可能是地址 */
Address CPU::ReadAddress(Address addr)
{
    return m_bus.Read(addr) | m_bus.Read(addr + 1) << 8;
}

void CPU::Reset(Address start_addr)
{
    m_skipCycles = m_cycles = 0;
    r_A = r_X = r_Y = 0;
    f_I = true;
    f_C = f_D = f_N = f_V = f_Z = false;
    r_PC = start_addr;
    /* Sp start at 0xfd */
    r_SP = 0xfd; //documented startup state
}
/*
 * 从内存的栈中读/写数据
*/
void CPU::PushStack(Byte val)
{
    // 请补全


}

Byte CPU::PullStack()
{
    // 请补全

    
}