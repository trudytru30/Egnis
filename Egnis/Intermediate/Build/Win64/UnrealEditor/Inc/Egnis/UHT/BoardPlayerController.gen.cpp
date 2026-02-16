// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BoardPlayerController.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeBoardPlayerController() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
EGNIS_API UClass* Z_Construct_UClass_ABoardPlayerController();
EGNIS_API UClass* Z_Construct_UClass_ABoardPlayerController_NoRegister();
EGNIS_API UEnum* Z_Construct_UEnum_Egnis_EInputIntent();
EGNIS_API UScriptStruct* Z_Construct_UScriptStruct_FClickResult();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
UPackage* Z_Construct_UPackage__Script_Egnis();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EInputIntent **************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EInputIntent;
static UEnum* EInputIntent_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EInputIntent.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EInputIntent.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Egnis_EInputIntent, (UObject*)Z_Construct_UPackage__Script_Egnis(), TEXT("EInputIntent"));
	}
	return Z_Registration_Info_UEnum_EInputIntent.OuterSingleton;
}
template<> EGNIS_API UEnum* StaticEnum<EInputIntent>()
{
	return EInputIntent_StaticEnum();
}
struct Z_Construct_UEnum_Egnis_EInputIntent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Action.Name", "EInputIntent::Action" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/BoardPlayerController.h" },
		{ "Move.Name", "EInputIntent::Move" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EInputIntent::Move", (int64)EInputIntent::Move },
		{ "EInputIntent::Action", (int64)EInputIntent::Action },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Egnis_EInputIntent_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Egnis,
	nullptr,
	"EInputIntent",
	"EInputIntent",
	Z_Construct_UEnum_Egnis_EInputIntent_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Egnis_EInputIntent_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Egnis_EInputIntent_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Egnis_EInputIntent_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Egnis_EInputIntent()
{
	if (!Z_Registration_Info_UEnum_EInputIntent.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EInputIntent.InnerSingleton, Z_Construct_UEnum_Egnis_EInputIntent_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EInputIntent.InnerSingleton;
}
// ********** End Enum EInputIntent ****************************************************************

// ********** Begin ScriptStruct FClickResult ******************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FClickResult;
class UScriptStruct* FClickResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FClickResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FClickResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FClickResult, (UObject*)Z_Construct_UPackage__Script_Egnis(), TEXT("ClickResult"));
	}
	return Z_Registration_Info_UScriptStruct_FClickResult.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FClickResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/BoardPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHit_MetaData[] = {
		{ "Category", "ClickResult" },
		{ "ModuleRelativePath", "Public/BoardPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHitUnit_MetaData[] = {
		{ "Category", "ClickResult" },
		{ "ModuleRelativePath", "Public/BoardPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHitBoard_MetaData[] = {
		{ "Category", "ClickResult" },
		{ "ModuleRelativePath", "Public/BoardPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitActor_MetaData[] = {
		{ "Category", "ClickResult" },
		{ "ModuleRelativePath", "Public/BoardPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldPoint_MetaData[] = {
		{ "Category", "ClickResult" },
		{ "ModuleRelativePath", "Public/BoardPlayerController.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bHit_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHit;
	static void NewProp_bHitUnit_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHitUnit;
	static void NewProp_bHitBoard_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHitBoard;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HitActor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldPoint;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FClickResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FClickResult_Statics::NewProp_bHit_SetBit(void* Obj)
{
	((FClickResult*)Obj)->bHit = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FClickResult_Statics::NewProp_bHit = { "bHit", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FClickResult), &Z_Construct_UScriptStruct_FClickResult_Statics::NewProp_bHit_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHit_MetaData), NewProp_bHit_MetaData) };
void Z_Construct_UScriptStruct_FClickResult_Statics::NewProp_bHitUnit_SetBit(void* Obj)
{
	((FClickResult*)Obj)->bHitUnit = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FClickResult_Statics::NewProp_bHitUnit = { "bHitUnit", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FClickResult), &Z_Construct_UScriptStruct_FClickResult_Statics::NewProp_bHitUnit_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHitUnit_MetaData), NewProp_bHitUnit_MetaData) };
void Z_Construct_UScriptStruct_FClickResult_Statics::NewProp_bHitBoard_SetBit(void* Obj)
{
	((FClickResult*)Obj)->bHitBoard = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FClickResult_Statics::NewProp_bHitBoard = { "bHitBoard", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FClickResult), &Z_Construct_UScriptStruct_FClickResult_Statics::NewProp_bHitBoard_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHitBoard_MetaData), NewProp_bHitBoard_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FClickResult_Statics::NewProp_HitActor = { "HitActor", nullptr, (EPropertyFlags)0x0114000000000004, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickResult, HitActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitActor_MetaData), NewProp_HitActor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FClickResult_Statics::NewProp_WorldPoint = { "WorldPoint", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickResult, WorldPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldPoint_MetaData), NewProp_WorldPoint_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FClickResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickResult_Statics::NewProp_bHit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickResult_Statics::NewProp_bHitUnit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickResult_Statics::NewProp_bHitBoard,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickResult_Statics::NewProp_HitActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickResult_Statics::NewProp_WorldPoint,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClickResult_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FClickResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Egnis,
	nullptr,
	&NewStructOps,
	"ClickResult",
	Z_Construct_UScriptStruct_FClickResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClickResult_Statics::PropPointers),
	sizeof(FClickResult),
	alignof(FClickResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClickResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FClickResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FClickResult()
{
	if (!Z_Registration_Info_UScriptStruct_FClickResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FClickResult.InnerSingleton, Z_Construct_UScriptStruct_FClickResult_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FClickResult.InnerSingleton;
}
// ********** End ScriptStruct FClickResult ********************************************************

// ********** Begin Class ABoardPlayerController Function BP_OnclickResolved ***********************
struct BoardPlayerController_eventBP_OnclickResolved_Parms
{
	FClickResult Result;
};
static FName NAME_ABoardPlayerController_BP_OnclickResolved = FName(TEXT("BP_OnclickResolved"));
void ABoardPlayerController::BP_OnclickResolved(FClickResult const& Result)
{
	BoardPlayerController_eventBP_OnclickResolved_Parms Parms;
	Parms.Result=Result;
	UFunction* Func = FindFunctionChecked(NAME_ABoardPlayerController_BP_OnclickResolved);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ABoardPlayerController_BP_OnclickResolved_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/BoardPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Result_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABoardPlayerController_BP_OnclickResolved_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BoardPlayerController_eventBP_OnclickResolved_Parms, Result), Z_Construct_UScriptStruct_FClickResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Result_MetaData), NewProp_Result_MetaData) }; // 2780328015
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoardPlayerController_BP_OnclickResolved_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoardPlayerController_BP_OnclickResolved_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABoardPlayerController_BP_OnclickResolved_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoardPlayerController_BP_OnclickResolved_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ABoardPlayerController, nullptr, "BP_OnclickResolved", Z_Construct_UFunction_ABoardPlayerController_BP_OnclickResolved_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoardPlayerController_BP_OnclickResolved_Statics::PropPointers), sizeof(BoardPlayerController_eventBP_OnclickResolved_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08480800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABoardPlayerController_BP_OnclickResolved_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABoardPlayerController_BP_OnclickResolved_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(BoardPlayerController_eventBP_OnclickResolved_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABoardPlayerController_BP_OnclickResolved()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABoardPlayerController_BP_OnclickResolved_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ABoardPlayerController Function BP_OnclickResolved *************************

// ********** Begin Class ABoardPlayerController ***************************************************
void ABoardPlayerController::StaticRegisterNativesABoardPlayerController()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ABoardPlayerController;
UClass* ABoardPlayerController::GetPrivateStaticClass()
{
	using TClass = ABoardPlayerController;
	if (!Z_Registration_Info_UClass_ABoardPlayerController.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("BoardPlayerController"),
			Z_Registration_Info_UClass_ABoardPlayerController.InnerSingleton,
			StaticRegisterNativesABoardPlayerController,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ABoardPlayerController.InnerSingleton;
}
UClass* Z_Construct_UClass_ABoardPlayerController_NoRegister()
{
	return ABoardPlayerController::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ABoardPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "BoardPlayerController.h" },
		{ "ModuleRelativePath", "Public/BoardPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentIntent_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/BoardPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IMCGameplay_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/BoardPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IMCUI_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/BoardPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PauseAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/BoardPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClickAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/BoardPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitTraceChannel_MetaData[] = {
		{ "Category", "Click|Trace" },
		{ "ModuleRelativePath", "Public/BoardPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoardTraceChannel_MetaData[] = {
		{ "Category", "Click|Trace" },
		{ "ModuleRelativePath", "Public/BoardPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentIntent_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentIntent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IMCGameplay;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IMCUI;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PauseAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ClickAction;
	static const UECodeGen_Private::FBytePropertyParams NewProp_UnitTraceChannel;
	static const UECodeGen_Private::FBytePropertyParams NewProp_BoardTraceChannel;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ABoardPlayerController_BP_OnclickResolved, "BP_OnclickResolved" }, // 2181110355
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoardPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ABoardPlayerController_Statics::NewProp_CurrentIntent_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ABoardPlayerController_Statics::NewProp_CurrentIntent = { "CurrentIntent", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoardPlayerController, CurrentIntent), Z_Construct_UEnum_Egnis_EInputIntent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentIntent_MetaData), NewProp_CurrentIntent_MetaData) }; // 1807670252
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoardPlayerController_Statics::NewProp_IMCGameplay = { "IMCGameplay", nullptr, (EPropertyFlags)0x0124080000010001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoardPlayerController, IMCGameplay), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IMCGameplay_MetaData), NewProp_IMCGameplay_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoardPlayerController_Statics::NewProp_IMCUI = { "IMCUI", nullptr, (EPropertyFlags)0x0124080000010001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoardPlayerController, IMCUI), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IMCUI_MetaData), NewProp_IMCUI_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoardPlayerController_Statics::NewProp_PauseAction = { "PauseAction", nullptr, (EPropertyFlags)0x0124080000010001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoardPlayerController, PauseAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PauseAction_MetaData), NewProp_PauseAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoardPlayerController_Statics::NewProp_ClickAction = { "ClickAction", nullptr, (EPropertyFlags)0x0124080000010001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoardPlayerController, ClickAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClickAction_MetaData), NewProp_ClickAction_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ABoardPlayerController_Statics::NewProp_UnitTraceChannel = { "UnitTraceChannel", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoardPlayerController, UnitTraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitTraceChannel_MetaData), NewProp_UnitTraceChannel_MetaData) }; // 756624936
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ABoardPlayerController_Statics::NewProp_BoardTraceChannel = { "BoardTraceChannel", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoardPlayerController, BoardTraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoardTraceChannel_MetaData), NewProp_BoardTraceChannel_MetaData) }; // 756624936
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABoardPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoardPlayerController_Statics::NewProp_CurrentIntent_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoardPlayerController_Statics::NewProp_CurrentIntent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoardPlayerController_Statics::NewProp_IMCGameplay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoardPlayerController_Statics::NewProp_IMCUI,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoardPlayerController_Statics::NewProp_PauseAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoardPlayerController_Statics::NewProp_ClickAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoardPlayerController_Statics::NewProp_UnitTraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoardPlayerController_Statics::NewProp_BoardTraceChannel,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoardPlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABoardPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_Egnis,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoardPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABoardPlayerController_Statics::ClassParams = {
	&ABoardPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ABoardPlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ABoardPlayerController_Statics::PropPointers),
	0,
	0x009003A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoardPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_ABoardPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABoardPlayerController()
{
	if (!Z_Registration_Info_UClass_ABoardPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABoardPlayerController.OuterSingleton, Z_Construct_UClass_ABoardPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABoardPlayerController.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABoardPlayerController);
ABoardPlayerController::~ABoardPlayerController() {}
// ********** End Class ABoardPlayerController *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Egnis_Source_Egnis_Public_BoardPlayerController_h__Script_Egnis_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EInputIntent_StaticEnum, TEXT("EInputIntent"), &Z_Registration_Info_UEnum_EInputIntent, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1807670252U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FClickResult::StaticStruct, Z_Construct_UScriptStruct_FClickResult_Statics::NewStructOps, TEXT("ClickResult"), &Z_Registration_Info_UScriptStruct_FClickResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FClickResult), 2780328015U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABoardPlayerController, ABoardPlayerController::StaticClass, TEXT("ABoardPlayerController"), &Z_Registration_Info_UClass_ABoardPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABoardPlayerController), 1290429263U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Egnis_Source_Egnis_Public_BoardPlayerController_h__Script_Egnis_1144295809(TEXT("/Script/Egnis"),
	Z_CompiledInDeferFile_FID_Egnis_Source_Egnis_Public_BoardPlayerController_h__Script_Egnis_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Egnis_Source_Egnis_Public_BoardPlayerController_h__Script_Egnis_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Egnis_Source_Egnis_Public_BoardPlayerController_h__Script_Egnis_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Egnis_Source_Egnis_Public_BoardPlayerController_h__Script_Egnis_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Egnis_Source_Egnis_Public_BoardPlayerController_h__Script_Egnis_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Egnis_Source_Egnis_Public_BoardPlayerController_h__Script_Egnis_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
