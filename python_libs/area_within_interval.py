from .base import _Base as Base
import cffi

class AreaWithinInterval(Base):
    def __init__(self) -> None:
        ffi = cffi.FFI()
        ffi.cdef("""
            double areaWithinInterval(
                func_area_under_curve_t *func,
                area_under_curve_t *areas,
                double left,
                double right,
                int interval);
            double quadraticPartition_f (double x);
            double quadraticSummation_f (double *x, double j);
            void example();
        """)
        self.lib = ffi.dlopen(self.object_path("example_area_within_interval.so"))
        return None

    def quadratic_partition(self, x):
        return self.lib.quadraticPartition_f(x)

    def quadratic_summation(self, x, j):
        return self.lib.quadraticSummation_f(x, j)

    def example(self) -> int:
        return self.lib.example()

