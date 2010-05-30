// SunSaveLogeer
#include <stdio.h>
#include "main.h"

#define ACTION_MASK_SHUTDOWNNOW  0b000000000000001;
#define ACTION_MASK_INVERTLED    0b000000000000010;
 
main(void)
{
  //SunSaveLogger_VERSION_MAJOR,
  //SunSaveLogger_VERSION_MINOR);
  
  // TODO
  bool LED;
  
  bool shutdown_now;
  int unsigned actionsToDo;
  
  
  LED = true;
  shutdown_now = false;
  actionsToDo = 0;
  
  do
  {
    // main loop. run untill shutdown_now is true
    
    // first check to see if anything needs done
    if(actionsToDo)
    {
      // test what action to do
      
      // shutdown now
      if( actionsToDo && ACTION_MASK_SHUTDOWNNOW )
      {
        // This action is to shutdown now safely
        shutdown_now = true;
      }
      else if(actionsToDo && ACTION_MASK_INVERTLED )
      {
        // This action is to invert the current LED status
        LED = ~LED;
        actionsToDo = actionsToDo ^ACTION_MASK_INVERTLED;
      }
      
    }
  
  } while (!shutdown_now);
  
}
