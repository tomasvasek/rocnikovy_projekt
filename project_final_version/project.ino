#include <IFTTTWebhook.h>
#include <ESP8266WiFi.h>
#define ledPin 5
#define wakePin 16
#define ssid "vaskovi2_home"
#define password "VaSkOvI654321"
#define IFTTT_API_KEY "bVC7mV4gdOBCnChEDjXz7V"
#define IFTTT_EVENT_NAME "button"

void setup() {
  Serial.begin(9600);
  while (!Serial) {
  }
  Serial.println(" ");
  Serial.println("Tlačítko zmáčknuto");
  Serial.println(" ");
  
  connectToWifi();
  
  IFTTTWebhook hook(IFTTT_API_KEY, IFTTT_EVENT_NAME);
  hook.trigger();
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  
  ESP.deepSleep(wakePin);

}

void connectToWifi() {
  Serial.println(" ");
  Serial.print("Connecting to: "); 
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  Serial.println(" ");
  Serial.print("Pokus o připojení: ");
  //10 sekund se pokouší o připojené
  int i = 10;
  while (WiFi.status() != WL_CONNECTED && i >= 0) {
    delay(1000);
    Serial.print(i);
    Serial.print(", ");
    i--;
  }
  Serial.println(" ");
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("Connected.");
    Serial.println(" ");
    Serial.print("NodeMCU ip address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("Připojení selhalo");
  }
} 

void loop() {
  Serial.println("This shouldn't get printed");
}
