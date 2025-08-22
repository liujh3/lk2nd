# Installation for PD1510

因为vivo y51 (pd1510)这款设备没有开启启动校验（和bootloader锁不是一回事，**不需要解锁bl**），所以我们可以直接替换原始固件，刷入DB410C的`cdt`、`sbl1`、`rpm`、`tz`、`sec`、`fsc`、`fsg`分区，`hyp`分区还可以使用[qhypstub](https://github.com/msm8916-mainline/qhypstub.git)来开启kvm，`aboot`和`boot`刷入我们编译的lk和lk2nd。

> 注意：这样操作会***丢失所有设备信息***，跟清零字库一样，请考虑要不要事先备份一下

> 刷入要使用9008工具，这个请自行准备，怎样进入9008模式也请自行Google。

#

### [编译](building.md)

### 分区，如果你想直接用db410c的分区表请跳过
  - 到[Qualcomm_tools](https://github.com/HelllGuest/Qualcomm_tools.git)获取 `ptool.py` ，用来生成分区表。工具是Python2，可能需要编译安装。
  - 准备一个 `partition.xml` 文件，编写你自己的分区，参考下面：
    >有几个label是启动必需的，不能乱填，请自行Google查找，或者直接用这里给出的，最起码能开机。filename无所谓，对上号就行。
    ```xml
    <physical_partition type="emmc">

    <partition label="cdt" addoffset="0" size_in_kb="2" type="A19F205F-CCD8-4B6D-8F1E-2D9BC24CFFB1" bootable="false" readonly="true" filename="sbc_1.0_8016.bin"/>
    <partition label="sbl1" addoffset="0" size_in_kb="512" type="DEA0BA2C-CBDD-4805-B4F9-F428251C3E98" bootable="false" readonly="true" filename="sbl1.mbn"/>
    <partition label="rpm" addoffset="0" size_in_kb="512" type="098DF793-D712-413D-9D4E-89D711772228" bootable="false" readonly="true" filename="rpm.mbn"/>
    <partition label="tz" addoffset="0" size_in_kb="1024" type="A053AA7F-40B8-4B1C-BA08-2F68AC71A4F4" bootable="false" readonly="true" filename="tz.mbn"/>
    <partition label="hyp" addoffset="0" size_in_kb="512" type="E1A6A689-0C8D-4CC6-B4E8-55A4320FBD8A" bootable="false" readonly="true" filename="hyp.mbn"/>
    <partition label="sec" addoffset="0" size_in_kb="16" type="303E6AC3-AF15-4C54-9E9B-D9A8FBECF401" bootable="false" readonly="true" filename="sec.dat"/>
    <partition label="fsc" addoffset="0" size_in_kb="1" type="57B90A16-22C9-E33B-8F5D-0E81686A68CB" bootable="false" readonly="true" filename=""/>
    <partition label="fsg" addoffset="117726" size_in_kb="2048" type="638FF8E2-22C9-E33B-8F5D-0E81686A68CB" bootable="false" readonly="true" filename="fs_image_linux.tar.gz.mbn.img"/>
    <partition label="aboot" addoffset="126976" size_in_kb="512" type="400FFDCD-22E0-47E7-9A23-F16ED9382388" bootable="true" readonly="true" filename="emmc_appsboot.mbn"/>
    <partition label="boot" addoffset="0" size_in_kb="65536" type="20117F86-E985-4357-B9EE-374BC1D8487D" bootable="false" readonly="true" filename="boot-erase.img"/>
    <partition label="rootfs" addoffset="0" size_in_kb="0" type="97D7B011-54DA-4835-B3C4-917AD6E73D74" bootable="false" readonly="false" filename=""/>

    </physical_partition>
    ```
  - 生成分区表
    ```sh
    ptool.py -x partition.xml
    ```

### 制作9008刷机包
  - 到[这里](https://www.96boards.org/documentation/consumer/dragonboard/dragonboard410c/downloads/debian.md.html)获取DB410C的bootloader，也可以直接点[这个](http://releases.linaro.org/96boards/dragonboard410c/linaro/rescue/latest/dragonboard-410c-bootloader-emmc-linux-*.zip)下载，注意是*http*连接。下载后解压
  - 用上一步生成的分区文件替换掉解压出来的，`gpt_main0.bin`、`gpt_backup0.bin`、`gpt_both0.bin`、`rawprogram0.xml`、`patch0.xml`，当然也可以直接全选复制过来，选择全部替换。没做上一步的请跳过。
  - 用第一步编译并**签名**的lk（`emmc_appsboot-test-signed.mbn`）替换掉aboot分区（`emmc_appsboot.mbn`）。
  - 用第一步编译出的lk2nd（`lk2nd.img`）替换掉boot分区（`boot-erase.img`）。
  - 如果需要开启kvm，请到[qhypstub](https://github.com/msm8916-mainline/qhypstub.git)，这个lk已经打好补丁了，只需要编译就行，记得**一定要签名**，然后替换掉`hyp`分区（`hyp.mbn`）。

### 用9008工具正常刷入即可
