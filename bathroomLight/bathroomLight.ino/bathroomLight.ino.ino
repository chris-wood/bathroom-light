const int greenLEDpin = 9;
const int redLEDpin = 11;
const int blueLEDpin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(greenLEDpin, OUTPUT);
  pinMode(redLEDpin, OUTPUT);
  pinMode(blueLEDpin, OUTPUT);
}


void loop() {

redSensorValue = analogRead(redSensorPin);
delay(5);
greenSensorValue = analogRead(greenSensorPin);
delay(5);
blueSensorValue = analogRead(blueSensorPin);

Serial.print("Raw Sensor Values \t Red: ");
Serial.print(redSensorValue);
Serial.print("\t Green: ");
Serial.print(greenSensorValue);
Serial.print("\t Blue: ");
Serial.println(blueSensorValue);

redValue = 255 - (redSensorValue/4);
greenValue = 255 - (greenSensorValue/4);
blueValue = 255 - (blueSensorValue/4);

Serial.print("Mapped Sensor Values \tRed: ");
Serial.print(redValue);
Serial.print("\t Green: ");
Serial.print(greenValue);
Serial.print("\t Blue: ");
Serial.println(blueValue);

  if (redValue < 40){
    analogWrite(redLEDpin, 0);
    analogWrite(greenLEDpin, 0);
    analogWrite(blueLEDpin, 0);
  }
  else{
    analogWrite(redLEDpin, redValue);
    analogWrite(greenLEDpin, greenValue);
    analogWrite(blueLEDpin, blueValue);

  }
}
