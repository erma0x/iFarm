// the Arduino pin, which connects to the IN pin of relay
const int RELAY_PIN_1 = 7;  
const int RELAY_PIN_2 = 8;  
const int RELAY_PIN_3 = 9; 

int SOIL_SENSOR = A0;
const int WATER_THRESHOLD = 700;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(SOIL_SENSOR, INPUT);
}

void loop() {
  int water;
  water = analogRead(SOIL_SENSOR);
  Serial.println(water);

  if (water > WATER_THRESHOLD ) {
  
    digitalWrite(RELAY_PIN_1, LOW);
    digitalWrite(RELAY_PIN_2, LOW);
    digitalWrite(RELAY_PIN_3, LOW);

    Serial.println("water");
    delay(10000);
  }

  delay(15000);
  
  if (water < WATER_THRESHOLD) {
    
    digitalWrite(RELAY_PIN_1, HIGH);
    digitalWrite(RELAY_PIN_2, HIGH);
    digitalWrite(RELAY_PIN_3, HIGH);
    
    Serial.println("no water");
    delay(10000);

  }
  delay(60000);  
}
