
#include <iostream>
#include <iomanip>

class Clock
{
public:
    int hour;
    int minute;
    int second;

    Clock(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s)
    {

    }

    bool operator == (const Clock & other) const
    {
        return (hour == other.hour && minute == other.minute && second == other.second);
    }

    bool operator<(const Clock& other) const
    {
        if (hour != other.hour)
        {
            return hour < other.hour;
        }

        if (minute != other.minute)
        {
            return minute < other.minute;
        }

        if (second != other.second)
        {
            return second < other.second;
        }

        return false;
    }

    Clock& operator++()
    {
        second++;

        if (second >= 60)
        {
            second = 0;
           
            minute++;
            
            if (minute >= 60) 
            {
                
                minute = 0;
                
                hour++;
                
                if (hour >= 24)
                {
                    hour = 0;
                }
            }
        }
        return *this;
    }
};


std::ostream& operator<<(std::ostream& os, const Clock& c)
{
    os << std::setw(2) << std::setfill('0') << c.hour << ':'
        << std::setw(2) << std::setfill('0') << c.minute << ':'
        << std::setw(2) << std::setfill('0') << c.second;
    return os;
}


int main()
{
    Clock midnight{ 0, 0, 0 };
    Clock threePM{ 15, 0, 0 };
    Clock almostMidnight{ 23, 59, 59 };

    std::cout << "Initial times:\n";
    std::cout << "midnight:      " << midnight << "\n";
    std::cout << "threePM:       " << threePM << "\n";
    std::cout << "almostMidnight:" << almostMidnight << "\n\n";

    // Test == operator
    if (midnight == threePM)
        std::cout << "midnight and threePM are the same time\n";
    else
        std::cout << "midnight and threePM are NOT the same time\n";

    // Test < operator
    if (midnight < threePM)
        std::cout << "midnight is earlier than threePM\n";
    else
        std::cout << "midnight is NOT earlier than threePM\n";

    std::cout << "\n--- Test pre-increment on almostMidnight (23:59:59) ---\n";
    ++almostMidnight;
    std::cout << "After ++ : " << almostMidnight << "\n";

    std::cout << "\n--- Test another increment ---\n";
    Clock testTime{ 12, 30, 59 };
    std::cout << "Before ++: " << testTime << "\n";
    ++testTime;
    std::cout << "After ++ : " << testTime << "\n";

    return 0;
}
