# Overview
The goal of this project is to create a smart alarm clock / heads-up display using a Raspberry Pi, a graphical display, a speaker, pushbuttons, and network collection. 

Ideally, it will be capable of connecting to the internet to obtain weather data and sync its clock, then convey this information to the user on the display. The user will be able to input an alarm time using a pushbutton array, and the speaker will play a sound when the time comes. It may even play soothing sounds for the user at their bedtime.

My motivation behind this project is that I wanted to create something that is modular and uses protocols and hardware that interest me. Network connection, graphical displays, and audio in particular seem like they would be exciting to implement. Additionally--since the project is modular--if I get stuck on one piece of hardware or specific aspect of the project I can use a fallback plan or save it as future work without inhibiting the rest of the project.


<img src="https://github.com/user-attachments/assets/f1155fc0-6e41-467f-9f03-85a659c20d35" width="800" alt="Final Project Diagram (1)">

System block diagram


# Target Build System
This project will use buildroot as the target build system.

# Hardware Platform
For this project I plan to use a Raspberry Pi 4B, which is included in the list of [supported Hardware](https://github.com/cu-ecen-aeld/aesd-assignments/wiki/Supported-Hardware-Platforms). I will use one board that is to be sourced myself. 

I plan to use the [following 5-inch display](https://www.amazon.com/dp/B0CXTFN8K9?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1), which is designed specifically for the Raspberry Pi. The display is likely the most important extra hardware component, so as a fallback if I cannot get this display to work, I will use a [simpler SPI display](https://www.adafruit.com/product/618).

Next, I have the [following USB speaker](https://www.amazon.com/dp/B075M7FHM1?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1) which I intend to implement for audio feedback. If I cannot get the speaker to work, a simple [piezo element](https://www.adafruit.com/product/160) will be the fallback.

Lastly, I plan to use [simple pushbuttons](https://www.adafruit.com/product/367) to accept user input using GPIO. As a stretch goal, the pushbuttons can be replaced by the display's capacitive touchscreen, though that is likely out of the scope of this iteration of the project.


# Open Source Projects Used
I intend to use the Buildroot package [X11](https://github.com/buildroot/buildroot/tree/2016.05/package/x11r7) for the display. A GUI framework such as [GTK](https://github.com/buildroot/buildroot/tree/master/package/libgtk3) may also be useful.

To handle audio, [ALSA](https://github.com/alsa-project/alsa-utils) may be useful for talking to the speaker, and [mpg123](https://www.mpg123.de/) for managing mp3 files.

Concerning network connections, I plan to use the [OpenWeather](https://openweathermap.org/appid) API to obtain weather data, which also includes timestamps that may be useful for synchronizing the clock. Otherwise, NTP will serve that purpose. 

# Previously Discussed Content

I will use the base Buildroot project from previous course content. I don't explicitly intend to use the aesdsocket or aesdchar components developed in class, but it is possible I will find them useful to use partially.

# New Content
- Graphical display using X11 and potential GUI framework
- UAC audio using ALSA
- NTP and public API access
- Sysfs GPIO control   

# Shared Material
I will use the [Raspberry Pi Hardware Hints](https://github.com/cu-ecen-aeld/buildroot-assignments-base/wiki/Raspberry-Pi-Hardware-Hints) section of the class wiki to help with USB configuration and potentially SPI if I use the fallback display plan.

# Source Code Organization

Buildroot Repository will be hosted at [https://github.com/cu-ecen-aeld/final-project-erpe9416]

ApplicationX code will be hosted in in a repository at [https://github.com/cu-ecen-aeld/assignments-3-and-later-erpe9416]

## Team project members:

Eric Percin

# Schedule Page
[https://github.com/users/erpe9416/projects/1/views/1]
