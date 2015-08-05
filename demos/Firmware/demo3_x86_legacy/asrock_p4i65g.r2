af+ 0xf000:0x5786 8 SMBus_ICH5_Reg_Write_Byte_SL
af+ 0xf000:0x578e 8 SMBus_ICH5_Reg_Read_Byte_SL
"CCa 0xf000:0x5786 void SMBus_ICH5_Reg_Write_Byte_SL(uint8_t reg<ah>, uint8_t value<al>);"
"CCa 0xf000:0x578e void SMBus_ICH5_Reg_Read_Byte_SL<al>(uint8_t reg<ah>);"

"CCa 0xf000:0x574d value = 0xD3; reg = 0x4; // XMIT_SLVA - Transmit Slave Address"
"CCa 0xf000:0x575b reg = 0x3; // HST_CMD - Host Command"
"CCa 0xf000:0x5762 value = 0x48; reg = 0x2; // HST_CNT - Host Control, value [6] - Start transmission, [3] - Byte Data mode"
af+ 0xf000:0x574d 57 SMBus_Read_Byte_SL
f .SMB_Write_CMD=0xf000:0x5755
f .SMB_Start_CMD=0xf000:0x5762
f .SMB_Read_Data=0xf000:0x5779
f .SMB_Wait=0xf000:0x576d

"CCa 0xf000:0x56e0 value = 0xD2; reg = 0x4; // XMIT_SLVA - Transmit Slave Address"
"CCa 0xf000:0x56ed value"
"CCa 0xf000:0x56ef reg = 0x3; // HST_CMD - Host Command"
"CCa 0xf000:0x56f7 value"
"CCa 0xf000:0x56fb reg = 0x5; // HST_D0 - Host Data 0"
"CCa 0xf000:0x5703 value = 0x48; reg = 0x2; // HST_CNT - Host Control, value [6] - Start transmission, [3] - Byte Data mode"
af+ 0xf000:0x56e0 64 SMBus_Write_Byte_SL
f .SMB_Write_CMD=0xf000:0x56e9
f .SMB_Write_Data=0xf000:0x56f7
f .SMB_Start_CMD=0xf000:0x5703
f .SMB_Wait=0xf000:0x570e

af+ 0xf000:0x5720 45 SMBus_Read_Block_SL
af+ 0xf000:0x56b1 47 SMBus_Write_Block_SL

af+ 0xf000:0x47a3 7 SMBus_ICH5_Reg_Write_Byte
af+ 0xf000:0x479c 7 SMBus_ICH5_Reg_Read_Byte
"CCa 0xf000:0x47a3 void SMBus_ICH5_Reg_Write_Byte(uint8_t reg<ah>, uint8_t value<al>);"
"CCa 0xf000:0x479c void SMBus_ICH5_Reg_Read_Byte<al>(uint8_t reg<ah>);"

"CCa 0xf000:0x47ad HST_STS - Host Status"
"CCa 0xf000:0x47b6 [3] - BUS_ERR; [2] - DEV_ERR; [1] - INTR (command termination); [0] - HOST_BUSY;"
af+ 0xf000:47aa 24 SMBus_Host_Transaction_Complete_Errors_Check
f .wait=0xf000:0x47ad
f .return_clear_carry=0xf000:0x47c0

"CCa 0xf000:0x47c5 HST_STS - Host Status"
"CCa 0xf000:0x47cb [1] - INTR (1 - successfull completion)"
af+ 0xf000:0x47c2 19 SMBus_Host_Transaction_Complete_Check
f .wait=0xf000:0x47c5
f .return_clear_carry=0xf000:0x47d3

Cd 2 @ 0xf000:0x46e0
Cd 2 @ 0xf000:0x46f2
Cd 2 @ 0xf000:0x4700
Cd 2 @ 0xf000:0x470c
Cd 2 @ 0xf000:0x4714
Cd 2 @ 0xf000:0x4722
Cd 2 @ 0xf000:0x472b
"CCa 0xf000:0x46e8 reg = 0x4; // XMIT_SLVA - Transmit Slave Address"
"CCa 0xf000:0x46f8 reg = 0x3; // HST_CMD - Host Command"
"CCa 0xf000:0x4702 value = 0x48; reg = 0x2; // HST_CNT - Host Control, value [6] - Start transmission, [3] - Byte Data mode"
"CCa 0xf000:0x4716 SMBus timeout or error"
"CCa 0xf000:0x4724 reg = 0x5; // HST_D0 - Host Data 0"
af+ 0xf000:0x46d2 100 SMBus_Read_Byte
f .SMB_Write_Address=0xf000:0x46e0
f .SMB_Write_CMD=0xf000:0x46f4
f .SMB_Start_CMD=0xf000:0x4702
f .SMB_Wati_Transaction_Completion=0xf000:0x470e
f .SMB_Host_Reset=0xf000:0x4716
f .SMB_Read_DATA0=0xf000:0x4724
f .return_clear_carry=0xf000:0x472d
f .return=0xf000:0x4732

af+ 0xf000:0x4736 102 SMBus_Write_Byte

af+ 0xf000:0x5c93 51 SIO_Init
f .read_loop=0xf000:0x5c9b
f .next_item=0xf000:0x5ca3
f .write_loop=0xf000:0x5caa
f .return=0xf000:0x5cbf

s 0xf000:0x4736
