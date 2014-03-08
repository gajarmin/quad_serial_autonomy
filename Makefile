
main: src/main.cpp Serial_Port
	g++ -std=c++11 -Iinclude -o ./main lib/serial_port.o src/main.cpp

Serial_Port: include/serial_port.h src/serial_port.cpp
	g++ -c -Iinclude -o lib/serial_port.o src/serial_port.cpp
