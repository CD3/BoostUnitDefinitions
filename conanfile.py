from conans import ConanFile

class ConanBuild(ConanFile):
    settings = "os","arch","compiler","build_type"
    generators = "CMakeDeps", "CMakeToolchain"
    requires = 'boost/1.72.0', 'catch2/3.0.1'

