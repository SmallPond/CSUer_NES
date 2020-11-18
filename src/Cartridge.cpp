#include<Cartridge.h>
#include<fstream>
#include <Log.h>

Cartridge::Cartridge():
    m_nameTableMirroring(0),
    m_mapperNumber(0),
    m_extendedRAM(false)
{

}
const std::vector<Byte>& Cartridge::GetROM()
{
    return m_PRG_ROM;
}
const std::vector<Byte>& Cartridge::GetVROM()
{
    return m_CHR_ROM;
}

Byte Cartridge::GetMapper()
{
    return m_mapperNumber;
}

Byte Cartridge::GetNameTableMirroring()
{
    return m_nameTableMirroring;
}

bool Cartridge::HasExtendedRAM()
{
    return m_extendedRAM;
}

/*
 * 完成.NES的加载与解析
 * .NES 文件头格式 https://wiki.nesdev.com/w/index.php/INES
 * 0-3: Constant $4E $45 $53 $1A ("NES" followed by MS-DOS end-of-file)
 * 4: Size of PRG ROM in 16 KB units
 * 5: Size of CHR ROM in 8 KB units (Value 0 means the board uses CHR RAM)
 * 6: Flags 6 - Mapper, mirroring, battery, trainer
 * 7: Flags 7 - Mapper, VS/Playchoice, NES 2.0
 * 8: Flags 8 - PRG-RAM size (rarely used extension)
 * 9: Flags 9 - TV system (rarely used extension)
 * 10: Flags 10 - TV system, PRG-RAM presence (unofficial, rarely used extension)
 * 11-15: Unused padding (should be filled with zero, but some rippers put their name across bytes 7-15
*/
bool Cartridge::LoadFromFile(std::string path)
{
    //请补全
    
    
}