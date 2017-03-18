
import java.awt.Robot; //java library that lets us take screenshots
import java.awt.AWTException;
import java.awt.event.InputEvent;
import java.awt.image.BufferedImage;
import java.awt.Rectangle;
import java.awt.Dimension;
import processing.serial.*; //library for serial communication

Serial port; //creates object "port" of serial class
Robot robby; //creates object "robby" of robot class

void setup()
{
  port = new Serial(this, Serial.list()[0],9600); //set baud rate
  size(100, 100); //window size (doesn't matter)
  try //standard Robot class error check
  {
    robby = new Robot();
  }
  catch (AWTException e)
  {
    println("Robot class not supported by your system!");
    exit();
  }
}
void draw()
{
  int pixel; //ARGB variable with 32 int bytes where
  //sets of 8 bytes are: Alpha, Red, Green, Blue Alpha is for opacity
  float r=0;
  float g=0;
  float b=0;
  //get screenshot into object "screenshot" of class BufferedImage
  BufferedImage screenshot = robby.createScreenCapture(new Rectangle(new Dimension(1920,1080)));
  //1920*1080 is the screen resolution
  int i=0;
  int j=0;
  //1920*1080
  //We can skip every alternate pixel and make the program run four times faster with no visible effect.
  for(i =0;i<1920;i++){
    for(j=0; j<1080;j++){
      pixel = screenshot.getRGB(i,j); //the ARGB integer has the colors of pixel (i,j)
      r = r+(int)(255&(pixel>>16)); //add up reds
      g = g+(int)(255&(pixel>>8)); //add up greens
      b = b+(int)(255&(pixel)); //add up blues
    }
  }
  r=r/(1920*1080); //average red
  g=g/(1920*1080); //average green
  b=b/(1920*1080); //average blue
  System.out.println(r);
  System.out.println(g);
  System.out.println(b);
  
  port.write(0xff); //write marker (0xff) for synchronization
  port.write((byte)(r)); //write red value
  port.write((byte)(g)); //write green value
  port.write((byte)(b)); //write blue value
  delay(10); //delay for safety
  background(r,g,b); //make window background average color
}
