# # Suppose your source, binaries and libraries are not in system default paths
# # and you set your own paths.
# set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install")

# # Set RPATH for building phase (optional)
# set(CMAKE_BUILD_RPATH "${CMAKE_BINARY_DIR}/lib")

# Set RPATH for installation
# $ORIGIN/../lib means that the dynamic linker will look for libraries
# in the 'lib' directory, which is at the same level as the 'bin' directory where executables reside.
set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")

# Use this to make sure that CMake does not clear the RPATH upon installation
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)