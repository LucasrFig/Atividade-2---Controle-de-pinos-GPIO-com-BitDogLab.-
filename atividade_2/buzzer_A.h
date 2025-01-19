void Ativar_Buzzer(){

    gpio_init(BUZZER_A);
    gpio_set_dir(BUZZER_A, GPIO_OUT);
}

void acionar_Buzzer(){
    gpio_put(BUZZER_A, 1);
    sleep_ms(2000);  // Buzzer ligado por 2 segundos
    gpio_put(BUZZER_A, 0);
}