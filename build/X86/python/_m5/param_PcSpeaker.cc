#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/PcSpeaker.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/x86/speaker.hh"

#include "dev/x86/i8254.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_PcSpeaker");
    py::class_<PcSpeakerParams, BasicPioDeviceParams, std::unique_ptr<PcSpeakerParams, py::nodelete>>(m, "PcSpeakerParams")
        .def(py::init<>())
        .def("create", &PcSpeakerParams::create)
        .def_readwrite("i8254", &PcSpeakerParams::i8254)
        ;

    py::class_<X86ISA::Speaker, BasicPioDevice, std::unique_ptr<X86ISA::Speaker, py::nodelete>>(m, "X86ISA_COLONS_Speaker")
        ;

}

static EmbeddedPyBind embed_obj("PcSpeaker", module_init, "BasicPioDevice");
