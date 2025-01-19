#ifndef BUZZER_A_H
#define BUZZER_A_H
void Ativar_Buzzer(uint buzzer_pin){
    gpio_init(buzzer_pin);
    gpio_set_dir(buzzer_pin, GPIO_OUT);
}

void acionar_Buzzer(uint buzzer_pin){
    gpio_put(buzzer_pin, 1);
    sleep_ms(2000);  // Buzzer ligado por 2 segundos
    gpio_put(buzzer_pin, 0);
}
#endif //BUZZER_A_H