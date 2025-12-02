#include "gpio_setup.h"
#include "led_matrix.h"
#include "swt_matrix.h"

void setup_pins() {
    for(int i=0;i<9;i++) {
        gpio_config_t led_conf = {
            .pin_bit_mask = (1ULL << LED_MATRIX[i]->pin),
            .mode = GPIO_MODE_OUTPUT,
            .pull_up_en = GPIO_PULLUP_DISABLE,
            .pull_down_en = GPIO_PULLDOWN_DISABLE,
            .intr_type = GPIO_INTR_DISABLE
        };
        gpio_config(&led_conf);

        gpio_config_t swt_conf = {
            .pin_bit_mask = (1ULL << SWT_MATRIX[i]->pin),
            .mode = GPIO_MODE_INPUT,
            .pull_up_en = GPIO_PULLUP_DISABLE,
            .pull_down_en = GPIO_PULLDOWN_DISABLE,
            .intr_type = GPIO_INTR_DISABLE
        };
        gpio_config(&swt_conf);
    }
    gpio_config_t but_conf = {
            .pin_bit_mask = (1ULL << SEL->pin),
            .mode = GPIO_MODE_INPUT,
            .pull_up_en = GPIO_PULLUP_DISABLE,
            .pull_down_en = GPIO_PULLDOWN_DISABLE,
            .intr_type = GPIO_INTR_DISABLE
        };
        gpio_config(&but_conf);
}
