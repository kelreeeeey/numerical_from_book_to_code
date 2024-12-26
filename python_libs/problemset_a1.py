from os.path import join as join_path, dirname
import cffi

class _Base(object):
    __shared_object_path__ = join_path(dirname( dirname(__file__) ), "shared_objects")

    def object_path(self, shared_object_name: str) -> str:
        return join_path(self.__shared_object_path__, shared_object_name )

class ProblemA1(_Base):
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


