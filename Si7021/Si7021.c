 /**
 * @file Si7021.c
 * @author James Brennan
 * @date March 13th, 2020
 * @brief Contains all the Si7021 driver functions
 *
 */


//***********************************************************************************
// Include files
//***********************************************************************************

//** Standard Libraries

//** Silicon Lab include files

//** User/developer include files
#include "Si7021.h"
#include "em_i2c.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "em_assert.h"
#include "i2c.h"
//#include "app.h"

//***********************************************************************************
// defined files
//***********************************************************************************


//***********************************************************************************
// Private variables
//***********************************************************************************
static uint32_t data;

//***********************************************************************************
// Private functions
//***********************************************************************************


//***********************************************************************************
// Global functions
//***********************************************************************************

/***************************************************************************//**
 * @brief
 *   Driver to open I2C to the si7021
 *
 * @details
 * 	 This routine is a low level driver.  The application code calls this function
 * 	 once to open I2C communication with the si7021
 *
 * @note
 *   This function is normally called once to initialize I2C to the peripheral
 *
 * @param[in] i2c
 *   Pointer to the base peripheral address of the I2C peripheral being opened
 *
 * @param[in] SDA_route
 *   SDA out-route for the i2c peripheral being used
 *
 * @param[in] SCL_route
 *   SCL out-route for the i2c peripheral being used
 *
 ******************************************************************************/

void si7021_i2c_open(I2C_TypeDef *i2c, uint32_t SDA_route, uint32_t SCL_route ){

	 I2C_OPEN_STRUCT i2c_open_struct;
	 //not ready to enable i2c yet
	 i2c_open_struct.enable = true;
	 //setting to master
	 i2c_open_struct.master = true;
	 //using the currently configured reference clock
	 i2c_open_struct.refFreq = false;
	 //using maximum possible freq, limited by the Si7021 whose max is 400kHz
	 i2c_open_struct.freq = I2C_FREQ_FAST_MAX;   //about 392 kHz
	 //Using the appropriate ratio for the max freq we selected
	 i2c_open_struct.clhr = i2cClockHLRAsymetric;

	 //setting up and enabling the output pins
	 i2c_open_struct.out_pin_SDA = SDA_route;
	 i2c_open_struct.out_pin_SCL = SCL_route;
	 i2c_open_struct.out_pin_SDA_en = true;
	 i2c_open_struct.out_pin_SCL_en = true;


	 i2c_open(i2c, &i2c_open_struct);


 }

/***************************************************************************//**
 * @brief
 *   Function to read from the si7021
 *
 * @details
 * 	 This function should be called whenever one wishes to read humidity
 *
 *
 *
 * @param[in] i2c
 *   Pointer to the base peripheral address of the I2C peripheral being opened
 *
 * @param[in] SI7021_READ_CB
 *   Callback variable used as part of the scheduler
 *
 *
 ******************************************************************************/

void si7021_read(uint32_t SI7021_READ_CB, I2C_TypeDef *i2c){
	uint32_t address = SI7021_I2C_ADDRESS;
	I2C_Start(I2C0, &data, address, SI7021_READ_CB, 0xf5);
}


/***************************************************************************//**
 * @brief
 *   This function to returns the humidity value from the si7021
 *
 * @details
 * 	 This function should be called as part of the scheduler after the I2C state machine has completed
 *
 *
 *
 * @param[out] humidity
 * Returns the humidity read on the si7021
 *
 *
 ******************************************************************************/

float si7021_return_humidity(void){
	float humidity;
	humidity = (125*((float)(data))/65536) - 6; //change these
	return humidity;
}



