// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PS5ControllerCrash : ModuleRules
{
	public PS5ControllerCrash(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "WebRTC", "OpenSSL" });

		if (Target.IsInPlatformGroup(UnrealPlatformGroup.Windows))
		{
			PublicSystemLibraries.Add("msdmo.lib");
			PublicSystemLibraries.Add("dmoguids.lib");
			PublicSystemLibraries.Add("wmcodecdspuuid.lib");
			PublicSystemLibraries.Add("winmm.lib");
			PublicSystemLibraries.Add("strmiids.lib");
		}
	}
}
