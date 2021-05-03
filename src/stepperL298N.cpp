/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/warf9/OneDrive/Documentos/10IoT/VisualStudio/stepperL298N/src/stepperL298N.ino"
#include <Ubidots.h>
//Globals
void setup();
void loop();
void PillsFun();
void WCSFun();
void batirFun();
void UbidotsMessages(const char *event, const char *data);
void forward(int steps);
void updateFun();
void interruptFunTouch();
#line 3 "c:/Users/warf9/OneDrive/Documentos/10IoT/VisualStudio/stepperL298N/src/stepperL298N.ino"
#define SwitchWater D0
#define BombaWater D1
#define ServoBY1 D2
#define ServoBY2 D3 //**
#define ServoAN1 D4
#define ServoAN2 D5
#define DCmotor D6
#define AlarmPin D7
#define touchbutton D8
#define ChangeNema D10
#define STEPPIN D11 //pull
#define DIRPIN D12
#define ENAPIN D13

const int STEPTIME = 2; //steps delay
const char *WEBHOOK_NAME= "UbidotsMessage";       //Declaramos el webhook configurado en la consola de Particle
Ubidots ubidots("webhook", UBI_PARTICLE);
Ubidots ubidotsGET("BBFF-scd8n8yDi9om9Vxg650ESuM26GeLQ9",UBI_TCP);
//variables
boolean iniciar = false;
boolean switchStatus = false;
boolean pill_blue = false;
boolean pill_white = false;
boolean pill_orange = false;
boolean pill_yellow = false;
int water_var = 0;
int sugar_teaspoons = 0;
int coffee_teaspoons = 0;
bool batir=false;
//const delays
const int t1servos=2000;
const int t2servos=500;
const int twater=6000;
const int tchangenema=2000;
const int tbatir=60000;
//-----------------------------
float batir_variable=0.0;
boolean reminderAlarm=false;
//VALORES INICIALES
int nivelagua = 40;
int nivelcafe = 30;
int nivelazucar = 50;
int cantazul = 20;
int cantamarillo = 20;
int cantblanco =  20;
int cantnaranja = 20;
//update
bool upblue=false;
bool upyellow=false;
bool uporange=false;
bool upwhite=false;
bool upwater=false;
bool upcoffee=false;
bool upsugar=false;
//------------------
bool initupdate=true;
void setup(){ //----------------------------------------Setup
  //Stepper
  pinMode(STEPPIN,OUTPUT);
  pinMode(DIRPIN,OUTPUT);
  pinMode(ENAPIN,OUTPUT);
  //Servos  
  pinMode(ServoAN1,OUTPUT);
  pinMode(ServoAN2,OUTPUT);
  pinMode(ServoBY1,OUTPUT);
  pinMode(ServoBY2,OUTPUT);
  //-----
  pinMode(DCmotor,OUTPUT);
  pinMode(ChangeNema,OUTPUT);
  pinMode(SwitchWater,INPUT);
  pinMode(BombaWater,OUTPUT); 
  pinMode(AlarmPin,OUTPUT);
  pinMode(touchbutton,INPUT);
  attachInterrupt(touchbutton, interruptFunTouch, CHANGE);
  Particle.subscribe("UbidotsWebhook", UbidotsMessages);  
}

void loop() { //------------------------------------------------------------------------------Loop
  if(initupdate) updateFun();
  String mssg = "Iniciar: "+String(iniciar) + " Amarillo:"+String(pill_yellow)+" Azul:"+String(pill_blue)+" Blanco:"+String(pill_white)+" Naranja:"+String(pill_orange)+" %Agua:"+String(water_var)+" #Cafe:"+String(coffee_teaspoons)+" #Azucar:"+String(sugar_teaspoons)+" Batir:"+String(batir_variable)+" Alarm:"+String(reminderAlarm);
  Serial.println(mssg);  
  if(iniciar and !reminderAlarm){
    reminderAlarm=true;
    switchStatus=digitalRead(SwitchWater);
    if(switchStatus){
      Particle.publish("nowater", "1", PUBLIC);     
      water_var=0;
      iniciar=0;
      for(int i=0;i<6;i++){
        analogWrite(AlarmPin, 100);
        delay(300); 
        analogWrite(AlarmPin, 0);
        delay(300);
      }
    }
    if(water_var or coffee_teaspoons or sugar_teaspoons) WCSFun();
    else  if(batir_variable) batirFun();
    PillsFun();
    iniciar=false;
    updateFun();
  }
  if(reminderAlarm){
    for(int i=0;i<3;i++){
      analogWrite(AlarmPin, 150);
      delay(600); 
      analogWrite(AlarmPin, 0);
      delay(600);
    }
  }
  delay(1000);
}

void PillsFun() {//---------------------------------------------------------------------------PillsFun
  if(pill_yellow){//---------------------------------yellow
    analogWrite(ServoAN2, 50);
    delay(t1servos);
    analogWrite(ServoAN2, 130);
    delay(t2servos);
    analogWrite(ServoAN1, 70);
    delay(t1servos);
    analogWrite(ServoAN1, 130);
    delay(t2servos);
    pill_yellow=false;
    upyellow=true;
    cantamarillo--;
  }
  if(pill_blue){//---------------------------------Blue
    analogWrite(ServoBY2, 50);
    delay(t1servos);
    analogWrite(ServoBY2, 130);
    delay(t2servos);
    analogWrite(ServoBY1, 50);
    delay(t1servos);
    analogWrite(ServoBY1, 130);
    delay(t2servos);
    pill_blue=false;
    upblue=true;
    cantazul--;
  }
  if(pill_white){//---------------------------------white
    analogWrite(ServoAN2, 180);
    delay(t1servos);
    analogWrite(ServoAN2, 130);
    delay(t2servos);
    analogWrite(ServoAN1, 190);
    delay(t1servos);
    analogWrite(ServoAN1, 130);
    delay(t2servos);
    pill_white=false;
    upwhite=true;
    cantblanco--;
  }
  if(pill_orange){//---------------------------------orange
    analogWrite(ServoBY2, 170);
    delay(t1servos);
    analogWrite(ServoBY2, 130);
    delay(t2servos);
    analogWrite(ServoBY1, 220);
    delay(t1servos);
    analogWrite(ServoBY1, 130);
    delay(t2servos);
    pill_orange=false;
    uporange=true;
    cantnaranja--;    
  }
}

void WCSFun(){//------------------------------------------------------------------water+coffee+sugar  
  if(water_var>0 and !switchStatus){
    digitalWrite(BombaWater, true); //activar bomba
    nivelagua=nivelagua-5;
    upwater=true;
  } 
  digitalWrite(ChangeNema, false); //nema change
  delay((twater*water_var)/100);
  digitalWrite(BombaWater, false); //apagar bomba  

  while(sugar_teaspoons>0){ //activar azucar
    forward(200);
    sugar_teaspoons--;
    batir=true;
    nivelazucar=nivelazucar-2;
    upsugar=true;
    delay(tchangenema);    
  }
  delay(tchangenema);
  digitalWrite(ChangeNema, true); //nema change  
  delay(tchangenema);
  while(coffee_teaspoons>0){ //activar cafe
    forward(200);
    coffee_teaspoons--;
    batir=true;
    nivelcafe=nivelcafe-2;
    upcoffee=true;
    delay(tchangenema);
  }
  digitalWrite(ChangeNema, false); //nema change
  if(batir_variable){
    digitalWrite(DCmotor, 1); //activar batidor
    delay(tbatir*batir_variable);
  } 
  batir=false;
  analogWrite(DCmotor, 0); //apagar batidor
  //reset values
  water_var=0;
  sugar_teaspoons=0;
  coffee_teaspoons=0;     
}

void batirFun(){
  analogWrite(DCmotor, 250); //activar batidor
  delay(tbatir*batir_variable);
  analogWrite(DCmotor, 0);
}

void UbidotsMessages(const char *event, const char *data)//------------------------------UbidotsMessages
{
  String datastring= String(data);
  Serial.println("RECIBIENDO DATOS ..."); 
  if(datastring.equals("iniciar") or datastring.equals("Calendarstart")){
    pill_blue=(bool) ubidotsGET.get("proyecto","azul");
    pill_orange=(bool) ubidotsGET.get("proyecto","naranja");
    pill_white=(bool) ubidotsGET.get("proyecto","blanca");
    pill_yellow=(bool) ubidotsGET.get("proyecto","amarilla");
    water_var=(int) ubidotsGET.get("proyecto","agua");
    coffee_teaspoons=(int) ubidotsGET.get("proyecto","cafe");
    sugar_teaspoons=(int) ubidotsGET.get("proyecto","azucar");
    batir_variable=(float) ubidotsGET.get("proyecto","batir");
    iniciar=true;
  }
   
}

void forward(int steps){ //---------------------------------------------------------------------forward
  //400 steps 1 revolution
  int i;
  digitalWrite(ENAPIN,LOW);
  digitalWrite(DIRPIN,HIGH);//SET DIRECTION 
  for(i=0;i<steps;i++){
    digitalWrite(STEPPIN,HIGH);
    delay(STEPTIME);
    digitalWrite(STEPPIN,LOW);
    delay(STEPTIME);  
  }  
  digitalWrite(ENAPIN,HIGH);//DISABLE STEPPER
}

void updateFun(){ //----------------------------------------------------------------------update ubidots
  if(upwater or initupdate) ubidots.add("nivelagua", (float) nivelagua);
  if(upcoffee or initupdate) ubidots.add("nivelcafe", (int) nivelcafe);
  if(upsugar or initupdate) ubidots.add("nivelazucar", (int) nivelazucar);
  if(upyellow or initupdate) ubidots.add("pastilla amarilla",(float) cantamarillo);
  if(upblue or initupdate) ubidots.add("pastilla azul", (int) cantazul);
  if(upwhite or initupdate) ubidots.add("pastilla blanca", (int) cantblanco);
  if(uporange or initupdate) ubidots.add("pastilla naranja", (int) cantnaranja);
  ubidots.send(WEBHOOK_NAME, PUBLIC);
  upblue=false;
  upyellow=false;
  uporange=false;
  upwhite=false;
  upwater=false;
  upcoffee=false;
  upsugar=false;
  initupdate=false;
}

void interruptFunTouch()//funcion de interrupcion
{   
  reminderAlarm=false;
}