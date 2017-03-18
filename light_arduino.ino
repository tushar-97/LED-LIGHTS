int red, green, blue; //red, green and blue values
int RedPin = 10; //Red pin 9 has a PWM
int GreenPin = 11; //Green pin 10 has a PWM
int BluePin = 9; //Blue pin 11 has a PWM
void setup()
{
Serial.begin(9600);
  //initial values (no significance)
  int red ;
  int blue;
  int green;
}
void loop()
{
//protocol expects data in format of 4 bytes
  //(xff) as a marker to ensure proper synchronization always
  //fol0ed by red, green, blue bytes
  if (Serial.available()>=4) {
    if(Serial.read() == 0xff){
      red = Serial.read();
      green= Serial.read();
      blue = Serial.read();
    }
  }
  //finally control led brightness through pulse-width modulation
  
  /*if(red>green && red>blue) {analogWrite(RedPin , 255); analogWrite(GreenPin , 0); analogWrite(BluePin , 0);}
  else if(green>red && green>blue){ analogWrite(GreenPin , 255); analogWrite(RedPin , 0); analogWrite(BluePin , 0);}
  else if(blue>green && blue>red){ analogWrite(BluePin , 255); analogWrite(RedPin , 0); analogWrite(GreenPin , 0);}*/
 
  
  analogWrite (RedPin, red);
  analogWrite (GreenPin, green);
  analogWrite (BluePin, blue);
  delay(10); //just to be safe
}
