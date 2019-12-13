#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/BaseTags.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/tags/base.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_BaseTags");
    py::class_<BaseTagsParams, ClockedObjectParams, std::unique_ptr<BaseTagsParams, py::nodelete>>(m, "BaseTagsParams")
        .def_readwrite("block_size", &BaseTagsParams::block_size)
        .def_readwrite("data_latency", &BaseTagsParams::data_latency)
        .def_readwrite("sequential_access", &BaseTagsParams::sequential_access)
        .def_readwrite("size", &BaseTagsParams::size)
        .def_readwrite("tag_latency", &BaseTagsParams::tag_latency)
        .def_readwrite("warmup_percentage", &BaseTagsParams::warmup_percentage)
        ;

    py::class_<BaseTags, ClockedObject, std::unique_ptr<BaseTags, py::nodelete>>(m, "BaseTags")
        ;

}

static EmbeddedPyBind embed_obj("BaseTags", module_init, "ClockedObject");
