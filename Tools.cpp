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
    :start(std::chrono::high_resolution_clock::now() ), duration(0.0)
{
}
//------------------------------------------------------------------------------------------------------------------




// ASlasher
//------------------------------------------------------------------------------------------------------------------
ASlasher::~ASlasher()
{
    std::cout << AsTools::Slash_String << std::endl;
}
//------------------------------------------------------------------------------------------------------------------
ASlasher::ASlasher(const std::string &text_to_print)
    : Text_To_Print(text_to_print)
{
    std::cout << AsTools::Slash_String << std::endl << "\t\t\t\t" << Text_To_Print << std::endl;

}
//------------------------------------------------------------------------------------------------------------------




// AsTools
const std::string AsTools::Slash_String = "//-------------------------------------------------------------------------";
//------------------------------------------------------------------------------------------------------------------
