#include <stdio.h>
#include <stdlib.h>

#include <CL\cl.h>


int main()
{
	unsigned int i, j;

	cl_platform_id platforms[32];

	cl_uint num_platforms;

	char vendor[1024];

	cl_device_id devices[32];

	cl_uint num_devices;

	char deviceName[1024];

	cl_uint numberOfCores;
	cl_long amountOfMemory;
	cl_uint clockFreq;
	cl_ulong maxAlocatableMem;
	cl_ulong localMem;
	cl_bool available;

	char device_version[1024];

	clGetPlatformIDs(32, platforms, &num_platforms);
	printf("\nNumber of platforms:\t%u\n\n", num_platforms);


	for (i = 0; i < num_platforms; i++)

	{

		printf("Platform:\t\t%u\n\n", i);

		clGetPlatformInfo(platforms[i], CL_PLATFORM_VENDOR, sizeof(vendor), vendor, NULL);

		printf("\tPlatform Vendor:\t%s\n", vendor);

		clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, sizeof(devices), devices, &num_devices);

		printf("\tNumber of devices:\t%u\n\n", num_devices);

		for (j = 0; j < num_devices; j++)
		{

			clGetDeviceInfo(devices[j], CL_DEVICE_NAME, sizeof(deviceName), deviceName, NULL);
			clGetDeviceInfo(devices[j], CL_DEVICE_VENDOR, sizeof(vendor), vendor, NULL);
			clGetDeviceInfo(devices[j], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(numberOfCores), &numberOfCores, NULL);
			clGetDeviceInfo(devices[j], CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(amountOfMemory), &amountOfMemory, NULL);
			clGetDeviceInfo(devices[j], CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(clockFreq), &clockFreq, NULL);
			clGetDeviceInfo(devices[j], CL_DEVICE_MAX_MEM_ALLOC_SIZE, sizeof(maxAlocatableMem), &maxAlocatableMem, NULL);
			clGetDeviceInfo(devices[j], CL_DEVICE_LOCAL_MEM_SIZE, sizeof(localMem), &localMem, NULL);
			clGetDeviceInfo(devices[j], CL_DEVICE_AVAILABLE, sizeof(available), &available, NULL);
			clGetDeviceInfo(devices[j], CL_DEVICE_VERSION, sizeof(device_version), device_version, NULL);
			printf("\tDevice: %u\n", j);

			printf("\t\tName:\t\t\t\t%s\n", deviceName);

			printf("\t\tVendor:\t\t\t\t%s\n", vendor);

			printf("\t\tAvailable:\t\t\t%s\n", available ? "Yes" : "No");

			printf("\t\tCompute Units:\t\t\t%u\n", numberOfCores);

			printf("\t\tClock Frequency:\t\t%u mHz\n", clockFreq);

			printf("\t\tGlobal Memory:\t\t\t%0.00f mb\n", (double)amountOfMemory / 1048576);

			printf("\t\tMax Allocateable Memory:\t%0.00f mb\n", (double)maxAlocatableMem / 1048576);

			printf("\t\tLocal Memory:\t\t\t%u kb\n\n", (unsigned int)localMem);

			printf("\t\tDevice Version:\t\t\t%s \n\n", device_version);

		}

	}

	return 0;

}