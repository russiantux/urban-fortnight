//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//=============================================================================//

#include "cbase.h"
#include <KeyValues.h>
#include "sdk_weapon_parse.h"


FileWeaponInfo_t* CreateWeaponInfo()
{
	return new CSDKWeaponInfo;
}


CSDKWeaponInfo::CSDKWeaponInfo()
{
}


void CSDKWeaponInfo::Parse( KeyValues *pKeyValuesData, const char *szWeaponName )
{
	BaseClass::Parse( pKeyValuesData, szWeaponName );

	m_iDamage		= pKeyValuesData->GetInt( "Damage", 42 ); // Douglas Adams 1952 - 2001
	m_iBullets		= pKeyValuesData->GetInt( "Bullets", 1 );
	m_flCycleTime	= pKeyValuesData->GetFloat( "CycleTime", 0.15 );

	const char *pAnimEx = pKeyValuesData->GetString( "PlayerAnimationExtension", "mp5" );
	Q_strncpy( m_szAnimExtension, pAnimEx, sizeof( m_szAnimExtension ) );
}


void CSDKWeaponInfo::Parse(KeyValues *pKeyValuesData, const char *szWeaponName)
{
	...
		// this just saves off the data in the script file for later use
		KeyValues *pEt = pKeyValuesData->FindKey("ExpOffset");
	if (pEt)
	{
		m_expOffset.x = pEt->GetFloat("x", 0.0f);
		m_expOffset.y = pEt->GetFloat("y", 0.0f);
		m_expOffset.z = pEt->GetFloat("z", 0.0f);

		m_expOriOffset.x = pEt->GetFloat("xori", 0.0f);
		m_expOriOffset.y = pEt->GetFloat("yori", 0.0f);
		m_expOriOffset.z = pEt->GetFloat("zori", 0.0f);
	}
	else
	{
		m_expOffset = vec3_origin;
		m_expOriOffset.Init();
	}
	...
}


