import qbs

StaticLibrary {
    name: "rv-core"
    files: [
        "inc/riscv/basic_types.hpp",
        "inc/riscv/cpu.hpp",
        "inc/riscv/instruction/field.hpp",
        "inc/riscv/instruction/format.hpp",
        "inc/riscv/instruction/id.hpp",
        "inc/riscv/instruction/identification.hpp",
        "inc/riscv/instruction/item.hpp",
        "inc/riscv/instruction/raw.hpp",
        "inc/riscv/instruction/raw_items.hpp",
        "inc/riscv/instruction/set/rv32a.hpp",
        "inc/riscv/instruction/set/rv32d.hpp",
        "inc/riscv/instruction/set/rv32f.hpp",
        "inc/riscv/instruction/set/rv32i.hpp",
        "inc/riscv/instruction/set/rv32m.hpp",
        "inc/riscv/instruction/set/rv32q.hpp",
        "inc/riscv/instruction/set/rv64a.hpp",
        "inc/riscv/instruction/set/rv64d.hpp",
        "inc/riscv/instruction/set/rv64f.hpp",
        "inc/riscv/instruction/set/rv64i.hpp",
        "inc/riscv/instruction/set/rv64m.hpp",
        "inc/riscv/instruction/set/rv64q.hpp",
        "inc/riscv/instruction/set/zicsr.hpp",
        "inc/riscv/instruction/type.hpp",
        "inc/riscv/register.hpp",
        "inc/riscv/simulator.hpp",
        "inc/riscv/unit.hpp",
        "inc/riscv/tools.hpp",
        "src/riscv/instruction/format.cpp",
        "src/riscv/instruction/id.cpp",
        "src/riscv/instruction/identification.cpp",
        "src/riscv/instruction/type.cpp",
        "src/riscv/register.cpp",
        "src/riscv/tools.cpp",
    ]
    buildDirectory: "../tmp/"
    install: true
    Depends { name: "cpp" }
    cpp.includePaths: ["inc", "inc_dep"]
    cpp.cxxLanguageVersion: "c++20"
    cpp.enableRtti: false
}
