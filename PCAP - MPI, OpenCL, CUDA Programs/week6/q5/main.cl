__kernel void ntimes(__global char *A, __global char *B, __global int *N) {
    int i = get_global_id(0);
    int j = 0;
    for(j=0;j<*N;j++){
        B[j*(*N)+i] = A[i];
    }
}

