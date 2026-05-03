/*
 * stm32f401xx.h
 *
 *  Created on: Feb 20, 2026
 *      Author: nilaNila
 */

#ifndef STM32F401XX_H_
#define STM32F401XX_H_
#include <stdint.h>

#define __vo     volatile
/****Processor Definition**********/
/*****Interrupt SET ENABLE Register
 * ARM CORTEX MX Processor NVIC  ISER Register Address**
 */
#define NVIC_ISER0           ((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1           ((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2           ((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3           ((__vo uint32_t*)0xE000E10C)
/**
 * Interrupt CLEAR ENABLE Register
 * ARM CORTEX MX Processor NVIC  ICER Register Address
 */
#define NVIC_ICER0           ((__vo uint32_t*)0XE000E180)
#define NVIC_ICER1           ((__vo uint32_t*)0XE000E184)
#define NVIC_ICER2           ((__vo uint32_t*)0XE000E188)
#define NVIC_ICER3           ((__vo uint32_t*)0XE000E18C)

/**
 *  Interrupt PriorityNVIC_IPRx Register
 * ARM CORTEX MX Processor NVIC   Register Address
 */

#define NVIC_PR_BASEADDR      ((__vo uint32_t*)0XE000E400)

/* memory Base addresses
 *
 */
#define FLASH_BASEADDR                   0x08000000U        //Data sheet page 51
#define ROM_BASEADDR                     0x1FFF0000U    //system memory
#define SRAM_BASEADDR                    0x20000000U    //one SRAM




/*PERIPHERAL BUS BASE ADDRESS  */

#define APB1_PERIBASEADDR                   0x40000000U
#define APB2_PERIBASEADDR                   0x40010000U
#define AHB1_PERIBASEADDR                   0x40020000U
#define AHB2_PERIBASEADDR                   0x50000000U

/* Base address of peripherals in 	AHB1 ***
 * Reference manual page No:38 */

#define GPIOA_BASEADDR      (AHB1_PERIBASEADDR + 0X0000)//
#define GPIOB_BASEADDR      (AHB1_PERIBASEADDR + 0X0400)
#define GPIOC_BASEADDR      (AHB1_PERIBASEADDR + 0X0800)
#define GPIOD_BASEADDR      (AHB1_PERIBASEADDR + 0X0C00)
#define GPIOE_BASEADDR      (AHB1_PERIBASEADDR + 0X1000)
#define GPIOH_BASEADDR      (AHB1_PERIBASEADDR + 0X1C00)

#define CRC_BASEADDR          (AHB1_PERIBASEADDR + 0X3000)
#define RCC_BASEADDR          (AHB1_PERIBASEADDR + 0X3800)
#define FLASH_IF_BASEADDR     (AHB1_PERIBASEADDR + 0X3C00)
#define DMA1_BASEADDR         (AHB1_PERIBASEADDR + 0X6000)
#define DMA2_BASEADDR         (AHB1_PERIBASEADDR + 0X6400)

/* Base address of peripherals in 	AHB2 */
/***Reference manual page No:38 */

#define USB_OTG_FS        (AHB2_PERIBASEADDR + 0X0000)

/* Base address of peripherals in 	APB1 */
/*Reference manual page No:39 */

/*TIMERS  IN APB1    */

#define TIMER2_BASEADDR         (APB1_PERIBASEADDR + 0X0000)
#define TIMER3_BASEADDR         (APB1_PERIBASEADDR + 0X0400)
#define TIMER4_BASEADDR         (APB1_PERIBASEADDR + 0X0800)
#define TIMER5_BASEADDR         (APB1_PERIBASEADDR + 0X0C00)

/*   OTHER PERIPHERALS IN APB1  */
#define RTC_BKP_REG            (APB1_PERIBASEADDR + 0X2800)
#define WWDG_BASEADDR          (APB1_PERIBASEADDR + 0X2C00)
#define IWDG_BASEADDR          (APB1_PERIBASEADDR + 0X3000)
#define I2S2EXT_BASEADDR       (APB1_PERIBASEADDR + 0X3400)

/* SPI IN APB1  */
#define SPI2_BASEADDR     (APB1_PERIBASEADDR + 0X3800)
#define SPI3_BASEADDR     (APB1_PERIBASEADDR + 0X3C00)

#define I2S3EXT_BASEADDR       (APB1_PERIBASEADDR + 0X4000)

#define USART2_BASEADDR        (APB1_PERIBASEADDR + 0X4400)

/*  I2C IN APB1  */
#define I2C1_BASEADDR          (APB1_PERIBASEADDR + 0X5400)
#define I2C2_BASEADDR          (APB1_PERIBASEADDR + 0X5800)
#define I2C3_BASEADDR          (APB1_PERIBASEADDR + 0X5C00)

#define PWR_BASEADDR           (APB1_PERIBASEADDR + 0X7000)


/* Base address of peripherals in 	APB2 */
/*Reference manual page No:39 */

/*TIMERS  IN APB2    */


#define TIMER1_BASEADDR         (APB2_PERIBASEADDR + 0X0000)
#define TIMER9_BASEADDR         (APB2_PERIBASEADDR + 0X4000)
#define TIMER10_BASEADDR         (APB2_PERIBASEADDR + 0X4400)
#define TIMER11_BASEADDR         (APB2_PERIBASEADDR + 0X4800)

/* USART IN APB2  ***/

#define USART1_BASEADDR        (APB2_PERIBASEADDR + 0X1000)
#define USART6_BASEADDR        (APB2_PERIBASEADDR + 0X1400)


#define ADC1_BASEADDR         (APB2_PERIBASEADDR + 0X2000)

#define SDIO_BASEADDR         (APB2_PERIBASEADDR + 0X2C00)


/* SPI IN APB2  */
#define SPI1_BASEADDR       (APB2_PERIBASEADDR + 0X3000)
#define SPI4_BASEADDR       (APB2_PERIBASEADDR + 0X3400)

//SYSCFG and EXTI  are in APB2
#define SYSCFG_BASEADDR         (APB2_PERIBASEADDR + 0X3800)
#define EXTI_BASEADDR           (APB2_PERIBASEADDR + 0X3C00)

/**
 * Macros for PORT CODE(values 0-7) FOR THE given GPIO PORT base address
 */

#define GPIO_BASEADDR_TO_CODE(x)         ((x==GPIOA)?0:\
				                          (x==GPIOB)?1:\
				                          (x==GPIOC)?2:\
				                          (x==GPIOD)?3:\
				                          (x==GPIOE)?4:\
				                          (x==GPIOH)?7:0)


/*GPIO Register definition
 *
 */
typedef struct
{

__vo uint32_t MODER;
__vo uint32_t OTYPER;
__vo uint32_t OSPEEDR;
__vo uint32_t PUPDR;
__vo uint32_t IDR ;
__vo uint32_t ODR ;
__vo uint32_t BSRR ;
__vo uint32_t LCKR ;
__vo uint32_t AFR[2];
}GPIO_RegDef;

/*RCC Register definition
 * Reference manual Page no 137*/

typedef struct
{

__vo uint32_t CR;
__vo uint32_t PLLCFGR;
__vo uint32_t CFGR;
__vo uint32_t CIR;
__vo uint32_t AHB1RSTR;
__vo uint32_t AHB2RSTR ;
     uint32_t Reserved[2] ;
__vo  uint32_t APB1RSTR ;
__vo uint32_t APB2RSTR;
     uint32_t Reserved1[2];
__vo uint32_t AHB1ENR;
__vo uint32_t AHB2ENR;
     uint32_t Reserved2[2];
__vo uint32_t APB1ENR;
__vo uint32_t APB2ENR;
     uint32_t Reserved3[2];
__vo uint32_t AHB1LPENR;
__vo uint32_t AHB2LPENR;
     uint32_t Reserved4[2];
__vo uint32_t APB1LPENR ;

__vo uint32_t APB2LPENR;
     uint32_t Reserved5[2];
__vo uint32_t BDCR ;

__vo uint32_t CSR;
     uint32_t Reserved6[2];
__vo uint32_t SSCGR ;

__vo uint32_t PLLI2SCFGR ;
__vo uint32_t DCKCFGR ;



}RCC_RegDef;



/********Peripheral register definition structure for  EXTI*********/

typedef struct
{
    __vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;

}EXTI_RegDef;

/****  for SYSCONFIG   ****/
typedef struct
{
    __vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];//To select port and pin number which is in EXTICR1,2,3,4
   uint32_t RESERVED1[2];
	__vo uint32_t CMPCR;
}SYSCFG_RegDef;

//NVIC REG Definition
/*
 * I2C  Register definition*/
typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t OAR1;
	__vo uint32_t OAR2;
	__vo uint32_t  DR;
	__vo uint32_t  SR1;
	__vo uint32_t  SR2;
	__vo uint32_t  CCR;
	__vo uint32_t TRISE;
	__vo uint32_t FLTR;
}I2C_RegDef;


/*SPI Register definition*/
typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t CRCPR;
	__vo uint32_t  RXCRCPR;
	__vo uint32_t  TXCRCPR;
	__vo uint32_t  I2SCFGR;
	__vo uint32_t  I2SPR;
}SPI_RegDef;

/*USART Register definition*/
typedef struct
{
		__vo uint32_t SR;
		__vo uint32_t DR;
		__vo uint32_t BRR;
		__vo uint32_t  CR1;
		__vo uint32_t  CR2;
		__vo uint32_t  CR3;
		__vo uint32_t  GTPR;

}USART_RegDef;



#define IRQ_NO_EXTI0        6
#define IRQ_NO_EXTI1        7
#define IRQ_NO_EXTI2        8
#define IRQ_NO_EXTI3        9
#define IRQ_NO_EXTI4        10
#define IRQ_NO_EXTI5_9      23
#define IRQ_NO_EXTI10_15    40
//GPIO

#define GPIOA      ((GPIO_RegDef *)GPIOA_BASEADDR)
#define GPIOB      ((GPIO_RegDef *)GPIOB_BASEADDR)
#define GPIOC      ((GPIO_RegDef *)GPIOC_BASEADDR)
#define GPIOD      ((GPIO_RegDef *)GPIOD_BASEADDR)
#define GPIOE      ((GPIO_RegDef *)GPIOE_BASEADDR)
#define GPIOH      ((GPIO_RegDef *)GPIOH_BASEADDR)


//SPI
#define SPI1   ((SPI_RegDef *)SPI1_BASEADDR)
#define SPI2   ((SPI_RegDef *)SPI2_BASEADDR)
#define SPI3   ((SPI_RegDef *)SPI3_BASEADDR)
#define SPI4   ((SPI_RegDef *)SPI4_BASEADDR)


//I2C


#define I2C1      ((I2C_RegDef *)I2C1_BASEADDR )
#define I2C2      ((I2C_RegDef *)I2C2_BASEADDR )
#define I2C3      ((I2C_RegDef *)I2C3_BASEADDR )


//USART
#define USART1      ((USART_RegDef *)USART1_BASEADDR )
#define USART2      ((USART_RegDef *)USART2_BASEADDR )
#define USART6      ((USART_RegDef *)USART6_BASEADDR )

/*  CLOCK enable
*****RCC  ***/
#define RCC      ((RCC_RegDef *)RCC_BASEADDR)
/* EXTI  ***/
#define EXTI     ((EXTI_RegDef *)EXTI_BASEADDR)   //In APB2 BUS
//SYSCONFIG  ***/

#define SYSCFG   ((SYSCFG_RegDef *)SYSCFG_BASEADDR)   //In APB2 BUS
/*  Enable macros*** Reference manual page no:118***/

//Port Enable
#define GPIOA_CLK_EN()      (RCC->AHB1ENR|=(1<<0))
#define GPIOB_CLK_EN()      (RCC->AHB1ENR|=(1<<1))
#define GPIOC_CLK_EN()      (RCC->AHB1ENR|=(1<<2))
#define GPIOD_CLK_EN()      (RCC->AHB1ENR|=(1<<3))
#define GPIOE_CLK_EN()      (RCC->AHB1ENR|=(1<<4))
#define GPIOH_CLK_EN()      (RCC->AHB1ENR|=(1<<7))

//I2C  Enable macros

#define I2C1_CLK_EN()      (RCC->APB1ENR|=(1<<21))
#define I2C2_CLK_EN()      (RCC->APB1ENR|=(1<<22))
#define I2C3_CLK_EN()      (RCC->APB1ENR|=(1<<23))

//spi Enable Macros
#define SPI1_CLK_EN()      (RCC->APB2ENR|=(1<<12))
#define SPI2_CLK_EN()      (RCC->APB1ENR|=(1<<14))
#define SPI3_CLK_EN()      (RCC->APB1ENR|=(1<<15))
#define SPI4_CLK_EN()      (RCC->APB2ENR|=(1<<13))

//USART Enable Macros

#define USART1_CLK_EN()    (RCC->APB2ENR|=(1<<4))
#define USART2_CLK_EN()    (RCC->APB1ENR|=(1<<17))
#define USART6_CLK_EN()    (RCC->APB2ENR|=(1<<5))
//SYSCONFIG Enable Macros
#define SYSCFG_CLK_EN()  (RCC->APB2ENR|=(1<<14))

/*  Disable macros****REFERENCE MANUAL PAGE 118
 *
 * PORT Disable macros*/
#define GPIOA_CLK_DIS()      (RCC->AHB1ENR&=~(1<<0))
#define GPIOB_CLK_DIS()      (RCC->AHB1ENR&=~(1<<1))
#define GPIOC_CLK_DIS()      (RCC->AHB1ENR&=~(1<<2))
#define GPIOD_CLK_DIS()      (RCC->AHB1ENR&=~(1<<3))
#define GPIOE_CLK_DIS()      (RCC->AHB1ENR&=~(1<<4))
#define GPIOH_CLK_DIS()      (RCC->AHB1ENR&=~(1<<7))

//I2C Disable macros
#define I2C1_CLK_DIS()      (RCC->APB1ENR&=~(1<<21))
#define I2C2_CLK_DIS()      (RCC->APB1ENR&=~(1<<22))
#define I2C3_CLK_DIS()      (RCC->APB1ENR&=~(1<<23))
//SPI Disable macros
#define SPI1_CLK_DIS()      (RCC->APB2ENR&=~(1<<12))
#define SPI2_CLK_DIS()      (RCC->APB1ENR&=~(1<<14))
#define SPI3_CLK_DIS()      (RCC->APB1ENR&=~(1<<15))
#define SPI4_CLK_DIS()      (RCC->APB2ENR&=~(1<<13))

//USART Disable macros PAGE
#define USART1_CLK_DIS()    (RCC->APB2ENR&=~(1<<4))
#define USART2_CLK_DIS()    (RCC->APB1ENR&=~(1<<17))
#define USART6_CLK_DIS()    (RCC->APB2ENR&=~(1<<5))

//RESET MACROS Page no:112 of reference manual
/****GPIO RESET macros***/
#define GPIOA_CLK_RST()     (RCC->AHB1RSTR|=(1<<0))  //
#define GPIOB_CLK_RST()     (RCC->AHB1RSTR|=(1<<1))
#define GPIOC_CLK_RST()     (RCC->AHB1RSTR|=(1<<2))
#define GPIOD_CLK_RST()     (RCC->AHB1RSTR|=(1<<3))
#define GPIOE_CLK_RST()     (RCC->AHB1RSTR|=(1<<4))
#define GPIOH_CLK_RST()     (RCC->AHB1RSTR|=(1<<7))


//clock reset for I2C AND SPI


#define I2C1_CLK_RST()       (RCC->APB1RSTR|=(1<<21))
#define I2C2_CLK_RST()       (RCC->APB1RSTR|=(1<<22))
#define I2C3_CLK_RST()       (RCC->APB1RSTR|=(1<<23))

#define SPI2_CLK_RST()       (RCC->APB1RSTR|=(1<<14))
#define SPI3_CLK_RST()       (RCC->APB1RSTR|=(1<<15))

#define SPI1_CLK_RST()       (RCC->APB2RSTR|=(1<<12))
#define SPI4_CLK_RST()       (RCC->APB2RSTR|=(1<<13))


#define ENABLE            1
#define DISABLE           0
#define SET               ENABLE
#define RESET             DISABLE

#define FLAG_SET          SET
#define FLAG_RESET        RESET

// FOR bit position in CR1 Register
#define SPI_CR1_CPHA        0
#define SPI_CR1_CPOL        1
#define SPI_CR1_MSTR        2
#define SPI_CR1_BR          3
#define SPI_CR1_SPE         6
#define SPI_CR1_LSBFIRST    7
#define SPI_CR1_SSI         8
#define SPI_CR1_SSM         9
#define SPI_CR1_RXONLY      10
#define SPI_CR1_DFF         11
#define SPI_CR1_CRCNEXT     12
#define SPI_CR1_CRCEN       13
#define SPI_CR1_BIDIOE      14
#define SPI_CR1_BIDIMODE    15

/*  Bit position for CR2 Register
 *
 */

#define SPI_CR2_RXDMAEN         0
#define SPI_CR2_TXDMAEN         1
#define SPI_CR2_SSOE            2
#define SPI_CR2_FRF             4
#define SPI_CR2_ERRIE           5
#define SPI_CR2_RXNEIE          6
#define SPI_CR2_TXEIE           7

/*Bit position definition for SPI SR Register
 *
 */
#define SPI_SR_RXNE              0
#define SPI_SR_TXE               1
#define SPI_SR_CHSIDE            2
#define SPI_SR_UDR               3
#define SPI_SR_CRCERR            4
#define SPI_SR_MODF              5
#define SPI_SR_OVR               6
#define SPI_SR_BSY               7
#define SPI_SR_FRE               8
/*
 * Bit position definition for I2C CR1 Register
 */
#define I2C_CR1_PE                0
#define I2C_CR1_NOSTRETCH         7
#define I2C_CR1_START             8
#define I2C_CR1_STOP              9
#define I2C_CR1_ACK               10
#define I2C_CR1_SWRST             15

/**
 * Bit position definition for I2C CR2 Register
 */
#define I2C_CR2_FREQ                0
#define I2C_CR2_ITERREN             8
#define I2C_CR2_ITEVTEN             9
#define I2C_CR2_ITBUFEN             10

/*
 * bit position definiion of I2C SR1 Register
 */
#define I2C_SR1_SB                  0
#define I2C_SR1_ADDR                1
#define I2C_SR1_BTF                 2
#define I2C_SR1_ADD10               3
#define I2C_SR1_STOPF               4
#define I2C_SR1_RXNE                6
#define I2C_SR1_TXE                 7

/*
 * Bit position definition for I2C OAR1 Register
 */
#define I2C_OAR1_ADD0                0
#define I2C_OAR1_ADD1                1
#define I2C_OAR1_ADD8                8
#define I2C_OAR1_ADD9                9
#define I2C_OAR1_BIT14               14
#define I2C_OAR1_ADDMODE             15

/*
 * Bit position definition for I2C OAR2 Register
 */
#define I2C_OAR2_ENDUAL                0
#define I2C_OAR2_ADD2                  1

#include "stm32f401xx_gpio_driver.h"
#include "stm32f401xx_spi_driver.h"
#include "stm32f401xx_i2c_driver.h"


#endif /* STM32F401XX_H_ */
