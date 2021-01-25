#include <bluefruit.h>

#define sensorPin 12

long distance = 0;
long duration = 0;

//#define debugPPG

BLEService timeStampService = BLEService(0x1165);

BLECharacteristic timeStampCharacteristic = BLECharacteristic(0x1166);

BLEDis bledis;    // DIS (Device Information Service) helper class instance
BLEBas  blebas;  // battery
BLEDfu  bledfu;  // OTA DFU service
BLEConnection* connection ;
uint32_t timeStampValue = 0;
long startTimer=0;

//ppg
long samplesTaken = 0; //Counter for calculating the Hz or read rate
byte ledMode;

int counter=0;
int counterG;
uint8_t buf[4];
int buflen=4;
bool connected=false;
unsigned int timer0;
uint16_t bufData[8];
bool dataReady=false;

int samplingRateHz = 100 ;
int samplingRateMs = 1000/10 ;

int mtu=0;
int phy=0;
int interval=0;
uint32_t irPPG=0;
uint32_t irPPG2=0;
uint32_t redPPG=0;
uint32_t redPPG2=0;
uint32_t greenPPG=0;
uint32_t greenPPG2=0;

void read_sensor() {
duration = pulseIn(sensorPin, HIGH);
distance = duration / 58;
delay(2);
}

void print_data() {
Serial.print("distance = ");
Serial.print(distance);
Serial.println(" cm");
}

void updateDistance(){
    read_sensor();
    print_data();
    uint8_t y = distance;
    buf[0]=y;
    dataReady = true ; 
    }
void setup() {
  pinMode(sensorPin, INPUT);
  
  Serial.begin(115200);
  Serial.println(F("Custom TimeStamp Service and Characteristic"));
  Serial.println(F("-----------------------\n"));

  // Initialise the Bluefruit module
  Serial.println("Initialise the OHB module");
  Bluefruit.autoConnLed(true);
  Bluefruit.configPrphBandwidth(BANDWIDTH_MAX);  
  Bluefruit.setTxPower(13);  //13 max - 0 min
  Bluefruit.begin();

  // Set the advertised device name (keep it short!)
  Serial.println("Setting Device Name to 'Open Health Band'");
  Bluefruit.setName("Open Health Band");

  // Set the connect/disconnect callback handlers
  Bluefruit.Periph.setConnectCallback(connect_callback);
  Bluefruit.Periph.setDisconnectCallback(disconnect_callback);
  Bluefruit.Periph.setConnInterval(6, 12); // 7.5 - 15 ms
  // Configure and Start the Device Information Service
  Serial.println("Configuring the Device Information Service");
  bledis.setManufacturer("CRI");
  bledis.setModel("OHB v0.1");
  bledis.setSerialNum("ZZHH");
  bledis.begin();

  // Setup the Custom Service BLEService and BLECharacteristic
  Serial.println("Configuring the Custom Service");
  setupTimeStampService();

  // Setup the advertising packet(s)
  Serial.println("Setting up the advertising payload(s)");
  startAdv();
}

void loop() {
  //timeStampValue = millis()-startTimer;
  //startTimer=millis();
  digitalToggle(LED_RED);
  updateDistance();
  if ( Bluefruit.connected() ) {
      if(dataReady)  {
      // Note: We use .notify instead of .write!
        // If it is connected but CCCD is not enabled
        // The characteristic's value is still updated although notification is not sent
        if ( timeStampCharacteristic.notify(buf,1) ){
            //Serial.print("timeStampCharacteristic updated to: ");
            //Serial.println(timeStampValue); 
            }
        else{
            Serial.println("ERROR: Notify not set in the CCCD or not connected!");
            }
        dataReady=false; 
        }
       else delay(1);
  }
}
