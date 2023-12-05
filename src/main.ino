/* REF (top female) - Reference electrode snap connector.  
 * Connect this to a separate section of the body such as a bony portion of the elbow
 * or a nonadjacent muscle near the muscle group.
 * MID (lower left female) - Middle muscle electrode snap connector.
 * Connect to the middle of the muscle group.
 * END (lower right female) - End muscle electrode snap connector.
 * Connect to the end of the muscle group.*/
 
/* button toggle for different gesture combinations
 * button 1 = rest, close, pinch 
 * button 2 = rest, point, hook*/
#define BUTTON_COMBO1 3 // left side
#define BUTTON_COMBO2 4 // right side

// pins for Force sensitive resistor
#define FSR1_PIN A6
//#define FSR2_PIN A7

// pins for myoware muscle sensors
// A1 = stick in Anterior-Flexor digitorum profundus-below
// A2 = stick in Posterior-Flexor carpi ulnaris-above
#define EMG_SENSOR1 A1
#define EMG_SENSOR2 A2

// pin for vibration motor
#define VIBRATION_MOTOR 10

/*------- Motor Driver 3 -------*/
//Motor A = pinky
#define PWMA 3 //Speed control 
#define AIN1 0 //Direction
#define AIN2 1 //Direction
//Motor B = ring
#define PWMB 5 //Speed control
#define BIN1 2 //Direction
#define BIN2 4 //Direction

/*------- Motor Driver 2 -------*/
//Motor C = middle
#define PWMC 6 //Speed control 
#define CIN1 7 //Direction
#define CIN2 8 //Direction
//Motor D = index
#define PWMD 9 //Speed control
#define DIN1 19 //Direction
#define DIN2 12 //Direction

/*------- Motor Driver 1 -------*/
//Motor E = thumb
#define PWME 11 //Speed control 
#define EIN1 14 //Direction
#define EIN2 13 //Direction

/* 0 = rest/open
 * 1 = close
 * 2 = pinch
 * 3 = point
 * 4 = hook*/
int pastGesture_memory = 0;
/* vibrate_start_counter = 0 = no vibr
 * vibrate_start_counter < 30 = vibr
 * vibrate_start_counter > 30 = no vibr*/
int vibrate_start_counter = 30;

void setup() {
  Serial.begin(9600); // Serial monitor/plotter
  //pin modes
  pinMode(BUTTON_COMBO1, INPUT);
  pinMode(BUTTON_COMBO2, INPUT);
  
  pinMode(EMG_SENSOR1, INPUT);
  pinMode(EMG_SENSOR2, INPUT);

  pinMode(FSR1_PIN, INPUT);
  //pinMode(FSR2_PIN, INPUT);

  pinMode(VIBRATION_MOTOR, OUTPUT);

  //Motor A = pinky
  pinMode(PWMA, OUTPUT); //Speed control 
  pinMode(AIN1, OUTPUT); //Direction
  pinMode(AIN2, OUTPUT); //Direction
  //Motor B = ring
  pinMode(PWMB, OUTPUT); //Speed control
  pinMode(BIN1, OUTPUT); //Direction
  pinMode(BIN2, OUTPUT); //Direction
  //Motor C = middle
  pinMode(PWMC, OUTPUT); //Speed control 
  pinMode(CIN1, OUTPUT); //Direction
  pinMode(CIN2, OUTPUT); //Direction
  //Motor D = index
  pinMode(PWMD, OUTPUT); //Speed control
  pinMode(DIN1, OUTPUT); //Direction
  pinMode(DIN2, OUTPUT); //Direction
  //Motor E = thumb
  pinMode(PWME, OUTPUT); //Speed control 
  pinMode(EIN1, OUTPUT); //Direction
  pinMode(EIN2, OUTPUT); //Direction
  
  delay(1000);
  robot_start();
}

/************************************
 * THE PROCESS OF THE EMG PH SOFTWARE
 * 1. START/WELCOME METHODS
 * * WELCOME METHOD GETS DATA SAMPLE FROM THE USER
 * * AT EACH OF THREE (3) GESTURES
 * 2. REST GESTURE
 * 3. GET EMG SIGNALS
 * 4. PROCESS SIGNALS
 * 5. USE GESTURE COMMANDS BASED ON EMG SIGNAL
 * * REPEATING THE GESTURE DONE DOES NOT MAKE ANY CHANGES
 * * NOT USING REST GESTURE BEFORE DOING ANOTHER GESTURE
 * * DOES NOT MAKE ANY CHANGES
 * 6. CHECK TWO (2) BUTTONS TO DETERMINE GESTURE COMBINATION
 * * NOTE THAT THERE IS NO GESTURE IF TWO (2) BUTTONS IS SAME
 * * IN STATE
 * 7. CONSTANT READING OF FSR VALUE WHEN IN ANY GESTURE
 * * REACHING A PROGRAMMED POINT/VALUE IN FSR TRIGGERS
 * * VIBRATION MOTORS
 * 8. REPEAT READING EMG SIGNLAS(NO. 3)
 ************************************/

void loop() {
  int command = Serial.read();
  int button_state = check_buttonState();
  if (command == '0'){// if device does not have data sets
    // initialize
    welcome();
  }else if (command == '1'){ // python detects extension, pointing upward
    if (button_state == 1){
      Serial.println("rest");//...................... for testing
      robot_rest(pastGesture_memory);
    }else if (button_state == 2){
      Serial.println("rest");//...................... for testing
      robot_rest(pastGesture_memory);
    } 
  }else if (command == '2'){ // python detects close, closed fist
    if (button_state == 1){
      if (pastGesture_memory == 0){
        Serial.println("close");//.......................... for testing
        robot_close();
      }
    }else if (button_state == 2){
      if (pastGesture_memory == 0){
        Serial.println("point");//................ for testing
        robot_point();
      }
    }
  }else if (command == '3'){ // python detects flexion, pointing downward
    if (button_state == 1){
      if (pastGesture_memory == 0){
        Serial.println("pinch");//................. for testing
        robot_pinch();
      }
    }else if (button_state == 2){
      if (pastGesture_memory == 0){
        Serial.println("hook");//............ for testing
        robot_hook();
      }
    }                             
  }

  check_FSR();
  readEMG(200);
}

void robot_start(){
  // move hand from open to close then back open
  robot_close();
  delay(500);
  robot_rest(pastGesture_memory);
  delay(400);
}

void welcome(){
  /*  Capture EMG signals 500 times 3 times
   *  NOTE: INSTRUCTION FOR GETTING DATA SETS
   *  HAND WILL CLOSE THEN OPEN
   *  AFTER IT OPENED, MAKE THE USER CLOSE HIS/HER FIST
   *  
   *  THE HAND WILL AGAIN CLOSE THEN OPEN
   *  AFTER IT OPENED, MAKE THE USER DO FLEXION
   *  FLEXION = FINGERS POINTING DOWNWARDS
   *  
   *  THE HAND WILL AGAIN CLOSE THEN OPEN
   *  AFTER IT OPENED, MAKE THE USER DO EXTENSION
   *  EXTENSION = FINGERS POINTING UPWARDS */
  robot_close();
  delay(1000);
  robot_rest(pastGesture_memory);
  delay(600);
  // First loop, for closed
  readEMG(500);
  delay(1000);

  robot_close();
  delay(1000);
  robot_rest(pastGesture_memory);
  delay(600);
  // Second loop, for fingers pointing downward-flexion
  readEMG(500);
  delay(1000);

  robot_close();
  delay(1000);
  robot_rest(pastGesture_memory);
  delay(600);
  // Third loop, for fingers pointing upward-extension
  readEMG(500);
  delay(1000);

  robot_close();
  delay(1000);
  robot_rest(pastGesture_memory);
  delay(600);
  robot_close();
  delay(1000);
  robot_rest(pastGesture_memory);
  delay(600);
}

void readEMG(int value_count){
  for(int count = 0; count <= value_count; count++){
    int emg1 = analogRead(EMG_SENSOR1);
    int emg2 = analogRead(EMG_SENSOR2);

    Serial.println(emg1);
    Serial.print(",");
    Serial.println(emg2);
  }
}

int check_buttonState(){
  //for checking
  //Serial.print(digitalRead(BUTTON_COMBO1));
  //Serial.print(" , ");
  //Serial.println(digitalRead(BUTTON_COMBO2));
  if (digitalRead(BUTTON_COMBO1) == 1 && digitalRead(BUTTON_COMBO2) == 0){
    return 1;
  }else if (digitalRead(BUTTON_COMBO1) == 0 && digitalRead(BUTTON_COMBO2) == 1){
    return 2;
  }else if (digitalRead(BUTTON_COMBO1) == 0 && digitalRead(BUTTON_COMBO2) == 0){
    return 0;
  }else if (digitalRead(BUTTON_COMBO1) == 1 && digitalRead(BUTTON_COMBO2 == 1)){
    return 0;
  }
}

void check_FSR(){
  /* This function checks the FSR value
   * This also prompts vibration motor if the FSR reached
   * a certain value
   * */
  int fsr_value = analogRead(FSR1_PIN);
  //for checking
  //Serial.println(fsr_value);
  if (fsr_value > 100){
    vibrate_start_counter--;
    if (vibrate_start_counter == 0){
      analogWrite(VIBRATION_MOTOR, 0);
      vibrate_start_counter = 80;
    }else if (vibrate_start_counter < 30){
      analogWrite(VIBRATION_MOTOR, 200);
    }
  }else if (fsr_value > 50){
    vibrate_start_counter--;
    if (vibrate_start_counter == 0){
      analogWrite(VIBRATION_MOTOR, 0);
      vibrate_start_counter = 80;
    }else if (vibrate_start_counter < 30){
      analogWrite(VIBRATION_MOTOR, 150);
    }
  }else if (fsr_value > 10){
    vibrate_start_counter--;
    if (vibrate_start_counter == 0){
      analogWrite(VIBRATION_MOTOR, 0);
      vibrate_start_counter = 80;
    }else if (vibrate_start_counter < 30){
      analogWrite(VIBRATION_MOTOR, 100);
    }
  }else{
    analogWrite(VIBRATION_MOTOR, 0);
    vibrate_start_counter = 30;
  }
}

// all robot available gestures
// button 1
void robot_rest(int memory){
  // rest position
  switch(memory){
     case 0: // rest
      break;
      
     case 1: // close
      move(1, 50, 1);
      move(2, 50, 1);
      move(3, 50, 1);
      move(4, 50, 1);
      move(5, 50, 1);

      delay(600);
      // stop the motors once it reached resting pos
      move(1, 0, 0);
      move(2, 0, 0);
      move(3, 0, 0);
      move(4, 0, 0);
      move(5, 0, 0);
      pastGesture_memory = 0;
      break;
      
     case 2: // pinch
      move(1, 50, 1);
      move(2, 50, 1);
      move(3, 0, 1);
      move(4, 0, 1);
      move(5, 0, 1);

      delay(600);
      // stop the motors once it reached resting pos
      move(1, 0, 0);
      move(2, 0, 0);
      move(3, 0, 0);
      move(4, 0, 0);
      move(5, 0, 0);
      pastGesture_memory = 0;
      break;
      
     case 3: // hook
      move(1, 0, 1);
      move(2, 50, 1);
      move(3, 50, 1);
      move(4, 50, 1);
      move(5, 50, 1);

      delay(600);
      // stop the motors once it reached resting pos
      move(1, 0, 0);
      move(2, 0, 0);
      move(3, 0, 0);
      move(4, 0, 0);
      move(5, 0, 0);
      pastGesture_memory = 0;
      break;
      
     case 4: // point
      move(1, 50, 1);
      move(2, 0, 1);
      move(3, 50, 1);
      move(4, 50, 1);
      move(5, 50, 1);

      delay(600);
      // stop the motors once it reached resting pos
      move(1, 0, 0);
      move(2, 0, 0);
      move(3, 0, 0);
      move(4, 0, 0);
      move(5, 0, 0);
      pastGesture_memory = 0;
      break;
  } 
}

void robot_close(){
  // closed fist position
  move(1, 70, 0);
  move(2, 70, 0);
  move(3, 70, 0);
  move(4, 70, 0);
  move(5, 70, 0);
  pastGesture_memory = 1;
}

void robot_pinch(){
  // index close, thumb close
  move(1, 70, 0);
  move(2, 70, 0);
  move(3, 0, 0);
  move(4, 0, 0);
  move(5, 0, 0);
  pastGesture_memory = 2;
}

// button 2
// includes robot_rest()
void robot_point(){
  // all close except index
  move(1, 70, 0);
  move(2, 0, 0);
  move(3, 70, 0);
  move(4, 70, 0);
  move(5, 70, 0);
  pastGesture_memory = 3;
}

void robot_hook(){
  // all close except thumb
  move(1, 0, 0);
  move(2, 70, 0);
  move(3, 70, 0);
  move(4, 70, 0);
  move(5, 70, 0);
  pastGesture_memory = 4;
}

// motor controller
void move(int motor, int speed, int direction){
  //Move specific motor at speed and direction
  //motor: 1 - 5 (5 motors)
  //speed: 0 is off, and 255 is full speed
  //direction: 0 clockwise, 1 counter-clockwise

  boolean inPin1 = LOW;//0
  boolean inPin2 = HIGH;//1

  if(direction == 1){
    inPin1 = HIGH;//1
    inPin2 = LOW;//0
  }

  switch(motor){
    case 1: // THUMB
        digitalWrite(AIN1, inPin1);
        digitalWrite(AIN2, inPin2);
        analogWrite(PWMA, speed);
        break;
    case 2: // INDEX
        digitalWrite(BIN1, inPin1);
        digitalWrite(BIN2, inPin2);
        analogWrite(PWMB, speed);
        break;
    case 3: // MIDDLE
        digitalWrite(CIN1, inPin1);
        digitalWrite(CIN2, inPin2);
        analogWrite(PWMC, speed);
        break;
    case 4: // RING
        digitalWrite(DIN1, inPin1);
        digitalWrite(DIN2, inPin2);
        analogWrite(PWMD, speed);
        break;
    case 5: // PINKY
        digitalWrite(EIN1, inPin1);
        digitalWrite(EIN2, inPin2);
        analogWrite(PWME, speed);
        break;
  }
}
