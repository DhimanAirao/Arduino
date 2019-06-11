
//This is the code to send and receive 2Byte data from external EEPROM using I2C communication


#include <Wire.h>
#define EEPROM_I2C_ADDRESS 0X50        // Address of the EEPROM available in data sheet
unsigned int val=65300,readValue;      // write the value which you want to write 
int address=0;                         // Write the address at which you want to write data
void setup() 
{
  Wire.begin();
  Serial.begin(9600);
}

void loop() 
{
  writeAddress_2(address,val);
  readValue=readAddress_2(address);
  Serial.print("The returned value is ");
  Serial.println(readValue);
  delay(100);  
}

void writeAddress_2(int address, unsigned int val)
{
  byte myArray[2];
  myArray[0] = (val >> 8) & 0xFF;
  myArray[1] = val & 0xFF;
  Wire.beginTransmission(EEPROM_I2C_ADDRESS);
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xFF)); // LSB 
  Wire.write(myArray, 2);
  Wire.endTransmission();
  delay(5);
}

unsigned int readAddress_2(int address)
{
  unsigned int rData = 0xFF;
  byte a,b;  
  Wire.beginTransmission(EEPROM_I2C_ADDRESS);  
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  Wire.endTransmission();  
  Wire.requestFrom(EEPROM_I2C_ADDRESS, 2);  
  a = Wire.read();
  b = Wire.read();
  rData = a;
  rData = (rData << 8) | b;
  return rData;
}
