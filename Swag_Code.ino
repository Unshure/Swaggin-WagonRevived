#include <NewPing.h>
#include <HC020K.h>
#include <DRV8835.h>
#include <Encoder.h>
#include <IRFilter.h>
#include <SharpDistSensor.h>
#include <SparkFun_TB6612.h>

Encoder encRight(0,1); //Motor 0 is Left
Encoder encLeft(2,3); //Motor 1 is Right
#define AIN1 20
#define BIN1 18
#define AIN2 21
#define BIN2 17
#define PWMA 5
#define PWMB 6
#define STBY 19


// these constants are used to allow you to make your motor configuration 
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = 1;
const int offsetB = 1;

const byte FrontSensor = A0;
const byte RearLeftSensor = A0;
const byte RearRightSensor = A0;

// Window size of the median filter (odd number, 1 = no filtering)
const byte mediumFilterWindowSize = 5;


// Initializing motors.  The library will allow you to initialize as many
// motors as you have memory for.  If you are using functions like forward
// that take 2 motors as arguements you can either write new functions or
// call the function more than once.
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);


//// Encoders           //Encoder declarations, eventually move it into a struct and hopefully a class on it's own.
//// - Right wheel
//#define RightA 1
//#define RightB 0
//// - Left wheel
//#define LeftA 2
//#define LeftB 3


void setup() {
  Serial.begin(9600);
  
}

//From Encoder File
long oldPosition  = -999;

void loop() {
  long newRightPosition = encRight.read();
  long newLeftPosition = encLeft.read();

  //if (newRightPosition != oldPosition) {
    //oldPosition = newRightPosition;
    //Serial.println(newRightPosition);

  //}

  
  //if (newLeftPosition != oldPosition) {
    //oldPosition = newLeftPosition;
    //Serial.println(newLeftPosition);

//  }
   //Use of the drive function which takes as arguements the speed
   //and optional duration.  A negative speed will cause it to go
   //backwards.  Speed can be from -255 to 255.  Also use of the 
   //brake function which takes no arguements.
   motor1.drive(100);
   motor2.drive(100);
   Serial.print(newLeftPosition);
   Serial.println(newRightPosition);
   //motor1.brake();
   //motor2.brake();
   
   delay(100);

}
