/**
 * Free Text Push notification send example
 *
 * You need to sign up for create your own node and field: https://iotguru.live/signup
 * 
 * The variables of the API call:
 *
 * {nodeKey} - the API key of your node
 * {message} - the message (URL encoded)
 *
 * http://api.iotguru.live/push/freeText/{nodeKey}/{message}
 *
 * See the example HTTP call below (don't forget to replace values!).
 *
 */
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

void setup() {
    Serial.begin(115200);
    Serial.setTimeout(2000);

    WiFi.mode(WIFI_STA);
    WiFi.begin("your.wifi.ssid", "your.wifi.password");

    while (WiFi.status() != WL_CONNECTED) {
        delay(50);
        Serial.print(".");
    }

    Serial.println("Connected...");
}

void loop()
{
    HTTPClient http;
    http.begin("http://api.iotguru.live/push/freeText/sTs5N5dlTmhbPT-ISHZApQ/message%20text");
    Serial.println("Result code: " + String(http.GET()));
    http.end();

    delay(60000);
}
