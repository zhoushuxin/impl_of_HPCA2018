from m5.params import *
from m5.SimObject import SimObject
from Controller import RubyController

class L1Cache_Controller(RubyController):
    type = 'L1Cache_Controller'
    cxx_header = 'mem/protocol/L1Cache_Controller.hh'
    sequencer = Param.RubySequencer("")
    L1Icache = Param.RubyCache("")
    L1Dcache = Param.RubyCache("")
    l2_select_num_bits = Param.Int("")
    request_latency = Param.Cycles((2), "")
    use_timeout_latency = Param.Cycles((50), "")
    send_evictions = Param.Bool("")
    requestFromL1Cache = Param.MessageBuffer("")
    responseFromL1Cache = Param.MessageBuffer("")
    requestToL1Cache = Param.MessageBuffer("")
    responseToL1Cache = Param.MessageBuffer("")
    triggerQueue = Param.MessageBuffer("")
    mandatoryQueue = Param.MessageBuffer("")
