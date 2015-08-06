#include "BsPrerequisites.h"
#include "BsHEString.h"

namespace BansheeEngine
{
	const UINT32 HEString::ENGINE_STRING_TABLE_ID = 30000; // Arbitrary

	HEString::HEString(const WString& identifier)
		:mInternal(identifier, ENGINE_STRING_TABLE_ID)
	{
		
	}

	HEString::HEString(const WString& identifier, const WString& default)
		: mInternal(identifier, default, ENGINE_STRING_TABLE_ID)
	{
		
	}

	HEString::HEString()
		: mInternal(ENGINE_STRING_TABLE_ID)
	{
		
	}

	HEString::operator HString() const
	{
		return mInternal;
	}
}