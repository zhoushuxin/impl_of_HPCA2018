/** \file L2Cache_State.hh
 *
 * Auto generated C++ code started by /home/zhoushuxin/gem5/src/mem/slicc/symbols/Type.py:565
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/protocol/L2Cache_State.hh"

using namespace std;

// Code to convert the current state to an access permission
AccessPermission L2Cache_State_to_permission(const L2Cache_State& obj)
{
    switch(obj) {
      case L2Cache_State_NP:
        return AccessPermission_Invalid;
      case L2Cache_State_I:
        return AccessPermission_Invalid;
      case L2Cache_State_ILS:
        return AccessPermission_Invalid;
      case L2Cache_State_ILX:
        return AccessPermission_Invalid;
      case L2Cache_State_ILO:
        return AccessPermission_Invalid;
      case L2Cache_State_ILOX:
        return AccessPermission_Invalid;
      case L2Cache_State_ILOS:
        return AccessPermission_Invalid;
      case L2Cache_State_ILOSX:
        return AccessPermission_Invalid;
      case L2Cache_State_S:
        return AccessPermission_Read_Only;
      case L2Cache_State_O:
        return AccessPermission_Read_Only;
      case L2Cache_State_OLS:
        return AccessPermission_Read_Only;
      case L2Cache_State_OLSX:
        return AccessPermission_Read_Only;
      case L2Cache_State_SLS:
        return AccessPermission_Read_Only;
      case L2Cache_State_M:
        return AccessPermission_Read_Write;
      case L2Cache_State_IFGX:
        return AccessPermission_Busy;
      case L2Cache_State_IFGS:
        return AccessPermission_Busy;
      case L2Cache_State_ISFGS:
        return AccessPermission_Busy;
      case L2Cache_State_IFGXX:
        return AccessPermission_Busy;
      case L2Cache_State_OFGX:
        return AccessPermission_Busy;
      case L2Cache_State_OLSF:
        return AccessPermission_Busy;
      case L2Cache_State_ILOW:
        return AccessPermission_Busy;
      case L2Cache_State_ILOXW:
        return AccessPermission_Busy;
      case L2Cache_State_ILOSW:
        return AccessPermission_Busy;
      case L2Cache_State_ILOSXW:
        return AccessPermission_Busy;
      case L2Cache_State_SLSW:
        return AccessPermission_Busy;
      case L2Cache_State_OLSW:
        return AccessPermission_Busy;
      case L2Cache_State_ILSW:
        return AccessPermission_Busy;
      case L2Cache_State_IW:
        return AccessPermission_Busy;
      case L2Cache_State_OW:
        return AccessPermission_Busy;
      case L2Cache_State_SW:
        return AccessPermission_Busy;
      case L2Cache_State_OXW:
        return AccessPermission_Busy;
      case L2Cache_State_OLSXW:
        return AccessPermission_Busy;
      case L2Cache_State_ILXW:
        return AccessPermission_Busy;
      case L2Cache_State_IFLS:
        return AccessPermission_Busy;
      case L2Cache_State_IFLO:
        return AccessPermission_Busy;
      case L2Cache_State_IFLOX:
        return AccessPermission_Busy;
      case L2Cache_State_IFLOXX:
        return AccessPermission_Busy;
      case L2Cache_State_IFLOSX:
        return AccessPermission_Busy;
      case L2Cache_State_IFLXO:
        return AccessPermission_Busy;
      case L2Cache_State_IGS:
        return AccessPermission_Busy;
      case L2Cache_State_IGM:
        return AccessPermission_Busy;
      case L2Cache_State_IGMLS:
        return AccessPermission_Busy;
      case L2Cache_State_IGMO:
        return AccessPermission_Busy;
      case L2Cache_State_IGMIO:
        return AccessPermission_Busy;
      case L2Cache_State_OGMIO:
        return AccessPermission_Busy;
      case L2Cache_State_IGMIOF:
        return AccessPermission_Busy;
      case L2Cache_State_IGMIOFS:
        return AccessPermission_Busy;
      case L2Cache_State_OGMIOF:
        return AccessPermission_Busy;
      case L2Cache_State_II:
        return AccessPermission_Busy;
      case L2Cache_State_MM:
        return AccessPermission_Busy;
      case L2Cache_State_SS:
        return AccessPermission_Busy;
      case L2Cache_State_OO:
        return AccessPermission_Busy;
      case L2Cache_State_OLSS:
        return AccessPermission_Busy;
      case L2Cache_State_OLSXS:
        return AccessPermission_Busy;
      case L2Cache_State_SLSS:
        return AccessPermission_Busy;
      case L2Cache_State_OI:
        return AccessPermission_Busy;
      case L2Cache_State_MI:
        return AccessPermission_Busy;
      case L2Cache_State_MII:
        return AccessPermission_Busy;
      case L2Cache_State_OLSI:
        return AccessPermission_Busy;
      case L2Cache_State_ILSI:
        return AccessPermission_Busy;
      case L2Cache_State_ILOSD:
        return AccessPermission_Busy;
      case L2Cache_State_ILOSXD:
        return AccessPermission_Busy;
      case L2Cache_State_ILOD:
        return AccessPermission_Busy;
      case L2Cache_State_ILXD:
        return AccessPermission_Busy;
      case L2Cache_State_ILOXD:
        return AccessPermission_Busy;
      default:
        panic("Unknown state access permission converstion for L2Cache_State");
    }
}

// Code for output operator
ostream&
operator<<(ostream& out, const L2Cache_State& obj)
{
    out << L2Cache_State_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
L2Cache_State_to_string(const L2Cache_State& obj)
{
    switch(obj) {
      case L2Cache_State_NP:
        return "NP";
      case L2Cache_State_I:
        return "I";
      case L2Cache_State_ILS:
        return "ILS";
      case L2Cache_State_ILX:
        return "ILX";
      case L2Cache_State_ILO:
        return "ILO";
      case L2Cache_State_ILOX:
        return "ILOX";
      case L2Cache_State_ILOS:
        return "ILOS";
      case L2Cache_State_ILOSX:
        return "ILOSX";
      case L2Cache_State_S:
        return "S";
      case L2Cache_State_O:
        return "O";
      case L2Cache_State_OLS:
        return "OLS";
      case L2Cache_State_OLSX:
        return "OLSX";
      case L2Cache_State_SLS:
        return "SLS";
      case L2Cache_State_M:
        return "M";
      case L2Cache_State_IFGX:
        return "IFGX";
      case L2Cache_State_IFGS:
        return "IFGS";
      case L2Cache_State_ISFGS:
        return "ISFGS";
      case L2Cache_State_IFGXX:
        return "IFGXX";
      case L2Cache_State_OFGX:
        return "OFGX";
      case L2Cache_State_OLSF:
        return "OLSF";
      case L2Cache_State_ILOW:
        return "ILOW";
      case L2Cache_State_ILOXW:
        return "ILOXW";
      case L2Cache_State_ILOSW:
        return "ILOSW";
      case L2Cache_State_ILOSXW:
        return "ILOSXW";
      case L2Cache_State_SLSW:
        return "SLSW";
      case L2Cache_State_OLSW:
        return "OLSW";
      case L2Cache_State_ILSW:
        return "ILSW";
      case L2Cache_State_IW:
        return "IW";
      case L2Cache_State_OW:
        return "OW";
      case L2Cache_State_SW:
        return "SW";
      case L2Cache_State_OXW:
        return "OXW";
      case L2Cache_State_OLSXW:
        return "OLSXW";
      case L2Cache_State_ILXW:
        return "ILXW";
      case L2Cache_State_IFLS:
        return "IFLS";
      case L2Cache_State_IFLO:
        return "IFLO";
      case L2Cache_State_IFLOX:
        return "IFLOX";
      case L2Cache_State_IFLOXX:
        return "IFLOXX";
      case L2Cache_State_IFLOSX:
        return "IFLOSX";
      case L2Cache_State_IFLXO:
        return "IFLXO";
      case L2Cache_State_IGS:
        return "IGS";
      case L2Cache_State_IGM:
        return "IGM";
      case L2Cache_State_IGMLS:
        return "IGMLS";
      case L2Cache_State_IGMO:
        return "IGMO";
      case L2Cache_State_IGMIO:
        return "IGMIO";
      case L2Cache_State_OGMIO:
        return "OGMIO";
      case L2Cache_State_IGMIOF:
        return "IGMIOF";
      case L2Cache_State_IGMIOFS:
        return "IGMIOFS";
      case L2Cache_State_OGMIOF:
        return "OGMIOF";
      case L2Cache_State_II:
        return "II";
      case L2Cache_State_MM:
        return "MM";
      case L2Cache_State_SS:
        return "SS";
      case L2Cache_State_OO:
        return "OO";
      case L2Cache_State_OLSS:
        return "OLSS";
      case L2Cache_State_OLSXS:
        return "OLSXS";
      case L2Cache_State_SLSS:
        return "SLSS";
      case L2Cache_State_OI:
        return "OI";
      case L2Cache_State_MI:
        return "MI";
      case L2Cache_State_MII:
        return "MII";
      case L2Cache_State_OLSI:
        return "OLSI";
      case L2Cache_State_ILSI:
        return "ILSI";
      case L2Cache_State_ILOSD:
        return "ILOSD";
      case L2Cache_State_ILOSXD:
        return "ILOSXD";
      case L2Cache_State_ILOD:
        return "ILOD";
      case L2Cache_State_ILXD:
        return "ILXD";
      case L2Cache_State_ILOXD:
        return "ILOXD";
      default:
        panic("Invalid range for type L2Cache_State");
    }
}

// Code to convert from a string to the enumeration
L2Cache_State
string_to_L2Cache_State(const string& str)
{
    if (str == "NP") {
        return L2Cache_State_NP;
    } else if (str == "I") {
        return L2Cache_State_I;
    } else if (str == "ILS") {
        return L2Cache_State_ILS;
    } else if (str == "ILX") {
        return L2Cache_State_ILX;
    } else if (str == "ILO") {
        return L2Cache_State_ILO;
    } else if (str == "ILOX") {
        return L2Cache_State_ILOX;
    } else if (str == "ILOS") {
        return L2Cache_State_ILOS;
    } else if (str == "ILOSX") {
        return L2Cache_State_ILOSX;
    } else if (str == "S") {
        return L2Cache_State_S;
    } else if (str == "O") {
        return L2Cache_State_O;
    } else if (str == "OLS") {
        return L2Cache_State_OLS;
    } else if (str == "OLSX") {
        return L2Cache_State_OLSX;
    } else if (str == "SLS") {
        return L2Cache_State_SLS;
    } else if (str == "M") {
        return L2Cache_State_M;
    } else if (str == "IFGX") {
        return L2Cache_State_IFGX;
    } else if (str == "IFGS") {
        return L2Cache_State_IFGS;
    } else if (str == "ISFGS") {
        return L2Cache_State_ISFGS;
    } else if (str == "IFGXX") {
        return L2Cache_State_IFGXX;
    } else if (str == "OFGX") {
        return L2Cache_State_OFGX;
    } else if (str == "OLSF") {
        return L2Cache_State_OLSF;
    } else if (str == "ILOW") {
        return L2Cache_State_ILOW;
    } else if (str == "ILOXW") {
        return L2Cache_State_ILOXW;
    } else if (str == "ILOSW") {
        return L2Cache_State_ILOSW;
    } else if (str == "ILOSXW") {
        return L2Cache_State_ILOSXW;
    } else if (str == "SLSW") {
        return L2Cache_State_SLSW;
    } else if (str == "OLSW") {
        return L2Cache_State_OLSW;
    } else if (str == "ILSW") {
        return L2Cache_State_ILSW;
    } else if (str == "IW") {
        return L2Cache_State_IW;
    } else if (str == "OW") {
        return L2Cache_State_OW;
    } else if (str == "SW") {
        return L2Cache_State_SW;
    } else if (str == "OXW") {
        return L2Cache_State_OXW;
    } else if (str == "OLSXW") {
        return L2Cache_State_OLSXW;
    } else if (str == "ILXW") {
        return L2Cache_State_ILXW;
    } else if (str == "IFLS") {
        return L2Cache_State_IFLS;
    } else if (str == "IFLO") {
        return L2Cache_State_IFLO;
    } else if (str == "IFLOX") {
        return L2Cache_State_IFLOX;
    } else if (str == "IFLOXX") {
        return L2Cache_State_IFLOXX;
    } else if (str == "IFLOSX") {
        return L2Cache_State_IFLOSX;
    } else if (str == "IFLXO") {
        return L2Cache_State_IFLXO;
    } else if (str == "IGS") {
        return L2Cache_State_IGS;
    } else if (str == "IGM") {
        return L2Cache_State_IGM;
    } else if (str == "IGMLS") {
        return L2Cache_State_IGMLS;
    } else if (str == "IGMO") {
        return L2Cache_State_IGMO;
    } else if (str == "IGMIO") {
        return L2Cache_State_IGMIO;
    } else if (str == "OGMIO") {
        return L2Cache_State_OGMIO;
    } else if (str == "IGMIOF") {
        return L2Cache_State_IGMIOF;
    } else if (str == "IGMIOFS") {
        return L2Cache_State_IGMIOFS;
    } else if (str == "OGMIOF") {
        return L2Cache_State_OGMIOF;
    } else if (str == "II") {
        return L2Cache_State_II;
    } else if (str == "MM") {
        return L2Cache_State_MM;
    } else if (str == "SS") {
        return L2Cache_State_SS;
    } else if (str == "OO") {
        return L2Cache_State_OO;
    } else if (str == "OLSS") {
        return L2Cache_State_OLSS;
    } else if (str == "OLSXS") {
        return L2Cache_State_OLSXS;
    } else if (str == "SLSS") {
        return L2Cache_State_SLSS;
    } else if (str == "OI") {
        return L2Cache_State_OI;
    } else if (str == "MI") {
        return L2Cache_State_MI;
    } else if (str == "MII") {
        return L2Cache_State_MII;
    } else if (str == "OLSI") {
        return L2Cache_State_OLSI;
    } else if (str == "ILSI") {
        return L2Cache_State_ILSI;
    } else if (str == "ILOSD") {
        return L2Cache_State_ILOSD;
    } else if (str == "ILOSXD") {
        return L2Cache_State_ILOSXD;
    } else if (str == "ILOD") {
        return L2Cache_State_ILOD;
    } else if (str == "ILXD") {
        return L2Cache_State_ILXD;
    } else if (str == "ILOXD") {
        return L2Cache_State_ILOXD;
    } else {
        panic("Invalid string conversion for %s, type L2Cache_State", str);
    }
}

// Code to increment an enumeration type
L2Cache_State&
operator++(L2Cache_State& e)
{
    assert(e < L2Cache_State_NUM);
    return e = L2Cache_State(e+1);
}
