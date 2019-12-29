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
  //Đoạn chương trình sau dùng để ghi thẻ sử dụng lệnh nfc.ghi_the(4,key,data) 
  // Trong đó 4: là block cần ghi, key là password, data là dữ liệu cần ghi vào block 4
 /* byte data[16] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
   if(nfc.ghi_the(4,key,data))
    Serial.print("Success");
  else
    Serial.println("Fail");
*/
  //Đoạn chương trình sau dùng để đọc thẻ sử dụng lệnh nfc.ghi_the(4,key,data) 
  // Trong đó 4: là block cần đọc, key là password, result là dữ liệu sau khi đọc xong được lưu vào đó
  byte  result[16];
  if(nfc.doc_the(4,key,result))
    Serial.println("Success");
  else
   Serial.println("Fail");
   
  for(byte i=0;i<16;i++)
  {
    Serial.print(result[i]);
    Serial.print(",");
  }
  Serial.println();
  delay(1000);
}
