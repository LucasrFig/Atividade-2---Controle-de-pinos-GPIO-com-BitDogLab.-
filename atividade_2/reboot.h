#ifndef REBOOT_H
#define REBOOT_H
void reboot(uint led){
            for(int i=0;i<6;i++){
            gpio_put(led,1);
            sleep_ms(100);
            gpio_put(led,0);
            sleep_ms(100);
            }
            reset_usb_boot(0, 0);                                                                                                                                                                                                                                                                                                                          
}
#endif//REBOOT_H