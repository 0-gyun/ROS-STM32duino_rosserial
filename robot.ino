/* 
 * rosserial::std_msgs::Float64 Test
 * Receives a Float64 input, subtracts 1.0, and publishes it
 */
#define MCU_STM32F103C8
#include <ros.h>
#include <std_msgs/Bool.h>
#include <geometry_msgs/Point.h>
#include <sensor_msgs/JointState.h>
#include<Servo.h>
#include<AccelStepper.h>
#include <arduino-timer.h>
Timer<1, micros> timer; 
Servo servo;

ros::NodeHandle nh;

#define step_pin1      PB12
#define dir_pin1       PB13
#define step_pin2      PB14
#define dir_pin2       PB15
#define step_pin3      PA8
#define dir_pin3       PA9

#define sw1            PB3
#define sw2            PB4
#define sw3            PB5

#define grip           PB7
 
AccelStepper stepper1(AccelStepper::DRIVER, step_pin1, dir_pin1); 
AccelStepper stepper2(AccelStepper::DRIVER, step_pin2, dir_pin2); 
AccelStepper stepper3(AccelStepper::DRIVER, step_pin3, dir_pin3);  

geometry_msgs::Point  current_pose;
ros::Publisher current_pose_pub("current_pose", &current_pose);

bool pub_timer(void *) {
  current_pose.x = stepper1.currentPosition();
  current_pose.y = stepper2.currentPosition();
  current_pose.z = stepper3.currentPosition();
  current_pose_pub.publish( &current_pose );
  nh.spinOnce();
  return true;
}

//homing Callback Fucntion
void HomingCb( const std_msgs::Bool& homing){
  
}
ros::Subscriber<std_msgs::Bool> homing_sub("homing", &HomingCb);

//Joint Callback Function
void JointCb( const sensor_msgs::JointState& msg){
  stepper1.moveTo(long(msg.position[0]*1000)-9370);
  stepper2.moveTo(long(msg.position[1]*1000)-1570);
  stepper3.moveTo(long(msg.position[2]*1000)-2410);
}
ros::Subscriber<sensor_msgs::JointState> joint_sub("joint_states", &JointCb);

//Gripper Callback Fucntion
void GripperCb( const std_msgs::Bool& gripper){
  if(gripper.data){
    servo.write(60);
  }
  else{
    servo.write(0);
  }
}
ros::Subscriber<std_msgs::Bool> gripper_sub("gripper", &GripperCb);

void setup()
{
  servo.attach(grip);
  nh.initNode();
  nh.advertise(current_pose_pub);
  nh.subscribe(joint_sub);
  nh.subscribe(homing_sub);
  nh.subscribe(gripper_sub);
  stepper1.setMaxSpeed(1500);
  stepper1.setSpeed(1500);
  stepper1.setAcceleration(1500);
  stepper2.setMaxSpeed(1500);
  stepper2.setSpeed(1500);
  stepper2.setAcceleration(1500);
  stepper3.setMaxSpeed(1500);
  stepper3.setSpeed(1500);
  stepper3.setAcceleration(1500);
  timer.every(10000, pub_timer);
}

void loop()
{
  timer.tick();
  if(stepper1.distanceToGo() != 0){
    stepper1.run();
  }
  else{
    stepper1.stop();
  }
  if(stepper2.distanceToGo() != 0){
    stepper2.run();
  }
  else{
    stepper2.stop();
  }
  if(stepper3.distanceToGo() != 0){
    stepper3.run();
  }
  else{
    stepper3.stop();
  }
  
}
