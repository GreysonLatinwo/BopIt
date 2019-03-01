# BopIt
This is a BopIt(tm) remake. Using a Ps4 controller

Prerequisites:
1. Cygwin

Setup:
1. Unzip the folder into your home directory in cygwin. 
2. Connect the PS4 Controller to your computer.
3. Compile the BopIt.c file into an executable. 
4. Use gcc to compile the file. Ex. gcc -o bopit BopIt.c
5. Run the ds4rd file and find the id of the sony controller. Ex. Type: 054c 09cc. 
6. Replace the space with a colon Ex. 054c:09cc

Execution: 
run this command.
1. ./ds4rd -d <device id> -D DS4_<BT/USB> -t -b -bt -bd | ./(filename)
2. use BT or USB based on whether you connected the Ps4 controller to the computer through Bluetooth or USB.
3. replace (filename) with the name use to compile the C code.

Help:
1. for more options and help with the ds4rd file
2. Run: ./ds4rd -h
