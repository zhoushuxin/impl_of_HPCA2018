import _m5.core
import m5.util

buildEnv = m5.util.SmartDict([('USE_FENV', True), ('SS_COMPATIBLE_FP', False), ('TARGET_ISA', 'x86'), ('TARGET_GPU_ISA', 'hsail'), ('CP_ANNOTATE', False), ('USE_POSIX_CLOCK', True), ('USE_KVM', True), ('USE_TUNTAP', True), ('PROTOCOL', 'MI_example'), ('HAVE_PROTOBUF', False), ('HAVE_PERF_ATTR_EXCLUDE_HOST', 1), ('USE_PNG', True)])

compileDate = _m5.core.compileDate
_globals = globals()
for key,val in _m5.core.__dict__.iteritems():
    if key.startswith('flag_'):
        flag = key[5:]
        _globals[flag] = val
del _globals
