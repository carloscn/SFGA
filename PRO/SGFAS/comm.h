#ifndef COMM_H
#define COMM_H

// 命令协议

// 命令协议遵循格式：
// 0xAA 0xBB 0x(cmd) 0x(length，从下一个字节算起，且不包含校验位) 0x(dat1) 0x(dat2) 0x(dat3) 0x(dat4) ...... 0x(校验位P)

// 校验算法： ^算法
// 例如：  0xAA 0xBB 0x01 0x07 0x00 0x01 0x02 0x03 0x04 0x05 0x06 0x07
// P = 0xAA^0xBB^0x01^0x08^0x00^0x01^0x02^0x03^0x04^0x05^0x06^0x07



#define                     CMD_ALARM                         0x00
#define                     CMD_GET_IMAGE                     0x01
#define                     CMD_THEFT_CHECKED                 0x02
#define                     CMD_ID_CONFIRM                    0x03
#define                     CMD_ID_CONFIRM_NO                   0x04
#define                     CMD_ID_CONFIRM_YES                  0x05
#define                     CMD_STOP_WARN                       0x06

// linux
#endif // COMM_H
