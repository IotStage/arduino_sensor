int nb_basc_speed = 0;
unsigned lastTimeMesure = 0, curTimeMesure;
float WIND_SPEED = 0.0;
unsigned int WIND_SPEED_PIN = 2;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  attachInterrupt(0, calculateWindSpeed, FALLING);

}

void loop() {
  /*Serial.print("vitesse: ");
  Serial.print(getWindSpeed(10000));
  Serial.print(" km/h ");*/
  getWindSpeed(1000);
  
}


void calculateWindSpeed(){
  nb_basc_speed++;
  //Serial.println(nb_basc_speed);
}


/*
 * Calcul la vitesse du vent
 */
float getWindSpeed(int interval){
    curTimeMesure = millis();
    if((curTimeMesure-lastTimeMesure) < interval){    
       return WIND_SPEED;
    }
    else{
      float vitesse = nb_basc_speed*2.4/(interval/1000);
      Serial.print(vitesse);
    Serial.print(" km/h ");
      Serial.println(nb_basc_speed);
      nb_basc_speed = 0;
      lastTimeMesure = curTimeMesure;
      WIND_SPEED = vitesse;
      return vitesse;
    }  
}
