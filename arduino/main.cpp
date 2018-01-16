char comdata[10] ="T";//Test通电即开启测试程序，测试内容包括：前进3秒；左拐3秒；右拐3秒；停止3秒；后退3秒；停止
int comdataLen=0;

//控制一个电机
int pin10 = 10;
int pin11 = 11; 
//控制另一个电机
int pin12 = 12;
int pin13 = 13;

int TestInt = 0;

void setup(){
    Serial.begin(9600);
    
    pinMode(pin10, OUTPUT);
    pinMode(pin11, OUTPUT);
    pinMode(pin12, OUTPUT);   
    pinMode(pin13, OUTPUT);
 
}   
void loop(){
     while(Serial.available()>0){
          comdata[comdataLen] = Serial.read();
          comdataLen++;
          delay(2);
      }
      if(comdata[0]=='F'){  //"Forward" 前进，左右轮都为高电平
          //Serial.println(comdata[0]);
          go_UP();
          comdataLen=0;
      }
      if(comdata[0]=='B'){  //"Back" 后退 
          //Serial.println(comdata[0]);
          go_BACK();
          comdataLen=0;
      }
      if(comdata[0]=='S'){  //Stop停止前进，左右为低电平
          //Serial.println(comdata[0]);        
          go_STOP();
          comdataLen=0;
      }
      
      if(comdata[0]=='L'){  //Left，左拐。左边为低电平，右边为高电平
         // Serial.println(comdata[0]);
          go_LEFT();
          comdataLen=0;
      }
      if(comdata[0]=='R'){  //Right，右拐。左边为高电平，右边为低电平
         // Serial.println(comdata[0]);
          go_RIGHT();
          comdataLen=0; 
      }
      if(comdata[0]=='T'){  //Test上电测试小车程序
          Serial.println(comdata[0]);
          go_UP();    delay(3000);
          go_LEFT();  delay(3000);   
          go_RIGHT(); delay(3000);
         // go_STOP();  delay(3000); 
          go_BACK();  delay(3000);
          go_STOP();  delay(3000);
          comdata[0] = ' ';
          comdataLen=0;
      }
      if(comdata[0]=='A'){  //Auto测试数据回传功能
          sendInfoToAndroid();
          comdataLen=0;
      }
}

////////////////////////////
void go_UP(){
   goHead_1_FL();
   goHead_2_FR();
}

void go_LEFT(){
     goBack_1_FL();
     goHead_2_FR();
}

void go_RIGHT(){
     goHead_1_FL();
     goBack_2_FR();
}

void go_STOP(){
   goStop_1_FL();
   goStop_2_FR();
}

void go_BACK(){
  goBack_1_FL();
  goBack_2_FR();
}

//////////////////////////////
void goHead_1_FL(){
      digitalWrite(pin10,LOW);
      digitalWrite(pin11,HIGH);
}
void goBack_1_FL(){
      digitalWrite(pin10,HIGH);
      digitalWrite(pin11,LOW);
}
void goStop_1_FL(){
      digitalWrite(pin10,LOW);
      digitalWrite(pin11,LOW);
}
//////////////////////////////
void goHead_2_FR(){
      digitalWrite(pin12,LOW);
      digitalWrite(pin13,HIGH);
}
void goBack_2_FR(){
      digitalWrite(pin12,HIGH);
      digitalWrite(pin13,LOW);
}
void goStop_2_FR(){
      digitalWrite(pin12,LOW);
      digitalWrite(pin13,LOW);
}
//向Android客户端发送信息
void sendInfoToAndroid(){
     Serial.println("   startHi android,i'm arduino.end");
     delay(2000);
}

