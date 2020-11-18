#include <CPU.h>
#include <CPUOpcodes.h>
#include <MainBus.h>
#include <Log.h>
/* CPU 6502 */

/*
参考：中文版 http://nesdev.com/nes_c.txt
     英文版： http://fms.komkon.org/EMUL8/NES.html
CPU Memory Map
--------------------------------------- $10000
 Upper Bank of Cartridge ROM            卡带的上层ROM
--------------------------------------- $C000
 Lower Bank of Cartridge ROM            卡带的下层ROM
--------------------------------------- $8000
 Cartridge RAM (may be battery-backed)  卡带的RAM（可能有电池支持）
--------------------------------------- $6000
 Expansion Modules                      扩充的模块
--------------------------------------- $5000
 Input/Output                           输入/输出
--------------------------------------- $2000
 2kB Internal RAM, mirrored 4 times     2KB的内部RAM，做4次镜象
--------------------------------------- $0000
*/
CPU::CPU(MainBus &mem) : m_bus(mem) 
{
    
}

void CPU::Reset()
{
    Reset(ReadAddress(ResetVector));
}
/* 内存addr处保存着一个地址信息 */
Address CPU::ReadAddress(Address addr)
{
    return m_bus.Read(addr) | m_bus.Read(addr + 1) << 8;
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


// 设置寄存器f_Z与f_N的值
void CPU::SetZN(Byte value)
{
    // 请补全

    
}

void CPU::SetPageCrossed(Address a, Address b, int inc)
{
    //Page is determined by the high byte
    if ((a & 0xff00) != (b & 0xff00))
        m_skipCycles += inc;
}

// 实现解码执行
void CPU::Step()
{
    ++m_cycles;

    if (m_skipCycles-- > 1)
        return;
    
    m_skipCycles = 0;
    /* 生成程序状态字 */
    /*
    int psw =   f_N << 7 |
                f_V << 6 |
                  1 << 5 |
                f_D << 3 |
                f_I << 2 |
                f_Z << 1 |
                f_C;
    */ 

   // LOG(Info) << "CPU Step, PC is 0x" 
    //     << std::hex 
    //     <<  static_cast<int>(GetPC())
    //     << "\t opcode is:" 
    //     << std::hex 
    //     <<  static_cast<int>(opcode)  
    //     << "\t CycleLength is " << CycleLength
    //         << std::endl;
    
    //请补全


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
* 请使用CPU类中已给定的成员变量和成员函数，将下面指令中空处补全
* 请根据doc/*.pdf里介绍的指令的作用与执行效果，补全代码
*/
bool CPU::ExecuteImplied(Byte opcode)
{
    /* static_cast 类型转换 */
    switch (static_cast<OperationImplied>(opcode))
    {
        case NOP:
            break;
        case JSR:
            /* jump to new location Saving Return Address */
            //Push address of next instruction - 1, thus r_PC + 1 instead of r_PC + 2
            //since r_PC and r_PC + 1 are address of subroutine
            //请补全


            break;
        case RTS:
            /* Return from  Subroutine*/
            //请补全


            break;
        case RTI:
            //请补全
            

            break;
        case JMP:
            //请补全


            break;
        case JMPI:
            {
                //6502 has a bug such that the when the vector of anindirect address begins at the last byte of a page,
                //the second byte is fetched from the beginning of that page rather than the beginning of the next
                //Recreating here:
                //请补全
                

            }
            break;
        case PHP:
            {
                Byte flags = f_N << 7 |
                                f_V << 6 |
                                1 << 5 | //supposed to always be 1
                                1 << 4 | //PHP pushes with the B flag as 1, no matter what
                                f_D << 3 |
                                f_I << 2 |
                                f_Z << 1 |
                                f_C;
                PushStack(flags);
            }
            break;
        case PLP:
            {
                Byte flags = PullStack();
                f_N = flags & 0x80;
                f_V = flags & 0x40;
                f_D = flags & 0x8;
                f_I = flags & 0x4;
                f_Z = flags & 0x2;
                f_C = flags & 0x1;
            }
            break;
        case PHA:
            //请补全


            break;
        case PLA:
            //请补全


            break;
        case DEY:
            --r_Y;
            SetZN(r_Y);
            break;
        case DEX:
            --r_X;
            SetZN(r_X);
            break;
        case TAY:
            r_Y = r_A;
            SetZN(r_Y);
            break;
        case INY:
            ++r_Y;
            SetZN(r_Y);
            break;
        case INX:
            ++r_X;
            SetZN(r_X);
            break;
        case CLC:
            f_C = false;
            break;
        case SEC:
            f_C = true;
            break;
        case CLI:
            f_I = false;
            break;
        case SEI:
            f_I = true;
            break;
        case CLD:
            f_D = false;
            break;
        case SED:
            f_D = true;
            break;
        case TYA:
            r_A = r_Y;
            SetZN(r_A);
            break;
        case CLV:
            f_V = false;
            break;
        case TXA:
            r_A = r_X;
            SetZN(r_A);
            break;
        case TXS:
            r_SP = r_X;
            break;
        case TAX:
            r_X = r_A;
            SetZN(r_X);
            break;
        case TSX:
            r_X = r_SP;
            SetZN(r_X);
            break;
        default:
            return false;
    }
    return true;
}

/* 同样，请使用CPU类中已给定的成员变量和成员函数，将下面指令中空处补全*/
bool CPU::ExecuteBranch(Byte opcode)
{
    if ((opcode & BranchInstructionMask) == BranchInstructionMaskResult)
    {
        //branch is initialized to the condition required (for the flag specified later)
        bool branch = opcode & BranchConditionMask;

        //set branch to true if the given condition is met by the given flag
        //We use xnor here, it is true if either both operands are true or false
        switch (opcode >> BranchOnFlagShift)
        {
            case Negative:
                branch = !(branch ^ f_N);
                break;
            case Overflow:
                branch = !(branch ^ f_V);
                break;
            case Carry:
                branch = !(branch ^ f_C);
                break;
            case Zero:
                branch = !(branch ^ f_Z);
                break;
            default:
                return false;
        }

        if (branch)
        {
            // 请补全


        }
        else
            ++r_PC;
        return true;
    }
    return false;
}

/*请使用CPU类中已给定的成员变量和成员函数，将下面指令中空处补全*/
bool CPU::ExecuteType1(Byte opcode)
{
    if ((opcode & InstructionModeMask) == 0x1)
    {
        Address location = 0; //Location of the operand, could be in RAM
        auto op = static_cast<Operation1>((opcode & OperationMask) >> OperationShift);
        switch (static_cast<AddressingMode1>(
                (opcode & AddrModeMask) >> AddrModeShift))
        {
            // 寻址方式也请理解
            case IndexedIndirectX:
                {
                    Byte zero_addr = r_X + m_bus.Read(r_PC++);
                    //Addresses wrap in zero page mode, thus pass through a mask
                    location = m_bus.Read(zero_addr & 0xff) | m_bus.Read((zero_addr + 1) & 0xff) << 8;
                }
                break;
            case ZeroPage:
                location = m_bus.Read(r_PC++);
                break;
            case Immediate:
                location = r_PC++;
                break;
            case Absolute:
                location = ReadAddress(r_PC);
                r_PC += 2;
                break;
            case IndirectY:
                {
                    Byte zero_addr = m_bus.Read(r_PC++);
                    location = m_bus.Read(zero_addr & 0xff) | m_bus.Read((zero_addr + 1) & 0xff) << 8;
                    if (op != STA)
                        SetPageCrossed(location, location + r_Y);
                    location += r_Y;
                }
                break;
            case IndexedX:
                // Address wraps around in the zero page
                location = (m_bus.Read(r_PC++) + r_X) & 0xff;
                break;
            case AbsoluteY:
                location = ReadAddress(r_PC);
                r_PC += 2;
                if (op != STA)
                    SetPageCrossed(location, location + r_Y);
                location += r_Y;
                break;
            case AbsoluteX:
                location = ReadAddress(r_PC);
                r_PC += 2;
                if (op != STA)
                    SetPageCrossed(location, location + r_X);
                location += r_X;
                break;
            default:
                return false;
        }

        switch (op)
        {
            case ORA:
                // 请补全


                break;
            case AND:
                // 请补全
                
                
                break;
            case EOR:
                r_A ^= m_bus.Read(location);
                SetZN(r_A);
                break;
            case ADC:
                {
                    Byte operand = m_bus.Read(location);
                    std::uint16_t sum = r_A + operand + f_C;
                    //Carry forward or UNSIGNED overflow
                    f_C = sum & 0x100;
                    //SIGNED overflow, would only happen if the sign of sum is
                    //different from BOTH the operands
                    f_V = (r_A ^ sum) & (operand ^ sum) & 0x80;
                    r_A = static_cast<Byte>(sum);
                    SetZN(r_A);
                }
                break;
            case STA:
                m_bus.Write(location, r_A);
                break;
            case LDA:
                r_A = m_bus.Read(location);
                SetZN(r_A);
                break;
            case SBC:
                {
                    //High carry means "no borrow", thus negate and subtract
                    std::uint16_t subtrahend = m_bus.Read(location),
                                diff = r_A - subtrahend - !f_C;
                    //if the ninth bit is 1, the resulting number is negative => borrow => low carry
                    f_C = !(diff & 0x100);
                    //Same as ADC, except instead of the subtrahend,
                    //substitute with it's one complement
                    f_V = (r_A ^ diff) & (~subtrahend ^ diff) & 0x80;
                    r_A = diff;
                    SetZN(diff);
                }
                break;
            case CMP:
                {
                    // 请补全
                    
                    
                }
                break;
            default:
                return false;
        }
        return true;
    }
    return false;
}

/*请使用CPU类中已给定的成员变量和成员函数，将下面指令中空处补全*/
bool CPU::ExecuteType2(Byte opcode)
{
    if ((opcode & InstructionModeMask) == 2)
    {
        Address location = 0;
        auto op = static_cast<Operation2>((opcode & OperationMask) >> OperationShift);
        auto addr_mode =
                static_cast<AddressingMode2>((opcode & AddrModeMask) >> AddrModeShift);
        switch (addr_mode)
        {
            case Immediate_:
                location = r_PC++;
                break;
            case ZeroPage_:
                location = m_bus.Read(r_PC++);
                break;
            case Accumulator:
                break;
            case Absolute_:
                location = ReadAddress(r_PC);
                r_PC += 2;
                break;
            case Indexed:
                {
                    location = m_bus.Read(r_PC++);
                    Byte index;
                    if (op == LDX || op == STX)
                        index = r_Y;
                    else
                        index = r_X;
                    //The mask wraps address around zero page
                    location = (location + index) & 0xff;
                }
                break;
            case AbsoluteIndexed:
                {
                    location = ReadAddress(r_PC);
                    r_PC += 2;
                    Byte index;
                    if (op == LDX || op == STX)
                        index = r_Y;
                    else
                        index = r_X;
                    SetPageCrossed(location, location + index);
                    location += index;
                }
                break;
            default:
                return false;
        }

        std::uint16_t operand = 0;
        switch (op)
        {
            case ASL:
            case ROL:
                if (addr_mode == Accumulator)
                {
                    auto prev_C = f_C;
                    f_C = r_A & 0x80;
                    r_A <<= 1;
                    //If Rotating, set the bit-0 to the the previous carry
                    r_A = r_A | (prev_C && (op == ROL));
                    SetZN(r_A);
                }
                else
                {
                    auto prev_C = f_C;
                    operand = m_bus.Read(location);
                    f_C = operand & 0x80;
                    operand = operand << 1 | (prev_C && (op == ROL));
                    SetZN(operand);
                    m_bus.Write(location, operand);
                }
                break;
            case LSR:
            case ROR:
                if (addr_mode == Accumulator)
                {
                    auto prev_C = f_C;
                    f_C = r_A & 1;
                    r_A >>= 1;
                    //If Rotating, set the bit-7 to the previous carry
                    r_A = r_A | (prev_C && (op == ROR)) << 7;
                    SetZN(r_A);
                }
                else
                {
                    auto prev_C = f_C;
                    operand = m_bus.Read(location);
                    f_C = operand & 1;
                    operand = operand >> 1 | (prev_C && (op == ROR)) << 7;
                    SetZN(operand);
                    m_bus.Write(location, operand);
                }
                break;
            case STX:
                m_bus.Write(location, r_X);
                break;
            case LDX:
                r_X = m_bus.Read(location);
                SetZN(r_X);
                break;
            case DEC:
                {
                    // 请补全
                    
                    
                }
                break;
            case INC:
                {
                    // 请补全


                }
                break;
            default:
                return false;
        }
        return true;
    }
    return false;
}

/*请理解*/
bool CPU::ExecuteType0(Byte opcode)
{
    if ((opcode & InstructionModeMask) == 0x0)
    {
        Address location = 0;
        switch (static_cast<AddressingMode2>((opcode & AddrModeMask) >> AddrModeShift))
        {
            case Immediate_:
                location = r_PC++;
                break;
            case ZeroPage_:
                location = m_bus.Read(r_PC++);
                break;
            case Absolute_:
                location = ReadAddress(r_PC);
                r_PC += 2;
                break;
            case Indexed:
                // Address wraps around in the zero page
                location = (m_bus.Read(r_PC++) + r_X) & 0xff;
                break;
            case AbsoluteIndexed:
                location = ReadAddress(r_PC);
                r_PC += 2;
                SetPageCrossed(location, location + r_X);
                location += r_X;
                break;
            default:
                return false;
        }
        std::uint16_t operand = 0;
        switch (static_cast<Operation0>((opcode & OperationMask) >> OperationShift))
        {
            case BIT:
                operand = m_bus.Read(location);
                f_Z = !(r_A & operand);
                f_V = operand & 0x40;
                f_N = operand & 0x80;
                break;
            case STY:
                m_bus.Write(location, r_Y);
                break;
            case LDY:
                r_Y = m_bus.Read(location);
                SetZN(r_Y);
                break;
            case CPY:
                {
                    std::uint16_t diff = r_Y - m_bus.Read(location);
                    f_C = !(diff & 0x100);
                    SetZN(diff);
                }
                break;
            case CPX:
                {
                    std::uint16_t diff = r_X - m_bus.Read(location);
                    f_C = !(diff & 0x100);
                    SetZN(diff);
                }
                break;
            default:
                return false;
        }

        return true;
    }
    return false;
}