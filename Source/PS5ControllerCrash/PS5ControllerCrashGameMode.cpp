// Copyright Epic Games, Inc. All Rights Reserved.

#include "PS5ControllerCrashGameMode.h"
#include "PS5ControllerCrashCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "WebRTC.h"

void InitWebRTC()
{
    rtc::LogMessage::LogToDebug(rtc::LS_VERBOSE);

#if defined(WIN32)
    rtc::EnsureWinsockInit();
#endif

    rtc::InitializeSSL();

    auto peerFactory = webrtc::CreatePeerConnectionFactory(
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        webrtc::CreateBuiltinAudioEncoderFactory(),
        webrtc::CreateBuiltinAudioDecoderFactory(),
        webrtc::CreateBuiltinVideoEncoderFactory(),
        webrtc::CreateBuiltinVideoDecoderFactory(),
        nullptr,
        nullptr);
}

APS5ControllerCrashGameMode::APS5ControllerCrashGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// initialize WebRTC
    InitWebRTC();
}
