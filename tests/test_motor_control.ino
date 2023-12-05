//motor A connected between A01 and A02
//motor B connected between B01 and B02

int STBY = 17; //standby

/*------- Motor Driver 3 -------*/
//Motor A
int PWMA = 3; //Speed control 
int AIN1 = 0; //Direction
int AIN2 = 1; //Direction
//Motor B
int PWMB = 5; //Speed control
int BIN1 = 2; //Direction
int BIN2 = 4; //Direction

/*------- Motor Driver 2 -------*/
// Motor A
int PWMC = 6; //Speed control 
int AIN3 = 7; //Direction
int AIN4 = 8; //Direction
// Motor B
int PWMD = 9; //Speed control
int BIN3 = 12; //Direction
int BIN4 = 19; //Direction

/*------- Motor Driver 1 -------*/
// Motor A
int PWME = 11; //Speed control 
int AIN5 = 14; //Direction
int AIN6 = 13; //Direction


void setup(){
  pinMode(STBY, OUTPUT);

/*------- Motor Driver 3 -------*/
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

 /*------- Motor Driver 2 -------*/
  pinMode(PWMC, OUTPUT);
  pinMode(AIN3, OUTPUT);
  pinMode(AIN4, OUTPUT);

  pinMode(PWMD, OUTPUT);
  pinMode(BIN3, OUTPUT);
  pinMode(BIN4, OUTPUT);

  /*------- Motor Driver 1 -------*/
  pinMode(PWME, OUTPUT);
  pinMode(AIN5, OUTPUT);
  pinMode(AIN6, OUTPUT);

}

void loop(){

  // Fist Gesture
  move(1, 255, 1); //motor 1, half speed, right
  move(2, 255, 1); //motor 2, half speed, right
  move(3, 255, 1); //motor 3, half speed, right
  move(4, 255, 1); //motor 4, half speed, right
  move(5, 255, 1); //motor 5, full speed, right
  delay(3000);
  
  move(1, 255, 0); //motor 1, full speed, left
  move(2, 180, 0); //motor 2, full speed, left
  move(3, 180, 0); //motor 3, full speed, left 
  move(4, 180, 0); //motor 4, full speed, left
  move(5, 255, 0); //motor 5, full speed, left
  delay(200);

  // Rest Gesture
  move(1, 0, 0); //motor 1, full speed, left
  move(2, 0, 0); //motor 2, full speed, left
  move(3, 0, 0); //motor 3, full speed, left 
  move(4, 0, 0); //motor 4, full speed, left
  move(5, 0, 0); //motor 5, full speed, left
  delay(3000);

  // Hook Gesture
  move(1, 0, 0); //motor 1, half speed, right
  move(2, 255, 1); //motor 2, half speed, right
  move(3, 255, 1); //motor 3, half speed, right
  move(4, 255, 1); //motor 4, half speed, right
  move(5, 255, 1); //motor 5, full speed, right
  delay(3000);

  // Rest Gesture
  move(1, 0, 0); //motor 1, full speed, left
  move(2, 180, 0); //motor 2, full speed, left
  move(3, 180, 0); //motor 3, full speed, left 
  move(4, 180, 0); //motor 4, full speed, left
  move(5, 255, 0); //motor 5, full speed, left
  delay(200);

  // Rest Gesture
  move(1, 0, 0); //motor 1, full speed, left
  move(2, 0, 0); //motor 2, full speed, left
  move(3, 0, 0); //motor 3, full speed, left 
  move(4, 0, 0); //motor 4, full speed, left
  move(5, 0, 0); //motor 5, full speed, left
  delay(3000);

  // Tip Gesture
  move(1, 255, 1); //motor 1, full speed, left
  move(2, 255, 1); //motor 2, full speed, left
  move(3, 0, 0); //motor 3, full speed, left 
  move(4, 0, 0); //motor 4, full speed, left
  move(5, 0, 0); //motor 5, full speed, left
  delay(3000);

  // Rest Gesture
  move(1, 255, 0); //motor 1, full speed, left
  move(2, 180, 0); //motor 2, full speed, left
  move(3, 0, 0); //motor 3, full speed, left 
  move(4, 0, 0); //motor 4, full speed, left
  move(5, 0, 0); //motor 5, full speed, left
  delay(200);

  // Rest Gesture
  move(1, 0, 0); //motor 1, full speed, left
  move(2, 0, 0); //motor 2, full speed, left
  move(3, 0, 0); //motor 3, full speed, left 
  move(4, 0, 0); //motor 4, full speed, left
  move(5, 0, 0); //motor 5, full speed, left
  delay(3000);


  //Point Gesture
  move(1, 255, 1); //motor 1, full speed, left
  move(2, 0, 0); //motor 2, full speed, left
  move(3, 255, 1); //motor 3, full speed, left 
  move(4, 255, 1); //motor 4, full speed, left
  move(5, 255, 1); //motor 5, full speed, left
  delay(3000);

  move(1, 255, 0); //motor 1, full speed, left
  move(2, 0, 0); //motor 2, full speed, left
  move(3, 180, 0); //motor 3, full speed, left 
  move(4, 180, 0); //motor 4, full speed, left
  move(5, 255, 0); //motor 5, full speed, left
  delay(200);

  // Rest Gesture
  move(1, 0, 0); //motor 1, full speed, left
  move(2, 0, 0); //motor 2, full speed, left
  move(3, 0, 0); //motor 3, full speed, left 
  move(4, 0, 0); //motor 4, full speed, left
  move(5, 0, 0); //motor 5, full speed, left
  delay(3000);
}


void move(int motor, int speed, int direction){
// Move specific motor at speed and direction
// motor: 0 for B 1 for A
// speed: 0 is off, and 255 is full speed
// direction: 0 clockwise, 1 counter-clockwise

  digitalWrite(STBY, HIGH); //disable standby

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if(motor == 1){
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);
  }
  if(motor == 2){
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, speed); 
  }
  if(motor == 3){
    digitalWrite(AIN3, inPin1);
    digitalWrite(AIN4, inPin2);
    analogWrite(PWMC, speed);
  }
  if(motor == 4){
    digitalWrite(BIN3, inPin1);
    digitalWrite(BIN4, inPin2);
    analogWrite(PWMD, speed);
  }
  if(motor == 5){
    digitalWrite(AIN5, inPin1);
    digitalWrite(AIN6, inPin2);
    analogWrite(PWME, speed);
  }
}

void stop(){
  // Enable standby  
  digitalWrite(STBY, LOW); 
}