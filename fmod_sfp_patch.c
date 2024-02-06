__attribute__((naked)) FMOD_RESULT F_API FMOD_System_SetSpeakerPosition_sfp(FMOD_SYSTEM *system, FMOD_SPEAKER speaker, float a1, float a2, FMOD_BOOL active) {
	asm volatile(
				 // skip r0 : argument `system` is not of type float
				 // skip r1 : argument `speaker` is not of type float
				 "vmov s0, r2\n" // move r2 to s0 : argument `a1` is of type float
				 "vmov s1, r3\n" // move r3 to s1 : argument `a2` is of type float
				 "ldr r2, [sp]\n" // move sp to r2 : freed up for argument `active`
				 "b FMOD_System_SetSpeakerPosition\n" // jump to original function
				 );
}


__attribute__((naked)) FMOD_RESULT F_API FMOD_System_Set3DSettings_sfp(FMOD_SYSTEM *system, float a1, float a2, float a3) {
	asm volatile(
				 // skip r0 : argument `system` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "vmov s1, r2\n" // move r2 to s1 : argument `a2` is of type float
				 "vmov s2, r3\n" // move r3 to s2 : argument `a3` is of type float
				 "b FMOD_System_Set3DSettings\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_System_SetGeometrySettings_sfp(FMOD_SYSTEM *system, float a1) {
	asm volatile(
				 // skip r0 : argument `system` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "b FMOD_System_SetGeometrySettings\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Sound_SetDefaults_sfp(FMOD_SOUND *sound, float a1, int priority) {
	asm volatile(
				 // skip r0 : argument `sound` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "ldr r1, [r2]\n" // move r2 to r1 : freed up for argument `priority`
				 "b FMOD_Sound_SetDefaults\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Sound_Set3DMinMaxDistance_sfp(FMOD_SOUND *sound, float a1, float a2) {
	asm volatile(
				 // skip r0 : argument `sound` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "vmov s1, r2\n" // move r2 to s1 : argument `a2` is of type float
				 "b FMOD_Sound_Set3DMinMaxDistance\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Sound_Set3DConeSettings_sfp(FMOD_SOUND *sound, float a1, float a2, float a3) {
	asm volatile(
				 // skip r0 : argument `sound` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "vmov s1, r2\n" // move r2 to s1 : argument `a2` is of type float
				 "vmov s2, r3\n" // move r3 to s2 : argument `a3` is of type float
				 "b FMOD_Sound_Set3DConeSettings\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Sound_SetMusicChannelVolume_sfp(FMOD_SOUND *sound, int channel, float a1) {
	asm volatile(
				 // skip r0 : argument `sound` is not of type float
				 // skip r1 : argument `channel` is not of type float
				 "vmov s0, r2\n" // move r2 to s0 : argument `a1` is of type float
				 "b FMOD_Sound_SetMusicChannelVolume\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Channel_SetVolume_sfp(FMOD_CHANNEL *channel, float a1) {
	asm volatile(
				 // skip r0 : argument `channel` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "b FMOD_Channel_SetVolume\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Channel_SetPitch_sfp(FMOD_CHANNEL *channel, float a1) {
	asm volatile(
				 // skip r0 : argument `channel` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "b FMOD_Channel_SetPitch\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Channel_SetReverbProperties_sfp(FMOD_CHANNEL *channel, int instance, float a1) {
	asm volatile(
				 // skip r0 : argument `channel` is not of type float
				 // skip r1 : argument `instance` is not of type float
				 "vmov s0, r2\n" // move r2 to s0 : argument `a1` is of type float
				 "b FMOD_Channel_SetReverbProperties\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Channel_SetLowPassGain_sfp(FMOD_CHANNEL *channel, float a1) {
	asm volatile(
				 // skip r0 : argument `channel` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "b FMOD_Channel_SetLowPassGain\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Channel_SetPan_sfp(FMOD_CHANNEL *channel, float a1) {
	asm volatile(
				 // skip r0 : argument `channel` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "b FMOD_Channel_SetPan\n" // jump to original function
				 );
}

// AAAAA

__attribute__((naked)) FMOD_RESULT F_API FMOD_Channel_SetMixLevelsOutput_sfp(FMOD_CHANNEL *channel, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8) {
	asm volatile(
				 // skip r0 : argument `channel` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "vmov s1, r2\n" // move r2 to s1 : argument `a2` is of type float
				 "vmov s2, r3\n" // move r3 to s2 : argument `a3` is of type float

				 "ldr r1, [sp]\n" // temp. store sp in r1
				 "ldr r2, [sp, #4]\n" // temp. store sp#4 in r2
				 "ldr r3, [sp, #8]\n" // temp. store sp#8 in r3

				 "vmov s3, r1\n" // move r1 to s3 : argument `a4` is of type float
				 "vmov s4, r2\n" // move r2 to s4 : argument `a5` is of type float
				 "vmov s5, r3\n" // move r3 to s5 : argument `a6` is of type float

				 "ldr r1, [sp, #12]\n" // temp. store sp#12 in r1
				 "ldr r2, [sp, #16]\n" // temp. store sp#16 in r2

				 "vmov s6, r1\n" // move r1 to s6 : argument `a7` is of type float
				 "vmov s7, r2\n" // move r2 to s7 : argument `a8` is of type float

				 "b FMOD_Channel_SetMixLevelsOutput\n" // jump to original function
				);
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Channel_AddFadePoint_sfp(FMOD_CHANNEL *channel, unsigned long long dspclock, float a1) {
	asm volatile(
				 // skip r0 : argument `channel` is not of type float
				 // skip r1 && r2 : argument `dspclock` is not of type float
				 "vmov s0, r3\n" // move r3 to s0 : argument `a1` is of type float
				 "b FMOD_Channel_AddFadePoint\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Channel_SetFadePointRamp_sfp(FMOD_CHANNEL *channel, unsigned long long dspclock, float a1) {
	asm volatile(
				 // skip r0 : argument `channel` is not of type float
				 // skip r1 && r2 : argument `dspclock` is not of type float
				 "vmov s0, r3\n" // move r3 to s0 : argument `a1` is of type float
				 "b FMOD_Channel_SetFadePointRamp\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Channel_Set3DMinMaxDistance_sfp(FMOD_CHANNEL *channel, float a1, float a2) {
	asm volatile(
				 // skip r0 : argument `channel` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "vmov s1, r2\n" // move r2 to s1 : argument `a2` is of type float
				 "b FMOD_Channel_Set3DMinMaxDistance\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Channel_Set3DConeSettings_sfp(FMOD_CHANNEL *channel, float a1, float a2, float a3) {
	asm volatile(
				 // skip r0 : argument `channel` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "vmov s1, r2\n" // move r2 to s1 : argument `a2` is of type float
				 "vmov s2, r3\n" // move r3 to s2 : argument `a3` is of type float
				 "b FMOD_Channel_Set3DConeSettings\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Channel_Set3DOcclusion_sfp(FMOD_CHANNEL *channel, float a1, float a2) {
	asm volatile(
				 // skip r0 : argument `channel` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "vmov s1, r2\n" // move r2 to s1 : argument `a2` is of type float
				 "b FMOD_Channel_Set3DOcclusion\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Channel_Set3DSpread_sfp(FMOD_CHANNEL *channel, float a1) {
	asm volatile(
				 // skip r0 : argument `channel` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "b FMOD_Channel_Set3DSpread\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Channel_Set3DLevel_sfp(FMOD_CHANNEL *channel, float a1) {
	asm volatile(
				 // skip r0 : argument `channel` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "b FMOD_Channel_Set3DLevel\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Channel_Set3DDopplerLevel_sfp(FMOD_CHANNEL *channel, float a1) {
	asm volatile(
				 // skip r0 : argument `channel` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "b FMOD_Channel_Set3DDopplerLevel\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Channel_Set3DDistanceFilter_sfp(FMOD_CHANNEL *channel, FMOD_BOOL custom, float a1, float a2) {
	asm volatile(
				 // skip r0 : argument `channel` is not of type float
				 // skip r1 : argument `FMOD_BOOL custom` is not of type float
				 "vmov s0, r2\n" // move r2 to s0 : argument `a1` is of type float
				 "vmov s1, r3\n" // move r3 to s1 : argument `a2` is of type float
				 "b FMOD_Channel_Set3DDistanceFilter\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Channel_SetFrequency_sfp(FMOD_CHANNEL *channel, float a1) {
	asm volatile(
				 // skip r0 : argument `channel` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "b FMOD_Channel_SetFrequency\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_SoundGroup_SetMuteFadeSpeed_sfp(FMOD_SOUNDGROUP *soundgroup, float a1) {
	asm volatile(
				 // skip r0 : argument `soundgroup` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "b FMOD_SoundGroup_SetMuteFadeSpeed\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_SoundGroup_SetVolume_sfp(FMOD_SOUNDGROUP *soundgroup, float a1) {
	asm volatile(
				 // skip r0 : argument `soundgroup` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "b FMOD_SoundGroup_SetVolume\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_DSP_SetWetDryMix_sfp(FMOD_DSP *dsp, float a1, float a2, float a3) {
	asm volatile(
				 // skip r0 : argument `dsp` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "vmov s1, r2\n" // move r2 to s1 : argument `a2` is of type float
				 "vmov s2, r3\n" // move r3 to s2 : argument `a3` is of type float
				 "b FMOD_DSP_SetWetDryMix\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_DSP_SetParameterFloat_sfp(FMOD_DSP *dsp, int index, float a1) {
	asm volatile(
				 // skip r0 : argument `dsp` is not of type float
				 // skip r1 : argument `index` is not of type float
				 "vmov s0, r2\n" // move r2 to s0 : argument `a1` is of type float
				 "b FMOD_DSP_SetParameterFloat\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_DSPConnection_SetMix_sfp(FMOD_DSPCONNECTION *dspconnection, float a1) {
	asm volatile(
				// skip r0 : argument `dspconnection` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "b FMOD_DSPConnection_SetMix\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Reverb3D_Set3DAttributes_sfp(FMOD_REVERB3D *reverb3d, const FMOD_VECTOR *position, float a1, float a2) {
	asm volatile(
				 // skip r0 : argument `reverb3d` is not of type float
				 // skip r1 : argument `*position` is not of type float
				 "vmov s0, r2\n" // move r2 to s0 : argument `a1` is of type float
				 "vmov s1, r3\n" // move r3 to s1 : argument `a2` is of type float
				 "b FMOD_Reverb3D_Set3DAttributes\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Sound_SetMusicSpeed_sfp(FMOD_SOUND *sound, float a1) {
	asm volatile(
				 // skip r0 : argument `sound` is not of type float
				 "vmov s0, r1\n" // move r1 to s0 : argument `a1` is of type float
				 "b FMOD_Sound_SetMusicSpeed\n" // jump to original function
				 );
}