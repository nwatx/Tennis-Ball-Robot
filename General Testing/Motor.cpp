#include <wiringPi.h>
#include<Motor.h>
class Motor
{

    public:
        Motor::Motor(int dirForwardPinLoc, int dirBackwardPinLoc, int powerPinLoc)
            : dirForwardPin{dirForwardPinLoc}, dirBackwardPin{dirBackwardPinLoc}, powerPin{powerPinLoc}
        {
            wiringPiSetup();
            pinMode(dirForwardPin, OUTPUT));
            pinMode(dirBackwardPin, OUTPUT));
            pinMode(powerPin, PWM_OUTPUT);
        }

        Motor::void setPower(double power)
        {
            if (power < 0)
            {
                //make motor spin backwards
                digitalWrite(dirForwardPin, LOW);
                digitalWrite(dirBackwardPin, HIGH);

                //give power to motor adjusted (usually from 0 to 1024), negate as power was initially negative
                double adjustedPower = -1 * power * 1024;
                pwmWrite(powerPin, adjustedPower);
            }

            else
            { //power > 0
                //make motor spin forwards
                digitalWrite(dirForwardPin, HIGH);
                digitalWrite(dirBackwardPin, LOW);

                //give power to motor adjusted (usually from 0 to 1024)
                double adjustedPower = power * 1024;
                pwmWrite(powerPin, adjustedPower);
            }
        }
};
