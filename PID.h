class PID
{
public:
	PID();
	double operator()(double errorVal, double kP, double kI, double kD);
private:
	bool firstTime;
	double prevErr, sum;
	unsigned long lastTime;
};