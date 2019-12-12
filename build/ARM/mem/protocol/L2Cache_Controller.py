from m5.params import *
from m5.SimObject import SimObject
from Controller import RubyController

class L2Cache_Controller(RubyController):
    type = 'L2Cache_Controller'
    cxx_header = 'mem/protocol/L2Cache_Controller.hh'
    L2cache = Param.RubyCache("")
    response_latency = Param.Cycles((2), "")
    request_latency = Param.Cycles((2), "")
    L1RequestFromL2Cache = Param.MessageBuffer("")
    GlobalRequestFromL2Cache = Param.MessageBuffer("")
    responseFromL2Cache = Param.MessageBuffer("")
    L1RequestToL2Cache = Param.MessageBuffer("")
    GlobalRequestToL2Cache = Param.MessageBuffer("")
    responseToL2Cache = Param.MessageBuffer("")
    triggerQueue = Param.MessageBuffer("")
