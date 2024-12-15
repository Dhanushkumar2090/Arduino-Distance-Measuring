int triggerPin = 7;
int echoPin = 8;
int triggerPin1 = 5;
int echoPin1 = 6;
int LED = 13;
int info = 0;
int state = 0;
int info1 = 0;
int state1 = 0;
void bluetooth()
{
if(Serial.available() > 0)
{
info = Serial.read();
state = 0;
}
if(info == '1')
{
digitalWrite(LED, HIGH);
if(state == 0)
{
Serial.println("LED ON");
state = 1;
}
}
else if(info == '0')
{
digitalWrite(LED, LOW);
if(state == 0)
{
Serial.println("LED OFF");
state = 1;
}
}
}
void sensor() {
}

int duration, distance;
digitalWrite(triggerPin, HIGH);
delay(10);
digitalWrite(triggerPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
Serial.print("LEFT: ");
Serial.print(distance);
Serial.print("cm");
Serial.println(" ");
if(distance <= 5)
{
digitalWrite(LED, LOW);
Serial.println("TOO CLOSE!!!");
delay(2000);
}
}//2
void bluetooth1()
{
if(Serial.available() > 0){
info1 = Serial.read();
state1 = 0;
}
if(info1 == '1')
{
digitalWrite(LED, HIGH);
if(state1 == 0)
{
Serial.println("LED ON");
state1 = 1;
}
}
else if(info1 == '0')
{
digitalWrite(LED, LOW);
if(state1 == 0)
{
Serial.println("LED OFF");
state1 = 1;
}
}
}

void sensor1()
{
int duration, distance;
digitalWrite(triggerPin1, HIGH);
delay(10);
digitalWrite(triggerPin1, LOW);
duration = pulseIn(echoPin1, HIGH);
distance = (duration/2) / 29.1;
Serial.print("RIGHT: ");
Serial.print(distance);
Serial.print("cm");
Serial.println(" ");
if(distance <= 5){
digitalWrite(LED, LOW);
Serial.println("TOO CLOSE!!!");
delay(2000);
}
}
void setup()
{
Serial.begin(9600);
pinMode(triggerPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(triggerPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(LED, OUTPUT);
digitalWrite(LED, LOW);
}
void loop()
{
bluetooth();
sensor();
delay(1000);
bluetooth1();
sensor1();
delay(1000)