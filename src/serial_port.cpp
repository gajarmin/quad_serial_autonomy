#include "serial_port.h"

#include <unistd.h>
#include <fcntl.h>

AeroSerialPort::AeroSerialPort(std::string dev_file)
{
    this->filename = dev_file;

    this->fd = open(this->filename.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);

    if (this -> fd == -1)
    {
        throw SerialPortException(std::string("Couldn't open device file ") + this->filename);
    }
    else
        fcntl(fd, F_SETFL, 0);
}

void AeroSerialPort::writeString(std::string str)
{
    int n = write(this->fd, str.c_str(), str.size());
    if (n < 0)
    {
        throw SerialPortException(std::string("Write of string") + str + std::string("failed!"));
    }
}

AeroSerialPort::~AeroSerialPort()
{
    close(fd);
}
