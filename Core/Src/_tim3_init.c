



#include "stm32g0xx_hal.h"
#include "_tim3_init.h"



 void _tim3_init (void){

//----------------------------------------------------------------
	 //konfiguracja timera
	 // --- CZĘŚĆ 1: OTWARCIE clocka  ---

	 RCC->APBENR1 |= RCC_APBENR1_TIM3EN;		//(Włączamy zegar)
	 (void)RCC->APBENR1;						// Czekamy,  AZ prad zegara dotrze do TIM3 -naturalny delay


	 // --- CZĘŚĆ 2: USTAWIANIE MASZYNY (Seria poleceń) ---
	 TIM3->PSC = 63;			// Ustawiamy podział (64 mln / 64 = 1 MHz)  ( pamietaj ze procek dodal sobie 63+1 )
	 TIM3->ARR = 1000;		// Ustawiamy okres (1000 µs = 1 kHz)

	 TIM3->CR1 |= TIM_CR1_ARPE;		//Włączamy buforowanie (płynność)

	 // --- CZĘŚĆ 3: ZATWIERDZENIE (Opcjonalnie, ale profesjonalnie) ---
	 TIM3->EGR |= TIM_EGR_UG;//- przepisz PSC i ARR do mechanizmu teraz!
//--------------------------------------------------------------------------


	 //1. Wybór trybu PWM Mode 1 w rejestrze CCMR1
	 // CC1S[1:0] = 00 (Output mode) - RM0444 Rozdział 22.4.7

	 // (Output mode)-w tym trybie mozemy dopiero skonfigurowac dalsza czesc rejestru dla trybu PWM
	 // zerowanie przestrzeni OC1M[2:0] - 					(7U<<4)
	 // + zerowanie przestrzeni  OCIM[3] -  				(1U<<16)
	  //+ ustawienie (Output mode) na CC1S ( czyli 00 ) -   (3U<<0)
	 TIM3->CCMR1 &= ( ~( (1U<<16) | (7U<<4) | (3U<<0) )  );

	 //0110: PWM mode 1
	 TIM3->CCMR1 |= (6U<<4);
	 TIM3->CCMR1 |= (1U<<3);

	 TIM3->CCER |= (1U << 0);
	 TIM3->CCR1 = 500U;













	 // --- CZĘŚĆ 4: START! ---
	 TIM3->CR1 |= TIM_CR1_CEN;	// Maszyna rusza!


}
