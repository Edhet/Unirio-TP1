#include <stdio.h>
#include <algorithm>

struct TimeStamp {
    int hours, minutes, seconds;

    TimeStamp operator - (TimeStamp const rhs) {
    TimeStamp result;

    result.hours = this->hours - rhs.hours;
    result.minutes = this->minutes - rhs.minutes;
    result.seconds = this->seconds - rhs.seconds;

    return result;
    }

    TimeStamp clamp_timestamp() {
        TimeStamp result;
        
        result.hours = std::clamp(this->hours, 0, 24);
        result.minutes = std::clamp(this->minutes, 0, 60);
        result.seconds = std::clamp(this->seconds, 0, 60);

        return result;
    }

    void print_timestamp() {
        printf("\n %d:%d:%d \n", this->hours, this->minutes, this->seconds);
    }
};

int main() {
    TimeStamp first, second, diference;

    printf("\nInput hour for the first timestamp: \n");
    scanf("%d", &first.hours);
    printf("\nInput minutes for the first timestamp: \n");
    scanf("%d", &first.minutes);
    printf("\nInput seconds for the first timestamp: \n");
    scanf("%d", &first.seconds);

    second.hours = first.hours + 1;
    second.minutes = first.minutes + 1;
    second.seconds = first.seconds + 1;

    first = first.clamp_timestamp();
    second = second.clamp_timestamp();

    diference = second - first;
    printf("\nThe diference between the two timestamps is: ");
    diference.print_timestamp();

    return 0;
}