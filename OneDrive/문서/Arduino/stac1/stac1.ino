int volume;
#include <DHT11.h>
//#include <Wire.h>
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
int pin=4;
int cds;
DHT11 dht11(pin);
float temp, humi;
int subval;
int res;
int subStatus1=0,subStatus2=0;

 void setup() {
  Serial.begin(9600); // For debugging, log
  Serial1.begin(9600);//업주, 폰통신
  Serial2.begin(9600); // 서브와 통신
//  lcd.begin (16,2);
//  lcd.print("Hello, world!");
}
 
void loop() {  

//if (Serial1.available()) {
//    Serial.write(Serial1.read());
//  }
//  if (Serial.available()) {
//    Serial1.write(Serial.read());
//  }
//  if (Serial2.available()) {
//    subval=Serial2.read();
//  }

  
  dht11.read(humi, temp);
  volume = analogRead(A0);
  cds = analogRead(A1);
  Serial.print("soum : ");
  Serial.println(volume);
  Serial.print(",");
  Serial.print("lux : ");
  Serial.println(cds);
  Serial.print(",");
  Serial.print("ondo : ");
  Serial.println((int)temp);
  Serial1.print(volume);
  Serial1.print(",");
  Serial1.print(cds);
  Serial1.print(",");
  Serial1.print((int)temp);
  Serial1.print(",");
  Serial1.print(subStatus1);
  Serial1.print(",");
  Serial1.println(subStatus2);
  
  delay(1000);
  
 
}

void Split(String sData, char cSeparator){   
    int nCount = 0;
    int nGetIndex = 0 ;
    //임시저장
    String sTemp = "";
    //원본 복사
    String sCopy = sData;
    while(true){
        //구분자 찾기
        nGetIndex = sCopy.indexOf(cSeparator);
        //리턴된 인덱스가 있나?
        if(-1 != nGetIndex){
            //있다.
            //데이터 넣고
            sTemp = sCopy.substring(0, nGetIndex);
            Serial.println( sTemp );
            //뺀 데이터 만큼 잘라낸다.
            sCopy = sCopy.substring(nGetIndex + 1);
        }else{
            //없으면 마무리 한다.
            Serial.println( sCopy );
            break;
        }
        //다음 문자로~
        ++nCount;
    }
}
