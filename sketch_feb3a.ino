#define pirPin 2
#define buttonPin 3  
#define motionLedPin 12
#define buttonLedPin 13  

volatile bool motionDetectedFlag = false;
volatile bool buttonPressedFlag = false;

void interruptMotion() {
    motionDetectedFlag = true;
}

void interruptButton() {
    buttonPressedFlag = true;
}

void setup() {
    pinMode(pirPin, INPUT);
    pinMode(buttonPin, INPUT_PULLUP);  
    pinMode(motionLedPin, OUTPUT);
    pinMode(buttonLedPin, OUTPUT);
    Serial.begin(9600);

    attachInterrupt(digitalPinToInterrupt(pirPin), interruptMotion, RISING);
    attachInterrupt(digitalPinToInterrupt(buttonPin), interruptButton, FALLING);
}

void loop() {
    if (motionDetectedFlag) {
        digitalWrite(motionLedPin, HIGH);
        Serial.println("Motion detected! Turning on Motion LED.");
        motionDetectedFlag = false;
    } else {
        digitalWrite(motionLedPin, LOW);
    }

    if (buttonPressedFlag) {
        digitalWrite(buttonLedPin, HIGH);
        Serial.println("Button pressed! Turning on Button LED.");
        buttonPressedFlag = false;
    } else {
        digitalWrite(buttonLedPin, LOW);
    }

    delay(1000);
}