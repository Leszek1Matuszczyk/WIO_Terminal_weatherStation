#include <TFT_eSPI.h>
#include "Free_Fonts.h"
#include <SPI.h>
#include "Seeed_BME280.h"
#include <Wire.h>

BME280 Sensor;

// Create an instance of the TFT_eSPI class for the LCD display
TFT_eSPI lcd = TFT_eSPI();

// Variables to keep track of the X position for each chart
int posX = 0;
int posX1 = 0;

// Variable to store the sensor readings
float temp = 0;
float pressure = 0;
float altitude = 0;
uint32_t humidity = 0;

// Structure to store chart values
struct Val {
  int line;
  int maxi;
  int mini;
  uint32_t color;
};
Val tempV, pressV, altiV, humidV;

// Variable to control the timing of different actions
long int time = 0;


// Function to draw a bar chart with a line for a given value
int chart1(Val line0, Val line1, Val line2, Val line3, int positionX, int positionY, int sizeX, int sizeY, uint32_t background) {
  int acVal[4];
  // Check if the chart has reached the end
  if (sizeX > posX) {
    // Map the sensor value to the size of the chart
    acVal[0] = map(line0.line, line0.maxi, line0.mini, 0, sizeY);
    acVal[1] = map(line1.line, line1.maxi, line1.mini, 0, sizeY);
    acVal[2] = map(line2.line, line2.maxi, line2.mini, 0, sizeY);
    acVal[3] = map(line3.line, line3.maxi, line3.mini, 0, sizeY);

    // Clear the previous column and draw the new one
    lcd.fillRect(posX + positionX, positionY, 2, sizeY, background);
    lcd.drawPixel(positionX + posX, acVal[0] + positionY, line0.color);
    lcd.drawPixel(positionX + posX, acVal[1] + positionY, line1.color);
    lcd.drawPixel(positionX + posX, acVal[2] + positionY, line2.color);
    lcd.drawPixel(positionX + posX, acVal[3] + positionY, line3.color);
    // Move to the next X position
    posX++;
  } else {
    // Reset X position when the chart is complete
    posX = 0;
  }
}

void setup() {
  // Initialize the LCD display
  lcd.init();
  lcd.setRotation(3);
  lcd.fillScreen(TFT_WHITE);
  lcd.setTextColor(TFT_BLACK);
  lcd.setCursor(0, 10);
  lcd.setFreeFont(FF1);
  lcd.print("Simple weather station using BME280");
  lcd.println();
  lcd.print("Github:    ");
  lcd.println();
  lcd.print("github.com/");
  lcd.println();
  lcd.print("Leszek1Matuszczyk/");
  lcd.println();
  lcd.print("/WIO_Terminal_weatherStation");
  delay(5000);
  lcd.fillScreen(TFT_WHITE);
  lcd.fillRect(0, 0, 320, 200, TFT_BLACK);
  Serial.begin(9600);
  if (!Sensor.init()) {
    Serial.println("Device error!");
  }
  time=millis();
}

void loop() {
  if(time==millis())
{
  // Read sensor values
  temp = Sensor.getTemperature();
  pressure = Sensor.getPressure();
  altitude = Sensor.calcAltitude(pressure);
  humidity = Sensor.getHumidity();

  // Set values for charting
  tempV.line = temp;
  tempV.maxi = 50;
  tempV.mini = -25;
  tempV.color = TFT_WHITE;

  pressV.line = pressure;
  pressV.maxi = 105000;
  pressV.mini = 95000;
  pressV.color = TFT_RED;

  altiV.line = altitude;
  altiV.maxi = 2000;
  altiV.mini = 0;
  altiV.color = TFT_GREEN;

  humidV.line = humidity;
  humidV.maxi = 100;
  humidV.mini = 0;
  humidV.color = TFT_BLUE;

  // Draw the chart on the LCD
  chart1(tempV, pressV, altiV, humidV, 0, 0, 320, 200, TFT_BLACK);

  // Print sensor values to serial monitor
  Serial.println(tempV.line);
  Serial.println(pressV.line);
  Serial.println(altiV.line);
  Serial.println(humidV.line);

  // Display sensor values on the LCD
  lcd.fillRect(0, 200, 300, 24, TFT_WHITE);
  lcd.setTextColor(TFT_BLACK);
  lcd.setCursor(0, 210);
  lcd.setFreeFont(FF1);
  lcd.print("T: ");
  lcd.print(temp);
  lcd.setCursor(100, 210);
  lcd.setTextColor(pressV.color);
  lcd.setFreeFont(FF1);
  lcd.print("P: ");
  lcd.print(pressure);
  lcd.setCursor(0, 222);
  lcd.setTextColor(altiV.color);
  lcd.setFreeFont(FF1);
  lcd.print("A: ");
  lcd.print(altitude);
  lcd.setCursor(100, 222);
  lcd.setTextColor(humidV.color);
  lcd.setFreeFont(FF1);
  lcd.print("H: ");
  lcd.print(humidity);

  time=millis()+1000;
}
}
