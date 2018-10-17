/*
  The standard library function

    int fseek(FILE *fp, long offset, int origin)

  is identical o lseek except that fp is a file pointer instead of a file
  descriptor and the return value is an int status, not a position. WRite fseek.
  Make sure that your fseek coordinates properly with the buffering done for
  the other functions of the library.
*/