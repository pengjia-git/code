#include "weather.h"
#include "weatherBoard.h"
#include "weatherObserver.h"
#include <unistd.h>

int main() {
  CStatiticBoard *board1 = new CStatiticBoard();
  CWeatherObserver observer;
  observer.registerWB(board1);
  while (1) {
    sleep(1);
  }
  return 0;
}
