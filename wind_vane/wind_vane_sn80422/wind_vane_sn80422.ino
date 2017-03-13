unsigned int WIND_VANE_PIN_INPUT = A2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  float res = getWindDirection();
  if(res != -1.0){
    Serial.print("direction: ");
    Serial.print(res);
    Serial.print(" degres, ");
    Serial.println(getHeading(res));
  }
  delay(1000);
}

float getWindDirection(){
    float res =-1.0;
    float sensorValue = analogRead(WIND_VANE_PIN_INPUT);
    
    float mesure = (sensorValue*5.0)/1023;
    //Serial.println(mesure);

    if(mesure < 4.02 && mesure > 3.74) {
      res = 0;
    }else if (mesure > 1.96 && mesure < 2.10) {
      res = 22.5;
    }else if (mesure > 2.23 && mesure < 2.32) {
      res = 45;
    }else if (mesure > 0.39 && mesure < 0.43) {
      res = 67.5;
    }else if (mesure >= 0.43 && mesure < 0.47) {
      res = 90;
    }else if (mesure > 0.30 && mesure < 0.34) {
      res = 112.5;
    }else if (mesure > 0.88 && mesure < 0.92) {
      res = 135;
    }else if (mesure > 0.60 && mesure < 0.64) {
      res = 157.5;
    }else if (mesure > 1.38 && mesure < 1.42) {
      res = 180;
    }else if (mesure > 1.17 && mesure < 1.21) {
      res = 202.5;
    }else if (mesure > 3.06 && mesure < 3.11) {
      res = 225;
    }else if (mesure > 2.91 && mesure < 2.96) {
      res = 247.5;
    }else if (mesure > 4.6 && mesure < 4.64) {
      res = 270;
    }else if (mesure >= 4.02 && mesure < 4.08) {
      res = 292.5;
    }else if (mesure > 4.76 && mesure < 4.8) {
      res = 315;
    }else if (mesure > 3.41 && mesure <= 3.5) {
      res = 337.5;
    }
    return res;
}

// Converts compass direction to heading 
String getHeading(float direction) { 
  String heading = "";
  
  if(direction < 22.5) 
   heading = "N"; 
  else if (direction <= 67.5) 
    heading = "NE"; 
  else if (direction < 112.5) 
    heading = "E"; 
  else if (direction <= 157.5) 
    heading = "SE"; 
  else if (direction < 212.5) 
    heading = "S"; 
  else if (direction <= 247.5) 
    heading = "SW"; 
  else if (direction < 292.5) 
    heading = "W"; 
  else if (direction <= 337.5) 
    heading = "NW"; 
  else 
    heading = "N"; 

   return heading;
}

