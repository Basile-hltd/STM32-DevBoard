# arm-none-eabi.cmake

# Système cible (bare-metal, pas d'OS)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Compilateurs
set(CMAKE_C_COMPILER   arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_OBJCOPY      arm-none-eabi-objcopy)
set(CMAKE_SIZE         arm-none-eabi-size)

# Ne pas essayer de compiler/linker un exécutable test au moment de la détection
# (indispensable en bare-metal, car il n'y a pas de runtime standard/OS)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Empêche CMake de chercher des libs/programmes de l'hôte
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)