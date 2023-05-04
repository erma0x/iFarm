int RELAY_PIN = 8;
int SOIL_SENSOR = A0;
void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(SOIL_SENSOR, INPUT);
}
void loop() {
  int water;
  water=analogRead(SOIL_SENSOR);
  Serial.println(water);
  if (water > 900){
    digitalWrite(RELAY_PIN, HIGH);
    delay(10000);
    digitalWrite(RELAY_PIN, LOW);
  }
 delay(60000);
}

