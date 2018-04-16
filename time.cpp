#include <iostream>
#include <sstream>
#include <ctime>
#include <sys/time.h>
#include <iomanip>

using namespace std;
int main() {
    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char* dt = ctime(&now);

    cout << "The local date and time is: " << dt << endl;

    // convert now to tm struct for UTC
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "The UTC date and time is:"<< dt << endl;

    // Another method
    timeval currentTime;
    gettimeofday(&currentTime, NULL);
    std::ostringstream dateKafka;
    dateKafka << currentTime.tv_sec << setfill('0') << setw(3) << (currentTime.tv_usec / 1000);
    cout << "Current time with gettimeofday: " << dateKafka.str() << endl;
    return 0;
}