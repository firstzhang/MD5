# CCM LOCK PLATFORM（CLP）
CCM LOCK PLATFORM是为了应对接下来越来越多的国芯平台项目，使用一个代码仓库去应对不同项目的变化

## 介绍
在原有菲度F1项目代码库的基础上，CLP在代码结构上做了如下更改：
1. 增加了Bootloader，用来增加平台的OTA功能
2. 剥离与国芯驱动层相关的代码（CCM_SDK），驱动代码单独使用一个仓库进行维护开发；CLP中通过submodule引用CCM_SDK
3. 锁端业务逻辑单独出来，以后需要增加不同的业务逻辑通过宏控制去添加代码
4. 没一个新的项目通过新建该项目的MDK workspace以及相应的project去配置该项目需要的功能

## 使用说明：
1. 克隆仓库代码，并且update submodule CCM_SDK
2. 在已有项目的workspace模板上，新建新项目的workspace以及工程配置
3. 首先编译Bootload，再进行Application的编译

---
目前编译完成后bin文件的生成流程有了很大的变化，主要生成流程如下：
1. 编译Bootload，生成Bootload的hex文件以及axf文件
2. 编译Application，生成Application的hex文件以及axf文件
3. 调用post_build_ccm.bat脚本，根据Bootload的hex文件生成pad bin文件（填充Boot文件为分配空间大小，不足部分填充0xFF）
4. 根据Application的hex文件生成pad sign bin文件（此bin文件做了大小填充，并在文件结尾写入了bin文件的CRC32校验值）
5. 合并Bootload的pad bin和Application的pad bin文件，生成生产文件
6. 根据Application的hex文件生成ota文件——CYACD2

## 工具使用
仓库的Tools目录下包含了两个工具：  
1. hex2xxx.exe，此工具主要是被post_build_ccm.bat脚本调用生成bin文件以及CYACD2文件
2. KeilProjectConvertor.exe，此工具主要用来根据mdk的工程文件生成VSCODE workspace，VSCODE可以不用配置方便的进行代码intellisense
