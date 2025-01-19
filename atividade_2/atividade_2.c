#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "reboot.h"
#include "hardware/uart.h"


#define LED_AZUL 12
#define LED_VERDE 11
#define LED_VERMELHO 13
#define BUZZER_A 21
#define UART_ID uart0
#define UART_TX 0
#define UART_RX 1
#define TRANSMISSAO 15200

void executar_comando(const char *comando) {
    if (strcmp(comando, "Ligar Azul") == 0) {
         ligar_led(LED_AZUL);
        uart_puts(UART_ID, "LED Azul Ligado\n");
    } else if (strcmp(comando, "Desligar Azul") == 0) {
        gpio_put(LED_AZUL, 0); // Desliga o LED
        gpio_put(LED_VERDE, 0);
        gpio_put(LED_VERMELHO, 0);
        uart_puts(UART_ID, "LED Azul Desligado\n");
    } 
    if (strcmp(comando, "Ligar Verde") == 0) {
       ligar_led(LED_VERDE);
        uart_puts(UART_ID, "LED Verde Ligado\n");
    } else if (strcmp(comando, "Desligar Verde") == 0) {
        gpio_put(LED_VERDE, 0); // Desliga o LED
        gpio_put(LED_AZUL, 0);
        gpio_put(LED_VERMELHO, 0);
        uart_puts(UART_ID, "LED Verde Desligado\n");
    }
    if (strcmp(comando, "Ligar Vermelho") == 0) {
       ligar_led(LED_VERMELHO);
        uart_puts(UART_ID, "LED Vermelho Ligado\n");
    } else if (strcmp(comando, "Desligar Vermelho") == 0) {
        gpio_put(LED_VERMELHO, 0); // Desliga o LED
        gpio_put(LED_VERDE, 0); // Desliga o LED
        gpio_put(LED_AZUL, 0);
        uart_puts(UART_ID, "LED Vermelho Desligado\n");
    }
    if (strcmp(comando, "Ligar Buzzer") == 0) {
        gpio_put(LED_VERMELHO, 1); // Liga o LED 
        uart_puts(UART_ID, "Buzzer Ligado\n");
    } else if (strcmp(comando, "Desligar Buzzer") == 0) {
        gpio_put(LED_VERMELHO, 0); // Desliga o LED
        uart_puts(UART_ID, "Buzzer Desligado\n");
    }else {
        uart_puts(UART_ID, "Comando desconhecido\n");
    }
}


//Definir macros:
int main()
{
    //Inicializar portas:
    //Inicializar buzzer:
    //Set_direction:
    //Inicialização da UART
    uart_init(UART_ID, TRANSMISSAO);
    gpio_set_function(UART_TX, GPIO_FUNC_UART);
    gpio_set_function(UART_RX, GPIO_FUNC_UART);
    setup_gpio();
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
