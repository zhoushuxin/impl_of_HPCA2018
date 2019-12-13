#ifndef __PARAMS__GenericPciHost__
#define __PARAMS__GenericPciHost__

class GenericPciHost;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/Platform.hh"

#include "params/PciHost.hh"

struct GenericPciHostParams
    : public PciHostParams
{
    GenericPciHost * create();
    Addr conf_base;
    uint8_t conf_device_bits;
    Addr conf_size;
    Addr pci_dma_base;
    Addr pci_mem_base;
    Addr pci_pio_base;
    Platform * platform;
};

#endif // __PARAMS__GenericPciHost__
