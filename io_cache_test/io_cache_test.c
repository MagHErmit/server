#include "my_sys.h"

int main() {
  int fd;
  IO_CACHE cache;
  uchar* buff_from = (uchar*)"qwer gfds hgfd sdfg";
  uchar* buff_to = (uchar*)malloc(sizeof(uchar) * 20);
  fd = my_open("input.txt",O_CREAT | O_RDWR,MYF(MY_WME));
  init_io_cache(&cache, fd, 2, CBQ_READ_APPEND, 0,0, MYF(MY_WME));

  my_b_write(&cache, buff_from, 6);
  my_b_read(&cache, buff_to, 3);
  my_b_read(&cache, buff_to, 3);

  end_io_cache(&cache);
  my_close(cache.file, MYF(MY_WME));
}