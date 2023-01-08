# CAN通信

[总结](https://blog.csdn.net/weixin_44793491/article/details/107298426)（超链接)

CAN是国际标准化的**`串行通信协议`**，采用数据块编码的方式，数据块根据帧的类型，能够让挂载在总线上的不同节点接收到相同的数据，再根据每个节点的配置对信息进行选择性处理（接收or丢弃）。

#### 硬件：

网络的两端必须有**`120Ω的终端电阻`**

![](E:\markdown\STM32\image\15.png)

#### 电平：

| name      | 性质 | 逻辑 | CAN_H | CAN_L | 电压差 |
| --------- | ---- | ---- | ----- | ----- | ------ |
| Recessive | 隐   | 1    | 2.5V  | 2.5V  | 0V     |
| Dominant  | 显性 | 0    | 3.5V  | 1.5V  | 2V     |

#### CAN帧：

| 序号 | 名称   | 帧用途                                                       |
| ---- | ------ | ------------------------------------------------------------ |
| 1    | 数据帧 | 用于发送单元向接收单元传送数据的帧。                         |
| 2    | 遥控帧 | 用于接收单元向具有相同 ID 的发送单元请求数据的帧。           |
| 3    | 错误帧 | 用于当检测出错误时向其它单元通知错误的帧。 （硬件自动完成）  |
| 4    | 过载帧 | 当一个节点正忙于处理接收的信息,可以通知其它节点暂缓发送新报文。（硬件自动完成） |
| 5    | 帧间隔 | 用于将数据帧及遥控帧与前面的帧分离开来的帧（硬件自动完成）   |

![](E:\markdown\STM32\image\16.png)

![](E:\markdown\STM32\image\17.png)



#### CAN仲裁：

1. 在总线空闲时，最先开始发送的节点获得发送权，一旦开始发送，不会被其他节点抢占。

2. 多个节点同时开始发送时，各发送节点从仲裁段的第一位开始进行仲裁。连续输出显性电平最多的节点可继续发送。(Dominant ：显性优先)

3. 具有相同ID的数据帧和遥控帧在总线上竞争时，仲裁段的最后一位（RTR）为显性位的数据帧具有优先权可继续发送。

4. 标准格式ID与具有相同ID的遥控帧或者扩展格式的数据帧在总线上竞争时，标准格式的RTR 位为显性位的具有优先权可继续发送。

#### CAN过滤器：

* 列表模式：判断报文ID与其是否一致
* 掩码模式：通过设定**`屏蔽码`**与**`验证码`**的方式来实现筛选出特定位上特定数值的ID报文。

| 工作模式         | CAN_FxR1寄存器和CAN_FxR2寄存器定义                           |
| ---------------- | ------------------------------------------------------------ |
| 32位宽的列表模式 | 两寄存器的定义一样，都用来存储某个期望通过的CAN ID，这样就可以存入2个期望通过的CAN ID(标准CAN ID和扩展CAN ID均可)。 |
| 16位宽的列表模式 | 两寄存器定义一样，且各自拆成两个，则总共可以写入4个标准CAN ID。 |
| 32位宽掩码模式   | CAN_FxR1用做32位宽的验证码，而CAN_FxR2则用作32位宽的屏蔽码。 |
| 16位宽的掩码模式 | 可以当做2对验证码+屏蔽码组合来用，但它只能对标准CAN ID进行过滤。 |


​	

```c
//过滤器Filter配置（32位掩码模式）
HAL_StatusTypeDef CANFilterInit(CAN_HandleTypeDef* hcan){
  CAN_FilterTypeDef  sFilterConfig;    //can过滤器初始化结构体定义

  sFilterConfig.FilterBank = 0;        //过滤器
                                      /*!< Specifies the filter bank which will be initialized.
                                       For single CAN instance(14 dedicated filter banks),
                                       this parameter must be a number between Min_Data = 0 and Max_Data = 											13.
                                       For dual CAN instances(28 filter banks shared),
                                       this parameter must be a number between Min_Data = 0 and Max_Data = 											27. */
  sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;   //掩码模式
  sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;  //位宽设置为32bit
  sFilterConfig.FilterIdHigh = 0x0000;                //标识符寄存器
  sFilterConfig.FilterIdLow = 0x0000;                 //标识符寄存器
  sFilterConfig.FilterMaskIdHigh = 0x0000;            //屏蔽寄存器
  sFilterConfig.FilterMaskIdLow = 0x0000;             //屏蔽寄存器
  sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;  //接收到的报文放到FIFO0邮箱当中
  sFilterConfig.FilterActivation = ENABLE;            //使能过滤器
  sFilterConfig.SlaveStartFilterBank = 14;            //为从属can选择开始的过滤器
  return HAL_OK;
}
```

```c
//CAN信号发送实例
void CanTransmit_DJI_1234(CAN_HandleTypeDef *hcanx, int16_t cm1_iq, int16_t cm2_iq, int16_t cm3_iq, int16_t cm4_iq){
	CAN_TxHeaderTypeDef TxMessage;
		
	TxMessage.DLC=0x08;         //Data的长度
	TxMessage.StdId=0x200;      //标准ID
	TxMessage.IDE=CAN_ID_STD;   //type of identifier 标准or扩展帧
	TxMessage.RTR=CAN_RTR_DATA; //   帧格式：数据帧和遥控帧

	uint8_t TxData[8];
	TxData[0] = (uint8_t)(cm1_iq >> 8);   
	TxData[1] = (uint8_t)cm1_iq;          
	TxData[2] = (uint8_t)(cm2_iq >> 8);   
	TxData[3] = (uint8_t)cm2_iq;
	TxData[4] = (uint8_t)(cm3_iq >> 8);   
	TxData[5] = (uint8_t)cm3_iq;
	TxData[6] = (uint8_t)(cm4_iq >> 8);   
	TxData[7] = (uint8_t)cm4_iq;         
	while(HAL_CAN_GetTxMailboxesFreeLevel(hcanx) == 0) ;      //等待空的发送邮箱
	if(HAL_CAN_AddTxMessage(hcanx,&TxMessage,TxData,&TxMailbox)!=HAL_OK)  //发送控制信号
	{
		 Error_Handler();       //如果CAN信息发送失败则进入死循环
	}
}
```

* 接收中断开启必要性

打开中断是为了CPU能够及时接受和处理放在 “接受邮箱” 中的报文。STM32F103系列单片机中CAN中具有两个“接受邮箱”，即**`FIFO0`**与**`FIFO1`**，每一个邮箱又有三层，每一层都可以存放一条报文，与过滤器匹配的报文会被放入FIFO邮箱中。