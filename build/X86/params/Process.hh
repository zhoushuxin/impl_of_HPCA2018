#ifndef __PARAMS__Process__
#define __PARAMS__Process__

class Process;

#include <vector>
#include <string>
#include <cstddef>
#include <string>
#include <vector>
#include "params/EmulatedDriver.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include <string>
#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>

#include "params/SimObject.hh"

struct ProcessParams
    : public SimObjectParams
{
    Process * create();
    std::vector< std::string > cmd;
    std::string cwd;
    std::vector< EmulatedDriver * > drivers;
    int egid;
    std::vector< std::string > env;
    std::string errout;
    int euid;
    std::string executable;
    int gid;
    std::string input;
    bool kvmInSE;
    uint64_t maxStackSize;
    std::string output;
    int pgid;
    int pid;
    int ppid;
    uint64_t simpoint;
    System * system;
    int uid;
    bool useArchPT;
};

#endif // __PARAMS__Process__
