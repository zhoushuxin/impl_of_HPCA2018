from m5.params import *
from m5.SimObject import SimObject
from Controller import RubyController

class DMA_Controller(RubyController):
    type = 'DMA_Controller'
    cxx_header = 'mem/protocol/DMA_Controller.hh'
    dma_sequencer = Param.DMASequencer("")
    request_latency = Param.Cycles((14), "")
    response_latency = Param.Cycles((14), "")
    responseFromDir = Param.MessageBuffer("")
    reqToDir = Param.MessageBuffer("")
    respToDir = Param.MessageBuffer("")
    mandatoryQueue = Param.MessageBuffer("")
    triggerQueue = Param.MessageBuffer("")
