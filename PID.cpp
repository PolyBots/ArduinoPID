#include "PID.h"
#include <Arduino.h>

PID::PID()
	: delta(0), sum(0), lastTime(0), firstTime(true)
{

}

double PID::operator()(double errorVal, double kP, double kI, double kD)
{
	unsigned long time = millis();
	double deltaErr = (firstTime ? 0 : errorVal - prevErr);
	double deltaTime = (firstTime ? 0 : double(time - lastTime)/1000.0);

	lastTime = time;
	prevErr = errorVal;
	firstTime = false;

	return (kP * errorVal) + (sum += kI * deltaTime * errorVal) + (kD * deltaErr/deltaTime);
}