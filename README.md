This is a wrapper that allows to use CPP api with FMOD and FMOD Studio assuming you have access only to the C api.<br>
In `build_sfp` folder it is provided a precompiled build for VitaSDK SoftFp usage.<br>
`fmod.c` is what has been used to generate the FMOD portion of the wrapper starting from original `fmod.hpp` header.<br>
`fmod_sfp_patch.c` is the softfp patch made by gl33ntwine for FMOD related functions having float args.<br>
FMOD Studio related functions had been manually crafted, including the softfp patches.
