#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
    printf("Unsigned char min: 0\nUnsigned char max: %d\nSigned char min: %d\nSigned char max: %d\nUnsigned int min: 0\nUnsigned int max: %lu\nSigned int min: %d\nSigned int max: %d\nUnsigned short min: 0\nUnsigned short max: %d\nSigned short min: %d\nSigned short max: %d\nUnsigned long min: 0\nUnsigned long max: %lu\nSigned long min: %ld\nSigned long max: %ld\nFloat min: %f\nFloat max: %f\nDouble min: %lf\nDouble max: %f\n", UCHAR_MAX, SCHAR_MIN, SCHAR_MAX, UINT_MAX, INT_MIN, INT_MAX, USHRT_MAX, SHRT_MIN, SHRT_MAX, ULONG_MAX, LONG_MIN, LONG_MAX, FLT_MIN, FLT_MAX, DBL_MIN, DBL_MAX);

    return 0;
}