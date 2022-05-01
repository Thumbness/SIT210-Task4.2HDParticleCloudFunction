const int greenLed = D0;
const int blueLed = D1;
const int redLed = D2;

// The following line is optional, but recommended in most firmware.
// It allows your code to run before the cloud is connected.
SYSTEM_THREAD(ENABLED);

// This function is called when the Particle.function is called
int ledToggle(String command)
{
    if (command.equals("red"))
    {
        digitalWrite(redLed, HIGH);
        digitalWrite(blueLed, LOW);
        digitalWrite(greenLed, LOW);
        return 1;
    }
    else if (command.equals("blue"))
    {
        digitalWrite(blueLed,HIGH);
        digitalWrite(greenLed, LOW);
        digitalWrite(redLed, LOW);
        return 0;
    }
    else if (command.equals("green"))
    {
        digitalWrite(blueLed,LOW);
        digitalWrite(greenLed, HIGH);
        digitalWrite(redLed, LOW);
        return 0;
    }
    else if (command.equals("flash"))
    {   
        for(int i = 1; i <= 10; i++)
        {
            digitalWrite(blueLed,HIGH);
            digitalWrite(greenLed, HIGH);
            digitalWrite(redLed, HIGH);
            delay(500);
            digitalWrite(blueLed,LOW);
            digitalWrite(greenLed, LOW);
            digitalWrite(redLed, LOW);
            delay(500);
        }
        return 0;
    }
    else if (command.equals("off"))
    {
        digitalWrite(blueLed,LOW);
        digitalWrite(greenLed, LOW);
        digitalWrite(redLed, LOW);
        return 0;
    }
    else
    {
        // Unknown option
        return -1;
    }
}

// The setup() method is called once when the device boots.
void setup()
{
    // In order to set a pin, you must tell Device OS that the
    // pin is an OUTPUT pin.
    // This is often done from setup() since you only need to
    // do it once.
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(blueLed,OUTPUT);

    // This registers a function call. When the function "led"
    // is called from the cloud, the ledToggle() function above
    // will be called.
    Particle.function("led", ledToggle);
}

void loop()
{
}