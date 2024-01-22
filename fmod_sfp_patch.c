FMOD_RESULT F_API FMOD_System_SetSpeakerPosition_sfp(FMOD_SYSTEM *system, FMOD_SPEAKER speaker, float a1, float a2, FMOD_BOOL active) {
	int f1, f2;
	f1 = *(int *)&a1;
	f2 = *(int *)&a2;
	return FMOD_System_SetSpeakerPosition(system, speaker, f1, f2, active);
}

FMOD_RESULT F_API FMOD_System_Set3DSettings_sfp(FMOD_SYSTEM *system, float a1, float a2, float a3) {
	int f1, f2, f3;
	f1 = *(int *)&a1;
	f2 = *(int *)&a2;
	f3 = *(int *)&a3;
	return FMOD_System_Set3DSettings(system, f1, f2, f3);
}

FMOD_RESULT F_API FMOD_System_SetGeometrySettings_sfp(FMOD_SYSTEM *system, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_System_SetGeometrySettings(system, f1);
}

FMOD_RESULT F_API FMOD_Sound_SetDefaults_sfp(FMOD_SOUND *sound, float a1, int priority) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_Sound_SetDefaults(sound, f1, priority);
}

FMOD_RESULT F_API FMOD_Sound_Set3DMinMaxDistance_sfp(FMOD_SOUND *sound, float a1, float a2) {
	int f1, f2;
	f1 = *(int *)&a1;
	f2 = *(int *)&a2;
	return FMOD_Sound_Set3DMinMaxDistance(sound, f1, f2);
}

FMOD_RESULT F_API FMOD_Sound_Set3DConeSettings_sfp(FMOD_SOUND *sound, float a1, float a2, float a3) {
	int f1, f2, f3;
	f1 = *(int *)&a1;
	f2 = *(int *)&a2;
	f3 = *(int *)&a3;
	return FMOD_Sound_Set3DConeSettings(sound, f1, f2, f3);
}

FMOD_RESULT F_API FMOD_Sound_SetMusicChannelVolume_sfp(FMOD_SOUND *sound, int channel, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_Sound_SetMusicChannelVolume(sound, channel, f1);
}

FMOD_RESULT F_API FMOD_Channel_SetVolume_sfp(FMOD_CHANNEL *channel, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_Channel_SetVolume(channel, f1);
}

FMOD_RESULT F_API FMOD_Channel_SetPitch_sfp(FMOD_CHANNEL *channel, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_Channel_SetPitch(channel, f1);
}

FMOD_RESULT F_API FMOD_Channel_SetReverbProperties_sfp(FMOD_CHANNEL *channel, int instance, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_Channel_SetReverbProperties(channel, instance, f1);
}

FMOD_RESULT F_API FMOD_Channel_SetLowPassGain_sfp(FMOD_CHANNEL *channel, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_Channel_SetLowPassGain(channel, f1);
}

FMOD_RESULT F_API FMOD_Channel_SetPan_sfp(FMOD_CHANNEL *channel, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_Channel_SetPan(channel, f1);
}

FMOD_RESULT F_API FMOD_Channel_SetMixLevelsOutput_sfp(FMOD_CHANNEL *channel, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8) {
	int f1, f2, f3, f4, f5, f6, f7, f8;
	f1 = *(int *)&a1;
	f2 = *(int *)&a2;
	f3 = *(int *)&a3;
	f4 = *(int *)&a4;
	f5 = *(int *)&a5;
	f6 = *(int *)&a6;
	f7 = *(int *)&a7;
	f8 = *(int *)&a8;
	return FMOD_Channel_SetMixLevelsOutput(channel, f1, f2, f3, f4, f5, f6, f7, f8);
}

FMOD_RESULT F_API FMOD_Channel_AddFadePoint_sfp(FMOD_CHANNEL *channel, unsigned long long dspclock, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_Channel_AddFadePoint(channel, dspclock, f1);
}

FMOD_RESULT F_API FMOD_Channel_SetFadePointRamp_sfp(FMOD_CHANNEL *channel, unsigned long long dspclock, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_Channel_SetFadePointRamp(channel, dspclock, f1);
}

FMOD_RESULT F_API FMOD_Channel_Set3DMinMaxDistance_sfp(FMOD_CHANNEL *channel, float a1, float a2) {
	int f1, f2;
	f1 = *(int *)&a1;
	f2 = *(int *)&a2;
	return FMOD_Channel_Set3DMinMaxDistance(channel, f1, f2);
}

FMOD_RESULT F_API FMOD_Channel_Set3DConeSettings_sfp(FMOD_CHANNEL *channel, float a1, float a2, float a3) {
	int f1, f2, f3;
	f1 = *(int *)&a1;
	f2 = *(int *)&a2;
	f3 = *(int *)&a3;
	return FMOD_Channel_Set3DConeSettings(channel, f1, f2, f3);
}

FMOD_RESULT F_API FMOD_Channel_Set3DOcclusion_sfp(FMOD_CHANNEL *channel, float a1, float a2) {
	int f1, f2;
	f1 = *(int *)&a1;
	f2 = *(int *)&a2;
	return FMOD_Channel_Set3DOcclusion(channel, f1, f2);
}

FMOD_RESULT F_API FMOD_Channel_Set3DSpread_sfp(FMOD_CHANNEL *channel, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_Channel_Set3DSpread(channel, f1);
}

FMOD_RESULT F_API FMOD_Channel_Set3DLevel_sfp(FMOD_CHANNEL *channel, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_Channel_Set3DLevel(channel, f1);
}

FMOD_RESULT F_API FMOD_Channel_Set3DDopplerLevel_sfp(FMOD_CHANNEL *channel, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_Channel_Set3DDopplerLevel(channel, f1);
}

FMOD_RESULT F_API FMOD_Channel_Set3DDistanceFilter_sfp(FMOD_CHANNEL *channel, FMOD_BOOL custom, float a1, float a2) {
	int f1, f2;
	f1 = *(int *)&a1;
	f2 = *(int *)&a2;
	return FMOD_Channel_Set3DDistanceFilter(channel, custom, f1, f2);
}

FMOD_RESULT F_API FMOD_Channel_SetFrequency_sfp(FMOD_CHANNEL *channel, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_Channel_SetFrequency(channel, f1);
}

FMOD_RESULT F_API FMOD_SoundGroup_SetMuteFadeSpeed_sfp(FMOD_SOUNDGROUP *soundgroup, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_SoundGroup_SetMuteFadeSpeed(soundgroup, f1);
}

FMOD_RESULT F_API FMOD_SoundGroup_SetVolume_sfp(FMOD_SOUNDGROUP *soundgroup, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_SoundGroup_SetVolume(soundgroup, f1);
}

FMOD_RESULT F_API FMOD_DSP_SetWetDryMix_sfp(FMOD_DSP *dsp, float a1, float a2, float a3) {
	int f1, f2, f3;
	f1 = *(int *)&a1;
	f2 = *(int *)&a2;
	f3 = *(int *)&a3;
	return FMOD_DSP_SetWetDryMix(dsp, f1, f2, f3);
}

FMOD_RESULT F_API FMOD_DSP_SetParameterFloat_sfp(FMOD_DSP *dsp, int index, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_DSP_SetParameterFloat(dsp, index, f1);
}

FMOD_RESULT F_API FMOD_DSPConnection_SetMix_sfp(FMOD_DSPCONNECTION *dspconnection, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_DSPConnection_SetMix(dspconnection, f1);
}

FMOD_RESULT F_API FMOD_Geometry_AddPolygon_sfp(FMOD_GEOMETRY *geometry, float a1, float a2, FMOD_BOOL doublesided, int numvertices, const FMOD_VECTOR *vertices, int *polygonindex) {
	int f1, f2;
	f1 = *(int *)&a1;
	f2 = *(int *)&a2;
	return FMOD_Geometry_AddPolygon(geometry, f1, f2, doublesided, numvertices, vertices, polygonindex);
}

FMOD_RESULT F_API FMOD_Geometry_SetPolygonAttributes_sfp(FMOD_GEOMETRY *geometry, int index, float a1, float a2, FMOD_BOOL doublesided) {
	int f1, f2;
	f1 = *(int *)&a1;
	f2 = *(int *)&a2;
	return FMOD_Geometry_SetPolygonAttributes(geometry, index, f1, f2, doublesided);
}

FMOD_RESULT F_API FMOD_Reverb3D_Set3DAttributes_sfp(FMOD_REVERB3D *reverb3d, const FMOD_VECTOR *position, float a1, float a2) {
	int f1, f2;
	f1 = *(int *)&a1;
	f2 = *(int *)&a2;
	return FMOD_Reverb3D_Set3DAttributes(reverb3d, position, f1, f2);
}

FMOD_RESULT F_API FMOD_Sound_SetMusicSpeed_sfp(FMOD_SOUND *sound, float a1) {
	int f1;
	f1 = *(int *)&a1;
	return FMOD_Sound_SetMusicSpeed(sound, f1);
}