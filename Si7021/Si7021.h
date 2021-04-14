//***********************************************************************************
// Include files
//***********************************************************************************

#ifndef SRC_HEADER_FILES_SI7021_H_
#define SRC_HEADER_FILES_SI7021_H_

/* System include statements */


/* Silicon Labs include statements */
#include "em_i2c.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "em_assert.h"

/* The developer's include statements */


//***********************************************************************************
// defined files
//***********************************************************************************

#define      SI7021_I2C_ADDRESS           0x40

//***********************************************************************************
// global variables
//***********************************************************************************


//***********************************************************************************
// function prototypes
//***********************************************************************************

 void si7021_i2c_open(I2C_TypeDef *i2c, uint32_t SDA_route, uint32_t SCL_route);

 void si7021_read(uint32_t SI7021_READ_CB, I2C_TypeDef *i2c);

 float si7021_return_humidity(void);

#endif /* SRC_HEADER_FILES_SI7021_H_ */
