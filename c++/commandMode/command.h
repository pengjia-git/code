#ifndef __COMMAND_H__
#define __COMMAND_H__

class CCommand {
public:
  virtual int execute() = 0;
  virtual int undo() = 0;
};

class CNoCommand : public CCommand {
public:
  int execute() { return 0; }
  int undo() { return 0; }
};
#endif
