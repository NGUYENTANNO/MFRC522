#include <MFRC522.h>
#include <SPI.h>
MFRC522 nfc(10,9);  //(SAD,RST)
void setup() 
{
  Serial.begin(115200); //Khoi tao truyen len may tinh
  nfc.begin();          //Khoi tao module RC522
  //Doc phien ban board RC522
  byte phien_ban = nfc.getFirmwareVersion();
  Serial.println(phien_ban);
  delay(2000);   
}
void loop() 
{
    byte key[6] = {255,255,255,255,255,255};
 /* byte data[16] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
   if(nfc.ghi_the(4,key,data))
    Serial.print("Success");
  else
    Serial.println("Fail");
 /* if(doc_the(9,key,data))
    Serial.print("Success");
  else
    Serial.println("Fail");
  delay(1000);
  Serial.println();
  for(byte i=0; i<=15;i++)
  {
    Serial.print(data[i]);Serial.print(",");
  }
  Serial.println();*/
  byte  result[16];
  if(nfc.doc_the(4,key,result))
    Serial.println("Success");
  else
   Serial.println("Fail");
   
  for(byte i=0;i<16;i++)
  {
   Serial.print(result[i]);Serial.print(",");
  }
  Serial.println();
  delay(1000);
}
