
__kernel void vector_add (__global int *A, __global int *B, __global int *C) {

    int i = get_global_id(0);

    C[i+1] = A[i];
    C[i] = A[i+1];

}



