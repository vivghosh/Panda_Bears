
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9,10 );

int msg_cnt=HIGH;

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);
  
  
}
  
     

  void send_text()
  {
      bool check = true;

   while(check==true)
      if(mySerial.available()>0)   
    {Serial.println("Ready");
  

  mySerial.println("AT+CMGF=1");    
  delay(1000);  


  mySerial.println("AT+CMGS=\"08119969783\"\r\n"); 
  delay(1);
  mySerial.println("There has been a gas leak!");
  delay(100);
  mySerial.println((char)26);
  delay(1000);
  Serial.println("Sent!");
  check = false;
    }
  }
  
bool read_mq2(){
   
}

void beep_buzzer()
{  tone(7,1000,500);
   delay(2000);
}

void action(bool check)
{  
  if(check==true){
     send_text();
          }
  }

float calc(int data)
{ float res=5.00;

  return res; 
}

void loop(){
    float thresh=2.00;
      
   if (calc(analogRead(A1))>thresh)
  {  Serial.println(analogRead(A1));
     while(msg_cnt){
      action(true);
      msg_cnt= LOW;
    } 
    tone(7,1000,500);
    delay(2000); }
   else action(false);
   
}





   
