#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "reboot.h"
#include "buzzer_A.h"

// DEFINIR PORTAS GPIO
#define LED_AZUL 12
#define LED_VERDE 11
#define LED_VERMELHO 13
#define BUZZER_A 21

// Função para inicializar os GPIOs
void setup_gpio() {
    gpio_init(LED_VERDE);
    gpio_init(LED_AZUL);
    gpio_init(LED_VERMELHO);

    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    Ativar_Buzzer(BUZZER_A);

    // Inicialmente, todos desligados
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
    gpio_put(BUZZER_A, 0);
}

// Funções de controle dos periféricos
void ligar_led(uint led_gpio) {
    gpio_put(LED_VERDE, led_gpio == LED_VERDE);
    gpio_put(LED_AZUL, led_gpio == LED_AZUL);
    gpio_put(LED_VERMELHO, led_gpio == LED_VERMELHO);
}

void desligar_leds() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
}

void ligar_todos_leds() {
    gpio_put(LED_VERDE, 1);
    gpio_put(LED_AZUL, 1);
    gpio_put(LED_VERMELHO, 1);
}

void executar_comando(const char *comando) {
    // LIGAR LED AZUL
    if (strcmp(comando, "Ligar Azul") == 0) {
        ligar_led(LED_AZUL);
        printf("LED Azul Ligado\n");

    // DESLIGAR LED AZUL
    } else if (strcmp(comando, "Desligar Azul") == 0) {
        gpio_put(LED_AZUL, 0);
        printf("LED Azul Desligado\n");

    // LIGAR LED VERDE
    } else if (strcmp(comando, "Ligar Verde") == 0) {
        ligar_led(LED_VERDE);
        printf("LED Verde Ligado\n");

    // DESLIGAR LED VERDE
    } else if (strcmp(comando, "Desligar Verde") == 0) {
        gpio_put(LED_VERDE, 0);
        printf("LED Verde Desligado\n");

    // LIGAR LED VERMELHO
    } else if (strcmp(comando, "Ligar Vermelho") == 0) {
        ligar_led(LED_VERMELHO);
        printf("LED Vermelho Ligado\n");

    // DESLIGAR LED VERMELHO
    } else if (strcmp(comando, "Desligar Vermelho") == 0) {
        gpio_put(LED_VERMELHO, 0);
        printf("LED Vermelho Desligado\n");

    // LIGAR TODOS OS LEDS
    } else if (strcmp(comando, "Ligar Todos") == 0) {
        ligar_todos_leds();
        printf("Todos os LEDs ligados\n");

    // DESLIGAR TODOS OS LEDS
    } else if (strcmp(comando, "Desligar Todos") == 0) {
        desligar_leds();
        printf("Todos os LEDs desligados\n");

    // ACIONAR BUZZER
    } else if (strcmp(comando, "Ligar Buzzer") == 0) {
        printf("Buzzer Ligado\n");
        acionar_Buzzer(BUZZER_A);

    // POR PLACA EM MODO BOOTLOADER
    } else if (strcmp(comando, "Reboot") == 0) {
        printf("Reiniciando o sistema no modo de gravação...\n");
        reboot(LED_VERMELHO);

    // COMANDO DESCONHECIDO
    } else {
        printf("Comando desconhecido: %s\n", comando);
    }
}

int main() {
    // Inicializar funções da stdio
    stdio_init_all();

    // Inicializar periféricos
    setup_gpio();

    char buffer[1024]; // Buffer para armazenar o comando

    while (true) {
        printf("Digite um comando: ");
        if (fgets(buffer, sizeof(buffer), stdin)) {
            // Remover o caractere de nova linha, se presente
            buffer[strcspn(buffer, "\r\n")] = '\0';
            executar_comando(buffer);
        }
    }
}

