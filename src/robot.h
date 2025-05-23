// robot.h
#pragma once

#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVO_MIN  150
#define SERVO_MAX  600

extern Adafruit_PWMServoDriver pwm;
extern float servoTrim[8];
extern float currentAngle[8];

class Oscillator {
public:
  float amplitude = 0;
  float phase = 0;
  float offset = 0;
  int period = 1000;
  unsigned long refTime = 0;
  bool running = true;

  void reset();
  void setAmplitude(float a);
  void setPhase(float p);
  void setOffset(float o);
  void setPeriod(int p);
  float refresh();
};

extern Oscillator osc[8];

void setServo(uint8_t ch, float angle);
void moveServos(int totalTime, float target[8]);
void playMotion(int steps, int T, int amplitude[8], int offset[8], int phase[8], int period[8]);
void stand(int transitionTime);
void walkForwardSteps(int steps, int T);
void turnLeftSteps(int steps, int T);
void turnRightSteps(int steps, int T);
void hello();
void moonwalkL(int steps, int T = 5000);
void run(int steps, int T = 5000);
void dance(int steps, int T = 600);
void frontBack(int steps, int T = 600);
void upDown(int steps, int T = 5000);
void pushUp(int steps, int T = 600);
void jump();
void home();
void walkForward(int T);
void turnRight(int T);
void turnLeft(int T);