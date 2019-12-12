#include "enums/DecoderFlavour.hh"
namespace Enums {
     const char *DecoderFlavourStrings[Num_DecoderFlavour] =
    {
        "Generic",
    };
    } // namespace Enums
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

static void
module_init(py::module &m_internal)
{
    py::module m = m_internal.def_submodule("enum_DecoderFlavour");

    py::enum_<Enums::DecoderFlavour>(m, "enum_DecoderFlavour")
        .value("Generic", Enums::Generic)
        .value("Num_DecoderFlavour", Enums::Num_DecoderFlavour)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_DecoderFlavour", module_init);
