<p align="left">
  <img 
    src="https://github.com/mariusstoica21/rtos_esp32/blob/main/Images/header.png"
  >
</p>


# RTOS and ESP32

A web application that allows the user to read data from sensors (gas sensor, motion sensor) and write data to the ESP32 builtin led, using a multithreaded program designed using Arduino and FreeRTOS.

There are five threads: one for the Internet connection, one for the builtin led, one for gas sensor, one for motion sensor and one for the LCD display.

The connection thread is running permanently. When a button is pressed, for example the 'ON' button, the led thread runs, turns the LED on, and suspends itself. The LCD display also runs in order to show the message 'ON', and then suspends itself.

## Summary
✅ G.U.I. 

❌ Ease of installation

✅ Additional hardware needed

✅ Video available

❌ Documentation


## Project description

### Folder structure

📁 Images : contains the images of the project.

📄 [WiFi_ESP32.ino](https://github.com/mariusstoica21/rtos_esp32/blob/main/WiFi_ESP32.ino): contains the main program.


### Technologies

<table>
  <tr>
    <th>🔨 Tools/Framework</th>
    <th>📘 Language</th>
    <th>📃 Usage </th>
    <th>📚 Files</th>
    <th> ℹ Details  </th>
  </tr>
  <tr>
    <td>Arduino</td>
    <td>C++</td>
    <td>Program that generates the webpage and reads/writes information from/to peripherals.</td>
    <td>WiFi_ESP32.ino</td>
    <td>
       <ul>
        <li>Multithreaded program, using FreeRTOS that reads/writes data from/to components.</li>
        <li>There are five threads: LED thread, LCD thread, GAS sensor thread, PIR sensor thread, Internet Connection thread.
         </li>
        <li>The Internet Connection thread runs permanently, while the other threads are suspended.</li>
        <li>The threads resume depending on the button pressed in the GUI.</li>
      </ul>
   </td>
  </tr>
</table>

## Additional resources

➕ NodeMCU ESP32

➕ Gas sensor

➕ PIR sensor

➕ LCD Display

## Installation

- Download the code.
- Connect the hardware components
- Run Arduino IDE.
- Configure/modify the WI-FI hostname and password.
- Connect the ESP32 module and compile the code.
- Check for the IP address in the Serial Monitor.
- Open a blank webpage and write the address from the Serial Monitor (for example 192.168.1.4).

## Tutorial

### Turn LED OFF

**Website point of view**: the message 'OFF' will be shown on the top of the page, on the "LCD display", and the circuit of the ESP32 and a led will be shown on the bottom of the page.

<p align="center">
  <img 
    src="https://github.com/mariusstoica21/rtos_esp32/blob/main/Images/1.JPG"
  >
</p>

**Physical point of view**: the ESP32 builtin led will be turned off, and on the LCD display, the message "OFF" will be displayed.

<p align="center">
  <img 
    src="https://github.com/mariusstoica21/rtos_esp32/blob/main/Images/6p.JPG"
  >
</p>

<p align="center">
  <img 
    src="https://github.com/mariusstoica21/rtos_esp32/blob/main/Images/5p.JPG"
  >
</p>

### Turn LED ON

**Website point of view**: the message 'ON' will be shown on the top of the page, on the "LCD display", and the circuit of the ESP32 and a led will be shown on the bottom of the page.

<p align="center">
  <img 
    src="https://github.com/mariusstoica21/rtos_esp32/blob/main/Images/2.JPG"
  >
</p>

**Physical point of view**: the ESP32 builtin led will be turned on, and on the LCD display, the message "ON" will be displayed.

<p align="center">
  <img 
    src="https://github.com/mariusstoica21/rtos_esp32/blob/main/Images/8p.JPG"
  >
</p>

<p align="center">
  <img 
    src="https://github.com/mariusstoica21/rtos_esp32/blob/main/Images/7p.JPG"
  >
</p>

### Check GAS sensor

**Website point of view**: the message 'No gas detected' will be shown on the top of the page, on the "LCD display", if the value read from the analog pin is below a given threshold; if the module senses gas, the message "GAS DETECTED!!!" will be shown; the circuit of the ESP32 and a MQ sensor will be shown on the bottom of the page.

<p align="center">
  <img 
    src="https://github.com/mariusstoica21/rtos_esp32/blob/main/Images/3.JPG"
  >
</p>

<p align="center">
  <img 
    src="https://github.com/mariusstoica21/rtos_esp32/blob/main/Images/4.JPG"
  >
</p>

**Physical point of view**: the LCD display will show either "No gas detected" or "GAS DETECTED!!!"

<p align="center">
  <img 
    src="https://github.com/mariusstoica21/rtos_esp32/blob/main/Images/1p.JPG"
  >
</p>

<p align="center">
  <img 
    src="https://github.com/mariusstoica21/rtos_esp32/blob/main/Images/2p.JPG"
  >
</p>

### Check PIR sensor

**Website point of view**: the message 'No motion' will be shown on the top of the page, on the "LCD display", if the PIR sensor does not detect any movement; if the module senses motion, the message "MOTION DETECTED!!!" will be shown; the circuit of the ESP32 and a PIR sensor will be shown on the bottom of the page.

<p align="center">
  <img 
    src="https://github.com/mariusstoica21/rtos_esp32/blob/main/Images/5.JPG"
  >
</p>

<p align="center">
  <img 
    src="https://github.com/mariusstoica21/rtos_esp32/blob/main/Images/6.JPG"
  >
</p>

**Physical point of view**: the LCD display will show either "No motion" or "MOTION DETECTED!!!"

<p align="center">
  <img 
    src="https://github.com/mariusstoica21/rtos_esp32/blob/main/Images/4p.JPG"
  >
</p>

<p align="center">
  <img 
    src="https://github.com/mariusstoica21/rtos_esp32/blob/main/Images/3p.JPG"
  >
</p>



