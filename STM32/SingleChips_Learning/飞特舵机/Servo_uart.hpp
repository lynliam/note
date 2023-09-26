//
// Created by Quan2 on 2023/8/3.
//

#ifndef SERVO_USART_SERVO_UART_HPP
#define SERVO_USART_SERVO_UART_HPP
#ifdef __cplusplus
extern "C" {
#endif
/**--------------------------C-----------------------------**/
#include "main.h"
#include "gpio.h"
#include "usart.h"
#include "retarget.h"

#ifdef __cplusplus
};
/**-----------------------------C++---------------------------**/
#endif

#define INST_PING 0x01
#define INST_READ 0x02
#define INST_WRITE 0x03
#define INST_REG_WRITE 0x04
#define INST_REG_ACTION 0x05
#define INST_SYNC_READ 0x82
#define INST_SYNC_WRITE 0x83


#define	SMS_STS_1M 0
#define	SMS_STS_0_5M 1
#define	SMS_STS_250K 2
#define	SMS_STS_128K 3
#define	SMS_STS_115200 4
#define	SMS_STS_76800	5
#define	SMS_STS_57600	6
#define	SMS_STS_38400	7

//内存表定义
//-------EPROM(只读)--------
#define SMS_STS_MODEL_L 3
#define SMS_STS_MODEL_H 4

//-------EPROM(读写)--------
#define SMS_STS_ID 5
#define SMS_STS_BAUD_RATE 6
#define SMS_STS_MIN_ANGLE_LIMIT_L 9
#define SMS_STS_MIN_ANGLE_LIMIT_H 10
#define SMS_STS_MAX_ANGLE_LIMIT_L 11
#define SMS_STS_MAX_ANGLE_LIMIT_H 12
#define SMS_STS_CW_DEAD 26
#define SMS_STS_CCW_DEAD 27
#define SMS_STS_OFS_L 31
#define SMS_STS_OFS_H 32
#define SMS_STS_MODE 33

//-------SRAM(读写)--------
#define SMS_STS_TORQUE_ENABLE 40
#define SMS_STS_ACC 41
#define SMS_STS_GOAL_POSITION_L 42
#define SMS_STS_GOAL_POSITION_H 43
#define SMS_STS_GOAL_TIME_L 44
#define SMS_STS_GOAL_TIME_H 45
#define SMS_STS_GOAL_SPEED_L 46
#define SMS_STS_GOAL_SPEED_H 47
#define SMS_STS_LOCK 55
#define SMS_ANGEL_MIN 9
#define SMS_ANGEL_MAX 9
#define SMS_ID 5
#define SMS_POSE_MAKEUP 0x1F

//-------SRAM(只读)--------
#define SMS_STS_PRESENT_POSITION_L 56
#define SMS_STS_PRESENT_POSITION_H 57
#define SMS_STS_PRESENT_SPEED_L 58
#define SMS_STS_PRESENT_SPEED_H 59
#define SMS_STS_PRESENT_LOAD_L 60
#define SMS_STS_PRESENT_LOAD_H 61
#define SMS_STS_PRESENT_VOLTAGE 62
#define SMS_STS_PRESENT_TEMPERATURE 63
#define SMS_STS_MOVING 66
#define SMS_STS_PRESENT_CURRENT_L 69
#define SMS_STS_PRESENT_CURRENT_H 70

#define BYTEHEAD 0xFF



class ServoMotor
{
public:
    ServoMotor(UART_HandleTypeDef uart_servo_handle_){
        uart_servo_handle = uart_servo_handle_;
        ID = 0x01;
        End = 0;  //大小端结构
        Error = 0;  //舵机状态
    }
/**
 * BIT11为方向位，表示正负方向，其他位可表示范围为0-2047步，设置零点位置
 * @param pose -2047 ~ 2047
 * @return
 */
    int set_pose_makeup(int16_t pose)
    {
        uint8_t bBuf[2];
        if(pose<0){
            pose = -pose;
            pose |= (1<<15);
        }
        Host2SCS(bBuf,bBuf+1,pose);
        return genWrite(SMS_POSE_MAKEUP, bBuf, 7);
    }
/**
 * 如果是一个电机可以不用
 * @param ID_
 */
    int set_ID(uint8_t ID_)
    {
        ID = ID_;
        uint8_t bBuf[8];
        bBuf[0]=BYTEHEAD;
        bBuf[1]=BYTEHEAD;
        bBuf[2] = 0xFE;
        bBuf[3] = 0X04;
        bBuf[4] = INST_WRITE;
        bBuf[5] = SMS_ID;
        bBuf[6] = ID_;
        bBuf[7] = check_sum(bBuf,7);
        HAL_UART_Transmit(&uart_servo_handle,bBuf,8,0xffff);
    }
/**
 * 设置电机模式为旋转
 * @return
 */
    int WheelMode()
    {
        return writeByte(SMS_STS_MODE, 1);
    }
/**
 *
 * @param Position  最大 32766 最小 -32766
 * @param Speed 速度  0~254
 * @param ACC  加速度 0~254
 * @return
 */
    int WritePosEx(int16_t Position, uint16_t Speed, uint8_t ACC)
    {
        uint8_t bBuf[7];
        if(Position<0){
            Position = -Position;
            Position |= (1<<15);
        }

        bBuf[0] = ACC;
        Host2SCS(bBuf+1, bBuf+2, Position);
        Host2SCS(bBuf+3, bBuf+4, 0);
        Host2SCS(bBuf+5, bBuf+6, Speed);

        return genWrite(SMS_STS_ACC, bBuf, 7);
    }
    /**
     * 限制最大位置
     * @param angle 1~4095
     * @return
     */
    int LimitAngleMAX(int16_t angle)
    {
        uint8_t  bBuf[2];
        Host2SCS(bBuf,bBuf+1,angle);
        return genWrite(SMS_ANGEL_MAX, bBuf, 2);
    }
    /**
     * 限制最小位置
     * @param angle 0~4094
     * @return
     */
    int LimitAngleMIM(int16_t angle)
    {
        uint8_t  bBuf[2];
        Host2SCS(bBuf,bBuf+1,angle);
        return genWrite(SMS_ANGEL_MIN, bBuf, 2);
    }
/**
 * 别用
 */
    void search_state()
    {
        uint8_t bag[6];
        bag[0]=0xFF;
        bag[1]=0xFF;
        bag[2]=ID;
        bag[3]=0x02;
        bag[4]=0x01;
        bag[5]= check_sum(bag,5);

        HAL_UART_Transmit(&uart_servo_handle,bag,6,0xff);
        HAL_UART_Receive_IT(&uart_servo_handle,bag,6);
    }
/**
 * 未测试
 * @param param1
 * @param param2
 */
    void read_data(uint8_t param1,uint8_t param2)
    {
        uint8_t bag[8];
        bag[0]=0xFF;
        bag[1]=0xFF;
        bag[2]=ID;
        bag[3]=0x04;
        bag[4]=0x02;
        bag[5]=param1;
        bag[6]=param2;
        bag[7]= check_sum(bag,7);
        HAL_UART_Transmit(&uart_servo_handle,bag,8,0xff);
        HAL_UART_Receive_IT(&uart_servo_handle,receive_bag8,8);
    }

    uint8_t receive_bag7[7];
    uint8_t receive_bag8[8];
private:
    UART_HandleTypeDef uart_servo_handle;
    uint16_t ID;
    uint8_t End;
    uint8_t Error;

    uint8_t check_sum(uint8_t *data, uint8_t num)
    {
        uint8_t sum = 0;
        for(int i=2;i<num;i++)
        {
            sum += data[i];
        }
        return ~sum;
    }

/**
 * 1个16位拆分为2个八位数
 * @param DataL 低位
 * @param DataH 高位
 * @param Data 数据
 */
    void Host2SCS(uint8_t *DataL, uint8_t* DataH, int Data)
    {
        if(End){
            *DataL = (Data>>8);
            *DataH = (Data&0xff);
        }else{
            *DataH = (Data>>8);
            *DataL = (Data&0xff);
        }
    }

/**
 * 2个八位数组合为16位数
 * @param DataL 低位
 * @param DataH 高位
 * @return
 */
    int SCS2Host(uint8_t DataL, uint8_t DataH)
    {
        int Data;
        if(End){
            Data = DataL;
            Data<<=8;
            Data |= DataH;
        }else{
            Data = DataH;
            Data<<=8;
            Data |= DataL;
        }
        return Data;
    }
    int genWrite(uint8_t MemAddr, uint8_t *nDat, uint8_t nLen)
    {
        writeBuf(MemAddr, nDat, nLen, INST_WRITE);
        return 0;
    }

    /**
     * 写数组函数
     * @param MemAddr
     * @param nDat
     * @param nLen
     * @param Fun
     */
    void writeBuf(uint8_t MemAddr, uint8_t *nDat, uint8_t nLen, uint8_t Fun)
    {
        uint8_t i;
        uint8_t msgLen = 2;
        uint8_t bBuf[6];
        uint8_t CheckSum = 0;
        bBuf[0] = 0xff;
        bBuf[1] = 0xff;
        bBuf[2] = ID;
        bBuf[4] = Fun;
        if(nDat){
            msgLen += nLen + 1;
            bBuf[3] = msgLen; //数据长度
            bBuf[5] = MemAddr;
            HAL_UART_Transmit(&uart_servo_handle,bBuf,6,0xffff);

        }else{
            bBuf[3] = msgLen;
            HAL_UART_Transmit(&uart_servo_handle,bBuf,5,0xffff);
        }
        CheckSum = ID + msgLen + Fun + MemAddr;
        if(nDat){
            for(i=0; i<nLen; i++){
                CheckSum += nDat[i];
            }
            HAL_UART_Transmit(&uart_servo_handle,nDat,nLen,0xffff);
        }
        CheckSum = ~CheckSum;
        HAL_UART_Transmit(&uart_servo_handle,&CheckSum,1,0xffff);
    }

    int writeByte(uint8_t MemAddr, uint8_t bDat)
    {
        writeBuf(MemAddr, &bDat, 1, INST_WRITE);
        return 0;
    }

};


#endif //SERVO_USART_SERVO_UART_HPP
