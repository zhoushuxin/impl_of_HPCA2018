#include "enums/ImageFormat.hh"
namespace Enums {
     const char *ImageFormatStrings[Num_ImageFormat] =
    {
        "Auto",
        "Bitmap",
        "Png",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_ImageFormat");

    py::enum_<Enums::ImageFormat>(m, "enum_ImageFormat")
        .value("Auto", Enums::Auto)
        .value("Bitmap", Enums::Bitmap)
        .value("Png", Enums::Png)
        .value("Num_ImageFormat", Enums::Num_ImageFormat)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_ImageFormat", module_init);
