#include "main.h"
#include "logger.h"


void init_system() {
    HAL_Init();
    SystemClock_Config();
}

int main(void) {
    init_system();
    logger_init(Error_Handler);

    for (uint16_t i = 0;; i += 20) {
        logger_send_imu(100, 200, 65000 - i);
        HAL_Delay(100);
    }
}

void Error_Handler(void) {
}

