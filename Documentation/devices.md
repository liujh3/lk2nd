# Supported devices

### msm8916

- Vivo Y51 (pd1510) (仅支持 `tmotm9605a` 面板，硬编码，不同面板的可能会损坏，而且需要将aboot刷成自己编译的lk，参照 [building.md](building.md))
- 其余设备我都删除了，设备树为 `lk2nd/device/dts/msm8916/msm8916.dts` ，仅包含引导必要的平台ID，没有设备型号，开机显示 Unknown ，如果想修复可以自己瞎填一个

### lk2nd-msm8909

- Acer Liquid Z330 (T01)
- CAT B35
- FarEasTone Smart 506 (quirky - see comment in `lk2nd/device/dts/msm8909/msm8909-1gb-qrd-skuc.dts`)
- Haier G151 / Andromax A (quirky - see comment in `lk2nd/device/dts/msm8909/msm8909-1gb-qrd-skuc.dts`)
- Lenovo Yoga Tab 3 8 LTE / WIFI
- Lenovo Yoga Tab 3 10 LTE / WIFI
- Lenovo Tab 10 (TB-X103F)
- Mobvoi TicWatch Pro (WF12096)
- Nokia 6300 4G
- Nokia 8000 4G
- Nokia 8110 4G
- ZTE N818S (sapphire)

### lk2nd-msm8952

- Alcatel Idol 4 (6055*)
- BQ X5 Plus (Longcheer L9360)
- Fossil Gen 6 (hoki)
- HMD Global Nokia 5 (nd1)
- HMD Global Nokia 6 (ple)
- Huawei Honor 7C (aum-l41) (quirky - see comment in `lk2nd/device/dts/msm8952/msm8937-huawei-aum.dts`)
- Huawei MediaPad T3 10 (ags- l09/l03/w09) (quirky - see comment in `lk2nd/device/dts/msm8952/msm8917-huawei-agassi.dts`)
- Leeco s2
- Lenovo K5 Play (l38011)
- Lenovo Tab M10 HD (TB-X505X)
- Motorola Moto E5 (nora)
- Motorola Moto E5 Plus (hannah) (MSM8917)
- Motorola Moto E5 Plus (hannah) (MSM8937)
- Motorola Moto G4 / G4 Plus (athene) ( `fastboot boot lk2nd.img`, then `fastboot flash lk2nd lk2nd.img` )
- Motorola Moto G5 (cedric)
- Motorola Moto G5S (montana)
- Motorola Moto G6 Play (jeter)
- OPPO A57 (A57) (quirky - see comment in `lk2nd/device/dts/msm8952/msm8940-oppo-a57.dts`)
- Redmi 3S (land)
- Redmi 4 (prada)
- Redmi 4A (rolex)
- Redmi 4X (santoni)
- Redmi 5A (riva)
- Redmi 7A (pine)
- Redmi GO (tiare)
- Redmi Note 3 Pro (kenzo)
- Redmi Note 5A (ugglite)
- Redmi Note 5A Prime (ugg)
- Sony Xperia X
- Sony Xperia X Compact
- Wileyfox Swift 2
- Xiaomi Mi Max (hydrogen)

### lk2nd-msm8953

- Asus Zenfone 3 ZE520KL/ZE552KL (zenfone3)
- Billion Capture+ (rimob)
- Fairphone 3
- Huawei Maimang 5 / Nova Plus / G9 (Plus) (milan)
- Huawei Nova (cannes)
- Lenovo P2 (kuntao)
- Lenovo ThinkSmart View (cd-18781y) (quirky - see comments in `lk2nd/device/dts/msm8953/apq8053-lenovo-cd-18781y.dts`)
- Meizu M6 Note (m1721)
- Motorola Moto G5 Plus (potter)
- Motorola Moto G5s Plus (sanders)
- Motorola Moto G6 (ali)
- Motorola Moto G7 Power (ocean)
- Motorola One (deen)
- OPPO R9s/R9sk (R9s/R9sk) (quirky - see comments in `lk2nd/device/dts/msm8953/msm8953-oppo-r9s.dts`)
- Samsung Galaxy A6+
- Samsung Galaxy J8 LTE
- Samsung Tab A2 XL WIFI
- Xiaomi Mi A1 (tissot)
- Xiaomi Mi A2 Lite (daisy)
- Xiaomi Mi Max 2 (oxygen)
- Xiaomi Redmi 4 Prime (markw)
- Xiaomi Redmi 5 (rosy)
- Xiaomi Redmi 5 Plus (vince)
- Xiaomi Redmi 6 Pro (sakura)
- Xiaomi Redmi 7 (onclite)
- Xiaomi Redmi Note 4X Snapdragon (mido)
- Xiaomi Redmi S2/Y2 (ysl)

### lk2nd-msm8974
- BlackBerry Passport - wolverine
- Fairphone 2 - FP2
- HTC One M8 - m8
- LG G3 - D855
- LG Google Nexus 5 - hammerhead D820, D821 (quirky - see comment in `lk2nd/device/dts/msm8974/msm8974-lge-hammerhead.dts`)
- Motorola Moto X 2014 - victara
- OnePlus One - bacon <!--(use `lk2nd-msm8974-appended-dtb.img`)-->
- Samsung Galaxy Note 3 - SM-N9005, SM-N900T
- Samsung Galaxy S5 - SM-G900F, SM-G900T
- Samsung Galaxy S5 China LTE (Duos) - SM-G9006V/W, SM-G9008V/W, SM-G9009W
- Sony Xperia Z3 - leo

### lk2nd-msm8226
- ASUS ZenWatch 2 - sparrow
- Coolpad 8730L - 8730l
- HTC One Mini 2 - memul (quirky - see comment in `lk2nd/device/dts/msm8226/msm8926-htc-memul.dts`)
- Huawei Ascend G6 4G - G6-L11 (quirky - see comment in `lk2nd/device/dts/msm8226/msm8926-huawei-g6-l11-vb.dts`)
- Huawei Watch - sturgeon
- LG Fx0 - madai
- LG G Watch R - lenok <!--(use `lk2nd-appended-dtb.img`)-->
- Motorola Moto G 2013 - falcon
- Motorola Moto G 4G 2013 - peregrine
- Motorola Moto G 2014 - titan
- Motorola Moto G 2014 LTE - thea
- Samsung Galaxy Grand 2 - SM-G7102
- Samsung Galaxy Tab 4 10.1 (2014) - SM-T530, SM-T535
- Samsung Galaxy Tab 4 8.0 (2014) - SM-T330, SM-T330NU, SM-T331
- Sony Xperia M2 - eagle (quirky - see comment in `lk2nd/device/dts/msm8226/msm8926-v2-720p-mtp.dts`)

### lk2nd-msm8994
- Huawei Nexus 6P - Angler
- LG G4 - h815

### lk2nd-msm8996

- LG G5 - h850
- LG V20 - h990
- OnePlus 3T
- Xiaomi Mi 5 - gemini
- Xiaomi Mi 5s - capricorn
- Xiaomi Mi 5s Plus - natrium
- ZTE Axon 7

### lk2nd-msm8960

- Samsung Galaxy Ace 3 LTE (GT-S7275R) (display refresh doesn't work)
- Samsung Galaxy Express (SGH-I437)
- Samsung Galaxy S4 Mini (GT-I9195)
- Sony Xperia SP (huashan) (quirky - see comment in `lk2nd/device/dts/msm8960/bundle.dts`)

## Porting new devices

If you are considering adding support for a new device, you would need to add a
new dts entry. You can see [targets.md](targets.md) to pick the correct target
for your SoC and consult [dt-bindings.md](dt-bindings.md) for the lk2nd dts format
and bindings.
