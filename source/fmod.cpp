#ifndef _FMOD_HPP
#define _FMOD_HPP

#include "fmod_common.h"
#include "fmod.h"
#include <vitasdk.h>

namespace FMOD
{
	class System;
	class Sound;
	class ChannelControl;
	class Channel;
	class ChannelGroup;
	class SoundGroup;
	class DSP;
	class DSPConnection;
	class Geometry;
	class Reverb3D;

	FMOD_RESULT F_API  Memory_Initialize(void *poolmem, int poollen, FMOD_MEMORY_ALLOC_CALLBACK useralloc, FMOD_MEMORY_REALLOC_CALLBACK userrealloc, FMOD_MEMORY_FREE_CALLBACK userfree, FMOD_MEMORY_TYPE memtypeflags = FMOD_MEMORY_ALL) { return FMOD_Memory_Initialize(poolmem, poollen, useralloc, userrealloc, userfree, memtypeflags); }
	FMOD_RESULT F_API  Memory_GetStats(int *currentalloced, int *maxalloced, bool blocking = true) { return FMOD_Memory_GetStats(currentalloced, maxalloced, blocking); }
	FMOD_RESULT F_API  Debug_Initialize(FMOD_DEBUG_FLAGS flags, FMOD_DEBUG_MODE mode = FMOD_DEBUG_MODE_TTY, FMOD_DEBUG_CALLBACK callback = 0, const char *filename = 0) { return FMOD_Debug_Initialize(flags, mode, callback, filename); }
	FMOD_RESULT F_API  File_SetDiskBusy(int busy) { return FMOD_File_SetDiskBusy(busy); }
	FMOD_RESULT F_API  File_GetDiskBusy(int *busy) { return FMOD_File_GetDiskBusy(busy); }

	/*
		FMOD System factory functions.
	*/
	 FMOD_RESULT F_API  System_Create		(System **system) { return FMOD_System_Create((FMOD_SYSTEM **)system); }

	/*
	   'System' API
	*/
	class System
	{
	  private:

		// Constructor made private so user cannot statically instance a System class.  System_Create must be used.
		System();
		System(const System &);

	  public:

		 FMOD_RESULT F_API  release				 ();

		// Setup functions.
		 FMOD_RESULT F_API  setOutput			   (FMOD_OUTPUTTYPE output);
		 FMOD_RESULT F_API  getOutput			   (FMOD_OUTPUTTYPE *output);
		 FMOD_RESULT F_API  getNumDrivers		   (int *numdrivers);
		 FMOD_RESULT F_API  getDriverInfo		   (int id, char *name, int namelen, FMOD_GUID *guid, int *systemrate, FMOD_SPEAKERMODE *speakermode, int *speakermodechannels);
		 FMOD_RESULT F_API  setDriver			   (int driver);
		 FMOD_RESULT F_API  getDriver			   (int *driver);
		 FMOD_RESULT F_API  setSoftwareChannels	 (int numsoftwarechannels);
		 FMOD_RESULT F_API  getSoftwareChannels	 (int *numsoftwarechannels);
		 FMOD_RESULT F_API  setSoftwareFormat	   (int samplerate, FMOD_SPEAKERMODE speakermode, int numrawspeakers);
		 FMOD_RESULT F_API  getSoftwareFormat	   (int *samplerate, FMOD_SPEAKERMODE *speakermode, int *numrawspeakers);
		 FMOD_RESULT F_API  setDSPBufferSize		(unsigned int bufferlength, int numbuffers);
		 FMOD_RESULT F_API  getDSPBufferSize		(unsigned int *bufferlength, int *numbuffers);
		 FMOD_RESULT F_API  setFileSystem		   (FMOD_FILE_OPEN_CALLBACK useropen, FMOD_FILE_CLOSE_CALLBACK userclose, FMOD_FILE_READ_CALLBACK userread, FMOD_FILE_SEEK_CALLBACK userseek, FMOD_FILE_ASYNCREAD_CALLBACK userasyncread, FMOD_FILE_ASYNCCANCEL_CALLBACK userasynccancel, int blockalign);
		 FMOD_RESULT F_API  attachFileSystem		(FMOD_FILE_OPEN_CALLBACK useropen, FMOD_FILE_CLOSE_CALLBACK userclose, FMOD_FILE_READ_CALLBACK userread, FMOD_FILE_SEEK_CALLBACK userseek);
		 FMOD_RESULT F_API  setAdvancedSettings	 (FMOD_ADVANCEDSETTINGS *settings);
		 FMOD_RESULT F_API  getAdvancedSettings	 (FMOD_ADVANCEDSETTINGS *settings);
		 FMOD_RESULT F_API  setCallback			 (FMOD_SYSTEM_CALLBACK callback, FMOD_SYSTEM_CALLBACK_TYPE callbackmask = FMOD_SYSTEM_CALLBACK_ALL);

		// Plug-in support.
		 FMOD_RESULT F_API  setPluginPath		   (const char *path);
		 FMOD_RESULT F_API  loadPlugin			  (const char *filename, unsigned int *handle, unsigned int priority = 0);
		 FMOD_RESULT F_API  unloadPlugin			(unsigned int handle);
		 FMOD_RESULT F_API  getNumNestedPlugins	 (unsigned int handle, int *count);
		 FMOD_RESULT F_API  getNestedPlugin		 (unsigned int handle, int index, unsigned int *nestedhandle);
		 FMOD_RESULT F_API  getNumPlugins		   (FMOD_PLUGINTYPE plugintype, int *numplugins);
		 FMOD_RESULT F_API  getPluginHandle		 (FMOD_PLUGINTYPE plugintype, int index, unsigned int *handle);
		 FMOD_RESULT F_API  getPluginInfo		   (unsigned int handle, FMOD_PLUGINTYPE *plugintype, char *name, int namelen, unsigned int *version);
		 FMOD_RESULT F_API  setOutputByPlugin	   (unsigned int handle);
		 FMOD_RESULT F_API  getOutputByPlugin	   (unsigned int *handle);
		 FMOD_RESULT F_API  createDSPByPlugin	   (unsigned int handle, DSP **dsp);
		 FMOD_RESULT F_API  getDSPInfoByPlugin	  (unsigned int handle, const FMOD_DSP_DESCRIPTION **description);
		 FMOD_RESULT F_API  registerCodec		   (FMOD_CODEC_DESCRIPTION *description, unsigned int *handle, unsigned int priority = 0);
		 FMOD_RESULT F_API  registerDSP			 (const FMOD_DSP_DESCRIPTION *description, unsigned int *handle);
		 FMOD_RESULT F_API  registerOutput		  (const FMOD_OUTPUT_DESCRIPTION *description, unsigned int *handle);

		// Init/Close.
		 FMOD_RESULT F_API  init					(int maxchannels, FMOD_INITFLAGS flags, void *extradriverdata);
		 FMOD_RESULT F_API  close				   ();

		// General post-init system functions.
		 FMOD_RESULT F_API  update				  ();
	   /* IMPORTANT! CALL THIS ONCE PER FRAME! */

		 FMOD_RESULT F_API  setSpeakerPosition	  (FMOD_SPEAKER speaker, float x, float y, bool active);
		 FMOD_RESULT F_API  getSpeakerPosition	  (FMOD_SPEAKER speaker, float *x, float *y, bool *active);
		 FMOD_RESULT F_API  setStreamBufferSize	 (unsigned int filebuffersize, FMOD_TIMEUNIT filebuffersizetype);
		 FMOD_RESULT F_API  getStreamBufferSize	 (unsigned int *filebuffersize, FMOD_TIMEUNIT *filebuffersizetype);
		 FMOD_RESULT F_API  set3DSettings		   (float dopplerscale, float distancefactor, float rolloffscale);
		 FMOD_RESULT F_API  get3DSettings		   (float *dopplerscale, float *distancefactor, float *rolloffscale);
		 FMOD_RESULT F_API  set3DNumListeners	   (int numlisteners);
		 FMOD_RESULT F_API  get3DNumListeners	   (int *numlisteners);
		 FMOD_RESULT F_API  set3DListenerAttributes (int listener, const FMOD_VECTOR *pos, const FMOD_VECTOR *vel, const FMOD_VECTOR *forward, const FMOD_VECTOR *up);
		 FMOD_RESULT F_API  get3DListenerAttributes (int listener, FMOD_VECTOR *pos, FMOD_VECTOR *vel, FMOD_VECTOR *forward, FMOD_VECTOR *up);
		 FMOD_RESULT F_API  set3DRolloffCallback	(FMOD_3D_ROLLOFF_CALLBACK callback);
		 FMOD_RESULT F_API  mixerSuspend			();
		 FMOD_RESULT F_API  mixerResume			 ();
		 FMOD_RESULT F_API  getDefaultMixMatrix	 (FMOD_SPEAKERMODE sourcespeakermode, FMOD_SPEAKERMODE targetspeakermode, float *matrix, int matrixhop);
		 FMOD_RESULT F_API  getSpeakerModeChannels  (FMOD_SPEAKERMODE mode, int *channels);

		// System information functions.
		 FMOD_RESULT F_API  getVersion			  (unsigned int *version);
		 FMOD_RESULT F_API  getOutputHandle		 (void **handle);
		 FMOD_RESULT F_API  getChannelsPlaying	  (int *channels, int *realchannels = 0);
		 FMOD_RESULT F_API  getCPUUsage			 (float *dsp, float *stream, float *geometry, float *update, float *total);
		 FMOD_RESULT F_API  getFileUsage			(long long *sampleBytesRead, long long *streamBytesRead, long long *otherBytesRead);
		 FMOD_RESULT F_API  getSoundRAM			 (int *currentalloced, int *maxalloced, int *total);

		// Sound/DSP/Channel/FX creation and retrieval.
		 FMOD_RESULT F_API  createSound			 (const char *name_or_data, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO *exinfo, Sound **sound);
		 FMOD_RESULT F_API  createStream			(const char *name_or_data, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO *exinfo, Sound **sound);
		 FMOD_RESULT F_API  createDSP			   (const FMOD_DSP_DESCRIPTION *description, DSP **dsp);
		 FMOD_RESULT F_API  createDSPByType		 (FMOD_DSP_TYPE type, DSP **dsp);
		 FMOD_RESULT F_API  createChannelGroup	  (const char *name, ChannelGroup **channelgroup);
		 FMOD_RESULT F_API  createSoundGroup		(const char *name, SoundGroup **soundgroup);
		 FMOD_RESULT F_API  createReverb3D		  (Reverb3D **reverb);

		 FMOD_RESULT F_API  playSound			   (Sound *sound, ChannelGroup *channelgroup, bool paused, Channel **channel);
		 FMOD_RESULT F_API  playDSP				 (DSP *dsp, ChannelGroup *channelgroup, bool paused, Channel **channel);
		 FMOD_RESULT F_API  getChannel			  (int channelid, Channel **channel);
		 FMOD_RESULT F_API  getMasterChannelGroup   (ChannelGroup **channelgroup);
		 FMOD_RESULT F_API  getMasterSoundGroup	 (SoundGroup **soundgroup);

		// Routing to ports.
		 FMOD_RESULT F_API  attachChannelGroupToPort   (FMOD_PORT_TYPE portType, FMOD_PORT_INDEX portIndex, ChannelGroup *channelgroup, bool passThru = false);
		 FMOD_RESULT F_API  detachChannelGroupFromPort (ChannelGroup *channelgroup);

		// Reverb API.
		 FMOD_RESULT F_API  setReverbProperties	 (int instance, const FMOD_REVERB_PROPERTIES *prop);
		 FMOD_RESULT F_API  getReverbProperties	 (int instance, FMOD_REVERB_PROPERTIES *prop);

		// System level DSP functionality.
		 FMOD_RESULT F_API  lockDSP				 ();
		 FMOD_RESULT F_API  unlockDSP			   ();

		// Recording API.
		 FMOD_RESULT F_API  getRecordNumDrivers	 (int *numdrivers, int *numconnected);
		 FMOD_RESULT F_API  getRecordDriverInfo	 (int id, char *name, int namelen, FMOD_GUID *guid, int *systemrate, FMOD_SPEAKERMODE *speakermode, int *speakermodechannels, FMOD_DRIVER_STATE *state);
		 FMOD_RESULT F_API  getRecordPosition	   (int id, unsigned int *position);
		 FMOD_RESULT F_API  recordStart			 (int id, Sound *sound, bool loop);
		 FMOD_RESULT F_API  recordStop			  (int id);
		 FMOD_RESULT F_API  isRecording			 (int id, bool *recording);

		// Geometry API.
		 FMOD_RESULT F_API  createGeometry		  (int maxpolygons, int maxvertices, Geometry **geometry);
		 FMOD_RESULT F_API  setGeometrySettings	 (float maxworldsize);
		 FMOD_RESULT F_API  getGeometrySettings	 (float *maxworldsize);
		 FMOD_RESULT F_API  loadGeometry			(const void *data, int datasize, Geometry **geometry);
		 FMOD_RESULT F_API  getGeometryOcclusion	(const FMOD_VECTOR *listener, const FMOD_VECTOR *source, float *direct, float *reverb);

		// Network functions.
		 FMOD_RESULT F_API  setNetworkProxy		 (const char *proxy);
		 FMOD_RESULT F_API  getNetworkProxy		 (char *proxy, int proxylen);
		 FMOD_RESULT F_API  setNetworkTimeout	   (int timeout);
		 FMOD_RESULT F_API  getNetworkTimeout	   (int *timeout);

		// Userdata set/get.
		 FMOD_RESULT F_API  setUserData			 (void *userdata);
		 FMOD_RESULT F_API  getUserData			 (void **userdata);
	};

	/*
		'Sound' API
	*/
	class Sound
	{
	  private:

		// Constructor made private so user cannot statically instance a Sound class.  Appropriate Sound creation or retrieval function must be used.
		Sound();
		Sound(const Sound &);

	  public:

		 FMOD_RESULT F_API  release				();
		 FMOD_RESULT F_API  getSystemObject		(System **system);

		// Standard sound manipulation functions.
		 FMOD_RESULT F_API  lock				   (unsigned int offset, unsigned int length, void **ptr1, void **ptr2, unsigned int *len1, unsigned int *len2);
		 FMOD_RESULT F_API  unlock				 (void *ptr1, void *ptr2, unsigned int len1, unsigned int len2);
		 FMOD_RESULT F_API  setDefaults			(float frequency, int priority);
		 FMOD_RESULT F_API  getDefaults			(float *frequency, int *priority);
		 FMOD_RESULT F_API  set3DMinMaxDistance	(float min, float max);
		 FMOD_RESULT F_API  get3DMinMaxDistance	(float *min, float *max);
		 FMOD_RESULT F_API  set3DConeSettings	  (float insideconeangle, float outsideconeangle, float outsidevolume);
		 FMOD_RESULT F_API  get3DConeSettings	  (float *insideconeangle, float *outsideconeangle, float *outsidevolume);
		 FMOD_RESULT F_API  set3DCustomRolloff	 (FMOD_VECTOR *points, int numpoints);
		 FMOD_RESULT F_API  get3DCustomRolloff	 (FMOD_VECTOR **points, int *numpoints);
		 FMOD_RESULT F_API  getSubSound			(int index, Sound **subsound);
		 FMOD_RESULT F_API  getSubSoundParent	  (Sound **parentsound);
		 FMOD_RESULT F_API  getName				(char *name, int namelen);
		 FMOD_RESULT F_API  getLength			  (unsigned int *length, FMOD_TIMEUNIT lengthtype);
		 FMOD_RESULT F_API  getFormat			  (FMOD_SOUND_TYPE *type, FMOD_SOUND_FORMAT *format, int *channels, int *bits);
		 FMOD_RESULT F_API  getNumSubSounds		(int *numsubsounds);
		 FMOD_RESULT F_API  getNumTags			 (int *numtags, int *numtagsupdated);
		 FMOD_RESULT F_API  getTag				 (const char *name, int index, FMOD_TAG *tag);
		 FMOD_RESULT F_API  getOpenState		   (FMOD_OPENSTATE *openstate, unsigned int *percentbuffered, bool *starving, bool *diskbusy);
		 FMOD_RESULT F_API  readData			   (void *buffer, unsigned int length, unsigned int *read);
		 FMOD_RESULT F_API  seekData			   (unsigned int pcm);

		 FMOD_RESULT F_API  setSoundGroup		  (SoundGroup *soundgroup);
		 FMOD_RESULT F_API  getSoundGroup		  (SoundGroup **soundgroup);

		// Synchronization point API.  These points can come from markers embedded in wav files, and can also generate channel callbacks.
		 FMOD_RESULT F_API  getNumSyncPoints	   (int *numsyncpoints);
		 FMOD_RESULT F_API  getSyncPoint		   (int index, FMOD_SYNCPOINT **point);
		 FMOD_RESULT F_API  getSyncPointInfo	   (FMOD_SYNCPOINT *point, char *name, int namelen, unsigned int *offset, FMOD_TIMEUNIT offsettype);
		 FMOD_RESULT F_API  addSyncPoint		   (unsigned int offset, FMOD_TIMEUNIT offsettype, const char *name, FMOD_SYNCPOINT **point);
		 FMOD_RESULT F_API  deleteSyncPoint		(FMOD_SYNCPOINT *point);

		// Functions also in Channel class but here they are the 'default' to save having to change it in Channel all the time.
		 FMOD_RESULT F_API  setMode				(FMOD_MODE mode);
		 FMOD_RESULT F_API  getMode				(FMOD_MODE *mode);
		 FMOD_RESULT F_API  setLoopCount		   (int loopcount);
		 FMOD_RESULT F_API  getLoopCount		   (int *loopcount);
		 FMOD_RESULT F_API  setLoopPoints		  (unsigned int loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int loopend, FMOD_TIMEUNIT loopendtype);
		 FMOD_RESULT F_API  getLoopPoints		  (unsigned int *loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int *loopend, FMOD_TIMEUNIT loopendtype);

		// For MOD/S3M/XM/IT/MID sequenced formats only.
		 FMOD_RESULT F_API  getMusicNumChannels	(int *numchannels);
		 FMOD_RESULT F_API  setMusicChannelVolume  (int channel, float volume);
		 FMOD_RESULT F_API  getMusicChannelVolume  (int channel, float *volume);
		 FMOD_RESULT F_API  setMusicSpeed		  (float speed);
		 FMOD_RESULT F_API  getMusicSpeed		  (float *speed);

		// Userdata set/get.
		 FMOD_RESULT F_API  setUserData			(void *userdata);
		 FMOD_RESULT F_API  getUserData			(void **userdata);
	};


	/*
		'ChannelControl API'.   This is a baseclassfor Channel and ChannelGroup so they can share the same functionality.  This cannot be used or instansiated explicitly.
	*/
	class ChannelControl
	{
	  private:

		// Constructor made private so user cannot statically instance a Controlclass.
		ChannelControl();
		ChannelControl(const ChannelControl &);

	  public:

		 FMOD_RESULT F_API  getSystemObject		(System **system);

		// General control functionality for Channels and ChannelGroups.
		 FMOD_RESULT F_API  stop				   ();
		 FMOD_RESULT F_API  setPaused			  (bool paused);
		 FMOD_RESULT F_API  getPaused			  (bool *paused);
		 FMOD_RESULT F_API  setVolume			  (float volume);
		 FMOD_RESULT F_API  getVolume			  (float *volume);
		 FMOD_RESULT F_API  setVolumeRamp		  (bool ramp);
		 FMOD_RESULT F_API  getVolumeRamp		  (bool *ramp);
		 FMOD_RESULT F_API  getAudibility		  (float *audibility);
		 FMOD_RESULT F_API  setPitch			   (float pitch);
		 FMOD_RESULT F_API  getPitch			   (float *pitch);
		 FMOD_RESULT F_API  setMute				(bool mute);
		 FMOD_RESULT F_API  getMute				(bool *mute);
		 FMOD_RESULT F_API  setReverbProperties	(int instance, float wet);
		 FMOD_RESULT F_API  getReverbProperties	(int instance, float *wet);
		 FMOD_RESULT F_API  setLowPassGain		 (float gain);
		 FMOD_RESULT F_API  getLowPassGain		 (float *gain);
		 FMOD_RESULT F_API  setMode				(FMOD_MODE mode);
		 FMOD_RESULT F_API  getMode				(FMOD_MODE *mode);
		 FMOD_RESULT F_API  setCallback			(FMOD_CHANNELCONTROL_CALLBACK callback);
		 FMOD_RESULT F_API  isPlaying			  (bool *isplaying);

		// Panning and level adjustment.
		// Note all 'set' functions alter a final matrix, this is why the only get function is getMixMatrix, to avoid other get functions returning incorrect/obsolete values.
		 FMOD_RESULT F_API  setPan				 (float pan);
		 FMOD_RESULT F_API  setMixLevelsOutput	 (float frontleft, float frontright, float center, float lfe, float surroundleft, float surroundright, float backleft, float backright);
		 FMOD_RESULT F_API  setMixLevelsInput	  (float *levels, int numlevels);
		 FMOD_RESULT F_API  setMixMatrix		   (float *matrix, int outchannels, int inchannels, int inchannel_hop = 0);
		 FMOD_RESULT F_API  getMixMatrix		   (float *matrix, int *outchannels, int *inchannels, int inchannel_hop = 0);

		// Clock based functionality.
		 FMOD_RESULT F_API  getDSPClock			(unsigned long long *dspclock, unsigned long long *parentclock);
		 FMOD_RESULT F_API  setDelay			   (unsigned long long dspclock_start, unsigned long long dspclock_end, bool stopchannels = true);
		 FMOD_RESULT F_API  getDelay			   (unsigned long long *dspclock_start, unsigned long long *dspclock_end, bool *stopchannels = 0);
		 FMOD_RESULT F_API  addFadePoint		   (unsigned long long dspclock, float volume);
		 FMOD_RESULT F_API  setFadePointRamp	   (unsigned long long dspclock, float volume);
		 FMOD_RESULT F_API  removeFadePoints	   (unsigned long long dspclock_start, unsigned long long dspclock_end);
		 FMOD_RESULT F_API  getFadePoints		  (unsigned int *numpoints, unsigned long long *point_dspclock, float *point_volume);

		// DSP effects.
		 FMOD_RESULT F_API  getDSP				 (int index, DSP **dsp);
		 FMOD_RESULT F_API  addDSP				 (int index, DSP *dsp);
		 FMOD_RESULT F_API  removeDSP			  (DSP *dsp);
		 FMOD_RESULT F_API  getNumDSPs			 (int *numdsps);
		 FMOD_RESULT F_API  setDSPIndex			(DSP *dsp, int index);
		 FMOD_RESULT F_API  getDSPIndex			(DSP *dsp, int *index);

		// 3D functionality.
		 FMOD_RESULT F_API  set3DAttributes		(const FMOD_VECTOR *pos, const FMOD_VECTOR *vel, const FMOD_VECTOR *alt_pan_pos = 0);
		 FMOD_RESULT F_API  get3DAttributes		(FMOD_VECTOR *pos, FMOD_VECTOR *vel, FMOD_VECTOR *alt_pan_pos = 0);
		 FMOD_RESULT F_API  set3DMinMaxDistance	(float mindistance, float maxdistance);
		 FMOD_RESULT F_API  get3DMinMaxDistance	(float *mindistance, float *maxdistance);
		 FMOD_RESULT F_API  set3DConeSettings	  (float insideconeangle, float outsideconeangle, float outsidevolume);
		 FMOD_RESULT F_API  get3DConeSettings	  (float *insideconeangle, float *outsideconeangle, float *outsidevolume);
		 FMOD_RESULT F_API  set3DConeOrientation   (FMOD_VECTOR *orientation);
		 FMOD_RESULT F_API  get3DConeOrientation   (FMOD_VECTOR *orientation);
		 FMOD_RESULT F_API  set3DCustomRolloff	 (FMOD_VECTOR *points, int numpoints);
		 FMOD_RESULT F_API  get3DCustomRolloff	 (FMOD_VECTOR **points, int *numpoints);
		 FMOD_RESULT F_API  set3DOcclusion		 (float directocclusion, float reverbocclusion);
		 FMOD_RESULT F_API  get3DOcclusion		 (float *directocclusion, float *reverbocclusion);
		 FMOD_RESULT F_API  set3DSpread			(float angle);
		 FMOD_RESULT F_API  get3DSpread			(float *angle);
		 FMOD_RESULT F_API  set3DLevel			 (float level);
		 FMOD_RESULT F_API  get3DLevel			 (float *level);
		 FMOD_RESULT F_API  set3DDopplerLevel	  (float level);
		 FMOD_RESULT F_API  get3DDopplerLevel	  (float *level);
		 FMOD_RESULT F_API  set3DDistanceFilter	(bool custom, float customLevel, float centerFreq);
		 FMOD_RESULT F_API  get3DDistanceFilter	(bool *custom, float *customLevel, float *centerFreq);

		// Userdata set/get.
		 FMOD_RESULT F_API  setUserData			(void *userdata);
		 FMOD_RESULT F_API  getUserData			(void **userdata);
	};

	/*
		'Channel' API.
	*/
	class Channel : public ChannelControl
	{
	  private:

		// Constructor made private so user cannot statically instance a Channel class.  Appropriate Channel creation or retrieval function must be used.
		Channel();
		Channel(const Channel &);

	  public:

		// Channel specific control functionality.
		 FMOD_RESULT F_API  setFrequency		   (float frequency);
		 FMOD_RESULT F_API  getFrequency		   (float *frequency);
		 FMOD_RESULT F_API  setPriority			(int priority);
		 FMOD_RESULT F_API  getPriority			(int *priority);
		 FMOD_RESULT F_API  setPosition			(unsigned int position, FMOD_TIMEUNIT postype);
		 FMOD_RESULT F_API  getPosition			(unsigned int *position, FMOD_TIMEUNIT postype);
		 FMOD_RESULT F_API  setChannelGroup		(ChannelGroup *channelgroup);
		 FMOD_RESULT F_API  getChannelGroup		(ChannelGroup **channelgroup);
		 FMOD_RESULT F_API  setLoopCount		   (int loopcount);
		 FMOD_RESULT F_API  getLoopCount		   (int *loopcount);
		 FMOD_RESULT F_API  setLoopPoints		  (unsigned int loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int loopend, FMOD_TIMEUNIT loopendtype);
		 FMOD_RESULT F_API  getLoopPoints		  (unsigned int *loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int *loopend, FMOD_TIMEUNIT loopendtype);

		// Information only functions.
		 FMOD_RESULT F_API  isVirtual			  (bool *isvirtual);
		 FMOD_RESULT F_API  getCurrentSound		(Sound **sound);
		 FMOD_RESULT F_API  getIndex			   (int *index);
	};

	/*
		'ChannelGroup' API
	*/
	class ChannelGroup : public ChannelControl
	{
	  private:

		// Constructor made private so user cannot statically instance a ChannelGroup class.  Appropriate ChannelGroup creation or retrieval function must be used.
		ChannelGroup();
		ChannelGroup(const ChannelGroup &);

	  public:

		 FMOD_RESULT F_API  release				 ();

		// Nested channel groups.
		 FMOD_RESULT F_API  addGroup				(ChannelGroup *group, bool propagatedspclock = true, DSPConnection **connection = 0);
		 FMOD_RESULT F_API  getNumGroups			(int *numgroups);
		 FMOD_RESULT F_API  getGroup				(int index, ChannelGroup **group);
		 FMOD_RESULT F_API  getParentGroup		  (ChannelGroup **group);

		// Information only functions.
		 FMOD_RESULT F_API  getName				 (char *name, int namelen);
		 FMOD_RESULT F_API  getNumChannels		  (int *numchannels);
		 FMOD_RESULT F_API  getChannel			  (int index, Channel **channel);
	};

	/*
		'SoundGroup' API
	*/
	class SoundGroup
	{
	  private:

		// Constructor made private so user cannot statically instance a SoundGroup class.  Appropriate SoundGroup creation or retrieval function must be used.
		SoundGroup();
		SoundGroup(const SoundGroup &);

	  public:

		 FMOD_RESULT F_API  release				();
		 FMOD_RESULT F_API  getSystemObject		(System **system);

		// SoundGroup control functions.
		 FMOD_RESULT F_API  setMaxAudible		  (int maxaudible);
		 FMOD_RESULT F_API  getMaxAudible		  (int *maxaudible);
		 FMOD_RESULT F_API  setMaxAudibleBehavior  (FMOD_SOUNDGROUP_BEHAVIOR behavior);
		 FMOD_RESULT F_API  getMaxAudibleBehavior  (FMOD_SOUNDGROUP_BEHAVIOR *behavior);
		 FMOD_RESULT F_API  setMuteFadeSpeed	   (float speed);
		 FMOD_RESULT F_API  getMuteFadeSpeed	   (float *speed);
		 FMOD_RESULT F_API  setVolume			  (float volume);
		 FMOD_RESULT F_API  getVolume			  (float *volume);
		 FMOD_RESULT F_API  stop				   ();

		// Information only functions.
		 FMOD_RESULT F_API  getName				(char *name, int namelen);
		 FMOD_RESULT F_API  getNumSounds		   (int *numsounds);
		 FMOD_RESULT F_API  getSound			   (int index, Sound **sound);
		 FMOD_RESULT F_API  getNumPlaying		  (int *numplaying);

		// Userdata set/get.
		 FMOD_RESULT F_API  setUserData			(void *userdata);
		 FMOD_RESULT F_API  getUserData			(void **userdata);
	};

	/*
		'DSP' API
	*/
	class DSP
	{
	  private:

		// Constructor made private so user cannot statically instance a DSP class.  Appropriate DSP creation or retrieval function must be used.
		DSP();
		DSP(const DSP &);

	  public:

		 FMOD_RESULT F_API  release				();
		 FMOD_RESULT F_API  getSystemObject		(System **system);

		// Connection / disconnection / input and output enumeration.
		 FMOD_RESULT F_API  addInput			   (DSP *input, DSPConnection **connection = 0, FMOD_DSPCONNECTION_TYPE type = FMOD_DSPCONNECTION_TYPE_STANDARD);
		 FMOD_RESULT F_API  disconnectFrom		 (DSP *target, DSPConnection *connection = 0);
		 FMOD_RESULT F_API  disconnectAll		  (bool inputs, bool outputs);
		 FMOD_RESULT F_API  getNumInputs		   (int *numinputs);
		 FMOD_RESULT F_API  getNumOutputs		  (int *numoutputs);
		 FMOD_RESULT F_API  getInput			   (int index, DSP **input, DSPConnection **inputconnection);
		 FMOD_RESULT F_API  getOutput			  (int index, DSP **output, DSPConnection **outputconnection);

		// DSP unit control.
		 FMOD_RESULT F_API  setActive			  (bool active);
		 FMOD_RESULT F_API  getActive			  (bool *active);
		 FMOD_RESULT F_API  setBypass			  (bool bypass);
		 FMOD_RESULT F_API  getBypass			  (bool *bypass);
		 FMOD_RESULT F_API  setWetDryMix		   (float prewet, float postwet, float dry);
		 FMOD_RESULT F_API  getWetDryMix		   (float *prewet, float *postwet, float *dry);
		 FMOD_RESULT F_API  setChannelFormat	   (FMOD_CHANNELMASK channelmask, int numchannels, FMOD_SPEAKERMODE source_speakermode);
		 FMOD_RESULT F_API  getChannelFormat	   (FMOD_CHANNELMASK *channelmask, int *numchannels, FMOD_SPEAKERMODE *source_speakermode);
		 FMOD_RESULT F_API  getOutputChannelFormat (FMOD_CHANNELMASK inmask, int inchannels, FMOD_SPEAKERMODE inspeakermode, FMOD_CHANNELMASK *outmask, int *outchannels, FMOD_SPEAKERMODE *outspeakermode);
		 FMOD_RESULT F_API  reset				  ();

		// DSP parameter control.
		 FMOD_RESULT F_API  setParameterFloat	  (int index, float value);
		 FMOD_RESULT F_API  setParameterInt		(int index, int value);
		 FMOD_RESULT F_API  setParameterBool	   (int index, bool value);
		 FMOD_RESULT F_API  setParameterData	   (int index, void *data, unsigned int length);
		 FMOD_RESULT F_API  getParameterFloat	  (int index, float *value, char *valuestr, int valuestrlen);
		 FMOD_RESULT F_API  getParameterInt		(int index, int *value, char *valuestr, int valuestrlen);
		 FMOD_RESULT F_API  getParameterBool	   (int index, bool *value, char *valuestr, int valuestrlen);
		 FMOD_RESULT F_API  getParameterData	   (int index, void **data, unsigned int *length, char *valuestr, int valuestrlen);
		 FMOD_RESULT F_API  getNumParameters	   (int *numparams);
		 FMOD_RESULT F_API  getParameterInfo	   (int index, FMOD_DSP_PARAMETER_DESC **desc);
		 FMOD_RESULT F_API  getDataParameterIndex  (int datatype, int *index);
		 FMOD_RESULT F_API  showConfigDialog	   (void *hwnd, bool show);

		// DSP attributes.
		 FMOD_RESULT F_API  getInfo				(char *name, unsigned int *version, int *channels, int *configwidth, int *configheight);
		 FMOD_RESULT F_API  getType				(FMOD_DSP_TYPE *type);
		 FMOD_RESULT F_API  getIdle				(bool *idle);

		// Userdata set/get.
		 FMOD_RESULT F_API  setUserData			(void *userdata);
		 FMOD_RESULT F_API  getUserData			(void **userdata);

		// Metering.
		 FMOD_RESULT F_API  setMeteringEnabled	 (bool inputEnabled, bool outputEnabled);
		 FMOD_RESULT F_API  getMeteringEnabled	 (bool *inputEnabled, bool *outputEnabled);
		 FMOD_RESULT F_API  getMeteringInfo		(FMOD_DSP_METERING_INFO *inputInfo, FMOD_DSP_METERING_INFO *outputInfo);
	};


	/*
		'DSPConnection' API
	*/
	class DSPConnection
	{
	  private:

		// Constructor made private so user cannot statically instance a DSPConnection class.  Appropriate DSPConnection creation or retrieval function must be used.
		DSPConnection();
		DSPConnection(const DSPConnection &);

	  public:

		 FMOD_RESULT F_API  getInput			  (DSP **input);
		 FMOD_RESULT F_API  getOutput			 (DSP **output);
		 FMOD_RESULT F_API  setMix				(float volume);
		 FMOD_RESULT F_API  getMix				(float *volume);
		 FMOD_RESULT F_API  setMixMatrix		  (float *matrix, int outchannels, int inchannels, int inchannel_hop = 0);
		 FMOD_RESULT F_API  getMixMatrix		  (float *matrix, int *outchannels, int *inchannels, int inchannel_hop = 0);
		 FMOD_RESULT F_API  getType			   (FMOD_DSPCONNECTION_TYPE *type);

		// Userdata set/get.
		 FMOD_RESULT F_API  setUserData		   (void *userdata);
		 FMOD_RESULT F_API  getUserData		   (void **userdata);
	};


	/*
		'Geometry' API
	*/
	class Geometry
	{
	  private:

		// Constructor made private so user cannot statically instance a Geometry class.  Appropriate Geometry creation or retrieval function must be used.
		Geometry();
		Geometry(const Geometry &);

	  public:

		 FMOD_RESULT F_API  release				();

		// Polygon manipulation.
		 FMOD_RESULT F_API  addPolygon			 (float directocclusion, float reverbocclusion, bool doublesided, int numvertices, const FMOD_VECTOR *vertices, int *polygonindex);
		 FMOD_RESULT F_API  getNumPolygons		 (int *numpolygons);
		 FMOD_RESULT F_API  getMaxPolygons		 (int *maxpolygons, int *maxvertices);
		 FMOD_RESULT F_API  getPolygonNumVertices  (int index, int *numvertices);
		 FMOD_RESULT F_API  setPolygonVertex	   (int index, int vertexindex, const FMOD_VECTOR *vertex);
		 FMOD_RESULT F_API  getPolygonVertex	   (int index, int vertexindex, FMOD_VECTOR *vertex);
		 FMOD_RESULT F_API  setPolygonAttributes   (int index, float directocclusion, float reverbocclusion, bool doublesided);
		 FMOD_RESULT F_API  getPolygonAttributes   (int index, float *directocclusion, float *reverbocclusion, bool *doublesided);

		// Object manipulation.
		 FMOD_RESULT F_API  setActive			  (bool active);
		 FMOD_RESULT F_API  getActive			  (bool *active);
		 FMOD_RESULT F_API  setRotation			(const FMOD_VECTOR *forward, const FMOD_VECTOR *up);
		 FMOD_RESULT F_API  getRotation			(FMOD_VECTOR *forward, FMOD_VECTOR *up);
		 FMOD_RESULT F_API  setPosition			(const FMOD_VECTOR *position);
		 FMOD_RESULT F_API  getPosition			(FMOD_VECTOR *position);
		 FMOD_RESULT F_API  setScale			   (const FMOD_VECTOR *scale);
		 FMOD_RESULT F_API  getScale			   (FMOD_VECTOR *scale);
		 FMOD_RESULT F_API  save				   (void *data, int *datasize);

		// Userdata set/get.
		 FMOD_RESULT F_API  setUserData			(void *userdata);
		 FMOD_RESULT F_API  getUserData			(void **userdata);
	};


	/*
		'Reverb' API
	*/
	class Reverb3D
	{
	  private:

		// Constructor made private so user cannot statically instance a Reverb3D class.  Appropriate Reverb creation or retrieval function must be used.
		Reverb3D();
		Reverb3D(const Reverb3D &);

	  public:

		 FMOD_RESULT F_API  release				();

		// Reverb manipulation.
		 FMOD_RESULT F_API  set3DAttributes		(const FMOD_VECTOR *position, float mindistance, float maxdistance);
		 FMOD_RESULT F_API  get3DAttributes		(FMOD_VECTOR *position, float *mindistance,float *maxdistance);
		 FMOD_RESULT F_API  setProperties		  (const FMOD_REVERB_PROPERTIES *properties);
		 FMOD_RESULT F_API  getProperties		  (FMOD_REVERB_PROPERTIES *properties);
		 FMOD_RESULT F_API  setActive			  (bool active);
		 FMOD_RESULT F_API  getActive			  (bool *active);

		// Userdata set/get.
		 FMOD_RESULT F_API  setUserData			(void *userdata);
		 FMOD_RESULT F_API  getUserData			(void **userdata);
	};
}

#endif

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

FMOD_RESULT F_API FMOD::System::release				 () { return FMOD_System_Release((FMOD_SYSTEM *)this); }
FMOD_RESULT F_API FMOD::System::setOutput			   (FMOD_OUTPUTTYPE output) { return FMOD_System_SetOutput((FMOD_SYSTEM *)this, output); }
FMOD_RESULT F_API FMOD::System::getOutput			   (FMOD_OUTPUTTYPE *output) { return FMOD_System_GetOutput((FMOD_SYSTEM *)this, output); }
FMOD_RESULT F_API FMOD::System::getNumDrivers		   (int *numdrivers) { return FMOD_System_GetNumDrivers((FMOD_SYSTEM *)this, numdrivers); }
FMOD_RESULT F_API FMOD::System::getDriverInfo		   (int id, char *name, int namelen, FMOD_GUID *guid, int *systemrate, FMOD_SPEAKERMODE *speakermode, int *speakermodechannels) { return FMOD_System_GetDriverInfo((FMOD_SYSTEM *)this, id, name, namelen, guid, systemrate, speakermode, speakermodechannels); }
FMOD_RESULT F_API FMOD::System::setDriver			   (int driver) { return FMOD_System_SetDriver((FMOD_SYSTEM *)this, driver); }
FMOD_RESULT F_API FMOD::System::getDriver			   (int *driver) { return FMOD_System_GetDriver((FMOD_SYSTEM *)this, driver); }
FMOD_RESULT F_API FMOD::System::setSoftwareChannels	 (int numsoftwarechannels) { return FMOD_System_SetSoftwareChannels((FMOD_SYSTEM *)this, numsoftwarechannels); }
FMOD_RESULT F_API FMOD::System::getSoftwareChannels	 (int *numsoftwarechannels) { return FMOD_System_GetSoftwareChannels((FMOD_SYSTEM *)this, numsoftwarechannels); }
FMOD_RESULT F_API FMOD::System::setSoftwareFormat	   (int samplerate, FMOD_SPEAKERMODE speakermode, int numrawspeakers) { return FMOD_System_SetSoftwareFormat((FMOD_SYSTEM *)this, samplerate, speakermode, numrawspeakers); }
FMOD_RESULT F_API FMOD::System::getSoftwareFormat	   (int *samplerate, FMOD_SPEAKERMODE *speakermode, int *numrawspeakers) { return FMOD_System_GetSoftwareFormat((FMOD_SYSTEM *)this, samplerate, speakermode, numrawspeakers); }
FMOD_RESULT F_API FMOD::System::setDSPBufferSize		(unsigned int bufferlength, int numbuffers) { return FMOD_System_SetDSPBufferSize((FMOD_SYSTEM *)this, bufferlength, numbuffers); }
FMOD_RESULT F_API FMOD::System::getDSPBufferSize		(unsigned int *bufferlength, int *numbuffers) { return FMOD_System_GetDSPBufferSize((FMOD_SYSTEM *)this, bufferlength, numbuffers); }
FMOD_RESULT F_API FMOD::System::setFileSystem		   (FMOD_FILE_OPEN_CALLBACK useropen, FMOD_FILE_CLOSE_CALLBACK userclose, FMOD_FILE_READ_CALLBACK userread, FMOD_FILE_SEEK_CALLBACK userseek, FMOD_FILE_ASYNCREAD_CALLBACK userasyncread, FMOD_FILE_ASYNCCANCEL_CALLBACK userasynccancel, int blockalign) { return FMOD_System_SetFileSystem((FMOD_SYSTEM *)this, useropen, userclose, userread, userseek, userasyncread, userasynccancel, blockalign); }
FMOD_RESULT F_API FMOD::System::attachFileSystem		(FMOD_FILE_OPEN_CALLBACK useropen, FMOD_FILE_CLOSE_CALLBACK userclose, FMOD_FILE_READ_CALLBACK userread, FMOD_FILE_SEEK_CALLBACK userseek) { return FMOD_System_AttachFileSystem((FMOD_SYSTEM *)this, useropen, userclose, userread, userseek); }
FMOD_RESULT F_API FMOD::System::setAdvancedSettings	 (FMOD_ADVANCEDSETTINGS *settings) { return FMOD_System_SetAdvancedSettings((FMOD_SYSTEM *)this, settings); }
FMOD_RESULT F_API FMOD::System::getAdvancedSettings	 (FMOD_ADVANCEDSETTINGS *settings) { return FMOD_System_GetAdvancedSettings((FMOD_SYSTEM *)this, settings); }
FMOD_RESULT F_API FMOD::System::setCallback			 (FMOD_SYSTEM_CALLBACK callback, FMOD_SYSTEM_CALLBACK_TYPE callbackmask ) { return FMOD_System_SetCallback((FMOD_SYSTEM *)this, callback, callbackmask); }
FMOD_RESULT F_API FMOD::System::setPluginPath		   (const char *path) { return FMOD_System_SetPluginPath((FMOD_SYSTEM *)this, path); }
FMOD_RESULT F_API FMOD::System::loadPlugin			  (const char *filename, unsigned int *handle, unsigned int priority ) { return FMOD_System_LoadPlugin((FMOD_SYSTEM *)this, filename, handle, priority); }
FMOD_RESULT F_API FMOD::System::unloadPlugin			(unsigned int handle) { return FMOD_System_UnloadPlugin((FMOD_SYSTEM *)this, handle); }
FMOD_RESULT F_API FMOD::System::getNumNestedPlugins	 (unsigned int handle, int *count) { return FMOD_System_GetNumNestedPlugins((FMOD_SYSTEM *)this, handle, count); }
FMOD_RESULT F_API FMOD::System::getNestedPlugin		 (unsigned int handle, int index, unsigned int *nestedhandle) { return FMOD_System_GetNestedPlugin((FMOD_SYSTEM *)this, handle, index, nestedhandle); }
FMOD_RESULT F_API FMOD::System::getNumPlugins		   (FMOD_PLUGINTYPE plugintype, int *numplugins) { return FMOD_System_GetNumPlugins((FMOD_SYSTEM *)this, plugintype, numplugins); }
FMOD_RESULT F_API FMOD::System::getPluginHandle		 (FMOD_PLUGINTYPE plugintype, int index, unsigned int *handle) { return FMOD_System_GetPluginHandle((FMOD_SYSTEM *)this, plugintype, index, handle); }
FMOD_RESULT F_API FMOD::System::getPluginInfo		   (unsigned int handle, FMOD_PLUGINTYPE *plugintype, char *name, int namelen, unsigned int *version) { return FMOD_System_GetPluginInfo((FMOD_SYSTEM *)this, handle, plugintype, name, namelen, version); }
FMOD_RESULT F_API FMOD::System::setOutputByPlugin	   (unsigned int handle) { return FMOD_System_SetOutputByPlugin((FMOD_SYSTEM *)this, handle); }
FMOD_RESULT F_API FMOD::System::getOutputByPlugin	   (unsigned int *handle) { return FMOD_System_GetOutputByPlugin((FMOD_SYSTEM *)this, handle); }
FMOD_RESULT F_API FMOD::System::createDSPByPlugin	   (unsigned int handle, DSP **dsp) { return FMOD_System_CreateDSPByPlugin((FMOD_SYSTEM *)this, handle, (FMOD_DSP **)dsp); }
FMOD_RESULT F_API FMOD::System::getDSPInfoByPlugin	  (unsigned int handle, const FMOD_DSP_DESCRIPTION **description) { return FMOD_System_GetDSPInfoByPlugin((FMOD_SYSTEM *)this, handle, description); }
FMOD_RESULT F_API FMOD::System::registerCodec		   (FMOD_CODEC_DESCRIPTION *description, unsigned int *handle, unsigned int priority ) { return FMOD_System_RegisterCodec((FMOD_SYSTEM *)this, description, handle, priority); }
FMOD_RESULT F_API FMOD::System::registerDSP			 (const FMOD_DSP_DESCRIPTION *description, unsigned int *handle) { return FMOD_System_RegisterDSP((FMOD_SYSTEM *)this, description, handle); }
FMOD_RESULT F_API FMOD::System::registerOutput		  (const FMOD_OUTPUT_DESCRIPTION *description, unsigned int *handle) { return FMOD_System_RegisterOutput((FMOD_SYSTEM *)this, description, handle); }
FMOD_RESULT F_API FMOD::System::init					(int maxchannels, FMOD_INITFLAGS flags, void *extradriverdata) { return FMOD_System_Init((FMOD_SYSTEM *)this, maxchannels, flags, extradriverdata); }
FMOD_RESULT F_API FMOD::System::close				   () { return FMOD_System_Close((FMOD_SYSTEM *)this); }
FMOD_RESULT F_API FMOD::System::update				  () { return FMOD_System_Update((FMOD_SYSTEM *)this); }
FMOD_RESULT F_API FMOD::System::setSpeakerPosition	  (FMOD_SPEAKER speaker, float x, float y, bool active) { return FMOD_System_SetSpeakerPosition_sfp((FMOD_SYSTEM *)this, speaker, x, y, active); }
FMOD_RESULT F_API FMOD::System::getSpeakerPosition	  (FMOD_SPEAKER speaker, float *x, float *y, bool *active) { return FMOD_System_GetSpeakerPosition((FMOD_SYSTEM *)this, speaker, x, y, (FMOD_BOOL *)active); }
FMOD_RESULT F_API FMOD::System::setStreamBufferSize	 (unsigned int filebuffersize, FMOD_TIMEUNIT filebuffersizetype) { return FMOD_System_SetStreamBufferSize((FMOD_SYSTEM *)this, filebuffersize, filebuffersizetype); }
FMOD_RESULT F_API FMOD::System::getStreamBufferSize	 (unsigned int *filebuffersize, FMOD_TIMEUNIT *filebuffersizetype) { return FMOD_System_GetStreamBufferSize((FMOD_SYSTEM *)this, filebuffersize, filebuffersizetype); }
FMOD_RESULT F_API FMOD::System::set3DSettings		   (float dopplerscale, float distancefactor, float rolloffscale) { return FMOD_System_Set3DSettings_sfp((FMOD_SYSTEM *)this, dopplerscale, distancefactor, rolloffscale); }
FMOD_RESULT F_API FMOD::System::get3DSettings		   (float *dopplerscale, float *distancefactor, float *rolloffscale) { return FMOD_System_Get3DSettings((FMOD_SYSTEM *)this, dopplerscale, distancefactor, rolloffscale); }
FMOD_RESULT F_API FMOD::System::set3DNumListeners	   (int numlisteners) { return FMOD_System_Set3DNumListeners((FMOD_SYSTEM *)this, numlisteners); }
FMOD_RESULT F_API FMOD::System::get3DNumListeners	   (int *numlisteners) { return FMOD_System_Get3DNumListeners((FMOD_SYSTEM *)this, numlisteners); }
FMOD_RESULT F_API FMOD::System::set3DListenerAttributes (int listener, const FMOD_VECTOR *pos, const FMOD_VECTOR *vel, const FMOD_VECTOR *forward, const FMOD_VECTOR *up) { return FMOD_System_Set3DListenerAttributes((FMOD_SYSTEM *)this, listener, pos, vel, forward, up); }
FMOD_RESULT F_API FMOD::System::get3DListenerAttributes (int listener, FMOD_VECTOR *pos, FMOD_VECTOR *vel, FMOD_VECTOR *forward, FMOD_VECTOR *up) { return FMOD_System_Get3DListenerAttributes((FMOD_SYSTEM *)this, listener, pos, vel, forward, up); }
FMOD_RESULT F_API FMOD::System::set3DRolloffCallback	(FMOD_3D_ROLLOFF_CALLBACK callback) { return FMOD_System_Set3DRolloffCallback((FMOD_SYSTEM *)this, callback); }
FMOD_RESULT F_API FMOD::System::mixerSuspend			() { return FMOD_System_MixerSuspend((FMOD_SYSTEM *)this); }
FMOD_RESULT F_API FMOD::System::mixerResume			 () { return FMOD_System_MixerResume((FMOD_SYSTEM *)this); }
FMOD_RESULT F_API FMOD::System::getDefaultMixMatrix	 (FMOD_SPEAKERMODE sourcespeakermode, FMOD_SPEAKERMODE targetspeakermode, float *matrix, int matrixhop) { return FMOD_System_GetDefaultMixMatrix((FMOD_SYSTEM *)this, sourcespeakermode, targetspeakermode, matrix, matrixhop); }
FMOD_RESULT F_API FMOD::System::getSpeakerModeChannels  (FMOD_SPEAKERMODE mode, int *channels) { return FMOD_System_GetSpeakerModeChannels((FMOD_SYSTEM *)this, mode, channels); }
FMOD_RESULT F_API FMOD::System::getVersion			  (unsigned int *version) { return FMOD_System_GetVersion((FMOD_SYSTEM *)this, version); }
FMOD_RESULT F_API FMOD::System::getOutputHandle		 (void **handle) { return FMOD_System_GetOutputHandle((FMOD_SYSTEM *)this, handle); }
FMOD_RESULT F_API FMOD::System::getChannelsPlaying	  (int *channels, int *realchannels ) { return FMOD_System_GetChannelsPlaying((FMOD_SYSTEM *)this, channels, realchannels); }
FMOD_RESULT F_API FMOD::System::getCPUUsage			 (float *dsp, float *stream, float *geometry, float *update, float *total) { return FMOD_System_GetCPUUsage((FMOD_SYSTEM *)this, dsp, stream, geometry, update, total); }
FMOD_RESULT F_API FMOD::System::getFileUsage			(long long *sampleBytesRead, long long *streamBytesRead, long long *otherBytesRead) { return FMOD_System_GetFileUsage((FMOD_SYSTEM *)this, sampleBytesRead, streamBytesRead, otherBytesRead); }
FMOD_RESULT F_API FMOD::System::getSoundRAM			 (int *currentalloced, int *maxalloced, int *total) { return FMOD_System_GetSoundRAM((FMOD_SYSTEM *)this, currentalloced, maxalloced, total); }
FMOD_RESULT F_API FMOD::System::createSound			 (const char *name_or_data, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO *exinfo, Sound **sound) { return FMOD_System_CreateSound((FMOD_SYSTEM *)this, name_or_data, mode, exinfo, (FMOD_SOUND **)sound); }
FMOD_RESULT F_API FMOD::System::createStream			(const char *name_or_data, FMOD_MODE mode, FMOD_CREATESOUNDEXINFO *exinfo, Sound **sound) { return FMOD_System_CreateStream((FMOD_SYSTEM *)this, name_or_data, mode, exinfo, (FMOD_SOUND **)sound); }
FMOD_RESULT F_API FMOD::System::createDSP			   (const FMOD_DSP_DESCRIPTION *description, DSP **dsp) { return FMOD_System_CreateDSP((FMOD_SYSTEM *)this, description, (FMOD_DSP **)dsp); }
FMOD_RESULT F_API FMOD::System::createDSPByType		 (FMOD_DSP_TYPE type, DSP **dsp) { return FMOD_System_CreateDSPByType((FMOD_SYSTEM *)this, type, (FMOD_DSP **)dsp); }
FMOD_RESULT F_API FMOD::System::createChannelGroup	  (const char *name, ChannelGroup **channelgroup) { return FMOD_System_CreateChannelGroup((FMOD_SYSTEM *)this, name, (FMOD_CHANNELGROUP **)channelgroup); }
FMOD_RESULT F_API FMOD::System::createSoundGroup		(const char *name, SoundGroup **soundgroup) { return FMOD_System_CreateSoundGroup((FMOD_SYSTEM *)this, name, (FMOD_SOUNDGROUP **)soundgroup); }
FMOD_RESULT F_API FMOD::System::createReverb3D		  (Reverb3D **reverb) { return FMOD_System_CreateReverb3D((FMOD_SYSTEM *)this, (FMOD_REVERB3D **)reverb); }
FMOD_RESULT F_API FMOD::System::playSound			   (Sound *sound, ChannelGroup *channelgroup, bool paused, Channel **channel) { return FMOD_System_PlaySound((FMOD_SYSTEM *)this, (FMOD_SOUND *)sound, (FMOD_CHANNELGROUP *)channelgroup, paused, (FMOD_CHANNEL **)channel); }
FMOD_RESULT F_API FMOD::System::playDSP				 (DSP *dsp, ChannelGroup *channelgroup, bool paused, Channel **channel) { return FMOD_System_PlayDSP((FMOD_SYSTEM *)this, (FMOD_DSP *)dsp, (FMOD_CHANNELGROUP *)channelgroup, paused, (FMOD_CHANNEL **)channel); }
FMOD_RESULT F_API FMOD::System::getChannel			  (int channelid, Channel **channel) { return FMOD_System_GetChannel((FMOD_SYSTEM *)this, channelid, (FMOD_CHANNEL **)channel); }
FMOD_RESULT F_API FMOD::System::getMasterChannelGroup   (ChannelGroup **channelgroup) { return FMOD_System_GetMasterChannelGroup((FMOD_SYSTEM *)this, (FMOD_CHANNELGROUP **)channelgroup); }
FMOD_RESULT F_API FMOD::System::getMasterSoundGroup	 (SoundGroup **soundgroup) { return FMOD_System_GetMasterSoundGroup((FMOD_SYSTEM *)this, (FMOD_SOUNDGROUP **)soundgroup); }
FMOD_RESULT F_API FMOD::System::attachChannelGroupToPort   (FMOD_PORT_TYPE portType, FMOD_PORT_INDEX portIndex, ChannelGroup *channelgroup, bool passThru ) { return FMOD_System_AttachChannelGroupToPort((FMOD_SYSTEM *)this, portType, portIndex, (FMOD_CHANNELGROUP *)channelgroup, passThru); }
FMOD_RESULT F_API FMOD::System::detachChannelGroupFromPort (ChannelGroup *channelgroup) { return FMOD_System_DetachChannelGroupFromPort((FMOD_SYSTEM *)this, (FMOD_CHANNELGROUP *)channelgroup); }
FMOD_RESULT F_API FMOD::System::setReverbProperties	 (int instance, const FMOD_REVERB_PROPERTIES *prop) { return FMOD_System_SetReverbProperties((FMOD_SYSTEM *)this, instance, prop); }
FMOD_RESULT F_API FMOD::System::getReverbProperties	 (int instance, FMOD_REVERB_PROPERTIES *prop) { return FMOD_System_GetReverbProperties((FMOD_SYSTEM *)this, instance, prop); }
FMOD_RESULT F_API FMOD::System::lockDSP				 () { return FMOD_System_LockDSP((FMOD_SYSTEM *)this); }
FMOD_RESULT F_API FMOD::System::unlockDSP			   () { return FMOD_System_UnlockDSP((FMOD_SYSTEM *)this); }
FMOD_RESULT F_API FMOD::System::getRecordNumDrivers	 (int *numdrivers, int *numconnected) { return FMOD_System_GetRecordNumDrivers((FMOD_SYSTEM *)this, numdrivers, numconnected); }
FMOD_RESULT F_API FMOD::System::getRecordDriverInfo	 (int id, char *name, int namelen, FMOD_GUID *guid, int *systemrate, FMOD_SPEAKERMODE *speakermode, int *speakermodechannels, FMOD_DRIVER_STATE *state) { return FMOD_System_GetRecordDriverInfo((FMOD_SYSTEM *)this, id, name, namelen, guid, systemrate, speakermode, speakermodechannels, state); }
FMOD_RESULT F_API FMOD::System::getRecordPosition	   (int id, unsigned int *position) { return FMOD_System_GetRecordPosition((FMOD_SYSTEM *)this, id, position); }
FMOD_RESULT F_API FMOD::System::recordStart			 (int id, Sound *sound, bool loop) { return FMOD_System_RecordStart((FMOD_SYSTEM *)this, id, (FMOD_SOUND *)sound, loop); }
FMOD_RESULT F_API FMOD::System::recordStop			  (int id) { return FMOD_System_RecordStop((FMOD_SYSTEM *)this, id); }
FMOD_RESULT F_API FMOD::System::isRecording			 (int id, bool *recording) { return FMOD_System_IsRecording((FMOD_SYSTEM *)this, id, (FMOD_BOOL *)recording); }
FMOD_RESULT F_API FMOD::System::createGeometry		  (int maxpolygons, int maxvertices, Geometry **geometry) { return FMOD_System_CreateGeometry((FMOD_SYSTEM *)this, maxpolygons, maxvertices, (FMOD_GEOMETRY **)geometry); }
FMOD_RESULT F_API FMOD::System::setGeometrySettings	 (float maxworldsize) { return FMOD_System_SetGeometrySettings_sfp((FMOD_SYSTEM *)this, maxworldsize); }
FMOD_RESULT F_API FMOD::System::getGeometrySettings	 (float *maxworldsize) { return FMOD_System_GetGeometrySettings((FMOD_SYSTEM *)this, maxworldsize); }
FMOD_RESULT F_API FMOD::System::loadGeometry			(const void *data, int datasize, Geometry **geometry) { return FMOD_System_LoadGeometry((FMOD_SYSTEM *)this, data, datasize, (FMOD_GEOMETRY **)geometry); }
FMOD_RESULT F_API FMOD::System::getGeometryOcclusion	(const FMOD_VECTOR *listener, const FMOD_VECTOR *source, float *direct, float *reverb) { return FMOD_System_GetGeometryOcclusion((FMOD_SYSTEM *)this, listener, source, direct, reverb); }
FMOD_RESULT F_API FMOD::System::setNetworkProxy		 (const char *proxy) { return FMOD_System_SetNetworkProxy((FMOD_SYSTEM *)this, proxy); }
FMOD_RESULT F_API FMOD::System::getNetworkProxy		 (char *proxy, int proxylen) { return FMOD_System_GetNetworkProxy((FMOD_SYSTEM *)this, proxy, proxylen); }
FMOD_RESULT F_API FMOD::System::setNetworkTimeout	   (int timeout) { return FMOD_System_SetNetworkTimeout((FMOD_SYSTEM *)this, timeout); }
FMOD_RESULT F_API FMOD::System::getNetworkTimeout	   (int *timeout) { return FMOD_System_GetNetworkTimeout((FMOD_SYSTEM *)this, timeout); }
FMOD_RESULT F_API FMOD::System::setUserData			 (void *userdata) { return FMOD_System_SetUserData((FMOD_SYSTEM *)this, userdata); }
FMOD_RESULT F_API FMOD::System::getUserData			 (void **userdata) { return FMOD_System_GetUserData((FMOD_SYSTEM *)this, userdata); }
FMOD_RESULT F_API FMOD::Sound::release				() { return FMOD_Sound_Release((FMOD_SOUND *)this); }
FMOD_RESULT F_API FMOD::Sound::getSystemObject		(System **system) { return FMOD_Sound_GetSystemObject((FMOD_SOUND *)this, (FMOD_SYSTEM **)system); }
FMOD_RESULT F_API FMOD::Sound::lock				   (unsigned int offset, unsigned int length, void **ptr1, void **ptr2, unsigned int *len1, unsigned int *len2) { return FMOD_Sound_Lock((FMOD_SOUND *)this, offset, length, ptr1, ptr2, len1, len2); }
FMOD_RESULT F_API FMOD::Sound::unlock				 (void *ptr1, void *ptr2, unsigned int len1, unsigned int len2) { return FMOD_Sound_Unlock((FMOD_SOUND *)this, ptr1, ptr2, len1, len2); }
FMOD_RESULT F_API FMOD::Sound::setDefaults			(float frequency, int priority) { return FMOD_Sound_SetDefaults_sfp((FMOD_SOUND *)this, frequency, priority); }
FMOD_RESULT F_API FMOD::Sound::getDefaults			(float *frequency, int *priority) { return FMOD_Sound_GetDefaults((FMOD_SOUND *)this, frequency, priority); }
FMOD_RESULT F_API FMOD::Sound::set3DMinMaxDistance	(float min, float max) { return FMOD_Sound_Set3DMinMaxDistance_sfp((FMOD_SOUND *)this, min, max); }
FMOD_RESULT F_API FMOD::Sound::get3DMinMaxDistance	(float *min, float *max) { return FMOD_Sound_Get3DMinMaxDistance((FMOD_SOUND *)this, min, max); }
FMOD_RESULT F_API FMOD::Sound::set3DConeSettings	  (float insideconeangle, float outsideconeangle, float outsidevolume) { return FMOD_Sound_Set3DConeSettings_sfp((FMOD_SOUND *)this, insideconeangle, outsideconeangle, outsidevolume); }
FMOD_RESULT F_API FMOD::Sound::get3DConeSettings	  (float *insideconeangle, float *outsideconeangle, float *outsidevolume) { return FMOD_Sound_Get3DConeSettings((FMOD_SOUND *)this, insideconeangle, outsideconeangle, outsidevolume); }
FMOD_RESULT F_API FMOD::Sound::set3DCustomRolloff	 (FMOD_VECTOR *points, int numpoints) { return FMOD_Sound_Set3DCustomRolloff((FMOD_SOUND *)this, points, numpoints); }
FMOD_RESULT F_API FMOD::Sound::get3DCustomRolloff	 (FMOD_VECTOR **points, int *numpoints) { return FMOD_Sound_Get3DCustomRolloff((FMOD_SOUND *)this, points, numpoints); }
FMOD_RESULT F_API FMOD::Sound::getSubSound			(int index, Sound **subsound) { return FMOD_Sound_GetSubSound((FMOD_SOUND *)this, index, (FMOD_SOUND **)subsound); }
FMOD_RESULT F_API FMOD::Sound::getSubSoundParent	  (Sound **parentsound) { return FMOD_Sound_GetSubSoundParent((FMOD_SOUND *)this, (FMOD_SOUND **)parentsound); }
FMOD_RESULT F_API FMOD::Sound::getName				(char *name, int namelen) { return FMOD_Sound_GetName((FMOD_SOUND *)this, name, namelen); }
FMOD_RESULT F_API FMOD::Sound::getLength			  (unsigned int *length, FMOD_TIMEUNIT lengthtype) { return FMOD_Sound_GetLength((FMOD_SOUND *)this, length, lengthtype); }
FMOD_RESULT F_API FMOD::Sound::getFormat			  (FMOD_SOUND_TYPE *type, FMOD_SOUND_FORMAT *format, int *channels, int *bits) { return FMOD_Sound_GetFormat((FMOD_SOUND *)this, type, format, channels, bits); }
FMOD_RESULT F_API FMOD::Sound::getNumSubSounds		(int *numsubsounds) { return FMOD_Sound_GetNumSubSounds((FMOD_SOUND *)this, numsubsounds); }
FMOD_RESULT F_API FMOD::Sound::getNumTags			 (int *numtags, int *numtagsupdated) { return FMOD_Sound_GetNumTags((FMOD_SOUND *)this, numtags, numtagsupdated); }
FMOD_RESULT F_API FMOD::Sound::getTag				 (const char *name, int index, FMOD_TAG *tag) { return FMOD_Sound_GetTag((FMOD_SOUND *)this, name, index, tag); }
FMOD_RESULT F_API FMOD::Sound::getOpenState		   (FMOD_OPENSTATE *openstate, unsigned int *percentbuffered, bool *starving, bool *diskbusy) { return FMOD_Sound_GetOpenState((FMOD_SOUND *)this, openstate, percentbuffered, (FMOD_BOOL *)starving, (FMOD_BOOL *)diskbusy); }
FMOD_RESULT F_API FMOD::Sound::readData			   (void *buffer, unsigned int length, unsigned int *read) { return FMOD_Sound_ReadData((FMOD_SOUND *)this, buffer, length, read); }
FMOD_RESULT F_API FMOD::Sound::seekData			   (unsigned int pcm) { return FMOD_Sound_SeekData((FMOD_SOUND *)this, pcm); }
FMOD_RESULT F_API FMOD::Sound::setSoundGroup		  (SoundGroup *soundgroup) { return FMOD_Sound_SetSoundGroup((FMOD_SOUND *)this, (FMOD_SOUNDGROUP *)soundgroup); }
FMOD_RESULT F_API FMOD::Sound::getSoundGroup		  (SoundGroup **soundgroup) { return FMOD_Sound_GetSoundGroup((FMOD_SOUND *)this, (FMOD_SOUNDGROUP **)soundgroup); }
FMOD_RESULT F_API FMOD::Sound::getNumSyncPoints	   (int *numsyncpoints) { return FMOD_Sound_GetNumSyncPoints((FMOD_SOUND *)this, numsyncpoints); }
FMOD_RESULT F_API FMOD::Sound::getSyncPoint		   (int index, FMOD_SYNCPOINT **point) { return FMOD_Sound_GetSyncPoint((FMOD_SOUND *)this, index, point); }
FMOD_RESULT F_API FMOD::Sound::getSyncPointInfo	   (FMOD_SYNCPOINT *point, char *name, int namelen, unsigned int *offset, FMOD_TIMEUNIT offsettype) { return FMOD_Sound_GetSyncPointInfo((FMOD_SOUND *)this, point, name, namelen, offset, offsettype); }
FMOD_RESULT F_API FMOD::Sound::addSyncPoint		   (unsigned int offset, FMOD_TIMEUNIT offsettype, const char *name, FMOD_SYNCPOINT **point) { return FMOD_Sound_AddSyncPoint((FMOD_SOUND *)this, offset, offsettype, name, point); }
FMOD_RESULT F_API FMOD::Sound::deleteSyncPoint		(FMOD_SYNCPOINT *point) { return FMOD_Sound_DeleteSyncPoint((FMOD_SOUND *)this, point); }
FMOD_RESULT F_API FMOD::Sound::setMode				(FMOD_MODE mode) { return FMOD_Sound_SetMode((FMOD_SOUND *)this, mode); }
FMOD_RESULT F_API FMOD::Sound::getMode				(FMOD_MODE *mode) { return FMOD_Sound_GetMode((FMOD_SOUND *)this, mode); }
FMOD_RESULT F_API FMOD::Sound::setLoopCount		   (int loopcount) { return FMOD_Sound_SetLoopCount((FMOD_SOUND *)this, loopcount); }
FMOD_RESULT F_API FMOD::Sound::getLoopCount		   (int *loopcount) { return FMOD_Sound_GetLoopCount((FMOD_SOUND *)this, loopcount); }
FMOD_RESULT F_API FMOD::Sound::setLoopPoints		  (unsigned int loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int loopend, FMOD_TIMEUNIT loopendtype) { return FMOD_Sound_SetLoopPoints((FMOD_SOUND *)this, loopstart, loopstarttype, loopend, loopendtype); }
FMOD_RESULT F_API FMOD::Sound::getLoopPoints		  (unsigned int *loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int *loopend, FMOD_TIMEUNIT loopendtype) { return FMOD_Sound_GetLoopPoints((FMOD_SOUND *)this, loopstart, loopstarttype, loopend, loopendtype); }
FMOD_RESULT F_API FMOD::Sound::getMusicNumChannels	(int *numchannels) { return FMOD_Sound_GetMusicNumChannels((FMOD_SOUND *)this, numchannels); }
FMOD_RESULT F_API FMOD::Sound::setMusicChannelVolume  (int channel, float volume) { return FMOD_Sound_SetMusicChannelVolume_sfp((FMOD_SOUND *)this, channel, volume); }
FMOD_RESULT F_API FMOD::Sound::getMusicChannelVolume  (int channel, float *volume) { return FMOD_Sound_GetMusicChannelVolume((FMOD_SOUND *)this, channel, volume); }
FMOD_RESULT F_API FMOD::Sound::setMusicSpeed		  (float speed) { return FMOD_Sound_SetMusicSpeed_sfp((FMOD_SOUND *)this, speed); }
FMOD_RESULT F_API FMOD::Sound::getMusicSpeed		  (float *speed) { return FMOD_Sound_GetMusicSpeed((FMOD_SOUND *)this, speed); }
FMOD_RESULT F_API FMOD::Sound::setUserData			(void *userdata) { return FMOD_Sound_SetUserData((FMOD_SOUND *)this, userdata); }
FMOD_RESULT F_API FMOD::Sound::getUserData			(void **userdata) { return FMOD_Sound_GetUserData((FMOD_SOUND *)this, userdata); }
FMOD_RESULT F_API FMOD::ChannelControl::getSystemObject		(System **system) { return FMOD_Channel_GetSystemObject((FMOD_CHANNEL *)this, (FMOD_SYSTEM **)system); }
FMOD_RESULT F_API FMOD::ChannelControl::stop				   () { return FMOD_Channel_Stop((FMOD_CHANNEL *)this); }
FMOD_RESULT F_API FMOD::ChannelControl::setPaused			  (bool paused) { return FMOD_Channel_SetPaused((FMOD_CHANNEL *)this, paused); }
FMOD_RESULT F_API FMOD::ChannelControl::getPaused			  (bool *paused) { return FMOD_Channel_GetPaused((FMOD_CHANNEL *)this, (FMOD_BOOL *)paused); }
FMOD_RESULT F_API FMOD::ChannelControl::setVolume			  (float volume) { return FMOD_Channel_SetVolume_sfp((FMOD_CHANNEL *)this, volume); }
FMOD_RESULT F_API FMOD::ChannelControl::getVolume			  (float *volume) { return FMOD_Channel_GetVolume((FMOD_CHANNEL *)this, volume); }
FMOD_RESULT F_API FMOD::ChannelControl::setVolumeRamp		  (bool ramp) { return FMOD_Channel_SetVolumeRamp((FMOD_CHANNEL *)this, ramp); }
FMOD_RESULT F_API FMOD::ChannelControl::getVolumeRamp		  (bool *ramp) { return FMOD_Channel_GetVolumeRamp((FMOD_CHANNEL *)this, (FMOD_BOOL *)ramp); }
FMOD_RESULT F_API FMOD::ChannelControl::getAudibility		  (float *audibility) { return FMOD_Channel_GetAudibility((FMOD_CHANNEL *)this, audibility); }
FMOD_RESULT F_API FMOD::ChannelControl::setPitch			   (float pitch) { return FMOD_Channel_SetPitch_sfp((FMOD_CHANNEL *)this, pitch); }
FMOD_RESULT F_API FMOD::ChannelControl::getPitch			   (float *pitch) { return FMOD_Channel_GetPitch((FMOD_CHANNEL *)this, pitch); }
FMOD_RESULT F_API FMOD::ChannelControl::setMute				(bool mute) { return FMOD_Channel_SetMute((FMOD_CHANNEL *)this, mute); }
FMOD_RESULT F_API FMOD::ChannelControl::getMute				(bool *mute) { return FMOD_Channel_GetMute((FMOD_CHANNEL *)this, (FMOD_BOOL *)mute); }
FMOD_RESULT F_API FMOD::ChannelControl::setReverbProperties	(int instance, float wet) { return FMOD_Channel_SetReverbProperties_sfp((FMOD_CHANNEL *)this, instance, wet); }
FMOD_RESULT F_API FMOD::ChannelControl::getReverbProperties	(int instance, float *wet) { return FMOD_Channel_GetReverbProperties((FMOD_CHANNEL *)this, instance, wet); }
FMOD_RESULT F_API FMOD::ChannelControl::setLowPassGain		 (float gain) { return FMOD_Channel_SetLowPassGain_sfp((FMOD_CHANNEL *)this, gain); }
FMOD_RESULT F_API FMOD::ChannelControl::getLowPassGain		 (float *gain) { return FMOD_Channel_GetLowPassGain((FMOD_CHANNEL *)this, gain); }
FMOD_RESULT F_API FMOD::ChannelControl::setMode				(FMOD_MODE mode) { return FMOD_Channel_SetMode((FMOD_CHANNEL *)this, mode); }
FMOD_RESULT F_API FMOD::ChannelControl::getMode				(FMOD_MODE *mode) { return FMOD_Channel_GetMode((FMOD_CHANNEL *)this, mode); }
FMOD_RESULT F_API FMOD::ChannelControl::setCallback			(FMOD_CHANNELCONTROL_CALLBACK callback) { return FMOD_Channel_SetCallback((FMOD_CHANNEL *)this, callback); }
FMOD_RESULT F_API FMOD::ChannelControl::isPlaying			  (bool *isplaying) { int r; FMOD_RESULT res = FMOD_Channel_IsPlaying((FMOD_CHANNEL *)this, (FMOD_BOOL *)&r); *(uint8_t *)isplaying = r; return res; }
FMOD_RESULT F_API FMOD::ChannelControl::setPan				 (float pan) { return FMOD_Channel_SetPan_sfp((FMOD_CHANNEL *)this, pan); }
FMOD_RESULT F_API FMOD::ChannelControl::setMixLevelsOutput	 (float frontleft, float frontright, float center, float lfe, float surroundleft, float surroundright, float backleft, float backright) { return FMOD_Channel_SetMixLevelsOutput_sfp((FMOD_CHANNEL *)this, frontleft, frontright, center, lfe, surroundleft, surroundright, backleft, backright); }
FMOD_RESULT F_API FMOD::ChannelControl::setMixLevelsInput	  (float *levels, int numlevels) { return FMOD_Channel_SetMixLevelsInput((FMOD_CHANNEL *)this, levels, numlevels); }
FMOD_RESULT F_API FMOD::ChannelControl::setMixMatrix		   (float *matrix, int outchannels, int inchannels, int inchannel_hop ) { return FMOD_Channel_SetMixMatrix((FMOD_CHANNEL *)this, matrix, outchannels, inchannels, inchannel_hop); }
FMOD_RESULT F_API FMOD::ChannelControl::getMixMatrix		   (float *matrix, int *outchannels, int *inchannels, int inchannel_hop ) { return FMOD_Channel_GetMixMatrix((FMOD_CHANNEL *)this, matrix, outchannels, inchannels, inchannel_hop); }
FMOD_RESULT F_API FMOD::ChannelControl::getDSPClock			(unsigned long long *dspclock, unsigned long long *parentclock) { return FMOD_Channel_GetDSPClock((FMOD_CHANNEL *)this, dspclock, parentclock); }
FMOD_RESULT F_API FMOD::ChannelControl::setDelay			   (unsigned long long dspclock_start, unsigned long long dspclock_end, bool stopchannels ) { return FMOD_Channel_SetDelay((FMOD_CHANNEL *)this, dspclock_start, dspclock_end, stopchannels); }
FMOD_RESULT F_API FMOD::ChannelControl::getDelay			   (unsigned long long *dspclock_start, unsigned long long *dspclock_end, bool *stopchannels ) { return FMOD_Channel_GetDelay((FMOD_CHANNEL *)this, dspclock_start, dspclock_end, (FMOD_BOOL *)stopchannels); }
FMOD_RESULT F_API FMOD::ChannelControl::addFadePoint		   (unsigned long long dspclock, float volume) { return FMOD_Channel_AddFadePoint_sfp((FMOD_CHANNEL *)this, dspclock, volume); }
FMOD_RESULT F_API FMOD::ChannelControl::setFadePointRamp	   (unsigned long long dspclock, float volume) { return FMOD_Channel_SetFadePointRamp_sfp((FMOD_CHANNEL *)this, dspclock, volume); }
FMOD_RESULT F_API FMOD::ChannelControl::removeFadePoints	   (unsigned long long dspclock_start, unsigned long long dspclock_end) { return FMOD_Channel_RemoveFadePoints((FMOD_CHANNEL *)this, dspclock_start, dspclock_end); }
FMOD_RESULT F_API FMOD::ChannelControl::getFadePoints		  (unsigned int *numpoints, unsigned long long *point_dspclock, float *point_volume) { return FMOD_Channel_GetFadePoints((FMOD_CHANNEL *)this, numpoints, point_dspclock, point_volume); }
FMOD_RESULT F_API FMOD::ChannelControl::getDSP				 (int index, DSP **dsp) { return FMOD_Channel_GetDSP((FMOD_CHANNEL *)this, index, (FMOD_DSP **)dsp); }
FMOD_RESULT F_API FMOD::ChannelControl::addDSP				 (int index, DSP *dsp) { return FMOD_Channel_AddDSP((FMOD_CHANNEL *)this, index, (FMOD_DSP *)dsp); }
FMOD_RESULT F_API FMOD::ChannelControl::removeDSP			  (DSP *dsp) { return FMOD_Channel_RemoveDSP((FMOD_CHANNEL *)this, (FMOD_DSP *)dsp); }
FMOD_RESULT F_API FMOD::ChannelControl::getNumDSPs			 (int *numdsps) { return FMOD_Channel_GetNumDSPs((FMOD_CHANNEL *)this, numdsps); }
FMOD_RESULT F_API FMOD::ChannelControl::setDSPIndex			(DSP *dsp, int index) { return FMOD_Channel_SetDSPIndex((FMOD_CHANNEL *)this, (FMOD_DSP *)dsp, index); }
FMOD_RESULT F_API FMOD::ChannelControl::getDSPIndex			(DSP *dsp, int *index) { return FMOD_Channel_GetDSPIndex((FMOD_CHANNEL *)this, (FMOD_DSP *)dsp, index); }
FMOD_RESULT F_API FMOD::ChannelControl::set3DAttributes		(const FMOD_VECTOR *pos, const FMOD_VECTOR *vel, const FMOD_VECTOR *alt_pan_pos ) { return FMOD_Channel_Set3DAttributes((FMOD_CHANNEL *)this, pos, vel, alt_pan_pos); }
FMOD_RESULT F_API FMOD::ChannelControl::get3DAttributes		(FMOD_VECTOR *pos, FMOD_VECTOR *vel, FMOD_VECTOR *alt_pan_pos ) { return FMOD_Channel_Get3DAttributes((FMOD_CHANNEL *)this, pos, vel, alt_pan_pos); }
FMOD_RESULT F_API FMOD::ChannelControl::set3DMinMaxDistance	(float mindistance, float maxdistance) { return FMOD_Channel_Set3DMinMaxDistance_sfp((FMOD_CHANNEL *)this, mindistance, maxdistance); }
FMOD_RESULT F_API FMOD::ChannelControl::get3DMinMaxDistance	(float *mindistance, float *maxdistance) { return FMOD_Channel_Get3DMinMaxDistance((FMOD_CHANNEL *)this, mindistance, maxdistance); }
FMOD_RESULT F_API FMOD::ChannelControl::set3DConeSettings	  (float insideconeangle, float outsideconeangle, float outsidevolume) { return FMOD_Channel_Set3DConeSettings_sfp((FMOD_CHANNEL *)this, insideconeangle, outsideconeangle, outsidevolume); }
FMOD_RESULT F_API FMOD::ChannelControl::get3DConeSettings	  (float *insideconeangle, float *outsideconeangle, float *outsidevolume) { return FMOD_Channel_Get3DConeSettings((FMOD_CHANNEL *)this, insideconeangle, outsideconeangle, outsidevolume); }
FMOD_RESULT F_API FMOD::ChannelControl::set3DConeOrientation   (FMOD_VECTOR *orientation) { return FMOD_Channel_Set3DConeOrientation((FMOD_CHANNEL *)this, orientation); }
FMOD_RESULT F_API FMOD::ChannelControl::get3DConeOrientation   (FMOD_VECTOR *orientation) { return FMOD_Channel_Get3DConeOrientation((FMOD_CHANNEL *)this, orientation); }
FMOD_RESULT F_API FMOD::ChannelControl::set3DCustomRolloff	 (FMOD_VECTOR *points, int numpoints) { return FMOD_Channel_Set3DCustomRolloff((FMOD_CHANNEL *)this, points, numpoints); }
FMOD_RESULT F_API FMOD::ChannelControl::get3DCustomRolloff	 (FMOD_VECTOR **points, int *numpoints) { return FMOD_Channel_Get3DCustomRolloff((FMOD_CHANNEL *)this, points, numpoints); }
FMOD_RESULT F_API FMOD::ChannelControl::set3DOcclusion		 (float directocclusion, float reverbocclusion) { return FMOD_Channel_Set3DOcclusion_sfp((FMOD_CHANNEL *)this, directocclusion, reverbocclusion); }
FMOD_RESULT F_API FMOD::ChannelControl::get3DOcclusion		 (float *directocclusion, float *reverbocclusion) { return FMOD_Channel_Get3DOcclusion((FMOD_CHANNEL *)this, directocclusion, reverbocclusion); }
FMOD_RESULT F_API FMOD::ChannelControl::set3DSpread			(float angle) { return FMOD_Channel_Set3DSpread_sfp((FMOD_CHANNEL *)this, angle); }
FMOD_RESULT F_API FMOD::ChannelControl::get3DSpread			(float *angle) { return FMOD_Channel_Get3DSpread((FMOD_CHANNEL *)this, angle); }
FMOD_RESULT F_API FMOD::ChannelControl::set3DLevel			 (float level) { return FMOD_Channel_Set3DLevel_sfp((FMOD_CHANNEL *)this, level); }
FMOD_RESULT F_API FMOD::ChannelControl::get3DLevel			 (float *level) { return FMOD_Channel_Get3DLevel((FMOD_CHANNEL *)this, level); }
FMOD_RESULT F_API FMOD::ChannelControl::set3DDopplerLevel	  (float level) { return FMOD_Channel_Set3DDopplerLevel_sfp((FMOD_CHANNEL *)this, level); }
FMOD_RESULT F_API FMOD::ChannelControl::get3DDopplerLevel	  (float *level) { return FMOD_Channel_Get3DDopplerLevel((FMOD_CHANNEL *)this, level); }
FMOD_RESULT F_API FMOD::ChannelControl::set3DDistanceFilter	(bool custom, float customLevel, float centerFreq) { return FMOD_Channel_Set3DDistanceFilter_sfp((FMOD_CHANNEL *)this, custom, customLevel, centerFreq); }
FMOD_RESULT F_API FMOD::ChannelControl::get3DDistanceFilter	(bool *custom, float *customLevel, float *centerFreq) { return FMOD_Channel_Get3DDistanceFilter((FMOD_CHANNEL *)this, (FMOD_BOOL *)custom, customLevel, centerFreq); }
FMOD_RESULT F_API FMOD::ChannelControl::setUserData			(void *userdata) { return FMOD_Channel_SetUserData((FMOD_CHANNEL *)this, userdata); }
FMOD_RESULT F_API FMOD::ChannelControl::getUserData			(void **userdata) { return FMOD_Channel_GetUserData((FMOD_CHANNEL *)this, userdata); }
FMOD_RESULT F_API FMOD::Channel::setFrequency		   (float frequency) { return FMOD_Channel_SetFrequency_sfp((FMOD_CHANNEL *)this, frequency); }
FMOD_RESULT F_API FMOD::Channel::getFrequency		   (float *frequency) { return FMOD_Channel_GetFrequency((FMOD_CHANNEL *)this, frequency); }
FMOD_RESULT F_API FMOD::Channel::setPriority			(int priority) { return FMOD_Channel_SetPriority((FMOD_CHANNEL *)this, priority); }
FMOD_RESULT F_API FMOD::Channel::getPriority			(int *priority) { return FMOD_Channel_GetPriority((FMOD_CHANNEL *)this, priority); }
FMOD_RESULT F_API FMOD::Channel::setPosition			(unsigned int position, FMOD_TIMEUNIT postype) { return FMOD_Channel_SetPosition((FMOD_CHANNEL *)this, position, postype); }
FMOD_RESULT F_API FMOD::Channel::getPosition			(unsigned int *position, FMOD_TIMEUNIT postype) { return FMOD_Channel_GetPosition((FMOD_CHANNEL *)this, position, postype); }
FMOD_RESULT F_API FMOD::Channel::setChannelGroup		(ChannelGroup *channelgroup) { return FMOD_Channel_SetChannelGroup((FMOD_CHANNEL *)this, (FMOD_CHANNELGROUP *)channelgroup); }
FMOD_RESULT F_API FMOD::Channel::getChannelGroup		(ChannelGroup **channelgroup) { return FMOD_Channel_GetChannelGroup((FMOD_CHANNEL *)this, (FMOD_CHANNELGROUP **)channelgroup); }
FMOD_RESULT F_API FMOD::Channel::setLoopCount		   (int loopcount) { return FMOD_Channel_SetLoopCount((FMOD_CHANNEL *)this, loopcount); }
FMOD_RESULT F_API FMOD::Channel::getLoopCount		   (int *loopcount) { return FMOD_Channel_GetLoopCount((FMOD_CHANNEL *)this, loopcount); }
FMOD_RESULT F_API FMOD::Channel::setLoopPoints		  (unsigned int loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int loopend, FMOD_TIMEUNIT loopendtype) { return FMOD_Channel_SetLoopPoints((FMOD_CHANNEL *)this, loopstart, loopstarttype, loopend, loopendtype); }
FMOD_RESULT F_API FMOD::Channel::getLoopPoints		  (unsigned int *loopstart, FMOD_TIMEUNIT loopstarttype, unsigned int *loopend, FMOD_TIMEUNIT loopendtype) { return FMOD_Channel_GetLoopPoints((FMOD_CHANNEL *)this, loopstart, loopstarttype, loopend, loopendtype); }
FMOD_RESULT F_API FMOD::Channel::isVirtual			  (bool *isvirtual) { return FMOD_Channel_IsVirtual((FMOD_CHANNEL *)this, (FMOD_BOOL *)isvirtual); }
FMOD_RESULT F_API FMOD::Channel::getCurrentSound		(Sound **sound) { return FMOD_Channel_GetCurrentSound((FMOD_CHANNEL *)this, (FMOD_SOUND **)sound); }
FMOD_RESULT F_API FMOD::Channel::getIndex			   (int *index) { return FMOD_Channel_GetIndex((FMOD_CHANNEL *)this, index); }
FMOD_RESULT F_API FMOD::ChannelGroup::release				 () { return FMOD_ChannelGroup_Release((FMOD_CHANNELGROUP *)this); }
FMOD_RESULT F_API FMOD::ChannelGroup::addGroup				(ChannelGroup *group, bool propagatedspclock , DSPConnection **connection ) { return FMOD_ChannelGroup_AddGroup((FMOD_CHANNELGROUP *)this, (FMOD_CHANNELGROUP *)group, propagatedspclock, (FMOD_DSPCONNECTION **)connection); }
FMOD_RESULT F_API FMOD::ChannelGroup::getNumGroups			(int *numgroups) { return FMOD_ChannelGroup_GetNumGroups((FMOD_CHANNELGROUP *)this, numgroups); }
FMOD_RESULT F_API FMOD::ChannelGroup::getGroup				(int index, ChannelGroup **group) { return FMOD_ChannelGroup_GetGroup((FMOD_CHANNELGROUP *)this, index, (FMOD_CHANNELGROUP **)group); }
FMOD_RESULT F_API FMOD::ChannelGroup::getParentGroup		  (ChannelGroup **group) { return FMOD_ChannelGroup_GetParentGroup((FMOD_CHANNELGROUP *)this, (FMOD_CHANNELGROUP **)group); }
FMOD_RESULT F_API FMOD::ChannelGroup::getName				 (char *name, int namelen) { return FMOD_ChannelGroup_GetName((FMOD_CHANNELGROUP *)this, name, namelen); }
FMOD_RESULT F_API FMOD::ChannelGroup::getNumChannels		  (int *numchannels) { return FMOD_ChannelGroup_GetNumChannels((FMOD_CHANNELGROUP *)this, numchannels); }
FMOD_RESULT F_API FMOD::ChannelGroup::getChannel			  (int index, Channel **channel) { return FMOD_ChannelGroup_GetChannel((FMOD_CHANNELGROUP *)this, index, (FMOD_CHANNEL **)channel); }
FMOD_RESULT F_API FMOD::SoundGroup::release				() { return FMOD_SoundGroup_Release((FMOD_SOUNDGROUP *)this); }
FMOD_RESULT F_API FMOD::SoundGroup::getSystemObject		(System **system) { return FMOD_SoundGroup_GetSystemObject((FMOD_SOUNDGROUP *)this, (FMOD_SYSTEM **)system); }
FMOD_RESULT F_API FMOD::SoundGroup::setMaxAudible		  (int maxaudible) { return FMOD_SoundGroup_SetMaxAudible((FMOD_SOUNDGROUP *)this, maxaudible); }
FMOD_RESULT F_API FMOD::SoundGroup::getMaxAudible		  (int *maxaudible) { return FMOD_SoundGroup_GetMaxAudible((FMOD_SOUNDGROUP *)this, maxaudible); }
FMOD_RESULT F_API FMOD::SoundGroup::setMaxAudibleBehavior  (FMOD_SOUNDGROUP_BEHAVIOR behavior) { return FMOD_SoundGroup_SetMaxAudibleBehavior((FMOD_SOUNDGROUP *)this, behavior); }
FMOD_RESULT F_API FMOD::SoundGroup::getMaxAudibleBehavior  (FMOD_SOUNDGROUP_BEHAVIOR *behavior) { return FMOD_SoundGroup_GetMaxAudibleBehavior((FMOD_SOUNDGROUP *)this, behavior); }
FMOD_RESULT F_API FMOD::SoundGroup::setMuteFadeSpeed	   (float speed) { return FMOD_SoundGroup_SetMuteFadeSpeed_sfp((FMOD_SOUNDGROUP *)this, speed); }
FMOD_RESULT F_API FMOD::SoundGroup::getMuteFadeSpeed	   (float *speed) { return FMOD_SoundGroup_GetMuteFadeSpeed((FMOD_SOUNDGROUP *)this, speed); }
FMOD_RESULT F_API FMOD::SoundGroup::setVolume			  (float volume) { return FMOD_SoundGroup_SetVolume_sfp((FMOD_SOUNDGROUP *)this, volume); }
FMOD_RESULT F_API FMOD::SoundGroup::getVolume			  (float *volume) { return FMOD_SoundGroup_GetVolume((FMOD_SOUNDGROUP *)this, volume); }
FMOD_RESULT F_API FMOD::SoundGroup::stop				   () { return FMOD_SoundGroup_Stop((FMOD_SOUNDGROUP *)this); }
FMOD_RESULT F_API FMOD::SoundGroup::getName				(char *name, int namelen) { return FMOD_SoundGroup_GetName((FMOD_SOUNDGROUP *)this, name, namelen); }
FMOD_RESULT F_API FMOD::SoundGroup::getNumSounds		   (int *numsounds) { return FMOD_SoundGroup_GetNumSounds((FMOD_SOUNDGROUP *)this, numsounds); }
FMOD_RESULT F_API FMOD::SoundGroup::getSound			   (int index, Sound **sound) { return FMOD_SoundGroup_GetSound((FMOD_SOUNDGROUP *)this, index, (FMOD_SOUND **)sound); }
FMOD_RESULT F_API FMOD::SoundGroup::getNumPlaying		  (int *numplaying) { return FMOD_SoundGroup_GetNumPlaying((FMOD_SOUNDGROUP *)this, numplaying); }
FMOD_RESULT F_API FMOD::SoundGroup::setUserData			(void *userdata) { return FMOD_SoundGroup_SetUserData((FMOD_SOUNDGROUP *)this, userdata); }
FMOD_RESULT F_API FMOD::SoundGroup::getUserData			(void **userdata) { return FMOD_SoundGroup_GetUserData((FMOD_SOUNDGROUP *)this, userdata); }
FMOD_RESULT F_API FMOD::DSP::release				() { return FMOD_DSP_Release((FMOD_DSP *)this); }
FMOD_RESULT F_API FMOD::DSP::getSystemObject		(System **system) { return FMOD_DSP_GetSystemObject((FMOD_DSP *)this, (FMOD_SYSTEM **)system); }
FMOD_RESULT F_API FMOD::DSP::addInput			   (DSP *input, DSPConnection **connection , FMOD_DSPCONNECTION_TYPE type ) { return FMOD_DSP_AddInput((FMOD_DSP *)this, (FMOD_DSP *)input, (FMOD_DSPCONNECTION **)connection, type); }
FMOD_RESULT F_API FMOD::DSP::disconnectFrom		 (DSP *target, DSPConnection *connection ) { return FMOD_DSP_DisconnectFrom((FMOD_DSP *)this, (FMOD_DSP *)target, (FMOD_DSPCONNECTION *)connection); }
FMOD_RESULT F_API FMOD::DSP::disconnectAll		  (bool inputs, bool outputs) { return FMOD_DSP_DisconnectAll((FMOD_DSP *)this, inputs, outputs); }
FMOD_RESULT F_API FMOD::DSP::getNumInputs		   (int *numinputs) { return FMOD_DSP_GetNumInputs((FMOD_DSP *)this, numinputs); }
FMOD_RESULT F_API FMOD::DSP::getNumOutputs		  (int *numoutputs) { return FMOD_DSP_GetNumOutputs((FMOD_DSP *)this, numoutputs); }
FMOD_RESULT F_API FMOD::DSP::getInput			   (int index, DSP **input, DSPConnection **inputconnection) { return FMOD_DSP_GetInput((FMOD_DSP *)this, index, (FMOD_DSP **)input, (FMOD_DSPCONNECTION **)inputconnection); }
FMOD_RESULT F_API FMOD::DSP::getOutput			  (int index, DSP **output, DSPConnection **outputconnection) { return FMOD_DSP_GetOutput((FMOD_DSP *)this, index, (FMOD_DSP **)output, (FMOD_DSPCONNECTION **)outputconnection); }
FMOD_RESULT F_API FMOD::DSP::setActive			  (bool active) { return FMOD_DSP_SetActive((FMOD_DSP *)this, active); }
FMOD_RESULT F_API FMOD::DSP::getActive			  (bool *active) { return FMOD_DSP_GetActive((FMOD_DSP *)this, (FMOD_BOOL *)active); }
FMOD_RESULT F_API FMOD::DSP::setBypass			  (bool bypass) { return FMOD_DSP_SetBypass((FMOD_DSP *)this, bypass); }
FMOD_RESULT F_API FMOD::DSP::getBypass			  (bool *bypass) { return FMOD_DSP_GetBypass((FMOD_DSP *)this, (FMOD_BOOL *)bypass); }
FMOD_RESULT F_API FMOD::DSP::setWetDryMix		   (float prewet, float postwet, float dry) { return FMOD_DSP_SetWetDryMix_sfp((FMOD_DSP *)this, prewet, postwet, dry); }
FMOD_RESULT F_API FMOD::DSP::getWetDryMix		   (float *prewet, float *postwet, float *dry) { return FMOD_DSP_GetWetDryMix((FMOD_DSP *)this, prewet, postwet, dry); }
FMOD_RESULT F_API FMOD::DSP::setChannelFormat	   (FMOD_CHANNELMASK channelmask, int numchannels, FMOD_SPEAKERMODE source_speakermode) { return FMOD_DSP_SetChannelFormat((FMOD_DSP *)this, channelmask, numchannels, source_speakermode); }
FMOD_RESULT F_API FMOD::DSP::getChannelFormat	   (FMOD_CHANNELMASK *channelmask, int *numchannels, FMOD_SPEAKERMODE *source_speakermode) { return FMOD_DSP_GetChannelFormat((FMOD_DSP *)this, channelmask, numchannels, source_speakermode); }
FMOD_RESULT F_API FMOD::DSP::getOutputChannelFormat (FMOD_CHANNELMASK inmask, int inchannels, FMOD_SPEAKERMODE inspeakermode, FMOD_CHANNELMASK *outmask, int *outchannels, FMOD_SPEAKERMODE *outspeakermode) { return FMOD_DSP_GetOutputChannelFormat((FMOD_DSP *)this, inmask, inchannels, inspeakermode, outmask, outchannels, outspeakermode); }
FMOD_RESULT F_API FMOD::DSP::reset				  () { return FMOD_DSP_Reset((FMOD_DSP *)this); }
FMOD_RESULT F_API FMOD::DSP::setParameterFloat	  (int index, float value) { return FMOD_DSP_SetParameterFloat_sfp((FMOD_DSP *)this, index, value); }
FMOD_RESULT F_API FMOD::DSP::setParameterInt		(int index, int value) { return FMOD_DSP_SetParameterInt((FMOD_DSP *)this, index, value); }
FMOD_RESULT F_API FMOD::DSP::setParameterBool	   (int index, bool value) { return FMOD_DSP_SetParameterBool((FMOD_DSP *)this, index, value); }
FMOD_RESULT F_API FMOD::DSP::setParameterData	   (int index, void *data, unsigned int length) { return FMOD_DSP_SetParameterData((FMOD_DSP *)this, index, data, length); }
FMOD_RESULT F_API FMOD::DSP::getParameterFloat	  (int index, float *value, char *valuestr, int valuestrlen) { return FMOD_DSP_GetParameterFloat((FMOD_DSP *)this, index, value, valuestr, valuestrlen); }
FMOD_RESULT F_API FMOD::DSP::getParameterInt		(int index, int *value, char *valuestr, int valuestrlen) { return FMOD_DSP_GetParameterInt((FMOD_DSP *)this, index, value, valuestr, valuestrlen); }
FMOD_RESULT F_API FMOD::DSP::getParameterBool	   (int index, bool *value, char *valuestr, int valuestrlen) { return FMOD_DSP_GetParameterBool((FMOD_DSP *)this, index, (FMOD_BOOL *)value, valuestr, valuestrlen); }
FMOD_RESULT F_API FMOD::DSP::getParameterData	   (int index, void **data, unsigned int *length, char *valuestr, int valuestrlen) { return FMOD_DSP_GetParameterData((FMOD_DSP *)this, index, data, length, valuestr, valuestrlen); }
FMOD_RESULT F_API FMOD::DSP::getNumParameters	   (int *numparams) { return FMOD_DSP_GetNumParameters((FMOD_DSP *)this, numparams); }
FMOD_RESULT F_API FMOD::DSP::getParameterInfo	   (int index, FMOD_DSP_PARAMETER_DESC **desc) { return FMOD_DSP_GetParameterInfo((FMOD_DSP *)this, index, desc); }
FMOD_RESULT F_API FMOD::DSP::getDataParameterIndex  (int datatype, int *index) { return FMOD_DSP_GetDataParameterIndex((FMOD_DSP *)this, datatype, index); }
FMOD_RESULT F_API FMOD::DSP::showConfigDialog	   (void *hwnd, bool show) { return FMOD_DSP_ShowConfigDialog((FMOD_DSP *)this, hwnd, show); }
FMOD_RESULT F_API FMOD::DSP::getInfo				(char *name, unsigned int *version, int *channels, int *configwidth, int *configheight) { return FMOD_DSP_GetInfo((FMOD_DSP *)this, name, version, channels, configwidth, configheight); }
FMOD_RESULT F_API FMOD::DSP::getType				(FMOD_DSP_TYPE *type) { return FMOD_DSP_GetType((FMOD_DSP *)this, type); }
FMOD_RESULT F_API FMOD::DSP::getIdle				(bool *idle) { return FMOD_DSP_GetIdle((FMOD_DSP *)this, (FMOD_BOOL *)idle); }
FMOD_RESULT F_API FMOD::DSP::setUserData			(void *userdata) { return FMOD_DSP_SetUserData((FMOD_DSP *)this, userdata); }
FMOD_RESULT F_API FMOD::DSP::getUserData			(void **userdata) { return FMOD_DSP_GetUserData((FMOD_DSP *)this, userdata); }
FMOD_RESULT F_API FMOD::DSP::setMeteringEnabled	 (bool inputEnabled, bool outputEnabled) { return FMOD_DSP_SetMeteringEnabled((FMOD_DSP *)this, inputEnabled, outputEnabled); }
FMOD_RESULT F_API FMOD::DSP::getMeteringEnabled	 (bool *inputEnabled, bool *outputEnabled) { return FMOD_DSP_GetMeteringEnabled((FMOD_DSP *)this, (FMOD_BOOL *)inputEnabled, (FMOD_BOOL *)outputEnabled); }
FMOD_RESULT F_API FMOD::DSP::getMeteringInfo		(FMOD_DSP_METERING_INFO *inputInfo, FMOD_DSP_METERING_INFO *outputInfo) { return FMOD_DSP_GetMeteringInfo((FMOD_DSP *)this, inputInfo, outputInfo); }
FMOD_RESULT F_API FMOD::DSPConnection::getInput			  (DSP **input) { return FMOD_DSPConnection_GetInput((FMOD_DSPCONNECTION *)this, (FMOD_DSP **)input); }
FMOD_RESULT F_API FMOD::DSPConnection::getOutput			 (DSP **output) { return FMOD_DSPConnection_GetOutput((FMOD_DSPCONNECTION *)this, (FMOD_DSP **)output); }
FMOD_RESULT F_API FMOD::DSPConnection::setMix				(float volume) { return FMOD_DSPConnection_SetMix_sfp((FMOD_DSPCONNECTION *)this, volume); }
FMOD_RESULT F_API FMOD::DSPConnection::getMix				(float *volume) { return FMOD_DSPConnection_GetMix((FMOD_DSPCONNECTION *)this, volume); }
FMOD_RESULT F_API FMOD::DSPConnection::setMixMatrix		  (float *matrix, int outchannels, int inchannels, int inchannel_hop ) { return FMOD_DSPConnection_SetMixMatrix((FMOD_DSPCONNECTION *)this, matrix, outchannels, inchannels, inchannel_hop); }
FMOD_RESULT F_API FMOD::DSPConnection::getMixMatrix		  (float *matrix, int *outchannels, int *inchannels, int inchannel_hop ) { return FMOD_DSPConnection_GetMixMatrix((FMOD_DSPCONNECTION *)this, matrix, outchannels, inchannels, inchannel_hop); }
FMOD_RESULT F_API FMOD::DSPConnection::getType			   (FMOD_DSPCONNECTION_TYPE *type) { return FMOD_DSPConnection_GetType((FMOD_DSPCONNECTION *)this, type); }
FMOD_RESULT F_API FMOD::DSPConnection::setUserData		   (void *userdata) { return FMOD_DSPConnection_SetUserData((FMOD_DSPCONNECTION *)this, userdata); }
FMOD_RESULT F_API FMOD::DSPConnection::getUserData		   (void **userdata) { return FMOD_DSPConnection_GetUserData((FMOD_DSPCONNECTION *)this, userdata); }
FMOD_RESULT F_API FMOD::Geometry::release				() { return FMOD_Geometry_Release((FMOD_GEOMETRY *)this); }
FMOD_RESULT F_API FMOD::Geometry::addPolygon			 (float directocclusion, float reverbocclusion, bool doublesided, int numvertices, const FMOD_VECTOR *vertices, int *polygonindex) { return FMOD_Geometry_AddPolygon((FMOD_GEOMETRY *)this, directocclusion, reverbocclusion, doublesided, numvertices, vertices, polygonindex); }
FMOD_RESULT F_API FMOD::Geometry::getNumPolygons		 (int *numpolygons) { return FMOD_Geometry_GetNumPolygons((FMOD_GEOMETRY *)this, numpolygons); }
FMOD_RESULT F_API FMOD::Geometry::getMaxPolygons		 (int *maxpolygons, int *maxvertices) { return FMOD_Geometry_GetMaxPolygons((FMOD_GEOMETRY *)this, maxpolygons, maxvertices); }
FMOD_RESULT F_API FMOD::Geometry::getPolygonNumVertices  (int index, int *numvertices) { return FMOD_Geometry_GetPolygonNumVertices((FMOD_GEOMETRY *)this, index, numvertices); }
FMOD_RESULT F_API FMOD::Geometry::setPolygonVertex	   (int index, int vertexindex, const FMOD_VECTOR *vertex) { return FMOD_Geometry_SetPolygonVertex((FMOD_GEOMETRY *)this, index, vertexindex, vertex); }
FMOD_RESULT F_API FMOD::Geometry::getPolygonVertex	   (int index, int vertexindex, FMOD_VECTOR *vertex) { return FMOD_Geometry_GetPolygonVertex((FMOD_GEOMETRY *)this, index, vertexindex, vertex); }
FMOD_RESULT F_API FMOD::Geometry::setPolygonAttributes   (int index, float directocclusion, float reverbocclusion, bool doublesided) { return FMOD_Geometry_SetPolygonAttributes((FMOD_GEOMETRY *)this, index, directocclusion, reverbocclusion, doublesided); }
FMOD_RESULT F_API FMOD::Geometry::getPolygonAttributes   (int index, float *directocclusion, float *reverbocclusion, bool *doublesided) { return FMOD_Geometry_GetPolygonAttributes((FMOD_GEOMETRY *)this, index, directocclusion, reverbocclusion, (FMOD_BOOL *)doublesided); }
FMOD_RESULT F_API FMOD::Geometry::setActive			  (bool active) { return FMOD_Geometry_SetActive((FMOD_GEOMETRY *)this, active); }
FMOD_RESULT F_API FMOD::Geometry::getActive			  (bool *active) { return FMOD_Geometry_GetActive((FMOD_GEOMETRY *)this, (FMOD_BOOL *)active); }
FMOD_RESULT F_API FMOD::Geometry::setRotation			(const FMOD_VECTOR *forward, const FMOD_VECTOR *up) { return FMOD_Geometry_SetRotation((FMOD_GEOMETRY *)this, forward, up); }
FMOD_RESULT F_API FMOD::Geometry::getRotation			(FMOD_VECTOR *forward, FMOD_VECTOR *up) { return FMOD_Geometry_GetRotation((FMOD_GEOMETRY *)this, forward, up); }
FMOD_RESULT F_API FMOD::Geometry::setPosition			(const FMOD_VECTOR *position) { return FMOD_Geometry_SetPosition((FMOD_GEOMETRY *)this, position); }
FMOD_RESULT F_API FMOD::Geometry::getPosition			(FMOD_VECTOR *position) { return FMOD_Geometry_GetPosition((FMOD_GEOMETRY *)this, position); }
FMOD_RESULT F_API FMOD::Geometry::setScale			   (const FMOD_VECTOR *scale) { return FMOD_Geometry_SetScale((FMOD_GEOMETRY *)this, scale); }
FMOD_RESULT F_API FMOD::Geometry::getScale			   (FMOD_VECTOR *scale) { return FMOD_Geometry_GetScale((FMOD_GEOMETRY *)this, scale); }
FMOD_RESULT F_API FMOD::Geometry::save				   (void *data, int *datasize) { return FMOD_Geometry_Save((FMOD_GEOMETRY *)this, data, datasize); }
FMOD_RESULT F_API FMOD::Geometry::setUserData			(void *userdata) { return FMOD_Geometry_SetUserData((FMOD_GEOMETRY *)this, userdata); }
FMOD_RESULT F_API FMOD::Geometry::getUserData			(void **userdata) { return FMOD_Geometry_GetUserData((FMOD_GEOMETRY *)this, userdata); }
FMOD_RESULT F_API FMOD::Reverb3D::release				() { return FMOD_Reverb3D_Release((FMOD_REVERB3D *)this); }
FMOD_RESULT F_API FMOD::Reverb3D::set3DAttributes		(const FMOD_VECTOR *position, float mindistance, float maxdistance) { return FMOD_Reverb3D_Set3DAttributes_sfp((FMOD_REVERB3D *)this, position, mindistance, maxdistance); }
FMOD_RESULT F_API FMOD::Reverb3D::get3DAttributes		(FMOD_VECTOR *position, float *mindistance,float *maxdistance) { return FMOD_Reverb3D_Get3DAttributes((FMOD_REVERB3D *)this, position, mindistance, maxdistance); }
FMOD_RESULT F_API FMOD::Reverb3D::setProperties		  (const FMOD_REVERB_PROPERTIES *properties) { return FMOD_Reverb3D_SetProperties((FMOD_REVERB3D *)this, properties); }
FMOD_RESULT F_API FMOD::Reverb3D::getProperties		  (FMOD_REVERB_PROPERTIES *properties) { return FMOD_Reverb3D_GetProperties((FMOD_REVERB3D *)this, properties); }
FMOD_RESULT F_API FMOD::Reverb3D::setActive			  (bool active) { return FMOD_Reverb3D_SetActive((FMOD_REVERB3D *)this, active); }
FMOD_RESULT F_API FMOD::Reverb3D::getActive			  (bool *active) { return FMOD_Reverb3D_GetActive((FMOD_REVERB3D *)this, (FMOD_BOOL *)active); }
FMOD_RESULT F_API FMOD::Reverb3D::setUserData			(void *userdata) { return FMOD_Reverb3D_SetUserData((FMOD_REVERB3D *)this, userdata); }
FMOD_RESULT F_API FMOD::Reverb3D::getUserData			(void **userdata) { return FMOD_Reverb3D_GetUserData((FMOD_REVERB3D *)this, userdata); }

#ifndef _FMOD_STUDIO_HPP
#define _FMOD_STUDIO_HPP

#include "fmod_studio.h"
#include "fmod_studio_common.h"
#include <vitasdk.h>

__attribute__((naked)) FMOD_RESULT F_API FMOD_Studio_System_SetListenerWeight_sfp(FMOD_STUDIO_SYSTEM *system, int listener, float weight) {
	asm volatile(
				 "vmov s0, r2\n" // move r2 to s0 : argument `weight` is of type float
				 "b FMOD_Studio_System_SetListenerWeight\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Studio_EventInstance_SetProperty_sfp(FMOD_STUDIO_EVENTINSTANCE *e, FMOD_STUDIO_EVENT_PROPERTY index, float value) {
	asm volatile(
				 "vmov s0, r2\n" // move r2 to s0 : argument `value` is of type float
				 "b FMOD_Studio_EventInstance_SetProperty\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Studio_EventInstance_SetReverbLevel_sfp(FMOD_STUDIO_EVENTINSTANCE *e, int index, float level) {
	asm volatile(
				 "vmov s0, r2\n" // move r1 to s0 : argument `level` is of type float
				 "b FMOD_Studio_EventInstance_SetReverbLevel\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Studio_EventInstance_SetParameterValue_sfp(FMOD_STUDIO_EVENTINSTANCE *e, const char *name, float level) {
	asm volatile(
				 "vmov s0, r2\n" // move r1 to s0 : argument `level` is of type float
				 "b FMOD_Studio_EventInstance_SetParameterValue\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Studio_EventInstance_SetParameterValueByIndex_sfp(FMOD_STUDIO_EVENTINSTANCE *e, int index, float level) {
	asm volatile(
				 "vmov s0, r2\n" // move r1 to s0 : argument `level` is of type float
				 "b FMOD_Studio_EventInstance_SetParameterValueByIndex\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Studio_EventInstance_SetVolume_sfp(FMOD_STUDIO_EVENTINSTANCE *e, float level) {
	asm volatile(
				 "vmov s0, r1\n" // move r1 to s0 : argument `level` is of type float
				 "b FMOD_Studio_EventInstance_SetVolume\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Studio_EventInstance_SetPitch_sfp(FMOD_STUDIO_EVENTINSTANCE *e, float level) {
	asm volatile(
				 "vmov s0, r1\n" // move r1 to s0 : argument `level` is of type float
				 "b FMOD_Studio_EventInstance_SetPitch\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Studio_ParameterInstance_SetValue_sfp(FMOD_STUDIO_PARAMETERINSTANCE *e, float level) {
	asm volatile(
				 "vmov s0, r1\n" // move r1 to s0 : argument `level` is of type float
				 "b FMOD_Studio_ParameterInstance_SetValue\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Studio_Bus_SetVolume_sfp(FMOD_STUDIO_BUS *e, float level) {
	asm volatile(
				 "vmov s0, r1\n" // move r1 to s0 : argument `level` is of type float
				 "b FMOD_Studio_Bus_SetVolume\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Studio_VCA_SetVolume_sfp(FMOD_STUDIO_VCA *e, float level) {
	asm volatile(
				 "vmov s0, r1\n" // move r1 to s0 : argument `level` is of type float
				 "b FMOD_Studio_VCA_SetVolume\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Studio_CommandReplay_SeekToTime_sfp(FMOD_STUDIO_COMMANDREPLAY *e, float level) {
	asm volatile(
				 "vmov s0, r1\n" // move r1 to s0 : argument `level` is of type float
				 "b FMOD_Studio_CommandReplay_SeekToTime\n" // jump to original function
				 );
}

__attribute__((naked)) FMOD_RESULT F_API FMOD_Studio_CommandReplay_GetCommandAtTime_sfp(FMOD_STUDIO_COMMANDREPLAY *e, float time, int *commandindex) {
	asm volatile(
				 "vmov s0, r1\n" // move r1 to s0 : argument `time` is of type float
				 "ldr r1, [r2]\n" // move r2 to r1 : freed up for argument `commandindex`
				 "b FMOD_Studio_CommandReplay_GetCommandAtTime\n" // jump to original function
				 );
}

namespace FMOD
{
namespace Studio
{
	class System;
	class EventDescription;
	class EventInstance;
	class CommandReplay;
	class VCA;
	class Bank;
	class Bus;
	class ParameterInstance;
	
	class System
	{
		private:
			System();
			System(const System &);	
		public:
			FMOD_RESULT F_API create(System **system, unsigned int headerversion = FMOD_VERSION);
			FMOD_RESULT F_API getVCAByID(const FMOD_GUID *id, VCA **vca);
			FMOD_RESULT F_API getListenerWeight(int listener, float *weight);
			FMOD_RESULT F_API loadBankFile(const char *filename, FMOD_STUDIO_LOAD_BANK_FLAGS flags, Bank **bank);
			FMOD_RESULT F_API getListenerAttributes(int listener, FMOD_3D_ATTRIBUTES *attributes);
			FMOD_RESULT F_API getBankList(Bank **array, int capacity, int *count);
			FMOD_RESULT F_API unregisterPlugin(const char *name);
			FMOD_RESULT F_API getSoundInfo(const char *key, FMOD_STUDIO_SOUND_INFO *info);
			FMOD_RESULT F_API loadBankMemory(const char *buffer, int length, FMOD_STUDIO_LOAD_MEMORY_MODE mode, FMOD_STUDIO_LOAD_BANK_FLAGS flags, Bank **bank);
			FMOD_RESULT F_API registerPlugin(const FMOD_DSP_DESCRIPTION *description);
			FMOD_RESULT F_API release();
			FMOD_RESULT F_API getLowLevelSystem(FMOD::System **system);
			bool isValid();
			FMOD_RESULT F_API resetBufferUsage();
			FMOD_RESULT F_API setCallback(FMOD_STUDIO_SYSTEM_CALLBACK callback, FMOD_STUDIO_SYSTEM_CALLBACK_TYPE callbackmask = FMOD_STUDIO_SYSTEM_CALLBACK_ALL);
			FMOD_RESULT F_API update();
			FMOD_RESULT F_API setNumListeners(int numlisteners);
			FMOD_RESULT F_API flushCommands();
			FMOD_RESULT F_API getBus(const char *path, Bus **bus);
			FMOD_RESULT F_API setUserData(void *userdata);
			FMOD_RESULT F_API getCPUUsage(FMOD_STUDIO_CPU_USAGE *usage);
			FMOD_RESULT F_API getAdvancedSettings(FMOD_STUDIO_ADVANCEDSETTINGS *settings);
			FMOD_RESULT F_API getUserData(void **userdata);
			FMOD_RESULT F_API loadCommandReplay(const char *filename, FMOD_STUDIO_COMMANDREPLAY_FLAGS flags, CommandReplay **playback);
			FMOD_RESULT F_API getEvent(const char *path, EventDescription **event);
			FMOD_RESULT F_API getBufferUsage(FMOD_STUDIO_BUFFER_USAGE *usage);
			FMOD_RESULT F_API startCommandCapture(const char *filename, FMOD_STUDIO_COMMANDCAPTURE_FLAGS flags);
			FMOD_RESULT F_API setListenerAttributes(int listener, const FMOD_3D_ATTRIBUTES *attributes);
			FMOD_RESULT F_API loadBankCustom(const FMOD_STUDIO_BANK_INFO *info, FMOD_STUDIO_LOAD_BANK_FLAGS flags, Bank **bank);
			FMOD_RESULT F_API getBusByID(const FMOD_GUID *id, Bus **bus);
			FMOD_RESULT F_API setAdvancedSettings(FMOD_STUDIO_ADVANCEDSETTINGS *settings);
			FMOD_RESULT F_API getVCA(const char *path, VCA **vca);
			FMOD_RESULT F_API getBank(const char *path, Bank **bank);
			FMOD_RESULT F_API setListenerWeight(int listener, float weight);
			FMOD_RESULT F_API flushSampleLoading();
			FMOD_RESULT F_API initialize(int maxchannels, FMOD_STUDIO_INITFLAGS studioflags, FMOD_INITFLAGS flags, void *extradriverdata);
			FMOD_RESULT F_API lookupID(const char *path, FMOD_GUID *id);
			FMOD_RESULT F_API getEventByID(const FMOD_GUID *id, EventDescription **event);
			FMOD_RESULT F_API lookupPath(const FMOD_GUID *id, char *path, int size, int *retrieved);
			FMOD_RESULT F_API getNumListeners(int *numlisteners);
			FMOD_RESULT F_API getBankByID(const FMOD_GUID *id, Bank **bank);
			FMOD_RESULT F_API unloadAll();
			FMOD_RESULT F_API getBankCount(int *count);
			FMOD_RESULT F_API stopCommandCapture();
	};
	
	class EventDescription
	{
		private:
			EventDescription();
			EventDescription(const EventDescription &);
		public:
			FMOD_RESULT F_API hasCue(bool *cue);
			FMOD_RESULT F_API isOneshot(bool *oneshot);
			FMOD_RESULT F_API getSoundSize(float *size);
			FMOD_RESULT F_API unloadSampleData();
			FMOD_RESULT F_API getMaximumDistance(float *distance);
			FMOD_RESULT F_API getUserProperty(const char *name, FMOD_STUDIO_USER_PROPERTY *property);
			FMOD_RESULT F_API getID(FMOD_GUID *id);
			FMOD_RESULT F_API getLength(int *length);
			FMOD_RESULT F_API getParameterCount(int *count);
			FMOD_RESULT F_API createInstance(EventInstance **instance);
			FMOD_RESULT F_API getInstanceCount(int *count);
			FMOD_RESULT F_API getUserData(void **userdata);
			FMOD_RESULT F_API getMinimumDistance(float *distance);
			FMOD_RESULT F_API getUserPropertyByIndex(int index, FMOD_STUDIO_USER_PROPERTY *property);
			bool isValid();
			FMOD_RESULT F_API getPath(char *path, int size, int *retrieved);
			FMOD_RESULT F_API setUserData(void *userdata);
			FMOD_RESULT F_API getParameterByIndex(int index, FMOD_STUDIO_PARAMETER_DESCRIPTION *parameter);
			FMOD_RESULT F_API releaseAllInstances();
			FMOD_RESULT F_API loadSampleData();
			FMOD_RESULT F_API getParameter(const char *name, FMOD_STUDIO_PARAMETER_DESCRIPTION *parameter);
			FMOD_RESULT F_API isSnapshot(bool *snapshot);
			FMOD_RESULT F_API setCallback(FMOD_STUDIO_EVENT_CALLBACK callback, FMOD_STUDIO_EVENT_CALLBACK_TYPE callbackmask = FMOD_STUDIO_EVENT_CALLBACK_ALL);
			FMOD_RESULT F_API getSampleLoadingState(FMOD_STUDIO_LOADING_STATE *state);
			FMOD_RESULT F_API getInstanceList(EventInstance **array, int capacity, int *count);
			FMOD_RESULT F_API is3D(bool *is3D);
			FMOD_RESULT F_API isStream(bool *isStream);
			FMOD_RESULT F_API getUserPropertyCount(int *count);
	};
	
	class EventInstance
	{
		private:
			EventInstance();
			EventInstance(const EventInstance &);
		public:
			FMOD_RESULT F_API getDescription(EventDescription **description);
			FMOD_RESULT F_API getReverbLevel(int index, float *level);
			FMOD_RESULT F_API getTimelinePosition(int *position);
			FMOD_RESULT F_API setProperty(FMOD_STUDIO_EVENT_PROPERTY index, float value);
			FMOD_RESULT F_API getPaused(bool *paused);
			FMOD_RESULT F_API setPaused(bool paused);
			FMOD_RESULT F_API setReverbLevel(int index, float level);
			FMOD_RESULT F_API getParameterByIndex(int index, ParameterInstance **parameter);
			FMOD_RESULT F_API setCallback(FMOD_STUDIO_EVENT_CALLBACK callback, FMOD_STUDIO_EVENT_CALLBACK_TYPE callbackmask = FMOD_STUDIO_EVENT_CALLBACK_ALL);
			FMOD_RESULT F_API getParameter(const char *name, ParameterInstance **parameter);
			FMOD_RESULT F_API getListenerMask(unsigned int *mask);
			FMOD_RESULT F_API getPitch(float *pitch, float *finalpitch = 0);
			FMOD_RESULT F_API getParameterValue(const char *name, float *value, float *finalvalue = 0);
			FMOD_RESULT F_API start();
			FMOD_RESULT F_API setListenerMask(unsigned int mask);
			FMOD_RESULT F_API triggerCue();
			bool isValid();
			FMOD_RESULT F_API setParameterValueByIndex(int index, float value);
			FMOD_RESULT F_API getPlaybackState(FMOD_STUDIO_PLAYBACK_STATE *state);
			FMOD_RESULT F_API isVirtual(bool *virtualState);
			FMOD_RESULT F_API set3DAttributes(const FMOD_3D_ATTRIBUTES *attributes);
			FMOD_RESULT F_API getParameterCount(int *count);
			FMOD_RESULT F_API setUserData(void *userdata);
			FMOD_RESULT F_API setTimelinePosition(int position);
			FMOD_RESULT F_API getParameterValueByIndex(int index, float *value, float *finalvalue = 0);
			FMOD_RESULT F_API getUserData(void **userdata);
			FMOD_RESULT F_API get3DAttributes(FMOD_3D_ATTRIBUTES *attributes);
			FMOD_RESULT F_API getChannelGroup(ChannelGroup **group);
			FMOD_RESULT F_API release();
			FMOD_RESULT F_API setParameterValuesByIndices(int *indices, float *values, int count);
			FMOD_RESULT F_API stop(FMOD_STUDIO_STOP_MODE mode);
			FMOD_RESULT F_API setVolume(float volume);
			FMOD_RESULT F_API setParameterValue(const char *name, float value);
			FMOD_RESULT F_API setPitch(float pitch);
			FMOD_RESULT F_API getVolume(float *volume, float *finalvolume = 0);
			FMOD_RESULT F_API getProperty(FMOD_STUDIO_EVENT_PROPERTY index, float *value);
	};
	
	class ParameterInstance
	{
		private:
			ParameterInstance();
			ParameterInstance(const ParameterInstance &);
		public:
			FMOD_RESULT F_API getDescription(FMOD_STUDIO_PARAMETER_DESCRIPTION *description);
			FMOD_RESULT F_API setValue(float value);
			bool isValid();
			FMOD_RESULT F_API getValue(float *value);
	};
	
	class Bus
	{
		private:
			Bus();
			Bus(const Bus &);
		public:
			FMOD_RESULT F_API setMute(bool mute);
			FMOD_RESULT F_API getID(FMOD_GUID *id);
			FMOD_RESULT F_API getChannelGroup(FMOD::ChannelGroup **channelgroup);
			FMOD_RESULT F_API setPaused(bool paused);
			FMOD_RESULT F_API getPaused(bool *paused);
			FMOD_RESULT F_API unlockChannelGroup();
			bool isValid();
			FMOD_RESULT F_API getMute(bool *mute);
			FMOD_RESULT F_API setVolume(float volume);
			FMOD_RESULT F_API getPath(char *path, int size, int *retrieved);
			FMOD_RESULT F_API stopAllEvents(FMOD_STUDIO_STOP_MODE mode);
			FMOD_RESULT F_API getVolume(float *volume, float *finalvolume = 0);
			FMOD_RESULT F_API lockChannelGroup();
	};
	
	class VCA
	{
		private:
			VCA();
			VCA(const VCA &);
		public:
			bool isValid();
			FMOD_RESULT F_API getVolume(float *volume, float *finalvolume = 0);
			FMOD_RESULT F_API getPath(char *path, int size, int *retrieved);
			FMOD_RESULT F_API getID(FMOD_GUID *id);
			FMOD_RESULT F_API setVolume(float volume);
	};
	
	class Bank
	{
		private:
			Bank();
			Bank(const Bank &);
		public:
			bool isValid();
			FMOD_RESULT F_API unload();
			FMOD_RESULT F_API loadSampleData();
			FMOD_RESULT F_API getPath(char *path, int size, int *retrieved);
			FMOD_RESULT F_API getStringCount(int *count);
			FMOD_RESULT F_API getEventList(EventDescription **array, int capacity, int *count);
			FMOD_RESULT F_API unloadSampleData();
			FMOD_RESULT F_API getBusCount(int *count);
			FMOD_RESULT F_API getEventCount(int *count);
			FMOD_RESULT F_API getLoadingState(FMOD_STUDIO_LOADING_STATE *state);
			FMOD_RESULT F_API getStringInfo(int index, FMOD_GUID *id, char *path, int size, int *retrieved);
			FMOD_RESULT F_API getVCAList(VCA **array, int capacity, int *count);
			FMOD_RESULT F_API getSampleLoadingState(FMOD_STUDIO_LOADING_STATE *state);
			FMOD_RESULT F_API getBusList(Bus **array, int capacity, int *count);
			FMOD_RESULT F_API getID(FMOD_GUID *id);
			FMOD_RESULT F_API getVCACount(int *count);
			FMOD_RESULT F_API getUserData(void **userdata);
			FMOD_RESULT F_API setUserData(void *userdata);
	};
	
	class CommandReplay
	{
		private:
			CommandReplay();
			CommandReplay(const CommandReplay &);
		public:
			bool isValid();
			FMOD_RESULT F_API setCreateInstanceCallback(FMOD_STUDIO_COMMANDREPLAY_CREATE_INSTANCE_CALLBACK callback);
			FMOD_RESULT F_API getLength(float *length);
			FMOD_RESULT F_API getUserData(void **userdata);
			FMOD_RESULT F_API getCommandAtTime(float time, int *commandindex);
			FMOD_RESULT F_API stop();
			FMOD_RESULT F_API getCommandInfo(int commandindex, FMOD_STUDIO_COMMAND_INFO *info);
			FMOD_RESULT F_API setPaused(bool paused);
			FMOD_RESULT F_API setBankPath(const char *bankPath);
			FMOD_RESULT F_API getPlaybackState(FMOD_STUDIO_PLAYBACK_STATE *state);
			FMOD_RESULT F_API setUserData(void *userdata);
			FMOD_RESULT F_API getPaused(bool *paused);
			FMOD_RESULT F_API getCurrentCommand(int *commandindex, float *currenttime);
			FMOD_RESULT F_API start();
			FMOD_RESULT F_API seekToCommand(int commandindex);
			FMOD_RESULT F_API setFrameCallback(FMOD_STUDIO_COMMANDREPLAY_FRAME_CALLBACK callback);
			FMOD_RESULT F_API setLoadBankCallback(FMOD_STUDIO_COMMANDREPLAY_LOAD_BANK_CALLBACK callback);
			FMOD_RESULT F_API getCommandCount(int *count);
			FMOD_RESULT F_API getSystem(System **system);
			FMOD_RESULT F_API getCommandString(int commandindex, char *buffer, int length);
			FMOD_RESULT F_API seekToTime(float time);
			FMOD_RESULT F_API release();
	};
};
};

bool FMOD::Studio::CommandReplay::isValid() { return FMOD_Studio_CommandReplay_IsValid((FMOD_STUDIO_COMMANDREPLAY *)this); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::getSystem(System **system) { return FMOD_Studio_CommandReplay_GetSystem((FMOD_STUDIO_COMMANDREPLAY *)this,(FMOD_STUDIO_SYSTEM **)system); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::getLength(float *length) { return FMOD_Studio_CommandReplay_GetLength((FMOD_STUDIO_COMMANDREPLAY *)this,length); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::getCommandCount(int *count) { return FMOD_Studio_CommandReplay_GetCommandCount((FMOD_STUDIO_COMMANDREPLAY *)this,count); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::getCommandInfo(int commandindex, FMOD_STUDIO_COMMAND_INFO *info) { return FMOD_Studio_CommandReplay_GetCommandInfo((FMOD_STUDIO_COMMANDREPLAY *)this,commandindex,info); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::getCommandString(int commandindex, char *buffer, int length) { return FMOD_Studio_CommandReplay_GetCommandString((FMOD_STUDIO_COMMANDREPLAY *)this,commandindex,buffer,length); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::getCommandAtTime(float time, int *commandindex) { return FMOD_Studio_CommandReplay_GetCommandAtTime_sfp((FMOD_STUDIO_COMMANDREPLAY *)this,time,commandindex); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::setBankPath(const char *bankPath)  { return FMOD_Studio_CommandReplay_SetBankPath((FMOD_STUDIO_COMMANDREPLAY *)this,bankPath); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::start()  { return FMOD_Studio_CommandReplay_Start((FMOD_STUDIO_COMMANDREPLAY *)this); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::stop()  { return FMOD_Studio_CommandReplay_Stop((FMOD_STUDIO_COMMANDREPLAY *)this); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::seekToTime(float time)  { return FMOD_Studio_CommandReplay_SeekToTime_sfp((FMOD_STUDIO_COMMANDREPLAY *)this,time); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::seekToCommand(int commandindex)  { return FMOD_Studio_CommandReplay_SeekToCommand((FMOD_STUDIO_COMMANDREPLAY *)this,commandindex); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::getPaused(bool *paused) { return FMOD_Studio_CommandReplay_GetPaused((FMOD_STUDIO_COMMANDREPLAY *)this,(int *)paused); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::setPaused(bool paused)  { return FMOD_Studio_CommandReplay_SetPaused((FMOD_STUDIO_COMMANDREPLAY *)this,paused); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::getPlaybackState(FMOD_STUDIO_PLAYBACK_STATE *state) { return FMOD_Studio_CommandReplay_GetPlaybackState((FMOD_STUDIO_COMMANDREPLAY *)this,state); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::getCurrentCommand(int *commandindex, float *currenttime) { return FMOD_Studio_CommandReplay_GetCurrentCommand((FMOD_STUDIO_COMMANDREPLAY *)this,commandindex,currenttime); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::release()  { return FMOD_Studio_CommandReplay_Release((FMOD_STUDIO_COMMANDREPLAY *)this); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::setFrameCallback(FMOD_STUDIO_COMMANDREPLAY_FRAME_CALLBACK callback)  { return FMOD_Studio_CommandReplay_SetFrameCallback((FMOD_STUDIO_COMMANDREPLAY *)this,callback); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::setLoadBankCallback(FMOD_STUDIO_COMMANDREPLAY_LOAD_BANK_CALLBACK callback)  { return FMOD_Studio_CommandReplay_SetLoadBankCallback((FMOD_STUDIO_COMMANDREPLAY *)this,callback); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::setCreateInstanceCallback(FMOD_STUDIO_COMMANDREPLAY_CREATE_INSTANCE_CALLBACK callback)  { return FMOD_Studio_CommandReplay_SetCreateInstanceCallback((FMOD_STUDIO_COMMANDREPLAY *)this,callback); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::getUserData(void **userdata) { return FMOD_Studio_CommandReplay_GetUserData((FMOD_STUDIO_COMMANDREPLAY *)this,userdata); }
FMOD_RESULT F_API FMOD::Studio::CommandReplay::setUserData(void *userdata)  { return FMOD_Studio_CommandReplay_SetUserData((FMOD_STUDIO_COMMANDREPLAY *)this,userdata); }
bool FMOD::Studio::System::isValid() { return FMOD_Studio_System_IsValid((FMOD_STUDIO_SYSTEM *)this); }
FMOD_RESULT F_API FMOD::Studio::System::create(System **system, unsigned int headerversion)  { return FMOD_Studio_System_Create((FMOD_STUDIO_SYSTEM **)system, headerversion); }
FMOD_RESULT F_API FMOD::Studio::System::setAdvancedSettings(FMOD_STUDIO_ADVANCEDSETTINGS *settings)  { return FMOD_Studio_System_SetAdvancedSettings((FMOD_STUDIO_SYSTEM *)this,settings); }
FMOD_RESULT F_API FMOD::Studio::System::getAdvancedSettings(FMOD_STUDIO_ADVANCEDSETTINGS *settings)  { return FMOD_Studio_System_GetAdvancedSettings((FMOD_STUDIO_SYSTEM *)this,settings); }
FMOD_RESULT F_API FMOD::Studio::System::initialize(int maxchannels, FMOD_STUDIO_INITFLAGS studioflags, FMOD_INITFLAGS flags, void *extradriverdata)  { return FMOD_Studio_System_Initialize((FMOD_STUDIO_SYSTEM *)this,maxchannels,studioflags,flags,extradriverdata); }
FMOD_RESULT F_API FMOD::Studio::System::release()  { return FMOD_Studio_System_Release((FMOD_STUDIO_SYSTEM *)this); }
FMOD_RESULT F_API FMOD::Studio::System::update()  { return FMOD_Studio_System_Update((FMOD_STUDIO_SYSTEM *)this); }
FMOD_RESULT F_API FMOD::Studio::System::flushCommands()  { return FMOD_Studio_System_FlushCommands((FMOD_STUDIO_SYSTEM *)this); }
FMOD_RESULT F_API FMOD::Studio::System::flushSampleLoading()  { return FMOD_Studio_System_FlushSampleLoading((FMOD_STUDIO_SYSTEM *)this); }
FMOD_RESULT F_API FMOD::Studio::System::getLowLevelSystem(FMOD::System **system) { return FMOD_Studio_System_GetLowLevelSystem((FMOD_STUDIO_SYSTEM *)this,(FMOD_SYSTEM **)system); }
FMOD_RESULT F_API FMOD::Studio::System::getEvent(const char *path, EventDescription **event) { return FMOD_Studio_System_GetEvent((FMOD_STUDIO_SYSTEM *)this,path,(FMOD_STUDIO_EVENTDESCRIPTION **)event); }
FMOD_RESULT F_API FMOD::Studio::System::getBus(const char *path, Bus **bus) { return FMOD_Studio_System_GetBus((FMOD_STUDIO_SYSTEM *)this,path,(FMOD_STUDIO_BUS **)bus); }
FMOD_RESULT F_API FMOD::Studio::System::getVCA(const char *path, VCA **vca) { return FMOD_Studio_System_GetVCA((FMOD_STUDIO_SYSTEM *)this,path,(FMOD_STUDIO_VCA **)vca); }
FMOD_RESULT F_API FMOD::Studio::System::getBank(const char *path, Bank **bank) { return FMOD_Studio_System_GetBank((FMOD_STUDIO_SYSTEM *)this,path,(FMOD_STUDIO_BANK**)bank); }
FMOD_RESULT F_API FMOD::Studio::System::getEventByID(const FMOD_GUID *id, EventDescription **event) { return FMOD_Studio_System_GetEventByID((FMOD_STUDIO_SYSTEM *)this,id,(FMOD_STUDIO_EVENTDESCRIPTION **)event); }
FMOD_RESULT F_API FMOD::Studio::System::getBusByID(const FMOD_GUID *id, Bus **bus) { return FMOD_Studio_System_GetBusByID((FMOD_STUDIO_SYSTEM *)this,id,(FMOD_STUDIO_BUS **)bus); }
FMOD_RESULT F_API FMOD::Studio::System::getVCAByID(const FMOD_GUID *id, VCA **vca) { return FMOD_Studio_System_GetVCAByID((FMOD_STUDIO_SYSTEM *)this,id,(FMOD_STUDIO_VCA **)vca); }
FMOD_RESULT F_API FMOD::Studio::System::getBankByID(const FMOD_GUID *id, Bank **bank) { return FMOD_Studio_System_GetBankByID((FMOD_STUDIO_SYSTEM *)this,id,(FMOD_STUDIO_BANK**)bank); }
FMOD_RESULT F_API FMOD::Studio::System::getSoundInfo(const char *key, FMOD_STUDIO_SOUND_INFO *info) { return FMOD_Studio_System_GetSoundInfo((FMOD_STUDIO_SYSTEM *)this,key,info); }
FMOD_RESULT F_API FMOD::Studio::System::lookupID(const char *path, FMOD_GUID *id) { return FMOD_Studio_System_LookupID((FMOD_STUDIO_SYSTEM *)this,path,id); }
FMOD_RESULT F_API FMOD::Studio::System::lookupPath(const FMOD_GUID *id, char *path, int size, int *retrieved) { return FMOD_Studio_System_LookupPath((FMOD_STUDIO_SYSTEM *)this,id,path,size,retrieved); }
FMOD_RESULT F_API FMOD::Studio::System::getNumListeners(int *numlisteners)  { return FMOD_Studio_System_GetNumListeners((FMOD_STUDIO_SYSTEM *)this,numlisteners); }
FMOD_RESULT F_API FMOD::Studio::System::setNumListeners(int numlisteners)  { return FMOD_Studio_System_SetNumListeners((FMOD_STUDIO_SYSTEM *)this,numlisteners); }
FMOD_RESULT F_API FMOD::Studio::System::getListenerAttributes(int listener, FMOD_3D_ATTRIBUTES *attributes) { return FMOD_Studio_System_GetListenerAttributes((FMOD_STUDIO_SYSTEM *)this,listener,attributes); }
FMOD_RESULT F_API FMOD::Studio::System::setListenerAttributes(int listener, const FMOD_3D_ATTRIBUTES *attributes)  { return FMOD_Studio_System_SetListenerAttributes((FMOD_STUDIO_SYSTEM *)this,listener,attributes); }
FMOD_RESULT F_API FMOD::Studio::System::getListenerWeight(int listener, float *weight)  { return FMOD_Studio_System_GetListenerWeight((FMOD_STUDIO_SYSTEM *)this,listener,weight); }
FMOD_RESULT F_API FMOD::Studio::System::setListenerWeight(int listener, float weight)  { return FMOD_Studio_System_SetListenerWeight_sfp((FMOD_STUDIO_SYSTEM *)this,listener,weight); }
FMOD_RESULT F_API FMOD::Studio::System::loadBankFile(const char *filename, FMOD_STUDIO_LOAD_BANK_FLAGS flags, Bank **bank)  { return FMOD_Studio_System_LoadBankFile((FMOD_STUDIO_SYSTEM *)this,filename,flags,(FMOD_STUDIO_BANK**)bank); }
FMOD_RESULT F_API FMOD::Studio::System::loadBankMemory(const char *buffer, int length, FMOD_STUDIO_LOAD_MEMORY_MODE mode, FMOD_STUDIO_LOAD_BANK_FLAGS flags, Bank **bank)  { return FMOD_Studio_System_LoadBankMemory((FMOD_STUDIO_SYSTEM *)this,buffer,length,mode,flags,(FMOD_STUDIO_BANK**)bank); }
FMOD_RESULT F_API FMOD::Studio::System::loadBankCustom(const FMOD_STUDIO_BANK_INFO *info, FMOD_STUDIO_LOAD_BANK_FLAGS flags, Bank **bank)  { return FMOD_Studio_System_LoadBankCustom((FMOD_STUDIO_SYSTEM *)this,info,flags,(FMOD_STUDIO_BANK**)bank); }
FMOD_RESULT F_API FMOD::Studio::System::unloadAll()  { return FMOD_Studio_System_UnloadAll((FMOD_STUDIO_SYSTEM *)this); }
FMOD_RESULT F_API FMOD::Studio::System::getCPUUsage(FMOD_STUDIO_CPU_USAGE *usage) { return FMOD_Studio_System_GetCPUUsage((FMOD_STUDIO_SYSTEM *)this,usage); }
FMOD_RESULT F_API FMOD::Studio::System::getBufferUsage(FMOD_STUDIO_BUFFER_USAGE *usage) { return FMOD_Studio_System_GetBufferUsage((FMOD_STUDIO_SYSTEM *)this,usage); }
FMOD_RESULT F_API FMOD::Studio::System::resetBufferUsage()  { return FMOD_Studio_System_ResetBufferUsage((FMOD_STUDIO_SYSTEM *)this); }
FMOD_RESULT F_API FMOD::Studio::System::registerPlugin(const FMOD_DSP_DESCRIPTION *description)  { return FMOD_Studio_System_RegisterPlugin((FMOD_STUDIO_SYSTEM *)this,description); }
FMOD_RESULT F_API FMOD::Studio::System::unregisterPlugin(const char *name)  { return FMOD_Studio_System_UnregisterPlugin((FMOD_STUDIO_SYSTEM *)this,name); }
FMOD_RESULT F_API FMOD::Studio::System::getBankCount(int *count) { return FMOD_Studio_System_GetBankCount((FMOD_STUDIO_SYSTEM *)this,count); }
FMOD_RESULT F_API FMOD::Studio::System::getBankList(Bank **array, int capacity, int *count) { return FMOD_Studio_System_GetBankList((FMOD_STUDIO_SYSTEM *)this,(FMOD_STUDIO_BANK**)array,capacity,count); }
FMOD_RESULT F_API FMOD::Studio::System::startCommandCapture(const char *filename, FMOD_STUDIO_COMMANDCAPTURE_FLAGS flags)  { return FMOD_Studio_System_StartCommandCapture((FMOD_STUDIO_SYSTEM *)this,filename,flags); }
FMOD_RESULT F_API FMOD::Studio::System::stopCommandCapture()  { return FMOD_Studio_System_StopCommandCapture((FMOD_STUDIO_SYSTEM *)this); }
FMOD_RESULT F_API FMOD::Studio::System::loadCommandReplay(const char *filename, FMOD_STUDIO_COMMANDREPLAY_FLAGS flags, CommandReplay **playback)  { return FMOD_Studio_System_LoadCommandReplay((FMOD_STUDIO_SYSTEM *)this,filename,flags,(FMOD_STUDIO_COMMANDREPLAY**)playback); }
FMOD_RESULT F_API FMOD::Studio::System::setCallback(FMOD_STUDIO_SYSTEM_CALLBACK callback, FMOD_STUDIO_SYSTEM_CALLBACK_TYPE callbackmask)  { return FMOD_Studio_System_SetCallback((FMOD_STUDIO_SYSTEM *)this,callback,FMOD_STUDIO_SYSTEM_CALLBACK_ALL); }
FMOD_RESULT F_API FMOD::Studio::System::getUserData(void **userdata) { return FMOD_Studio_System_GetUserData((FMOD_STUDIO_SYSTEM *)this,userdata); }
FMOD_RESULT F_API FMOD::Studio::System::setUserData(void *userdata)  { return FMOD_Studio_System_SetUserData((FMOD_STUDIO_SYSTEM *)this,userdata); }
bool FMOD::Studio::EventDescription::isValid() { return FMOD_Studio_EventDescription_IsValid((FMOD_STUDIO_EVENTDESCRIPTION *)this); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::getID(FMOD_GUID *id) { return FMOD_Studio_EventDescription_GetID((FMOD_STUDIO_EVENTDESCRIPTION *)this,id); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::getPath(char *path, int size, int *retrieved) { return FMOD_Studio_EventDescription_GetPath((FMOD_STUDIO_EVENTDESCRIPTION *)this,path,size,retrieved); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::getParameterCount(int *count) { return FMOD_Studio_EventDescription_GetParameterCount((FMOD_STUDIO_EVENTDESCRIPTION *)this,count); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::getParameterByIndex(int index, FMOD_STUDIO_PARAMETER_DESCRIPTION *parameter) { return FMOD_Studio_EventDescription_GetParameterByIndex((FMOD_STUDIO_EVENTDESCRIPTION *)this,index,(FMOD_STUDIO_PARAMETER_DESCRIPTION *)parameter); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::getParameter(const char *name, FMOD_STUDIO_PARAMETER_DESCRIPTION *parameter) { return FMOD_Studio_EventDescription_GetParameter((FMOD_STUDIO_EVENTDESCRIPTION *)this,name,(FMOD_STUDIO_PARAMETER_DESCRIPTION *)parameter); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::getUserPropertyCount(int *count) { return FMOD_Studio_EventDescription_GetUserPropertyCount((FMOD_STUDIO_EVENTDESCRIPTION *)this,count); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::getUserPropertyByIndex(int index, FMOD_STUDIO_USER_PROPERTY *property) { return FMOD_Studio_EventDescription_GetUserPropertyByIndex((FMOD_STUDIO_EVENTDESCRIPTION *)this,index,property); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::getUserProperty(const char *name, FMOD_STUDIO_USER_PROPERTY *property) { return FMOD_Studio_EventDescription_GetUserProperty((FMOD_STUDIO_EVENTDESCRIPTION *)this,name,property); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::getLength(int *length) { return FMOD_Studio_EventDescription_GetLength((FMOD_STUDIO_EVENTDESCRIPTION *)this,length); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::getMinimumDistance(float *distance) { return FMOD_Studio_EventDescription_GetMinimumDistance((FMOD_STUDIO_EVENTDESCRIPTION *)this,distance); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::getMaximumDistance(float *distance) { return FMOD_Studio_EventDescription_GetMaximumDistance((FMOD_STUDIO_EVENTDESCRIPTION *)this,distance); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::getSoundSize(float *size) { return FMOD_Studio_EventDescription_GetSoundSize((FMOD_STUDIO_EVENTDESCRIPTION *)this,size); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::isSnapshot(bool *snapshot) { return FMOD_Studio_EventDescription_IsSnapshot((FMOD_STUDIO_EVENTDESCRIPTION *)this,(int *)snapshot); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::isOneshot(bool *oneshot) { return FMOD_Studio_EventDescription_IsOneshot((FMOD_STUDIO_EVENTDESCRIPTION *)this,(int *)oneshot); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::isStream(bool *isStream) { return FMOD_Studio_EventDescription_IsStream((FMOD_STUDIO_EVENTDESCRIPTION *)this,(int *)isStream); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::is3D(bool *is3D) { return FMOD_Studio_EventDescription_Is3D((FMOD_STUDIO_EVENTDESCRIPTION *)this,(int *)is3D); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::hasCue(bool *cue) { return FMOD_Studio_EventDescription_HasCue((FMOD_STUDIO_EVENTDESCRIPTION *)this,(int *)cue); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::createInstance(EventInstance **instance) { return FMOD_Studio_EventDescription_CreateInstance((FMOD_STUDIO_EVENTDESCRIPTION *)this,(FMOD_STUDIO_EVENTINSTANCE **)instance); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::getInstanceCount(int *count) { return FMOD_Studio_EventDescription_GetInstanceCount((FMOD_STUDIO_EVENTDESCRIPTION *)this,count); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::getInstanceList(EventInstance **array, int capacity, int *count) { return FMOD_Studio_EventDescription_GetInstanceList((FMOD_STUDIO_EVENTDESCRIPTION *)this,(FMOD_STUDIO_EVENTINSTANCE **)array,capacity,count); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::loadSampleData()  { return FMOD_Studio_EventDescription_LoadSampleData((FMOD_STUDIO_EVENTDESCRIPTION *)this); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::unloadSampleData()  { return FMOD_Studio_EventDescription_UnloadSampleData((FMOD_STUDIO_EVENTDESCRIPTION *)this); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::getSampleLoadingState(FMOD_STUDIO_LOADING_STATE *state) { return FMOD_Studio_EventDescription_GetSampleLoadingState((FMOD_STUDIO_EVENTDESCRIPTION *)this,state); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::releaseAllInstances()  { return FMOD_Studio_EventDescription_ReleaseAllInstances((FMOD_STUDIO_EVENTDESCRIPTION *)this); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::setCallback(FMOD_STUDIO_EVENT_CALLBACK callback, FMOD_STUDIO_EVENT_CALLBACK_TYPE callbackmask)  { return FMOD_Studio_EventDescription_SetCallback((FMOD_STUDIO_EVENTDESCRIPTION *)this,callback,FMOD_STUDIO_EVENT_CALLBACK_ALL); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::getUserData(void **userdata) { return FMOD_Studio_EventDescription_GetUserData((FMOD_STUDIO_EVENTDESCRIPTION *)this,userdata); }
FMOD_RESULT F_API FMOD::Studio::EventDescription::setUserData(void *userdata) { return FMOD_Studio_EventDescription_SetUserData((FMOD_STUDIO_EVENTDESCRIPTION *)this,userdata); }
bool FMOD::Studio::EventInstance::isValid() { return FMOD_Studio_EventInstance_IsValid((FMOD_STUDIO_EVENTINSTANCE *)this); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::getDescription(EventDescription **description) { return FMOD_Studio_EventInstance_GetDescription((FMOD_STUDIO_EVENTINSTANCE *)this,(FMOD_STUDIO_EVENTDESCRIPTION **)description); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::getVolume(float *volume, float *finalvolume) { return FMOD_Studio_EventInstance_GetVolume((FMOD_STUDIO_EVENTINSTANCE *)this,volume,finalvolume); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::setVolume(float volume)  { return FMOD_Studio_EventInstance_SetVolume_sfp((FMOD_STUDIO_EVENTINSTANCE *)this,volume); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::getPitch(float *pitch, float *finalpitch) { return FMOD_Studio_EventInstance_GetPitch((FMOD_STUDIO_EVENTINSTANCE *)this,pitch,finalpitch); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::setPitch(float pitch)  { return FMOD_Studio_EventInstance_SetPitch_sfp((FMOD_STUDIO_EVENTINSTANCE *)this,pitch); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::get3DAttributes(FMOD_3D_ATTRIBUTES *attributes) { return FMOD_Studio_EventInstance_Get3DAttributes((FMOD_STUDIO_EVENTINSTANCE *)this,(FMOD_3D_ATTRIBUTES*)attributes); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::set3DAttributes(const FMOD_3D_ATTRIBUTES *attributes)  { return FMOD_Studio_EventInstance_Set3DAttributes((FMOD_STUDIO_EVENTINSTANCE *)this,(FMOD_3D_ATTRIBUTES*)attributes); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::getListenerMask(unsigned int *mask) { return FMOD_Studio_EventInstance_GetListenerMask((FMOD_STUDIO_EVENTINSTANCE *)this,mask); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::setListenerMask(unsigned int mask)  { return FMOD_Studio_EventInstance_SetListenerMask((FMOD_STUDIO_EVENTINSTANCE *)this,mask); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::getProperty(FMOD_STUDIO_EVENT_PROPERTY index, float *value) { return FMOD_Studio_EventInstance_GetProperty((FMOD_STUDIO_EVENTINSTANCE *)this,index,value); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::setProperty(FMOD_STUDIO_EVENT_PROPERTY index, float value)  { return FMOD_Studio_EventInstance_SetProperty_sfp((FMOD_STUDIO_EVENTINSTANCE *)this,index,value); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::getReverbLevel(int index, float *level) { return FMOD_Studio_EventInstance_GetReverbLevel((FMOD_STUDIO_EVENTINSTANCE *)this,index,level); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::setReverbLevel(int index, float level)  { return FMOD_Studio_EventInstance_SetReverbLevel_sfp((FMOD_STUDIO_EVENTINSTANCE *)this,index,level); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::getPaused(bool *paused) { return FMOD_Studio_EventInstance_GetPaused((FMOD_STUDIO_EVENTINSTANCE *)this,(int *)paused); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::setPaused(bool paused)  { return FMOD_Studio_EventInstance_SetPaused((FMOD_STUDIO_EVENTINSTANCE *)this,paused); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::start()  { return FMOD_Studio_EventInstance_Start((FMOD_STUDIO_EVENTINSTANCE *)this); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::stop(FMOD_STUDIO_STOP_MODE mode)  { return FMOD_Studio_EventInstance_Stop((FMOD_STUDIO_EVENTINSTANCE *)this,mode); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::getTimelinePosition(int *position) { return FMOD_Studio_EventInstance_GetTimelinePosition((FMOD_STUDIO_EVENTINSTANCE *)this,position); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::setTimelinePosition(int position)  { return FMOD_Studio_EventInstance_SetTimelinePosition((FMOD_STUDIO_EVENTINSTANCE *)this,position); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::getPlaybackState(FMOD_STUDIO_PLAYBACK_STATE *state) { return FMOD_Studio_EventInstance_GetPlaybackState((FMOD_STUDIO_EVENTINSTANCE *)this,state); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::getChannelGroup(ChannelGroup **group) { return FMOD_Studio_EventInstance_GetChannelGroup((FMOD_STUDIO_EVENTINSTANCE *)this,(FMOD_CHANNELGROUP **)group); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::release()  { return FMOD_Studio_EventInstance_Release((FMOD_STUDIO_EVENTINSTANCE *)this); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::isVirtual(bool *virtualState) { return FMOD_Studio_EventInstance_IsVirtual((FMOD_STUDIO_EVENTINSTANCE *)this,(int *)virtualState); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::getParameterValue(const char *name, float *value, float *finalvalue)  { return FMOD_Studio_EventInstance_GetParameterValue((FMOD_STUDIO_EVENTINSTANCE *)this,name,value,finalvalue); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::setParameterValue(const char *name, float value)  { return FMOD_Studio_EventInstance_SetParameterValue_sfp((FMOD_STUDIO_EVENTINSTANCE *)this,name,value); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::getParameterValueByIndex(int index, float *value, float *finalvalue)  { return FMOD_Studio_EventInstance_GetParameterValueByIndex((FMOD_STUDIO_EVENTINSTANCE *)this,index,value,finalvalue); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::setParameterValueByIndex(int index, float value)  { return FMOD_Studio_EventInstance_SetParameterValueByIndex_sfp((FMOD_STUDIO_EVENTINSTANCE *)this,index,value); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::setParameterValuesByIndices(int *indices, float *values, int count)  { return FMOD_Studio_EventInstance_SetParameterValuesByIndices((FMOD_STUDIO_EVENTINSTANCE *)this,indices,values,count); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::getParameter(const char *name, ParameterInstance **parameter) { return FMOD_Studio_EventInstance_GetParameter((FMOD_STUDIO_EVENTINSTANCE *)this,name,(FMOD_STUDIO_PARAMETERINSTANCE **)parameter); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::getParameterByIndex(int index, ParameterInstance **parameter) { return FMOD_Studio_EventInstance_GetParameterByIndex((FMOD_STUDIO_EVENTINSTANCE *)this,index,(FMOD_STUDIO_PARAMETERINSTANCE **)parameter); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::getParameterCount(int *count) { return FMOD_Studio_EventInstance_GetParameterCount((FMOD_STUDIO_EVENTINSTANCE *)this,count); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::triggerCue()  { return FMOD_Studio_EventInstance_TriggerCue((FMOD_STUDIO_EVENTINSTANCE *)this); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::setCallback(FMOD_STUDIO_EVENT_CALLBACK callback, FMOD_STUDIO_EVENT_CALLBACK_TYPE callbackmask)  { return FMOD_Studio_EventInstance_SetCallback((FMOD_STUDIO_EVENTINSTANCE *)this,callback,FMOD_STUDIO_EVENT_CALLBACK_ALL); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::getUserData(void **userdata) { return FMOD_Studio_EventInstance_GetUserData((FMOD_STUDIO_EVENTINSTANCE *)this,userdata); }
FMOD_RESULT F_API FMOD::Studio::EventInstance::setUserData(void *userdata)  { return FMOD_Studio_EventInstance_SetUserData((FMOD_STUDIO_EVENTINSTANCE *)this,userdata); }
bool FMOD::Studio::ParameterInstance::isValid() { return FMOD_Studio_ParameterInstance_IsValid((FMOD_STUDIO_PARAMETERINSTANCE *)this); }
FMOD_RESULT F_API FMOD::Studio::ParameterInstance::getDescription(FMOD_STUDIO_PARAMETER_DESCRIPTION *description) { return FMOD_Studio_ParameterInstance_GetDescription((FMOD_STUDIO_PARAMETERINSTANCE *)this,description); }
FMOD_RESULT F_API FMOD::Studio::ParameterInstance::getValue(float *value) { return FMOD_Studio_ParameterInstance_GetValue((FMOD_STUDIO_PARAMETERINSTANCE *)this,value); }
FMOD_RESULT F_API FMOD::Studio::ParameterInstance::setValue(float value)  { return FMOD_Studio_ParameterInstance_SetValue_sfp((FMOD_STUDIO_PARAMETERINSTANCE *)this,value); }
bool FMOD::Studio::Bus::isValid() { return FMOD_Studio_Bus_IsValid((FMOD_STUDIO_BUS *)this); }
FMOD_RESULT F_API FMOD::Studio::Bus::getID(FMOD_GUID *id) { return FMOD_Studio_Bus_GetID((FMOD_STUDIO_BUS *)this,id); }
FMOD_RESULT F_API FMOD::Studio::Bus::getPath(char *path, int size, int *retrieved) { return FMOD_Studio_Bus_GetPath((FMOD_STUDIO_BUS *)this,path,size,retrieved); }
FMOD_RESULT F_API FMOD::Studio::Bus::getVolume(float *volume, float *finalvolume) { return FMOD_Studio_Bus_GetVolume((FMOD_STUDIO_BUS *)this,volume,finalvolume); }
FMOD_RESULT F_API FMOD::Studio::Bus::setVolume(float volume)  { return FMOD_Studio_Bus_SetVolume_sfp((FMOD_STUDIO_BUS *)this,volume); }
FMOD_RESULT F_API FMOD::Studio::Bus::getPaused(bool *paused) { return FMOD_Studio_Bus_GetPaused((FMOD_STUDIO_BUS *)this,(int *)paused); }
FMOD_RESULT F_API FMOD::Studio::Bus::setPaused(bool paused)  { return FMOD_Studio_Bus_SetPaused((FMOD_STUDIO_BUS *)this,paused); }
FMOD_RESULT F_API FMOD::Studio::Bus::getMute(bool *mute) { return FMOD_Studio_Bus_GetMute((FMOD_STUDIO_BUS *)this,(int *)mute); }
FMOD_RESULT F_API FMOD::Studio::Bus::setMute(bool mute)  { return FMOD_Studio_Bus_SetMute((FMOD_STUDIO_BUS *)this,mute); }
FMOD_RESULT F_API FMOD::Studio::Bus::stopAllEvents(FMOD_STUDIO_STOP_MODE mode)  { return FMOD_Studio_Bus_StopAllEvents((FMOD_STUDIO_BUS *)this,mode); }
FMOD_RESULT F_API FMOD::Studio::Bus::lockChannelGroup()  { return FMOD_Studio_Bus_LockChannelGroup((FMOD_STUDIO_BUS *)this); }
FMOD_RESULT F_API FMOD::Studio::Bus::unlockChannelGroup()  { return FMOD_Studio_Bus_UnlockChannelGroup((FMOD_STUDIO_BUS *)this); }
FMOD_RESULT F_API FMOD::Studio::Bus::getChannelGroup(FMOD::ChannelGroup **channelgroup) { return FMOD_Studio_Bus_GetChannelGroup((FMOD_STUDIO_BUS *)this,(FMOD_CHANNELGROUP **)channelgroup); }
bool FMOD::Studio::VCA::isValid() { return FMOD_Studio_VCA_IsValid((FMOD_STUDIO_VCA *)this); }
FMOD_RESULT F_API FMOD::Studio::VCA::getID(FMOD_GUID *id) { return FMOD_Studio_VCA_GetID((FMOD_STUDIO_VCA *)this,id); }
FMOD_RESULT F_API FMOD::Studio::VCA::getPath(char *path, int size, int *retrieved) { return FMOD_Studio_VCA_GetPath((FMOD_STUDIO_VCA *)this,path,size,retrieved); }
FMOD_RESULT F_API FMOD::Studio::VCA::getVolume(float *volume, float *finalvolume) { return FMOD_Studio_VCA_GetVolume((FMOD_STUDIO_VCA *)this,volume,finalvolume); }
FMOD_RESULT F_API FMOD::Studio::VCA::setVolume(float volume)  { return FMOD_Studio_VCA_SetVolume_sfp((FMOD_STUDIO_VCA *)this,volume); }
bool FMOD::Studio::Bank::isValid() { return FMOD_Studio_Bank_IsValid((FMOD_STUDIO_BANK *)this); }
FMOD_RESULT F_API FMOD::Studio::Bank::getID(FMOD_GUID *id) { return FMOD_Studio_Bank_GetID((FMOD_STUDIO_BANK *)this,id); }
FMOD_RESULT F_API FMOD::Studio::Bank::getPath(char *path, int size, int *retrieved) { return FMOD_Studio_Bank_GetPath((FMOD_STUDIO_BANK *)this,path,size,retrieved); }
FMOD_RESULT F_API FMOD::Studio::Bank::unload()  { return FMOD_Studio_Bank_Unload((FMOD_STUDIO_BANK *)this); }
FMOD_RESULT F_API FMOD::Studio::Bank::loadSampleData()  { return FMOD_Studio_Bank_LoadSampleData((FMOD_STUDIO_BANK *)this); }
FMOD_RESULT F_API FMOD::Studio::Bank::unloadSampleData()  { return FMOD_Studio_Bank_UnloadSampleData((FMOD_STUDIO_BANK *)this); }
FMOD_RESULT F_API FMOD::Studio::Bank::getLoadingState(FMOD_STUDIO_LOADING_STATE *state) { return FMOD_Studio_Bank_GetLoadingState((FMOD_STUDIO_BANK *)this,state); }
FMOD_RESULT F_API FMOD::Studio::Bank::getSampleLoadingState(FMOD_STUDIO_LOADING_STATE *state) { return FMOD_Studio_Bank_GetSampleLoadingState((FMOD_STUDIO_BANK *)this,state); }
FMOD_RESULT F_API FMOD::Studio::Bank::getStringCount(int *count) { return FMOD_Studio_Bank_GetStringCount((FMOD_STUDIO_BANK *)this,count); }
FMOD_RESULT F_API FMOD::Studio::Bank::getStringInfo(int index, FMOD_GUID *id, char *path, int size, int *retrieved) { return FMOD_Studio_Bank_GetStringInfo((FMOD_STUDIO_BANK *)this,index,id,path,size,retrieved); }
FMOD_RESULT F_API FMOD::Studio::Bank::getEventCount(int *count) { return FMOD_Studio_Bank_GetEventCount((FMOD_STUDIO_BANK *)this,count); }
FMOD_RESULT F_API FMOD::Studio::Bank::getEventList(EventDescription **array, int capacity, int *count) { return FMOD_Studio_Bank_GetEventList((FMOD_STUDIO_BANK *)this,(FMOD_STUDIO_EVENTDESCRIPTION **)array,capacity,count); }
FMOD_RESULT F_API FMOD::Studio::Bank::getBusCount(int *count) { return FMOD_Studio_Bank_GetBusCount((FMOD_STUDIO_BANK *)this,count); }
FMOD_RESULT F_API FMOD::Studio::Bank::getBusList(Bus **array, int capacity, int *count) { return FMOD_Studio_Bank_GetBusList((FMOD_STUDIO_BANK *)this,(FMOD_STUDIO_BUS **)array,capacity,count); }
FMOD_RESULT F_API FMOD::Studio::Bank::getVCACount(int *count) { return FMOD_Studio_Bank_GetVCACount((FMOD_STUDIO_BANK *)this,count); }
FMOD_RESULT F_API FMOD::Studio::Bank::getVCAList(VCA **array, int capacity, int *count) { return FMOD_Studio_Bank_GetVCAList((FMOD_STUDIO_BANK *)this,(FMOD_STUDIO_VCA **)array,capacity,count); }
FMOD_RESULT F_API FMOD::Studio::Bank::getUserData(void **userdata) { return FMOD_Studio_Bank_GetUserData((FMOD_STUDIO_BANK *)this,userdata); }
FMOD_RESULT F_API FMOD::Studio::Bank::setUserData(void *userdata)  { return FMOD_Studio_Bank_SetUserData((FMOD_STUDIO_BANK *)this,userdata); }

#endif