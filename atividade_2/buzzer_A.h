#ifndef BUZZER_A_H
#define BUZZER_A_H
void play_tone(uint buzzer_pin, int frequency, int duration_ms) {
    int delay = 1000000 / (frequency * 2);  // Calcula o atraso para gerar a frequência
    int cycles = (duration_ms * 1000) / (delay * 2);

    for (int i = 0; i < cycles; i++) {
        gpio_put(buzzer_pin, 1);
        sleep_us(delay);
        gpio_put(buzzer_pin, 0);
        sleep_us(delay);
    }
}

void Ativar_Buzzer(uint buzzer_pin){
    gpio_init(buzzer_pin);
    gpio_set_dir(buzzer_pin, GPIO_OUT);
}

void acionar_Buzzer(uint buzzer_pin){
    play_tone(buzzer_pin,150,2000);
}

#endif //BUZZER_A_H

