#include <sys/stat.h>
#include <sys/types.h>

int main()
{
  const char * path="/home/jia/code/c/make_a_dir_for_test";
  mkdir(path,0777);
  return 0;
}
