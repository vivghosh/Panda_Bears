
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,9);

int msg_cnt=HIGH;

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(4800);
  Serial.begin(4800);
  }
  
     
//to send the text
  void send_text()
  {    
      bool check = true, reci=true;
      int rea,count=0;

  
    //Serial.println("\n\r"); 
   do{  
    
    Serial.println("******Ready*****");
  

   mySerial.println("AT+CMGF=1\r\n");    
   delay(1000);

   reci=text_stop();//acknowledgement function call
   if(reci==false)
   { break;
   }
     
  mySerial.println("AT+CMGS=\"08119969783\"\r\n"); 
  delay(1);
   
  mySerial.println("There has been a gas leak!");
  delay(100);
  mySerial.println((char)26);
  delay(1000);
  Serial.println("*****Sent!******");
 
    count++;
    delay(2000);
    
    
  } while(count<=8);
  }


//acknowlwdgement function
bool text_stop(){
    int count=0;
    bool stat = true;

    //check thrice for acknowledgement message
    while(count<=3){
      delay(3000);
      Serial.println("-----MSG Status:-----");
     mySerial.println("AT+CMGF=0\r\n+CMGU<CR>");    
  delay(1000);  
   mySerial.println("AT+CMGF=1");    
  delay(1000);
  
  mySerial.println("AT+CNMI=2,2,0,0,0\r\n");
 int     rea=mySerial.readString().length();
     Serial.println(rea);
     Serial.println("----Done-----");
     count++;
     if(rea>70)
     {  stat = false;
      break;
    }
    }
    return stat;
}
  


void loop(){
    int thresh=20;//threshold value for smoke
      
   if (calc(analogRead(A1))>thresh)
  {  //Serial.println(analogRead(A1));
     while(msg_cnt){
      send_text();
      msg_cnt= LOW;
    }
    tone(7,1000,500);
    delay(2000); }
   
  } 
}





   
