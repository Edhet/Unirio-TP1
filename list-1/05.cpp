#include <stdio.h>

int main() {
    int byte_size;
    float transfer_speed, result;

    printf("\nWhat's the file size in bytes: \n");
    scanf("%d", &byte_size);
    printf("\nWhat's the file transfer speed in bytes per second: \n");
    scanf("%f", &transfer_speed);

    result = static_cast<float>(byte_size) / transfer_speed;
    printf("\n   Time until file transfer completion: %2.1fs\n", result);

    return 0;
}
