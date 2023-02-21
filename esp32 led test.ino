/*--------For ESP32----------*/
//the relays connect to
// #define ENABLE_PIN 5
// #define SELECTOR_A 2
// #define SELECTOR_B 4
// #define SELECTOR_C 21
// #define SELECTOR_D 19

/*------For Arduino UNO------*/
int ENABLE_PIN = 3;
int SELECTOR_A = 4;
int SELECTOR_B = 5;
int SELECTOR_C = 6;
int SELECTOR_D = 7;

int mag_num = 0;

void relay_SetStatus(unsigned char status_1, unsigned char status_2, unsigned char status_3, unsigned char status_4, unsigned char status_5) {
  digitalWrite(ENABLE_PIN, status_1);
  digitalWrite(SELECTOR_D, status_2);
  digitalWrite(SELECTOR_C, status_3);
  digitalWrite(SELECTOR_B, status_4);
  digitalWrite(SELECTOR_A, status_5);
}

void relay_init(void) {  //initialize the relay and set as OUTPUT
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(SELECTOR_D, OUTPUT);
  pinMode(SELECTOR_C, OUTPUT);
  pinMode(SELECTOR_B, OUTPUT);
  pinMode(SELECTOR_A, OUTPUT);
  digitalWrite(ENABLE_PIN, HIGH);

  relay_SetStatus(1, 0, 0, 0, 0);  //turn off all the relay
}

void motor_run(int mag_num) {  //Select which motor to run
  if (mag_num == 1)
    relay_SetStatus(0, 0, 0, 0, 0);  //turn on RELAY_1
  if (mag_num == 2)
    relay_SetStatus(0, 0, 0, 0, 1);  //turn on RELAY_2
  if (mag_num == 3)
    relay_SetStatus(0, 0, 0, 1, 0);  //turn on RELAY_3
  if (mag_num == 4)
    relay_SetStatus(0, 0, 0, 1, 1);  //turn on RELAY_4
  if (mag_num == 5)
    relay_SetStatus(0, 0, 1, 0, 0);  //turn on RELAY_5
  if (mag_num == 6)
    relay_SetStatus(0, 0, 1, 0, 1);  //turn on RELAY_6
  if (mag_num == 7)
    relay_SetStatus(0, 0, 1, 1, 0);  //turn on RELAY_7
  if (mag_num == 8)
    relay_SetStatus(0, 0, 1, 1, 1);  //turn on RELAY_8
  if (mag_num == 9)
    relay_SetStatus(0, 1, 0, 0, 0);  //turn on RELAY_9
  if (mag_num == 10)
    relay_SetStatus(0, 1, 0, 0, 1);  //turn on RELAY_10
  if (mag_num == 11)
    relay_SetStatus(0, 1, 0, 1, 0);  //turn on RELAY_11
  if (mag_num == 12)
    relay_SetStatus(0, 1, 0, 1, 1);  //turn on RELAY_12
  if (mag_num == 13)
    relay_SetStatus(0, 1, 1, 0, 0);  //turn on RELAY_13
  if (mag_num == 14)
    relay_SetStatus(0, 1, 1, 0, 1);  //turn on RELAY_14
  if (mag_num == 15)
    relay_SetStatus(0, 1, 1, 1, 0);  //turn on RELAY_15
  if (mag_num == 16)
    relay_SetStatus(0, 1, 1, 1, 1);  //turn on RELAY_16
}

void setup() {
  Serial.begin(9600);
  relay_init();
}

void loop() {
  if (mag_num<=16) {
    motor_run(mag_num);
    Serial.print("Relay: ");
    Serial.println(mag_num);
    mag_num++;
    delay(2000);
  }
  else{
    mag_num = 0;
  }
}