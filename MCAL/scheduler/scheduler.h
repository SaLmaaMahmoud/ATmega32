/*
 * scheduler.h
 *
 * Created: 08/08/2021 02:14:08 AM
 *  Author: Salma
 */ 


#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "BITMATH.h"
#include "STD_TYPES.h"

#include "TMR.h"
#include <avr/interrupt.h>
	
#define INTERRUPT_Timer_2_Overflow 5
	
/*************** PUBPLIC CONSTANTS ****************/
//The maximum number of tasks required at any one time
#define SCH_MAX_TASKS	(1)			
#define Error_port	PORT_A
/*************************************************/

/***************** ERROR CODES ******************/
#define ERROR_SCH_TOO_MANY_TASKS (1)
#define ERROR_SCH_CANNOT_DELETE_TASK (2)
#define RETURN_NORMAL 0
#define RETURN_ERROR 1
/*************************************************/
	
/* Total memory for task is 7-bytes */
typedef struct
{
	//pointer to the task (must be a 'void (void)' function)
	void (* ptask) (void) ;

	// Delay (ticks) until the function will (next) be run
	// - see SCH_Add_Task() for further details
	u8 delay ;

	// Interval (ticks) between subsequent runs.
	// - see SCH_Add_Task() for further details
	u8 priod ;

	// Incremented (by scheduler) when task is due to execute
	u16 RunMe ;
	} sTask ;

/************** PUBPLIC FUNCTIONS PROTOTYPES ***************/
/*****************Core scheduler functions******************/

/*Description : Prepares scheduler data structures and sets up 
				timer interrupts at required rate. Must call this 
				function before using the scheduler.
  Parameters  : none
  Return type : void */
void SCH_Init_T2 (void) ;

/*Description : Causes a task (function) to be executed at regular
				intervals or after a user-defined delay
  Parameters  : the name of the function (task) -> void (*pFunction)
				the delay before task is first executed -> const tWord DELAY
				the interval between repeated executions of the task -> const tWord PERIOD
  Return type : u16 */
u16 SCH_Add_Task( void (*pFunction) , const u8 DELAY , const u8 PERIOD) ;
	
/*Description : When a task (function) is due to run, SCH_Dispatch_Tasks() 
				will run it. This function must be called (repeatedly) 
				from the main loop.
  Parameters  : none
  Return type : void */
void SCH_Dispatch_Tasks(void) ;

/*Description : After all the tasks have been added, this function 
				is called to begin the scheduling process. The function
				achieves this by globally enabling interrupts.
  Parameters  : none
  Return type : void */
void SCH_Start(void) ;
	
/*Description : Delete Tasks from the array
  Parameters  : The task index -> const u16 Task_Index
  Return type : u16 */
u16 SCH_Delete_Task(const u16 Task_Index) ;
		
/*Description : Report the error codes
  Parameters  : none
  Return type : void */
void SCH_Report_Status(void) ;

	
#endif /* SCHEDULER_H_ */