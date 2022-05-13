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
    <td>C</td>
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


