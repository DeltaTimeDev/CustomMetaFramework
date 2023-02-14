// Fill out your copyright notice in the Description page of Project Settings.


#include "BTLanFunctionLibrary.h"
#include "SocketSubsystem.h"

void UBTLanFunctionLibrary::FindIP_Address(FString& IP_Address)
{
	bool bCanBindAll;
	TSharedPtr<class FInternetAddr> Addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalHostAddr(*GLog, bCanBindAll);
	FString MyIP = Addr->ToString(false);
	IP_Address = MyIP;
}
