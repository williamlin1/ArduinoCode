#include <AndroidAccessory.h>
#include <AFMotor.h>

char accessoryName[] = "Mega_ADK";
char companyName[] = "Arduino";

AndroidAccessory usb(companyName, accessoryName);
AF_DCMotor motor(1, MOTOR12_64KHZ);
void setup() {
  Serial.begin(9600);
  usb.begin();
  // put your setup code here, to run once:

}

void loop() {
  int msg[2];
  // put your main code here, to run repeatedly:
  
  if(usb.isConnected()){
    msg[0] = usb.read();
    msg[1] = usb.read();  
    byte mesToSend[4] = {(byte)5,(byte)4,(byte)3,(byte)2};
      int bytesSent = usb.write(mesToSend,4);
      Serial.println(msg[0]);
      Serial.println(msg[1]);
      Serial.println(msg[2]);
      Serial.println(msg[3]);

    if(msg[0] == 164){
      Serial.println("SEtitng speed");
      motor.setSpeed(200);
      Serial.println("SEt speed");
      if(msg[1] == 5){
        Serial.println("Before forward");
        motor.run(FORWARD);
        Serial.println("Sending forward message");
      }
    }
    
    Serial.println("we are connected");
    
  }else{
    Serial.println("we are not connected");
  }
}
