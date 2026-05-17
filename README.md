# **Multimedia**

## How to build
Copy the project using git: `git clone https://github.com/DyzeeX/multimedia.git`.  

Download [cmake](https://github.com/Kitware/CMake).  

Install *libmagic* `sudo apt install libmagic-dev` (for my example Ubuntu/Debian)  

Go to the project directory.  
`cd multimedia`

Create a build folder and move to it.  
`mkdir build && cd build`

Configure the project.  
`cmake ..`

Compiling.  
`cmake --build .`

Run the programm.  
`./bin/multimedia`

## Input format
Program will request you to enter string - the path to the directory:  
`Please, enter the full directory path:`  
And integer - reset time in seconds:  
`Please, enter the repeat time in seconds:`

After this programm will run as daemon process. To finish execute, write in terminal:  
`pkill multimedia`
