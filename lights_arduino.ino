int red, green, blue; 
int RedPin = 10;
int GreenPin = 9; 
int BluePin = 11; 
int threshold = 150; 
int volume;

void setup() 
{                
  Serial.begin(9600);  
  Serial.flush();
}

void loop() {
  
  volume = analogRead(A0); // Reads the value from the Analog PIN A0
  Serial.println(volume);
  //Serial.println();
  delay(10);

  if (Serial.available()>=4)
  {
    if(Serial.read() == 0xff)
    {
      red = Serial.read();
      green= Serial.read();
      blue = Serial.read();
    }
  }
  
  if(volume<=threshold)
  {
    analogWrite (RedPin, red);
    analogWrite (GreenPin, green);
    analogWrite (BluePin, blue);
    delay(100); //just to be safe
  }  

  else
  {
    analogWrite (RedPin,0);
    analogWrite (GreenPin,0);
    analogWrite (BluePin,0);
  }
  
 

}
