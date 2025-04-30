# Smart Alarm Clock and HUD Overview

![image](https://github.com/user-attachments/assets/fa609385-17ea-47be-a75f-6d02cf9a4be1)


The goal of this project was to create a smart alarm clock / heads-up display using a Raspberry Pi, a graphical display, a speaker, pushbuttons, and network collection. 

The Smart Alarm Clock and HUD connects to the internet to obtain weather data and sync its clock, then conveys this information to the user on a graphical display. The user is able to input an alarm time using two pushbuttons, and the speaker plays an alarm sound when the time comes. 

My motivation behind this project was that I wanted to create something that is modular and uses protocols and hardware that interest me. Network connection, graphical displays, and audio in particular seemed like they would be exciting to implement. Additionally--since the project was modular--if I got stuck on one piece of hardware or specific aspect of the project I could use a fallback plan or save it as future work without inhibiting the rest of the project.

<img src="https://github.com/user-attachments/assets/f1155fc0-6e41-467f-9f03-85a659c20d35" width="800" alt="Final Project Diagram (1)">

System block diagram

# Target Build System
This project will use buildroot as the target build system.

# Hardware Platform
For this project I used a Raspberry Pi 4B, which is included in the list of [supported Hardware](https://github.com/cu-ecen-aeld/aesd-assignments/wiki/Supported-Hardware-Platforms). I used one board that is to be sourced myself. 

I used the [following 5-inch display](https://www.amazon.com/dp/B0CXTFN8K9?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1), which is designed specifically for the Raspberry Pi.

I used the [following USB speaker](https://www.amazon.com/dp/B075M7FHM1?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1) for audio playback.

And I used [simple pushbuttons](https://www.adafruit.com/product/367) to accept user input using GPIO.

# Open Source Projects Used

I used the following open source projects and Buildroot packages:

- [LVGL](https://docs.lvgl.io/master/index.html) to simulate and run the GUI
- [dhcpcd](https://github.com/buildroot/buildroot/tree/master/package/dhcpcd) or managing network configuration via DHCP
- [wpa_supplicant](https://github.com/buildroot/buildroot/tree/master/package/wpa_supplicant) for WPA/WPA2 authentication
- [ntp](https://github.com/rancher/buildroot/tree/master/package/ntp) for synchronizing the system clock with internet time servers
- [libgpiod](https://github.com/buildroot/buildroot/tree/master/package/libgpiod) for accessing and controlling GPIO pins from user space
- [ALSA](https://github.com/alsa-project/alsa-utils) for managing audio playback 
- [mpg123](https://www.mpg123.de/) for playing MP3 audio files
- [OpenWeather](https://openweathermap.org/appid) as an API to obtain weather data

# Previously Discussed Content

I used the base Buildroot project from previous course content. I didd't explicitly use the aesdsocket or aesdchar components developed in class, but leveraged their structure in creating my own package. 

# New Content
- Graphical display
- UAC audio using ALSA
- NTP and public API access
- GPIO control   

# Shared Material
I used the [Raspberry Pi Hardware Hints](https://github.com/cu-ecen-aeld/buildroot-assignments-base/wiki/Raspberry-Pi-Hardware-Hints) section of the class wiki.

# Source Code Organization

[Buildroot Repository](https://github.com/cu-ecen-aeld/final-project-erpe9416)

[Application code](https://github.com/erpe9416/final-project-assignment-erpe9416)

## Team project members:

Eric Percin

# Schedule Page
[Schedule Page](https://github.com/users/erpe9416/projects/1/views/1)
