#include "enums/PageManage.hh"
namespace Enums {
     const char *PageManageStrings[Num_PageManage] =
    {
        "open",
        "open_adaptive",
        "close",
        "close_adaptive",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_PageManage");

    py::enum_<Enums::PageManage>(m, "enum_PageManage")
        .value("open", Enums::open)
        .value("open_adaptive", Enums::open_adaptive)
        .value("close", Enums::close)
        .value("close_adaptive", Enums::close_adaptive)
        .value("Num_PageManage", Enums::Num_PageManage)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_PageManage", module_init);
