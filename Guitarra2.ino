#include <AFMotor.h>

// Connect a stepper motor with 48 steps per revolution (7.5 degree)
// to motor port #2 (M3 and M4)
AF_Stepper motor(200, 2);

void setup() {
  pinMode(19, OUTPUT); // Declare the LED as an output
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("INICIO");

  motor.setSpeed(100);  // 10 rpm   
}

void loop() {
  int pos=1, siz=17, posant;
  int piratas[siz]={1,3,4,4,4,5,6,6,6,7,5,5,4,3,3,4,1};
  //int vueltas[siz]={0,150,100,0,0,150,50,0,0,200,250,0,150,100,100,250};
  for (int x=0; x<(siz) ; x++ ){
      if(pos<piratas[x]){
        motor.step(vue(pos,piratas[x]), FORWARD, SINGLE);
        pos=piratas[x];
        digitalWrite(19, HIGH); // Turn the LED on
        delay(500); 
        digitalWrite(19, LOW); // Turn the LED on
    }
      else if(pos>piratas[x]){
         motor.step(vue(pos,piratas[x]), BACKWARD, SINGLE);
        pos=piratas[x];
        digitalWrite(19, HIGH); // Turn the LED on
        delay(500);
        digitalWrite(19, LOW); // Turn the LED on
      }
      else if(pos==piratas[x]){
        motor.step(vue(pos,piratas[x]), BACKWARD, SINGLE);
        pos=piratas[x];
        delay(300);
        digitalWrite(19, HIGH); // Turn the LED on
        delay(500);
        digitalWrite(19, LOW); // Turn the LED on
        delay(500);
      }
  }
       Serial.println("FIN");

  while(1){
    
  }
}
int vue(int pos, int fin){
 int lasi = 100;
 int sidO = 50;
 int dOre = 100;
 int remi = 150;
 int mifa = 50;
 int fasol = 200;
 int solla = 200;
 int vueltastot=0;
 int notas[7]={100,50,100,150,50,200,200};
 if (pos==fin){
  vueltastot=0;
 }
 else if(pos<fin){
   for(int x=0;x<fin-pos;x++) {
    if (((pos-1)+x)>6){
      pos=pos-7;
      fin=fin-7;
    }
   vueltastot=vueltastot+notas[(pos-1)+x];
   }
 }
 else if (pos>fin){
   for(int x=0;x<pos-fin;x++) {
    if (((pos-2))>6){
      pos=pos-7;
      fin=fin-7;
    }
    if (((pos-2)-x)<0){
      pos=pos+7;
      fin=fin+7;
    }
   vueltastot=vueltastot+notas[(pos-2)-x];
   } 
 }
 
 Serial.println(vueltastot);
 return vueltastot;
}
