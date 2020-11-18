#ifndef _CPU_H_
#define _CPU_H_
#include <MainBus.h>

class CPU {
    public:
        /* CPU 连接总线 */
        CPU(MainBus &mem);

        void Reset();
        void Reset(Address start_address);

        void Step();
        Address GetPC() { return r_PC; }

    private:
        /* 根据src/CPU.cpp中用到的函数或成员变量，请自行补全此处私有成员*/
        // 请补全
        
        
};

#endif 