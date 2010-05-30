# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "main.h.in"
  "main.h"
  )
 
# add the executable
add_executable(SunSaveLogger main.c)
