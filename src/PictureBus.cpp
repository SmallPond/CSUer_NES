#include <PictureBus.h>
#include <Log.h>
/*
 * http://fms.komkon.org/EMUL8/NES.html
 * PPU Memory Map
--------------------------------------- $4000
 Empty
--------------------------------------- $3F20
 Sprite Palette
--------------------------------------- $3F10
 Image Palette
--------------------------------------- $3F00
 Empty
--------------------------------------- $3000
 Attribute Table 3
--------------------------------------- $2FC0
 Name Table 3 (32x30 tiles)
--------------------------------------- $2C00
 Attribute Table 2
--------------------------------------- $2BC0
 Name Table 2 (32x30 tiles)
--------------------------------------- $2800
 Attribute Table 1
--------------------------------------- $27C0
 Name Table 1 (32x30 tiles)
--------------------------------------- $2400
 Attribute Table 0
--------------------------------------- $23C0
 Name Table 0 (32x30 tiles)
--------------------------------------- $2000
 Pattern Table 1 (256x2x8, may be VROM)
--------------------------------------- $1000
 Pattern Table 0 (256x2x8, may be VROM)
--------------------------------------- $0000

*/

PictureBus::PictureBus() : 
    m_RAM(0x800),
    m_palette(0x20),
    m_mapper(nullptr)
{

}

/* 根据上面的PPU Memory Map，将这里补充完整*/
Byte PictureBus::Read(Address addr)
{
    if(addr < 0x2000)
    {
        // 请补全


    }
    else if (addr < 0x3eff)
    {
        // 请补全

        
    }
    else if (addr < 0x3fff)
    {
        /* 0x3f00 - 0x3f20 */
        // 分为image 和 sprite，每个 palette 大小为16
        // 请补全

        
    }
    return 0;
}

/* platette 是 Byte? 不是 Address ？ */
Byte PictureBus::ReadPalette(Byte platetteAddr)
{
    /* 这里也不检查边界？ */
    return m_palette[platetteAddr];
}

/* 仿照Read的处理，将Write补充完整*/
void PictureBus::Write(Address addr, Byte value)
{
    //请补全


}


void PictureBus::UpdateMirroring()
{
    switch (m_mapper->GetNameTableMirroring())
    {
        case Horizontal:
            m_NameTable0 = m_NameTable1 = 0;
            m_NameTable2 = m_NameTable3 = 0x400;
            LOG(InfoVerbose) << "Horizontal Name Table mirroring set. (Vertical Scrolling)" << std::endl;
            break;
        case Vertical:
            m_NameTable0 = m_NameTable2 = 0;
            m_NameTable1 = m_NameTable3 = 0x400;
            LOG(InfoVerbose) << "Vertical Name Table mirroring set. (Horizontal Scrolling)" << std::endl;
            break;
        case OneScreenLower:
            m_NameTable0 = m_NameTable1 = m_NameTable2 = m_NameTable3 = 0;
            LOG(InfoVerbose) << "Single Screen mirroring set with lower bank." << std::endl;
            break;
        case OneScreenHigher:
            m_NameTable0 = m_NameTable1 = m_NameTable2 = m_NameTable3 = 0x400;
            LOG(InfoVerbose) << "Single Screen mirroring set with higher bank." << std::endl;
            break;
        default:
            m_NameTable0 = m_NameTable1 = m_NameTable2 = m_NameTable3 = 0;
            LOG(Error) << "Unsupported Name Table mirroring : " << m_mapper->GetNameTableMirroring() << std::endl;
    }
}

bool PictureBus::SetMapper(Mapper *mapper)
{
    // 请补全

    
}