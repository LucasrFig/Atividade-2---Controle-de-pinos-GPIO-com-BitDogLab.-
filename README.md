──────────────────────────────────────────────────────────────────────  
# PROJETO - CONTROLE DE PINOS GPIO UTILIZANDO COMUNICAÇÃO SERIAL UART
(SUB GRUPO 6 - ATIVIDADE 2)  
**Equipe do Projeto:** 

──────────────────────────────────────────────────────────────────────

- João Murillo Brito Taveira  
- Amanda Cardoso Lopes  
- Lucas Ricardo De Lima Figueiredo (Líder da semana)  
- Matheus Leite Machado  
- Vinícius Da Silva Barreto Dos Santos  
- Wendel Souza Santos  

──────────────────────────────────────────────────────────────────────  
## OBJETIVO DO PROJETO  
──────────────────────────────────────────────────────────────────────  

O objetivo deste projeto é criar um sistema de controle de pinos GPIO (General Purpose Input/Output) utilizando a comunicação serial por meio da interface UART. Através desse sistema, será possível acionar os LEDs RGB, o buzzer e por a placa em modo bootloader com base nos comandos recebidos pelo terminal, oferecendo uma interação simples e prática com o microcontrolador. 

──────────────────────────────────────────────────────────────────────  
## METODOLOGIA ESCOLHIDA PARA REALIZAÇÃO DO PROJETO
──────────────────────────────────────────────────────────────────────  
Decidimos que cada integrante ficasse encarregado por criar uma branch no git, fazer alterações no arquivo ou enviar uma biblioteca com a função pela qual ficou responsável. Após isso, o líder deve dar merge das alterações na branch principal, baixar as bibliotecas criadas e adicionar a main e, por fim, fazer os testes e ajustes finais antes de enviar a tarefa. 

──────────────────────────────────────────────────────────────────────  
## FUNCIONALIDADES DO PROJETO  
──────────────────────────────────────────────────────────────────────  

O programa oferece funcionalidades a partir dos seguintes comandos:

**Comando 'BLUE_ON':** Acende o LED Azul (Apaga os demais LEDs).

**Comando 'BLUE_OFF':** Apaga o LED Azul.

**Comando 'GREEN_ON':** Acende o LED Verde(Apaga os demais LEDs).

**Comando 'GREEN_OFF':** Apaga o LED Verde.

**Comando 'RED_ON':** Acende o LED Vermelho(Apaga os demais LEDs).

**Comando 'RED_OFF':** Apaga o LED Vermelho.

**Comando 'ALL_ON':** Acende todos os LEDs.

**Comando 'ALL_OFF':** Apaga todos os LEDs.

**Comando 'BUZZER_ON':** Aciona o Buzzer por um breve período.

**Comando 'REBOOT':** Põe a placa em modo bootloader.

──────────────────────────────────────────────────────────────────────  
## ESTRUTURA DO PROGRAMA  
──────────────────────────────────────────────────────────────────────  

O programa segue a seguinte estrutura de funcionamento:

1. *Leitura do Comando:* O comando é informado pelo usuário no terminal.  
2. *Ação de Cada Comando:* Dependendo do comando identificado, o sistema realiza a ação correspondente, como acender LEDs ou emitir som com o buzzer.  
3. *Controle de GPIO:* O programa utiliza funções para controlar os pinos GPIO, ativando/desativando LEDs e o buzzer.  
4. *Interatividade:* O sistema permite múltiplas interações, com o usuário podendo utilizar de diferentes comandos para acionar as funcionalidades desejadas.

──────────────────────────────────────────────────────────────────────  
## TECNOLOGIAS UTILIZADAS  
──────────────────────────────────────────────────────────────────────  
- Linguagem: C
- Microcontrolador: Raspberry Pi Pico (RP2040)
- Biblioteca: pico/stdlib.h, pico/bootrom.h
- Emulação de terminal: Putty

──────────────────────────────────────────────────────────────────────  
## COMO EXECUTAR O PROJETO
──────────────────────────────────────────────────────────────────────  
- **Clone o Repositório:**
  git clone https://github.com/LucasrFig/Atividade-2_Controle-de-pinos-GPIO-com-BitDogLab.git

- **Compile o Código:**
  Utilize o ambiente de desenvolvimento VS Code. 
  Instalar extensão: Raspberry Pi Pico.

- **Carregue na Raspberry Pi Pico:**
  Conecte a Raspberry Pi Pico em modo de boot.
  Copie o arquivo .uf2 gerado para a unidade de armazenamento da Pico.

- **Faça o download do PuTTY**
  Site Download: https://www.putty.org/
  
- **Configurar PuTTY**
  1. Acesse o Gerenciador de dispositivos e vá em 'Portas (COM e LPT)'.
  2. Identifique o número da porta COM onde a placa está conectada.
  3. Abra o PuTTY e escolha o Connection type 'Serial'
  4. Em 'Serial line' escreva COM e o número da porta na qual a placa está conectada.
  5. Em 'Speed' coloque o número 115200.
  6. Clique em Open.
  7. Pronto, agora você pode acessar o terminal e enviar comandos para a placa por meio da plataforma PuTTY.
  
──────────────────────────────────────────────────────────────────────  
## CONCLUSÃO  
──────────────────────────────────────────────────────────────────────  
Neste projeto, exploramos o controle de pinos GPIO por meio do protocolo UART, um dos pilares da comunicação em sistemas embarcados. Com o auxílio do PuTTY como emulador de terminal, interagimos diretamente com o microcontrolador via comunicação serial, ampliando as possibilidades de controle. Essa experiência prática foi fundamental para aprofundar nosso domínio em protocolos de comunicação, além de otimizar nossas habilidades no desenvolvimento de códigos eficientes.

──────────────────────────────────────────────────────────────────────  
## EQUIPE DO PROJETO - CONTROLE DE PINOS GPIO UTILIZANDO COMUNICAÇÃO SERIAL UART
UTILIZANDO COMUNICAÇÃO VIA PROTOCOLO UART
*Subgrupo 6 - Atividade 2*  
──────────────────────────────────────────────────────────────────────

──────────────────────────────────────────────────────────────────────  
## VÍDEO DO PROJETO  
────────────────────────────────────────────────────────────────────── 
 
