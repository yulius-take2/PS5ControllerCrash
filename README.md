# PS5 Controller UE4.25.4 WebRTC Crash

## To reproduce
1. Hookup PS5 Controller on Windows 10
2. Make sure Windows 10 detects the controller in Control Panel.
3. Build and start project in Visual Studio.
4. Notice crash
5. Remove PS5 Controller
6. Start project
7. Notice no crash

## Code

Simply initializating WebRTC crashes.

https://github.com/yulius-take2/PS5ControllerCrash/blob/main/Source/PS5ControllerCrash/PS5ControllerCrashGameMode.cpp#L8-L29

```
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
```
