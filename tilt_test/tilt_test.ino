//----------------------------------------
// Pin declarations
//----------------------------------------

// Tilt switches
const int tilt1 = 2;
const int tilt2 = 3;
const int tilt3 = 4;
const int tilt4 = 5;

// LED
const int led = 8;

//----------------------------------------
// Setup
//----------------------------------------

void setup() {
  // Set all tilt switches as digital inputs.
  pinMode(tilt1, INPUT);
  pinMode(tilt2, INPUT);
  pinMode(tilt3, INPUT);
  pinMode(tilt4, INPUT);

  // Set LED as digital output.
  pinMode(led, OUTPUT);

  // Initialize serial monitor.
  Serial.begin(9600);
}

//----------------------------------------
// Main loop
//----------------------------------------

void loop() {
  // Get state of tilt switches; 0 = not tilted/is connected,
  // 1 = tilted/not connected.
  int tilt1_tilt = digitalRead(tilt1);
  int tilt2_tilt = digitalRead(tilt2);
  int tilt3_tilt = digitalRead(tilt3);
  int tilt4_tilt = digitalRead(tilt4);

  // Print states of tilt switches.
  Serial.print("Tilt1: ");
  Serial.println(tilt1_tilt);
  Serial.print("Tilt2: ");
  Serial.println(tilt2_tilt);
  Serial.print("Tilt3: ");
  Serial.println(tilt3_tilt);
  Serial.print("Tilt4: ");
  Serial.println(tilt4_tilt);
  Serial.println();
  
  // Check if all tilt switches are NOT tilted because tilt = 1
  // due to active low inputs through pull-up resistors,
  // and turn on LED if all tilt switches are NOT tilted aka
  // if the board is level and balanced.
  if (!tilt1_tilt && !tilt2_tilt && !tilt3_tilt && !tilt4_tilt) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  
  delay(100);
}
