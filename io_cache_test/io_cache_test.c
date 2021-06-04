#include "my_sys.h"

int main() {
  int fd;
  IO_CACHE cache;
  uchar* buff = malloc(sizeof(uchar) * 64);
  buff[0] = 'z';
  buff[1] = 'y';
  fd = my_open("input.txt",O_CREAT | O_RDWR,MYF(MY_WME));
  init_io_cache(&cache, fd, 2, CBQ_READ_APPEND, 0,0, MYF(MY_WME));

  my_b_write(&cache, buff, 2);
  my_b_read(&cache, buff, 1);

  end_io_cache(&cache);
  my_close(cache.file, MYF(MY_WME));
}