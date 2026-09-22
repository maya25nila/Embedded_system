#define F_CPU 16000000UL

#include <avr/io.h>
#include "i2c.h"

/*
 * ATmega328P I2C/TWI
 *
 * SDA = PC4
 * SCL = PC5
 *
 * CPU clock = 16 MHz
 * I2C clock = 100 kHz
 */

void i2c_init(void)
{
    /* 
    *set prescalar
    *set bound rate
    *Enable TWI

    
    Set SCL frequency = 100 kHz
     
       SCL = F_CPU / (16 + 2*TWBR*Prescaler)

       Prescaler = 1
       TWBR = 72

       16000000 / (16 + 2*72)
       = 16000000 / 160
       = 100000 Hz
    */

    TWSR = 0x00;        // Prescaler = 1
    TWBR = 72;          // 100 kHz

    TWCR = (1 << TWEN); // Enable TWI
}


/*
 * Generate START condition
 *CLEAR TWINT bit in TWCR register to start the operation 
 *set TWSTA bit to generate START condition
 *Enable TWI by setting TWEN bit in TWCR register
 */
void i2c_start(void)
{
    TWCR = (1 << TWINT) |
           (1 << TWSTA) |
           (1 << TWEN);

    /* Wait until START is transmitted */
    while (!(TWCR & (1 << TWINT)));
}


/*
 * Send one byte
 *
 * This can be:
 *   Slave address + Write
 *   Slave address + Read
 *   Register address
 *   Data
 */
void i2c_write(uint8_t data)
{
    TWDR = data;

    TWCR = (1 << TWINT) |
           (1 << TWEN);

    /* Wait until transmission is complete */
    while (!(TWCR & (1 << TWINT)));
}


/*
 * Read a byte and send ACK
 *
 * Used when more bytes are still required.
 */
uint8_t i2c_read_ack(void)
{
    TWCR = (1 << TWINT) |
           (1 << TWEN) |
           (1 << TWEA);//Enable ACK bit to send ACK after receiving data

    /* Wait until data is received */
    while (!(TWCR & (1 << TWINT)));

    return TWDR;
}


/*
 * Read the final byte and send NACK
 *
 * Used when this is the last byte to be read.
 */
uint8_t i2c_read_nack(void)
{//Disable ACK bit to send NACK (TWEA BIT 0)after receiving data not to request more data

    TWCR = (1 << TWINT) |
           (1 << TWEN);

    /* Wait until data is received */
    while (!(TWCR & (1 << TWINT)));

    return TWDR;
}


/*
 * Generate STOP condition
 */
void i2c_stop(void)
{//Generate STOP condition by setting TWSTO bit in TWCR register and clear TWINT to start the operation
    TWCR = (1 << TWINT) |
           (1 << TWSTO) |
           (1 << TWEN);
}