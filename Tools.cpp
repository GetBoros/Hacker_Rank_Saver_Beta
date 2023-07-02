#include "Tools.h"

// AsSimple_Timer
AsSimple_Timer::~AsSimple_Timer()
{
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Duration = (" << duration.count() << " Seconds!!!)" << std::endl;
}
//------------------------------------------------------------------------------------------------------------------
AsSimple_Timer::AsSimple_Timer()
: start(std::chrono::high_resolution_clock::now() ), duration(0.0)
{

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
