# **CONTROLE DE SERVOMOTOR POR PWM NO RP2040**

Este repositório contém o código-fonte e o diagrama referentes a parte 1 da atividade prática que consiste em utilizar o microcontrolador Raspberry Pi Pico W e um servomotor, para simular o controle do ângulo do servomotor por PWM.

## **COMPONENTES UTILIZADOS**

Neste projeto foram utilizados os seguintes componentes:

- Microcontrolador Raspberry pi pico w;
- 01 Servomotor;
- 01 Led vermelho.

## **FUNCIONALIDADES IMPLEMENTADAS**

1. Configuração da GPIO 22 para PWM:
- A frequência de PWM foi configurada para aproximadamente 50Hz (período de 20ms).
- A flange do servomotor foi ajustada para a posição de 180 graus com um ciclo ativo de 2.400µs (0,12% de Duty Cycle).
- O código aguarda 05 segundos nesta posição.

2. Ajuste da posição do servomotor para 90 graus:
- O ciclo ativo foi ajustado para 1.470µs (0,0735% de Duty Cycle).
- A flange do servomotor foi movida para a posição de 90 graus, aguardando 05 segundos nesta posição.

3. Movimento do servomotor para 0 graus:
- O ciclo ativo foi ajustado para 500µs (0,025% de Duty Cycle).
- A flange foi movida para a posição de 0 graus, aguardando 05 segundos nesta posição.

4. Movimentação periódica do braço do servomotor entre 0 e 180 graus:
- A movimentação foi feita suavemente, com incremento do ciclo ativo de ±5µs e um atraso de 10ms a cada ajuste de posição.

5. Experimento com LED RGB:
- Utilizando a GPIO 12, foi realizado um experimento para observar o comportamento do LED RGB com as variações do ciclo de PWM.
- Foi observado que o LED exibiu mudanças de cor e intensidade em função da variação do PWM, refletindo as alterações de ciclo ativo.

## Organização da Equipe
- **Líder de Projeto:** [VITÓRIA CAVALCANTI] — responsável pelo gerenciamento do repositório, estrutura do código e revisão dos pull requests.
- **Desenvolvedor 1:** [LÁISA BIANCA] — responsável pelo movimento do servomotor para 180 e 90 graus.
- **Desenvolvedor 2:** [LAÍSE CAFÉ] — responsável pelo movimento do servomor para 0 graus e o movimento continuo suave.

---

## **VÍDEO EXPLICATIVO**
[Link do vídeo explicativo](https://www.canva.com/design/DAGrerhXk_c/fb2iasPDV7GdsxLI7v1RkQ/watch?utm_content=DAGrerhXk_c&utm_campaign=designshare&utm_medium=link2&utm_source=uniquelinks&utlId=hf6d82df8b5)

## Licença
Este projeto é destinado exclusivamente para fins acadêmicos na disciplina **ELET0021 — Microcontroladores e Microprocessadores**.

---