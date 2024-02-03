#include <DynamixelWorkbench.h> //Include dynamixel workbench and sdk libraries

DynamixelWorkbench dxl_wb; //Initialize dynamixel workbench object

int high1 = -1;
int low1 = -1;
int high2 = -1;
int low2 = -1;
int high3 = -1;
int low3 = -1;
int high4 = -1;
int low4 = -1;
int high5 = -1;
int low5 = -1;

uint32_t get_data_1;
uint32_t get_data_2;
uint32_t get_data_3;
uint32_t get_data_4;
uint32_t get_data_5;
uint32_t get_data_6;
uint32_t get_data_7;
uint32_t get_data_8;
uint32_t get_data_9;
uint32_t get_data_10;

uint8_t ID1 = 1;
uint8_t ID2 = 2;
uint8_t ID3 = ;
uint8_t ID3 = ;
uint8_t ID3 = ;


void setup() {
  // Initialize communication with dynamixel motor
  dxl_wb.init("1", 1000000);

  //Ping motor 1 so that we can send commands to it and read data from it
  uint16_t model_number = 0;
  dxl_wb.ping(ID1, &model_number);
  dxl_wb.ping(ID2, &model_number);
  dxl_wb.ping(ID3, &model_number);
  dxl_wb.ping(ID4, &model_number);
  dxl_wb.ping(ID5, &model_number);

  //Initialize serial communication with a baudrate of 9600
  Serial.begin(9600);

  dxl_wb.goalPosition(ID1, (int32_t)(0));
  dxl_wb.goalPosition(ID2, (int32_t)(0));
  dxl_wb.goalPosition(ID3, (int32_t)(0));
  dxl_wb.goalPosition(ID4, (int32_t)(0));
  dxl_wb.goalPosition(ID5, (int32_t)(0)); 

}

void loop() {
  if(Serial.available() >1)
{
  //Rdad in low and high byte of a 10 bit number
  low1 = Serial.read();
  high1 = Serial.read();
  low2 = Serial.read();
  high2 = Serial.read();
  low3 = Serial.read();
  high3 = Serial.read();
  low4 = Serial.read();
  high4 = Serial.read();
  low5 = Serial.read();
  high5 = Serial.read();
  delay(1500);
  
  //Contorl motor 1 to get gc to number we read in
  dxl_wb.goalPosition(ID1, (int32_t) (low1 + high1*356));
  delay(3000);
  
  dxl_wb.goalPosition(ID2, (int32_t) (low2 + high2*356));
  delay(3000); //wait until we get to the position before we continue
  
  dxl_wb.goalPosition(ID3, (int32_t) (low3 + high3*356));
  delay(3000); //wait until we get to the position before we continue
  
  dxl_wb.goalPosition(ID4, (int32_t) (low4 + high4*356));
  delay(3000); //wait until we get to the position before we continue
  
  dxl_wb.goalPosition(ID5, (int32_t) (low5 + high5*356));
  delay(3000); //wait until we get to the position before we continue

  //Checks the Position property of the dynamixel
  dxl_wb.readRegister(ID1, (uint16_t)36, (uint16_t)3, &get_data_1);
  dxl_wb.readRegister(ID1, (uint16_t)37, (uint16_t)3, &get_data_2);

  dxl_wb.readRegister(ID2, (uint16_t)36, (uint16_t)4, &get_data_3);
  dxl_wb.readRegister(ID2, (uint16_t)37, (uint16_t)4, &get_data_4);

  dxl_wb.readRegister(ID2, (uint16_t)36, (uint16_t)4, &get_data_5);
  dxl_wb.readRegister(ID2, (uint16_t)37, (uint16_t)4, &get_data_6);

  dxl_wb.readRegister(ID2, (uint16_t)36, (uint16_t)4, &get_data_7);
  dxl_wb.readRegister(ID2, (uint16_t)37, (uint16_t)4, &get_data_8);

  dxl_wb.readRegister(ID2, (uint16_t)36, (uint16_t)4, &get_data_9);
  dxl_wb.readRegister(ID2, (uint16_t)37, (uint16_t)4, &get_data_10);
  

  //Send the low and high bytes over the serial port back to Matlab
  Serial.write((int8_t)get_data_1);
  Serial.write((int8_t)get_data_2);
//
  Serial.write((int8_t)get_data_3);
  Serial.write((int8_t)get_data_4);

  Serial.write((int8_t)get_data_5);
  Serial.write((int8_t)get_data_6);

  Serial.write((int8_t)get_data_7);
  Serial.write((int8_t)get_data_8);

  Serial.write((int8_t)get_data_9);
  Serial.write((int8_t)get_data_10);
}}
