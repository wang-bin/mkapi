./mkapi.sh -name openal ~/openal-soft/include/AL/al{c,}.h
#### WARNING: the generated openal_api.cpp is not correct, you have to modify some lines

./mkapi.sh -I ~/android-ndk-r10e/platforms/android-19/arch-arm/usr/include/ -name egl ~/android-ndk-r10e/platforms/android-19/arch-arm/usr/include/EGL/egl.h
