// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CharacterBase.h"
#include "Board.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeCharacterBase() {}

// ********** Begin Cross Module References ********************************************************
EGNIS_API UClass* Z_Construct_UClass_ABoard_NoRegister();
EGNIS_API UClass* Z_Construct_UClass_ACharacterBase();
EGNIS_API UClass* Z_Construct_UClass_ACharacterBase_NoRegister();
EGNIS_API UClass* Z_Construct_UClass_UHealthComponent_NoRegister();
EGNIS_API UEnum* Z_Construct_UEnum_Egnis_EColorType();
EGNIS_API UScriptStruct* Z_Construct_UScriptStruct_FTileCoord();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
UPackage* Z_Construct_UPackage__Script_Egnis();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ACharacterBase Function GainHealth ***************************************
struct Z_Construct_UFunction_ACharacterBase_GainHealth_Statics
{
	struct CharacterBase_eventGainHealth_Parms
	{
		float AmountHealed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "Public/CharacterBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AmountHealed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ACharacterBase_GainHealth_Statics::NewProp_AmountHealed = { "AmountHealed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CharacterBase_eventGainHealth_Parms, AmountHealed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACharacterBase_GainHealth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACharacterBase_GainHealth_Statics::NewProp_AmountHealed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACharacterBase_GainHealth_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACharacterBase_GainHealth_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACharacterBase, nullptr, "GainHealth", Z_Construct_UFunction_ACharacterBase_GainHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACharacterBase_GainHealth_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACharacterBase_GainHealth_Statics::CharacterBase_eventGainHealth_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACharacterBase_GainHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACharacterBase_GainHealth_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACharacterBase_GainHealth_Statics::CharacterBase_eventGainHealth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACharacterBase_GainHealth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACharacterBase_GainHealth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACharacterBase::execGainHealth)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_AmountHealed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GainHealth(Z_Param_AmountHealed);
	P_NATIVE_END;
}
// ********** End Class ACharacterBase Function GainHealth *****************************************

// ********** Begin Class ACharacterBase Function GetTeam ******************************************
struct Z_Construct_UFunction_ACharacterBase_GetTeam_Statics
{
	struct CharacterBase_eventGetTeam_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "Public/CharacterBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ACharacterBase_GetTeam_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CharacterBase_eventGetTeam_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACharacterBase_GetTeam_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACharacterBase_GetTeam_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACharacterBase_GetTeam_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACharacterBase_GetTeam_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACharacterBase, nullptr, "GetTeam", Z_Construct_UFunction_ACharacterBase_GetTeam_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACharacterBase_GetTeam_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACharacterBase_GetTeam_Statics::CharacterBase_eventGetTeam_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACharacterBase_GetTeam_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACharacterBase_GetTeam_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACharacterBase_GetTeam_Statics::CharacterBase_eventGetTeam_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACharacterBase_GetTeam()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACharacterBase_GetTeam_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACharacterBase::execGetTeam)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetTeam();
	P_NATIVE_END;
}
// ********** End Class ACharacterBase Function GetTeam ********************************************

// ********** Begin Class ACharacterBase Function LossHealth ***************************************
struct Z_Construct_UFunction_ACharacterBase_LossHealth_Statics
{
	struct CharacterBase_eventLossHealth_Parms
	{
		float HealthToLoss;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ===== Funciones =====\n" },
#endif
		{ "ModuleRelativePath", "Public/CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "===== Funciones =====" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HealthToLoss;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ACharacterBase_LossHealth_Statics::NewProp_HealthToLoss = { "HealthToLoss", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CharacterBase_eventLossHealth_Parms, HealthToLoss), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACharacterBase_LossHealth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACharacterBase_LossHealth_Statics::NewProp_HealthToLoss,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACharacterBase_LossHealth_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACharacterBase_LossHealth_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACharacterBase, nullptr, "LossHealth", Z_Construct_UFunction_ACharacterBase_LossHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACharacterBase_LossHealth_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACharacterBase_LossHealth_Statics::CharacterBase_eventLossHealth_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACharacterBase_LossHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACharacterBase_LossHealth_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACharacterBase_LossHealth_Statics::CharacterBase_eventLossHealth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACharacterBase_LossHealth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACharacterBase_LossHealth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACharacterBase::execLossHealth)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_HealthToLoss);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LossHealth(Z_Param_HealthToLoss);
	P_NATIVE_END;
}
// ********** End Class ACharacterBase Function LossHealth *****************************************

// ********** Begin Class ACharacterBase Function SetCurrentTile ***********************************
struct Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics
{
	struct CharacterBase_eventSetCurrentTile_Parms
	{
		FTileCoord NewTile;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewTile_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewTile;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics::NewProp_NewTile = { "NewTile", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CharacterBase_eventSetCurrentTile_Parms, NewTile), Z_Construct_UScriptStruct_FTileCoord, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewTile_MetaData), NewProp_NewTile_MetaData) }; // 1348766882
void Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CharacterBase_eventSetCurrentTile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CharacterBase_eventSetCurrentTile_Parms), &Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics::NewProp_NewTile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACharacterBase, nullptr, "SetCurrentTile", Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics::CharacterBase_eventSetCurrentTile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics::CharacterBase_eventSetCurrentTile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACharacterBase_SetCurrentTile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACharacterBase_SetCurrentTile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACharacterBase::execSetCurrentTile)
{
	P_GET_STRUCT_REF(FTileCoord,Z_Param_Out_NewTile);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetCurrentTile(Z_Param_Out_NewTile);
	P_NATIVE_END;
}
// ********** End Class ACharacterBase Function SetCurrentTile *************************************

// ********** Begin Class ACharacterBase Function SnapToCurrentTile ********************************
struct Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile_Statics
{
	struct CharacterBase_eventSnapToCurrentTile_Parms
	{
		bool bKeepCurrentZ;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Grid" },
		{ "CPP_Default_bKeepCurrentZ", "false" },
		{ "ModuleRelativePath", "Public/CharacterBase.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bKeepCurrentZ_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bKeepCurrentZ;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile_Statics::NewProp_bKeepCurrentZ_SetBit(void* Obj)
{
	((CharacterBase_eventSnapToCurrentTile_Parms*)Obj)->bKeepCurrentZ = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile_Statics::NewProp_bKeepCurrentZ = { "bKeepCurrentZ", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CharacterBase_eventSnapToCurrentTile_Parms), &Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile_Statics::NewProp_bKeepCurrentZ_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile_Statics::NewProp_bKeepCurrentZ,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACharacterBase, nullptr, "SnapToCurrentTile", Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile_Statics::CharacterBase_eventSnapToCurrentTile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile_Statics::CharacterBase_eventSnapToCurrentTile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACharacterBase::execSnapToCurrentTile)
{
	P_GET_UBOOL(Z_Param_bKeepCurrentZ);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SnapToCurrentTile(Z_Param_bKeepCurrentZ);
	P_NATIVE_END;
}
// ********** End Class ACharacterBase Function SnapToCurrentTile **********************************

// ********** Begin Class ACharacterBase ***********************************************************
void ACharacterBase::StaticRegisterNativesACharacterBase()
{
	UClass* Class = ACharacterBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GainHealth", &ACharacterBase::execGainHealth },
		{ "GetTeam", &ACharacterBase::execGetTeam },
		{ "LossHealth", &ACharacterBase::execLossHealth },
		{ "SetCurrentTile", &ACharacterBase::execSetCurrentTile },
		{ "SnapToCurrentTile", &ACharacterBase::execSnapToCurrentTile },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ACharacterBase;
UClass* ACharacterBase::GetPrivateStaticClass()
{
	using TClass = ACharacterBase;
	if (!Z_Registration_Info_UClass_ACharacterBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("CharacterBase"),
			Z_Registration_Info_UClass_ACharacterBase.InnerSingleton,
			StaticRegisterNativesACharacterBase,
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
	return Z_Registration_Info_UClass_ACharacterBase.InnerSingleton;
}
UClass* Z_Construct_UClass_ACharacterBase_NoRegister()
{
	return ACharacterBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ACharacterBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "CharacterBase.h" },
		{ "ModuleRelativePath", "Public/CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealthComp_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Board_MetaData[] = {
		{ "Category", "Grid" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ===== Grid / Board =====\n" },
#endif
		{ "ModuleRelativePath", "Public/CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "===== Grid / Board =====" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTile_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSnapToTileOnBeginPlay_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TileZOffset_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "Category", "CharacterBase" },
		{ "ModuleRelativePath", "Public/CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Team_MetaData[] = {
		{ "Category", "Team" },
		{ "ModuleRelativePath", "Public/CharacterBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealthComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Board;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentTile;
	static void NewProp_bSnapToTileOnBeginPlay_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSnapToTileOnBeginPlay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TileZOffset;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Team;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACharacterBase_GainHealth, "GainHealth" }, // 4070363802
		{ &Z_Construct_UFunction_ACharacterBase_GetTeam, "GetTeam" }, // 654376632
		{ &Z_Construct_UFunction_ACharacterBase_LossHealth, "LossHealth" }, // 2268010217
		{ &Z_Construct_UFunction_ACharacterBase_SetCurrentTile, "SetCurrentTile" }, // 1656358630
		{ &Z_Construct_UFunction_ACharacterBase_SnapToCurrentTile, "SnapToCurrentTile" }, // 2238946531
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACharacterBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACharacterBase_Statics::NewProp_HealthComp = { "HealthComp", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharacterBase, HealthComp), Z_Construct_UClass_UHealthComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealthComp_MetaData), NewProp_HealthComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACharacterBase_Statics::NewProp_Board = { "Board", nullptr, (EPropertyFlags)0x0114000000020815, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharacterBase, Board), Z_Construct_UClass_ABoard_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Board_MetaData), NewProp_Board_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ACharacterBase_Statics::NewProp_CurrentTile = { "CurrentTile", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharacterBase, CurrentTile), Z_Construct_UScriptStruct_FTileCoord, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTile_MetaData), NewProp_CurrentTile_MetaData) }; // 1348766882
void Z_Construct_UClass_ACharacterBase_Statics::NewProp_bSnapToTileOnBeginPlay_SetBit(void* Obj)
{
	((ACharacterBase*)Obj)->bSnapToTileOnBeginPlay = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACharacterBase_Statics::NewProp_bSnapToTileOnBeginPlay = { "bSnapToTileOnBeginPlay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACharacterBase), &Z_Construct_UClass_ACharacterBase_Statics::NewProp_bSnapToTileOnBeginPlay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSnapToTileOnBeginPlay_MetaData), NewProp_bSnapToTileOnBeginPlay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACharacterBase_Statics::NewProp_TileZOffset = { "TileZOffset", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharacterBase, TileZOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TileZOffset_MetaData), NewProp_TileZOffset_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ACharacterBase_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ACharacterBase_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharacterBase, Type), Z_Construct_UEnum_Egnis_EColorType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) }; // 1204476259
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ACharacterBase_Statics::NewProp_Team = { "Team", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACharacterBase, Team), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Team_MetaData), NewProp_Team_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACharacterBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharacterBase_Statics::NewProp_HealthComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharacterBase_Statics::NewProp_Board,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharacterBase_Statics::NewProp_CurrentTile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharacterBase_Statics::NewProp_bSnapToTileOnBeginPlay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharacterBase_Statics::NewProp_TileZOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharacterBase_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharacterBase_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharacterBase_Statics::NewProp_Team,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACharacterBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACharacterBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Egnis,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACharacterBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACharacterBase_Statics::ClassParams = {
	&ACharacterBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACharacterBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACharacterBase_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACharacterBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ACharacterBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACharacterBase()
{
	if (!Z_Registration_Info_UClass_ACharacterBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACharacterBase.OuterSingleton, Z_Construct_UClass_ACharacterBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACharacterBase.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACharacterBase);
ACharacterBase::~ACharacterBase() {}
// ********** End Class ACharacterBase *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_luis2_OneDrive___U_tad_Documents_GitHub_Egnis_Egnis_Source_Egnis_Public_CharacterBase_h__Script_Egnis_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACharacterBase, ACharacterBase::StaticClass, TEXT("ACharacterBase"), &Z_Registration_Info_UClass_ACharacterBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACharacterBase), 4011413454U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_luis2_OneDrive___U_tad_Documents_GitHub_Egnis_Egnis_Source_Egnis_Public_CharacterBase_h__Script_Egnis_494368104(TEXT("/Script/Egnis"),
	Z_CompiledInDeferFile_FID_Users_luis2_OneDrive___U_tad_Documents_GitHub_Egnis_Egnis_Source_Egnis_Public_CharacterBase_h__Script_Egnis_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_luis2_OneDrive___U_tad_Documents_GitHub_Egnis_Egnis_Source_Egnis_Public_CharacterBase_h__Script_Egnis_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
