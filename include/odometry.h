
void odom_Initialize(const tSensors leftQuad, const tSensors rightQuad, const long start_x, const long start_y, const long start_theta)
{
  bdom.pos_x = start_x;
  bdom.pos_y = start_y;
  bdom.pos_theta = start_theta;

  bdom.leftQuad = leftQuad;
  bdom.rightQuad = rightQuad;
}

void odom_SetScales(const float scale, const float turnScale)
{
  bdom.scale = scale;
  bdom.turnScale = turnScale;
}

void odom_GuessScales(const float chassisDiameter, const float wheelDiameter)
{
  bdom.scale = wheelDiameter * PI * UTIL_IN_TO_MM; //1 in = 25.4 mm
  bdom.turnScale = chassisDiameter / wheelDiameter;
}

task trackOdometry()
{
  SensorValue[bdom.leftQuad] = 0;
  SensorValue[bdom.rightQuad] = 0;

  long lastLeft, lastRight, leftTicks, rightTicks;

  float leftMM, rightMM, mm;

  int leftSample, rightSample;

  while (true)
  {
    //Save quads
    leftSample = SensorValue[bdom.leftQuad];
    rightSample = SensorValue[bdom.rightQuad];

    //Get delta
    leftTicks = leftSample - lastLeft;
    rightTicks = rightSample - lastRight;

    //Save last vals
    lastLeft = leftSample;
    lastRight = rightSample;

    //Convert to mm
    leftMM = (float)leftTicks / bdom.scale;
    rightMM = (float)rightTicks / bdom.scale;

    //Get avg delta
    mm = (leftMM + rightMM) / 2.0;

    //Get theta
    bdom.pos_theta += (rightTicks - leftTicks) / bdom.turnScale;

    //Wrap theta
    if(bdom.pos_theta > 180)
      bdom.pos_theta -= 360;
    if(bdom.pos_theta <= -180)
      bdom.pos_theta += 360;

    //Do the odom math
    bdom.pos_x += mm * cosDegrees(bdom.pos_theta);
    bdom.pos_y += mm * sinDegrees(bdom.pos_theta);

    //Save to global
    BCI_Odometry_X = bdom.pos_x;
    BCI_Odometry_Y = bdom.pos_y;
    BCI_Odometry_Theta = bdom.pos_theta;

    //Task wait
    wait1Msec(5);
  }
}
#include "odometry.h"

void odom_Initialize(const tSensors leftQuad, const tSensors rightQuad, const long start_x, const long start_y, const long start_theta)
{
  bdom.pos_x = start_x;
  bdom.pos_y = start_y;
  bdom.pos_theta = start_theta;

  bdom.leftQuad = leftQuad;
  bdom.rightQuad = rightQuad;
}

void odom_SetScales(const float scale, const float turnScale)
{
  bdom.scale = scale;
  bdom.turnScale = turnScale;
}

void odom_GuessScales(const float chassisDiameter, const float wheelDiameter)
{
  bdom.scale = wheelDiameter * PI * UTIL_IN_TO_MM; //1 in = 25.4 mm
  bdom.turnScale = chassisDiameter / wheelDiameter;
}

task trackOdometry()
{
  SensorValue[bdom.leftQuad] = 0;
  SensorValue[bdom.rightQuad] = 0;

  long lastLeft, lastRight, leftTicks, rightTicks;

  float leftMM, rightMM, mm;

  int leftSample, rightSample;

  while (true)
  {
    //Save quads
    leftSample = SensorValue[bdom.leftQuad];
    rightSample = SensorValue[bdom.rightQuad];

    //Get delta
    leftTicks = leftSample - lastLeft;
    rightTicks = rightSample - lastRight;

    //Save last vals
    lastLeft = leftSample;
    lastRight = rightSample;

    //Convert to mm
    leftMM = (float)leftTicks / bdom.scale;
    rightMM = (float)rightTicks / bdom.scale;

    //Get avg delta
    mm = (leftMM + rightMM) / 2.0;

    //Get theta
    bdom.pos_theta += (rightTicks - leftTicks) / bdom.turnScale;

    //Wrap theta
    if(bdom.pos_theta > 180)
      bdom.pos_theta -= 360;
    if(bdom.pos_theta <= -180)
      bdom.pos_theta += 360;

    //Do the odom math
    bdom.pos_x += mm * cosDegrees(bdom.pos_theta);
    bdom.pos_y += mm * sinDegrees(bdom.pos_theta);

    //Save to global
    BCI_Odometry_X = bdom.pos_x;
    BCI_Odometry_Y = bdom.pos_y;
    BCI_Odometry_Theta = bdom.pos_theta;

    //Task wait
    wait1Msec(5);
  }
}
#include "odometry.h"

void odom_Initialize(const tSensors leftQuad, const tSensors rightQuad, const long start_x, const long start_y, const long start_theta)
{
  bdom.pos_x = start_x;
  bdom.pos_y = start_y;
  bdom.pos_theta = start_theta;

  bdom.leftQuad = leftQuad;
  bdom.rightQuad = rightQuad;
}

void odom_SetScales(const float scale, const float turnScale)
{
  bdom.scale = scale;
  bdom.turnScale = turnScale;
}

void odom_GuessScales(const float chassisDiameter, const float wheelDiameter)
{
  bdom.scale = wheelDiameter * PI * UTIL_IN_TO_MM; //1 in = 25.4 mm
  bdom.turnScale = chassisDiameter / wheelDiameter;
}

task trackOdometry()
{
  SensorValue[bdom.leftQuad] = 0;
  SensorValue[bdom.rightQuad] = 0;

  long lastLeft, lastRight, leftTicks, rightTicks;

  float leftMM, rightMM, mm;

  int leftSample, rightSample;

  while (true)
  {
    //Save quads
    leftSample = SensorValue[bdom.leftQuad];
    rightSample = SensorValue[bdom.rightQuad];

    //Get delta
    leftTicks = leftSample - lastLeft;
    rightTicks = rightSample - lastRight;

    //Save last vals
    lastLeft = leftSample;
    lastRight = rightSample;

    //Convert to mm
    leftMM = (float)leftTicks / bdom.scale;
    rightMM = (float)rightTicks / bdom.scale;

    //Get avg delta
    mm = (leftMM + rightMM) / 2.0;

    //Get theta
    bdom.pos_theta += (rightTicks - leftTicks) / bdom.turnScale;

    //Wrap theta
    if(bdom.pos_theta > 180)
      bdom.pos_theta -= 360;
    if(bdom.pos_theta <= -180)
      bdom.pos_theta += 360;

    //Do the odom math
    bdom.pos_x += mm * cosDegrees(bdom.pos_theta);
    bdom.pos_y += mm * sinDegrees(bdom.pos_theta);

    //Save to global
    BCI_Odometry_X = bdom.pos_x;
    BCI_Odometry_Y = bdom.pos_y;
    BCI_Odometry_Theta = bdom.pos_theta;

    //Task wait
    wait1Msec(5);
  }
}
