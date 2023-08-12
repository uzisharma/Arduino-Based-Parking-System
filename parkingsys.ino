//ARDUINO (!!!!!!!!!!!!!!!AUTOMATIC PRAKING SYSTEM!!!!!!!!!!!!!!!!) 
//4TH SEMESTER MINI-PROJECT [RVS COLLEGE OF ENGINEERING AND TECHNOLOGY]
//BY:- 1, UJJWAL SHARMA
//     2, SUAJN ADHIKARY


#include <String.h>
#include <Wire.h>           
#include <LiquidCrystal_I2C.h>    
    LiquidCrystal_I2C lcd(0x27,16,2);  
#include <Servo.h>   
    Servo gate;
 
 const int IR1 = 6;        // IR Sensor 1  
 const int IR2 = 7;        // IR Sensor 2  
 const int buzzer = 2;     // Buzzer
 const int ledred = 13;    // RedLED
 const int ledgreen = 11;  // GreedLED
 int Slot = 5;             // Total number of parking Slots  
 int flag1 = 0;  
 int flag2 = 0; 

//Function to display onto the LCD
      void lcdDisplay(String topline, String bottomline, int delay_time){
              lcd.setCursor (0,0);
              lcd.print(topline);
              lcd.setCursor (0,1);
              lcd.print(bottomline);
              delay (delay_time);
              if(delay_time>0)
                  lcd.clear();
      }

//Function to Calculate the Number of SLOTS LEFT
      void slotUpdate(int &Slot, int &flag1, int &flag2){
        if(flag1==1){
             Slot -= 1;
        }else if(flag2 ==1){
          Slot +=1;
        }
         lcdDisplay("   Welcome!!!", "Slot Left : ", 0);
         lcd.print(Slot);
         
      }

  
 void setup()  
      {
        Serial.begin(9600);
        lcd.init();      
        lcd.backlight();  
        pinMode(IR1, INPUT);  
        pinMode(IR2, INPUT);
        pinMode(ledred,OUTPUT);
        pinMode(ledgreen,OUTPUT);  
        gate.attach(9);  
        gate.write(100);  

        String names[2] = {"Ujjwal Sharma", "Sujan Adhikary"};
        String roll_num[2] = {" ECE/462/21L", " ECE/461/21L"};
        
        lcdDisplay(" PARKING SYSTEM", "      By  ", 2000); 
        for(int i=0;i<2;i++){
         lcdDisplay(names[i],roll_num[i], 2000);
          }
        slotUpdate(Slot, flag1, flag2);     
      } 

 
 void loop()
        {   
    if(Slot==0){
      digitalWrite(ledgreen, LOW);
      digitalWrite(ledred, HIGH);
    }else{
      digitalWrite(ledgreen, HIGH);
      digitalWrite(ledred,LOW);
    }

// CASE 1: When the Parking is Full, and no SLOTS are available    
        if(digitalRead(IR1)==LOW && Slot==0){
          while(digitalRead(IR1)==LOW){
            lcdDisplay("   SORRY :(  ", "  Parking Full ", 0);
            tone(buzzer, 1000);
            digitalWrite(ledred, HIGH);
            delay(300);
            digitalWrite(ledred, LOW);
            delay(300);
          }
          digitalWrite(ledred, LOW);
          noTone(buzzer);
          slotUpdate(Slot, flag1, flag2); 
        }

//CASE 2: Entry of Vehicle
        if(digitalRead(IR1)==LOW && Slot!=0){
          slotUpdate(Slot, flag1, flag2);  
              gate.write(0);
              flag1 = 1;
              while(flag1){
                lcdDisplay(" Please Standby!!"," ",90);
                tone(buzzer,3000);
                if( (digitalRead(IR2)==LOW) &&(digitalRead(IR1)==HIGH)){
                   delay(500);
                  break;
                }
               }
              gate.write(100);
              noTone(buzzer);
               slotUpdate(Slot, flag1, flag2);
               flag1 = 0;
           
        }

//CASE 3: Exit of Vehicle
        if(digitalRead(IR2)==LOW && Slot<5){
          gate.write(0);
          flag2 = 1;
          while(flag2){
            lcdDisplay(" Please Standby!!"," ",90);
            tone(buzzer,3000);
            if((digitalRead(IR2)==HIGH) && (digitalRead(IR1)==LOW)){
              delay(500);
              break;
            }
          }
          gate.write(100);
          noTone(buzzer);
          slotUpdate(Slot, flag1, flag2);
          flag2 = 0;
        }
  


 }  
