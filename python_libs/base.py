from os.path import join as join_path, dirname

__all__ = ["_Base"]

class _Base(object):
    __shared_object_path__ = join_path(dirname( dirname(__file__) ), "shared_objects")
    def object_path(self, shared_object_name: str) -> str:
        return join_path(self.__shared_object_path__, shared_object_name )


