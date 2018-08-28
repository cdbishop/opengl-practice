include(default)

[settings]
compiler=gcc
compiler.libcxx=libstdc++11
compiler.version=8
compiler.exception=seh
compiler.threads=posix

fmt:compiler='Visual Studio'
fmt:compiler.version=15
fmt:compiler.runtime=MT

glad:compiler=gcc
glad:compiler.version=8

glfw:compiler=gcc
glfw:compiler.version=8

[options]
fmt:header_only=True