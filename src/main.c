// SunSaveLogeer
#include <stdio.h>
#include "main.h"

#define TRUE  1
#define FALSE 0

#define ACTION_MASK_SHUTDOWNNOW  0b000000000000001
#define ACTION_MASK_LEDINVERT    0b000000000000010

int unsigned actionsToDo = 0;

// TODO
char LED = TRUE;

interupt_ledFlash()
{
  actionsToDo = actionsToDo && ACTION_MASK_LEDINVERT;
  
  // reset interupt
  //TODO
}

interupt_shutdown()
{
  // we want to finish what ever is in the queue in the main loop
  // and then shutdown
  
  // kill all interupts to make sure now new events come in 
  //TODO
  
  actionsToDo = actionsToDo && ACTION_MASK_SHUTDOWNNOW;
  
  // turn LED on to constant to let user know that it has been resived
  LED = TRUE;
}
 
main(void)
{
  //SunSaveLogger_VERSION_MAJOR
  //SunSaveLogger_VERSION_MINOR
  
  do
  {
    // main loop. run untill shutdown_now is true
    
    // first check to see if anything needs done
    if(actionsToDo)
    {
      // test what action to do
      
      if(actionsToDo && ACTION_MASK_LEDINVERT )
      {
        // This action is to invert the current LED status
        LED = ~LED;
        actionsToDo = actionsToDo ^ ACTION_MASK_LEDINVERT;
      }
      
    }
 
  // this is only true with a shutdown intended AND no actions in the queue 
  } while (actionsToDo != ACTION_MASK_SHUTDOWNNOW);
  
}
