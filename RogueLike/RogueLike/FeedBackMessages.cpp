#include "FeedBackMessages.h"

//Constructor
FeedBackMessages::FeedBackMessages()
{
	//Intialising Fields
	Message = "";
	MessageTicks = 0;

}//End Constructor


 //////////////////////////////////////////////////////////////////////////
 // This method is used to erase the message after the duration of the message
 // in message ticks has reached 0
 //////////////////////////////////////////////////////////////////////////
void FeedBackMessages::CountDownMessageTimeout()
{
	if (MessageTicks > 0)
	{
		MessageTicks--;
	}
	else
	{
		Message = "";
	}
}//End CountDownMessageTimeout
