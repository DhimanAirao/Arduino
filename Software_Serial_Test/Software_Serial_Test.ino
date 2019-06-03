/*
 1. Upload this code and open the serial monitor
 2. On the serial monitor enter the command AT 
 3. If the response is OK, your esp8266 serial baud rate is 115200 
    and you have to change it to 9600. Enter the command AT+UART_CUR=9600,8,1,0,0
    Then on the void setup make this change: espSerial.begin(9600); and upload again the code.
    Test the communication. Enter again the command AT 
    if the response is OK you are ready to run the example code.

 4. Otherwise if you can't see anything on the serial display 
    change the esp8266 serial baud rate to 9600 or 115200 or other, until you get a response.
    Then enter the command AT+UART_CUR=9600,8,1,0,0 to change the speed to 9600 
 5. If you ESP8266 works only at 115200 don't use software Serial. Use hardware serial with ARDUINO MREGA board. 
*/

// AT                             Command to display the OK message
// AT+GMR                         Command to display esp8266 version info
// AT+UART_CUR=9600,8,1,0,0       Command to change the ESP8266 serial baud rate  to 9600   
// AT+UART_DEF=9600,8,1,0,0       Command to change the default ESP8266 serial baud rate  to 9600    
// AT+RST 


void setup() 
{
    Serial.begin(9600);
    Serial1.begin(9600);   // or 115200
}

void loop() 
{
  while (Serial.available()) 
  { 
      char ch = Serial.read();
      Serial1.print(ch);
  }
  
  while (Serial1.available()) 
  { 
      char ch = Serial1.read();
      Serial.print(ch);
   }
}
