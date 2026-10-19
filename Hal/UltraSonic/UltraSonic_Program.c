/*
 * UltraSonic_Program.c
 *
 *  Created on: Oct 12, 2026
 *      Author: oa000
 */

static void UltraSonic_EdgeProssing()
{
	// 1- at Pos 1 will reset timer and change to falling

	//2- at pos 2 will read the ICR1 Value map to travel time and change to rising

	//3- After finish reset the flag
}

void UltraSonic_Init()
{
	//1- Config To DIO Direction
	//2- Init to the ICU Driver -> Call the call Back function(UltraSonic_edgeProssing) & call The ICU_Init
}



void UltraSonic_Trigger()
{
	//0-Reset The flag
	//1- Send the 1usec high Pulse on specific DIO pin and After the Make it Low
	//Note : Make Sure from UltraSonic Flag
}

//uint8_t UltraSonic_GetDistance(uint8_t *DistanceValue)
//{
//	//Make Sure The Processing Finished
//	// Calc the Distance
//}





