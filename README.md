# ROS-STM32duino_rosserial

## Environments Setup
I use different enviroment for run rosserial and Upload.
>  Run rosserial : Ubuntu 18.04 (melodic)\
>  Upload rosserial aruduino program : Windows

### rosserial [1]
Ubuntu 18.04
> 1. Install Arudiuno IDE
> https://websiteforstudents.com/how-to-install-arduino-ide-on-ubuntu-18-04-16-04/ \
> **or**\
> sudo apt-get install arduino
> 2. Install rosserial 

    sudo apt-get install ros-melodic-rosserial-arduino
    sudo apt-get install ros-melodic-rosserial
    cd ~/Arduino/libraries     //     "cd <arduino IDE path>/libraries"
    **Terminal 1**
    roscore
    **Terminal 2**
    rosrun rosserial_arduino make_libraries.py .
    
  You can see the **ros_lib** folder in your **/Arduino/libraries**
    
    
### STM32duino Upload [2]
Windows 10
> 1. Arduino IDE - Setup - Additional Boards Managers URLs\
>    https://raw.githubusercontent.com/stm32duino/BoardManagerFiles/master/STM32/package_stm_index.json
> 2. Tools - Boards Managers\
>    Install **"STM32 Cores"** by STMicroelectronics
> 3. Download ros_lib \
>   Steckch - Include libaries - Include .Zip libraries and include **ros_lib** folder\
>   *In my case, I install rosserial in Ubuntu 18.04 and copy the ros_lib folder to Windows arduino (Check rosserial)*

## STM32duino ros_lib Upload
If you upload the example of ros_lib and just run thw nodes, you face the *"Sync Error"*
Basically, the rosserial didn't support STM32duino USB communication (just Hardware Serial)
So, you need to add the STM32duino USB communication code in ros_lib







## References
[1] http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup
[2] https://github.com/stm32duino
