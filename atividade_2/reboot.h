#ifndef REBOOT_H
#define REBOOT_H
void reboot(){
            printf("Reiniciando o sistema no modo de gravação...\n");
            gpio_put(LED_RED,1);
            sleep_ms(1000);
            reset_usb_boot(0, 0);                                                                                                                                                                                                                                                                                                                            
}
#endif//REBOOT_H