#include <iostream>
#include <cmath>

int main()
{
    int distance /*in mmeters*/; std::cin >> distance;
    long long fare = 0;

    if (distance <= 1000)
    {
        fare = 5000;
    }
    else if (distance <= 30000)
    {
        fare = 5000; // First KM
        double remaining_meters = distance - 1000; // omit first KM
        int blocks = ceil(remaining_meters / 200.0); // convert into 200m blocks
        fare += blocks * 1000;
        /*
            Dividing by 200 converts the distance in meters into
            the number of 200m blocks. Then multiply by 1000VND
            to get the cost.
        */
    }
    else
    {
        // up to 30 km
        fare = 5000;
        double remaining_meters = 30000 - 1000;
        int blocks = ceil(remaining_meters / 200.0);
        fare += blocks * 1000;

        // beyond 30 km
        double extra_km = distance - 30000;
        fare += ceil(extra_km) * 3000;
    }

    std::cout << "Total fare: " << fare << "vnd" << std::endl;

    return 0;
}