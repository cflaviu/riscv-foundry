import qbs

CppApplication {
    files: [
        "test1.cpp",
    ]
    name: "rv-unit-tests"
    consoleApplication: true
    cpp.includePaths: ["inc", "inc_dep"]
    cpp.cxxLanguageVersion: "c++20"
    cpp.enableRtti: false
    Depends { name: "rv-core" }
    Depends { name: "rv-dissassembler" }
    Group {
        fileTagsFilter: "application"
        qbs.install: false;
        qbs.installDir: "bin"
    }
}
