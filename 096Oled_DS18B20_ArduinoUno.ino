#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <DallasTemperature.h> //DS18B20 library

#define ONE_WIRE_BUS 4 //DS18B20 #4 pin

// OLED display TWI address (Use I2C Scanner)
#define OLED_ADDR   0x3C

//DS18B20 Tools/Settings
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

Adafruit_SSD1306 display(-1);

//#if (SSD1306_LCDHEIGHT != 64)
//#error("Height incorrect, please fix Adafruit_SSD1306.h!");
//#endif

void setup() {
  Serial.begin(9600);
  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();
  sensors.begin();

  // display a line of text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Boot");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setTextSize(2);
  display.display();
}

void loop() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Temperature:");
  
  display.setTextSize(2);
  sensors.requestTemperatures(); 
  //Serial.print(sensors.getTempCByIndex(0)); 
  //Serial.println(" - Celsius temperature: ");
  //display.clearDisplay();
  //display.display();
  display.setCursor(0,8);
  display.print(sensors.getTempCByIndex(0));
  
  display.setCursor(65,6);
  display.setTextSize(1);
  display.print("o");

  display.setCursor(72,8);
  display.setTextSize(2);
  display.print("C");
  display.display();
  delay(1500);
}
