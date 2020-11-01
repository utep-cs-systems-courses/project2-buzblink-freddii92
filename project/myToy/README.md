Project 2: Blinky-Buzzy Toy
===========================
# What the program does:

  This program will implement certain features to the MSP430
  Microcontroller. These features include making sounds, the LEDs flashing and
  the user of the buttons. When you connect the MSP430 to the computer, it
  will go into the idle state which nothing will happen. Once you click a
  button, it will start sounds and the LEDs will start turning on and off. The
  following buttons will perform the assigned tasks:
  	    S1. Will play the song Twinkle Twinkle Little Star. The LED lights
  will follow the rythm of the music.
       	    S2. Will dim both LEDs
	    S3. Will play the song Happy Birthday. The LED lights will follow
  the rythm of the music.
      	    S4. Will immitate a cop siren.

# How to compile:
  I have create a Makefile that will be easy to compile and clean the
  project. The instructions are as follows:
  	   make - Compile the entire project
	   make load - Compile and run the project on the MSP430
	   make clean - Clean all .o and .elf files
