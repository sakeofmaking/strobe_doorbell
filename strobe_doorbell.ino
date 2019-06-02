/* 
 *  Strobe Doorbell
 * 
 * Purpose: Transmitter triggers momentary high on D2 of receiver. D2 feeds into D0 of uC. 
 * D4 of uC triggers transistor for 10 sec. Transistor enables strobe for 10 sec.
 */

const int rfReceiver = 0;   // pin number of RF Receiver
const int transistor = 4;        // pin number of the transistor

boolean rfState = LOW;

void setup() {
  // Initialize pins as output and input
  pinMode(rfReceiver, INPUT);
  pinMode(transistor, OUTPUT);
}

// Loop forever 
void loop() {
  // Read the state from the RF Receiver
  rfState = digitalRead(rfReceiver);

  // If state changes, trigger relay momentarily
  if(rfState == HIGH){
    digitalWrite(transistor, HIGH); 
    delay(10000);
    digitalWrite(transistor, LOW);
  }

}
