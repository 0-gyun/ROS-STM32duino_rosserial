# ROS-STM32duino_rosserial

## Environments Setup
I use different enviroment for run rosserial and Upload.
> Run rosserial : Ubuntu 18.04 (melodic)
> Upload rosserial aruduino program : Windows

### rosserial [1]
Ubuntu 18.04
> 1. Install Arudiuno IDE
> https://websiteforstudents.com/how-to-install-arduino-ide-on-ubuntu-18-04-16-04/
> or
> sudo apt-get install arduino
> 2. Install rosserial 
    sudo apt-get install ros-melodic-rosserial-arduino.\
    sudo apt-get install ros-melodic-rosserial.\
    cd ~/Arduino/libraries // cd <arduino IDE path>/libraries.\
    **Terminal 1**.\
    roscore.\
    **Terminal 2**.\
    rosrun rosserial_arduino make_libraries.py ..\
    
    
### STM32duino Upload [2]
Windows 10
> 1. Arduino IDE - Setup - Additional Boards Managers URLs
> https://raw.githubusercontent.com/stm32duino/BoardManagerFiles/master/STM32/package_stm_index.json
> 2. Tools - Boards Managers
> Install **"STM32 Cores"** by STMicroelectronics
> 3. ros_lib
>> Downlaod ros_lib
>> Steckch - Include libaries - Include .Zip libraries and include **ros_lib** folder
>> in my case, I install rosserial in Ubuntu 18.04 and copy the ros_lib folder to Windows arduino (Check install rosserial)


[1] https://github.com/stm32duino
