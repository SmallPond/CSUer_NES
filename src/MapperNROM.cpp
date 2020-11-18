#include<MapperNROM.h>
#include<Log.h>

/* NROM-Mapper0: 最简单的实现方式 */


MapperNROM::MapperNROM(Cartridge& cart): 
    Mapper(cart, Mapper::NROM)
{
    /* 0x4000 = 16 KB */
    if (cart.GetROM().size() == 0x4000) //1 bank
    {
        // 请补全


    }
    else //2 banks
    {
        // 请补全


    }

    if (cart.GetVROM().size() == 0)
    {
        // 请补全


    }
    else
    {
        // 请补全


    }
}

Byte MapperNROM::ReadPRG(Address addr)
{
    if (!m_oneBank)
    {
        // 请补全


    }  
    else //镜像读
    {
        // 请补全


    }
        
}

void MapperNROM::WritePRG(Address addr, Byte value)
{
    LOG(InfoVerbose) << "ROM memory write attempt at " << +addr << " to set " << +value << std::endl;
}

Byte MapperNROM::ReadCHR(Address addr)
{
    // 这里不进行越界判断？
    if (m_usesCharacterRAM)
    {
        return m_characterRAM[addr];
    }
    else
    {
        return m_cartridge.GetVROM()[addr];
    }
}


void MapperNROM::WriteCHR(Address addr, Byte value)
{
    if (m_usesCharacterRAM)
    {
        m_characterRAM[addr] = value;
    }
    else
    {
        LOG(Info) << "Read-only CHR memory write attempt at " << std::hex << addr << std::endl;
    }
        
}