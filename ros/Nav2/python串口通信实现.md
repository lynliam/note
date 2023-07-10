# python中串口通信的步骤及实现

```shell
import serial#导入串口通信库
from time import sleep

ser = serial.Serial()

def port_open_recv():#对串口的参数进行配置
    ser.port='com3'
    ser.baudrate=9600
    ser.bytesize=8
    ser.stopbits=1
    ser.parity="N"#奇偶校验位
    ser.open()
    if(ser.isOpen()):
        print("串口打开成功！")
    else:
        print("串口打开失败！")
#isOpen()函数来查看串口的开闭状态



def port_close():
    ser.close()
    if(ser.isOpen()):
        print("串口关闭失败！")
    else:
        print("串口关闭成功！")

def send(send_data):
    if(ser.isOpen()):
        ser.write(send_data.encode('utf-8'))#编码
        print("发送成功",send_data)
    else:
        print("发送失败！")

if __name__ == '__main__':
    port_open_recv()
    while True:
        a=input("输入要发送的数据：")
        send(a)
        sleep(0.5)#起到一个延时的效果，这里如果不加上一个while True，程序执行一次就自动跳出了

```



```shell
import serial

#对串口的参数进行配置
ser = serial.Serial(
port=None,   #设置串口号
baudrate=9600,     # 波特率
bytesize=EIGHTBITS,   # 数据位数
parity=PARITY_NONE,   # 奇偶校验位
stopbits=STOPBITS_ONE, # 停止位
timeout=None,      # 读超时设置
xonxoff=0,       # 软件流控，流程控制，解决数据丢失问题
rtscts=0,        # 硬件流控， 
#pc机中常用的两种流控制是硬件流控制（包括rts/cts、dtr/cts等）和软件流控制xon/xoff（继续/停止）
interCharTimeout=None  # 字符间隔超时


#不同平台下的初始化
ser=serial.Serial("/dev/ttyUSB0",9600,timeout=0.5) #使用USB连接串行口
ser=serial.Serial("/dev/ttyAMA0",9600,timeout=0.5) #使用树莓派的GPIO口连接串行口
ser=serial.Serial(1,9600,timeout=0.5)#winsows系统使用com1口连接串行口
ser=serial.Serial("com1",9600,timeout=0.5)#winsows系统使用com1口连接串行口
ser=serial.Serial("/dev/ttyS1",9600,timeout=0.5)#Linux系统使用com1口连接串行口


#函数方法
ser.isOpen()：查看端口是否被打开。
ser.open() ：打开端口‘。
ser.close()：关闭端口。
ser.read()：从端口读字节数据。默认1个字节。
ser.read_all():从端口接收全部数据。
ser.write("hello")：向端口写数据。
ser.readline()：读一行数据。
ser.readlines()：读多行数据。
in_waiting()：返回接收缓存中的字节数。
flush()：等待所有数据写出。
flushInput()：丢弃接收缓存中的所有数据。
flushOutput()：终止当前写操作，并丢弃发送缓存中的数据。
```

