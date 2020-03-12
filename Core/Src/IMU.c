#include "IMU.h"

#include <string.h>

I2C_HandleTypeDef hi2c1;

void i2c_init(void (*error_handler) (void)) {
    hi2c1.Instance = I2C1;
    hi2c1.Init.ClockSpeed = 100000;
    hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.OwnAddress2 = 0;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    if (HAL_I2C_Init(&hi2c1) != HAL_OK) {
        error_handler();
    }
}

s8 i2c_read(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt) {
    //Finish
}

s8 i2c_write(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt) {
    HAL_StatusTypeDef ret = 0;

    ret = HAL_I2C_Master_Transmit(&hi2c1, dev_addr, &reg_addr,
            1, HAL_MAX_DELAY);
    if (ret != HAL_OK) return ret;

    ret = HAL_I2C_Master_Transmit(&hi2c1, dev_addr, reg_data,
            cnt, HAL_MAX_DELAY);
    return ret;
}

void imu_init(void (*error_handler) (void)) {
    i2c_init(error_handler);

}
