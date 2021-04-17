#define SC1 D1
#define SC2 D2 
#define M1 D5
#define M2 D6
#define M3 D7
#define M4 D8

#define trigPin D3
#define echoPin D4

long duration;
int distance;

int spd=200;

void forward()
{
  analogWrite(SC1, spd); 
  analogWrite(SC2, spd); 
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
  delay(50);
  Serial.println("FORWARD");
}

void backward()
{
  analogWrite(SC1, spd);
  analogWrite(SC2, spd);
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  delay(50);
  Serial.println("BACKWARD");
}

void left()
{
  analogWrite(SC1, spd); 
  analogWrite(SC2, spd); 
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
  delay(50);
  Serial.println("LEFT");
}

void right()
{
  analogWrite(SC1, spd);
  analogWrite(SC2, spd); 
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  delay(50);
  Serial.println("RIGHT");
}

void STOP()
{
 
  analogWrite(SC1, spd);
  analogWrite(SC2, spd);
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
  delay(50);
  Serial.println("STOP");
}

void ultrasonic()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.println("Distance: ");
  Serial.print(distance);
  delay(100);
}

void setup() {
  pinMode(SC1,OUTPUT);
  pinMode(SC2,OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  ultrasonic();
  if(distance>20)
  {
     forward();
  }
  else
  {
      STOP();
      backward();
      delay(1000);
      STOP();
      int i=random(100);
      if(i%2==0)
      {
          left();
          delay(1000);
          STOP();
    }
    else
    {
          right();
          delay(1000);
          STOP();
   } 
  }
}
 
