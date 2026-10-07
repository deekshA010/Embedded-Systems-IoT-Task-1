const int tempPin = A0;
const int ledPin = 8;
const int buzzerPin = 9;

const float threshold = 30.0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  Serial.println("Smart Temperature Monitoring System");
  Serial.println("-----------------------------------");
}

void loop() {

  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * (5.0 / 1023.0);

  float temperature = (voltage - 0.5) * 100.0;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature >= threshold) {

    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);

    Serial.println("ALERT: Temperature is HIGH!");

  }
  else {

    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);

    Serial.println("Status: Temperature is NORMAL.");
  }

  Serial.println();

  delay(1000);
}
