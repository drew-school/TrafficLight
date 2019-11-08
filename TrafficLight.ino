// define LED pins
#define R1 3
#define Y1 4
#define G1 5
#define R2 7
#define Y2 8
#define G2 9
  
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the LED pins as outputs.
  pinMode(R1, OUTPUT);
  pinMode(G1, OUTPUT);  
  pinMode(Y1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(G2, OUTPUT);  
  pinMode(Y2, OUTPUT);     
}

// control red green and yellow LEDs of first "traffic light"
void rgy1(double r, double g, double y) {
    digitalWrite(R1, r);
    digitalWrite(G1, g);
    digitalWrite(Y1, y);
}
// control red green and yellow LEDs of second "traffic light"
void rgy2(double r, double g, double y) {
    digitalWrite(R2, r);
    digitalWrite(G2, g);
    digitalWrite(Y2, y);
}

// initialize count and delay variables
int count = 0;
int delayTime = 0;

// the loop routine runs over and over again forever:
void loop() {
  //this switch determines what part of the sequence of traffic lights we are in
  //it then turns "on" the correct LEDs, and gives the main program an approriate delayTime
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

  //increase the counter, keeping it between 0-5
  count ++;
  count %= 6;

  //delay next cycle based on what part of cycle we are in (e.g. don't want both lights to be red for very long)
  delay(delayTime);
}
