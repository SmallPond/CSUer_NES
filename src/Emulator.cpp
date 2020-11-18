#include <Emulator.h>
#include <Log.h>


/*
 * 将 m_cpuCycleDuration增大可方便调试 
*/
Emulator::Emulator(): 
    m_cpu(m_bus),
    m_screenScale(2.f),
    m_ppu(m_pictureBus, m_emulatorScreen),
    m_cycleTimer(),
    m_cpuCycleDuration(std::chrono::nanoseconds(559))
{
    // 855555559
    if(!m_bus.SetReadCallback(PPUSTATUS, [&](void) {return m_ppu.GetStatus();}) ||
        !m_bus.SetReadCallback(PPUDATA, [&](void) {return m_ppu.GetData();}) ||
        // !m_bus.SetReadCallback(JOY1, [&](void) {return m_controller1.Read();}) ||
        // !m_bus.SetReadCallback(JOY2, [&](void) {return m_controller2.Read();}) ||
        !m_bus.SetReadCallback(OAMDATA, [&](void) {return m_ppu.GetOAMData();}))
    {
        LOG(Error) << "Critical error: Failed to set I/O callbacks" << std::endl;
    }

    if(!m_bus.SetWriteCallback(PPUCTRL, [&](Byte b) {m_ppu.Control(b);}) ||
        !m_bus.SetWriteCallback(PPUMASK, [&](Byte b) {m_ppu.SetMask(b);}) ||
        !m_bus.SetWriteCallback(OAMADDR, [&](Byte b) {m_ppu.SetOAMAddress(b);}) ||
        !m_bus.SetWriteCallback(PPUADDR, [&](Byte b) {m_ppu.SetDataAddress(b);}) ||
        !m_bus.SetWriteCallback(PPUSCROL, [&](Byte b) {m_ppu.SetScroll(b);}) ||
        !m_bus.SetWriteCallback(PPUDATA, [&](Byte b) {m_ppu.SetData(b);}) ||
        !m_bus.SetWriteCallback(OAMDMA, [&](Byte b) {DMA(b);}) ||
        // !m_bus.SetWriteCallback(JOY1, [&](Byte b) {m_controller1.strobe(b); m_controller2.strobe(b);}) ||
        !m_bus.SetWriteCallback(OAMDATA, [&](Byte b) {m_ppu.SetOAMData(b);}))
    {
        LOG(Error) << "Critical error: Failed to set I/O callbacks" << std::endl;
    }
    // ppu 设置中断回调函数
    m_ppu.SetInterruptCallback([&](){ m_cpu.Interrupt(CPU::NMI); });

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
    

    /* CPU设置，PPU设置*/
    //请补全


    /* 窗口创建于设置 */
    //请补全


    /* 颜色填充*/
    // 请补全

    /* 时钟设置*/
    // 请补全

    sf::Event event;
    bool isFocus = true, isPause = false;

    while(m_window.isOpen())
    {
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // 请补全


            }
            else if (event.type == sf::Event::GainedFocus)
            {
               // 请补全

                
            }
            else if (event.type == sf::Event::LostFocus)
                isFocus = false;
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F2)
            {
                // 请补全

                
            }
            else if (isPause && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::F3)
            {
                for (int i = 0; i < 29781; ++i) //Around one frame
                {
                    //PPU
                    // 请补全

                
                    //CPU
                    // 请补全

                
                }
            }
                
        }

        if (isFocus && !isPause)
        {
            // 请补全

                
        }
        else
        {
            // 1/60 second
            sf::sleep(sf::milliseconds(1000/60));
        }
    }
}

void Emulator::DMA(Byte page)
{
    m_cpu.SkipDMACycles();
    auto page_ptr = m_bus.GetPagePtr(page);
    m_ppu.DoDMA(page_ptr);
}
