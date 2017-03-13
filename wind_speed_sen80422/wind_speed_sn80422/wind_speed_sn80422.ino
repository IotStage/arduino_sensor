
int nb_basc_speed = 0;
int intervalMesure = 10;
unsigned long lastTimeMesure = 0, curTimeMesure = 0;
float curWindMesure=0.0, lastWindMesure=0.0;

unsigned int WIND_SPEED_PIN = A1;

void setup() {
  
  Serial.begin(9600);
  initMesure();

}

void loop() {
    curTimeMesure = millis();
    if((curTimeMesure-lastTimeMesure) < intervalMesure*1000){
      calculateWindSpeed();
    }
    else{
      
      //recuperer la vitesse
      float vitesse = getWindSpeed();
      
      /*Serial.print("Vitesse: ");
      Serial.print(vitesse);
      Serial.println(" km/h");*/

      
      initMesure();
    }
}

/*
 * Reinitialisation
 */
float initMesure(){

  //initialiser les parametres du capteur de la vitesse du vent
  nb_basc_speed = 0;
  curWindMesure=0.0;
  lastWindMesure=0.0;

  //linstant de mesure
  lastTimeMesure = curTimeMesure;
}

/*
 * 
 */
float getWindSpeed(){
  float vitesse = nb_basc_speed*2.4/intervalMesure;
  return vitesse;
}

/*
 * calculer le nombre dimpulsion du capteur de vent
 */
void calculateWindSpeed(){
  float sensorValue = analogRead(WIND_SPEED_PIN);      
  curWindMesure = (sensorValue*5)/1023;
  if(curWindMesure<2.50 && lastWindMesure>2.5){
     nb_basc_speed++;
     Serial.println(nb_basc_speed);
  }
  lastWindMesure = curWindMesure;
}

