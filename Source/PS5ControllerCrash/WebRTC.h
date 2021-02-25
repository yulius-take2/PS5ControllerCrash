#pragma once

#include "HAL/Platform.h"

#undef __native_client__

#if PLATFORM_WINDOWS

#define __PRETTY_FUNCTION__ __FUNCSIG__

#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows/AllowWindowsPlatformAtomics.h"

THIRD_PARTY_INCLUDES_START

// WebRTC requires `htonll` to be defined, which depends either on `NTDDI_VERION` value or
// `INCL_EXTRA_HTON_FUNCTIONS` to be defined
#if !defined(INCL_EXTRA_HTON_FUNCTIONS)
#	if defined(UNDEF_INCL_EXTRA_HTON_FUNCTIONS)
#		pragma message(": Error: `UNDEF_INCL_EXTRA_HTON_FUNCTIONS` already defined, use another name")
#	endif
#	define UNDEF_INCL_EXTRA_HTON_FUNCTIONS
#	define INCL_EXTRA_HTON_FUNCTIONS
#endif

// C4582/3: constructor/desctructor is not implicitly called in "api/rtcerror.h", treated as an error by UE4
// for some unknown reasons we have to disable it inside those UE4's windows-related includes
// C6323: Use of arithmetic operator on Boolean type(s).
#pragma warning(push)
#pragma warning(disable: 4582 4583 6323)

#include "rtc_base/win32.h"
#include "rtc_base/win32socketinit.h"
#include "rtc_base/win32socketserver.h"

// uses Win32 Interlocked* functions
#include "rtc_base/refcountedobject.h"

#pragma warning(pop)

#if defined(UNDEF_INCL_EXTRA_HTON_FUNCTIONS)
#	undef UNDEF_INCL_EXTRA_HTON_FUNCTIONS
#	undef INCL_EXTRA_HTON_FUNCTIONS
#endif

THIRD_PARTY_INCLUDES_END

#include "Windows/HideWindowsPlatformAtomics.h"
#include "Windows/HideWindowsPlatformTypes.h"

#endif // PLATFORM_WINDOWS

THIRD_PARTY_INCLUDES_START

// C4582: constructor is not implicitly called in "api/rtcerror.h", treated as an error by UE4
// C6319: Use of the comma-operator in a tested expression causes the left argument to be ignored when it has no side-effects.
// C6323: Use of arithmetic operator on Boolean type(s).
#pragma warning(push)
#pragma warning(disable: 4582 6319 6323)

#ifdef WIN32
#include "rtc_base/win32socketinit.h"
#endif

#include "rtc_base/atomicops.h"
#include "rtc_base/buffer.h"
#include "rtc_base/helpers.h"
#include "rtc_base/logging.h"
#include "rtc_base/refcount.h"
#include "rtc_base/scoped_ref_ptr.h"
#include "rtc_base/scoped_ref_ptr.h"
#include "rtc_base/ssladapter.h"
#include "rtc_base/sslstreamadapter.h"
#include "rtc_base/stringencode.h"
#include "rtc_base/stringutils.h"
#include "rtc_base/thread.h"
#include "rtc_base/physicalsocketserver.h"

#include "api/audio_codecs/builtin_audio_decoder_factory.h"
#include "api/audio_codecs/builtin_audio_encoder_factory.h"
#include "api/video_codecs/builtin_video_decoder_factory.h"
#include "api/video_codecs/builtin_video_encoder_factory.h"
#include "api/datachannelinterface.h"
#include "api/jsep.h"
#include "api/jsepsessiondescription.h"
#include "api/mediaconstraintsinterface.h"
#include "api/mediastreaminterface.h"
#include "api/peerconnectioninterface.h"
#include "api/test/fakeconstraints.h"
#include "api/video/video_frame.h"
#include "api/video/i420_buffer.h"
#include "pc/peerconnectionfactory.h"
#include "pc/mediastream.h"
#include "pc/peerconnection.h"
#include "pc/sessiondescription.h"

#include "media/base/videosourcebase.h"
#include "media/engine/webrtcvideocapturerfactory.h"
#include "modules/video_capture/video_capture_factory.h"
#include "modules/audio_device/audio_device_impl.h"
#include "modules/audio_device/include/audio_device_data_observer.h"

#pragma warning(pop)

 // because WebRTC uses STL
#include <string>
#include <memory>

	THIRD_PARTY_INCLUDES_END



