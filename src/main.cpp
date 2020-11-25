#include <Arduino.h>
#include <SimpleFOC.h>


HardwareSerial Serial1(USART2_RX, USART2_TX);
BLDCDriver6PWM driver(PHASE_UH, PHASE_UL, PHASE_VH, PHASE_VL, PHASE_WH, PHASE_WL);
BLDCMotor motor(6);
HallSensor sensor(HALL1, HALL2, HALL3, 6);

void hallA() {
  sensor.handleA();
}

void hallB() {
  sensor.handleB();
}

void hallC() {
  sensor.handleC();
}

volatile long pwm_on_micros; // from 1000 to 2000

void pwm1() {
  static bool last_state;
  static long last_start_time;
  unsigned long now = micros();
  bool state_now = digitalRead(PWM);
  if (state_now != last_state) {
      if (state_now) {
          last_start_time = now;
      } else {
          pwm_on_micros = now - last_start_time;
      }
      last_state = state_now;
  }
}

void setup() {

  Serial1.begin(115200);
  delay(1000);

  attachInterrupt(digitalPinToInterrupt(PWM), pwm1, CHANGE);
  sensor.enableInterrupts(hallA, hallB, hallC);
  sensor.init();

  motor.linkDriver(&driver);
  motor.linkSensor(&sensor);
  motor.controller = ControlType::voltage;

  driver.voltage_power_supply = 24;
  motor.voltage_limit = 5;
  motor.voltage_sensor_align = 1;
  motor.useMonitoring(Serial1);

  driver.init();
  motor.init();
  // motor.initFOC(2.1, Direction::CCW);
  motor.initFOC();
}

void loop() {
  float voltage_target = map(pwm_on_micros,1000,2000,-500,500)/100.0; // map from -5v to +5v
  motor.loopFOC();
  motor.move(voltage_target);
  motor.monitor();
}