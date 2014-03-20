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

struct sensorValues* dataParsing(char* data,struct sensorValues* retVal)
{
	

	sscanf(data,"%d,%d,%d,%d,%d,%d,%d,%d,%d", &(retVal->gyroscope.x),&(retVal->gyroscope.y),&(retVal->gyroscope.z),
		&(retVal->accelerometer.x),&(retVal->accelerometer.y),&(retVal->accelerometer.z),&(retVal->magnetometer.x),
		&(retVal->magnetometer.y),&(retVal->magnetometer.z));

	return retVal;
}

int main()
{
	char* example="1,2,3,4,5,6,7,8,9";

	struct sensorValues YAY;

	dataParsing(example, &YAY);

	return 0;
}