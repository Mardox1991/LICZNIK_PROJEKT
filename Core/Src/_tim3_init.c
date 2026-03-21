



#include "stm32g0xx_hal.h"
#include "_tim3_init.h"



 void _tim3_init (void){


	 // --- CZĘŚĆ 1: OTWARCIE clocka  ---

	 RCC->APBENR1 |= RCC_APBENR1_TIM3EN;		//(Włączamy zegar)
	 (void)RCC->APBENR1;						// Czekamy,  AZ prad zegara dotrze do TIM3 -


	 // --- CZĘŚĆ 2: USTAWIANIE MASZYNY (Seria poleceń) ---
	 TIM3->PSC = 63;			// Ustawiamy podział (64 mln / 64 = 1 MHz)  ( pamietaj ze procek dodal sobie 63+1 )
	 TIM3->ARR = 1000;		// Ustawiamy okres (1000 µs = 1 kHz)

	 TIM3->CR1 |= TIM_CR1_ARPE; // Włączamy buforowanie (płynność)




}
