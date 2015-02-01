#include <Servo.h> 
#include "angles.h"

#include "pins.h"
     

Servo servo[8];


int pos = 0; 
int input=0;
//void Initialize()
//{
//    //Initialization
//  
//    KneeBL.write(180);
//    KneeBR.write(180);
//    KneeFL.write(180);
//    KneeFR.write(180);
////  
//    HipBL.write(45);
//    HipBR.write(135);
//    HipFL.write(135);
//    HipFR.write(45); 
//  
//}

void setup() 
{ 
//  KneeBL.attach(5);  
//  KneeBR.attach(7);
//  KneeFL.attach(11);  
//  KneeFR.attach(13);
//  
//  HipBL.attach(4);  
//  HipBR.attach(6);
//  HipFL.attach(10);  
//  HipFR.attach(12);


  Serial.begin(9600);
   Serial.println("Hello world");
    for(int i=0;i<8;i++)
       servo[i].attach(servo_pin[i]);
       
       stand_up();

  //Initialization
//  Initialize();
  
} 

void stand_up()
{
  for(int i=0;i<8;i++)
    servo[i].write(stand_position[i]);  // Set the positions of the servos to the postions in the "angles.h" file
}

void move_servo(int x,int y)
{
  servo[x].write(servo[x].read()+y); // Read the current position of Servo 'x' and move it by 'y' degrees
}



void forward()
{
 /////  
 for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(0,-1);
    move_servo(2,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Move the Left Front and Right Rear legs forward
  {
    move_servo(4,+1);
    move_servo(6,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Lower the Left front and Right Rear legs
  {
    move_servo(0,+1);
    move_servo(2,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)       // Move the Left Front and Right Rear legs back &
  {                                     // Raise the Right Front and Left Rear legs
    move_servo(4,-1);
    move_servo(6,+1);
    move_servo(1,-1);
    move_servo(3,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Right Front and Left Rear legs forward
  {
    move_servo(5,-1);
    move_servo(7,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Lower the Right Front and Left Rear legs 
  {
    move_servo(1,+1);
    move_servo(3,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Right Front and Left Rear legs back
  {
    move_servo(5,+1);
    move_servo(7,-1);
    delay(delay_time); 
  }  

  
// ////////////////////////////////////////
  
}



void backward()
{
  // //////////////////////////////////////
 
  for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(0,-1);
    move_servo(2,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Move the Left Front and Right Rear legs back
  {
    move_servo(4,-1);
    move_servo(6,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Lower the Left front and Right Rear legs
  {
    move_servo(0,+1);
    move_servo(2,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)       // Move the Left Front and Right Rear legs forward &
  {                                     // Raise the Right Front and Left Rear legs
    move_servo(4,+1);
    move_servo(6,-1);
    move_servo(1,-1);
    move_servo(3,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Right Front and Left Rear legs back
  {
    move_servo(5,+1);
    move_servo(7,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Lower the Right Front and Left Rear legs 
  {
    move_servo(1,+1);
    move_servo(3,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Right Front and Left Rear legs forward
  {
    move_servo(5,-1);
    move_servo(7,+1);
    delay(delay_time); 
  }
// ////////////////////////////////////////
  
}



void step_right()
{
  // //////////////////////////////////////
 
 for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(0,-1);
    move_servo(2,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Move the Left Front leg forward and Right Rear leg backward
  {
    move_servo(4,+1);
    move_servo(6,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Lower the Left front and Right Rear legs
  {
    move_servo(0,+1);
    move_servo(2,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)       // Move the Left Front leg backward, Right Rear leg forward &
  {                                     // Raise the Right Front and Left Rear legs
    move_servo(4,-1);
    move_servo(6,-1);
    move_servo(1,-1);
    move_servo(3,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Left Rear leg forward and Right Front leg backward
  {
    move_servo(5,+1);
    move_servo(7,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Lower the Right Front and Left Rear legs 
  {
    move_servo(1,+1);
    move_servo(3,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Left Rear leg backward and Right Front leg forward
  {
    move_servo(5,-1);
    move_servo(7,-1);
    delay(delay_time); 
  } 
//////  
  
// ////////////////////////////////////////
  
}



void step_left()
{
  // //////////////////////////////////////
 
 for(int i=0;i<displacement;i++)      // Raise the Left Front and Right Rear legs
  {
    move_servo(0,-1);
    move_servo(2,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Move the Left Front leg backward and Right Rear leg forward
  {
    move_servo(4,-1);
    move_servo(6,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)      // Lower the Left front and Right Rear legs
  {
    move_servo(0,+1);
    move_servo(2,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)       // Move the Left Front leg forward, Right Rear leg backward &
  {                                     // Raise the Right Front and Left Rear legs
    move_servo(4,+1);
    move_servo(6,+1);
    move_servo(1,-1);
    move_servo(3,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Left Rear leg backward and Right Front leg forward
  {
    move_servo(5,-1);
    move_servo(7,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Lower the Right Front and Left Rear legs 
  {
    move_servo(1,+1);
    move_servo(3,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)        // Move the Left Rear leg forward and Right Front leg backward
  {
    move_servo(5,+1);
    move_servo(7,+1);
    delay(delay_time); 
  }  
// ////////////////////////////////////////
  
}


void continous_forward()
{
  for(int i=0;i<displacement;i++)          // Raise the Left Front and Right Rear legs
  {
    move_servo(0,-1);
    move_servo(2,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)          // Move the Left Front and Right Rear legs forward
  {
    move_servo(4,+1);
    move_servo(6,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)          // Lower the Left Front and Right Rear legs
  {
    move_servo(0,+1);
    move_servo(2,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)          // Move the Left Front and Right Rear legs backward twice the displacement & 
  {                                        // Raise the Right Front and Left Rear legs
    move_servo(4,-2);
    move_servo(6,+2);
    move_servo(1,-1);
    move_servo(3,-1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)          // Move the Right Front and Left Rear Legs forward
  {
    move_servo(5,-1);
    move_servo(7,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)          // Lower the Right Front and Left Rear legs
  {
    move_servo(1,+1);
    move_servo(3,+1);
    delay(delay_time); 
  }
  for(int i=0;i<displacement;i++)          // Move the Right Front and Left Rear legs backward twice the displacement
  {                                        // Raise the Left Front and Right Rear legs
    move_servo(5,+2);
    move_servo(7,-2);
    move_servo(0,-1);
    move_servo(2,-1);
    delay(delay_time); 
  }

 // irrecv.resume(); 
  //results.value=0;

  while(1)                       // Enter an infinite while loop
  {
    if(Serial.available() > 0)  // Break when there is incoming Remote data
      
        break;
    

    for(int i=0;i<displacement;i++)        // Move the Left Front and Right Rear legs forward twice the displacement
    {
      move_servo(4,+2);
      move_servo(6,-2);
      delay(delay_time); 
    }
    for(int i=0;i<displacement;i++)        // Lower the Left Front and Right Rear legs
    {
      move_servo(0,+1);
      move_servo(2,+1);
      delay(delay_time); 
    }
    for(int i=0;i<displacement;i++)        // Move the Left Front and Right Rear legs backward twice the displacement
    {                                      // Raise the Right Front and Left Rear legs
      move_servo(4,-2);
      move_servo(6,+2);
      move_servo(1,-1);
      move_servo(3,-1);
      delay(delay_time); 
    }

    if(Serial.available() > 0)
      
        break;
    

    for(int i=0;i<displacement;i++)        // Move the Right Front and Left Rear legs forward twice the displacement 
    {
      move_servo(5,-2);
      move_servo(7,+2);
      delay(delay_time); 
    }
    for(int i=0;i<displacement;i++)        // Lower the Right Front and Left Rear legs
    {
      move_servo(1,+1);
      move_servo(3,+1);
      delay(delay_time); 
    }
    for(int i=0;i<displacement;i++)        // Move the Right Front and Left Rear legs backward, twice the displacement
    {                                      // Raise the Left Front and Right Rear legs
      move_servo(5,+2);
      move_servo(7,-2);
      move_servo(0,-1);
      move_servo(2,-1);
      delay(delay_time); 
    }
  }  
  stand_up();                    // Stand up when the while loop breaks
}


void stretch()
{
  for(int i=0;i<stretch_displacement;i++)        // Stretch the bot towards the left
  {                                      
    move_servo(0,-1);
    move_servo(1,+1);
    move_servo(2,+1);
    move_servo(3,-1);
    delay(stretch_delay_time); 
  }
  delay(500);
  for(int i=0;i<stretch_displacement;i++)        // Stretch the bot towards the right
  {                                       
    move_servo(0,+2);
    move_servo(1,-2);
    move_servo(2,-2);
    move_servo(3,+2);
    delay(stretch_delay_time); 
  }
  delay(500);
  for(int i=0;i<stretch_displacement;i++)        // Bring it back to initial position
  {                                      
    move_servo(0,-1);
    move_servo(1,+1);
    move_servo(2,+1);
    move_servo(3,-1);
    delay(stretch_delay_time); 
  }
  delay(500);

  for(int i=0;i<stretch_displacement;i++)        // Stretch the bot towards the back
  {                                       
    move_servo(4,+1);
    move_servo(5,-1);
    move_servo(6,-1);
    move_servo(7,+1);
    delay(stretch_delay_time); 
  }
  delay(500);
  for(int i=0;i<stretch_displacement;i++)        // Stretch the bot towards the front
  {                                       
    move_servo(4,-2);
    move_servo(5,+2);
    move_servo(6,+2);
    move_servo(7,-2);
    delay(stretch_delay_time); 
  }
  delay(500);
  for(int i=0;i<stretch_displacement;i++)        // Bring it back to initial position
  {                                       
    move_servo(4,+1);
    move_servo(5,-1);
    move_servo(6,-1);
    move_servo(7,+1);
    delay(stretch_delay_time); 
  }
  delay(500);
}


void loop() 
{ 


   if (Serial.available() > 0)
{ 
  
  input = Serial.read();
  //Serial.print("I received:");
  //Serial.println(input,DEC);
  //Serial.println(input);
  
  if (input == 1)
  {
   
    stretch();
   stand_up();
    }
  if (input == 2)
  {
    
    continous_forward();
     stand_up();
  }
  if (input == 3)
  {
    
    step_left();
     stand_up();
  }

  if (input == 4)
  {
    
    forward();
    stand_up();
  }
}

}


