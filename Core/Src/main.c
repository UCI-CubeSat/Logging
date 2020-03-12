#include "main.h"
#include "logger.h"
#include "IMU.h"

void init_system() {
    HAL_Init();
    SystemClock_Config();
}

void init_peripherals() {
    logger_init(Error_Handler);
    imu_init(Error_Handler);
}

int main(void) {
    init_system();
    init_peripherals();

    //Call IMU function to get euler angles

    for (uint16_t i = 0;; i += 20) {
        logger_send_imu(100, 200, 65000 - i);
        HAL_Delay(100);
    }
}

void Error_Handler(void) {
}

