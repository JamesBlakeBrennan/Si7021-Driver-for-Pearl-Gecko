//***********************************************************************************
// Include files
//***********************************************************************************

#ifndef SRC_HEADER_FILES_I2C_H_
#define SRC_HEADER_FILES_I2C_H_


/* System include statements */


/* Silicon Labs include statements */
#include "em_i2c.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "em_assert.h"
#include "sleep_routines.h"
#include "scheduler.h"


/* The developer's include statements */

//***********************************************************************************
// defined files
//***********************************************************************************



//***********************************************************************************
// private variables
//***********************************************************************************

typedef struct {
	uint32_t 					STATE;				// Current state of i2c state machine
	I2C_TypeDef                 *i2c;					//Which I2C peripheral is being used
	uint32_t					slaveAddress;               //address of slave unit being accessed
	uint32_t					Command;               //address of slave unit being accessed
	uint32_t					*Data;
	uint32_t                    SI7021_Read_CB;

}   I2C_STATE_MACHINE;


//***********************************************************************************
// global variables
//***********************************************************************************
typedef struct {
	bool 					enable;				// Enable I2C peripheral when initialization completed.
	bool					master;		        // Set to master (true) or slave (false) mode.
	uint32_t				refFreq;			// I2C reference clock assumed when configuring bus frequency setup.
	uint32_t				freq;				// (Max) I2C bus frequency to use.
	I2C_ClockHLR_TypeDef	clhr;				//Clock low/high ratio control.

	uint32_t		out_pin_SDA;		// SDA route to gpio port/pin
	uint32_t		out_pin_SCL;		// SCL route to gpio port/pin
	bool			out_pin_SDA_en;		// enable SDA route
	bool			out_pin_SCL_en;		// enable SCL route

	uint32_t          SI7021_CB;

}  I2C_OPEN_STRUCT ;




//***********************************************************************************
// function prototypes
//***********************************************************************************


void i2c_open(I2C_TypeDef *i2c, I2C_OPEN_STRUCT *app_i2c_struct);

void I2C0_IRQHandler(void);

void I2C1_IRQHandler(void);

void I2C_Start(I2C_TypeDef *i2c, uint32_t *data, uint32_t address, uint32_t SI7021_READ_CB, uint32_t Command);


#endif /* SRC_HEADER_FILES_I2C_H_ */
