#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "reboot.h"
#include "hardware/uart.h"

//DEFINIR PORTAS GPIO
#define LED_AZUL 12
#define LED_VERDE 11
#define LED_VERMELHO 13
#define BUZZER_A 21

//DEFINIR MACROS UART
#define UART_ID uart0
#define UART_TX 0
#define UART_RX 1
#define TRANSMISSAO 15200


// Função para inicializar os GPIOs
void setup_gpio() {
    gpio_init(LED_VERDE);
    gpio_init(LED_AZUL);
    gpio_init(LED_VERMELHO);
    gpio_init(BUZZER_A);

    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(BUZZER_A, GPIO_OUT);

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


//Executa uma ação de acorodo com o comando fornecido
void executar_comando(const char *comando) {
    //LIGAR LED AZUL
    if (strcmp(comando, "Ligar Azul") == 0) {
        ligar_led(LED_AZUL);
        uart_puts(UART_ID, "LED Azul Ligado\n");

    //DESLIGAR LED AZUL
    }else if (strcmp(comando, "Desligar Azul") == 0) {
            gpio_put(LED_AZUL, 0); 
            uart_puts(UART_ID, "LED Azul Desligado\n");

    //LIGAR LED VERDE
    }else if (strcmp(comando, "Ligar Verde") == 0) {
            ligar_led(LED_VERDE);
            uart_puts(UART_ID, "LED Verde Ligado\n");

    //DESLIGAR LED VERDE
    }else if (strcmp(comando, "Desligar Verde") == 0) {
            gpio_put(LED_VERDE, 0);
            uart_puts(UART_ID, "LED Verde Desligado\n");

    //LIGAR LED VERMELHO
    }else if (strcmp(comando, "Ligar Vermelho") == 0) {
            ligar_led(LED_VERMELHO);
            uart_puts(UART_ID, "LED Vermelho Ligado\n");

    //DESLIGAR LED VERMELHO
    }else if (strcmp(comando, "Desligar Vermelho") == 0) {
            gpio_put(LED_VERMELHO, 0);
            uart_puts(UART_ID, "LED Vermelho Desligado\n");
            
    //ACIONAR BUZZER
    }else if (strcmp(comando, "Ligar Buzzer") == 0) {
        // Liga o buzzeR
        uart_puts(UART_ID, "Buzzer Ligado\n");

    //POR PLACA EM MODO BOOTLOADER    
    }else if (strcmp(comando, "Reboot") == 0) {
        // Põe em Reboot
    }else{
        uart_puts(UART_ID, "Comando desconhecido\n");
    }
}


//Definir macros:
int main()
{
    //Inicializar periféricos
    setup_gpio();

    //Inicializar UART
    uart_init(UART_ID, TRANSMISSAO);
    gpio_set_function(UART_TX, GPIO_FUNC_UART);
    gpio_set_function(UART_RX, GPIO_FUNC_UART);
    uart_puts(UART_ID, "Sistema Iniciado\n");

    char buffer[32]; // Buffer para armazenar o comando
    int idx = 0;     // Índice do buffer

    while (true) {
        //ler comando:     
        //
        if (uart_is_readable(UART_ID)) {
            char c = uart_getc(UART_ID); // Lê um caractere
            uart_putc(UART_ID, c);       // Ecoa o caractere recebido (opcional)

            // Verifica se o caractere é de término
            if (c == '\n' || c == '\r') {
                buffer[idx] = '\0'; // Finaliza a string
                executar_comando(buffer); // Chama a função para processar o comando
                idx = 0; // Reseta o índice
            } else {
                buffer[idx++] = c; // Adiciona o caractere ao buffer
                if (idx >= sizeof(buffer) - 1) {
                    idx = 0; // Evita overflow do buffer
                }
            }
        }
    }
}
