#include <iostream>
#include <thread>

#include "serial_port.h"

int main()
{
    try
    {
        AeroSerialPort asp("/dev/ttyACM0");
        
        for (int i=1300; i>1200; i-=5)
        {
            char buf[100];

            sprintf(buf, "5123.45;%i;%i;%i;%i;", i, i, i, i);
            asp.writeString(std::string(buf));

            std::this_thread::sleep_for(std::chrono::milliseconds(250));

        }
        asp.writeString("4\r");
    }
    catch (AeroSerialPort::SerialPortException e)
    {
        std::cout << e.what() << std::endl;
    }

}
