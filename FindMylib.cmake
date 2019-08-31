# Find the MYLIB includes and library
#
# MYLIB is a just very simple library for square root and cube calculation.

# MYLIB_INCLUDE_DIR - where to find square.h and cube.h
# MYLIB_LIBRARIES   - List of fully qualified libraries to link against.
# MYLIB_FOUND       - Do not attempt to use if "no" or undefined.

FIND_PATH(MYLIB_INCLUDE_DIR cube.h
  /usr/local/include
  /usr/include
)

FIND_LIBRARY(MY_LIBRARY mylib
  /usr/local/lib
  /usr/lib
)

IF(MYLIB_INCLUDE_DIR)
  IF(MYLIB_LIBRARY)
    SET( MYLIB_LIBRARIES ${AUTOPACK_LIBRARY} )
    SET( MYLIB_FOUND "YES" )
  ENDIF(MYLIB_LIBRARY)
ENDIF(MYLIB_INCLUDE_DIR)


## Alternative way
#[[
find_program(MYLIB_EXECUTABLE NAMES mylib-build
  HINTS
  $ENV{MYLIB_DIR}
  PATH_SUFFIXES bin
  DOC "My math library")

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(Mylib DEFAULT_MSG SPHINX_EXECUTABLE)

mark_as_advanced(MYLIB_EXECUTABLE)]]
