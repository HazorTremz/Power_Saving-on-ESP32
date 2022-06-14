//Defining the state for esp32 and the respecive reactive pin
int state = HIGH ;
int saver_pin = 13;


void setup() {
  //Initiating the serial monitor 
  Serial.begin(9600);
  //Initiating the reactive pin/touch pin
  pinMode(saver_pin,INPUT_PULLUP);
  
}

void loop() {
    //Checking touch pin state
   state =  digitalRead(saver_pin);
   
   Serial.println("*PERFORMACE MODE : ON*");
   //Condition for the esp to go in power saving mode
     if(state == LOW)
    {
      Serial.println("*POWER-SAVING MODE : ON*");
      //Initiating the sleep mode
      esp_deep_sleep_start();
  
    }
    
    //Waking esp32 mode after sleep mode on touch pin state "HIGH"
   esp_sleep_enable_ext0_wakeup(GPIO_NUM_13,1);
 

}
