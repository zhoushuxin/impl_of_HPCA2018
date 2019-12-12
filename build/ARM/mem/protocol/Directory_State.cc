/** \file Directory_State.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:565
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/protocol/Directory_State.hh"

using namespace std;

// Code to convert the current state to an access permission
AccessPermission Directory_State_to_permission(const Directory_State& obj)
{
    switch(obj) {
      case Directory_State_I:
        return AccessPermission_Read_Write;
      case Directory_State_S:
        return AccessPermission_Read_Only;
      case Directory_State_O:
        return AccessPermission_Maybe_Stale;
      case Directory_State_M:
        return AccessPermission_Maybe_Stale;
      case Directory_State_IS:
        return AccessPermission_Busy;
      case Directory_State_SS:
        return AccessPermission_Read_Only;
      case Directory_State_OO:
        return AccessPermission_Busy;
      case Directory_State_MO:
        return AccessPermission_Busy;
      case Directory_State_MM:
        return AccessPermission_Busy;
      case Directory_State_MM_DMA:
        return AccessPermission_Busy;
      case Directory_State_MI:
        return AccessPermission_Busy;
      case Directory_State_MIS:
        return AccessPermission_Busy;
      case Directory_State_OS:
        return AccessPermission_Busy;
      case Directory_State_OSS:
        return AccessPermission_Busy;
      case Directory_State_XI_M:
        return AccessPermission_Busy;
      case Directory_State_XI_U:
        return AccessPermission_Busy;
      case Directory_State_OI_D:
        return AccessPermission_Busy;
      case Directory_State_OD:
        return AccessPermission_Busy;
      case Directory_State_MD:
        return AccessPermission_Busy;
      default:
        panic("Unknown state access permission converstion for Directory_State");
    }
}

// Code for output operator
ostream&
operator<<(ostream& out, const Directory_State& obj)
{
    out << Directory_State_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
Directory_State_to_string(const Directory_State& obj)
{
    switch(obj) {
      case Directory_State_I:
        return "I";
      case Directory_State_S:
        return "S";
      case Directory_State_O:
        return "O";
      case Directory_State_M:
        return "M";
      case Directory_State_IS:
        return "IS";
      case Directory_State_SS:
        return "SS";
      case Directory_State_OO:
        return "OO";
      case Directory_State_MO:
        return "MO";
      case Directory_State_MM:
        return "MM";
      case Directory_State_MM_DMA:
        return "MM_DMA";
      case Directory_State_MI:
        return "MI";
      case Directory_State_MIS:
        return "MIS";
      case Directory_State_OS:
        return "OS";
      case Directory_State_OSS:
        return "OSS";
      case Directory_State_XI_M:
        return "XI_M";
      case Directory_State_XI_U:
        return "XI_U";
      case Directory_State_OI_D:
        return "OI_D";
      case Directory_State_OD:
        return "OD";
      case Directory_State_MD:
        return "MD";
      default:
        panic("Invalid range for type Directory_State");
    }
}

// Code to convert from a string to the enumeration
Directory_State
string_to_Directory_State(const string& str)
{
    if (str == "I") {
        return Directory_State_I;
    } else if (str == "S") {
        return Directory_State_S;
    } else if (str == "O") {
        return Directory_State_O;
    } else if (str == "M") {
        return Directory_State_M;
    } else if (str == "IS") {
        return Directory_State_IS;
    } else if (str == "SS") {
        return Directory_State_SS;
    } else if (str == "OO") {
        return Directory_State_OO;
    } else if (str == "MO") {
        return Directory_State_MO;
    } else if (str == "MM") {
        return Directory_State_MM;
    } else if (str == "MM_DMA") {
        return Directory_State_MM_DMA;
    } else if (str == "MI") {
        return Directory_State_MI;
    } else if (str == "MIS") {
        return Directory_State_MIS;
    } else if (str == "OS") {
        return Directory_State_OS;
    } else if (str == "OSS") {
        return Directory_State_OSS;
    } else if (str == "XI_M") {
        return Directory_State_XI_M;
    } else if (str == "XI_U") {
        return Directory_State_XI_U;
    } else if (str == "OI_D") {
        return Directory_State_OI_D;
    } else if (str == "OD") {
        return Directory_State_OD;
    } else if (str == "MD") {
        return Directory_State_MD;
    } else {
        panic("Invalid string conversion for %s, type Directory_State", str);
    }
}

// Code to increment an enumeration type
Directory_State&
operator++(Directory_State& e)
{
    assert(e < Directory_State_NUM);
    return e = Directory_State(e+1);
}
