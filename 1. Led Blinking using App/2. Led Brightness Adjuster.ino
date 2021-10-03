int led = 7;
int data = 0;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()>0){
  data = Serial.read();
  Serial.println(data);
  analogWrite(led,data);
}
}
