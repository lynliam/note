# Can I add Arm Compiler 5 to Keil MDK 5.37 or newer?



If you need to build your project using Arm Compiler 5 or cannot migrate to Arm Compiler for Embedded, you must download and add Arm Compiler 5 into your Keil MDK installation manually as follows:

1. Open the [*Arm Compiler downloads index*](https://developer.arm.com/documentation/ka005198/latest) and read the important information at the top of the page.
2. In the "Releases without Functional Safety qualification or certification" "section, find the row for *Arm Compiler 5.06 update 7 (build 960).* Follow the link to download this Arm Compiler 5 release.
3. Select revision `r5p6-07rel1` (if necessary), and download the **Arm Compiler 5.06 update 7 (build 960) Win32** package for windows.
4. In the Keil MDK installation directory, install the compiler toolchain into the `.\ARM` subdirectory, e.g., assuming the Keil tools are installed at `C:\Keil_v5` , install the compiler toolchain at:
   1. `C:\Keil_v5\ARM\Arm_Compiler_5.06u7`
5. Follow the steps in the [*Manage Arm Compiler Versions*](https://www.keil.com/support/man/docs/uv4/uv4_armcompilers.htm) section to register and add the installed Arm Compiler 5.

> ### Caution
>
> Installing the toolchain into its default installation directory is not supported and will result in the tools reporting following error when building a project:
>
> ```
> Error: C9555E: Failed to check out a license
> ```

> ### Note
>
> Note: If after building, this error appears in the output window:
>
> ```
> *** Error: The configured compiler version '5.06 update 7 (build 960)' does not support the selected User Based Licensing technology
> ```
>
> Then follow the steps in [Keil MDK: unexpected activation of User-Based Licensing (UBL)](https://developer.arm.com/documentation/ka005577/latest)





**Install**

In the `C:\Keil_v5\ARM` directory, the Arm Compiler toolchains reside as a subfolder. Do not change the names of the original folders, i.e., preserve the `.\ARMCC` and `.\ARMCLANG` folders - these are the Arm Compiler versions that installed together with the MDK tools.

Open the downloaded installer. When prompted, change the default installation path to a subfolder inside the Keil directory, e.g., install Arm Compiler 5 v 5.06u6 in the `C:\Keil_v5\ARM\ARMCCv506u6`. folder. Finish the installation.

**Associate**

1. Open Keil uVison
2. Let the IDE know about the newly added compiler. See the steps in: [Setup Default Arm Compiler Version](https://developer.arm.com/documentation/101407/0538/Creating-Applications/Tips-and-Tricks/Setup-Default-Arm-Compiler-Version).
3. Open a MDK project. Choose which compiler version to use to build that project. See the steps in: [Selecting the Arm Compiler Version](https://developer.arm.com/documentation/101407/0538/Creating-Applications/Tips-and-Tricks/Manage-Arm-Compiler-Versions).

#### TROUBLESHOOTING

**Licensing** The Keil license on the PC has to support the selected version of the Arm compiler. See [Licensing errors](https://developer.arm.com/documentation/101454/0110/License-Management/Licensing-Errors). There could be compiler or linker errors if the compiler toolchain:

- was released after the support period for the license expired
- version downloaded was never included within a MDK software release
- is older than Arm Compiler 5.02

**Version** This feature only works for:

- MDK v5.12 or later
- Arm Compiler 5.04 or later
- Arm Compiler for Embedded 6.01 or later

**Older tool version** For tools too old to use this feature, including:

- MDK v5.11 or older
- Arm Compiler 5.01 or older

Use the older method for switching compiler toolschains. See [Application Note 267: Update Arm Compilation Tools](https://developer.arm.com/documentation/kan267/latest/), Or, rather than switch compiler toolschains,instead have multiple versions of the Keil IDE. See [µVision: Using Different Versions of the Keil IDE On the Same Computer](https://developer.arm.com/documentation/ka002949/latest).