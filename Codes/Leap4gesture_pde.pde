import com.onformative.leap.*;
import org.firmata.*;
import cc.arduino.*;
import processing.serial.*;
import com.leapmotion.leap.Gesture;
import com.leapmotion.leap.SwipeGesture;
import com.leapmotion.leap.CircleGesture;
import com.leapmotion.leap.ScreenTapGesture;
import com.leapmotion.leap.KeyTapGesture;
import com.leapmotion.leap.Gesture.State;
import com.onformative.leap.LeapMotionP5;
import com.leapmotion.leap.Hand;
LeapMotionP5 leap;
float backgroundColor;

Serial myPort;
PImage bg;
public void setup() {
  size(300, 300);
  //String portName = Serial.list()[4];
  // setting up the serial connection through chosen port
  myPort = new Serial(this, "COM6", 9600);
  
   //dont generate a serialEvent() unless you get a newline character from arduino:
 myPort.bufferUntil('\n');
 leap = new LeapMotionP5(this);
leap.enableGesture(Gesture.Type.TYPE_SWIPE);
leap.enableGesture(Gesture.Type.TYPE_CIRCLE);
leap.enableGesture(Gesture.Type.TYPE_KEY_TAP);
leap.enableGesture(Gesture.Type.TYPE_SCREEN_TAP);
backgroundColor = (0);

}

public void draw() {
  background(backgroundColor);
  for (Hand hand : leap.getHandList()) {
    PVector handPos = leap.getPosition(hand);
    ellipse(handPos.x, handPos.y, 20, 20);
  }
}
public void circleGestureRecognized(CircleGesture gesture, String clockwiseness) {
      if (gesture.state() == State.STATE_STOP) {
        println("//////////////////////////////////////");
        println("Gesture type: " + gesture.type().toString());
        println("ID: " + gesture.id());
        println("Radius: " + gesture.radius());
        println("Normal: " + gesture.normal());
        println("Turns: " + gesture.progress());
        println("Clockwiseness: " + clockwiseness);
        println("Turns: " + gesture.progress());
        println("Center: " + leap.vectorToPVector(gesture.center()));
        println("Duration: " + gesture.durationSeconds() + "s");
        println("//////////////////////////////////////");
      if(clockwiseness == "clockwise")
      {
        backgroundColor = 255;
        myPort.write(1);
      }
      else
      {
        backgroundColor = 0;
         myPort.write(2);
      }
      }
      else if (gesture.state() == State.STATE_START) {}
      else if (gesture.state() == State.STATE_UPDATE) {}
  }
      
public void swipeGestureRecognized(SwipeGesture gesture) {
if (gesture.state() == State.STATE_STOP) {
      println("//////////////////////////////////////");
       println("Gesture type: " + gesture.type());
      println("ID: " + gesture.id());
    println("Position: " + leap.vectorToPVector(gesture.position()));
println("Direction: " + gesture.direction());
println("Duration: " + gesture.durationSeconds() + "s");
println("Speed: " + gesture.speed());
println("//////////////////////////////////////");
if(gesture.direction().getX() > 0)
{
  myPort.write(3);
  println("Right Swipe");
}
else
{
  myPort.write(4);
  println("Left Swipe");
}

  for (Hand hand : leap.getHandList())
  {
    PVector handPos = leap.getPosition(hand);
    if(handPos.y > 200)     {      
  }  
  }
}
else if (gesture.state() == State.STATE_START) {   }  
else if (gesture.state() == State.STATE_UPDATE) {   } 
} 

public void screenTapGestureRecognized(ScreenTapGesture gesture) {
  if (gesture.state() == State.STATE_STOP) {
    System.out.println("//////////////////////////////////////");
    System.out.println("Gesture type: " + gesture.type());
    System.out.println("ID: " + gesture.id());
    System.out.println("Position: " + leap.vectorToPVector(gesture.position()));
    System.out.println("Direction: " + gesture.direction());
    System.out.println("Duration: " + gesture.durationSeconds() + "s");
    System.out.println("//////////////////////////////////////");
    println("SCREEN TAP");
    myPort.write(5);
  } 
  else if (gesture.state() == State.STATE_START) {
  } 
  else if (gesture.state() == State.STATE_UPDATE) {
  }
}

public void KeyTapGestureRecognized(KeyTapGesture gesture) {
  if (gesture.state() == State.STATE_STOP) {
    System.out.println("//////////////////////////////////////");
    System.out.println("Gesture type: " + gesture.type());
    System.out.println("ID: " + gesture.id());
    System.out.println("Position: " + leap.vectorToPVector(gesture.position()));
    System.out.println("Direction: " + gesture.direction());
    System.out.println("Duration: " + gesture.durationSeconds() + "s");
    System.out.println("//////////////////////////////////////");
    println("KEY TAP");
    myPort.write(6);
  
} 
  else if (gesture.state() == State.STATE_START) {
  } 
  else if (gesture.state() == State.STATE_UPDATE) {
  }
}

public void stop() {
  leap.stop();
}


