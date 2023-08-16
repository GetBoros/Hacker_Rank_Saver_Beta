#include "Tools.h"

// AsSimple_Timer
AsSimple_Timer::~AsSimple_Timer()
{
    double hour, min, seconds;

    End = std::chrono::high_resolution_clock::now();
    Duration = End - Start;
    seconds = Duration.count();

    float ms = Duration.count() * 1000.0f;

    min = seconds / 60;
    hour = min / 60;

    seconds = (int)seconds % 60;
    min  = (int)min % 60;


    if (Is_Life_Time)
        std::cout << "Program life time: = (" << (int)hour << " Hours : " << min << " mins : " << seconds << " seconds)\n";
    else
        std::cout << "\t\t\t\t\t\t\t    ms: " << ms << std::endl;
}
//------------------------------------------------------------------------------------------------------------------
AsSimple_Timer::AsSimple_Timer()
: Is_Life_Time(false), Start(std::chrono::high_resolution_clock::now() ), Duration(0.0)
{

}
//------------------------------------------------------------------------------------------------------------------
AsSimple_Timer::AsSimple_Timer(bool is_life_time)
 : Is_Life_Time(is_life_time), Start(std::chrono::high_resolution_clock::now() ), Duration(0.0)
{

}
//------------------------------------------------------------------------------------------------------------------
double AsSimple_Timer::Get_Duration()
{
    return static_cast<double>(Duration.count() );
}
//------------------------------------------------------------------------------------------------------------------



// ASlasher
SYSTEMTIME ASlasher::Local_Time;
int ASlasher::Slasher_Counter = 0;
//------------------------------------------------------------------------------------------------------------------
ASlasher::~ASlasher()
{
    std::cout << AsTools::Slash_String << std::endl;
}
//------------------------------------------------------------------------------------------------------------------
ASlasher::ASlasher(const std::string &text_to_print)
: Text_To_Print(text_to_print)
{
    // read binary local time
    if (Slasher_Counter == 0)
    {
        Slasher_Counter++;
        std::ifstream data_bin_read("Data.bin", std::ios::binary);
        if (data_bin_read.is_open())
        {
            data_bin_read.read(reinterpret_cast<char*>(&Local_Time), sizeof(Local_Time) );
            data_bin_read.close();

            std::cout << AsTools::Slash_String << std::endl 
                << "Last Visits was: " << Local_Time.wDay
                << "." << Local_Time.wMonth
                << "." << Local_Time.wYear
                << " Time: " << Local_Time.wHour
                << ":" << Local_Time.wMinute
                << "\t" << Text_To_Print << std::endl;
        }
    }
    else
        std::cout << AsTools::Slash_String << std::endl << "\t\t\t\t\t" << Text_To_Print << std::endl;
}
//------------------------------------------------------------------------------------------------------------------




// AsTools
const std::string AsTools::Slash_String = "//------------------------------------------------------------------------------------";
//------------------------------------------------------------------------------------------------------------------
