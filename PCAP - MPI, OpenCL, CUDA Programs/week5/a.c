#include <stdlib.h>
#include <stdio.h>
#include <CL/cl.h>

int main() {
    cl_device_id device_id;
    cl_uint num_devices;

    cl_int id = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &device_id, &num_devices);

    return 0;
}
