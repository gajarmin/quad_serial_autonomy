#include <stdio.h>

struct sensorValues
{
	struct{ 
	
		int x;
		int y;
		int z;
	} gyroscope;

	struct 
	{
		int x;
		int y;
		int z;

	}accelerometer;

	struct 
	{
		int x;
		int y;
		int z;
	}magnetometer;
};

sensorValues* dataParsing(char* data,sensorValues* retVal)
{
	

	sscanf(data,"%d,%d,%d,%d,%d,%d,%d,%d,%d", retVal->gyroscope.x,retVal->gyroscope.y,retVal->gyroscope.z,
		retVal->accelerometer.x,retVal->accelerometer.y,retVal->accelerometer.z,retVal->magnetometer.x,
		retVal->magnetometer.y,retVal->magnetometer.z);

	return retVal;
}