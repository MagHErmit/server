#include "my_sys.h"
#include "pthread.h"


IO_CACHE cache;
uchar* buff_from;
uchar* buff_to;

void* read_to_cache()
{
  for (int i= 0; i < 5; ++i)
    my_b_read(&cache, buff_to + (i*4), 4);
  return NULL;
}

void* write_to_cache()
{
  for (int i= 0; i < 5; ++i)
    my_b_write(&cache, buff_from + (i*4), 4);
  return NULL;
}

int main() {
  pthread_t thr_read;//, thr_write;

  int fd;
  buff_from = (uchar*)"qwer gfds hgfd sdfg";
  buff_to = (uchar*)malloc(sizeof(uchar) * 20);
  fd = my_open("input.txt",O_CREAT | O_RDWR,MYF(MY_WME));
  init_io_cache(&cache, fd, 2, CBQ_READ_APPEND, 0,0, MYF(MY_WME));

  //pthread_create(&thr_write, NULL, write_to_cache, NULL);
  pthread_create(&thr_read, NULL, read_to_cache, NULL);

  pthread_join(thr_read, NULL);
  //pthread_join(thr_write, NULL);

  end_io_cache(&cache);
  my_close(cache.file, MYF(MY_WME));
}