#include <Emulator.h>
#include <Log.h>


Emulator::Emulator(): 
    m_cpu(m_bus),
    m_screenScale(2.f)
{

}

/* 红白机正式开始工作的主函数*/
void Emulator::Run(std::string rom_path)
{
    /* 从rom_path加载并解析.nes文件*/
    // 请补全
    

    /* 创建Mapper并初始化*/
    // 请补全
    

    /* 待添加PPU总线的mapper设置 */
    // 请补全
    

    /* CPU设置*/
    //请补全


    /* 窗口创建于设置 */
    //请补全


    /* 颜色填充*/
    // 请补全

    // sf::Event event;
    while(m_window.isOpen())
    {
        //请补全

        
    }

}