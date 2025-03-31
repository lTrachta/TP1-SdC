#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/timer.h>
#include <stdio.h>
#include <libopencm3/stm32/common/usart_common_all.h>
#include <libopencm3/stm32/f1/gpio.h>

#define ITERATIONS     60000000
#define SYS_CLK_MHZ    24    // Frecuencia del reloj en MHz

#define COM_UART       USART2
#define COM_PORT       GPIOA
#define COM_TX_PIN     GPIO2
#define COM_RX_PIN     GPIO3
#define BAUD_RATE      9600
#define DATA_BITS      8
#define BUFFER_SIZE    64

// Configura el reloj del sistema según la frecuencia definida
void init_system_clock(void) {
    if (SYS_CLK_MHZ == 72) {
        rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_72MHZ]);
    } else {
        rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_24MHZ]);
    }
}

// Inicializa TIM2 para contar con un tick de 1 µs
void init_timer(void) {
    rcc_periph_clock_enable(RCC_TIM2);
    // Se configura el prescaler para que 72 MHz / 72 = 1 MHz
    timer_set_prescaler(TIM2, SYS_CLK_MHZ - 1);
    timer_set_period(TIM2, 0xFFFF);
    timer_enable_counter(TIM2);
}

// Inicializa USART2 para transmisión
void init_usart(void) {
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_USART2);
    gpio_set_mode(COM_PORT, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, COM_TX_PIN | COM_RX_PIN);
    
    usart_set_baudrate(USART2, BAUD_RATE);
    usart_set_databits(USART2, DATA_BITS);
    usart_set_stopbits(USART2, USART_STOPBITS_1);
    usart_set_mode(USART2, USART_MODE_TX);
    usart_set_parity(USART2, USART_PARITY_NONE);
    usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);
    
    usart_enable(USART2);
}

// Envía por UART un mensaje formateado con la frecuencia y el tiempo transcurrido
void uart_send_message(uint32_t elapsed_time) {
    char msg[BUFFER_SIZE];
    snprintf(msg, sizeof(msg), "Frecuencia: %02d [Mhz], Tiempo de ejecucion: %02u [S]", SYS_CLK_MHZ, elapsed_time);
    for (char *p = msg; *p; p++) {
        usart_send_blocking(COM_UART, *p);
    }
}

int main(void) {
    init_system_clock();
    init_timer();
    init_usart();
    
    volatile uint32_t sum = 0;
    // Bucle que simula una carga de trabajo (aproximadamente 10 segundos, según la cantidad de iteraciones)
    for (uint32_t j = 0; j < ITERATIONS; j++) {
        sum++;  // Operación dummy para consumir tiempo
    }
    
    uint32_t timer_ticks = timer_get_counter(TIM2);
    // Convertir microsegundos a "segundos" (aunque dividir por 1000 convierte a milisegundos)
    uint32_t elapsed_time = timer_ticks / 1000;
    
    timer_disable_counter(TIM2);
    uart_send_message(elapsed_time);
    
    return 0;
}
