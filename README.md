# BopIt
This is a BopIt(tm) remake. Using a Ps4 controller

Prerequisites:
Cygwin

Setup:
1. Unzip the folder into your home directory in cygwin. 
2. connect the PS4 Controller to your computer.
3. compile the BopIt.c file into an executable.
    a. use gcc to compile the file. Ex. gcc -o bopit BopIt.c
4. run the ds4rd file and find the id of the sony controller.
    a. Ex. Type: 054c 09cc
        I. replace the space with a colon Ex. 054c:09cc

Execution: 
run this command:
./ds4rd -d <device id> -D DS4_<BT/USB> -t -b -bt -bd | ./<filename>
  use BT or USB based on whether you connected the Ps4 controller to the computer through Bluetooth or USB.
  replace "<filename>" with the name use to compile the C code.

Help:
for more options and help with the ds4rd file
Run: ./ds4rd -h
