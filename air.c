/* vim:ts=4:shiftwidth=4:expandtab:smartindent
*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

int main() {
	stdio_init_all();

    gpio_init(14);
    gpio_set_dir(14, GPIO_OUT);
    gpio_put(14, 1);

	i2c_init(i2c0, 4*1000);
    gpio_set_function(12, GPIO_FUNC_I2C);
    gpio_set_function(13, GPIO_FUNC_I2C);
    gpio_pull_up(12);
    gpio_pull_up(13);

    while (true) {
        if (i2c_write_blocking(i2c0, 0x77, "\xd0", 1, false) != 1) {
            printf("Write failed!\n");
            continue;
        }

        uint8_t buf;
        if (i2c_read_blocking(i2c0, 0x77, &buf, 1, false) != 1) {
            printf("Read failed!\n");
            continue;
        }

        printf("Version %d\n", buf);

        sleep_ms(250);
        sleep_ms(250);

		printf("Hello world!\n");
    }
}
