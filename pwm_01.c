// Inclusão das bibliotecas
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definições de pinos e parâmetros
#define SERVO_PIN 22
#define LED_RED_PIN 12
#define PWM_CLOCK_DIVIDER 64.0
#define PWM_PERIOD_US 20000.0
#define PWM_TOP_VALUE 39063

uint slice_servo;
uint slice_led;

// Calcula o duty cycle para um dado tempo em microsegundos
static uint16_t calculate_pwm_duty(float pulse_width_us) {
    return (uint16_t)((pulse_width_us / PWM_PERIOD_US) * PWM_TOP_VALUE);
}

// Configura o nível do PWM para um pino específico
static void set_pwm_pulse(uint slice, uint gpio, float pulse_width_us) {
    uint16_t duty_cycle = calculate_pwm_duty(pulse_width_us);
    pwm_set_gpio_level(gpio, duty_cycle);
}

// Inicializa um pino para operação com PWM
static void initialize_pwm_pin(uint gpio, uint *slice_num) {
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    *slice_num = pwm_gpio_to_slice_num(gpio);

    pwm_set_clkdiv(*slice_num, PWM_CLOCK_DIVIDER);
    pwm_set_wrap(*slice_num, PWM_TOP_VALUE);
    pwm_set_enabled(*slice_num, true);
}

int main() {
    stdio_init_all();

    // Configuração inicial dos pinos do servo e LED
    initialize_pwm_pin(SERVO_PIN, &slice_servo);
    initialize_pwm_pin(LED_RED_PIN, &slice_led);

    sleep_ms(2000);  // Pequena pausa antes de iniciar

    // Láisa Bianca: Movimento do servo e LED para 180°
    set_pwm_pulse(slice_servo, SERVO_PIN, 2400);  // ~180 graus
    set_pwm_pulse(slice_led, LED_RED_PIN, 2400);
    sleep_ms(5000);

    // Láisa Bianca: Movimento do servo e LED para 90°
    set_pwm_pulse(slice_servo, SERVO_PIN, 1470);  // ~90 graus
    set_pwm_pulse(slice_led, LED_RED_PIN, 1470);
    sleep_ms(5000);

    // Laíse Café: Movimento do servo e LED para 0°
    set_pwm_pulse(slice_servo, SERVO_PIN, 500);   // ~0 graus
    set_pwm_pulse(slice_led, LED_RED_PIN, 500);
    sleep_ms(5000);

    // Laíse Café: Movimento contínuo suave do servo e LED
    while (true) {
        for (float pulse = 500; pulse <= 2400; pulse += 5) {
            set_pwm_pulse(slice_servo, SERVO_PIN, pulse);
            set_pwm_pulse(slice_led, LED_RED_PIN, pulse);
            sleep_ms(10);
        }

        for (float pulse = 2400; pulse >= 500; pulse -= 5) {
            set_pwm_pulse(slice_servo, SERVO_PIN, pulse);
            set_pwm_pulse(slice_led, LED_RED_PIN, pulse);
            sleep_ms(10);
        }
    }

    return 0;
}