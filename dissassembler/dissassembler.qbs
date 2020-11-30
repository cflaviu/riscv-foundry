import qbs

CppApplication {
    name: "rv-dissassembler"
    consoleApplication: true
    files: [
        "inc/riscv/dissassembler.hpp",
        "inc/riscv/executable/elf.hpp",
        "src/riscv/dissassembler.cpp",
        "src/riscv/main.cpp",
    ]
    cpp.includePaths: ["inc", "inc_dep", "../core/inc"]
    cpp.cxxLanguageVersion: "c++20"
    cpp.enableRtti: false
    cpp.libraryPaths: [
        "/usr/local/lib",
        "/usr/lib/x86_64-linux-gnu"
    ]
    cpp.staticLibraries: [
        "/home/io/Development/02_riscv/build-riscv-sim-Desktop-Debug/Debug/install-root/usr/local/lib/librv-core.a",
        "/usr/lib/x86_64-linux-gnu/libboost_iostreams.so.1.71.0"
    ]
    Depends { name: "rv-core" }
    Group {
        fileTagsFilter: "application"
        qbs.install: false;
        qbs.installDir: "bin"
    }
}
