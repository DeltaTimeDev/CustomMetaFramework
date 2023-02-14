// Fill out your copyright notice in the Description page of Project Settings.


#include "BMC/BTHttpTestActor.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Templates/SharedPointer.h"
#include "GenericPlatform/GenericPlatformMisc.h"

// Sets default values
ABTHttpTestActor::ABTHttpTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABTHttpTestActor::BeginPlay()
{
	Super::BeginPlay();

    FString MacId = FGenericPlatformMisc::GetDeviceId();

   // const std::string cstr(reinterpret_cast<const char*>(MacId.GetData()), MacId.Num());
   // FString frameAsFString = cstr.c_str();

    //CreateRequest();

    //TMap<FString, bool> Quests;
    //Quests.Add("Part1", true);
    //Quests.Add("Part2", true);
    //Quests.Add("Part3", false);
    //Quests.Add("Part4", true);
    //Quests.Add("Part5", false);



    //FString JsonString = CreateJson(MacId, Quests);

    //UE_LOG(LogTemp, Error, TEXT("JsonString : %s"), *JsonString);
    //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("JsonString %s"), *JsonString));
    //CreateRequest();

}

// Called every frame
void ABTHttpTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void ABTHttpTestActor::CreateRequest()
//{
//
//    FString uriBase = TEXT("http://ip.jsontest.com/");
//
//    FString uriQuery = uriBase + TEXT("/basicspacedata/query/class/gp/OBJECT_ID/~~") + NewObjectId + TEXT("/orderby/DECAY_DATE%20desc/emptyresult/show");
//
//    FHttpModule& httpModule = FHttpModule::Get();
//
//    // Create an http request
//    // The request will execute asynchronously, and call us back on the Lambda below
//    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> pRequest = httpModule.CreateRequest();
//
//    // This is where we set the HTTP method (GET, POST, etc)
//    // The Space-Track.org REST API exposes a "POST" method we can use to get
//    // general perturbations data about objects orbiting Earth
//    pRequest->SetVerb(TEXT("POST"));
//
//    // We'll need to tell the server what type of content to expect in the POST data
//    pRequest->SetHeader(TEXT("Content-Type"), TEXT("application/x-www-form-urlencoded"));
//
//    FString RequestContent = TEXT("identity=") + NewUser + TEXT("&password=") + NewPassword + TEXT("&query=") + uriQuery;
//    // Set the POST content, which contains:
//    // * Identity/password credentials for authentication
//    // * A REST API query
//    //   This allows us to login and get the results is a single call
//    //   Otherwise, we'd need to manage session cookies across multiple calls.
//    pRequest->SetContentAsString(RequestContent);
//
//    // Set the http URL
//    pRequest->SetURL(uriLogin);
//
//    // Set the callback, which will execute when the HTTP call is complete
//    pRequest->OnProcessRequestComplete().BindLambda(
//        // Here, we "capture" the 'this' pointer (the "&"), so our lambda can call this
//        // class's methods in the callback.
//        [&](
//            FHttpRequestPtr pRequest,
//            FHttpResponsePtr pResponse,
//            bool connectedSuccessfully) mutable {
//
//                if (connectedSuccessfully) {
//
//                    // We should have a JSON response - attempt to process it.
//                    ProcessSpaceTrackResponse(pResponse->GetContentAsString());
//                }
//                else {
//                    switch (pRequest->GetStatus()) {
//                    case EHttpRequestStatus::Failed_ConnectionError:
//                        UE_LOG(LogTemp, Error, TEXT("Connection failed."));
//                    default:
//                        UE_LOG(LogTemp, Error, TEXT("Request failed."));
//                    }
//                }
//        });
//
//    // Finally, submit the request for processing
//    pRequest->ProcessRequest();
//}


void ABTHttpTestActor::CreateRequest()
{
    auto request = FHttpModule::Get().CreateRequest();
    request->SetURL(FString("http://google.com"));
    request->OnProcessRequestComplete().BindLambda([](FHttpRequestPtr request, FHttpResponsePtr response, bool success) {
        UE_LOG(LogTemp, Error, TEXT("Response came!"));
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Response came ")));

        });
    request->ProcessRequest();
}

FString ABTHttpTestActor::CreateJson(FString MacId, TMap<FString, bool> Quests)
{   
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);;
    JsonObject->SetStringField("MacId", MacId);
    JsonObject->SetStringField("UserName", "Baris");    

    TArray<TSharedPtr<FJsonObject>> QuestsJsonArray;
    TArray<TSharedPtr<FJsonValue>> PlayersData;

    for (TTuple<FString,bool> Quest : Quests)
    {
        TSharedPtr<FJsonObject> QuestJson = MakeShareable(new FJsonObject);
        QuestJson->SetStringField("Name", Quest.Key);
        QuestJson->SetBoolField("Success", Quest.Value);

        PlayersData.Add(MakeShareable(new FJsonValueObject(QuestJson)));
    }    
    JsonObject->SetArrayField("Quests", PlayersData);

    FString OutputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

    

    return OutputString;
}

void ABTHttpTestActor::LoginWithSpaceTrack(const FString& NewObjectId, const FString& NewUser, const FString& NewPassword)
{
    //FString uriBase = LIVE_URL_BASE;
    //FString uriLogin = uriBase + TEXT("/ajaxauth/login");

    //FString uriQuery = uriBase + TEXT("/basicspacedata/query/class/gp/OBJECT_ID/~~") + NewObjectId + TEXT("/orderby/DECAY_DATE%20desc/emptyresult/show");

    //FHttpModule& httpModule = FHttpModule::Get();

    //// Create an http request
    //// The request will execute asynchronously, and call us back on the Lambda below
    //TSharedRef<IHttpRequest, ESPMode::ThreadSafe> pRequest = httpModule.CreateRequest();

    //// This is where we set the HTTP method (GET, POST, etc)
    //// The Space-Track.org REST API exposes a "POST" method we can use to get
    //// general perturbations data about objects orbiting Earth
    //pRequest->SetVerb(TEXT("POST"));

    //// We'll need to tell the server what type of content to expect in the POST data
    //pRequest->SetHeader(TEXT("Content-Type"), TEXT("application/x-www-form-urlencoded"));

    //FString RequestContent = TEXT("identity=") + NewUser + TEXT("&password=") + NewPassword + TEXT("&query=") + uriQuery;
    //// Set the POST content, which contains:
    //// * Identity/password credentials for authentication
    //// * A REST API query
    ////   This allows us to login and get the results is a single call
    ////   Otherwise, we'd need to manage session cookies across multiple calls.
    //pRequest->SetContentAsString(RequestContent);

    //// Set the http URL
    //pRequest->SetURL(uriLogin);

    //// Set the callback, which will execute when the HTTP call is complete
    //pRequest->OnProcessRequestComplete().BindLambda(
    //    // Here, we "capture" the 'this' pointer (the "&"), so our lambda can call this
    //    // class's methods in the callback.
    //    [&](
    //        FHttpRequestPtr pRequest,
    //        FHttpResponsePtr pResponse,
    //        bool connectedSuccessfully) mutable {

    //            if (connectedSuccessfully) {

    //                // We should have a JSON response - attempt to process it.
    //                ProcessSpaceTrackResponse(pResponse->GetContentAsString());
    //            }
    //            else {
    //                switch (pRequest->GetStatus()) {
    //                case EHttpRequestStatus::Failed_ConnectionError:
    //                    UE_LOG(LogTemp, Error, TEXT("Connection failed."));
    //                default:
    //                    UE_LOG(LogTemp, Error, TEXT("Request failed."));
    //                }
    //            }
    //    });

    //// Finally, submit the request for processing
    //pRequest->ProcessRequest();
}


