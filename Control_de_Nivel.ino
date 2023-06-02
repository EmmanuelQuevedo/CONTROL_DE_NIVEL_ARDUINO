//NIVEL

int trig = 3;
int echo = 4;
int bombaauto=13;

long tiempo;
float dist;
int encendido = 0;

void setup() {
Serial.begin(9600);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
pinMode(bombaauto, OUTPUT);
digitalWrite(bombaauto,HIGH);
}

void loop() {

digitalWrite(trig, 0);
delayMicroseconds(5);
digitalWrite(trig, HIGH);

tiempo= pulseIn(echo, HIGH);
dist= float (0.0349*(tiempo/2));

delay(1000);

Serial.println(dist);

if(dist>=12){
//tanque debera estar vacio
digitalWrite(bombaauto,HIGH);
encendido=1;

}

if((dist<12)&&(dist>3)&&(encendido==1)){
//tanque se debera estar llenando
digitalWrite(bombaauto,HIGH);

}

if(dist<=3){
//tanque debera estar lleno
digitalWrite(bombaauto,LOW);
encendido=0;
}

}
