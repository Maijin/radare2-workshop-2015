#include <idc.idc>

static main(void) 
{
	Message("OMAP3430 Script Started!\n");
	System_Control_Module();
	CM_Module();
	PRM_Module();
	MLB_Module();
	MMU_Module();
	DMA_Module();
	INTC_Module();
	GPIO_Module();
	Message("OMAP3430 Script Done!\n");
}

// --- For internal usage

static CreateByteRegister(base, offset, name, comment) 
{
	auto addr;
	addr = base + offset;
	MakeByte(addr);
	MakeName(addr, name);
	MakeRptCmt(addr, comment);
}

static CreateWordRegister(base, offset, name, comment) 
{
	auto addr;
	addr = base + offset;
	MakeWord(addr);
	MakeName(addr, name);
	MakeRptCmt(addr, comment);
}

static CreateDwordRegister(base, offset, name, comment) 
{
	auto addr;
	addr = base + offset;
	MakeDword(addr);
	MakeName(addr, name);
	MakeRptCmt(addr, comment);
}

static memcpy(to, from, size)
{
	auto i;
	for (i = 0; i  < size; i = i + 1)
	{
		PatchByte(to, Byte(from) );
		from = from + 1;
		to = to + 1;
	}
}

// --- System Control Module
#define OMAP3430_SCM_BASE 0x48002000
#define OMAP3430_SCM_END 0x48003FFF

// --- Clock Manager Module
#define OMAP3430_CM_REG_A_BASE 0x48004000
#define OMAP3430_CM_REG_A_END 0x48005FFF

// --- PRM Module
#define OMAP3430_PRM_BASE 0x48306000
#define OMAP3430_PRM_END 0x48307FFF

// --- L3 Core Configuration Module

// --- L4 Core Configuration Module
#define OMAP3430_L4_AP_BASE 0x48040000
#define OMAP3430_L4_AP_END 0x480407FF
#define OMAP3430_L4_IP_BASE 0x48040800
#define OMAP3430_L4_IP_END 0x48040FFF
#define OMAP3430_L4_LA_BASE 0x48041000
#define OMAP3430_L4_LA_END 0x48041FFF

// --- IPC Mailbox Module
#define OMAP3430_MLB_BASE 0x48094000
#define OMAP3430_MLB_END 0x48094FFF

// --- Memory Management Units Module
#define OMAP3430_MMU_CAM_BASE 0x480BD400
#define OMAP3430_MMU_CAM_END 0x480BD4FF
#define OMAP3430_MMU_IVA2_BASE 0x5D00000
#define OMAP3430_MMU_IVA2_END 0x5D000FF

// --- DMA Module
#define OMAP3430_SDMA_BASE 0x48056000
#define OMAP3430_SDMA_END 0x48056FFF

// --- Interrupt Controller Module
#define OMAP3430_MPU_INTC_BASE 0x48200000
#define OMAP3430_MPU_INTC_END 0x48200FFF
#define OMAP3430_MODEM_INTC_BASE 0x480C7000
#define OMAP3430_MODEM_INTC_END 0x480C7FFF

// --- Memory Subsystem
#define OMAP3430_GPMC_BASE 0x6E000000
#define OMAP3430_GPMC_END 0x6EFFFFFF
#define OMAP3430_SMS_BASE 0x6C000000
#define OMAP3430_SMS_END 0x6C00FFFF
#define OMAP3430_SDRC_BASE 0x6D000000
#define OMAP3430_SDRC_END 0x6D00FFFF
#define OMAP3430_OCM_ROM_START 0x40014000
#define OMAP3430_OCM_ROM_END 0x4001BFFF
#define OMAP3430_OCM_RAM_START 0x40200000
#define OMAP3430_OCM_RAM_END 0x4020FFFF

// --- Camera Module

// --- SGX Module
#define OMAP3430_SGX_BASE 0x50000000
#define OMAP3430_SGX_BASE 0x5000FFFF

// --- Display Subsystem Module
#define OMAP3430_DSS_BASE 0x4804FC00
#define OMAP3430_DSS_END 0x48050CFF

// --- Timers Module
#define OMAP3430_32kHz_TIMER_BASE 0x48320000
#define OMAP3430_32kHz_TIMER_END 0x48320FFF
#define OMAP3430_WDTIMER2_BASE 0x48314000
#define OMAP3430_WDTIMER2_END 0x48314FFF
#define OMAP3430_WDTIMER3_BASE 0x49030000
#define OMAP3430_WDTIMER3_END 0x49030FFF
#define OMAP3430_GPTIMER1_BASE 0x48318000
#define OMAP3430_GPTIMER1_END 0x48318FFF
#define OMAP3430_GPTIMER2_BASE 0x49032000
#define OMAP3430_GPTIMER2_END 0x49032FFF
#define OMAP3430_GPTIMER3_BASE 0x49034000
#define OMAP3430_GPTIMER3_END 0x49034FFF
#define OMAP3430_GPTIMER4_BASE 0x49036000
#define OMAP3430_GPTIMER4_END 0x49036FFF
#define OMAP3430_GPTIMER5_BASE 0x49038000
#define OMAP3430_GPTIMER5_END 0x49038FFF
#define OMAP3430_GPTIMER6_BASE 0x4903A000
#define OMAP3430_GPTIMER6_END 0x4903AFFF
#define OMAP3430_GPTIMER7_BASE 0x4903C000
#define OMAP3430_GPTIMER7_END 0x4903CFFF
#define OMAP3430_GPTIMER8_BASE 0x4903E000
#define OMAP3430_GPTIMER8_END 0x4903EFFF
#define OMAP3430_GPTIMER9_BASE 0x49040000
#define OMAP3430_GPTIMER9_END 0x49040FFF
#define OMAP3430_GPTIMER10_BASE 0x48086000
#define OMAP3430_GPTIMER10_END 0x48086FFF
#define OMAP3430_GPTIMER11_BASE 0x48088000
#define OMAP3430_GPTIMER11_END 0x48088FFF

// --- UART Module
#define OMAP3430_UART1_BASE 0x4806A000
#define OMAP3430_UART1_END 0x4806A3FC
#define OMAP3430_UART2_BASE 0x4806C000
#define OMAP3430_UART2_END 0x4806C3FC
#define OMAP3430_UART3_BASE 0x49020000
#define OMAP3430_UART3_END 0x490203FC

// --- I2C Module
#define OMAP3430_I2C1_BASE 0x48070000
#define OMAP3430_I2C1_END 0x48070078 
#define OMAP3430_I2C2_BASE 0x48072000
#define OMAP3430_I2C2_END 0x48072078
#define OMAP3430_I2C3_BASE 0x48060000
#define OMAP3430_I2C3_END 0x48060078

// --- Multichannel SPI Module
#define OMAP3430_MCSPI1_BASE 0x48098000
#define OMAP3430_MCSPI1_END 0x48098FFF
#define OMAP3430_MCSPI2_BASE 0x4809A000
#define OMAP3430_MCSPI2_END 0x4809AFFF
#define OMAP3430_MCSPI3_BASE 0x480B8000
#define OMAP3430_MCSPI3_END 0x480B8FFF
#define OMAP3430_MCSPI4_BASE 0x480BA000
#define OMAP3430_MCSPI4_END 0x480BAFFF

// --- HDQ/1-Wire Module
#define OMAP3430_HDQ_BASE 0x480B2000
#define OMAP3430_HDQ_END 0x480B2FFF

// --- Multichannel Buffered Serial Port Module
#define OMAP3430_MCBSP1_BASE 0x48074000
#define OMAP3430_MCBSP1_END 0x48074FFF
#define OMAP3430_MCBSP5_BASE 0x48096000
#define OMAP3430_MCBSP5_END 0x48096FFF
#define OMAP3430_MCBSP2_BASE 0x49022000
#define OMAP3430_MCBSP2_END 0x49022FFF
#define OMAP3430_MCBSP3_BASE 0x49024000
#define OMAP3430_MCBSP3_END 0x49024FFF
#define OMAP3430_MCBSP4_BASE 0x49026000
#define OMAP3430_MCBSP4_END 0x49026FFF
#define OMAP3430_SLIDETONE_MCBSP2_BASE 0x49028000
#define OMAP3430_SLIDETONE_MCBSP2_END 0x49028FFF
#define OMAP3430_SLIDETONE_MCBSP3_BASE 0x4902A000
#define OMAP3430_SLIDETONE_MCBSP_END 0x4902AFFF

// --- General Purpose I/O Module
#define OMAP3430_GPIO1_BASE 0x48310000
#define OMAP3430_GPIO1_END 0x48310FFF
#define OMAP3430_GPIO2_BASE 0x49050000
#define OMAP3430_GPIO2_END 0x49050FFF
#define OMAP3430_GPIO3_BASE 0x49052000
#define OMAP3430_GPIO3_END 0x49052FFF
#define OMAP3430_GPIO4_BASE 0x49054000
#define OMAP3430_GPIO4_END 0x49054FFF
#define OMAP3430_GPIO5_BASE 0x49056000
#define OMAP3430_GPIO5_END 0x49056FFF
#define OMAP3430_GPIO6_BASE 0x49058000
#define OMAP3430_GPIO6_END 0x49058FFF

// --- System Control Module
static System_Control_Module(void) 
{
	if (!SegCreate(OMAP3430_SCM_BASE, OMAP3430_SCM_END, 0, 1, 0, 0)) {
		Warning("Can't create System Control Module registers segment!\n");
		return;
	}
	SegRename(OMAP3430_SCM_BASE, "SCM");
	SegClass(OMAP3430_SCM_BASE, "REGISTERS");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x0, "OMAP3430_reg_CONTROL_REVISION", "Control module revision");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x10, "OMAP3430_reg_CONTROL_SYSCONFIG", "Set various parameters relative to the Idle mode of the Control module");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x30, "OMAP3430_reg_CONTROL_PADCONF_SDRC_D0", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x34, "OMAP3430_reg_CONTROL_PADCONF_SDRC_D2", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x38, "OMAP3430_reg_CONTROL_PADCONF_SDRC_D4", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x3C, "OMAP3430_reg_CONTROL_PADCONF_SDRC_D6", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x40, "OMAP3430_reg_CONTROL_PADCONF_SDRC_D8", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x44, "OMAP3430_reg_CONTROL_PADCONF_SDRC_D10", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x48, "OMAP3430_reg_CONTROL_PADCONF_SDRC_D12", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x4C, "OMAP3430_reg_CONTROL_PADCONF_SDRC_D14", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x50, "OMAP3430_reg_CONTROL_PADCONF_SDRC_D16", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x54, "OMAP3430_reg_CONTROL_PADCONF_SDRC_D18", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x58, "OMAP3430_reg_CONTROL_PADCONF_SDRC_D20", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x5C, "OMAP3430_reg_CONTROL_PADCONF_SDRC_D22", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x60, "OMAP3430_reg_CONTROL_PADCONF_SDRC_D24", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x64, "OMAP3430_reg_CONTROL_PADCONF_SDRC_D26", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x68, "OMAP3430_reg_CONTROL_PADCONF_SDRC_D28", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x6C, "OMAP3430_reg_CONTROL_PADCONF_SDRC_D30", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x70, "OMAP3430_reg_CONTROL_PADCONF_SDRC_CLK", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x74, "OMAP3430_reg_CONTROL_PADCONF_SDRC_DQS1", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x78, "OMAP3430_reg_CONTROL_PADCONF_SDRC_DQS3", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x7C, "OMAP3430_reg_CONTROL_PADCONF_GPMC_A2", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x80, "OMAP3430_reg_CONTROL_PADCONF_GPMC_A4", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x84, "OMAP3430_reg_CONTROL_PADCONF_GPMC_A6", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x88, "OMAP3430_reg_CONTROL_PADCONF_GPMC_A8", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x8C, "OMAP3430_reg_CONTROL_PADCONF_GPMC_A10", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x90, "OMAP3430_reg_CONTROL_PADCONF_GPMC_D1", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x94, "OMAP3430_reg_CONTROL_PADCONF_GPMC_D3", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x98, "OMAP3430_reg_CONTROL_PADCONF_GPMC_D5", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x9C, "OMAP3430_reg_CONTROL_PADCONF_GPMC_D7", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA0, "OMAP3430_reg_CONTROL_PADCONF_GPMC_D9", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA4, "OMAP3430_reg_CONTROL_PADCONF_GPMC_D11", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA8, "OMAP3430_reg_CONTROL_PADCONF_GPMC_D13", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xAC, "OMAP3430_reg_CONTROL_PADCONF_GPMC_D15", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xB0, "OMAP3430_reg_CONTROL_PADCONF_GPMC_NCS1", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xB4, "OMAP3430_reg_CONTROL_PADCONF_GPMC_NCS3", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xB8, "OMAP3430_reg_CONTROL_PADCONF_GPMC_NCS5", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xBC, "OMAP3430_reg_CONTROL_PADCONF_GPMC_NCS7", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xC0, "OMAP3430_reg_CONTROL_PADCONF_GPMC_NADV_ALE", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xC4, "OMAP3430_reg_CONTROL_PADCONF_GPMC_NWE", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xC8, "OMAP3430_reg_CONTROL_PADCONF_GPMC_NBE1", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xCC, "OMAP3430_reg_CONTROL_PADCONF_GPMC_WAIT0", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xD0, "OMAP3430_reg_CONTROL_PADCONF_GPMC_WAIT2", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xD4, "OMAP3430_reg_CONTROL_PADCONF_DSS_PCLK", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xD8, "OMAP3430_reg_CONTROL_PADCONF_DSS_VSYNC", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xDC, "OMAP3430_reg_CONTROL_PADCONF_DSS_DATA0", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xE0, "OMAP3430_reg_CONTROL_PADCONF_DSS_DATA2", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xE4, "OMAP3430_reg_CONTROL_PADCONF_DSS_DATA4", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xE8, "OMAP3430_reg_CONTROL_PADCONF_DSS_DATA6", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xEC, "OMAP3430_reg_CONTROL_PADCONF_DSS_DATA8", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xF0, "OMAP3430_reg_CONTROL_PADCONF_DSS_DATA10", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xF4, "OMAP3430_reg_CONTROL_PADCONF_DSS_DATA12", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xF8, "OMAP3430_reg_CONTROL_PADCONF_DSS_DATA14", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xFC, "OMAP3430_reg_CONTROL_PADCONF_DSS_DATA16", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x100, "OMAP3430_reg_CONTROL_PADCONF_DSS_DATA18", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x104, "OMAP3430_reg_CONTROL_PADCONF_DSS_DATA20", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x108, "OMAP3430_reg_CONTROL_PADCONF_DSS_DATA22", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x10C, "OMAP3430_reg_CONTROL_PADCONF_CAM_HS", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x110, "OMAP3430_reg_CONTROL_PADCONF_CAM_XCLKA", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x114, "OMAP3430_reg_CONTROL_PADCONF_CAM_FLD", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x118, "OMAP3430_reg_CONTROL_PADCONF_CAM_D1", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x11C, "OMAP3430_reg_CONTROL_PADCONF_CAM_D3", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x120, "OMAP3430_reg_CONTROL_PADCONF_CAM_D5", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x124, "OMAP3430_reg_CONTROL_PADCONF_CAM_D7", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x128, "OMAP3430_reg_CONTROL_PADCONF_CAM_D9", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x12C, "OMAP3430_reg_CONTROL_PADCONF_CAM_D11", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x130, "OMAP3430_reg_CONTROL_PADCONF_CAM_WEN", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x134, "OMAP3430_reg_CONTROL_PADCONF_CSI2_DX0", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x138, "OMAP3430_reg_CONTROL_PADCONF_CSI2_DX1", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x13C, "OMAP3430_reg_CONTROL_PADCONF_MCBSP2_FSX", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x140, "OMAP3430_reg_CONTROL_PADCONF_MCBSP2_DR", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x144, "OMAP3430_reg_CONTROL_PADCONF_MMC1_CLK", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x148, "OMAP3430_reg_CONTROL_PADCONF_MMC1_DAT0", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x14C, "OMAP3430_reg_CONTROL_PADCONF_MMC1_DAT2", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x150, "OMAP3430_reg_CONTROL_PADCONF_MMC1_DAT4", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x154, "OMAP3430_reg_CONTROL_PADCONF_MMC1_DAT6", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x158, "OMAP3430_reg_CONTROL_PADCONF_MMC2_CLK", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x15C, "OMAP3430_reg_CONTROL_PADCONF_MMC2_DAT0", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x160, "OMAP3430_reg_CONTROL_PADCONF_MMC2_DAT2", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x164, "OMAP3430_reg_CONTROL_PADCONF_MMC2_DAT4", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x168, "OMAP3430_reg_CONTROL_PADCONF_MMC2_DAT6", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x16C, "OMAP3430_reg_CONTROL_PADCONF_MCBSP3_DX", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x170, "OMAP3430_reg_CONTROL_PADCONF_MCBSP3_CLKX", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x174, "OMAP3430_reg_CONTROL_PADCONF_UART2_CTS", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x178, "OMAP3430_reg_CONTROL_PADCONF_UART2_TX", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x17C, "OMAP3430_reg_CONTROL_PADCONF_UART1_TX", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x180, "OMAP3430_reg_CONTROL_PADCONF_UART1_CTS", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x184, "OMAP3430_reg_CONTROL_PADCONF_MCBSP4_CLKX", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x188, "OMAP3430_reg_CONTROL_PADCONF_MCBSP4_DX", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x18C, "OMAP3430_reg_CONTROL_PADCONF_MCBSP1_CLKR", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x190, "OMAP3430_reg_CONTROL_PADCONF_MCBSP1_DX", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x194, "OMAP3430_reg_CONTROL_PADCONF_MCBSP_CLKS", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x198, "OMAP3430_reg_CONTROL_PADCONF_MCBSP1_CLKX", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x19C, "OMAP3430_reg_CONTROL_PADCONF_UART3_RTS_SD", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1A0, "OMAP3430_reg_CONTROL_PADCONF_UART3_TX_IRTX", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1A4, "OMAP3430_reg_CONTROL_PADCONF_HSUSB0_STP", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1A8, "OMAP3430_reg_CONTROL_PADCONF_HSUSB0_NXT", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1AC, "OMAP3430_reg_CONTROL_PADCONF_HSUSB0_DATA1", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1B0, "OMAP3430_reg_CONTROL_PADCONF_HSUSB0_DATA3", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1B4, "OMAP3430_reg_CONTROL_PADCONF_HSUSB0_DATA5", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1B8, "OMAP3430_reg_CONTROL_PADCONF_HSUSB0_DATA7", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1BC, "OMAP3430_reg_CONTROL_PADCONF_I2C1_SDA", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1C0, "OMAP3430_reg_CONTROL_PADCONF_I2C2_SDA", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1C4, "OMAP3430_reg_CONTROL_PADCONF_I2C3_SDA", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1C8, "OMAP3430_reg_CONTROL_PADCONF_MCSPI1_CLK", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1CC, "OMAP3430_reg_CONTROL_PADCONF_MCSPI1_SOMI", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1D0, "OMAP3430_reg_CONTROL_PADCONF_MCSPI1_CS1", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1D4, "OMAP3430_reg_CONTROL_PADCONF_MCSPI1_CS3", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1D8, "OMAP3430_reg_CONTROL_PADCONF_MCSPI2_SIMO", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1DC, "OMAP3430_reg_CONTROL_PADCONF_MCSPI2_CS0", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1E0, "OMAP3430_reg_CONTROL_PADCONF_SYS_NIRQ", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1E4, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD0", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1E8, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD2", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1EC, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD4", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1F0, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD6", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1F4, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD8", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1F8, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD10", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x1FC, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD12", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x200, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD14", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x204, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD16", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x208, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD18", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x20C, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD20", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x210, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD22", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x214, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD24", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x218, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD26", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x21C, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD28", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x220, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD30", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x224, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD32", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x228, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD34", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x22C, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MCAD36", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x230, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_NRESPWRON", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x234, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_ARMNIRQ", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x238, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_SPINT", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x23C, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_DMAREQ0", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x240, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_DMAREQ2", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x244, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_NTRST", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x248, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_TDO", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x24C, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_TCK", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x250, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_MSTDBY", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x254, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_IDLEACK", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x258, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_SWRITE", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x25C, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_SREAD", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x260, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_SBUSFLAG", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x264, "OMAP3430_reg_CONTROL_PADCONF_SDRC_CKE1", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x5D8, "OMAP3430_reg_CONTROL_PADCONF_ETK_CLK", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x5DC, "OMAP3430_reg_CONTROL_PADCONF_ETK_D0", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x5E0, "OMAP3430_reg_CONTROL_PADCONF_ETK_D2", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x5E4, "OMAP3430_reg_CONTROL_PADCONF_ETK_D4", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x5E8, "OMAP3430_reg_CONTROL_PADCONF_ETK_D6", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x5EC, "OMAP3430_reg_CONTROL_PADCONF_ETK_D8", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x5F0, "OMAP3430_reg_CONTROL_PADCONF_ETK_D10", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x5F4, "OMAP3430_reg_CONTROL_PADCONF_ETK_D12", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x5F8, "OMAP3430_reg_CONTROL_PADCONF_ETK_D14", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x270, "OMAP3430_reg_CONTROL_PADCONF_OFF", "Off mode pad configuration register");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x274, "OMAP3430_reg_CONTROL_DEVCONF0", "Static device configuration register-0. Module dedicated functions");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x278, "OMAP3430_reg_CONTROL_RESERVED_0", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x27C, "OMAP3430_reg_CONTROL_RESERVED_1", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x290, "OMAP3430_reg_CONTROL_MSUSPENDMUX_0", "MSuspend Control register: control the use of MSuspend signals at module level");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x294, "OMAP3430_reg_CONTROL_MSUSPENDMUX_1", "MSuspend Control register: control the use of MSuspend signals at module level");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x298, "OMAP3430_reg_CONTROL_MSUSPENDMUX_2", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x29C, "OMAP3430_reg_CONTROL_MSUSPENDMUX_3", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x2A0, "OMAP3430_reg_CONTROL_MSUSPENDMUX_4", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x2A4, "OMAP3430_reg_CONTROL_MSUSPENDMUX_5", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x2B0, "OMAP3430_reg_CONTROL_PROT_CTRL", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x2D8, "OMAP3430_reg_CONTROL_DEVCONF1", "Static device configuration register-1, Module dedicated functions");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x2DC, "OMAP3430_reg_CONTROL_CSIRXFE", "This register makes possible to control some settings of CSIRXFE cells used in the design");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x2E4, "OMAP3430_reg_CONTROL_PROT_ERR_STATUS", "Protection Error Status Register");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x2E8, "OMAP3430_reg_CONTROL_PROT_ERR_STATUS_DEBUG", "Protection Error Status Debug Register");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x2F0, "OMAP3430_reg_CONTROL_STATUS", "Control Module Status register: latches system information at reset time");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x2F4, "OMAP3430_reg_CONTROL_GENERAL_PURPOSE_STATUS", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x300, "OMAP3430_reg_CONTROL_RPUB_KEY_H_0", "Root public key hash; B-field");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x304, "OMAP3430_reg_CONTROL_RPUB_KEY_H_1", "Root public key hash; B-field");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x308, "OMAP3430_reg_CONTROL_RPUB_KEY_H_2", "Root public key hash; B-field");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x30C, "OMAP3430_reg_CONTROL_RPUB_KEY_H_3", "Root public key hash; B-field");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x310, "OMAP3430_reg_CONTROL_RPUB_KEY_H_4", "Root public key hash; B-field");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x370, "OMAP3430_reg_CONTROL_USB_CONF_0", "USB Fuse conf [31:0], USB Product ID [31:16], Vendor ID [15:0]");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x374, "OMAP3430_reg_CONTROL_USB_CONF_1", "USB Fuse conf 1, SEQ_DISADAPTCLK[1], USB PHY detection mode [0]");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x380, "OMAP3430_reg_CONTROL_FUSE_OPP1_VDD1", "Standard Fuse OPP1 VDD1");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x384, "OMAP3430_reg_CONTROL_FUSE_OPP2_VDD1", "Standard Fuse OPP2 VDD1");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x388, "OMAP3430_reg_CONTROL_FUSE_OPP3_VDD1", "Standard Fuse OPP3 VDD1");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x38C, "OMAP3430_reg_CONTROL_FUSE_OPP4_VDD1", "Standard Fuse OPP4 VDD1");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x390, "OMAP3430_reg_CONTROL_FUSE_OPP5_VDD1", "Standard Fuse OPP5 VDD1");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x394, "OMAP3430_reg_CONTROL_FUSE_OPP1_VDD2", "Standard Fuse OPP1 VDD2");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x398, "OMAP3430_reg_CONTROL_FUSE_OPP2_VDD2", "Standard Fuse OPP2 VDD2");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x39C, "OMAP3430_reg_CONTROL_FUSE_OPP3_VDD2", "Standard Fuse OPP3 VDD2");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x3A0, "OMAP3430_reg_CONTROL_RESERVED_3", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x400, "OMAP3430_reg_CONTROL_IVA2_BOOTADDR", "This register defines the physical address of the IVA2 boot loader");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x404, "OMAP3430_reg_CONTROL_IVA2_BOOTMOD", "This register defines the IVA2 bootmode");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x420, "OMAP3430_reg_CONTROL_DEBOBS_0", "Select the set of signals to be observed for hw_dbg0, hw_dbg1");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x424, "OMAP3430_reg_CONTROL_DEBOBS_1", "Select the set of signals to be observed for hw_dbg2, hw_dbg3");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x428, "OMAP3430_reg_CONTROL_DEBOBS_2", "Select the set of signals to be observed for hw_dbg4, hw_dbg5");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x42C, "OMAP3430_reg_CONTROL_DEBOBS_3", "Select the set of signals to be observed for hw_dbg6, hw_dbg7");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x430, "OMAP3430_reg_CONTROL_DEBOBS_4", "Select the set of signals to be observed for hw_dbg8, hw_dbg9");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x434, "OMAP3430_reg_CONTROL_DEBOBS_5", "Select the set of signals to be observed for hw_dbg10, hw_dbg11");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x438, "OMAP3430_reg_CONTROL_DEBOBS_6", "Select the set of signals to be observed for hw_dbg12, hw_dbg13");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x43C, "OMAP3430_reg_CONTROL_DEBOBS_7", "Select the set of signals to be observed for hw_dbg14, hw_dbg15");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x440, "OMAP3430_reg_CONTROL_DEBOBS_8", "Select the set of signals to be observed for hw_dbg16, hw_dbg17");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x444, "OMAP3430_reg_CONTROL_PROG_IO0", "Configure drive strength of I/O cells");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x448, "OMAP3430_reg_CONTROL_PROG_IO1", "Configure drive strength of I/O cells");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x450, "OMAP3430_reg_CONTROL_DSS_DPLL_SPREADING", "This register controls the EMI Reduction feature for Display_SS/DSI DPLL");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x454, "OMAP3430_reg_CONTROL_CORE_DPLL_SPREADING", "This register controls the EMI Reduction feature for CORE domain DPLL");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x458, "OMAP3430_reg_CONTROL_PER_DPLL_SPREADING", "This register controls the EMI Reduction feature for PER domain DPLL");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x45C, "OMAP3430_reg_CONTROL_USBHOST_DPLL_SPREADING", "This register controls the EMI Reduction feature for USBHOST domain DPLL");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x460, "OMAP3430_reg_CONTROL_SDRC_SHARING", "SDRC Sharing configuration register");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x464, "OMAP3430_reg_CONTROL_SDRC_MCFG0", "SDRC MCFG Configuration register-0");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x468, "OMAP3430_reg_CONTROL_SDRC_MCFG1", "SDRC MCFG Configuration register-1");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x46C, "OMAP3430_reg_CONTROL_MODEM_FW_CONFIGURATION_LOCK", "Allows locking of the modem isolation registers in the SCM until the next battery removal");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x470, "OMAP3430_reg_CONTROL_MODEM_MEMORY_RESOURCES_CONF", "Modem Memory Resources configuration");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x474, "OMAP3430_reg_CONTROL_MODEM_GPMC_DT_FW_REQ_INFO", "Modem GPMC Default firewall request info register");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x478, "OMAP3430_reg_CONTROL_MODEM_GPMC_DT_FW_RD", "Modem GPMC Default firewall read permission register");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x47C, "OMAP3430_reg_CONTROL_MODEM_GPMC_DT_FW_WR", "Modem GPMC Default firewall write permission register");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x480, "OMAP3430_reg_CONTROL_MODEM_GPMC_BOOT_CODE", "GPMC Flash Boot Code protection register");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x484, "OMAP3430_reg_CONTROL_MODEM_SMS_RG_ATT1", "Modem SMS Default firewall register");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x488, "OMAP3430_reg_CONTROL_MODEM_SMS_RG_RDPERM1", "Modem SMS Default firewall read permission register");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x48C, "OMAP3430_reg_CONTROL_MODEM_SMS_RG_WRPERM1", "Modem SMS Default firewall write permission register");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x490, "OMAP3430_reg_CONTROL_MODEM_D2D_FW_DEBUG_MODE", "D2D firewall debug mode register");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x498, "OMAP3430_reg_CONTROL_DPF_OCM_RAM_FW_ADDR_MATCH", "OCM RAM Dynamic Power Framework Handling");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x49C, "OMAP3430_reg_CONTROL_DPF_OCM_RAM_FW_REQINFO", "OCM RAM Dynamic Power Framework Handling");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x4A0, "OMAP3430_reg_CONTROL_DPF_OCM_RAM_FW_WR", "OCM RAM Dynamic Power Framework Handling");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x4A4, "OMAP3430_reg_CONTROL_DPF_REGION4_GPMC_FW_ADDR_MATCH", "GPMC Dynamic Power Framework Handling");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x4A8, "OMAP3430_reg_CONTROL_DPF_REGION4_GPMC_FW_REQINFO", "GPMC Dynamic Power Framework Handling");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x4AC, "OMAP3430_reg_CONTROL_DPF_REGION4_GPMC_FW_WR", "GPMC Dynamic Power Framework Handling");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x4B0, "OMAP3430_reg_CONTROL_DPF_REGION1_IVA2_FW_ADDR_MATCH", "IVA2 Dynamic Power Framework Handling");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x4B4, "OMAP3430_reg_CONTROL_DPF_REGION1_IVA2_FW_REQINFO", "IVA2 Dynamic Power Framework Handling");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x4B8, "OMAP3430_reg_CONTROL_DPF_REGION1_IVA2_FW_WR", "IVA2 Dynamic Power Framework Handling");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x538, "OMAP3430_reg_CONTROL_DPF_MAD2D_FW_ADDR_MATCH", "MAD2D Dynamic Power Framework Handling");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x53C, "OMAP3430_reg_CONTROL_DPF_MAD2D_FW_REQINFO", "MAD2D Dynamic Power Framework Handling");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x540, "OMAP3430_reg_CONTROL_DPF_MAD2D_FW_WR", "MAD2D Dynamic Power Framework Handling");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x520, "OMAP3430_reg_CONTROL_PBIAS_LITE", "This register controls the settings for PBIAS LITE MMC/SD/SDIO1 pins");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x524, "OMAP3430_reg_CONTROL_TEMP_SENSOR", "Temperature Sensor register");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x530, "OMAP3430_reg_CONTROL_CSI", "Controls CSIb receiver trimming setting");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0x9FC, "OMAP3430_reg_CONTROL_SAVE_RESTORE_MEM", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA00, "OMAP3430_reg_CONTROL_PADCONF_I2C4_SCL", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA04, "OMAP3430_reg_CONTROL_PADCONF_SYS_32K", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA08, "OMAP3430_reg_CONTROL_PADCONF_SYS_NRESWARM", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA0C, "OMAP3430_reg_CONTROL_PADCONF_SYS_BOOT1", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA10, "OMAP3430_reg_CONTROL_PADCONF_SYS_BOOT3", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA14, "OMAP3430_reg_CONTROL_PADCONF_SYS_BOOT5", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA18, "OMAP3430_reg_CONTROL_PADCONF_SYS_OFF_MODE", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA1C, "OMAP3430_reg_CONTROL_PADCONF_JTAG_NTRST", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA20, "OMAP3430_reg_CONTROL_PADCONF_JTAG_TMS_TMSC", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA24, "OMAP3430_reg_CONTROL_PADCONF_JTAG_EMU0", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA4C, "OMAP3430_reg_CONTROL_PADCONF_SAD2D_SWAKEUP", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA50, "OMAP3430_reg_CONTROL_PADCONF_JTAG_TDO", "");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA5C, "OMAP3430_reg_CONTROL_WKUP_CTRL", "USB TXEN polarity control and log modem warm reset source mux sel");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA68, "OMAP3430_reg_CONTROL_WKUP_DEBOBS_0", "Select the WKUP domain set of signals to be observed for hw_dbg3, hw_dbg2, hw_dbg1, hw_dbg0");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA6C, "OMAP3430_reg_CONTROL_WKUP_DEBOBS_1", "Select the WKUP domain set of signals to be observed for hw_dbg7, hw_dbg6, hw_dbg5, hw_dbg4");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA70, "OMAP3430_reg_CONTROL_WKUP_DEBOBS_2", "Select the WKUP domain set of signals to be observed for hw_dbg11, hw_dbg10, hw_dbg9, hw_dbg8");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA74, "OMAP3430_reg_CONTROL_WKUP_DEBOBS_3", "Select the WKUP domain set of signals to be observed for hw_dbg15, hw_dbg14, hw_dbg13, hw_dbg12");
	CreateDwordRegister(OMAP3430_SCM_BASE, 0xA78, "OMAP3430_reg_CONTROL_WKUP_DEBOBS_4", "Select the WKUP domain set of signals to be observed for hw_dbg17, hw_dbg16");
	Message("Added OMAP3430 System Control Module registers\n");
}

// --- Clock Manager Module
static CM_Module(void)
{
	if (!SegCreate(OMAP3430_CM_REG_A_BASE, OMAP3430_CM_REG_A_END, 0x0, 1, 0, 0)) {
		Warning("Can't create Clock Manager Module registers segment!\n");
		return;
	}
	SegRename(OMAP3430_CM_REG_A_BASE, "CM");
	SegClass(OMAP3430_CM_REG_A_BASE, "REGISTERS");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x0, "OMAP3430_reg_CM_FCLKEN_IVA2", "This register controls the IVA2 domain functional clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x4, "OMAP3430_reg_CM_CLKEN_PLL_IVA2", "This register controls the IVA2 DPLL modes");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x20, "OMAP3430_reg_CM_IDLEST_IVA2", "IVA2 standby status and access availability monitoring. This register is read only and automatically updated");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x24, "OMAP3430_reg_CM_IDLEST_PLL_IVA2", "This register allows monitoring the master clock activiry. This register is read only and automatically updated");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x34, "OMAP3430_reg_CM_AUTOIDLE_PLL_IVA2", "This register provides automatic control over the IVA2 DPLL activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x40, "OMAP3430_reg_CM_CLKSEL1_PLL_IVA2", "This register provides controls over the IVA2 DPLL");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x44, "OMAP3430_reg_CM_CLKSEL2_PLL_IVA2", "This register provides controls over the IVA2 DPLL");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x48, "OMAP3430_reg_CM_CLKSTCTRL_IVA2", "This register enables the domain power state transition. It controls the HW supervised domain power state transition between ACTIVE and INACTIVE states");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x4C, "OMAP3430_reg_CM_CLKSTST_IVA2", "This register provides a status on the clock activity in the domain (IVA2 DPLL output clock)");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x800, "OMAP3430_reg_CM_REVISION", "This register contains the IP revision code for the CM part of the PRCM");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x810, "OMAP3430_reg_CM_SYSCONFIG", "This register controls the various parameters of the interface clock");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x904, "OMAP3430_reg_CM_CLKEN_PLL_MPU", "This register controls the DPLL1 modes");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x920, "OMAP3430_reg_CM_IDLEST_MPU", "Modules access availability monitoring. This register is read only and automatically updated");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x924, "OMAP3430_reg_CM_IDLEST_PLL_MPU", "This register allows monitoring the master clock activity. This register is read only and automatically updated");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x934, "OMAP3430_reg_CM_AUTOIDLE_PLL_MPU", "This register provides automatic control over the DPLL1 activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x940, "OMAP3430_reg_CM_CLKSEL1_PLL_MPU", "This register provides controls over the MPU DPLL");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x944, "OMAP3430_reg_CM_CLKSEL2_PLL_MPU", "This register provides controls over the MPU DPLL");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x948, "OMAP3430_reg_CM_CLKSTCTRL_MPU", "This register enables the domain power state transition. It controls the HW supervised domain power state transition betweeen ACTIVE and INACTIVE states");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x94C, "OMAP3430_reg_CM_CLKSTST_MPU", "This register provides a status on the clock activity in the domain (MPU DPLL output clock)");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xA00, "OMAP3430_reg_CM_FCLKEN1_CORE", "Controls the module functional clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xA08, "OMAP3430_reg_CM_FCLKEN3_CORE", "Controls the module functional clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xA10, "OMAP3430_reg_CM_ICLKEN1_CORE", "Controls the modules interface clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xA18, "OMAP3430_reg_CM_ICLKEN3_CORE", "Controls the modules interface clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xA20, "OMAP3430_reg_CM_IDLEST1_CORE", "CORE modules access availability monitoring. This register read only and automatically updated");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xA28, "OMAP3430_reg_CM_IDLEST3_CORE", "CORE modules access availability monitoring. This register read only and automatically updated");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xA30, "OMAP3430_reg_CM_AUTOIDLE1_CORE", "This register controls the automatic control of the CORE modules interface clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xA38, "OMAP3430_reg_CM_AUTOIDLE3_CORE", "This register controls the automatic control of the CORE modules interface clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xA40, "OMAP3430_reg_CM_CLKSEL_CORE", "CORE modules clock selection");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xA48, "OMAP3430_reg_CM_CLKSTCTRL_CORE", "This register enables the domain power state transition. It controls the HW supervised domain power state transition between ACTIVE and INACTIVE states");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xA4C, "OMAP3430_reg_CM_CLKSTST_CORE", "This register provides a status on the interface clock activity in the domain");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xB00, "OMAP3430_reg_CM_FCLKEN_SGX", "Controls the Graphic engine functional clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xB10, "OMAP3430_reg_CM_ICLKEN_SGX", "Controls the Graphic engine interface clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xB20, "OMAP3430_reg_CM_IDLEST_SGX", "SGX standby status. This register is read only and automatically updated");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xB40, "OMAP3430_reg_CM_CLKSEL_SGX", "SGX clock selection");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xB44, "OMAP3430_reg_CM_SLEEPDEP_SGX", "This register allows enabling or disabling the sleep transition dependency of SGX domain with respect to other domain");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xB48, "OMAP3430_reg_CM_CLKSTCTRL_SGX", "This register enables the domain power state transition. It controls the HW supervised domain power state transition between ACTIVE and INACTIVE states");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xB4C, "OMAP3430_reg_CM_CLKSTST_SGX", "This register provides a status on the interface clock activity in the domain");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xC00, "OMAP3430_reg_CM_FCLKEN_WKUP", "Controls the modules functional clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xC10, "OMAP3430_reg_CM_ICLKEN_WKUP", "Controls the modules interface clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xC20, "OMAP3430_reg_CM_IDLEST_WKUP", "WAKEUP domain modules access monitoring. This register is read only and automatically updated");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xC30, "OMAP3430_reg_CM_AUTOIDLE_WKUP", "This register controls the automatic control of the WAKEUP modules interface clock activity. This activity is related to CORE domain activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xC40, "OMAP3430_reg_CM_CLKSEL_WKUP", "WAKEUP domain modules source clock selection");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xD00, "OMAP3430_reg_CM_CLKEN_PLL", "This register allows controlling the DPLL3 and DPLL4 modes");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xD04, "OMAP3430_reg_CM_CLKEN2_PLL", "This register controls the DPLL5 modes");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xD20, "OMAP3430_reg_CM_IDLEST_CKGEN", "This register allows monitoring the master clock activity. This register is read only and automatically updated");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xD24, "OMAP3430_reg_CM_IDLEST2_CKGEN", "This register allows monitoring the master clock activity. This register is read only and automatically updated");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xD30, "OMAP3430_reg_CM_AUTOIDLE_PLL", "This register provides automatic control over the DPLL3 and DPLL4 activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xD34, "OMAP3430_reg_CM_AUTOIDEL2_PLL", "This register provides automatic control over the DPLL5 activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xD40, "OMAP3430_reg_CM_CLKSEL1_PLL", "This register controls the selection of the master clock frequencies");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xD44, "OMAP3430_reg_CM_CLKSEL2_PLL", "This register controls the selection of the master clock frequencies");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xD48, "OMAP3430_reg_CM_CLKSEL3_PLL", "This register controls the selection of the master clock frequencies");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xD4C, "OMAP3430_reg_CM_CLKSEL4_PLL", "This register controls the selection of the master clock frequencies");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xD50, "OMAP3430_reg_CM_CLKSEL5_PLL", "This register controls the selection of the master clock frequencies");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xD70, "OMAP3430_reg_CM_CLKOUT_CTRL", "This register provides control over the SYS_CLKOUT2 output clock");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xE00, "OMAP3430_reg_CM_FCLKEN_DSS", "Controls the modules functional clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xE10, "OMAP3430_reg_CM_ICLKEN_DSS", "Controls the modules interface clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xE20, "OMAP3430_reg_CM_IDLEST_DSS", "Module access availability monitoring. This register is read only and automatically updated");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xE30, "OMAP3430_reg_CM_AUTOIDLE_DSS", "This register controls the automatic control of the modules interface clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xE40, "OMAP3430_reg_CM_CLKSEL_DSS", "Modules clock selection");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xE44, "OMAP3430_reg_CM_SLEEPDEP_DSS", "This register allows enebling or disabling the sleep transition dependency of DSS domain with respect to other domain");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xE48, "OMAP3430_reg_CM_CLKSTCTRL_DSS", "This register enables the domain power state transition. It controls the HW supervised domain power state transition between ACTIVE and INACTIVE states");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xE4C, "OMAP3430_reg_CM_CLKSTST_DSS", "This register provides a status on the OCP interface clock activity in the domain");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xF00, "OMAP3430_reg_CM_FCLKEN_CAM", "Controls the modules functional clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xF10, "OMAP3430_reg_CM_ICLKEN_CAM", "Controls the modules interface clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xF20, "OMAP3403_reg_CM_IDLEST_CAM", "Modules access availability monitoring. This register is read only and automatically updated");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xF30, "OMAP3430_reg_CM_AUTOIDLE_CAM", "This register controls the automatic control of the modules interface clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xF40, "OMAP3430_reg_CM_CLKSEL_CAM", "CAM module clock selection");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xF44, "OMAP3430_reg_CM_SLEEPDEP_CAM", "This register allows enabling or disabling the sleep transition dependency of CAM domain with respect to other domain");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xF48, "OMAP3430_reg_CM_CLKSTCTRL_CAM", "This register allows to enable or disable SW and HW supervised transition between ACTIVE and INACTIVE states");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0xF4C, "OMAP3430_reg_CM_CLKSTST_CAM", "This register provides a status on the OCP interface clock activity in the domain");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1000, "OMAP3430_reg_CM_FCLKEN_PER", "Controls the modules functional clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1010, "OMAP3430_reg_CM_ICLKEN_PER", "Controls the modules interface clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1020, "OMAP3430_reg_CM_IDLEST_PER", "Modules access availability monitoring. This register is read only and automatically updated");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1030, "OMAP3430_reg_CM_AUTOIDLE_PER", "This register controls the automatic control of the modules interface clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1040, "OMAP3430_reg_CM_CLKSEL_PER", "PER domain modules source clock selection");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1044, "OMAP3430_reg_CM_SLEEPDEP_PER", "This register allows enebling or disabling the sleep transition dependency of PER domain with respect to other domain");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1048, "OMAP3430_reg_CM_CLKSTCTRL_PER", "This register enables the domain power state transition. It controls the HW supervised domain power state transition between ACTIVE and INACTIVE states");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x104C, "OMAP3430_reg_CM_CLKSTST_PER", "This register provides a status on the OCP interface clock activity in the domain");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1140, "OMAP3430_reg_CM_CLKSEL1_EMU", "Modules clock selection");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1148, "OMAP3430_reg_CM_CLKSTCTRL_EMU", "This register allows to enable or disable SW and HW supervised trasition between ACTIVE and INACTIVE states");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x114C, "OMAP3430_reg_CM_CLKSTST_EMU", "This register provides a status on the clock activity in the domain (dpends on the selected source clock)");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1150, "OMAP3430_reg_CM_CLKSEL2_EMU", "This register provides override controls over the DPLL3");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1154, "OMAP3430_reg_CM_CLKSEL3_EMU", "This register provides override controls over the PERIPHERAL DPLL");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x129C, "OMAP3430_reg_CM_POLCTRL", "This register allows setting the polarity of device outputs control signals");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1320, "OMAP3430_reg_CM_IDLEST_NEON", "Modules access availability monitoring. This register is read only and automatically updated");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1348, "OMAP3430_reg_CM_CLKSTCTRL_NEON", "This register enables the domain power state transition. It controls the HW supervised domain power state transition between ACTIVE and INACTIVE states");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1400, "OMAP3430_reg_CM_FCLKEN_USBHOST", "Controls the modules functional clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1410, "OMAP3430_reg_CM_ICLKEN_USBHOST", "Controls the modules interface clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1420, "OMAP3430_reg_CM_IDLEST_USBHOST", "Modules access availability monitoring. This register is read only and automatically updated");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1430, "OMAP3430_reg_CM_AUTOIDLE_USBHOST", "This register controls the automatic control of the modules interface clock activity");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1444, "OMAP3430_reg_CM_SLEEPDEP_USBHOST", "This register allows enabling or disabling the sleep transition dependency of USB HOST domain with respect to other domain");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x1448, "OMAP3430_reg_CM_CLKSTCTRL_USBHOST", "This register enables the domain power state transition. It controls the HW supervised domain power state transition between ACTIVE and INACTIVE states");
	CreateDwordRegister(OMAP3430_CM_REG_A_BASE, 0x144C, "OMAP3430_reg_CM_CLKSTST_USBHOST", "This register provides a status on the interface clock activity in the domain");
	Message("Added OMAP3430 CM Module registers\n");
}

// --- PRM Module
static PRM_Module(void)
{
	if (!SegCreate(OMAP3430_PRM_BASE, OMAP3430_PRM_END, 0x0, 1, 0 , 0)) {
		Warning("Can't create PRM registers segment!\n");
		return;
	}
	SegRename(OMAP3430_PRM_BASE, "PRM");
	SegClass(OMAP3430_PRM_BASE, "REGISTERS");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x50, "OMAP3430_reg_RM_RSTCTRL_IVA2", "This register controls the release of the IVA2 sub-system resets");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x58, "OMAP3430_reg_RM_RSTST_IVA2", "This register logs the different reset sources of the IVA2 domain. Each bit is set upon release of the domain reset signal. Must be cleared by software");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xC8, "OMAP3430_reg_PM_WKDEP_IVA2", "This register allows enabling or disabling the wake-up of the IVA2 domain upon another domain wakeup events");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xE0, "OMAP3430_reg_PM_PWSTCTRL_IVA2", "This register controls the IVA2 domain power state transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xE4, "OMAP3430_reg_PM_PWSTST_IVA2", "This register provides a status on the power state transition of the IVA2 domain");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xE8, "OMAP3430_reg_PM_PREPWSTST_IVA2", "This register provides a status on the IVA2 domain previous power state. It indicates the state entered during the last sleep transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xF8, "OMAP3430_reg_PRM_IRQSTATUS_IVA2", "This interrupt status register regroups all the status of the module internal events that can generate an interrupt. Write1 to a given bit resets this bit. This register applies on the interrupt line 1 mapped to the IVA2 interrupt controller");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xFC, "OMAP3430_reg_PRM_IRQENABLE_IVA2", "This interrupt enable register allows masking/unmasking the module internal sources of interrupt, on a event-by-event basis. This register applies on the interrupt line 0 mapped to the IVA2 Wake-Up Generator");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x804, "OMAP3430_reg_PRM_REVISION", "This register contains the IP revision code for the PRM part of the PRCM");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x814, "OMAP3430_reg_PRM_SYSCONFIG", "This register controls the various parameters of the interface");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x818, "OMAP3430_reg_PRM_IRQSTATUS_MPU", "This interrupt status register regroups all the status of the module internal events that can generate an interrupt. Write 1 to a given bit resets this bit. This registers applies on the interrupt line 0 mapped to the MPU interrupt controller");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x81C, "OMAP3430_reg_PRM_IRQENABLE_MPU", "The interrupt enable register allows masking/unmasking the module internal sources of interrupt, on a event-by-event basis. This register applies on the interrupt line 0 mapped to the MPU interrupt controller");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x958, "OMAP3430_reg_RM_RSTST_MPU", "This register logs the different reset sources of the MPU domain. Each bit is set upon release of the domain reset signal. Must be cleared by software");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x9C8, "OMAP3430_reg_PM_WKDEP_MPU", "This register allows enabling or disabling the wake-up of the MPU domain upon another domain wakeup events");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x9D4, "OMAP3430_reg_PM_EVGENCTRL_MPU", "This register allows controlling the feature of the event generator");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x9D8, "OMAP3430_reg_PM_EVGENONTIM_MPU", "This register sets the ON count duration of the event generator (number of system clock cycles)");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x9DC, "OMAP3430_reg_PM_EVGENOFFTIM_MPU", "This register sets the OFF count duration of the event generator (number of system clock cycles)");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x9E0, "OMAP3430_reg_PM_PWSTCTRL_MPU", "This register controls the MPU domain power state transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x9E4, "OMAP3430_reg_PM_PWSTST_MPU", "This register provides a status on the MPU domain power state");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x9E8, "OMAP3430_reg_PM_PREPWSTST_MPU", "This register provides a status on the MPU domain previous power state. It indicates the state entered during the last sleep transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xA58, "OMAP3430_reg_RM_RSTST_CORE", "This register logs the different reset sources of the CORE domain. Each bit is set upon release of thee domain reset signal. Must be cleared by software");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xAA0, "OMAP3430_reg_PM_WKEN1_CORE", "This register allows enabling/disabling modules wake-up events");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xAA4, "OMAP3430_reg_PM_MPUGRPSEL1_CORE", "This register allows selecting the group of modules that wake-up the MPU");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xAA8, "OMAP3430_reg_PM_IVA2GRPSEL1_CORE", "This register allows selecting the group of modules that wake-up the IVA2");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xAB0, "OMAP3430_reg_PM_WKST1_CORE", "This register logs module wake-up events. Must be cleared by software. If it is not cleared, it prevents further domain transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xAB8, "OMAP3430_reg_PM_WKST3_CORE", "This register logs module wake-up events. Must be cleared by software. If it is not cleared, it prevents further domain transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xAE0, "OMAP3430_reg_PM_PWSTCTRL_CORE", "This register controls the CORE domain power state transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xAE4, "OMAP3430_reg_PM_PWSTST_CORE", "This register provides a status on the power state transition of the CORE domain");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xAE8, "OMAP3430_reg_PM_PREPWSTST_CORE", "This register provides a status on the CORE domain previous power state. It indicates the state entered during the last sleep transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xAF0, "OMAP3430_reg_PM_WKEN3_CORE", "This register allows enabling/disabling modules wake-up events");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xAF4, "OMAP3430_reg_PM_IVA2GRPSEL3_CORE", "This register allows selecting the group of modules that wake-up the IVA2");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xAF8, "OMAP3430_reg_PM_MPUGRPSEL3_CORE", "This register allows selecting the group of modules that wake-up the MPU");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xB58, "OMAP3430_reg_RM_RSTST_SGX", "This register logs the different reset sources of the SGX domain. Each bit is set upon release of the domain reset signal. Must be cleared by software");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xBC8, "OMAP3430_reg_PM_WKDEP_SGX", "This register allows enabling or disabling the wake-up of the SGX domain upon another domain wakeup");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xBE0, "OMAP3430_reg_PM_PWSTCTRL_SGX", "This register controls the SGX domain power state transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xBE4, "OMAP3430_reg_PM_PWSTST_SGX", "This register provides a status on the power state transition of the SGX domain");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xBE8, "OMAP3430_reg_PM_PREPWSTST_SGX", "This register provides a status on the SGX domain previous power state. It indicates the state entered during the last sleep transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xCA0, "OMAP3430_reg_PM_WKEN_WKUP", "This register allows enabling/disabling modules wake-up events");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xCA4, "OMAP3430_reg_PM_MPUGRPSEL_WKUP", "IO pad is always selected in the MPU wake-up events group");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xCA8, "OMAP3430_reg_PM_IVA2GRPSEL_WKUP", "This register allows selecting the group of modules that wake-up the IVA2");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xCB0, "OMAP3430_reg_PM_WKST_WKUP", "This register logs module wake-up events. Must be cleared by software. If it is not cleared, it prevents further domain transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xD40, "OMAP3430_reg_PRM_CLKSEL", "This register controls the selection of the system clock frequency. This register is reset on power-up only");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xD70, "OMAP3430_reg_PRM_CLKOUT_CTRL", "This register provides control over the SYS_CLKOUT1 output clock");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xE58, "OMAP3430_reg_RM_RSTST_DSS", "This register logs the different reset sources of the DSS domain. Each bit is set upon release of the domain reset signal. Must be cleared by software");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xEA0, "OMAP3430_reg_PM_WKEN_DSS", "This register allows enabling/disabling modules wake-up events");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xEC8, "OMAP3430_reg_PM_WKDEP_DSS", "This register allows enabling or disabling the wake-up of the DISPLAY domain upon another domain wakeup");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xEE0, "OMAP3430_reg_PM_PWSTCTRL_DSS", "This register controls the DISPLAY domain power state transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xEE4, "OMAP3430_reg_PM_PWSTST_DSS", "This register provides a status on the power state transition of the DSS domain");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xEE8, "OMAP3430_reg_PM_PREPWSTST_DSS", "This register provides a status on the DSS domain previous power state. It indicates the state entered during the last sleep transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xF58, "OMAP3430_reg_RM_RSTST_CAM", "This register logs the different reset sources of the CAMERA domain. Each bit is set upon release of the domain reset signal. Must be cleared by software");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xFC8, "OMAP3430_reg_PM_WKDEP_CAM", "This register allows enabling or disabling the wake-up of the CAM domain upon another domain");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xFE0, "OMAP3430_reg_PM_PWSTCTRL_CAM", "This register controls the CAM domain power state transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xFE4, "OMAP3430_reg_PM_PWSTST_CAM", "This register provides a status on the power state transition of the CAMERA domain");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0xFE8, "OMAP3430_reg_PM_PREPWSTST_CAM", "This register provides a status on the CAM domain previous power state. It indicates the state entered during the last sleep transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1058, "OMAP3430_reg_RM_RSTST_PER", "This register logs the different reset sources of the PERIPHERAL domain. Each bit is set upon release of the domain reset signal. Must be cleared by software");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x10A0, "OMAP3430_reg_PM_WKEN_PER", "This register allows enabling/disabling modules wake-up events");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x10A4, "OMAP3430_reg_PM_MPUGRPSEL_PER", "This register allows selecting the group of modules that wake-up the MPU");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x10A8, "OMAP3430_reg_PM_IVA2GRPSEL_PER", "This register allows selecting the group of modules that wake-up the IVA2");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x10B0, "OMAP3430_reg_PM_WKST_PER", "This register logs module wake-up events. Must be cleared by software. If it is not cleared, it prevents further domain transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x10C8, "OMAP3430_reg_PM_WKDEP_PER", "This register allows enabling or disabling the wake-up of the PER domain upon another domain wakeup events");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x10E0, "OMAP3430_reg_PM_PWSTCTRL_PER", "This register controls the PER domain power state transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x10E4, "OMAP3430_reg_PM_PWSTST_PER", "This register provides a status on the power state transition of the PERIPHERAL domain");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x10E8, "OMAP3430_reg_PM_PREPWSTST_PER", "This register provides a status on the PER domain previous power state. It indicates the state entered during the last sleep transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1158, "OMAP3430_reg_RM_RSTST_EMU", "This register logs the different reset sources of the EMU domain. Each bit is set upon release of the domain reset signal. Must be cleared by software");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x11E4, "OMAP3430_reg_PM_PWSTST_EMU", "This register provides a status on the power state transition of the EMULATION domain");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1220, "OMAP3430_reg_PRM_VC_SMPS_SA", "This register allows the setting of the I2C slave address of the Power IC device");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1224, "OMAP3430_reg_PRM_VC_SMPS_VOL_RA", "This register allows the setting of the voltage configuration register address for the VDD channels");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1228, "OMAP3430_reg_PRM_VC_SMPS_CMD_RA", "This register allows the setting of the ON/Retention/OFF command configuration register address for the VDD channels. It is used if the Power IC device has different register addresses for voltage value and ON/Retention/OFF command");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x122C, "OMAP3430_reg_PRM_VC_CMD_VAL_0", "This register allows the setting of the ON/Retention/OFF voltage level values for the first VDD channel");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1230, "OMAP3430_reg_PRM_VC_CMD_VAL_1", "This register allows the setting of the ON/Retention/OFF voltage level values for the second VDD channel. It is used of the second channel has different values than the first channel");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1234, "OMAP3430_reg_PRM_VC_CH_CONF", "This register allows the configuration pointers for both VDD channels");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1238, "OMAP3430_reg_PRM_VC_I2C_CFG", "This register allows the configuration pointers for both VDD channels");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x123C, "OMAP3430_reg_PRM_VC_BYPASS_VAL", "This register allows the programming of the Power IC device using the bypass interface");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1250, "OMAP3430_reg_PRM_RSTCTRL", "Global software and DPLL3 reset control. This register is auto-cleared/ Only write 1 is possible. A read returns 0 only");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1254, "OMAP3430_reg_PRM_RSTTIME", "Reset duration control");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1258, "OMAP3430_reg_PRM_RSTST", "This register logs the global reset sources. Each bit is set upon release of the domain reset signal. Must be cleared by software");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1260, "OMAP3430_reg_PRM_VOLTCTRL", "This register allows a direct control on the external power IC");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1264, "OMAP3430_reg_PRM_SRAM_PCHARGE", "This register allows setting the pre-charge time of the SRAM");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1270, "OMAP3430_reg_PRM_CLKSRC_CTRL", "This register provides control over the device source clock");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1280, "OMAP3430_reg_PRM_OBS", "This register logs the observable signals (18 bits). This register is inteded to be read through the debugger interface when the device is in OFF mode");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1290, "OMAP3430_reg_PRM_VOLTSETUP1", "This register allows setting the setup time of the VDD1 and VDD2 regulators. This register is used when exiting off/retention/sleep mode (or entering off/retention/sleep mode) and when OMAP manages the sequencing of the voltages regulation steps");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1294, "OMAP3430_reg_PRM_VOLTOFFSET", "This register allows controlling the sys_offmode signal upon wake-up from OFF mode when the OFF sequence is supervised by the Power IC. This register allows setting the offset-time to de-assert sys_offmode when exiting the OFF mode");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1298, "OMAP3430_reg_PRM_CLKSETUP", "This register allows setting the setup time of the oscillator system clock (sys_clk), based on nnumber of 32 kHz clock cycles");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x129C, "OMAP3430_reg_PRM_POLCTRL", "This register allows setting the polarity of device outputs control signals");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x12A0, "OMAP3430_reg_PRM_VOLTSETUP2", "This register allows setting the overall setup time of VDD1 and VDD2 regulators. This register is used when exiting OFF mode and when the Power IC manages the sequencing of the voltages regulation steps");
	// Here is an Secret Register Array. All information about them not available in public domain
	
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1358, "OMAP3430_reg_RM_RSTST_NEON", "This register logs the different reset sources of the NEON domain. Each bit is set upon release of the domain reset signal. Must be cleared by software");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x13C8, "OMAP3430_reg_PM_WKDEP_NEON", "This register allows enabling or disabling the wake-up of the NEON domain upon another domain");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x13E0, "OMAP3430_reg_PM_PWSTCTRL_NEON", "This register controls the NEON domain power state transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x13E4, "OMAP3430_reg_PM_PWSTST_NEON", "This register provides a status on the power state transition of the NEON domain");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x13E8, "OMAP3430_reg_PM_PREPWSTST_NEON", "This register provides a status on the NEON domain previous power state. It indicates the state entered during the last sleep transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x1458, "OMAP3430_reg_RM_RSTST_USBHOST", "This register logs the different reset sources of the USBHOST domain. Each bit is set upon release of the domain reset signal. Must be cleared by software");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x14A0, "OMAP3430_reg_PM_WKEN_USBHOST", "This register allows enabling/disabling modules wake-up events");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x14A4, "OMAP3430_reg_PM_MPUGRPSEL_USBHOST", "This register allows selecting the group of modules that wake-up the MPU");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x14A8, "OMAP3430_reg_PM_IVA2GRPSEL_USBHOST", "This register allows selecting the group of modules that wake-up the IVA2");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x14B0, "OMAP3430_reg_PM_WKST_USBHOST", "This register logs module wake-up events. Must be cleared by software. If it is not cleared, it prevents further domain transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x14C8, "OMAP3430_reg_PM_WKDEP_USBHOST", "This register allows enabling or disabling the wake-up of the USB HOST domain upon another domain wakeup");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x14E0, "OMAP3430_reg_PM_PWSTCTRL_USBHOST", "This register controls the USB HOST domain power state transition");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x14E4, "OMAP3430_reg_PM_PWSTST_USBHOST", "This register provides a status on the power state transition of the USB HOST domain");
	CreateDwordRegister(OMAP3430_PRM_BASE, 0x14E8, "OMAP3430_reg_PM_PREPWSTST_USBHOST", "This register provides a status on the USB HOST domain previous power state. It indicates the state entered during the last sleep transition");
	Message("Added OMAP3430 PRM Module registers\n");
}

// --- IPC Mailbox Module
static MLB_Module(void)
{
	if (!SegCreate(OMAP3430_MLB_BASE, OMAP3430_MLB_END, 0x0, 1, 0, 0)) {
		Warning("Can't create IPC Mailbox registers segment!\n");
		return;
	}
	SegRename(OMAP3430_MLB_BASE, "IPC_MAILBOX");
	SegClass(OMAP3430_MLB_BASE, "REGISTERS");
	CreateDwordRegister(OMAP3430_MLB_BASE, 0x0, "OMAP3430_reg_MAILBOX_REVISION", "This register contains the IP revision code.");
	CreateDwordRegister(OMAP3430_MLB_BASE, 0x10, "OMAP3430_reg_MAILBOX_SYSCONFIG", "This register controls the various parameters of the L4-Core interface");
	CreateDwordRegister(OMAP3430_MLB_BASE, 0x14, "OMAP3430_reg_MAILBOX_SYSSTATUS", "This register provides status information about the module, excluding the interrupt status information");
	CreateDwordRegister(OMAP3430_MLB_BASE, 0x40, "OMAP3430_reg_MAILBOX_MESSAGE_0", "The message register stores the next to be read message of the mailbox 0");
	CreateDwordRegister(OMAP3430_MLB_BASE, 0x44, "OMAP3430_reg_MAILBOX_MESSAGE_1", "The message register stores the next to be read message of the mailbox 1");
	CreateDwordRegister(OMAP3430_MLB_BASE, 0x80, "OMAP3430_reg_MAILBOX_FIFOSTATUS_0", "The FIFO status register has the status related to the mailbox internal FIFO");
	CreateDwordRegister(OMAP3430_MLB_BASE, 0x84, "OMAP3430_reg_MAILBOX_FIFOSTATUS_1", "The FIFO status register has the status related to the mailbox internal FIFO");
	CreateDwordRegister(OMAP3430_MLB_BASE, 0xC0, "OMAP3430_reg_MAILBOX_MSGSTATUS_0", "The message status register has the status of the messages in the mailbox");
	CreateDwordRegister(OMAP3430_MLB_BASE, 0xC4, "OMAP3430_reg_MAILBOX_MSGSTATUS_1", "The message status register has the status of the messages in the mailbox");
	CreateDwordRegister(OMAP3430_MLB_BASE, 0x100, "OMAP3430_reg_MAILBOX_IRQSTATUS_0", "The interrupt status register has the status for each event that may be responsible for the generation of an interrupt to the corresponding user - write 1 to a given bit resets this bit");
	CreateDwordRegister(OMAP3430_MLB_BASE, 0x104, "OMAP3430_reg_MAILBOX_IRQENABLE_0", "The interrupt enable register enables to mask/unmask the module internal source of interrupt to the corresponding user");
	CreateDwordRegister(OMAP3430_MLB_BASE, 0x108, "OMAP3430_reg_MAILBOX_IRQSTATUS_1", "The interrupt status register has the status for each event that may be responsible for the generation of an interrupt to the corresponding user - write 1 to a given bit resets this bit");
	CreateDwordRegister(OMAP3430_MLB_BASE, 0x10C, "OMAP3430_reg_MAILBOX_IRQENABLE_1", "The interrupt enable register enables to mask/unmask the module internal source of interrupt to the corresponding user");
	Message("Added OMAP3430 IPC Mailbox Module registers\n");
}

// --- Memory Management Units Module
static MMU_Module(void)
{
	if (!SegCreate(OMAP3430_MMU_CAM_BASE, OMAP3430_MMU_CAM_END, 0x0, 1, 0, 0)) {
		Warning("Can't create MMU Camera registers segment!\n");
		return;
	}
	if (!SegCreate(OMAP3430_MMU_IVA2_BASE, OMAP3430_MMU_IVA2_END, 0x0, 1, 0, 0)) {
		Warning("Can't create MMU IVA2 registers segment!\n");
		return;
	}
	SegRename(OMAP3430_MMU_CAM_BASE, "MMU_CAM");
	SegClass(OMAP3430_MMU_CAM_BASE, "REGISTERS");
	SegRename(OMAP3430_MMU_IVA2_BASE, "MMU_IVA2");
	SegClass(OMAP3430_MMU_IVA2_BASE, "REGISTERS");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x0, "OMAP3430_reg_CAM_MMU_REVISION", "This register contains the IP revision code");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x10, "OMAP3430_reg_CAM_MMU_SYSCONFIG", "This register contains the various parameters of the interconnect interface");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x14, "OMAP3430_reg_CAM_MMU_SYSSTATUS", "This register provides status information about the module, excluding the interrupt status information");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x18, "OMAP3430_reg_CAM_MMU_IRQSTATUS", "This interrupt status register regroups all the status of the module internal events that can generate an interrupt");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x1C, "OMAP3430_reg_CAM_MMU_IRQENABLE", "The interrupt enable register allows the module's internal sources of interrupt to be masked and unmasked on an event-by-event basis");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x40, "OMAP3430_reg_CAM_MMU_WALKING_ST", "This register provides status information about the table walking logic");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x44, "OMAP3430_reg_CAM_MMU_CNTL", "This register programs the MMU features");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x48, "OMAP3430_reg_CAM_MMU_FAULT_AD", "This register contains the virtual address that generated the interrupt");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x4C, "OMAP3430_reg_CAM_MMU_TTB", "This register contains the resolution table base address");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x50, "OMAP3430_reg_CAM_MMU_LOCK", "This register locks some of the TLB entries or specifies the TLB entry to be read");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x54, "OMAP3430_reg_CAM_MMU_LD_TLB", "This register loads a TLB entry (CAM+RAM)");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x58, "OMAP3430_reg_CAM_MMU_CAM", "This register holds a CAM entry");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x5C, "OMAP3430_reg_CAM_MMU_RAM", "This register holds a RAM entry");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x60, "OMAP3430_reg_CAM_MMU_GFLUSH", "This register flushes all the non-protected TLB entries");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x64, "OMAP3430_reg_CAM_MMU_FLUSH_ENTRY", "This register flushes the entry pointed to by the CAM virtual address");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x68, "OMAP3430_reg_CAM_MMU_READ_CAM", "This register reads CAM data from a CAM entry");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x6C, "OMAP3430_reg_CAM_MMU_READ_RAM", "This register reads RAM data from a RAM entry");
	CreateDwordRegister(OMAP3430_MMU_CAM_BASE, 0x70, "OMAP3430_reg_CAM_MMU_EMU_FAULT_AD", "This register contains the last virtual address of a fault caused by the debugger");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x0, "OMAP3430_reg_IVA2_MMU_REVISION", "This register contains the IP revision code");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x10, "OMAP3430_reg_IVA2_MMU_SYSCONFIG", "This register contains the various parameters of the interconnect interface");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x14, "OMAP3430_reg_IVA2_MMU_SYSSTATUS", "This register provides status information about the modules, excluding the interrupt status information");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x18, "OMAP3430_reg_IVA2_MMU_IRQSTATUS", "This interrupt status register regroups all the status of the module internal events that can generate an interrupt");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x1C, "OMAP3430_reg_IVA2_MMU_IRQENABLE", "The interrupt enable register allows the module's internal sources of interrupt to be masked and unmasked on an event-by-event basis");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x40, "OMAP3430_reg_IVA2_MMU_WALKING_ST", "This register provides status information about the table walking logic");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x44, "OMAP3430_reg_IVA2_MMU_CNTL", "This register programs the MMU features");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x48, "OMAP3430_reg_IVA2_MMU_FAULT_AD", "This register contains the virtual address that generated the interrupt");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x4C, "OMAP3430_reg_IVA2_MMU_TTB", "This register contains the resolution table base address");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x50, "OMAP3430_reg_IVA2_MMU_LOCK", "This register locks some of the TLB entries or specifies the TLB entry to be read");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x54, "OMAP3430_reg_IVA2_MMU_LD_TLB", "This register loads a TLB entry (CAM+RAM)");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x58, "OMAP3430_reg_IVA2_MMU_CAM", "This register holds a CAM entry");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x5C, "OMAP3430_reg_IVA2_MMU_RAM", "This register holds a RAM entry");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x60, "OMAP3430_reg_IVA2_MMU_GFLUSH", "This register flushes all the non-protected TLB entries");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x64, "OMAP3430_reg_IVA2_MMU_FLUSH_ENTRY", "This register flushes the entry pointed to by the CAM virtual address");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x68, "OMAP3430_reg_IVA2_MMU_READ_CAM", "This register read CAM data from a CAM entry");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x6C, "OMAP3430_reg_IVA2_MMU_READ_RAM", "This register read RAM data from a RAM entry");
	CreateDwordRegister(OMAP3430_MMU_IVA2_BASE, 0x70, "OMAP3430_reg_IVA2_MMU_EMU_FAULT_AD", "This register contains the last virtual address of a fault caused by the debugger");
	Message("Added OMAP3430 MMU Module registers\n");
}

// --- DMA Module
static DMA_Module(void)
{
	if (!SegCreate(OMAP3430_SDMA_BASE, OMAP3430_SDMA_END, 0x0, 1, 0, 0)) {
		Warning("Can't create DMA registers segment!\n");
		return;
	}
	SegRename(OMAP3430_SDMA_BASE, "DMA");
	SegClass(OMAP3430_SDMA_BASE, "REGISTERS");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x0, "OMAP3430_reg_DMA4_REVISION", "This register contains the DMA revision code");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8, "OMAP3430_reg_DMA4_IRQSTATUS_L0", "The interrupt status register regroups all the status of the DMA4 channels that can generate an interrupt over line L0");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC, "OMAP3430_reg_DMA4_IRQSTATUS_L1", "The interrupt status register regroups all the status of the DMA4 channels that can generate an interrupt over line L1");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x10, "OMAP3430_reg_DMA4_IRQSTATUS_L2", "The interrupt status register regroups all the status of the DMA4 channels that can generate an interrupt over line L2");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x14, "OMAP3430_reg_DMA4_IRQSTATUS_L3", "The interrupt status register regroups all the status of the DMA4 channels that can generate an interrupt over line L3");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x18, "OMAP3430_reg_DMA4_IRQENABLE_L0", "The interrupt enable register allows to mask/unmask the module internal sources of interrupt, on line L0");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1C, "OMAP3430_reg_DMA4_IRQENABLE_L1", "The interrupt enable register allows to mask/unmask the module internal sources of interrupt, on line L1");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x20, "OMAP3430_reg_DMA4_IRQENABLE_L2", "The interrupt enable register allows to mask/unmask the module internal sources of interrupt, on line L2");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x24, "OMAP3430_reg_DMA4_IRQENABLE_L3", "The interrupt enable register allows to mask/unmask the module internal sources of interrupt, on line L3");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x28, "OMAP3430_reg_DMA4_SYSSTATUS", "The register provides status information about the module excluding the interrupt status information");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2C, "OMAP3430_reg_DMA4_OCP_SYSCONFIG", "This register controls the various parameters of the OCP interface");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x64, "OMAP3430_reg_DMA4_CAPS_0", "DMA Capabilities Register 0 LSW");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6C, "OMAP3430_reg_DMA4_CAPS_2", "DMA Capabilities Register 2");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x70, "OMAP3430_reg_DMA4_CAPS_3", "DMA Capabilities Register 3");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x74, "OMAP3430_reg_DMA4_CAPS_4", "DMA Capabilities Register 4");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x78, "OMAP3430_reg_DMA4_GCR", "FIFO sharing between high and low priority channel. The Maximum per channel FIFO depth is bounded by the low and high channel FIFO bufget. The high respectively low priority channels maximum burst size must be less than the min (high respectively low priority channel FIFO budget, per channel maximum FIFO depth)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x80, "OMAP3430_reg_DMA4_CCR0", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x84, "OMAP3430_reg_DMA4_CLNK_CTRL0", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x88, "OMAP3430_reg_DMA4_CICR0", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8C, "OMAP3430_reg_DMA4_CSR0", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x90, "OMAP3430_reg_DMA4_CSDP0", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x94, "OMAP3430_reg_DMA4_CEN0", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x98, "OMAP3430_reg_DMA4_CFN0", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9C, "OMAP3430_reg_DMA4_CSSA0", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA0, "OMAP3430_reg_DMA4_CDSA0", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA4, "OMAP3430_reg_DMA4_CSEI0", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA8, "OMAP3430_reg_DMA4_CSFI0", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xAC, "OMAP3430_reg_DMA4_CDEI0", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB0, "OMAP3430_reg_DMA4_CDFI0", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB4, "OMAP3430_reg_DMA4_CSAC0", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB8, "OMAP3430_reg_DMA4_CDAC0", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBC, "OMAP3430_reg_DMA4_CCEN0", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC0, "OMAP3430_reg_DMA4_CCFN0", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC4, "OMAP3430_reg_DMA4_COLOR0", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xE0, "OMAP3430_reg_DMA4_CCR1", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xE4, "OMAP3430_reg_DMA4_CLNK_CTRL1", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xE8, "OMAP3430_reg_DMA4_CICR1", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xEC, "OMAP3430_reg_DMA4_CSR1", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xF0, "OMAP3430_reg_DMA4_CSDP1", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xF4, "OMAP3430_reg_DMA4_CEN1", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xF8, "OMAP3430_reg_DMA4_CFN1", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xFC, "OMAP3430_reg_DMA4_CSSA1", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x100, "OMAP3430_reg_DMA4_CDSA1", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x104, "OMAP3430_reg_DMA4_CSEI1", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x108, "OMAP3430_reg_DMA4_CSFI1", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x10C, "OMAP3430_reg_DMA4_CDEI1", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x110, "OMAP3430_reg_DMA4_CDFI1", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x114, "OMAP3430_reg_DMA4_CSAC1", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x118, "OMAP3430_reg_DMA4_CDAC1", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x11C, "OMAP3430_reg_DMA4_CCEN1", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x120, "OMAP3430_reg_DMA4_CCFN1", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x124, "OMAP3430_reg_DMA4_COLOR1", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x140, "OMAP3430_reg_DMA4_CCR2", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x144, "OMAP3430_reg_DMA4_CLNK_CTRL2", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x148, "OMAP3430_reg_DMA4_CICR2", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x14C, "OMAP3430_reg_DMA4_CSR2", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x150, "OMAP3430_reg_DMA4_CSDP2", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x154, "OMAP3430_reg_DMA4_CEN2", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x158, "OMAP3430_reg_DMA4_CFN2", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x15C, "OMAP3430_reg_DMA4_CSSA2", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x160, "OMAP3430_reg_DMA4_CDSA2", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x164, "OMAP3430_reg_DMA4_CSEI2", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x168, "OMAP3430_reg_DMA4_CSFI2", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x16C, "OMAP3430_reg_DMA4_CDEI2", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x170, "OMAP3430_reg_DMA4_CDFI2", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x174, "OMAP3430_reg_DMA4_CSAC2", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x178, "OMAP3430_reg_DMA4_CDAC2", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x17C, "OMAP3430_reg_DMA4_CCEN2", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x180, "OMAP3430_reg_DMA4_CCFN2", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x184, "OMAP3430_reg_DMA4_COLOR2", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1A0, "OMAP3430_reg_DMA4_CCR3", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1A4, "OMAP3430_reg_DMA4_CLNK_CTRL3", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1A8, "OMAP3430_reg_DMA4_CICR3", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1AC, "OMAP3430_reg_DMA4_CSR3", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1B0, "OMAP3430_reg_DMA4_CSDP3", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1B4, "OMAP3430_reg_DMA4_CEN3", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1B8, "OMAP3430_reg_DMA4_CFN3", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1BC, "OMAP3430_reg_DMA4_CSSA3", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1C0, "OMAP3430_reg_DMA4_CDSA3", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1C4, "OMAP3430_reg_DMA4_CSEI3", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1C8, "OMAP3430_reg_DMA4_CSFI3", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1CC, "OMAP3430_reg_DMA4_CDEI3", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1D0, "OMAP3430_reg_DMA4_CDFI3", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1D4, "OMAP3430_reg_DMA4_CSAC3", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1D8, "OMAP3430_reg_DMA4_CDAC3", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1DC, "OMAP3430_reg_DMA4_CCEN3", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1E0, "OMAP3430_reg_DMA4_CCFN3", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x1E4, "OMAP3430_reg_DMA4_COLOR3", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x200, "OMAP3430_reg_DMA4_CCR4", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x204, "OMAP3430_reg_DMA4_CLNK_CTRL4", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x208, "OMAP3430_reg_DMA4_CICR4", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x20C, "OMAP3430_reg_DMA4_CSR4", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x210, "OMAP3430_reg_DMA4_CSDP4", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x214, "OMAP3430_reg_DMA4_CEN4", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x218, "OMAP3430_reg_DMA4_CFN4", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x21C, "OMAP3430_reg_DMA4_CSSA4", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x220, "OMAP3430_reg_DMA4_CDSA4", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x224, "OMAP3430_reg_DMA4_CSEI4", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x228, "OMAP3430_reg_DMA4_CSFI4", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x22C, "OMAP3430_reg_DMA4_CDEI4", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x230, "OMAP3430_reg_DMA4_CDFI4", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x234, "OMAP3430_reg_DMA4_CSAC4", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x238, "OMAP3430_reg_DMA4_CDAC4", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x23C, "OMAP3430_reg_DMA4_CCEN4", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x240, "OMAP3430_reg_DMA4_CCFN4", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x244, "OMAP3430_reg_DMA4_COLOR4", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x260, "OMAP3430_reg_DMA4_CCR5", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x264, "OMAP3430_reg_DMA4_CLNK_CTRL5", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x268, "OMAP3430_reg_DMA4_CICR5", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x26C, "OMAP3430_reg_DMA4_CSR5", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x270, "OMAP3430_reg_DMA4_CSDP5", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x274, "OMAP3430_reg_DMA4_CEN5", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x278, "OMAP3430_reg_DMA4_CFN5", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x27C, "OMAP3430_reg_DMA4_CSSA5", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x280, "OMAP3430_reg_DMA4_CDSA5", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x284, "OMAP3430_reg_DMA4_CSEI5", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x288, "OMAP3430_reg_DMA4_CSFI5", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x28C, "OMAP3430_reg_DMA4_CDEI5", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x290, "OMAP3430_reg_DMA4_CDFI5", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x294, "OMAP3430_reg_DMA4_CSAC5", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x298, "OMAP3430_reg_DMA4_CDAC5", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x29C, "OMAP3430_reg_DMA4_CCEN5", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2A0, "OMAP3430_reg_DMA4_CCFN5", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2A4, "OMAP3430_reg_DMA4_COLOR5", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2C0, "OMAP3430_reg_DMA4_CCR6", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2C4, "OMAP3430_reg_DMA4_CLNK_CTRL6", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2C8, "OMAP3430_reg_DMA4_CICR6", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2CC, "OMAP3430_reg_DMA4_CSR6", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2D0, "OMAP3430_reg_DMA4_CSDP6", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2D4, "OMAP3430_reg_DMA4_CEN6", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2D8, "OMAP3430_reg_DMA4_CFN6", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2DC, "OMAP3430_reg_DMA4_CSSA6", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2E0, "OMAP3430_reg_DMA4_CDSA6", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2E4, "OMAP3430_reg_DMA4_CSEI6", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2E8, "OMAP3430_reg_DMA4_CSFI6", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2EC, "OMAP3430_reg_DMA4_CDEI6", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2F0, "OMAP3430_reg_DMA4_CDFI6", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2F4, "OMAP3430_reg_DMA4_CSAC6", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2F8, "OMAP3430_reg_DMA4_CDAC6", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x2FC, "OMAP3430_reg_DMA4_CCEN6", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x300, "OMAP3430_reg_DMA4_CCFN6", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x304, "OMAP3430_reg_DMA4_COLOR6", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x320, "OMAP3430_reg_DMA4_CCR7", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x324, "OMAP3430_reg_DMA4_CLNK_CTRL7", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x328, "OMAP3430_reg_DMA4_CICR7", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x32C, "OMAP3430_reg_DMA4_CSR7", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x330, "OMAP3430_reg_DMA4_CSDP7", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x334, "OMAP3430_reg_DMA4_CEN7", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x338, "OMAP3430_reg_DMA4_CFN7", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x33C, "OMAP3430_reg_DMA4_CSSA7", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x340, "OMAP3430_reg_DMA4_CDSA7", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x344, "OMAP3430_reg_DMA4_CSEI7", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x348, "OMAP3430_reg_DMA4_CSFI7", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x34C, "OMAP3430_reg_DMA4_CDEI7", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x350, "OMAP3430_reg_DMA4_CDFI7", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x354, "OMAP3430_reg_DMA4_CSAC7", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x358, "OMAP3430_reg_DMA4_CDAC7", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x35C, "OMAP3430_reg_DMA4_CCEN7", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x360, "OMAP3430_reg_DMA4_CCFN7", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x364, "OMAP3430_reg_DMA4_COLOR7", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x380, "OMAP3430_reg_DMA4_CCR8", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x384, "OMAP3430_reg_DMA4_CLNK_CTRL8", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x388, "OMAP3430_reg_DMA4_CICR8", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x38C, "OMAP3430_reg_DMA4_CSR8", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x390, "OMAP3430_reg_DMA4_CSDP8", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x394, "OMAP3430_reg_DMA4_CEN8", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x398, "OMAP3430_reg_DMA4_CFN8", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x39C, "OMAP3430_reg_DMA4_CSSA8", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3A0, "OMAP3430_reg_DMA4_CDSA8", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3A4, "OMAP3430_reg_DMA4_CSEI8", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3A8, "OMAP3430_reg_DMA4_CSFI8", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3AC, "OMAP3430_reg_DMA4_CDEI8", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3B0, "OMAP3430_reg_DMA4_CDFI8", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3B4, "OMAP3430_reg_DMA4_CSAC8", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3B8, "OMAP3430_reg_DMA4_CDAC8", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3BC, "OMAP3430_reg_DMA4_CCEN8", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3C0, "OMAP3430_reg_DMA4_CCFN8", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3C4, "OMAP3430_reg_DMA4_COLOR8", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3E0, "OMAP3430_reg_DMA4_CCR9", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3E4, "OMAP3430_reg_DMA4_CLNK_CTRL9", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3E8, "OMAP3430_reg_DMA4_CICR9", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3EC, "OMAP3430_reg_DMA4_CSR9", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3F0, "OMAP3430_reg_DMA4_CSDP9", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3F4, "OMAP3430_reg_DMA4_CEN9", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3F8, "OMAP3430_reg_DMA4_CFN9", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x3FC, "OMAP3430_reg_DMA4_CSSA9", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x400, "OMAP3430_reg_DMA4_CDSA9", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x404, "OMAP3430_reg_DMA4_CSEI9", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x408, "OMAP3430_reg_DMA4_CSFI9", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x40C, "OMAP3430_reg_DMA4_CDEI9", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x410, "OMAP3430_reg_DMA4_CDFI9", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x414, "OMAP3430_reg_DMA4_CSAC9", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x418, "OMAP3430_reg_DMA4_CDAC9", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x41C, "OMAP3430_reg_DMA4_CCEN9", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x420, "OMAP3430_reg_DMA4_CCFN9", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x424, "OMAP3430_reg_DMA4_COLOR9", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x440, "OMAP3430_reg_DMA4_CCR10", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x444, "OMAP3430_reg_DMA4_CLNK_CTRL10", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x448, "OMAP3430_reg_DMA4_CICR10", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x44C, "OMAP3430_reg_DMA4_CSR10", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x450, "OMAP3430_reg_DMA4_CSDP10", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x454, "OMAP3430_reg_DMA4_CEN10", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x458, "OMAP3430_reg_DMA4_CFN10", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x45C, "OMAP3430_reg_DMA4_CSSA10", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x460, "OMAP3430_reg_DMA4_CDSA10", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x464, "OMAP3430_reg_DMA4_CSEI10", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x468, "OMAP3430_reg_DMA4_CSFI10", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x46C, "OMAP3430_reg_DMA4_CDEI10", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x470, "OMAP3430_reg_DMA4_CDFI10", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x474, "OMAP3430_reg_DMA4_CSAC10", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x478, "OMAP3430_reg_DMA4_CDAC10", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x47C, "OMAP3430_reg_DMA4_CCEN10", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x480, "OMAP3430_reg_DMA4_CCFN10", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x484, "OMAP3430_reg_DMA4_COLOR10", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4A0, "OMAP3430_reg_DMA4_CCR11", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4A4, "OMAP3430_reg_DMA4_CLNK_CTRL11", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4A8, "OMAP3430_reg_DMA4_CICR11", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4AC, "OMAP3430_reg_DMA4_CSR11", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4B0, "OMAP3430_reg_DMA4_CSDP11", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4B4, "OMAP3430_reg_DMA4_CEN11", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4B8, "OMAP3430_reg_DMA4_CFN11", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4BC, "OMAP3430_reg_DMA4_CSSA11", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4C0, "OMAP3430_reg_DMA4_CDSA11", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4C4, "OMAP3430_reg_DMA4_CSEI11", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4C8, "OMAP3430_reg_DMA4_CSFI11", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4CC, "OMAP3430_reg_DMA4_CDEI11", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4D0, "OMAP3430_reg_DMA4_CDFI11", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4D4, "OMAP3430_reg_DMA4_CSAC11", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4D8, "OMAP3430_reg_DMA4_CDAC11", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4DC, "OMAP3430_reg_DMA4_CCEN11", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4E0, "OMAP3430_reg_DMA4_CCFN11", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x4E4, "OMAP3430_reg_DMA4_COLOR11", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x500, "OMAP3430_reg_DMA4_CCR12", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x504, "OMAP3430_reg_DMA4_CLNK_CTRL12", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x508, "OMAP3430_reg_DMA4_CICR12", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x50C, "OMAP3430_reg_DMA4_CSR12", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x510, "OMAP3430_reg_DMA4_CSDP12", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x514, "OMAP3430_reg_DMA4_CEN12", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x518, "OMAP3430_reg_DMA4_CFN12", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x51C, "OMAP3430_reg_DMA4_CSSA12", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x520, "OMAP3430_reg_DMA4_CDSA12", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x524, "OMAP3430_reg_DMA4_CSEI12", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x528, "OMAP3430_reg_DMA4_CSFI12", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x52C, "OMAP3430_reg_DMA4_CDEI12", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x530, "OMAP3430_reg_DMA4_CDFI12", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x534, "OMAP3430_reg_DMA4_CSAC12", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x538, "OMAP3430_reg_DMA4_CDAC12", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x53C, "OMAP3430_reg_DMA4_CCEN12", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x540, "OMAP3430_reg_DMA4_CCFN12", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x544, "OMAP3430_reg_DMA4_COLOR12", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x560, "OMAP3430_reg_DMA4_CCR13", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x564, "OMAP3430_reg_DMA4_CLNK_CTRL13", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x568, "OMAP3430_reg_DMA4_CICR13", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x56C, "OMAP3430_reg_DMA4_CSR13", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x570, "OMAP3430_reg_DMA4_CSDP13", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x574, "OMAP3430_reg_DMA4_CEN13", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x578, "OMAP3430_reg_DMA4_CFN13", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x57C, "OMAP3430_reg_DMA4_CSSA13", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x580, "OMAP3430_reg_DMA4_CDSA13", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x584, "OMAP3430_reg_DMA4_CSEI13", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x588, "OMAP3430_reg_DMA4_CSFI13", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x58C, "OMAP3430_reg_DMA4_CDEI13", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x590, "OMAP3430_reg_DMA4_CDFI13", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x594, "OMAP3430_reg_DMA4_CSAC13", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x598, "OMAP3430_reg_DMA4_CDAC13", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x59C, "OMAP3430_reg_DMA4_CCEN13", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5A0, "OMAP3430_reg_DMA4_CCFN13", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5A4, "OMAP3430_reg_DMA4_COLOR13", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5C0, "OMAP3430_reg_DMA4_CCR14", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5C4, "OMAP3430_reg_DMA4_CLNK_CTRL14", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5C8, "OMAP3430_reg_DMA4_CICR14", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5CC, "OMAP3430_reg_DMA4_CSR14", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5D0, "OMAP3430_reg_DMA4_CSDP14", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5D4, "OMAP3430_reg_DMA4_CEN14", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5D8, "OMAP3430_reg_DMA4_CFN14", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5DC, "OMAP3430_reg_DMA4_CSSA14", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5E0, "OMAP3430_reg_DMA4_CDSA14", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5E4, "OMAP3430_reg_DMA4_CSEI14", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5E8, "OMAP3430_reg_DMA4_CSFI14", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5EC, "OMAP3430_reg_DMA4_CDEI14", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5F0, "OMAP3430_reg_DMA4_CDFI14", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5F4, "OMAP3430_reg_DMA4_CSAC14", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5F8, "OMAP3430_reg_DMA4_CDAC14", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x5FC, "OMAP3430_reg_DMA4_CCEN14", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x600, "OMAP3430_reg_DMA4_CCFN14", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x604, "OMAP3430_reg_DMA4_COLOR14", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x620, "OMAP3430_reg_DMA4_CCR15", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x624, "OMAP3430_reg_DMA4_CLNK_CTRL15", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x628, "OMAP3430_reg_DMA4_CICR15", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x62C, "OMAP3430_reg_DMA4_CSR15", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x630, "OMAP3430_reg_DMA4_CSDP15", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x634, "OMAP3430_reg_DMA4_CEN15", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x638, "OMAP3430_reg_DMA4_CFN15", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x63C, "OMAP3430_reg_DMA4_CSSA15", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x640, "OMAP3430_reg_DMA4_CDSA15", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x644, "OMAP3430_reg_DMA4_CSEI15", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x648, "OMAP3430_reg_DMA4_CSFI15", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x64C, "OMAP3430_reg_DMA4_CDEI15", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x650, "OMAP3430_reg_DMA4_CDFI15", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x654, "OMAP3430_reg_DMA4_CSAC15", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x658, "OMAP3430_reg_DMA4_CDAC15", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x65C, "OMAP3430_reg_DMA4_CCEN15", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x660, "OMAP3430_reg_DMA4_CCFN15", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x664, "OMAP3430_reg_DMA4_COLOR15", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x680, "OMAP3430_reg_DMA4_CCR16", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x684, "OMAP3430_reg_DMA4_CLNK_CTRL16", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x688, "OMAP3430_reg_DMA4_CICR16", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x68C, "OMAP3430_reg_DMA4_CSR16", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x690, "OMAP3430_reg_DMA4_CSDP16", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x694, "OMAP3430_reg_DMA4_CEN16", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x698, "OMAP3430_reg_DMA4_CFN16", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x69C, "OMAP3430_reg_DMA4_CSSA16", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6A0, "OMAP3430_reg_DMA4_CDSA16", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6A4, "OMAP3430_reg_DMA4_CSEI16", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6A8, "OMAP3430_reg_DMA4_CSFI16", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6AC, "OMAP3430_reg_DMA4_CDEI16", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6B0, "OMAP3430_reg_DMA4_CDFI16", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6B4, "OMAP3430_reg_DMA4_CSAC16", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6B8, "OMAP3430_reg_DMA4_CDAC16", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6BC, "OMAP3430_reg_DMA4_CCEN16", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6C0, "OMAP3430_reg_DMA4_CCFN16", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6C4, "OMAP3430_reg_DMA4_COLOR16", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6E0, "OMAP3430_reg_DMA4_CCR17", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6E4, "OMAP3430_reg_DMA4_CLNK_CTRL17", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6E8, "OMAP3430_reg_DMA4_CICR17", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6EC, "OMAP3430_reg_DMA4_CSR17", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6F0, "OMAP3430_reg_DMA4_CSDP17", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6F4, "OMAP3430_reg_DMA4_CEN17", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6F8, "OMAP3430_reg_DMA4_CFN17", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x6FC, "OMAP3430_reg_DMA4_CSSA17", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x700, "OMAP3430_reg_DMA4_CDSA17", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x704, "OMAP3430_reg_DMA4_CSEI17", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x708, "OMAP3430_reg_DMA4_CSFI17", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x70C, "OMAP3430_reg_DMA4_CDEI17", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x710, "OMAP3430_reg_DMA4_CDFI17", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x714, "OMAP3430_reg_DMA4_CSAC17", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x718, "OMAP3430_reg_DMA4_CDAC17", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x71C, "OMAP3430_reg_DMA4_CCEN17", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x720, "OMAP3430_reg_DMA4_CCFN17", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x724, "OMAP3430_reg_DMA4_COLOR17", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x740, "OMAP3430_reg_DMA4_CCR18", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x744, "OMAP3430_reg_DMA4_CLNK_CTRL18", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x748, "OMAP3430_reg_DMA4_CICR18", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x74C, "OMAP3430_reg_DMA4_CSR18", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x750, "OMAP3430_reg_DMA4_CSDP18", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x754, "OMAP3430_reg_DMA4_CEN18", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x758, "OMAP3430_reg_DMA4_CFN18", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x75C, "OMAP3430_reg_DMA4_CSSA18", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x760, "OMAP3430_reg_DMA4_CDSA18", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x764, "OMAP3430_reg_DMA4_CSEI18", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x768, "OMAP3430_reg_DMA4_CSFI18", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x76C, "OMAP3430_reg_DMA4_CDEI18", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x770, "OMAP3430_reg_DMA4_CDFI18", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x774, "OMAP3430_reg_DMA4_CSAC18", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x778, "OMAP3430_reg_DMA4_CDAC18", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x77C, "OMAP3430_reg_DMA4_CCEN18", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x780, "OMAP3430_reg_DMA4_CCFN18", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x784, "OMAP3430_reg_DMA4_COLOR18", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7A0, "OMAP3430_reg_DMA4_CCR19", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7A4, "OMAP3430_reg_DMA4_CLNK_CTRL19", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7A8, "OMAP3430_reg_DMA4_CICR19", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7AC, "OMAP3430_reg_DMA4_CSR19", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7B0, "OMAP3430_reg_DMA4_CSDP19", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7B4, "OMAP3430_reg_DMA4_CEN19", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7B8, "OMAP3430_reg_DMA4_CFN19", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7BC, "OMAP3430_reg_DMA4_CSSA19", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7C0, "OMAP3430_reg_DMA4_CDSA19", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7C4, "OMAP3430_reg_DMA4_CSEI19", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7C8, "OMAP3430_reg_DMA4_CSFI19", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7CC, "OMAP3430_reg_DMA4_CDEI19", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7D0, "OMAP3430_reg_DMA4_CDFI19", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7D4, "OMAP3430_reg_DMA4_CSAC19", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7D8, "OMAP3430_reg_DMA4_CDAC19", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7DC, "OMAP3430_reg_DMA4_CCEN19", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7E0, "OMAP3430_reg_DMA4_CCFN19", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x7E4, "OMAP3430_reg_DMA4_COLOR19", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x800, "OMAP3430_reg_DMA4_CCR20", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x804, "OMAP3430_reg_DMA4_CLNK_CTRL20", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x808, "OMAP3430_reg_DMA4_CICR20", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x80C, "OMAP3430_reg_DMA4_CSR20", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x810, "OMAP3430_reg_DMA4_CSDP20", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x814, "OMAP3430_reg_DMA4_CEN20", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x818, "OMAP3430_reg_DMA4_CFN20", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x81C, "OMAP3430_reg_DMA4_CSSA20", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x820, "OMAP3430_reg_DMA4_CDSA20", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x824, "OMAP3430_reg_DMA4_CSEI20", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x828, "OMAP3430_reg_DMA4_CSFI20", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x82C, "OMAP3430_reg_DMA4_CDEI20", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x830, "OMAP3430_reg_DMA4_CDFI20", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x834, "OMAP3430_reg_DMA4_CSAC20", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x838, "OMAP3430_reg_DMA4_CDAC20", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x83C, "OMAP3430_reg_DMA4_CCEN20", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x840, "OMAP3430_reg_DMA4_CCFN20", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x844, "OMAP3430_reg_DMA4_COLOR20", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x860, "OMAP3430_reg_DMA4_CCR21", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x864, "OMAP3430_reg_DMA4_CLNK_CTRL21", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x868, "OMAP3430_reg_DMA4_CICR21", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x86C, "OMAP3430_reg_DMA4_CSR21", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x870, "OMAP3430_reg_DMA4_CSDP21", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x874, "OMAP3430_reg_DMA4_CEN21", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x878, "OMAP3430_reg_DMA4_CFN21", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x87C, "OMAP3430_reg_DMA4_CSSA21", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x880, "OMAP3430_reg_DMA4_CDSA21", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x884, "OMAP3430_reg_DMA4_CSEI21", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x888, "OMAP3430_reg_DMA4_CSFI21", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x88C, "OMAP3430_reg_DMA4_CDEI21", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x890, "OMAP3430_reg_DMA4_CDFI21", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x894, "OMAP3430_reg_DMA4_CSAC21", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x898, "OMAP3430_reg_DMA4_CDAC21", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x89C, "OMAP3430_reg_DMA4_CCEN21", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8A0, "OMAP3430_reg_DMA4_CCFN21", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8A4, "OMAP3430_reg_DMA4_COLOR21", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8C0, "OMAP3430_reg_DMA4_CCR22", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8C4, "OMAP3430_reg_DMA4_CLNK_CTRL22", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8C8, "OMAP3430_reg_DMA4_CICR22", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8CC, "OMAP3430_reg_DMA4_CSR22", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8D0, "OMAP3430_reg_DMA4_CSDP22", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8D4, "OMAP3430_reg_DMA4_CEN22", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8D8, "OMAP3430_reg_DMA4_CFN22", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8DC, "OMAP3430_reg_DMA4_CSSA22", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8E0, "OMAP3430_reg_DMA4_CDSA22", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8E4, "OMAP3430_reg_DMA4_CSEI22", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8E8, "OMAP3430_reg_DMA4_CSFI22", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8EC, "OMAP3430_reg_DMA4_CDEI22", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8F0, "OMAP3430_reg_DMA4_CDFI22", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8F4, "OMAP3430_reg_DMA4_CSAC22", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8F8, "OMAP3430_reg_DMA4_CDAC22", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x8FC, "OMAP3430_reg_DMA4_CCEN22", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x900, "OMAP3430_reg_DMA4_CCFN22", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x904, "OMAP3430_reg_DMA4_COLOR22", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x920, "OMAP3430_reg_DMA4_CCR23", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x924, "OMAP3430_reg_DMA4_CLNK_CTRL23", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x928, "OMAP3430_reg_DMA4_CICR23", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x92C, "OMAP3430_reg_DMA4_CSR23", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x930, "OMAP3430_reg_DMA4_CSDP23", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x934, "OMAP3430_reg_DMA4_CEN23", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x938, "OMAP3430_reg_DMA4_CFN23", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x93C, "OMAP3430_reg_DMA4_CSSA23", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x940, "OMAP3430_reg_DMA4_CDSA23", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x944, "OMAP3430_reg_DMA4_CSEI23", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x948, "OMAP3430_reg_DMA4_CSFI23", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x94C, "OMAP3430_reg_DMA4_CDEI23", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x950, "OMAP3430_reg_DMA4_CDFI23", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x954, "OMAP3430_reg_DMA4_CSAC23", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x958, "OMAP3430_reg_DMA4_CDAC23", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x95C, "OMAP3430_reg_DMA4_CCEN23", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x960, "OMAP3430_reg_DMA4_CCFN23", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x964, "OMAP3430_reg_DMA4_COLOR23", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x980, "OMAP3430_reg_DMA4_CCR24", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x984, "OMAP3430_reg_DMA4_CLNK_CTRL24", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x988, "OMAP3430_reg_DMA4_CICR24", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x98C, "OMAP3430_reg_DMA4_CSR24", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x990, "OMAP3430_reg_DMA4_CSDP24", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x994, "OMAP3430_reg_DMA4_CEN24", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x998, "OMAP3430_reg_DMA4_CFN24", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x99C, "OMAP3430_reg_DMA4_CSSA24", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9A0, "OMAP3430_reg_DMA4_CDSA24", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9A4, "OMAP3430_reg_DMA4_CSEI24", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9A8, "OMAP3430_reg_DMA4_CSFI24", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9AC, "OMAP3430_reg_DMA4_CDEI24", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9B0, "OMAP3430_reg_DMA4_CDFI24", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9B4, "OMAP3430_reg_DMA4_CSAC24", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9B8, "OMAP3430_reg_DMA4_CDAC24", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9BC, "OMAP3430_reg_DMA4_CCEN24", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9C0, "OMAP3430_reg_DMA4_CCFN24", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9C4, "OMAP3430_reg_DMA4_COLOR24", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9E0, "OMAP3430_reg_DMA4_CCR25", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9E4, "OMAP3430_reg_DMA4_CLNK_CTRL25", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9E8, "OMAP3430_reg_DMA4_CICR25", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9EC, "OMAP3430_reg_DMA4_CSR25", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9F0, "OMAP3430_reg_DMA4_CSDP25", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9F4, "OMAP3430_reg_DMA4_CEN25", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9F8, "OMAP3430_reg_DMA4_CFN25", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0x9FC, "OMAP3430_reg_DMA4_CSSA25", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA00, "OMAP3430_reg_DMA4_CDSA25", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA04, "OMAP3430_reg_DMA4_CSEI25", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA08, "OMAP3430_reg_DMA4_CSFI25", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA0C, "OMAP3430_reg_DMA4_CDEI25", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA10, "OMAP3430_reg_DMA4_CDFI25", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA14, "OMAP3430_reg_DMA4_CSAC25", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA18, "OMAP3430_reg_DMA4_CDAC25", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA1C, "OMAP3430_reg_DMA4_CCEN25", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA20, "OMAP3430_reg_DMA4_CCFN25", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA24, "OMAP3430_reg_DMA4_COLOR25", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA40, "OMAP3430_reg_DMA4_CCR26", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA44, "OMAP3430_reg_DMA4_CLNK_CTRL26", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA48, "OMAP3430_reg_DMA4_CICR26", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA4C, "OMAP3430_reg_DMA4_CSR26", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA50, "OMAP3430_reg_DMA4_CSDP26", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA54, "OMAP3430_reg_DMA4_CEN26", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA58, "OMAP3430_reg_DMA4_CFN26", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA5C, "OMAP3430_reg_DMA4_CSSA26", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA60, "OMAP3430_reg_DMA4_CDSA26", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA64, "OMAP3430_reg_DMA4_CSEI26", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA68, "OMAP3430_reg_DMA4_CSFI26", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA6C, "OMAP3430_reg_DMA4_CDEI26", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA70, "OMAP3430_reg_DMA4_CDFI26", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA74, "OMAP3430_reg_DMA4_CSAC26", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA78, "OMAP3430_reg_DMA4_CDAC26", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA7C, "OMAP3430_reg_DMA4_CCEN26", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA80, "OMAP3430_reg_DMA4_CCFN26", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xA84, "OMAP3430_reg_DMA4_COLOR26", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xAA0, "OMAP3430_reg_DMA4_CCR27", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xAA4, "OMAP3430_reg_DMA4_CLNK_CTRL27", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xAA8, "OMAP3430_reg_DMA4_CICR27", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xAAC, "OMAP3430_reg_DMA4_CSR27", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xAB0, "OMAP3430_reg_DMA4_CSDP27", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xAB4, "OMAP3430_reg_DMA4_CEN27", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xAB8, "OMAP3430_reg_DMA4_CFN27", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xABC, "OMAP3430_reg_DMA4_CSSA27", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xAC0, "OMAP3430_reg_DMA4_CDSA27", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xAC4, "OMAP3430_reg_DMA4_CSEI27", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xAC8, "OMAP3430_reg_DMA4_CSFI27", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xACC, "OMAP3430_reg_DMA4_CDEI27", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xAD0, "OMAP3430_reg_DMA4_CDFI27", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xAD4, "OMAP3430_reg_DMA4_CSAC27", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xAD8, "OMAP3430_reg_DMA4_CDAC27", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xADC, "OMAP3430_reg_DMA4_CCEN27", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xAE0, "OMAP3430_reg_DMA4_CCFN27", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xAE4, "OMAP3430_reg_DMA4_COLOR27", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB00, "OMAP3430_reg_DMA4_CCR28", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB04, "OMAP3430_reg_DMA4_CLNK_CTRL28", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB08, "OMAP3430_reg_DMA4_CICR28", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB0C, "OMAP3430_reg_DMA4_CSR28", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB10, "OMAP3430_reg_DMA4_CSDP28", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB14, "OMAP3430_reg_DMA4_CEN28", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB18, "OMAP3430_reg_DMA4_CFN28", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB1C, "OMAP3430_reg_DMA4_CSSA28", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB20, "OMAP3430_reg_DMA4_CDSA28", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB24, "OMAP3430_reg_DMA4_CSEI28", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB28, "OMAP3430_reg_DMA4_CSFI28", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB2C, "OMAP3430_reg_DMA4_CDEI28", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB30, "OMAP3430_reg_DMA4_CDFI28", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB34, "OMAP3430_reg_DMA4_CSAC28", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB38, "OMAP3430_reg_DMA4_CDAC28", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB3C, "OMAP3430_reg_DMA4_CCEN28", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB40, "OMAP3430_reg_DMA4_CCFN28", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB44, "OMAP3430_reg_DMA4_COLOR28", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB60, "OMAP3430_reg_DMA4_CCR29", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB64, "OMAP3430_reg_DMA4_CLNK_CTRL29", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB68, "OMAP3430_reg_DMA4_CICR29", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB6C, "OMAP3430_reg_DMA4_CSR29", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB70, "OMAP3430_reg_DMA4_CSDP29", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB74, "OMAP3430_reg_DMA4_CEN29", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB78, "OMAP3430_reg_DMA4_CFN29", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB7C, "OMAP3430_reg_DMA4_CSSA29", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB80, "OMAP3430_reg_DMA4_CDSA29", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB84, "OMAP3430_reg_DMA4_CSEI29", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB88, "OMAP3430_reg_DMA4_CSFI29", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB8C, "OMAP3430_reg_DMA4_CDEI29", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB90, "OMAP3430_reg_DMA4_CDFI29", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB94, "OMAP3430_reg_DMA4_CSAC29", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB98, "OMAP3430_reg_DMA4_CDAC29", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xB9C, "OMAP3430_reg_DMA4_CCEN29", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBA0, "OMAP3430_reg_DMA4_CCFN29", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBA4, "OMAP3430_reg_DMA4_COLOR29", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBC0, "OMAP3430_reg_DMA4_CCR30", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBC4, "OMAP3430_reg_DMA4_CLNK_CTRL30", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBC8, "OMAP3430_reg_DMA4_CICR30", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBCC, "OMAP3430_reg_DMA4_CSR30", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBD0, "OMAP3430_reg_DMA4_CSDP30", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBD4, "OMAP3430_reg_DMA4_CEN30", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBD8, "OMAP3430_reg_DMA4_CFN30", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBDC, "OMAP3430_reg_DMA4_CSSA30", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBE0, "OMAP3430_reg_DMA4_CDSA30", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBE4, "OMAP3430_reg_DMA4_CSEI30", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBE8, "OMAP3430_reg_DMA4_CSFI30", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBEC, "OMAP3430_reg_DMA4_CDEI30", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBF0, "OMAP3430_reg_DMA4_CDFI30", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBF4, "OMAP3430_reg_DMA4_CSAC30", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBF8, "OMAP3430_reg_DMA4_CDAC30", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xBFC, "OMAP3430_reg_DMA4_CCEN30", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC00, "OMAP3430_reg_DMA4_CCFN30", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC04, "OMAP3430_reg_DMA4_COLOR30", "Channel DMA COLOR KEY / SOLID COLOR");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC20, "OMAP3430_reg_DMA4_CCR31", "Channel Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC24, "OMAP3430_reg_DMA4_CLNK_CTRL31", "Channel Link Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC28, "OMAP3430_reg_DMA4_CICR31", "Channel Interrupt Control Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC2C, "OMAP3430_reg_DMA4_CSR31", "Channel Status Register");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC30, "OMAP3430_reg_DMA4_CSDP31", "Channel Source Destination Parameters");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC34, "OMAP3430_reg_DMA4_CEN31", "Channel Element Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC38, "OMAP3430_reg_DMA4_CFN31", "Channel Frame Number");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC3C, "OMAP3430_reg_DMA4_CSSA31", "Channel Source Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC40, "OMAP3430_reg_DMA4_CDSA31", "Channel Destination Start Address");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC44, "OMAP3430_reg_DMA4_CSEI31", "Channel Source Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC48, "OMAP3430_reg_DMA4_CSFI31", "Channel Source Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC4C, "OMAP3430_reg_DMA4_CDEI31", "Channel Destination Element Index (Signed)");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC50, "OMAP3430_reg_DMA4_CDFI31", "Channel Destination Frame Index (Signed) or 16-bit Packet size");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC54, "OMAP3430_reg_DMA4_CSAC31", "Channel Source Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC58, "OMAP3430_reg_DMA4_CDAC31", "Channel Destination Address Value. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC5C, "OMAP3430_reg_DMA4_CCEN31", "Channel Current Transferred Element Number in the current frame. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC60, "OMAP3430_reg_DMA4_CCFN31", "Channel Current Transferred Frame Number in the current transfer. User has to access this register only in 32-bit access. If accessed in 8-bit or 16-bit data may be corrupted");
	CreateDwordRegister(OMAP3430_SDMA_BASE, 0xC64, "OMAP3430_reg_DMA4_COLOR31", "Channel DMA COLOR KEY / SOLID COLOR");
	Message("Added OMAP3430 DMA Module registers\n");
}

// --- Interrupt Controller Module
static INTC_Module(void)
{
	if (!SegCreate(OMAP3430_MPU_INTC_BASE, OMAP3430_MPU_INTC_END, 0x0, 1, 0, 0)) {
		Warning("Can't create MPU INTC registers segment!\n");
		return;
	}
	if (!SegCreate(OMAP3430_MODEM_INTC_BASE, OMAP3430_MODEM_INTC_END, 0x0, 1, 0, 0)) {
		Warning("Can't create MODEM INTC registers segment!\n");
		return;
	}
	SegRename(OMAP3430_MPU_INTC_BASE, "MPU_INTC");
	SegClass(OMAP3430_MPU_INTC_BASE, "REGISTERS");
	SegRename(OMAP3430_MODEM_INTC_BASE, "MODEM_INTC");
	SegClass(OMAP3430_MODEM_INTC_BASE, "REGISTERS");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x0, "OMAP3430_reg_INTCPS_REVISION", "This register contains the IP revision code");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x10, "OMAP3430_reg_INTCPS_SYSCONFIG", "This register controls various parameters of the module interface");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x14, "OMAP3430_reg_INTCPS_SYSSTATUS", "This register provides status information about the module");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x40, "OMAP3430_reg_INTCPS_SIR_IRQ", "This register supplies the currently active IRQ interrupt number");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x44, "OMAP3430_reg_INTCPS_SIR_FIQ", "This register supplies the currently active FIQ interrupt number");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x48, "OMAP3430_reg_INTCPS_CONTROL", "This register contains the new interrupt agreement bits");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x4C, "OMAP3430_reg_INTCPS_PROTECTION", "This register controls protection of the other registers. It can be accessed only in supervisor mode, regardless of the current value of the protection bit");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x50, "OMAP3430_reg_INTCPS_IDLE", "This register controls the functional clock auto-idle and the synchronizer clock auto-gating");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x60, "OMAP3430_reg_INTCPS_IRQ_PRIORITY", "This register supplies the currently active IRQ priority level");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x64, "OMAP3430_reg_INTCPS_FIQ_PRIORITY", "This register supplies the currently active FIQ priority level");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x68, "OMAP3430_reg_INTCPS_THRESHOLD", "This register sets the priority threshold");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x80, "OMAP3430_reg_INTCPS_ITR0", "This register shows the raw interrupt input status before masking");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x84, "OMAP3430_reg_INTCPS_MIR0", "This register contains the interrupt mask");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x88, "OMAP3430_reg_INTCPS_MIR_CLEAR0", "This register is used to clear the interrupt mask bits");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x8C, "OMAP3430_reg_INTCPS_MIR_SET0", "This register is used to set the interrupt mask bits");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x90, "OMAP3430_reg_INTCPS_ISR_SET0", "This register is used to set the software interrupt bits. It is also used to read the currently active software interrupts");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x94, "OMAP3430_reg_INTCPS_ISR_CLEAR0", "This register is used to clear the software interrupt bits");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x98, "OMAP3430_reg_INTCPS_PENDING_IRQ0", "This register contains the IRQ status after masking");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x9C, "OMAP3430_reg_INTCPS_PENDING_FIQ0", "This register contains the FIQ status after masking");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0xA0, "OMAP3430_reg_INTCPS_ITR1", "This register shows the raw interrupt status before masking");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0xA4, "OMAP3430_reg_INTCPS_MIR1", "This register contains the interrupt mask");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0xA8, "OMAP3430_reg_INTCPS_MIR_CLEAR1", "This register is used to clear the interrupt mask bits");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0xAC, "OMAP3430_reg_INTCPS_MIR_SET1", "This register is used to set the interrupt mask bits");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0xB0, "OMAP3430_reg_INTCPS_ISR_SET1", "This register is used to set the software interrupt bits. It is also used to read the currently active software interrupts");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0xB4, "OMAP3430_reg_INTCPS_ISR_CLEAR1", "This register is ised to clear the software interrupt bits");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0xB8, "OMAP3430_reg_INTCPS_PENDING_IRQ1", "This register contains the IRQ status after masking");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0xBC, "OMAP3430_reg_INTCPS_PENDING_FIQ1", "This register contains the FIQ status after masking");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0xC0, "OMAP3430_reg_INTCPS_ITR2", "This register shows the raw interrupt status before masking");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0xC4, "OMAP3430_reg_INTCPS_MIR2", "This register contains the interrupt mask");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0xC8, "OMAP3430_reg_INTCPS_MIR_CLEAR2", "This register is used to clear the interrupt mask bits");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0xCC, "OMAP3430_reg_INTCPS_MIR_SET2", "This register is used to set the interrupt mask bits");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0xD0, "OMAP3430_reg_INTCPS_ISR_SET2", "This register is used to set the software interrupt bits. It is also used to read the currently active software interrupts");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0xD4, "OMAP3430_reg_INTCPS_ISR_CLEAR2", "This register is used to clear the software interrupt bits");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0xD8, "OMAP3430_reg_INTCPS_PENDING_IRQ2", "This register contains the IRQ status after masking");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0xDC, "OMAP3430_reg_INTCPS_PENDING_FIQ2", "This register contains the FIQ status after masking");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x100, "OMAP3430_reg_INTCPS_ILR0", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x104, "OMAP3430_reg_INTCPS_ILR1", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x108, "OMAP3430_reg_INTCPS_ILR2", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x10C, "OMAP3430_reg_INTCPS_ILR3", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x110, "OMAP3430_reg_INTCPS_ILR4", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x114, "OMAP3430_reg_INTCPS_ILR5", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x118, "OMAP3430_reg_INTCPS_ILR6", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x11C, "OMAP3430_reg_INTCPS_ILR7", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x120, "OMAP3430_reg_INTCPS_ILR8", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x124, "OMAP3430_reg_INTCPS_ILR9", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x128, "OMAP3430_reg_INTCPS_ILR10", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x12C, "OMAP3430_reg_INTCPS_ILR11", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x130, "OMAP3430_reg_INTCPS_ILR12", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x134, "OMAP3430_reg_INTCPS_ILR13", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x138, "OMAP3430_reg_INTCPS_ILR14", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x13C, "OMAP3430_reg_INTCPS_ILR15", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x140, "OMAP3430_reg_INTCPS_ILR16", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x144, "OMAP3430_reg_INTCPS_ILR17", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x148, "OMAP3430_reg_INTCPS_ILR18", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x14C, "OMAP3430_reg_INTCPS_ILR19", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x150, "OMAP3430_reg_INTCPS_ILR20", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x154, "OMAP3430_reg_INTCPS_ILR21", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x158, "OMAP3430_reg_INTCPS_ILR22", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x15C, "OMAP3430_reg_INTCPS_ILR23", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x160, "OMAP3430_reg_INTCPS_ILR24", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x164, "OMAP3430_reg_INTCPS_ILR25", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x168, "OMAP3430_reg_INTCPS_ILR26", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x16C, "OMAP3430_reg_INTCPS_ILR27", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x170, "OMAP3430_reg_INTCPS_ILR28", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x174, "OMAP3430_reg_INTCPS_ILR29", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x178, "OMAP3430_reg_INTCPS_ILR30", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x17C, "OMAP3430_reg_INTCPS_ILR31", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x180, "OMAP3430_reg_INTCPS_ILR32", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x184, "OMAP3430_reg_INTCPS_ILR33", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x188, "OMAP3430_reg_INTCPS_ILR34", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x18C, "OMAP3430_reg_INTCPS_ILR35", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x190, "OMAP3430_reg_INTCPS_ILR36", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x194, "OMAP3430_reg_INTCPS_ILR37", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x198, "OMAP3430_reg_INTCPS_ILR38", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x19C, "OMAP3430_reg_INTCPS_ILR39", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1A0, "OMAP3430_reg_INTCPS_ILR40", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1A4, "OMAP3430_reg_INTCPS_ILR41", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1A8, "OMAP3430_reg_INTCPS_ILR42", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1AC, "OMAP3430_reg_INTCPS_ILR43", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1B0, "OMAP3430_reg_INTCPS_ILR44", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1B4, "OMAP3430_reg_INTCPS_ILR45", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1B8, "OMAP3430_reg_INTCPS_ILR46", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1BC, "OMAP3430_reg_INTCPS_ILR47", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1C0, "OMAP3430_reg_INTCPS_ILR48", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1C4, "OMAP3430_reg_INTCPS_ILR49", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1C8, "OMAP3430_reg_INTCPS_ILR50", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1CC, "OMAP3430_reg_INTCPS_ILR51", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1D0, "OMAP3430_reg_INTCPS_ILR52", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1D4, "OMAP3430_reg_INTCPS_ILR53", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1D8, "OMAP3430_reg_INTCPS_ILR54", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1DC, "OMAP3430_reg_INTCPS_ILR55", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1E0, "OMAP3430_reg_INTCPS_ILR56", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1E4, "OMAP3430_reg_INTCPS_ILR57", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1E8, "OMAP3430_reg_INTCPS_ILR58", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1EC, "OMAP3430_reg_INTCPS_ILR59", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1F0, "OMAP3430_reg_INTCPS_ILR60", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1F4, "OMAP3430_reg_INTCPS_ILR61", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1F8, "OMAP3430_reg_INTCPS_ILR62", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x1FC, "OMAP3430_reg_INTCPS_ILR63", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x200, "OMAP3430_reg_INTCPS_ILR64", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x204, "OMAP3430_reg_INTCPS_ILR65", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x208, "OMAP3430_reg_INTCPS_ILR66", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x20C, "OMAP3430_reg_INTCPS_ILR67", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x210, "OMAP3430_reg_INTCPS_ILR68", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x214, "OMAP3430_reg_INTCPS_ILR69", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x218, "OMAP3430_reg_INTCPS_ILR70", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x21C, "OMAP3430_reg_INTCPS_ILR71", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x220, "OMAP3430_reg_INTCPS_ILR72", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x224, "OMAP3430_reg_INTCPS_ILR73", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x228, "OMAP3430_reg_INTCPS_ILR74", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x22C, "OMAP3430_reg_INTCPS_ILR75", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x230, "OMAP3430_reg_INTCPS_ILR76", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x234, "OMAP3430_reg_INTCPS_ILR77", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x238, "OMAP3430_reg_INTCPS_ILR78", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x23C, "OMAP3430_reg_INTCPS_ILR79", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x240, "OMAP3430_reg_INTCPS_ILR80", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x244, "OMAP3430_reg_INTCPS_ILR81", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x248, "OMAP3430_reg_INTCPS_ILR82", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x24C, "OMAP3430_reg_INTCPS_ILR83", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x250, "OMAP3430_reg_INTCPS_ILR84", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x254, "OMAP3430_reg_INTCPS_ILR85", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x258, "OMAP3430_reg_INTCPS_ILR86", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x25C, "OMAP3430_reg_INTCPS_ILR87", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x260, "OMAP3430_reg_INTCPS_ILR88", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x264, "OMAP3430_reg_INTCPS_ILR89", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x268, "OMAP3430_reg_INTCPS_ILR90", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x26C, "OMAP3430_reg_INTCPS_ILR91", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x270, "OMAP3430_reg_INTCPS_ILR92", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x274, "OMAP3430_reg_INTCPS_ILR93", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x278, "OMAP3430_reg_INTCPS_ILR94", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MPU_INTC_BASE, 0x27C, "OMAP3430_reg_INTCPS_ILR95", "This register contain the priority for the interrupts and the FIQ/IRQ steering");
	CreateDwordRegister(OMAP3430_MODEM_INTC_BASE, 0x10, "OMAP3430_reg_INTC_SYSCONFIG", "This register controls various parameters of the module interface");
	CreateDwordRegister(OMAP3430_MODEM_INTC_BASE, 0x50, "OMAP3430_reg_INTC_IDLE", "This register controls the functional clock auto-idle and the synchronizer clock auto-gating");
	Message("Added OMAP3430 Interrupt Controller Module registers\n");
}

// --- Memory Subsystem Module
static MEMORY_Module(void)
{
	if (!SegCreate(OMAP3430_GPMC_BASE, OMAP3430_GPMC_END, 0x0, 1, 0, 0)) {
		Warning("Can't create GPMC registers segment!\n");
		return;
	}
	if (!SegCreate(OMAP3430_SMS_BASE, OMAP3430_SMS_END, 0x0, 1, 0, 0)) {
		Warning("Can't create SMS registers segment!\n");
		return;
	}
	if (!SegCreate(OMAP3430_SDRC_BASE, OMAP3430_SDRC_END, 0x0, 1, 0, 0)) {
		Warning("Can't create SDRC registers segment!\n");
		return;
	}
	SegRename(OMAP3430_GPMC_BASE, "GPMC");
	SegRename(OMAP3430_SMS_BASE, "SMS");
	SegRename(OMAP3430_SDRC_BASE, "SDRC");
	SegClass(OMAP3430_GPMC_BASE, "REGISTERS");
	SegClass(OMAP3430_SMS_BASE, "REGISTERS");
	SegClass(OMAP3430_SDRC_BASE, "REGISTERS");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x0, "OMAP3430_reg_GPMC_REVISION", "This register contains the IP revision code");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x10, "OMAP3430_reg_GPMC_SYSCONFIG", "This register controls the various parameters of the Interconnect");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x14, "OMAP3430_reg_GPMC_SYSSTATUS", "This register provides status information about the module, excluding the interrupt status information");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x18, "OMAP3430_reg_GPMC_IRQSTATUS", "This interrupt status register regroups all the status of the module internal events that can generate an interrupt");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x1C, "OMAP3430_reg_GPMC_IRQENABLE", "This interrupt enable register allows to mask/unmask the module internal sources of interrupt, on a event-by-event basis");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x40, "OMAP3430_reg_GPMC_TIMEOUT_CONTROL", "This register allows the user to set the start value of the timeout counter");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x44, "OMAP3430_reg_GPMC_ERR_ADDRESS", "This register stores the address of the illegal access when an error occurs");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x48, "OMAP3430_reg_GPMC_ERR_TYPE", "This register stores the type of error when an error occurs");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x50, "OMAP3430_reg_GPMC_CONFIG", "The configuration register allows global configuration of the GPMC");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x54, "OMAP3430_reg_GPMC_STATUS", "The status register provides global status bits of the GPMC");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x60, "OMAP3430_reg_GPMC_CONFIG1_0", "The configuration register 1 sets signal control parameters per chip-select");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x64, "OMAP3430_reg_GPMC_CONFIG2_0", "CS signal timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x68, "OMAP3430_reg_GPMC_CONFIG3_0", "nADV signal timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x6C, "OMAP3430_reg_GPMC_CONFIG4_0", "nWE and nOE signals timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x70, "OMAP3430_reg_GPMC_CONFIG5_0", "RdAccessTime and CycleTime timing parameters configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x74, "OMAP3430_reg_GPMC_CONFIG6_0", "WrAccessTime, WrDataOnADmuxBus, Cycle2Cycle and BusTurnAround parameters configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x78, "OMAP3430_reg_GPMC_CONFIG7_0", "CS address mapping configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x7C, "OMAP3430_reg_GPMC_NAND_COMMAND_0", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x80, "OMAP3430_reg_GPMC_NAND_ADDRESS_0", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x84, "OMAP3430_reg_GPMC_NAND_DATA_0", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x60, "OMAP3430_reg_GPMC_CONFIG1_1", "The configuration register 1 sets signal control parameters per chip-select");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x64, "OMAP3430_reg_GPMC_CONFIG2_1", "CS signal timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x68, "OMAP3430_reg_GPMC_CONFIG3_1", "nADV signal timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x6C, "OMAP3430_reg_GPMC_CONFIG4_1", "nWE and nOE signals timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x70, "OMAP3430_reg_GPMC_CONFIG5_1", "RdAccessTime and CycleTime timing parameters configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x74, "OMAP3430_reg_GPMC_CONFIG6_1", "WrAccessTime, WrDataOnADmuxBus, Cycle2Cycle and BusTurnAround parameters configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x78, "OMAP3430_reg_GPMC_CONFIG7_1", "CS address mapping configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x7C, "OMAP3430_reg_GPMC_NAND_COMMAND_1", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x80, "OMAP3430_reg_GPMC_NAND_ADDRESS_1", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x84, "OMAP3430_reg_GPMC_NAND_DATA_1", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x60, "OMAP3430_reg_GPMC_CONFIG1_2", "The configuration register 1 sets signal control parameters per chip-select");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x64, "OMAP3430_reg_GPMC_CONFIG2_2", "CS signal timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x68, "OMAP3430_reg_GPMC_CONFIG3_2", "nADV signal timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x6C, "OMAP3430_reg_GPMC_CONFIG4_2", "nWE and nOE signals timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x70, "OMAP3430_reg_GPMC_CONFIG5_2", "RdAccessTime and CycleTime timing parameters configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x74, "OMAP3430_reg_GPMC_CONFIG6_2", "WrAccessTime, WrDataOnADmuxBus, Cycle2Cycle and BusTurnAround parameters configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x78, "OMAP3430_reg_GPMC_CONFIG7_2", "CS address mapping configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x7C, "OMAP3430_reg_GPMC_NAND_COMMAND_2", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x80, "OMAP3430_reg_GPMC_NAND_ADDRESS_2", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x84, "OMAP3430_reg_GPMC_NAND_DATA_2", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x60, "OMAP3430_reg_GPMC_CONFIG1_3", "The configuration register 1 sets signal control parameters per chip-select");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x64, "OMAP3430_reg_GPMC_CONFIG2_3", "CS signal timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x68, "OMAP3430_reg_GPMC_CONFIG3_3", "nADV signal timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x6C, "OMAP3430_reg_GPMC_CONFIG4_3", "nWE and nOE signals timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x70, "OMAP3430_reg_GPMC_CONFIG5_3", "RdAccessTime and CycleTime timing parameters configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x74, "OMAP3430_reg_GPMC_CONFIG6_3", "WrAccessTime, WrDataOnADmuxBus, Cycle2Cycle and BusTurnAround parameters configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x78, "OMAP3430_reg_GPMC_CONFIG7_3", "CS address mapping configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x7C, "OMAP3430_reg_GPMC_NAND_COMMAND_3", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x80, "OMAP3430_reg_GPMC_NAND_ADDRESS_3", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x84, "OMAP3430_reg_GPMC_NAND_DATA_3", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x60, "OMAP3430_reg_GPMC_CONFIG1_4", "The configuration register 1 sets signal control parameters per chip-select");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x64, "OMAP3430_reg_GPMC_CONFIG2_4", "CS signal timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x68, "OMAP3430_reg_GPMC_CONFIG3_4", "nADV signal timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x6C, "OMAP3430_reg_GPMC_CONFIG4_4", "nWE and nOE signals timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x70, "OMAP3430_reg_GPMC_CONFIG5_4", "RdAccessTime and CycleTime timing parameters configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x74, "OMAP3430_reg_GPMC_CONFIG6_4", "WrAccessTime, WrDataOnADmuxBus, Cycle2Cycle and BusTurnAround parameters configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x78, "OMAP3430_reg_GPMC_CONFIG7_4", "CS address mapping configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x7C, "OMAP3430_reg_GPMC_NAND_COMMAND_4", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x80, "OMAP3430_reg_GPMC_NAND_ADDRESS_4", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x84, "OMAP3430_reg_GPMC_NAND_DATA_4", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x60, "OMAP3430_reg_GPMC_CONFIG1_5", "The configuration register 1 sets signal control parameters per chip-select");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x64, "OMAP3430_reg_GPMC_CONFIG2_5", "CS signal timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x68, "OMAP3430_reg_GPMC_CONFIG3_5", "nADV signal timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x6C, "OMAP3430_reg_GPMC_CONFIG4_5", "nWE and nOE signals timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x70, "OMAP3430_reg_GPMC_CONFIG5_5", "RdAccessTime and CycleTime timing parameters configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x74, "OMAP3430_reg_GPMC_CONFIG6_5", "WrAccessTime, WrDataOnADmuxBus, Cycle2Cycle and BusTurnAround parameters configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x78, "OMAP3430_reg_GPMC_CONFIG7_5", "CS address mapping configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x7C, "OMAP3430_reg_GPMC_NAND_COMMAND_5", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x80, "OMAP3430_reg_GPMC_NAND_ADDRESS_5", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x84, "OMAP3430_reg_GPMC_NAND_DATA_5", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x60, "OMAP3430_reg_GPMC_CONFIG1_6", "The configuration register 1 sets signal control parameters per chip-select");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x64, "OMAP3430_reg_GPMC_CONFIG2_6", "CS signal timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x68, "OMAP3430_reg_GPMC_CONFIG3_6", "nADV signal timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x6C, "OMAP3430_reg_GPMC_CONFIG4_6", "nWE and nOE signals timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x70, "OMAP3430_reg_GPMC_CONFIG5_6", "RdAccessTime and CycleTime timing parameters configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x74, "OMAP3430_reg_GPMC_CONFIG6_6", "WrAccessTime, WrDataOnADmuxBus, Cycle2Cycle and BusTurnAround parameters configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x78, "OMAP3430_reg_GPMC_CONFIG7_6", "CS address mapping configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x7C, "OMAP3430_reg_GPMC_NAND_COMMAND_6", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x80, "OMAP3430_reg_GPMC_NAND_ADDRESS_6", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x84, "OMAP3430_reg_GPMC_NAND_DATA_6", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x60, "OMAP3430_reg_GPMC_CONFIG1_7", "The configuration register 1 sets signal control parameters per chip-select");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x64, "OMAP3430_reg_GPMC_CONFIG2_7", "CS signal timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x68, "OMAP3430_reg_GPMC_CONFIG3_7", "nADV signal timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x6C, "OMAP3430_reg_GPMC_CONFIG4_7", "nWE and nOE signals timing parameter configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x70, "OMAP3430_reg_GPMC_CONFIG5_7", "RdAccessTime and CycleTime timing parameters configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x74, "OMAP3430_reg_GPMC_CONFIG6_7", "WrAccessTime, WrDataOnADmuxBus, Cycle2Cycle and BusTurnAround parameters configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x78, "OMAP3430_reg_GPMC_CONFIG7_7", "CS address mapping configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x7C, "OMAP3430_reg_GPMC_NAND_COMMAND_7", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x80, "OMAP3430_reg_GPMC_NAND_ADDRESS_7", "This register is not a true register, just an address location");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x84, "OMAP3430_reg_GPMC_NAND_DATA_7", "This register is not a true register, just an address location");

	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x1E0, "OMAP3430_reg_GPMC_PREFETCH_CONFIG1", "Prefetch engine configuration 1");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x1E4, "OMAP3430_reg_GPMC_PREFETCH_CONFIG2", "Prefetch engine configuration 2");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x1EC, "OMAP3430_reg_GPMC_PREFETCH_CONTROL", "Prefetch engine control");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x1F0, "OMAP3430_reg_GPMC_PREFETCH_STATUS", "Prefetch engine status");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x1F4, "OMAP3430_reg_GPMC_ECC_CONFIG", "ECC configuration");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x1F8, "OMAP3430_reg_GPMC_ECC_CONTROL", "ECC control");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x1FC, "OMAP3430_reg_GPMC_ECC_SIZE_CONFIG", "ECC size");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x200, "OMAP3430_reg_GPMC_ECC1_RESULT", "ECC result register");

	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x240, "OMAP3430_reg_GPMC_BCH_RESULT0_0", "BCH ECC result (bits 0 to 31)");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x244, "OMAP3430_reg_GPMC_BCH_RESULT1_0", "BCH ECC result (bits 32 to 63)");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x248, "OMAP3430_reg_GPMC_BCH_RESULT2_0", "BCH ECC result (bits 64 to 95)");
	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x24C, "OMAP3430_reg_GPMC_BCH_RESULT3_0", "BCH ECC result (bits 96 to 103)");

	CreateDwordRegister(OMAP3430_GPMC_BASE, 0x2D0, "OMAP3430_reg_GPMC_BCH_SWDATA", "This register is used to directly pass data to the BCH ECC calculator without accessing the actual NAND flash interface");
	Message("Added OMAP3430 Memory Subsystem Module registers\n");
}

// --- General Purpose I/O Module
static GPIO_Module(void)
{
	if (!SegCreate(OMAP3430_GPIO1_BASE, OMAP3430_GPIO1_END, 0x0, 1, 0, 0)) {
		Warning("Can't create GPIO registers segment!\n");
		return;
	}
	SegRename(OMAP3430_GPIO1_BASE, "GPIO1");
	SegClass(OMAP3430_GPIO1_BASE, "REGISTERS");
	CreateDwordRegister(OMAP3430_GPIO1_BASE, 0x0, "OMAP3430_reg_GPIO1_REVISION", "This register contains the IP revision code.");
	Message("Added OMAP3430 GPIO Module registers\n");
}


