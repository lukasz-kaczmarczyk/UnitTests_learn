#include "bcm2835.h"

void pinMode(uint8_t pin, uint8_t mode);
int bcm2835_init();
void bcm2835_gpio_fsel(uint8_t pin, uint8_t mode);

int inits(){
    return bcm2835_init();
}

void pinMode(uint8_t pin, uint8_t mode){
    bcm2835_gpio_fsel(pin, mode);
}

int bcm2835_init()
{
	return 1;
}

void bcm2835_gpio_fsel(uint8_t pin, uint8_t mode)
{
	;
}
