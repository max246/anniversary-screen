# anniversary-screen

Simple anniversary screen using ESP ( Adafruit HUZZAH ) and a TFT screen ( Adafruit 2.4" TFT LCD with Touchscreen Breakout w/MicroSD Socket - ILI9341 ).

Adafruit has a simple project which uses a TFT FeatherWing - 2.4", due to being discontinuted and my time frame was a bit tight I had to switch over to a similar version which was dafruit 2.4" TFT. Now Adafruit has released a V2 which could be used but potentially the code needs to be amended to match the right pins and use the proper touch input.

The idea is to display 3 cards on a small screen device which are: Current Time, Time since Met, Time since Official. 

The program autoamtically broadcast an AP to allow you to configure your own WIFI and then once it is connected to the internet, it pulls the update to date time from a NTP server.

## Images

![alt text](https://github.com/max246/anniversary-screen/raw/main/static/time.jpg "Time scren")
![alt text](https://github.com/max246/anniversary-screen/raw/main/static/met.jpg "Met screen")
![alt text](https://github.com/max246/anniversary-screen/raw/main/static/together.jpg "Togheter screen")



## Links


[Original project](https://learn.adafruit.com/wifi-weather-station-with-tft-display)

[Adafruit 2.4" TFT](https://www.adafruit.com/product/3315)

[Adafruit Huzzah](https://www.adafruit.com/product/2821)

[Battery](https://www.adafruit.com/product/2011)

[Switch](https://www.adafruit.com/product/805)
