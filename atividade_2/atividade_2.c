#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "reboot.h"

#define LED_RED 13
#define LED_BLUE 12
#define LED_GREEN 11


int main()
{
    gpio_init(LED_RED);
    gpio_init(LED_BLUE);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_RED,GPIO_OUT);
    gpio_set_dir(LED_BLUE,GPIO_OUT);
    gpio_set_dir(LED_GREEN,GPIO_OUT);

    while (true) {
        
    }
}
