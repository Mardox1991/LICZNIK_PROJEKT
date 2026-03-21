




#include "stm32g0xx_hal.h"
#include "_gpio_init.h"



void _gpio_init (void){

	// --- KROK 1: Dostarczenie "prądu" do bramy wejściowej DLA portu A ---
	RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
	(void)RCC->IOPENR;//  odczytanie rejestru, dajemy czas aby clock dla GPIOA sie zalaczyl


}
