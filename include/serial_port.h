#ifndef SERIAL_PORT_H
#define SERIAL_PORT_H

#include <string>
#include <exception>

class AeroSerialPort
{
    private:
        std::string filename;
        int fd;
    public:
        AeroSerialPort(std::string dev_file);
        void writeString(std::string string);
        ~AeroSerialPort();
        class SerialPortException : public std::exception
        {
            private:
                std::string details;
            public:
            SerialPortException(std::string details) : details(details)
            {
            }
            virtual const char* what() const throw()
            {
                return details.c_str();
            }
            ~SerialPortException() throw()
            {}
        };
};

#endif
