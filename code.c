int sensors[4];
int low[4] = {1000, 1000, 1000, 1000};
int high[4]= {0, 0, 0, 0};
int ports[4] = {A0, A1, A2, A3}; // data and ports stored in arrays for easy traversal

const int ledPin = 13;

void setup()
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);	// use onboard LED as an indicator
  
  for(int i = 0; i < 4; i++){	// calibrate each phototransistor based on current state of the environment
    while(millis() < 5000*(i+1)) {
      sensors[i] = analogRead(ports[i]);
      if(sensors[i] > high[i])
        high[i] = sensors[i];
      else if(sensors[i] < low[i])
        low[i] = sensors[i];
    }
  }
  
  digitalWrite(ledPin,LOW);
}

void loop()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  
  int combination = 0;
  int bit = 0;
  
  for(int i = 0; i < 4; i++){	// acquire the state of each phototransistor
    sensors[i] = analogRead(ports[i]);
    if(sensors[i] <= (low[i] + high[i])/2){	// convert analog input to digital
      bit = 1;
      digitalWrite(5 - i, HIGH);	// light up the associated LED
    } else
      bit = 0;
    combination += (bit << i);	// use bit manipulation to get the combination
  }
  
  if(combination != 0){		// if any key is pressed
  	int pitch = combination*100;
  	tone(8, pitch, 10);	// generate the corresponding tone
  }
  
  delay(10);
}
