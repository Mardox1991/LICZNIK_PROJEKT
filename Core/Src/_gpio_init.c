




#include "stm32g0xx_hal.h"
#include "_gpio_init.h"



void _gpio_init (void){

	// --- KROK 1: Dostarczenie "prądu" do bramy wejściowej DLA portu A ---
	RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
	(void)RCC->IOPENR;//  odczytanie rejestru,naturalny delay- dajemy czas aby clock dla GPIOA sie zalaczyl



	//--Alternate function mode configuration .
	//ustawienie pinu PA6 w trybie alternatywnym  ( ustawiamy brame )
	//bedziemy sterowac PWM za pomoca tim3
	GPIOA->MODER &= ( ~(3U<<12) ); //najpierw czyscimy pole rejestru  ktore bedziemy nadpisywac
	GPIOA->MODER |=	   (2U<<12) ;     // 10




	GPIOA->AFR[0] &= ( ~(0xFU << 24) ); // Czyścimy pole AFSEL6 (4 bity)

    // Mapujemy fizyczne połączenie (krosowanie) pinu PA6 z wyjściem sprzętowym TIM3_CH1 poprzez wybór funkcji AF1.
    GPIOA->AFR[0] |=  (1U<<24);  // Wpisujemy 1 (AF1).



}
