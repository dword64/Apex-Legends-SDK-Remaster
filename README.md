# Apex-Legends-SDK-Remaster
This is a simple version of https://github.com/ethanedits/Apex-Legends-SDK since so many people having struggles with python binding

*Open Source Cheat* for **Apex Legends**, designed for ease of use. Made to understand reversing of Apex Legends and respawn's modified source engine as well as their Easy Anti Cheat Implementation.

This Project consists of two parts, *Driver* and *Usermode*.
Since this project utilizes a Kernel Driver you will most likely want to change the ***hooked function*** as well as the *shellcode* that goes along with it. You can change both of these inside ***Memory.h*** in the Driver

Current function: `NtOpenCompositionSurfaceSectionInfo`

Current shellcode: `0x8B, 0x04, 0x24, 0x89, 0x41, 0x44, 0xC7, 0x41, 0x30, 0x0F, 0x00, 0x10`

To build this project, please download the ```Windows Driver Kit (WDK)```, and build in **Release | x64**. Build and place *KDMapper* (https://github.com/TheCruZ/kdmapper) in the directory of your build, as the project will attempt to map the driver for you.

Additionally, to correctly replace *EAC's splash screen*, you will need to change paths in `Utils.h`


![Image1](https://media.discordapp.net/attachments/733974815735808041/913891455209181205/unknown.png)


Inside Apex Legends SDK you will find the SDK, consisting of the ***Entity system*** and ***Engine***. I have also included a *DirectX9 Overlay* which is used for rendering the menu as well as ESP.


# Build Instructions:

```
1. Switch Build Settings of both Apex Legends SDK and ApexDriver to Release|x64

2. Go to ApexDriver and in Configuration Properties/Driver Signing/General, go to Sign Mode, and turn it Off.

3. Install DirectX9

DX9 SDK: https://www.microsoft.com/en-us/download/details.aspx?id=6812

Default Path:
$(DXSDK_DIR)Lib\x64\d3d9.lib;$(DXSDK_DIR)Lib\x64\d3dx9.lib;$(DXSDK_DIR)Lib\x86\d3d9.lib;$(DXSDK_DIR)Lib\x86\d3dx9.lib

```

# Credits
[ethanedits](https://github.com/ethanedits)
