from .base import _Base as Base
import cffi

class ProblemA1(Base):
    def __init__(self):
        ffi = cffi.FFI()
        ffi.cdef("""
            double constantSummation(double n, double constant_);
            float linearSummation (float n);
            double quadraticSummation (double n);
            double bicubicSummation (double n);
        """)
        self.lib = ffi.dlopen(self.object_path("problem.so"))
    def constantSummation(self, n, constant): return self.lib.constantSummation(n, constant)
    def linearSummation(self, n): return self.lib.linearSummation(n)
    def quadraticSummation(self, n): return self.lib.quadraticSummation(n)
    def bicubicSummation(self, n): return self.lib.bicubicSummation(n)


