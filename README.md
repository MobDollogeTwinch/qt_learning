### 环境
#### os
Arch Linux x86_64
#### clang
> clang --version

clang version 20.1.8  
Target: x86_64-pc-linux-gnu  
Thread model: posix  
InstalledDir: /usr/bin
#### cmake
> cmake --version

cmake version 4.1.1
#### qt
> qmake6 --version

QMake version 3.1  
Using Qt version 6.9.2 in /usr/lib
### 构建命令
cd 到对应子文件执行  
> cmake -B build -S . -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
