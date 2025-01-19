#include "pico/stdlib.h"
#include <string.h>

// Definição dos pinos
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 21

// Função para inicializar os GPIOs
void setup_gpio() {
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);
    gpio_init(LED_RED);
    gpio_init(BUZZER);

    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(BUZZER, GPIO_OUT);

    // Inicialmente, todos desligados
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_RED, 0);
    gpio_put(BUZZER, 0);
}

// Funções de controle dos periféricos
void ligar_led(uint led_gpio) {
    gpio_put(LED_GREEN, led_gpio == LED_GREEN);
    gpio_put(LED_BLUE, led_gpio == LED_BLUE);
    gpio_put(LED_RED, led_gpio == LED_RED);
}

void desligar_leds() {
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_RED, 0);
}

void ligar_todos_leds() {
    gpio_put(LED_GREEN, 1);
    gpio_put(LED_BLUE, 1);
    gpio_put(LED_RED, 1);
}

void buzzer_som() {
    gpio_put(BUZZER, 1);
    sleep_ms(2000); // Buzzer ligado por 2 segundos
    gpio_put(BUZZER, 0);
}

int main() {
    // Inicializar o sistema e a UART
    stdio_init_all();
    setup_gpio();

    char comando[10];

    printf("Sistema iniciado. Aguardando comandos pela UART...\n");

    while (true) {
        // Ler entrada da UART
        if (scanf("%s", comando) > 0) {
            if (strcmp(comando, "GREEN") == 0) {
                ligar_led(LED_GREEN);
                printf("LED verde ligado!\n");
            } else if (strcmp(comando, "BLUE") == 0) {
                ligar_led(LED_BLUE);
                printf("LED azul ligado!\n");
            } else if (strcmp(comando, "RED") == 0) {
                ligar_led(LED_RED);
                printf("LED vermelho ligado!\n");
            } else if (strcmp(comando, "WHITE") == 0) {
                ligar_todos_leds();
                printf("Todos os LEDs ligados (luz branca)!\n");
            } else if (strcmp(comando, "OFF") == 0) {
                desligar_leds();
                printf("Todos os LEDs desligados!\n");
            } else if (strcmp(comando, "BUZZ") == 0) {
                printf("Buzzer ativado por 2 segundos!\n");
                buzzer_som();
            
            } else {
                printf("Comando invalido: %s\n", comando);
            }
        }
    }
}
