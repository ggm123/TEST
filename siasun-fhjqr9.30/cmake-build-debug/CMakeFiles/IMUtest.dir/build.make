# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/siasunhebo/clion-2019.1.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/siasunhebo/clion-2019.1.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/siasunhebo/ggm/siasun-fhjqr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/siasunhebo/ggm/siasun-fhjqr/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/IMUtest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IMUtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IMUtest.dir/flags.make

CMakeFiles/IMUtest.dir/main.c.o: CMakeFiles/IMUtest.dir/flags.make
CMakeFiles/IMUtest.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siasunhebo/ggm/siasun-fhjqr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/IMUtest.dir/main.c.o"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IMUtest.dir/main.c.o   -c /home/siasunhebo/ggm/siasun-fhjqr/main.c

CMakeFiles/IMUtest.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IMUtest.dir/main.c.i"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siasunhebo/ggm/siasun-fhjqr/main.c > CMakeFiles/IMUtest.dir/main.c.i

CMakeFiles/IMUtest.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IMUtest.dir/main.c.s"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siasunhebo/ggm/siasun-fhjqr/main.c -o CMakeFiles/IMUtest.dir/main.c.s

CMakeFiles/IMUtest.dir/TCP/TCP.c.o: CMakeFiles/IMUtest.dir/flags.make
CMakeFiles/IMUtest.dir/TCP/TCP.c.o: ../TCP/TCP.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siasunhebo/ggm/siasun-fhjqr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/IMUtest.dir/TCP/TCP.c.o"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IMUtest.dir/TCP/TCP.c.o   -c /home/siasunhebo/ggm/siasun-fhjqr/TCP/TCP.c

CMakeFiles/IMUtest.dir/TCP/TCP.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IMUtest.dir/TCP/TCP.c.i"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siasunhebo/ggm/siasun-fhjqr/TCP/TCP.c > CMakeFiles/IMUtest.dir/TCP/TCP.c.i

CMakeFiles/IMUtest.dir/TCP/TCP.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IMUtest.dir/TCP/TCP.c.s"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siasunhebo/ggm/siasun-fhjqr/TCP/TCP.c -o CMakeFiles/IMUtest.dir/TCP/TCP.c.s

CMakeFiles/IMUtest.dir/HC_SuK043_C/HC_SuK043_C.c.o: CMakeFiles/IMUtest.dir/flags.make
CMakeFiles/IMUtest.dir/HC_SuK043_C/HC_SuK043_C.c.o: ../HC_SuK043_C/HC_SuK043_C.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siasunhebo/ggm/siasun-fhjqr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/IMUtest.dir/HC_SuK043_C/HC_SuK043_C.c.o"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IMUtest.dir/HC_SuK043_C/HC_SuK043_C.c.o   -c /home/siasunhebo/ggm/siasun-fhjqr/HC_SuK043_C/HC_SuK043_C.c

CMakeFiles/IMUtest.dir/HC_SuK043_C/HC_SuK043_C.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IMUtest.dir/HC_SuK043_C/HC_SuK043_C.c.i"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siasunhebo/ggm/siasun-fhjqr/HC_SuK043_C/HC_SuK043_C.c > CMakeFiles/IMUtest.dir/HC_SuK043_C/HC_SuK043_C.c.i

CMakeFiles/IMUtest.dir/HC_SuK043_C/HC_SuK043_C.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IMUtest.dir/HC_SuK043_C/HC_SuK043_C.c.s"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siasunhebo/ggm/siasun-fhjqr/HC_SuK043_C/HC_SuK043_C.c -o CMakeFiles/IMUtest.dir/HC_SuK043_C/HC_SuK043_C.c.s

CMakeFiles/IMUtest.dir/FD123_CA_000/FD123_CA_000.c.o: CMakeFiles/IMUtest.dir/flags.make
CMakeFiles/IMUtest.dir/FD123_CA_000/FD123_CA_000.c.o: ../FD123_CA_000/FD123_CA_000.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siasunhebo/ggm/siasun-fhjqr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/IMUtest.dir/FD123_CA_000/FD123_CA_000.c.o"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IMUtest.dir/FD123_CA_000/FD123_CA_000.c.o   -c /home/siasunhebo/ggm/siasun-fhjqr/FD123_CA_000/FD123_CA_000.c

CMakeFiles/IMUtest.dir/FD123_CA_000/FD123_CA_000.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IMUtest.dir/FD123_CA_000/FD123_CA_000.c.i"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siasunhebo/ggm/siasun-fhjqr/FD123_CA_000/FD123_CA_000.c > CMakeFiles/IMUtest.dir/FD123_CA_000/FD123_CA_000.c.i

CMakeFiles/IMUtest.dir/FD123_CA_000/FD123_CA_000.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IMUtest.dir/FD123_CA_000/FD123_CA_000.c.s"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siasunhebo/ggm/siasun-fhjqr/FD123_CA_000/FD123_CA_000.c -o CMakeFiles/IMUtest.dir/FD123_CA_000/FD123_CA_000.c.s

CMakeFiles/IMUtest.dir/CNS_MGS_160S/CNS_MGS_160S.c.o: CMakeFiles/IMUtest.dir/flags.make
CMakeFiles/IMUtest.dir/CNS_MGS_160S/CNS_MGS_160S.c.o: ../CNS_MGS_160S/CNS_MGS_160S.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siasunhebo/ggm/siasun-fhjqr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/IMUtest.dir/CNS_MGS_160S/CNS_MGS_160S.c.o"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IMUtest.dir/CNS_MGS_160S/CNS_MGS_160S.c.o   -c /home/siasunhebo/ggm/siasun-fhjqr/CNS_MGS_160S/CNS_MGS_160S.c

CMakeFiles/IMUtest.dir/CNS_MGS_160S/CNS_MGS_160S.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IMUtest.dir/CNS_MGS_160S/CNS_MGS_160S.c.i"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siasunhebo/ggm/siasun-fhjqr/CNS_MGS_160S/CNS_MGS_160S.c > CMakeFiles/IMUtest.dir/CNS_MGS_160S/CNS_MGS_160S.c.i

CMakeFiles/IMUtest.dir/CNS_MGS_160S/CNS_MGS_160S.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IMUtest.dir/CNS_MGS_160S/CNS_MGS_160S.c.s"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siasunhebo/ggm/siasun-fhjqr/CNS_MGS_160S/CNS_MGS_160S.c -o CMakeFiles/IMUtest.dir/CNS_MGS_160S/CNS_MGS_160S.c.s

CMakeFiles/IMUtest.dir/CNS_RFID_1S/CNS_RFID_1S.c.o: CMakeFiles/IMUtest.dir/flags.make
CMakeFiles/IMUtest.dir/CNS_RFID_1S/CNS_RFID_1S.c.o: ../CNS_RFID_1S/CNS_RFID_1S.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siasunhebo/ggm/siasun-fhjqr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/IMUtest.dir/CNS_RFID_1S/CNS_RFID_1S.c.o"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IMUtest.dir/CNS_RFID_1S/CNS_RFID_1S.c.o   -c /home/siasunhebo/ggm/siasun-fhjqr/CNS_RFID_1S/CNS_RFID_1S.c

CMakeFiles/IMUtest.dir/CNS_RFID_1S/CNS_RFID_1S.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IMUtest.dir/CNS_RFID_1S/CNS_RFID_1S.c.i"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siasunhebo/ggm/siasun-fhjqr/CNS_RFID_1S/CNS_RFID_1S.c > CMakeFiles/IMUtest.dir/CNS_RFID_1S/CNS_RFID_1S.c.i

CMakeFiles/IMUtest.dir/CNS_RFID_1S/CNS_RFID_1S.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IMUtest.dir/CNS_RFID_1S/CNS_RFID_1S.c.s"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siasunhebo/ggm/siasun-fhjqr/CNS_RFID_1S/CNS_RFID_1S.c -o CMakeFiles/IMUtest.dir/CNS_RFID_1S/CNS_RFID_1S.c.s

CMakeFiles/IMUtest.dir/UART/UART.c.o: CMakeFiles/IMUtest.dir/flags.make
CMakeFiles/IMUtest.dir/UART/UART.c.o: ../UART/UART.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siasunhebo/ggm/siasun-fhjqr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/IMUtest.dir/UART/UART.c.o"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IMUtest.dir/UART/UART.c.o   -c /home/siasunhebo/ggm/siasun-fhjqr/UART/UART.c

CMakeFiles/IMUtest.dir/UART/UART.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IMUtest.dir/UART/UART.c.i"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siasunhebo/ggm/siasun-fhjqr/UART/UART.c > CMakeFiles/IMUtest.dir/UART/UART.c.i

CMakeFiles/IMUtest.dir/UART/UART.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IMUtest.dir/UART/UART.c.s"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siasunhebo/ggm/siasun-fhjqr/UART/UART.c -o CMakeFiles/IMUtest.dir/UART/UART.c.s

CMakeFiles/IMUtest.dir/CAN/can.c.o: CMakeFiles/IMUtest.dir/flags.make
CMakeFiles/IMUtest.dir/CAN/can.c.o: ../CAN/can.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siasunhebo/ggm/siasun-fhjqr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/IMUtest.dir/CAN/can.c.o"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IMUtest.dir/CAN/can.c.o   -c /home/siasunhebo/ggm/siasun-fhjqr/CAN/can.c

CMakeFiles/IMUtest.dir/CAN/can.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IMUtest.dir/CAN/can.c.i"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siasunhebo/ggm/siasun-fhjqr/CAN/can.c > CMakeFiles/IMUtest.dir/CAN/can.c.i

CMakeFiles/IMUtest.dir/CAN/can.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IMUtest.dir/CAN/can.c.s"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siasunhebo/ggm/siasun-fhjqr/CAN/can.c -o CMakeFiles/IMUtest.dir/CAN/can.c.s

CMakeFiles/IMUtest.dir/SPC_SDIO_1616/SPC_SDIO_1616.c.o: CMakeFiles/IMUtest.dir/flags.make
CMakeFiles/IMUtest.dir/SPC_SDIO_1616/SPC_SDIO_1616.c.o: ../SPC_SDIO_1616/SPC_SDIO_1616.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siasunhebo/ggm/siasun-fhjqr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/IMUtest.dir/SPC_SDIO_1616/SPC_SDIO_1616.c.o"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IMUtest.dir/SPC_SDIO_1616/SPC_SDIO_1616.c.o   -c /home/siasunhebo/ggm/siasun-fhjqr/SPC_SDIO_1616/SPC_SDIO_1616.c

CMakeFiles/IMUtest.dir/SPC_SDIO_1616/SPC_SDIO_1616.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IMUtest.dir/SPC_SDIO_1616/SPC_SDIO_1616.c.i"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siasunhebo/ggm/siasun-fhjqr/SPC_SDIO_1616/SPC_SDIO_1616.c > CMakeFiles/IMUtest.dir/SPC_SDIO_1616/SPC_SDIO_1616.c.i

CMakeFiles/IMUtest.dir/SPC_SDIO_1616/SPC_SDIO_1616.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IMUtest.dir/SPC_SDIO_1616/SPC_SDIO_1616.c.s"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siasunhebo/ggm/siasun-fhjqr/SPC_SDIO_1616/SPC_SDIO_1616.c -o CMakeFiles/IMUtest.dir/SPC_SDIO_1616/SPC_SDIO_1616.c.s

CMakeFiles/IMUtest.dir/Timer/Timer.c.o: CMakeFiles/IMUtest.dir/flags.make
CMakeFiles/IMUtest.dir/Timer/Timer.c.o: ../Timer/Timer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siasunhebo/ggm/siasun-fhjqr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/IMUtest.dir/Timer/Timer.c.o"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IMUtest.dir/Timer/Timer.c.o   -c /home/siasunhebo/ggm/siasun-fhjqr/Timer/Timer.c

CMakeFiles/IMUtest.dir/Timer/Timer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IMUtest.dir/Timer/Timer.c.i"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siasunhebo/ggm/siasun-fhjqr/Timer/Timer.c > CMakeFiles/IMUtest.dir/Timer/Timer.c.i

CMakeFiles/IMUtest.dir/Timer/Timer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IMUtest.dir/Timer/Timer.c.s"
	/opt/poky/1.7/sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc   -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 --sysroot=/opt/poky/1.7/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siasunhebo/ggm/siasun-fhjqr/Timer/Timer.c -o CMakeFiles/IMUtest.dir/Timer/Timer.c.s

# Object files for target IMUtest
IMUtest_OBJECTS = \
"CMakeFiles/IMUtest.dir/main.c.o" \
"CMakeFiles/IMUtest.dir/TCP/TCP.c.o" \
"CMakeFiles/IMUtest.dir/HC_SuK043_C/HC_SuK043_C.c.o" \
"CMakeFiles/IMUtest.dir/FD123_CA_000/FD123_CA_000.c.o" \
"CMakeFiles/IMUtest.dir/CNS_MGS_160S/CNS_MGS_160S.c.o" \
"CMakeFiles/IMUtest.dir/CNS_RFID_1S/CNS_RFID_1S.c.o" \
"CMakeFiles/IMUtest.dir/UART/UART.c.o" \
"CMakeFiles/IMUtest.dir/CAN/can.c.o" \
"CMakeFiles/IMUtest.dir/SPC_SDIO_1616/SPC_SDIO_1616.c.o" \
"CMakeFiles/IMUtest.dir/Timer/Timer.c.o"

# External object files for target IMUtest
IMUtest_EXTERNAL_OBJECTS =

IMUtest: CMakeFiles/IMUtest.dir/main.c.o
IMUtest: CMakeFiles/IMUtest.dir/TCP/TCP.c.o
IMUtest: CMakeFiles/IMUtest.dir/HC_SuK043_C/HC_SuK043_C.c.o
IMUtest: CMakeFiles/IMUtest.dir/FD123_CA_000/FD123_CA_000.c.o
IMUtest: CMakeFiles/IMUtest.dir/CNS_MGS_160S/CNS_MGS_160S.c.o
IMUtest: CMakeFiles/IMUtest.dir/CNS_RFID_1S/CNS_RFID_1S.c.o
IMUtest: CMakeFiles/IMUtest.dir/UART/UART.c.o
IMUtest: CMakeFiles/IMUtest.dir/CAN/can.c.o
IMUtest: CMakeFiles/IMUtest.dir/SPC_SDIO_1616/SPC_SDIO_1616.c.o
IMUtest: CMakeFiles/IMUtest.dir/Timer/Timer.c.o
IMUtest: CMakeFiles/IMUtest.dir/build.make
IMUtest: CMakeFiles/IMUtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/siasunhebo/ggm/siasun-fhjqr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable IMUtest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IMUtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IMUtest.dir/build: IMUtest

.PHONY : CMakeFiles/IMUtest.dir/build

CMakeFiles/IMUtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IMUtest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IMUtest.dir/clean

CMakeFiles/IMUtest.dir/depend:
	cd /home/siasunhebo/ggm/siasun-fhjqr/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/siasunhebo/ggm/siasun-fhjqr /home/siasunhebo/ggm/siasun-fhjqr /home/siasunhebo/ggm/siasun-fhjqr/cmake-build-debug /home/siasunhebo/ggm/siasun-fhjqr/cmake-build-debug /home/siasunhebo/ggm/siasun-fhjqr/cmake-build-debug/CMakeFiles/IMUtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IMUtest.dir/depend
