
#include "JoyStickUtils.h"


//right now, the library does NOT support hot pluggable controllers, meaning 
//you must always either restart your Arduino after you conect the controller, 
//or call config_gamepad(pins) again after connecting the controller.


void setup(){
  Serial.begin(115200);

}

void loop(){
   /* You must Read Gamepad to get new values
   Read GamePad and set vibration values
   ps2x.read_gamepad(small motor on/off, larger motor strenght from 0-255)
   if you don't enable the rumble, use ps2x.read_gamepad(); with no values
   
   you should call this at least once a second
   */
   
    ps2x.read_gamepad(false, vibrate);          //read controller and set large motor to spin at 'vibrate' speed
    
    if(ps2x.Button(PSB_START))                   //will be TRUE as long as button is pressed
      Serial.println("Start is being held");
    if(ps2x.Button(PSB_SELECT))
      Serial.println("Select is being held");
         
    if(ps2x.Button(PSB_PAD_UP)) {         //will be TRUE as long as button is pressed
      Serial.println("UP is being held");
    }
    if(ps2x.Button(PSB_PAD_RIGHT)){
      Serial.println("Right is being held");
    }
    if(ps2x.Button(PSB_PAD_LEFT)){
      Serial.println("LEFT is being held");
    }
    if(ps2x.Button(PSB_PAD_DOWN)){
      Serial.println("DOWN is being held");
    }   
    
    if (ps2x.NewButtonState())               //will be TRUE if any button changes state (on to off, or off to on)
    {
        if(ps2x.Button(PSB_L3))
          Serial.println("L3 pressed");
        if(ps2x.Button(PSB_R3))
          Serial.println("R3 pressed");
        if(ps2x.Button(PSB_L2))
          Serial.println("L2 pressed");
        if(ps2x.Button(PSB_R2))
          Serial.println("R2 pressed");
    }   
         
    if(ps2x.ButtonPressed(PSB_RED))             //will be TRUE if button was JUST pressed
          Serial.println("Circle just pressed");

    if(ps2x.ButtonReleased(PSB_RED))             //will be TRUE if button was JUST released
          Serial.println("Circle just released"); 


    if(ps2x.ButtonPressed(PSB_PINK))             //will be TRUE if button was JUST pressed
          Serial.println("Square just pressed");
                  
    if(ps2x.ButtonReleased(PSB_PINK))             //will be TRUE if button was JUST released
          Serial.println("Square just released");     

    if(ps2x.ButtonPressed(PSB_GREEN))             //will be TRUE if button was JUST pressed
          Serial.println("Triangle just pressed");
                  
    if(ps2x.ButtonReleased(PSB_GREEN))             //will be TRUE if button was JUST released
          Serial.println("Triangle just released");   

    if(ps2x.ButtonPressed(PSB_BLUE))             //will be TRUE if button was JUST pressed
          Serial.println("X just pressed"); 
                  
    if(ps2x.ButtonReleased(PSB_BLUE))             //will be TRUE if button was JUST released
         Serial.println("X just released");   

         
    //if(ps2x.NewButtonState(PSB_BLUE))            //will be TRUE if button was JUST pressed OR released
    //     Serial.println("X just changed");    
    
    if(ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) // print stick values if either is TRUE
    {
        Serial.print("Stick Values:");
        Serial.print(ps2x.Analog(PSS_LY), DEC); // LY
        Serial.print(",");
        Serial.print(ps2x.Analog(PSS_LX), DEC); // LX
        Serial.print(",");
        Serial.print(ps2x.Analog(PSS_RY), DEC); // RY
        Serial.print(",");
        Serial.println(ps2x.Analog(PSS_RX), DEC); // RX
    } 
    
 delay(50);
}