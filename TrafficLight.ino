
#define R1 3
#define Y1 4
#define G1 5
#define R2 7
#define Y2 8
#define G2 9
  
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(R1, OUTPUT);
  pinMode(G1, OUTPUT);  
  pinMode(Y1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(G2, OUTPUT);  
  pinMode(Y2, OUTPUT);     
}

void rgy1(double r, double g, double y) {
    digitalWrite(R1, r);
    digitalWrite(G1, g);
    digitalWrite(Y1, y);
}
void rgy2(double r, double g, double y) {
    digitalWrite(R2, r);
    digitalWrite(G2, g);
    digitalWrite(Y2, y);
}

int count = 0;
int delayTime = 0;
// the loop routine runs over and over again forever:
void loop() {
  switch (count) {
    case 0://red red
      rgy1(HIGH,LOW,LOW);
      rgy2(HIGH,LOW,LOW);
      delayTime = 750;
      break;
    case 1://green red
      rgy1(LOW,HIGH,LOW);
      rgy2(HIGH,LOW,LOW);
      delayTime = 4000;
      break;
    case 2://yellow red
      rgy1(LOW,LOW,HIGH);
      rgy2(HIGH,LOW,LOW);
      delayTime = 1500;
      break;
    case 3://red red
      rgy1(HIGH,LOW,LOW);
      rgy2(HIGH,LOW,LOW);
      delayTime = 750;
      break;
    case 4://red green
      rgy1(HIGH,LOW,LOW);
      rgy2(LOW,HIGH,LOW);
      delayTime = 4000;
      break;
    case 5://red yellow
      rgy1(HIGH,LOW,LOW);
      rgy2(LOW,LOW,HIGH);
      delayTime = 1500;
      break;
  }
  
  count ++;
  count %= 6;
  delay(delayTime);

}
