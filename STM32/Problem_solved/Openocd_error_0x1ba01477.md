

```shell
Info : The selected transport took over low-level target control. The results might differ compared to plain JTAG/SWD
adapter speed: 8000 kHz
adapter_nsrst_delay: 100
Info : clock speed 8000 kHz
Info : STLINK v2 JTAG v31 API v2 SWIM v7 VID 0x0483 PID 0x3748
Info : using stlink api v2
Info : Target voltage: 3.162004
Info : Unable to match requested speed 8000 kHz, using 4000 kHz
Info : Stlink adapter speed set to 4000 kHz
Warn : UNEXPECTED idcode: 0x2ba01477
Error: expected 1 of 1: 0x1ba01477
in procedure 'program' 
in procedure 'init' called at file "embedded:startup.tcl", line 495
in procedure 'ocd_bouncer'
** OpenOCD init failed **
shutdown command invoked
```

## 法一

在stm32f1x.cfg 文件中，在文件最上方添加

```shell
set CPUTAPID 0
```

The zero tells OpenOCD to ignore the id number, so any MCU will then work…

Information Source: [OpenOCD TAPs](http://openocd.org/doc/html/TAP-Declaration.html#TAP-Declaration-Commands)

## 法二

修改某一行

```shell
#jtag scan chain
if { [info exists CPUTAPID] } {
   set _CPUTAPID $CPUTAPID
} else {
   if { [using_jtag] } {
      # See STM Document RM0008 Section 26.6.3
      set _CPUTAPID 0x3ba00477
   } {
      # this is the SW-DP tap id not the jtag tap id
      set _CPUTAPID 0x1ba01477
   }
}
```

为

```shell
set _CPUTAPID 0x2ba01477
```



