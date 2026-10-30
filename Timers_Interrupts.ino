#define LED_Blink_Pin  0  // Blinking led PB0
#define LED_Fade_Pin   1  // Fading led PB1
#define LED_Extra_Pin  2  // Extra led PB2

#define BUTTON_1_Pin   2  // Button_1 PD2
#define BUTTON_2_Pin   3  // Button_2 PD3


int speedOptions[] = {63, 31, 16};     // Different speed values
int currentSpeedIndex = 0;

int brightnessOptions[] = {0, 80, 160, 255}; // Different brightness values
int currentBrightnessIndex = 0;

volatile int blinkCounter = 0;
volatile int blinkInterval = 63;

void setup() {
  // Inputs & Outputs
  DDRB |= (1 << LED_Blink_Pin) | (1 << LED_Fade_Pin) | (1 << LED_Extra_Pin);
  DDRD &= ~((1 << BUTTON_1_Pin) | (1 << BUTTON_2_Pin));
  
  // Pull_up 
  PORTD |= (1 << BUTTON_1_Pin) | (1 << BUTTON_2_Pin);
  
  // Turning on the extra led (system working)
  PORTB |= (1 << LED_Extra_Pin);

  // CTC Mode
  TCCR0A = (1 << WGM01);                      // CTC
  TCCR0B = (1 << CS02) | (1 << CS00);         // Prescaler = 1024
  OCR0A = 249;    
  TIMSK0 = (1 << OCIE0A);                     // Compare Match

  // Fast PWM Mode
  TCCR1A = (1 << COM1A1) | (1 << WGM10);      // Fast PWM 8-bit, Non-inverting
  TCCR1B = (1 << WGM12) | (1 << CS11);        // Prescaler = 8
  OCR1A = brightnessOptions[currentBrightnessIndex]; 

  // Normal Mode
  TCCR2A = 0;                                 // Normal Mode
  TCCR2B = (1 << CS22) | (1 << CS21) | (1 << CS20); // Prescaler = 1024

  sei();
}

void loop() {
   
  // Button_1 is pressed
  if (!(PIND & (1 << BUTTON_1_Pin))) {
    Delay(2);  
    
    if (!(PIND & (1 << BUTTON_1_Pin))) {
    
      // Change speed
      currentSpeedIndex = (currentSpeedIndex + 1) % 3;
      blinkInterval = speedOptions[currentSpeedIndex];
    
      // Wait until unpressed
      while (!(PIND & (1 << BUTTON_1_Pin)));
    }
  }

  // Button_2 is pressed
  if (!(PIND & (1 << BUTTON_2_Pin))) {
    Delay(2);  
    
    if (!(PIND & (1 << BUTTON_2_Pin))) {

      // Change brightness
      currentBrightnessIndex = (currentBrightnessIndex + 1) % 4;
      OCR1A = brightnessOptions[currentBrightnessIndex];
    
      // Wait until unpressed
      while (!(PIND & (1 << BUTTON_2_Pin)));
    }
  }
}

// Blinking
ISR(TIMER0_COMPA_vect) {
  blinkCounter++;

  if (blinkCounter >= blinkInterval) {
    PORTB ^= (1 << LED_Blink_Pin);  // Toggle
    blinkCounter = 0;
  }
}

// Delay function
void Delay(unsigned int delayTicks) {
  for (unsigned int i = 0; i < delayTicks; i++) {
    TCNT2 = 0;                            
    TIFR2 |= (1 << TOV2);                 
    while ((TIFR2 & (1 << TOV2)) == 0);   
  }
}