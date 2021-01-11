#include <IFTTTWebhook.h>
#include <ESP8266WiFi.h>
#define ledPin 5
#define wakePin 16
#define ssid "vaskovi2_home"
#define password "VaSkOvI654321"
#define IFTTT_API_KEY "0i2y5jhIgd7P3S2YjAg53SEZE_uAKCqt5MdjSEY8Kz"
#define IFTTT_EVENT_NAME "facebook_post"

void setup() {
  Serial.println(" ");
  Serial.begin(1200);
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
  Serial.print("Připojování k: "); 
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  Serial.println(" ");
  Serial.print("Pokus o připojení: ");
  //10 sekund se pokouší o připojení
  int i = 10;
  while (WiFi.status() != WL_CONNECTED && i >= 0) { //dokud se nepřipojí k Wi-Fi, odečítá se od i 1 každou sekundu a vypíše se to společně s čárkou
    delay(1000);
    Serial.print(i);
    Serial.print(", ");
    i--;
  }
  Serial.println(" ");
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("Připojeno.");
    Serial.println(" ");
    Serial.print("NodeMCU ip addresa je: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("Připojení selhalo");
  }
} 

void loop() {
  Serial.println("Tohle by se nemělo vypsat, pokud funguje DeeepSleep");
}
