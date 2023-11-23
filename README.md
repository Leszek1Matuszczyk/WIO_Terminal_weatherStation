# Arduino Weather Station with WIO Terminal

This Arduino project utilizes the WIO Terminal, featuring a built-in LCD screen and a BME280 sensor, to create a visually appealing weather station. The weather station provides real-time data on temperature, pressure, altitude, and humidity, presenting a comprehensive overview of the current weather conditions.

## Hardware Requirements

- **WIO Terminal:** A compact and powerful development board with a built-in LCD screen and various built-in sensors.
- **BME280 Sensor:** A sensor measuring temperature, pressure, and humidity.

## Project Features

- **Real-time Weather Data:** The WIO Terminal collects data from the BME280 sensor to provide accurate and up-to-date information on the current weather conditions.

- **Visual Representation:** The project visualizes the weather data through a line chart displayed on the WIO Terminal's LCD screen. Each line represents a different weather parameter, allowing for an intuitive understanding of the weather state.

- **Temperature, Pressure, Altitude, and Humidity:** The weather station monitors and displays essential weather parameters, including temperature, atmospheric pressure, altitude, and humidity.

## Setup Instructions

1. **Connect the BME280 Sensor:** Ensure that the BME280 sensor is properly connected to the WIO Terminal.

2. **Add the Free_Fonts Library:**
    - Download the Free_Fonts library from [GitHub](https://github.com/lewisxhe/Free_Fonts).
    - Copy the entire `Free_Fonts` folder to your Arduino project folder.

3. **Upload the Arduino Code:** Upload the provided Arduino code to the WIO Terminal using the Arduino IDE.

4. **Monitor the LCD Screen:** Once the code is uploaded, the WIO Terminal's LCD screen will start displaying the weather information in a visually appealing chart.

## Customization

Feel free to customize the project to suit your preferences or extend its functionality. You can modify the visual representation, add more sensors, or integrate additional features based on your requirements.

## Dependencies

- **TFT_eSPI Library:** This project uses the TFT_eSPI library to interface with the WIO Terminal's LCD screen.
- **Seeed_BME280 Library:** The Seeed_BME280 library is essential for interacting with the BME280 sensor.
- **Free_Fonts Library:** The Free_Fonts library provides additional font options for text display.

## Acknowledgments

This project is made possible by the contributions of the Arduino community and the creators of the WIO Terminal, BME280 sensor, and Free_Fonts libraries.

## License

This project is open-source and available under the [MIT License](LICENSE). Feel free to use, modify, and share the code according to the terms of the license.

---

Enjoy your Arduino Weather Station with WIO Terminal! If you encounter any issues or have suggestions for improvements, please feel free to contribute or reach out for assistance.
