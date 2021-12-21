int SWITCH = 8;

int SENSOR1_ECHO = 12, SENSOR1_TRIG = 13;
int SENSOR2_ECHO = 3, SENSOR2_TRIG = 4;

int RED = 7, BLUE = 5, GREEN = 4;

int BUZZER = 2;

long DURATION1, DURATION2;

int DISTANCE1, DISTANCE2;

int S;
int ActiveTime;
unsigned long time;

void setup() {
	pinMode(SWITCH, INPUT);
	pinMode(SENSOR1_ECHO, INPUT);
	pinMode(SENSOR1_TRIG, OUTPUT);
	pinMode(SENSOR2_ECHO, INPUT);
	pinMode(SENSOR2_TRIG, OUTPUT);
	pinMode(RED, OUTPUT);
	pinMode(GREEN, OUTPUT);
	pinMode(BLUE, OUTPUT);
	pinMode(BUZZER, OUTPUT);
	Serial.begin(9600);
}
void loop() {
	S = digitalRead(SWITCH);
	if (S == 1){
		delay(60000);
 
		while (S == 1){
			RGB(0, 255, 0);
			 
			digitalWrite(SENSOR1_TRIG, LOW);
			delayMicroseconds(2);
			 
			digitalWrite(SENSOR1_TRIG, HIGH);
			delayMicroseconds(10);
			digitalWrite(SENSOR1_TRIG, LOW);
			 
			DURATION1 = pulseIn(SENSOR1_ECHO, HIGH);
			DISTANCE1 = DURATION1 * 0.034 / 2;
			 
			delay(500);
			S = digitalRead(SWITCH);
			 
			if (DISTANCE1 <= 50){
			 
				ActiveTime = millis();
				while (S == 1){
					RGB(255, 0, 0);
			 
					if (millis() - ActiveTime > 15000){
						tone(BUZZER, 1000);
			 
						while (S == 1){
							RGB(0, 0, 0);
							delay(100);
							RGB(255, 0, 0);
							delay(100);
							S = digitalRead(SWITCH);
						}
					}
 
					S = digitalRead(SWITCH);
				}
			}
		}
	}
	noTone(BUZZER);
	RGB(0, 0, 0);
}
void RGB(int REDValue, int GREENValue, int BLUEValue){
	analogWrite(RED, REDValue);
	analogWrite(GREEN, GREENValue);
	analogWrite(BLUE, BLUEValue);
}
