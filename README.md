# C++一步步实现红白机模拟器

## 项目分解

选择**不同的分支来查看每次增加的内容**，以达到分解整个项目实现的目的。

- Lab1：模拟CPU6502、总线和内存RAM，实现CPU可从内存中读写数据和取指令
- Lab2：参考6502 CPU 的datasheet，实现了CPU对指令的解码执行
- Lab3：解析卡带（Cartidge 游戏卡）的文件格式，编写简单的.nes程序（加法运算），测试 CPU 能否正常执行程序。
- Lab4：实现 Mapper，预留给游戏卡的地址空间是有限的，游戏卡的程序内存（Program Memory）被限制在 32 KB，角色内存（Character Memory）被限制在 8 KB。为了突破这种限制，人们发明了内存映射器（Mapper）。
  - 内存映射器是游戏卡中的一个硬件，具有存储体空间切换（Bank Switching）的功能，以将新的程序或角色内存引入到可寻址的内存空间。
- Lab5：多媒体库（SFML 简单快速多媒体库）的配置和使用，并构建PPU总线（Picture Bus）以及虚拟屏幕(Virtual Screen)的实现
- Lab6: 实现 PPU 的各个回调函数，显示游戏画面
- Lab7：增加按键控制，愉快游戏！


## 实验开始
start分支为master分支，然后经过修改-提交-合并-修改冲突-提交-合并这六个过程，将其它分支依次往start分支上合并，并补全代码。

```sh
# 1.克隆仓库，当前位于主分支start
git clone https://github.com/SmallPond/CSUer_NES.git

# 2.主分支start不需要修改，直接将分支Lab1合并到主分支start
git merge origin/Lab1

# 3.补全Lab1的代码，运行成功
...

# 4.提交到git本地仓库
git add .
git commit -m "输入你的提示文本"

# 5.将分支Lab2也合并到主分支start，去开启实验2
git merge origin/Lab2

# 6.此时会产生冲突，
<<<<<<< HEAD
=======
- Lab2: 参考6502 CPU 的datasheet，实现了CPU对指令的解码执行
>>>>>>> origin/Lab2

# 7.直接将<<<<<<< HEAD ======= >>>>>>> origin/Lab2这些多余字符去掉，再次提交到本地仓库
git add .
git commit -m "输入你的提示文本"

# 8.再次将分支Lab2也合并到主分支start
git merge origin/Lab2

# 9.合并成功，开始补全Lab2代码。进入后面实验时，循环步骤4 ~ 8

# 10.可切换到其它分支进行查看,之后再切回主分支start即可
git checkout LabN
git checkout start
```


# 参考文献

1. [nesdev wiki ](https://wiki.nesdev.com/w/index.php/Nesdev#NES)
2. [NES专题——PPU工作原理](https://blog.csdn.net/qq_34254642/article/details/104193445)
3. [Nintendo Entertainment System Architecture](http://fms.komkon.org/EMUL8/NES.html)
4. [wiki_nesdev_标准控制器](https://wiki.nesdev.com/w/index.php/Standard_controller)
