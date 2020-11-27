class ExperimentalEncoder
{
private:
    int pinA;
    int pinB;
    int position;
    unsigned char state;
    int location;

public:
    ExperimentalEncoder(int pinALoc, int pinBLoc);
    void update();
    int read();

    static void callbackMethod();
    void registerCallback();
};