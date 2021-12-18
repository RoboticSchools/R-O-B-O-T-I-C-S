String mainString;
byte redLed =9;
byte greenLed =10;
byte blueLed = 11;

void setup(){
  Serial.begin(9600);
  }

  void loop(){
    if(Serial.available()>0){
      mainString=Serial.readString();
      byte firstCommaIndex = mainString.indexOf('.');
      byte secondCommaIndex = mainString.indexOf('.',firstCommaIndex +1);
      String red=mainString.substring(0,firstCommaIndex);
      String green=mainString.substring(firstCommaIndex + 1,secondCommaIndex);
      String blue=mainString.substring(secondCommaIndex+1);

      int r= red.toInt();
      int g=green.toInt();
      int b=blue.toInt();

      analogWrite(redLed,r);
      analogWrite(greenLed,g);
      analogWrite(blueLed,b);
     
    }
    }
