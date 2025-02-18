#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "hardware/adc.h" 
#include "hardware/pwm.h"

// Definição dos pinos dos potenciômetros do joystick
#define VRX_PIN_RED 27   // Pino de entrada analógica para eixo X do joystick
#define VRY_PIN_BLUE 26  // Pino de entrada analógica para eixo Y do joystick
#define SW_PIN 22        // Pino para o botão do joystick

// Definição dos pinos dos LEDs PWM
#define LED_PIN_RED 13  
#define LED_PIN_BLUE 12
#define LED_PIN_GREEN 11

#define ADC_CENTER 2160 // Valor aproximado da posição central

bool led_state = false;
bool sw_value;
bool estado_pwm_leds;
uint16_t vrx_value, vry_value;

// Função para inicializar um pino GPIO para saída PWM
uint pwm_init_gpio(uint gpio, uint wrap) {
    gpio_set_function(gpio, GPIO_FUNC_PWM);  // Configura o pino como saída PWM
    uint slice_num = pwm_gpio_to_slice_num(gpio); // Obtém o slice PWM correspondente ao pino
    pwm_set_wrap(slice_num, wrap);  // Define o valor máximo do contador PWM
    pwm_set_enabled(slice_num, true); // Habilita o PWM no slice
    return slice_num;  
}

void joystick_init(){
    adc_init();
    adc_gpio_init(VRX_PIN_RED);
    adc_gpio_init(VRY_PIN_BLUE);
    // Configura o botão do joystick como entrada
    gpio_init(SW_PIN);
    gpio_set_dir(SW_PIN, GPIO_IN);
    gpio_pull_up(SW_PIN);
}

void pwm_gpio_init(){
    uint pwm_wrap = 4095;  // Define o valor máximo do PWM
    pwm_init_gpio(LED_PIN_RED, pwm_wrap);   // Inicializa o PWM para o LED vermelho
    pwm_init_gpio(LED_PIN_BLUE, pwm_wrap); // Inicializa o PWM para o LED azul
}

void read_joystick() {
    adc_select_input(1); // Seleciona entrada analógica VRX_PIN_RED
    vrx_value = adc_read();
    
    adc_select_input(0); // Seleciona entrada analógica VRY_PIN_BLUE
    vry_value = adc_read();
    
    sw_value = !gpio_get(SW_PIN); // Lê o botão (ativo em LOW)
}

void control_joystick_leds(){
    read_joystick(); // Lê os valores do joystick
    
    if (estado_pwm_leds) {
        // Controle do brilho dos LEDs baseado nos valores do joystick
        if(vrx_value <= ADC_CENTER) pwm_set_gpio_level(LED_PIN_RED, 0);  // Desliga o LED vermelho se abaixo do centro
        else pwm_set_gpio_level(LED_PIN_RED, vrx_value);                // Ajusta PWM do LED vermelho
        
        if (vry_value <= ADC_CENTER) pwm_set_gpio_level(LED_PIN_BLUE, 0);   // Desliga o LED azul se acima do centro
        else pwm_set_gpio_level(LED_PIN_BLUE, vry_value - ADC_CENTER);       // Ajusta PWM do LED azul para acender ao mover para baixo
    } else {
        pwm_set_gpio_level(LED_PIN_RED, 0);  // Desliga o LED vermelho
        pwm_set_gpio_level(LED_PIN_BLUE, 0); // Desliga o LED azul
    }
    
    if (sw_value) {
        led_state = !led_state; // Alterna o estado do LED verde com o botão do joystick
        if (!estado_pwm_leds) led_state = false;
        gpio_put(LED_PIN_GREEN, led_state);
        sleep_ms(200); // Debounce do botão
    }
}

#endif
