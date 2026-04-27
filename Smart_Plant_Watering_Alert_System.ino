const int soilSensor = A0;
const int led1       = 6;  // BLINK LED — dry soil alert
const int led2       = 8;  // NORMAL LED — wet soil

int soilValue = 0;
int dryValue  = 500; // adjust if needed

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  soilValue = analogRead(soilSensor);

  Serial.print("Soil Value: ");
  Serial.println(soilValue);

  // ===== DRY SOIL = led1 BLINKS =====
  if (soilValue < dryValue) {
    digitalWrite(led2, LOW);   // led2 OFF

    // led1 blinks fast
    digitalWrite(led1, HIGH);
    delay(200);
    digitalWrite(led1, LOW);
    delay(200);
  }

  // ===== WET SOIL = led2 ON NORMALLY =====
  else {
    digitalWrite(led1, LOW);   // led1 OFF
    digitalWrite(led2, HIGH);  // led2 ON steady
    delay(500);
  }
}
