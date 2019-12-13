#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "params/Cache.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/cache.hh"

#include "enums/Clusivity.hh"
namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("param_Cache");
    py::class_<CacheParams, BaseCacheParams, std::unique_ptr<CacheParams, py::nodelete>>(m, "CacheParams")
        .def(py::init<>())
        .def("create", &CacheParams::create)
        .def_readwrite("clusivity", &CacheParams::clusivity)
        .def_readwrite("writeback_clean", &CacheParams::writeback_clean)
        ;

    py::class_<Cache, BaseCache, std::unique_ptr<Cache, py::nodelete>>(m, "Cache")
        ;

}

static EmbeddedPyBind embed_obj("Cache", module_init, "BaseCache");
